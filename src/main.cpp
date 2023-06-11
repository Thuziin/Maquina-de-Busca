#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "document.h"
#include "index.h"

using namespace std;

/**
 * @brief main(): Função que realiza a comunição entre todas as classes.
 * Permite realizar pesquisa e caso aconteça algum imprevisto é informado ao user.
 * 
 * @warning Necessário que a versão do c++ utilizada para compilar seja a 17.
*/

int main () {
	try {
		string path = "./documents";
		Document files(path);    
		vector<pair<string, vector<string>>> documents = files.DocumentReader();

		Index element(documents);	
		
		while (true) {
			string word;
			cout << "Informe qual(s) palavra(s) deseja: (digite exit para encerar): ";
			getline(cin, word);
			if (word == "exit") {
				cout << "Encerrando ..." << endl;
				break;
			}

			// Realizando a pesquisa de acordo com o pedido do user
			vector<pair<string, int>> result = element.Search(word);
			
			// Verificando se o resultado da pesquisa é vazia
			if (result.empty()) {
				cout << "Sua pesquisa não apresenta resultado!" << endl << endl;
			} else {
				// Percorrendo o resultado da pesquisa e monstrando na tela.
				cout << "Listando documentos: " << endl;
				int i = 1;
				for (auto it: result) {
					cout << i << ") " << it.first << endl;
					i++;
				}
				
				cout << endl;
			}

		}
	} catch (documentFailure& e) {
		// Tratamento da excessão caso algum documento não tenha sido lido.
		cout << "Não foi possível ler o documento: " << e.faultyDocument << endl;
	}

	return 0;
}