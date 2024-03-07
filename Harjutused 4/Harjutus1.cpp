#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "Harjutus1.h"

using namespace std;
namespace fs = filesystem;

int main() {
    cout << liidaJaPiira(4, 1) << '\n';
    cout << liidaJaPiira(10, 100) << '\n';
    cout << liidaJaPiira<int, 0>(0, 1) << '\n';

    auto asukoht = filesystem::path("elemendid.txt");
    string elemendid[] = {"üks", "kaks", "kolm"};
    looFailKirjuta<string>(asukoht, elemendid, 3);

    return 0;
}