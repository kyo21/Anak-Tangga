#include <iostream>
#include <map>
#include <set>

using namespace std;

map<int, int> memo;

int hitungCaraMencapaiPuncak(int n, set<int>& langkahDiperbolehkan) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    // Periksa apakah hasil untuk langkah saat ini sudah dimemoisasi
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    int cara = 0;

    // Hitung jumlah cara dengan mempertimbangkan setiap langkah yang diperbolehkan
    for (int langkah : langkahDiperbolehkan) {
        cara = hitungCaraMencapaiPuncak(n - langkah, langkahDiperbolehkan);
    }

    // Memoisasi hasil untuk langkah saat ini
    memo[n] = cara;

    return cara;
}

void tampilkanSemuaCaraMencapaiPuncak(int n, set<int>& langkahDiperbolehkan, string jalurSaatIni) {
    if (n < 0) return;
    if (n == 0) {
        cout << jalurSaatIni << endl;
        return;
    }

    for (int langkah : langkahDiperbolehkan) {
        tampilkanSemuaCaraMencapaiPuncak(n - langkah, langkahDiperbolehkan, jalurSaatIni + to_string(langkah) + " ");
    }
}

int main() {
    int n;
    set<int> langkahDiperbolehkan = {1, 3};  // Langkah yang diperbolehkan: 1 anak tangga atau 3 anak tangga

    cout << "Masukkan jumlah anak tangga (n): ";
    cin >> n;

    int cara = hitungCaraMencapaiPuncak(n, langkahDiperbolehkan);

    cout << "Jumlah cara untuk mencapai puncak tangga: " << cara << endl;

    cout << "Semua cara untuk mencapai puncak tangga:" << endl;
    tampilkanSemuaCaraMencapaiPuncak(n, langkahDiperbolehkan, "");

    return 0;
}
