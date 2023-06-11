#ifndef DOCUMENT_H_
#define DOCUMENT_H_

#include <string>
#include <vector>

using namespace std;

/**
 * @brief: struct falhaDocumento: armazena o(s) nome(s) do(s) documento(s) que não foram possíveis de ler.
*/
struct documentFailure {
    string faultyDocument;
};

/**
 * @brief class Document: acessa o diretório dos documentos, realiza suas leituras e 
 *        armazena suas informações.
*/
class Document {
    public:
        // Construtor da classe Document.
        Document (string path);

        // Método que realiza leitura e armazena os dados dos documentos.
        vector<pair<string, vector<string>>> DocumentReader();

    private:
        string directoryPath_; // Váriavel que recebe o caminho para o diretório dos documentos.
};

#endif