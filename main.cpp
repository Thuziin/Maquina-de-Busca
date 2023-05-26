#include <iostream>
#include <string>
#include <filesystem>

#include "document.cpp"

using namespace std;

int main () {
	string caminho = "./documents";
	Document sla(caminho);
	vector<string> documents = sla.DocumentReader();

	for (auto document: documents) {
		cout << document << endl;
	}
	return 0;
}