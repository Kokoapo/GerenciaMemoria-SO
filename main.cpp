#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string PATH = "../logs/trace";

int main(int argc, char **argv) {
    if (argc != 3 || atoi(argv[1]) < 1 || atoi(argv[1]) > 4 || atoi(argv[2]) != 4 || atoi(argv[2]) != 8 || atoi(argv[2]) != 16 || atoi(argv[2]) != 32) {
        cout << "Forma de executar: main <numero do arquivo de log (entre 1 e 4)> <numero de frames livres (4, 8, 16, 32)>";
        return 0;
    }

    int *referenceString = new int[atoi(argv[2])];
    string hexStr;
    ifstream log(PATH+argv[1]);
    if (!log.is_open()) return -1;
    
    while(getline(log, hexStr)) {
        unsigned int addr = stoul(hexStr, nullptr, 16);
        unsigned int pagina = addr & 0xFFFFF000;
        cout << hex << hexStr << ' ' << addr << ' ' << pagina << endl;
    }

    log.close();
    return 0;
}