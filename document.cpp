#include <iostream>
#include <string>
	
#include <filesystem>
#include <vector>
#include <fstream>

#include <algorithm>
#include <cctype>

using namespace std;

class Document {
	public:
		// Construtor que inicializar recebendo o caminho para o diretório com os documentos .txt
		Document (string caminho) {
			caminhoDiretorio_ = caminho;
		}

		// Leitura dos documentos .txt e sua normalização antes de devolver para o usuário
		vector<pair<string, vector<string>>> DocumentReader () {
			vector<pair<string, vector<string>>> documentos;
			
			// Iteração para acesssar cada arquivo do diretório informado
			for (const auto& entry : filesystem::directory_iterator(caminhoDiretorio_)){
				if (entry.is_regular_file()) {
					ifstream file(entry.path());

					if (file) {
						string palavra;
						vector<string> palavras;

						// Percorrendo o arquivo atual e guardando palavra por palavra em um vector de palavras
						while (file >> palavra) {
							palavras.push_back(normalizarPalavra(palavra));
						}

						// Guardando no vector de documentos o nome do documento atual e suas respectivas palavras
						documentos.emplace_back(entry.path().filename().string(), palavras);
					}
				}
			}
			return documentos;
		}

		// Função que realiza todas as correções necessárias

		string normalizarPalavra (const string palavra) {
			string palavraNormalizada = palavra;
		    // Transformando a palavara para minúscula
		    transform(
		        palavraNormalizada.begin(), palavraNormalizada.end(), palavraNormalizada.begin(),[](unsigned char c){
		            return tolower(c); 
		    });

		    // Removendo caracteres  !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
		    palavraNormalizada.erase(
		        remove_if(palavraNormalizada.begin(), palavraNormalizada.end(), [](unsigned char c) {
		            return ispunct(c);
		        }),
		    palavraNormalizada.end());

		    // Removendo numeração
		    palavraNormalizada.erase(
		        remove_if(palavraNormalizada.begin(), palavraNormalizada.end(), [](unsigned char c) {
		            return isdigit(c);
		        }),
		    palavraNormalizada.end());
		    
		    // Removendo acento e cedilha
		        

		    return palavraNormalizada;
		}

	private:
		string caminhoDiretorio_;
};