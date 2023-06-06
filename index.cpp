#include "index.h"

using namespace std;

Index::Index (vector<pair<string, vector<string>>> documento) {
    for (auto it: documento) {
        for (auto palavra: it.second) {
            dicionario_[it.first][normalizarPalavra(palavra)]++;
        }
    }
}

string Index::normalizarPalavra (string palavra) {
    string palavraNormalizada = palavra;
    // Transformando a palavara para minúscula
    transform(
        palavraNormalizada.begin(), palavraNormalizada.end(), palavraNormalizada.begin(),[](unsigned char c){
            return tolower(c); 
    });

     // Removendo caracteres  !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
    palavraNormalizada.erase(
        remove_if(palavraNormalizada.begin(), palavraNormalizada.end(), [](unsigned char c) {
            return ispunct(c);
        }),
    palavraNormalizada.end());

    // Removendo numeração
    palavraNormalizada.erase(
        remove_if(palavraNormalizada.begin(), palavraNormalizada.end(), [](unsigned char c) {
            return isdigit(c);
        }),
    palavraNormalizada.end());
                
    return palavraNormalizada;
}

vector<string> Index::divisaoPalavra(string pesquisa) {
    vector<string> todasPalavras;
    string palavra;
    istringstream iss(pesquisa);
    while (iss >> palavra) {
        todasPalavras.push_back(normalizarPalavra(palavra));
    }
    return todasPalavras;
}

bool Index::compare (pair<string, int> a, pair<string, int> b) {
    return a.second > b.second; 
} 

vector<pair<string, int>> Index::Pesquisa (string pesquisa) {        
    vector<string> todasPalavras = divisaoPalavra(pesquisa);
    vector<pair<string,int>>resultado;

    for (auto documento: dicionario_) {
        bool todasPalavrasPresentes = true;
        for (const auto& palavra: todasPalavras) {
            if (documento.second.find(palavra) == documento.second.end()) {
                todasPalavrasPresentes = false;
                break;
            }
        }

         if (todasPalavrasPresentes) {
            int frequencia = 0;
            for (const auto& palavra: todasPalavras) {
                frequencia += documento.second.at(palavra);
            }
            resultado.push_back(make_pair(documento.first, frequencia));
        }
    }
    sort(resultado.begin(), resultado.end(), compare);
    return resultado;
}