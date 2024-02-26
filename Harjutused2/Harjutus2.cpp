#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Mitme ülesande tulemus sisestada? ";
    cin >> n;

    int punktidKokku = 0;
    int maksPunktidKokku = 0;

    for (int i = 1; i <= n; ++i) {
        int punktid, maksPunktid;

        cout << i << ". Ülesande eest saadud punktisumma: ";
        cin >> punktid;

        cout << "Maksimalne võimalik punktide arv " << i << ". Ülesande eest: ";
        cin >> maksPunktid;

        punktidKokku += punktid;
        maksPunktidKokku += maksPunktid;
    }

    double protsent = static_cast<double>(punktidKokku) / maksPunktidKokku * 100;

    cout << "Kogusumma on " << punktidKokku << " " << maksPunktidKokku << "-st ehk " << fixed << setprecision(2) << protsent << "%." << endl;

    return 0;
}