#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string lühendaja(const string& nimi) {
    istringstream iss(nimi);
    vector<string> osad;
    string osa;

    while (iss >> osa) {
        osad.push_back(osa);
    }

    if (osad.size() < 2) {
        return nimi;
    }

    string lühendatud = osad.back() + " "; // Siia tuleb perekonnanimi

    // Lisame eesnimedele esimesed tähed koos punktidega.
    for (size_t i = 0; i < osad.size() - 1; ++i) {
        if (osad[i].find('-') != string::npos) {
            istringstream eesnimi_stream(osad[i]);
            string eesnimi_osad;
            while (getline(eesnimi_stream, eesnimi_osad, '-')) {
                lühendatud += eesnimi_osad[0] + "-";
            }
        } else {
            lühendatud += osad[i][0] + ".";
        }
        if (i < osad.size() - 2) {
            lühendatud += " ";
        }
    }
    return lühendatud;
}

int main() {
    cout << lühendaja("Mari-Anne Lill") << endl;
    cout << lühendaja("Otto Triin Kaido Maastik") << endl;

    return 0;
}