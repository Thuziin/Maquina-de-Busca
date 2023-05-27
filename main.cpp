#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

#include "document.cpp"

using namespace std;

// Para o programa compilar é necessário usar a versão do c++17

int main () {
	string caminho = "./documents";
	Document arquivo(caminho);
	vector<pair<string, vector<string>>> documentos = arquivo.DocumentReader();

	for (auto it: documentos) {
		cout << "Arquivo: " << it.first << endl;
		cout << "Palavras: " << endl;
		for (auto palavra: it.second) {
			cout << palavra << endl;
		}
	}
	return 0;
}