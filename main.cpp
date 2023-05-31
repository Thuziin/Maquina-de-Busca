#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "document.cpp"

using namespace std;

// Para o programa compilar é necessário usar a versão do c++17

// Função que realiza todas as correções necessárias

string normalizarPalavra (const string palavra) {
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
    
    // Removendo acento e cedilha
        
    return palavraNormalizada;
}

int main () {
	string caminho = "./documents";
	Document arquivo(caminho);
	vector<pair<string, vector<string>>> documentos = arquivo.DocumentReader();
	map<string, map<string, int>> documentoCerto;

	for (const auto it: documentos) {
		for (auto palavra: it.second) {
			documentoCerto[it.first][normalizarPalavra(palavra)]++;
		}
	}

	for (const auto it: documentoCerto) {
		cout << "Documento: " << it.first << endl;
		for (const auto info: it.second) {
			cout << "Palavra: " << info.first << " - " << "Qtd: " << info.second << endl;
		}
		cout << endl;
	}
	return 0;
}