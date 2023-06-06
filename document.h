#ifndef DOCUMENT_H_
#define DOCUMENT_H_

#include <iostream>
#include <string>
#include <vector>

#include <filesystem>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

class Document {
    public:
        // Construtor que inicializar recebendo o caminho para o diretório com os documentos .txt
        Document (string caminho);

        // Leitura dos documentos .txt e sua normalização antes de devolver para o usuário
        vector<pair<string, vector<string>>> DocumentReader();

    private:
        string caminhoDiretorio_;
};

#endif