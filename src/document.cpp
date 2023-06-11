#include "document.h"

#include <iostream>

#include <filesystem>
#include <algorithm>
#include <fstream>
#include <cctype>

#include <cstdlib>

using namespace std;

Document::Document (string path) {
	directoryPath_ = path;
}

vector<pair<string, vector<string>>> Document::DocumentReader () {
	vector<pair<string, vector<string>>> docs;

	try {
		if (filesystem::is_empty(directoryPath_)) {
			throw runtime_error("O diretório está vazio.");
		}
		// Iteração para percorrer os documentos presentes no diretório
		for (const auto& entry : filesystem::directory_iterator(directoryPath_)){
			if (entry.is_regular_file()) {
				ifstream file(entry.path());

				if (!file) {
					// Lançando excessão caso não seija possivél ler algum documento.
					throw documentFailure{(entry.path().filename().string())};
				}
				
				if (file) {
					string str;
					vector<string> Words;

					while (file >> str) {
						Words.push_back(str);
					}
					// Armazenando o nome do documento e suas palavras.
					docs.emplace_back(entry.path().filename().string(), Words);
				}
			}
		}
	} catch (exception& e) {
		// Tratando exceção caso o diretório esteja vazio, depois encerra o programa.
		cerr << "Erro: " << e.what() << endl;
		exit(1);
	}
	
	return docs;
}