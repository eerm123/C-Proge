#ifndef HARJUTUS1_H
#define HARJUTUS1_H

#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;


template<typename T, int N = 10>
T liidaJaPiira(T a, T b) {
    T summa = a + b;
    return (summa < N) ? summa : N;
}

template<typename T>
void looFailKirjuta(fs::path asukoht, T elemendid[], size_t arv) {
    ofstream fail(asukoht);

    for (size_t i = 0; i < arv; ++i) {
        fail << elemendid[i] << '\n';
    }

    if (!fail.is_open()) {
        cerr << "Faili ei leitud" << '\n';
        return;
    }

    fail.close();

    cout << "Fail loodud ja kirjutatud: " << asukoht << '\n';
}

#endif
