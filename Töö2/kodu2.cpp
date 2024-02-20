#include <iostream>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <vector>

using namespace std;

bool korrektne(string & number) {
    int summa = 0;
    bool kahekordne = false;
    
    // Liigun läbi kõik numbrid krediitkaardi numbris tagurpidi
    for (int i = number.length() - 1; i >= 0; --i) {
        char c = number[i];
        //kontrolli kas sümbol on number
        if (!isdigit(c)) {
            return false; // kui ei ole number, tagasta false
        }

        int num = c - '0';

        // Kui on iga teise numbri kord, korruta seda kahega
        if (kahekordne) {
            num *= 2;

            // Kui tulemus on kahekohaline, siis lahuta 9-ga
            if (num > 9) {
                num -= 9;
            }
        }
        
        summa += num;

        kahekordne = !kahekordne;
    }

    return (summa % 10 == 0);
}

void kolmnurk() {
    int ruum, read;
    
    cout << " ";
    cin >> read;

    for(int i = 1, k = 0; i <= read; ++i, k = 0) {
        for(ruum = 1; ruum <= read-i; ++ruum) {
            cout << "  ";
        }
        
        while(k != 2*i-1) {
            cout << "* ";
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
    string krediitkaardiNumber;

    cout << " ";
    cin >> krediitkaardiNumber;
    
    if (korrektne(krediitkaardiNumber)) {
        cout << "Korrektne" << endl;
    } else {
        cout << "Vale" << endl;
    }

}

void blackjack() {
    vector<int> looKaardipakk() {
        vector<int> kaardipakk;
        for (int i = 0; i < 4; ++i) {
            for (int j = 2; j <= 11; ++j) {
                kaardipakk.push_back(j);
            }
        }
        return kaardipakk;
    }

    int jagakaart(vector<int> & kaardipakk) {
        static size_t index = 0;
        return kaardipakk[index++];
    }

    int arvutaSumma(vector<int> & kaardid) {
        int summa = 0;
        for (int kaart : kaardid) {
            summa += kaart;
        }
        return summa;
    }

    vector<int> kaardipakk = looKaardipakk();
    srand(static_cast<unsigned>(time(nullptr)));

    vector<int> kasutajaKaardid;
    vector<int> arvutiKaardid;

    // Arvuti jagab esimese kaardi
    arvutiKaardid.push_back(jagakaart(kaardipakk));
    cout << "Arvuti esimene kaart: " << arvutiKaardid[0] << endl;

    // Kasutaja saab kaks esimest kaarti
    kasutajaKaardid.push_back(jagakaart(kaardipakk));
    kasutajaKaardid.push_back(jagakaart(kaardipakk));

    while (true) {
        cout << "Sinu kaardid: ";
        for (int kaart : kasutajaKaardid) {
            cout << kaart << " ";
        }
        cout << "(Summa: " << arvutaSumma(kasutajaKaardid) << ")" << endl;

        char vastus;
        cout << "Kas soovid veel kaarti? (J/E): ";
        cin >> vastus;

        if (tolower(vastus) == 'j') {
            kasutajaKaardid.push_back(jagakaart(kaardipakk));
        } else {
            break;
        }

        if (arvutaSumma(kasutajaKaardid) > 21) {
            cout << "Ületasid 21! kaotus!" << endl;
            return;
        }
    }
    
    while (arvutaSumma(arvutiKaardid) < 17) {
        arvutiKaardid.push_back(jagakaart(kaardipakk));
    }

    cout << "Arvuti kaardid: ";
    for (int kaart : arvutiKaardid) {
        cout << kaart << " ";
    }
    cout << "(Summa: " << arvutaSumma(arvutiKaardid) << ")" << endl;

    // Kontrollime võitu, kaotust või viiki
    if (arvutaSumma(arvutiKaardid) > 21 || (arvutaSumma(kasutajaKaardid) > arvutaSumma(arvutiKaardid) && arvutaSumma(kasutajaKaardid) <= 21)) {
        cout << "Võitsid" << endl;
    } else if (arvutaSumma(kasutajaKaardid) == arvutaSumma(arvutiKaardid)) {
        cout << "Viik" << endl;
    } else {
        cout << "Kaotus" << endl;
    }
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