#ifndef INDEX_H_
#define INDEX_H

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
        Index (vector<pair<string, vector<string>>> documento);

        // Método que normaliza as palavras dos documentos
        string normalizarPalavra (const string palavra);

        // Separação termo a termo dos elementos passados para Pesquisa
        vector<string> divisaoPalavra (string pesquisa);

        // Método que faz a comparação para a ordenação da Pesquisa (1º maior repetição, 2º ordem lexicográfica)
        static bool compare (pair<string, int> a, pair<string, int> b);

        // Método que realiza pesquisa com base na entrada do usuário
        vector<pair<string, int>> Pesquisa (string pesquisa);
        
    private:
        map<string, map<string, int>> dicionario_; // Variável que armazena os elementos dos documetos.      
};

#endif