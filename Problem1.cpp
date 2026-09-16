#include <iostream>
using namespace std;

int perbaruiK(int K, int tereliminasi) {
    K = (tereliminasi % 2 == 0) ? K + 2 : K - 1;
    return (K < 2) ? 2 : K;
}

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): "; cin >> N;
    cout << "Masukkan nilai eliminasi (K): "; cin >> K;

    bool aktif[10000]; 
    for (int i = 1; i <= N; i++) aktif[i] = true;

    int sisa = N, pos = 1;
    cout << "Urutan dieliminasi: ";
    
    while (sisa > 1) {
        int langkah = (K - 1) % sisa;

        while (langkah > 0) {
            pos = (pos % N) + 1;
            if (aktif[pos]) langkah--;
        }

        aktif[pos] = false;
        cout << pos << " ";

        K = perbaruiK(K, pos);
        sisa--;

        if (sisa > 0) {
            while (!aktif[pos]) pos = (pos % N) + 1;
        }
    }
    cout << "\nAstronot terakhir yang bertahan: " << pos << "\n";
    return 0;
}