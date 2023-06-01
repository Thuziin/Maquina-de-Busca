#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "document.cpp"

using namespace std;

// Para o programa compilar é necessário usar a versão do c++17

int main () {

	string caminho = "./documents";

	Document arquivo(caminho);
    
	vector<pair<string, vector<string>>> documentos = arquivo.DocumentReader();

	return 0;
}