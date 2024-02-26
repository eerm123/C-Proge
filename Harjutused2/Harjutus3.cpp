#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    const int reisijateArv = 5;
    const int read = 6;
    const int istmeteArv = 4;

    srand(static_cast<unsigned int>(time(nullptr)));

    char istmed[read][istmeteArv];

    for (int i = 0; i < read; ++i) {
        for (int j = 0; j < istmeteArv; ++j) {
            istmed[i][j] = 'A' + j;
        }
    }

    for (int k = 0; k < reisijateArv; ++k) {
        int rida = rand() % read;
        int koht = rand() % istmeteArv;
        istmed[rida][koht] = 'X';
    }

    for (int i = 0; i < read; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < istmeteArv; ++j) {
            cout << istmed[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int sisestatudRida;
    char sisestatudKoht;

    while (true) {
        cout << "Sisesta rida, lõpetuseks 100:";
        cin >> sisestatudRida;

        if (sisestatudRida == 100) {
            break;
        }

        cout << "Sisesta koht: ";
        cin >> sisestatudKoht;

        if (istmed[sisestatudRida - 1][sisestatudKoht - 'A'] == 'X') {
            cout << "See koht on juba broneeritud" << endl;
        } else {
            istmed[sisestatudRida - 1][sisestatudKoht - 'A'] = 'X';

            for (int i = 0; i < read; ++i) {
                cout << i + 1 << " ";
                for (int j = 0; j < istmeteArv; ++j) {
                    cout << istmed[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
