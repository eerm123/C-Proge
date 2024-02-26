#include <iostream>
#include <fstream>
#include <map>
#include <cctype>

using namespace std;

void sagedus(const string& failinimi) {
    ifstream fail(failinimi);

    if (!fail.is_open()) {
        cerr << "Faili " << failinimi << " ei leitud" << endl;
        return;
    }

    map<char, int> sagedused;
    
    string rida;
    while (getline(fail, rida)) {
        for (char symbol : rida) {
            if (isalpha(symbol) || isdigit(symbol)) {
                symbol = tolower(symbol);
                sagedused[symbol]++;
            }
        }
    }

    char korgeim_sumbol = ' ';
    int korgeim_sagedus = 0;

    for (const auto& paar : sagedused) {
        if (paar.second > korgeim_sagedus) {
            korgeim_sumbol = paar.first;
            korgeim_sagedus = paar.second;
        }
    }

    cout << korgeim_sumbol << ": " << korgeim_sagedus << endl;

}

int main() {
    sagedus("/home/eero/sisend.txt");
    sagedus("/home/eero/ei_eksisteeri.txt");
    return 0;
}