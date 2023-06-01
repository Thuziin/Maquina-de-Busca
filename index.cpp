#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

#include <algorithm>
#include <cctype>

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

        void Pesquisa (vector<string> pesquisa) {
            map<string, int> resultado;            
            string query;
            for (auto j: pesquisa) {
                query = normalizarPalavra(j);
                for (auto it: dicionario_) {
                    for (auto info: it.second) {
                        if (info.first == query) {
                            resultado[it.first] = info.second;
                        }
                    }
                }
            }

            if (resultado.empty()) {
                cout << "A palavra passada " << query << " não está em nenhum documento" << endl;
            } else {
                for (auto k: resultado) {
                    cout << k.first << endl;
                }
            }

            // for (auto it: dicionario_) {
            //     cout << it.first << endl;
            //     for (auto i: it.second) {
            //         cout << i.first << " - ";
            //     }
            //     cout << endl;
            // }
        }
    
    private:
        map<string, map<string, int>> dicionario_; // Variável que armazena os elementos dos documetos.
};