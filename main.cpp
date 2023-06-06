#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "document.h"
#include "index.cpp"

using namespace std;

// Para o programa compilar é necessário usar a versão do c++17

// Definindo um tipo para o par de documento e frequência
typedef std::pair<std::string, int> DocumentoFrequencia;

// Função para comparar dois pares com base na frequência (usada pela std::sort)
bool compararFrequencia(const DocumentoFrequencia& a, const DocumentoFrequencia& b) {
    return a.second > b.second;  // Ordem crescente
}

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

		vector<pair<string, int>> resultado = elemento.Pesquisa(palavra);
		set<string> documentoOrdenados;
		
		if (resultado.empty()) {
			cout << "Sua pesquisa não apresenta resultado!" << endl;
		} else {
			sort(resultado.begin(), resultado.end(), compararFrequencia);
			for (auto it: resultado) {
				cout << it.first << endl;
			}
		}

	}

	return 0;
}