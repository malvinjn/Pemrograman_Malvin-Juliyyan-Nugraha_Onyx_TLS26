#include <iostream>
using namespace std;

int panjang(const char teks[]) {
    int len = 0;
    while (teks[len] != '\0') len++;
    return len;
}

int keAngka(char c) { return c - 'A' + 1; }
char keHuruf(int n) { return (char)(n - 1 + 'A'); }

int main() {
    char pesan[1000], sandi[1000];
    cout << "Masukkan pesan asli: "; cin >> pesan;

    int len = panjang(pesan);

    if (len > 0) {
        sandi[0] = pesan[0];

        for (int i = 1; i < len; i++) {
            int nilai_baru = keAngka(pesan[i]) + keAngka(pesan[i - 1]);
            nilai_baru %= 26;
            
            if (nilai_baru == 0) nilai_baru = 26;
            sandi[i] = keHuruf(nilai_baru);
        }
        sandi[len] = '\0';

        cout << "Pesan sandi: " << sandi << "\n";
    }
    return 0;
}