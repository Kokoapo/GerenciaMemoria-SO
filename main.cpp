#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string PATH_REF = "../reference_strings/";

unsigned long long int OPT(unsigned int *frames, int framesT, unsigned int *referenceString, int refStrT) {
    cout << "OPT!\n";
    unsigned long long int pageFaults = 0;
    int *framesWorthness = new int[framesT]; 

    for (int pag = 0; pag < refStrT; pag++) {
        for (int frame = 0; frame < framesT; frame++) {
        
        }
    }

    return pageFaults;
}

unsigned long long int LRU(unsigned int *frames, int framesT, unsigned int *referenceString, int refStrT) {
    cout << "LRU!\n";
    unsigned long long int pageFaults = 0;
    
    return pageFaults;
}

int main(int argc, char **argv) {
    if (argc != 4 || (atoi(argv[2]) != 4 && atoi(argv[2]) != 8 && atoi(argv[2]) != 16 && atoi(argv[2]) != 32) || (atoi(argv[3]) != 0 && atoi(argv[3]) != 1)) {
        cout << "Forma de executar: main.exe <nome da reference string> <numero de frames livres (4, 8, 16, 32)> <algoritmo de substituicao (0 = OPT, 1 = LRU)\n";
        return 0;
    }

    unsigned int *frames = new unsigned int[atoi(argv[2])];
    unsigned int *referenceString = new unsigned int[6287037];
    string hexStr;
    ifstream log(PATH_REF+argv[1]);
    if (!log.is_open()) {
        cout << "Falha ao abrir o arquivo\n";
        return -1;
    }
    
    int refStrT = 0;
    while(getline(log, hexStr)) {
        unsigned int addr = stoul(hexStr, nullptr, 16);
        unsigned int pagina = addr & 0xFFFFF000;
        referenceString[refStrT++] = pagina;
    }
    log.close();

    switch (atoi(argv[3])) {
        case 0:
            OPT(frames, atoi(argv[2]), referenceString, refStrT);
            break;
        case 1:
            LRU(frames, atoi(argv[2]), referenceString, refStrT);
            break;
        default:
            break;
    }

    return 0;
}