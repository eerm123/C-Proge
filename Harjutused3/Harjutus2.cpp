#include <iostream>
#include <string>

using namespace std;

string sugu(const string& isikukood) {
    char esimene_tahemark = isikukood[0];
    if (esimene_tahemark == '1' || esimene_tahemark == '3' || esimene_tahemark == '5') {
        return "M";
    } else if (esimene_tahemark == '2' || esimene_tahemark == '4' || esimene_tahemark == '6') {
        return "N";
    } else {
        return "Tundmatu";
    }
}

string sünnikuupäev(const string& isikukood) {
    string sünnikuupäev;
    sünnikuupäev += isikukood.substr(5, 2) + ".";
    sünnikuupäev += isikukood.substr(3, 2) + ".";

    char esimene_tahemark = isikukood[0];
    if (esimene_tahemark == '1' || esimene_tahemark == '2') {
        // 1800-1899
        sünnikuupäev += "18" + isikukood.substr(1, 2);
    } else if (esimene_tahemark == '3' || esimene_tahemark == '4') {
        // 1900 - 1999
        sünnikuupäev += "19" + isikukood.substr(1, 2);
    } else if (esimene_tahemark == '5' || esimene_tahemark == '6') {
        sünnikuupäev += "20" + isikukood.substr(1, 2);
    } else {
        sünnikuupäev += "Tundmatu";
    }
    
    return sünnikuupäev;
}

int main() {
    string isikukood = "50010032721";
    cout << "Sugu: " << sugu(isikukood) << endl;
    cout << "Sünnikuupäev: " << sünnikuupäev(isikukood) << endl;

    return 0;
}