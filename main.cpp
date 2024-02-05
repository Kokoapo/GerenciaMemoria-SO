#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string PATH_REF = "../reference_strings/";

int main(int argc, char **argv) {
    if (argc != 4 || (atoi(argv[2]) != 4 && atoi(argv[2]) != 8 && atoi(argv[2]) != 16 && atoi(argv[2]) != 32) || (atoi(argv[3]) != 0 && atoi(argv[3]) != 1)) {
        cout << "Forma de executar: main.exe <nome da reference string> <numero de frames livres (4, 8, 16, 32)> <algoritmo de substituicao (0 = OPT, 1 = LRU)\n";
        return 0;
    }

    int *referenceString = new int[atoi(argv[2])];
    string hexStr;
    ifstream log(PATH_REF+argv[1]);
    if (!log.is_open()) {
        cout << "Falha ao abrir o arquivo\n";
        return -1;
    }
    
    while(getline(log, hexStr)) {
        unsigned int addr = stoul(hexStr, nullptr, 16);
        unsigned int pagina = addr & 0xFFFFF000;
        cout << hex << hexStr << ' ' << addr << ' ' << pagina << endl;
    }

    log.close();
    return 0;
}