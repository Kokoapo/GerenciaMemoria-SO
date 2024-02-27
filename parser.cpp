#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
string PATH_REF = "../reference_strings/";
string PATH_RES = "resultado/";
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
int get_faults(string str)
{
    int final = 0;
    for (auto it = str.begin(); it != str.end();)
    {
        char c = *it;
        if (c >= '0' && c <= '9')
            break;
        it = str.erase(it);
    }
    stringstream s(str);
    s >> final;
    return final;
}
void open_file(ifstream &infile, string name)
{
    if (infile.is_open())
        infile.close();
    infile.open(name);
    if(!infile)
    {
        cout << "error: " << name << endl;
        exit(-1);
    }
}
int main()
{
    ifstream file;
    ofstream outfile("resultados.txt");
    outfile << "log\tpercentagem\tframes livres\tALG\tfaults\ttotal de entradas\n";
    for(int l=1; l<=4; l++)
    {
        for(int p=10; p<=100; p+=10)
        {
            open_file(file, PATH_REF+"ref"+to_string(p)+"log"+to_string(l));
            auto entries = count_lines(file);
            file.close();
            for(int f=4; f<=32; f*=2)
            {
                for(int t=0; t<=1; t++)
                {
                    open_file(file, PATH_RES+"ref"+to_string(p)+"log"+to_string(l)+" "+to_string(f)+" "+to_string(t));
                    stringstream ss;
                    ss << file.rdbuf();
                    auto faults = get_faults(ss.str());
                    outfile << l << '\t' << p << '\t' << f << '\t' << (t? "LRU\t" : "OPT\t") << faults << '\t' << entries << endl;
                    file.close();
                }
            }
        }
    }
    outfile.close();
}