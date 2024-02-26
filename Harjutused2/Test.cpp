#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>

using std::default_random_engine, std::uniform_int_distribution;;
using std::vector;

void prindi_kohad(std::vector<std::vector<bool>> kohad) {
    for (size_t i = 0; i < kohad.size(); i++) {
        std::cout << (i + 1) << " ";
        for (size_t j = 0; j < kohad.size(); j++) {
            char x = 'A' + j;
            std::cout << (kohad[i][j] ? 'X' : x) << " ";
        }
        std::cout << '\n';
    }
}

int main() {
    default_random_engine genereerija;
    uniform_int_distribution<int> jaotus(0, ISTMETE_ARV);

    const ISTMETE_ARV = 4;
    const RIDADE_ARV = 6;
    vector<vector<bool>> kohad;

    for (int i =; i < RIDADE_ARV; i++) {
        kohad.push_back(vector<bool>(ISTMETE_ARV, false));
    }
    
}
