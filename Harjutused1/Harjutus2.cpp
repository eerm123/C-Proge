#include <iostream>

using namespace std;

int kõndimine = 4;
float trepid = 5.5;
int ujumine = 10;
int korvpall = 8;
int maadlus = 8;

int main()  {
    int kaal;
    int minutid;
    cout << "Sisesta kaal: ";
    cin >> kaal;
    cout << "Sisesta minutid: ";
    cin >> minutid;
    cout << "Tegevus" << "\t" << "Aeg min\t";
    cout <<"Kuluatud kcal" << endl;
    cout << "------------------------------------------" << endl;
    double jagatud = (double)minutid / (double)60;
    cout << "Kõndimine\t" << minutid << "\t" << (kaal* (jagatud * kõndimine)) << endl;
    cout << "Treppidel käimine\t" << minutid << "\t" << (kaal * (jagatud * trepid)) << endl;
    cout << "Ujumine\t" << minutid << "\t" << (kaal * (jagatud * ujumine)) << endl;
    cout << "Korvpall\t" << minutid << "\t" << (kaal * (jagatud * korvpall)) << endl;
    cout << "Maadlus\t" << minutid << "\t" << (kaal * (jagatud * maadlus)) << endl;
    return 0;
}
