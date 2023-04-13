#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ofstream logFile("logs.txt");

    if(!logFile)
        throw invalid_argument("Le fichier n'a pas pu être créé");

    logFile << "Démarrage du programme" << endl;

    cout << "Entrez le chemin du fichier à cloner" << endl;

    string inputFilePath;
    getline(cin, inputFilePath);
    std::ifstream inputFile(inputFilePath);


    if(!inputFile) {
        logFile << "Le fichier n'existe pas" << endl;
        throw invalid_argument("Le fichier n'existe pas");
    }

    string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    size_t dotPostion = inputFilePath.find_last_of(".");
    string extension = inputFilePath.substr(dotPostion);

    string fileName = inputFilePath.substr(inputFilePath.find_last_of('/'));
    string fileNameWithoutExt = fileName.substr(1, fileName.find_first_of('.') -1);

    string outputFilePath = fileNameWithoutExt + "-clone" + extension;

    ofstream outputFile(outputFilePath);

    if(!outputFile) {
        throw invalid_argument("Le fichier n'a pas pu être créé");
        logFile << "Le fichier n'a pas pu être créé" << endl;
    }

    outputFile << fileContent;
    outputFile.close();

    logFile << "Fichier cloné avec succès" << endl;

    return 0;
}