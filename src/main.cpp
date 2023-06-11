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

			// Realizando a pesquisa de acordo com o pedido do user
			vector<pair<string, int>> resultado = elemento.Pesquisa(palavra);
			
			// Verificando se o resultado da pesquisa é vazia
			if (resultado.empty()) {
				cout << "Sua pesquisa não apresenta resultado!" << endl << endl;
			} else {
				// Percorrendo o resultado da pesquisa e monstrando na tela.
				cout << "Listando documentos: " << endl;
				int i = 1;
				for (auto it: resultado) {
					cout << i << ") " << it.first << endl;
					i++;
				}
				
				cout << endl;
			}

		}
	} catch (falhaDocumento& e) {
		// Tratamento da excessão caso algum documento não tenha sido lido.
		cout << "Não foi possível ler o documento: " << e.documentoComErro << endl;
	}

	return 0;
}