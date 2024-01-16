#include <iostream>
#include <map>
#include <set>

using namespace std;

map<int, int> steps;

int hitungCaraMencapaiPuncak(int n, set<int>& langkahDiperbolehkan) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    // Periksa apakah hasil untuk langkah saat ini sudah dimemoisasi
    if (steps.find(n) != steps.end()) {
        return steps[n];
    }

    int cara = 0;

    // Hitung jumlah cara dengan mempertimbangkan setiap langkah yang diperbolehkan
    for (int langkah : langkahDiperbolehkan) {
        cara += hitungCaraMencapaiPuncak(n - langkah, langkahDiperbolehkan);
    }

    // Memoisasi hasil untuk langkah saat ini
   steps[n] = cara;

    return cara;
}

