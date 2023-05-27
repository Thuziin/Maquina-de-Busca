#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <map>

#include "document.cpp"

using namespace std;

// Para o programa compilar é necessário usar a versão do c++17

int main () {
	string caminho = "./documents";
	Document arquivo(caminho);
	vector<pair<string, vector<string>>> documentos = arquivo.DocumentReader();
	map<string, map<string, int>> documentoCerto;

	for (const auto it: documentos) {
		for (auto palavra: it.second) {
			documentoCerto[it.first][palavra]++;
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