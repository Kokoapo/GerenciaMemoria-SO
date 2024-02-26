#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string PATH_LOG = "../logs/trace";
string PATH_REF = "../reference_strings/ref";
int count_lines(ifstream &infile)
{
    int lines = 0;
    string temp;
    while (getline(infile, temp))
        lines++;
    infile.clear();
    infile.seekg(0);
    return lines;
}
int main(int argc, char **argv)
{
    if (argc != 3 || atoi(argv[1]) < 1 || atoi(argv[1]) > 4 || atoi(argv[2]) < 1 || atoi(argv[2]) > 100)
    {
        cout << "Forma de executar: criar_reference_string.exe <numero do arquivo de log (entre 1 e 4)> <tamanho da reference string>\n";
        return 0;
    }

    ifstream log(PATH_LOG + argv[1]);
    ofstream ref(PATH_REF + argv[2] + "log" + argv[1]);
    if (!log.is_open() || !ref.is_open())
    {
        cout << "Falha ao abrir os arquivos\n";
        return -1;
    }

    int max_log = count_lines(log), logN = atoi(argv[1]), refT = atoi(argv[2]);

    refT = (max_log * refT) / 100;
    ref << std::hex;
    unsigned int ultimo = 0xFFFFFFFF;
    for (int i = 0; i < refT; i++)
    {
        string end;
        getline(log, end);
        unsigned int addr = stoul(end, nullptr, 16);

        addr = addr & 0xFFFFF000;
        if (addr != ultimo)
        {
            ref << addr << endl;
            ultimo = addr;
        }
    }

    log.close();
    ref.close();
    return 0;
}
