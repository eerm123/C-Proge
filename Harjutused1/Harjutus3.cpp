#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float raadius;

    cout << "Sisesta ringi raadius: ";
    cin >> raadius;
    float pindala = (M_PI * pow(raadius, 2));
    cout << "Ringi pindala: " << fixed << setprecision(2) << pindala << '\n';
    cout << "Ringi ümbermõõt: " << fixed << setprecision(2) << (2* M_PI * raadius) << '\n';
    cout << "Raadius kaks korda väiksema pindala korral: " << fixed << setprecision(2) << sqrt((pindala/2) / M_PI) << '\n';
    return 0;
}