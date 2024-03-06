#include <iostream>

using namespace std;

int main() {

    int x, y, z;
    x = 4; y = 5;
    z = y + 6;
    while(((z-x) % 4) != 0) {
        cout << z << " ";
        z = z + 7;
    }
}