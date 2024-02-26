#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Sisesta positiivne täisarv: ";
    cin >> n;

    double alg = static_cast<double>(n) / 2.0;
    double eelmineLahend = 0.0;

    do {
        double r = static_cast<double>(n) / alg;
        eelmineLahend = alg;
        alg = (alg + r) / 2.0;
    } while (abs(alg - eelmineLahend) > 0.01 * eelmineLahend);

    cout << "Ruutjuur " << n << "-st: " << fixed << setprecision(2) << alg << endl;
    
    return 0;
}