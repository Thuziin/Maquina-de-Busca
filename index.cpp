#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

class Index {
    public:
        // Construtor da classe Index.
        Index (vector<pair<string, vector<string>>> documento) {
            for (auto it: documento) {
                for (auto palavra: it.second) {
                    dicionario_[it.first][normalizarPalavra(palavra)]++;
                }
            }
        }

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
                
            return palavraNormalizada;
        }

        vector<string> Pesquisa (string pesquisa) {
            vector<string> todasPalavras;
            string palavra;
            istringstream iss(pesquisa);
            while (iss >> palavra) {
                todasPalavras.push_back(normalizarPalavra(palavra));
            }           

            vector<string>resultado;

            for (auto documento: dicionario_) {
                bool todasPalavrasPresentes = true;
                for (const auto& palavra: todasPalavras) {
                    if (documento.second.find(palavra) == documento.second.end()) {
                        todasPalavrasPresentes = false;
                        break;
                    }
                }

                if (todasPalavrasPresentes) {
                    resultado.push_back(documento.first);
                }
            }
            return resultado;
        }
    
    private:
        map<string, map<string, int>> dicionario_; // Variável que armazena os elementos dos documetos.
};