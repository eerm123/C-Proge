#include "kodu4.h"
#include <iostream>
#include <concepts>

using namespace std;

int main() {
    cout << liida(5, 6) << endl;
    cout << boolalpha << onVahemikus<5>(1, 10) << endl;

    cout << endl;

    Massiiv<int> m{};
    m.lisaElement(5);
    m.lisaElement(8);
    m.lisaElement(5);
    m.lisaElement(5);
    m.print();
    m.kustutaElement();
    m.print();
    m.lisaElement(25);
    m.asendaElement(m.getElement(0), 9);
    m.print();
    cout << m.getElement(8) << '\n';
    cout << boolalpha << m.kasTais() << '\n';
    cout << m.vabuKohti() << " " << m.kasSisaldub(23) << " " << m.getSuurus() << '\n';

    return 0;
}
