#include "document.h"

#include <iostream>

#include <filesystem>
#include <algorithm>
#include <fstream>
#include <cctype>

#include <cstdlib>

using namespace std;

Document::Document (string caminho) {
	caminhoDiretorio_ = caminho;
}

vector<pair<string, vector<string>>> Document::DocumentReader () {
	vector<pair<string, vector<string>>> documentos;

	try {
		if (filesystem::is_empty(caminhoDiretorio_)) {
			throw runtime_error("O diretório está vazio.");
		}
		// Iteração para percorrer os documentos presentes no diretório
		for (const auto& entry : filesystem::directory_iterator(caminhoDiretorio_)){
			if (entry.is_regular_file()) {
				ifstream file(entry.path());

				if (!file) {
					// Lançando excessão caso não seija possivél ler algum documento.
					throw falhaDocumento{(entry.path().filename().string())};
				}
				
				if (file) {
					string palavra;
					vector<string> palavras;

					while (file >> palavra) {
						palavras.push_back(palavra);
					}
					// Armazenando o nome do documentos e suas palavras.
					documentos.emplace_back(entry.path().filename().string(), palavras);
				}
			}
		}
	} catch (exception& e) {
		// Tratando exceção caso o diretório esteja vazio, depois encerra o programa.
		cerr << "Erro: " << e.what() << endl;
		exit(1);
	}
	
	return documentos;
}