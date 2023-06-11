#ifndef DOCUMENT_H_
#define DOCUMENT_H_

#include <string>
#include <vector>

using namespace std;

/**
 * @brief: struct falhaDocumento: armazena o(s) nome(s) do(s) documento(s) que não foram possíveis de ler.
*/
struct falhaDocumento {
    string documentoComErro;
};

/**
 * @brief class Document: acessa o diretório dos documentos, realiza suas leituras e 
 *        armazena suas informações.
*/
class Document {
    public:
        // Construtor da classe Document.
        Document (string caminho);

        // Método que realiza leitura e armazena os dados dos documentos.
        vector<pair<string, vector<string>>> DocumentReader();

    private:
        string caminhoDiretorio_; // Váriavel que recebe o caminho para o diretório dos documentos.
};

#endif