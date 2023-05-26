#include <iostream>
#include <string>
#include <filesystem>

#include "document.cpp"

using namespace std;

// Para o programa compilar é necessário usar a versão do c++17

int main () {
	string caminho = "./documents";
	Document arquivo(caminho);
	vector<string> documents = arquivo.DocumentReader();

	for (auto document: documents) {
		cout << document << endl;
	}
	return 0;
}