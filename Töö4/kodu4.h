#ifndef KODU4_H
#define KODU4_H

#include <iostream>
#include <concepts>
#include <string>

using namespace std;

// Mallifunktsioonid
template<typename T, typename N>
requires integral<T> || floating_point<T> || is_same<T, string>::value
T liida(T a, N b) {
    return a + b;
};

template<int N>
bool onVahemikus(int min, int max) {
    return (N >= min && N <= max);
}


// Klass Massiiv
template<typename T>
requires integral<T> || floating_point<T>
class Massiiv {
private:
    static const int MAKS_PIKKUS = 100;
    T massiiv[MAKS_PIKKUS];
    int suurus;

public:
    Massiiv();
    T getElement(int i);
    bool kasTais();
    int getSuurus();
    void print();
    void lisaElement(T el);
    void kustutaElement();
    void asendaElement(T el1, T el2);
    int vabuKohti();
    bool kasSisaldub(T el);
};

template<typename T>
Massiiv<T>::Massiiv() : suurus(0) {
    for (int i = 0; i < MAKS_PIKKUS; ++i) {
        massiiv[i] = T();
    }
}

template<typename T>
T Massiiv<T>::getElement(int i) {
    if (i >= 0 && i < suurus) {
        return massiiv[i];
    } else {
        return -1111;
    }
}

template<typename T>
bool Massiiv<T>::kasTais() {
    return suurus == MAKS_PIKKUS;
}

template<typename T>
int Massiiv<T>::getSuurus() {
    return suurus;
}

template<typename T>
void Massiiv<T>::print() {
    for (int i = 0; i < suurus; ++i) {
        cout << massiiv[i] << " ";
    }
    cout << endl;
}

template<typename T>
void Massiiv<T>::lisaElement(T el) {
    static_assert(liida<T, T>);
    if (suurus < MAKS_PIKKUS) {
        massiiv[suurus++] = el;
    }
}

template<typename T>
void Massiiv<T>::kustutaElement() {
    if (suurus > 0) {
        massiiv[--suurus] = T();
    }
}

template<typename T>
void Massiiv<T>::asendaElement(T el1, T el2) {
    for (int i = 0; i < suurus; ++i) {
        if (massiiv[i] == el1) {
            massiiv[i] = el2;
        }
    }
}

template<typename T>
int Massiiv<T>::vabuKohti() {
    return MAKS_PIKKUS - suurus;
}

template<typename T>
bool Massiiv<T>::kasSisaldub(T el) {
    for (int i = 0; i < suurus; ++i) {
        if (massiiv[i] == el) {
            return true;
        }
    }
    return false;
};

#endif
