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
    double V=0;
    double R;

    while (getline(fin, line)) {
        size_t c = line.find(';');

        if (line.empty() || line[0] == 'w') {
            continue;
        }
        else if (line[0] == 'S') {
            S=stoi(line.substr(c+1));
        }
        else if (line[0] == 'n') {
            n=stoi(line.substr(c+1));
        }
        else {
            r.push_back(stod(line.substr(c+1)));
            w.push_back(stod(line.erase(c)));

        }
    }

    for(int i=0;i<n;i++){
        V=V+w[i]*S*(1+r[i]);
    }

    R=V/S-1;

    fou <<"S "<<"= "<<fixed<<setprecision(2)<<S<<", ";
    fou<<"n "<<"= "<<n<< endl;
    fou <<"w "<<"= "<<"[ "<<w<<"]"<<endl;
    fou <<"r "<<"= "<<"[ "<<r<<"]"<<endl;
    fou <<"Rate of return of the portfolio: "<<setprecision(4)<<R<<endl;
    fou <<"V: "<<setprecision(2)<<V<<endl;


    fin.close();
    fou.close();

  return 0;
}

