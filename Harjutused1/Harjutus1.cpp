#include <iostream>

using namespace std;

int main() {
    int x;
    cout << "Sisesta täisarv: ";
    cin >> x;
    cout << x%10 << endl;
    cout << (x>>1) << endl;
    cout << (x<<1) << endl;
    return 0;
}