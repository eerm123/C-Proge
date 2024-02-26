#include <iostream>
#include <string>

using namespace std;

void pööraTagurpidi(string& sone) {
    size_t pikkus = sone.length();
    for (size_t i = 0; i < pikkus / 2; ++i) {
        swap(sone[i], sone[pikkus - i - 1]);
    }
}

void tagurpidi(size_t arv, string massiiv[]) {
    for (size_t i = 0; i < arv; ++i) {
        pööraTagurpidi(massiiv[i]);
    }

    for (size_t i = 0; i < arv / 2; ++i) {
        swap(massiiv[i], massiiv[arv - i - 1]);
    }
}

int main() {
    string massiiv[] = {"kaks", "kolm", "neli"};
    tagurpidi(3, massiiv);

    for (int i = 0; i < 3; ++i) {
        cout << massiiv[i] << '\n';
    }

    return 0;
}