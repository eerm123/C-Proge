#include "kodu3_fun_dekl.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

int fun(int a, int b) {
    return a + b; 
}

int fun(double x) { 
    return static_cast<int>(std::round(x * x));
}

string fun(unsigned int n, string str) {
    string result;
    for (unsigned int i = 0; i < n; ++i) {
        result += str;
    }
    return result; 
}

double kehamassiindeks(double pikkus, double kaal) { 
    return kaal / (pikkus * pikkus); 
}

string hinnang(double index) { 
    if (index < 18.5) {
        return "alakaal";
    } else if (index < 24.9) {
        return "normaalkaal";
    } else if (index < 29.9) {
        return "ülekaal";
    } else {
        return "rasvumine"; 
    }
}

// string otsi_mustrit(int& argc, char* argv[]) {
//     return {};
// }

unsigned long int faktoriaal_li(int n) { 
    if (n < 0) {
        return 0;
    }
    unsigned long int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result; 
}

string otsi_mustrit(int& argc, char* argv[]) { 
    if (argc < 3) {
        cerr << "Kasutamine: " << argv[0] << " -otsi=otsitav_sõne argument1 argument2..." << endl;
        return "Mustrit ei ole olemas.";
    }

    string otsitav_muster = "-otsi=";
    for (int i = 1; i < argc; ++i) {
        string argument = argv[i];
        size_t leitud_indeks = argument.find(otsitav_muster);
        if (leitud_indeks != string::npos) {
            return "Otsitav '" + argument.substr(leitud_indeks + otsitav_muster.length()) + "' leiti.";
        }
    }
    return "Mustrit ei ole olemas"; 
}

void andmed_failist(const string& failinimi) { 
    ifstream fail(failinimi);
    if (!fail) {
        cerr << "Faili avamine ebaõnnestus" << endl;
        return;
    }

    double arv;
    vector<double> rea_arvud;
    while (fail >> arv) {
        rea_arvud.push_back(arv);
    }
    
    fail.close();

    double rea_keskmine = accumulate(rea_arvud.begin(), rea_arvud.end(), 0.0) / rea_arvud.size();

    ofstream tulemused_fail("tulemused.txt");
    if (tulemused_fail) {
        for (double arv : rea_arvud) {
            tulemused_fail << arv << " ";
        }
        tulemused_fail << endl << rea_keskmine << endl;
    } else {
        cerr << "Tulemuste faili avamine ebaõnnestus" << endl;
    }
}

#if !defined(VPL_TEST)  // See main funktsioon kommenteeritakse välja
int main(int argc, char* argv[]) {
  
  // Testimine essal kodutööl
    //   int sum = fun(3, 5);
    //   cout << "Sum: " << sum << endl;
    
    //   int squared = fun(4.5);
    //   cout << "Squared and rounded: " << squared << endl;

    //   string repreatedStr = fun(10, "C++");
    //   cout << "Repeated string: " << repreatedStr << endl;


  // Testimine teisel kodutööl

    // if (argc != 3) {
    //     cerr << "Kasutamine: " << argv[0] << " <pikkus_meetrites> <kaal_kilogrammides>" << endl;
    //     return 1;
    // }

    // double pikkus = stod(argv[1]);
    // double kaal = stod(argv[2]);

    // double kmi = kehamassiindeks(pikkus, kaal);
    // cout << "kmi: " << kmi << " hinnang: " << hinnang(kmi) << '\n';

  // Tesimine kolmandal kodutööl
    
    // if (argc != 2) {
    //     cerr << "Kasutamine: " << argv[0] << " <failinimi>" << endl;
    //     return 1;
    // }

    // andmed_failist(string(argv[1]));

    return 0;
}
#endif