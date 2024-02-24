#include <fstream>
#include <string>
#include "page-algorithms.h"

using namespace std;

string PATH_REF = "../reference_strings/";

int main(int argc, char **argv) {
    if (argc != 4 || (atoi(argv[2]) != 4 && atoi(argv[2]) != 8 && atoi(argv[2]) != 16 && atoi(argv[2]) != 32) || (atoi(argv[3]) != 0 && atoi(argv[3]) != 1)) {
        cout << "Forma de executar: main.exe <nome da reference string> <numero de frames livres (4, 8, 16, 32)> <algoritmo de substituicao (0 = OPT, 1 = LRU)\n";
        return 0;
    }

    unsigned int *frames = new unsigned int[atoi(argv[2])];
    for(int i = 0; i < atoi(argv[2]); i++) {
        frames[i] = 0xFFFFFFFF;
    }
    unsigned int *referenceString = new unsigned int[6287037];
    string hexStr;
    ifstream log(PATH_REF+argv[1]);
    if (!log.is_open()) {
        cout << "Falha ao abrir o arquivo\n";
        return -1;
    }
    
    int refStrT = 0;
    while(getline(log, hexStr)) {
        referenceString[refStrT++] = stoul(hexStr, nullptr, 16);
    }
    log.close();

    unsigned int resultado;
    switch (atoi(argv[3])) {
        case 0:
            resultado = OPT(frames, atoi(argv[2]), referenceString, refStrT);
            break;
        case 1:
            resultado = LRU(frames, atoi(argv[2]), referenceString, refStrT);
            break;
        default:
            break;
    }

    cout << "# de Page Faults: " << (int)resultado << endl;
    return 0;
}
