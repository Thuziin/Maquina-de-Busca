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
		// Iteração para acesssar cada arquivo do diretório informado
		for (const auto& entry : filesystem::directory_iterator(caminhoDiretorio_)){
			if (entry.is_regular_file()) {
				ifstream file(entry.path());

				if (!file) {
					throw falhaDocumento{(entry.path().filename().string())};
				}
				
				if (file) {
					string palavra;
					vector<string> palavras;
					// Percorrendo o arquivo atual e guardando palavra por palavra em um vector de palavras
					while (file >> palavra) {
						palavras.push_back(palavra);
					}

					// Guardando no vector de documentos o nome do documento atual e suas respectivas palavras
					documentos.emplace_back(entry.path().filename().string(), palavras);
				}
			}
		}
	} catch (exception& e) {
		cerr << "Erro: " << e.what() << endl;
		exit(1);
	}
	
	return documentos;
}