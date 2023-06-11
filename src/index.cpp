#include "index.h"

#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

Index::Index (vector<pair<string, vector<string>>> document) {
    for (auto it: document) {
        for (auto word: it.second) {
            dictionary_[it.first][standardizeWord(word)]++;
        }
    }
}

string Index::standardizeWord (string word) {
    string standardWord = word;
    // Transformando a palavara para minúscula
    transform(
        standardWord.begin(), standardWord.end(), standardWord.begin(),[](unsigned char c){
            return tolower(c); 
    });

     // Removendo caracteres  !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
    standardWord.erase(
        remove_if(standardWord.begin(), standardWord.end(), [](unsigned char c) {
            return ispunct(c);
        }),
    standardWord.end());

    // Removendo numeração
    standardWord.erase(
        remove_if(standardWord.begin(), standardWord.end(), [](unsigned char c) {
            return isdigit(c);
        }),
    standardWord.end());
                
    return standardWord;
}

vector<string> Index::wordDivision(string query) {
    vector<string> Words;
    string word;
    // Leitura de uma string e divisão termo a termo dela.
    istringstream iss(query);
    while (iss >> word) {
        Words.push_back(standardizeWord(word));
    }
    return Words;
}

bool Index::compare (pair<string, int> a, pair<string, int> b) {
    return a.second > b.second; 
} 

vector<pair<string, int>> Index::Search (string query) {        
    vector<string> Words = wordDivision(query);
    vector<pair<string,int>>result;

    for (auto document: dictionary_) {
        bool allWordsPresent = true;
        for (const auto& word: Words) {
            if (document.second.find(word) == document.second.end()) {
                allWordsPresent = false;
                break;
            }
        }

         if (allWordsPresent) {
            int frequency = 0;
            for (const auto& word: Words) {
                frequency += document.second.at(word);
            }
            result.push_back(make_pair(document.first, frequency));
        }
    }
    // Ordenação do resultado de acordo com os critérios estabelecidos.
    sort(result.begin(), result.end(), compare);
    return result;
}