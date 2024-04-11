#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "src/Utils.hpp"
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("data.csv");

    if(fin.fail())
    {
        cerr << "file not found" << endl;
        return 1;
    }

    ofstream fou("result.txt");

    string line;
    vector<double> w;
    vector<double> r;
    double S;
    int n;

    while (getline(fin, line)) {

        if (line.empty() || line[0] == 'w') {
            continue; // Ignora le righe non contenenti valori numerici
        }
        else if (line[0] == 'S') {
            S=stoi(line.substr(2));
        }
        else if (line[0] == 'n') {
            n=stoi(line.substr(2));
        }
        else {
            size_t c = line.find(';');
            r.push_back(stod(line.substr(c+1)));
            w.push_back(stod(line.erase(c)));

        }
    }

    fou <<"S "<<"= "<<fixed<<setprecision(2)<<S<<", "<<"n "<<"= "<<n<< endl;
    fou <<"w "<<"= "<<"[ "<<w<<"]"<<endl;
    fou <<"r "<<"= "<<"[ "<<r<<"]"<<endl;





    fin.close();
    fou.close();

  return 0;
}

