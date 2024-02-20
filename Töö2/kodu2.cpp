#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

void kolmnurk() {
    int ruum, read;
    
    cout << "";
    cin >> read;

    for(int i = 1, k = 0; i <= read; ++i, k = 0) {
        for(ruum = 1; ruum <= read-i; ++ruum) {
            cout << " ";
        }
        
        while(k != 2*i-1) {
            cout << "*";
            ++k;
        }
        cout << endl;
    }
}

void tabel(double algus, double kesk, double lõpp) {
    cout << setw(12) << "Nael" << setw(15) << "Kg" << endl;
    cout << "       ---------------------\n" << endl;
    while (algus <= lõpp) {
        double kg = algus * 0.453592;
        cout << setw(12) << fixed << setprecision(1) << algus << setw(15) << fixed << setprecision(4) << kg << endl;
        algus += kesk;
    }
}

void krediitkaart() {    
    string number;
    cout << "";
    cin >> number;

    int summa = 0, kahekordne = 0;

    for (int i = number.length() - 1; i >= 0; --i) {
        char c = number[i];
        if (!isdigit(c)) {
            cout << "vale" << endl;
            return;
        }

        int num = c - 0;
        if (kahekordne) {
            num *= 2;
            num -= (num > 9) ? 9 : 0;
        }

        summa += num;
        kahekordne = !kahekordne;
    }

    cout << (summa % 10 == 0 ? "korrektne" : "vale") << endl;
}

void blackjack() {
    const int suurus = 32;
    int kaardipakk[suurus];
    iota(kaardipakk, kaardipakk + suurus, 2);
    
    auto jagakaart = [&kaardipakk]() {
        static mt19937 mt(static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count()));
        uniform_int_distribution<int> dist(0, suurus - 1);

        int index = dist(mt);
        int kaart = kaardipakk[index];
        swap(kaardipakk[index], kaardipakk[suurus - 1]);
        return min(kaart, 11);
    };

    auto arvutSumma = [](const int * kaardid, int suurus) {
        return accumulate(kaardid, kaardid + suurus, 0);
    };

    int kasutajaKaardid[2] = {jagakaart(), jagakaart()};

    while (true) {
        cout << "Sinu kaardid: " << kasutajaKaardid[0] << " " << kasutajaKaardid[1] << " (Summa: " << arvutSumma(kasutajaKaardid, 2) << ")" << endl;
        
        char vastus;
        cout << "Kas soovid veel kaarti? (J/E)";
        cin >> vastus;

        if (tolower(vastus) == 'j') {
            kasutajaKaardid[1] = jagakaart();
        } else {
            break;
        }

        if (arvutSumma(kasutajaKaardid, 2) > 21) {
            cout << "Ületasid 21!" << endl;
            return;
        }
    }

    cout << "Sinu lõplikud kaardid: " << kasutajaKaardid[0] << " " << kasutajaKaardid[1] << "(Summa: " << arvutSumma(kasutajaKaardid, 2) << ")" << endl;
    cout << (arvutSumma(kasutajaKaardid, 2) == 21 ? "Võitsid!" : "Kaotasid") << endl;
}

#if !defined(VPL_TEST)
int main() {
    // Testi oma funktsioone siin
    // kolmnurk();
    // tabel(2.2, 0.4, 4.0);
    // krediitkaart();
    // blackjack();
}
#endif