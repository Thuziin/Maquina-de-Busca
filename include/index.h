#ifndef INDEX_H_
#define INDEX_H

#include <string>
#include <vector>
#include <map>

using namespace std;

/**
 * @brief class Index: cria um dicionário (com os nomes dos documentos, suas palavras e frequência)
 *        e realiza a pesquisa desejada pelo user
 * 
 * @note: Esta classe possui métodos que auxiliam na construção do dicionario e na realização da pesquisa
*/
class Index {
    public:
        // Construtor da classe Index.
        Index (vector<pair<string, vector<string>>> documents);

        // Método que normaliza as palavras dos documentos/pesquisa.
        string standardizeWord (const string word);

        // Método que separa termo a termo os elementos passados para Pesquisa().
        vector<string> wordDivision (string query);

        // Método que faz a comparação para a ordenação da Pesquisa (1º maior repetição,
        // 2º ordem lexicográfica)
        static bool compare (pair<string, int> a, pair<string, int> b);

        // Método que realiza pesquisa com base na entrada do usuário
        vector<pair<string, int>> Search (string query);
        
    private:
        map<string, map<string, int>> dictionary_; // Dicionario contendo os informações dos documentos.      
};

#endif