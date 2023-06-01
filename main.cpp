#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "document.cpp"
#include "index.cpp"

using namespace std;

// Para o programa compilar é necessário usar a versão do c++17

int main () {

	string caminho = "./documents";

	Document arquivo(caminho);
    
	vector<pair<string, vector<string>>> documentos = arquivo.DocumentReader();

	Index elemento(documentos);
	
	bool escolha = true;
	while (escolha) {
		vector<string> query;
		string word;
		cout << "Insira a(s) palavra(s) que deseja (digite exit para terminar): ";
		while (cin >> word) {
			if (word == "exit") {
				escolha = false;
			} else {
				query.push_back(word);
				elemento.Pesquisa(query);
			}
			break;
		}
		break;
		
	}

	return 0;
}