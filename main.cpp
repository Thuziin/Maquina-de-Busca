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
	
	while (true) {
		string palavra;
		cout << "Informe qual(s) palavra(s) deseja: (digite exit para encerar): ";
		getline(cin, palavra);
		if (palavra == "exit") {
			cout << "Encerrando ..." << endl;
			break;
		}
		vector<string> resultado = elemento.Pesquisa(palavra);

		if (resultado.empty()) {
			cout << "A(s) palavra(s) pesquisada(s) não foram encontrada(s)!" << endl;
		} else {
			for (auto it: resultado) {
				cout << it << endl;
			}
		}

	}

	return 0;
}