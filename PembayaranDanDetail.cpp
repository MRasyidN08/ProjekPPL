#include <iostream>
#include <iomanip>
#include "Heading.hpp"

using namespace std;

void tampilkanRincianPembelian(PembelianItem pembelian[], int jumlahPembelian) {
    cout << "\nRincian Pembelian Anda:\n";
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "| No | " << setw(40) << left << "Pesanan"
         << "| " << setw(8) << left << "Jumlah"
         << "| " << setw(15) << left << "Harga" << " |" << endl;
    cout << "----------------------------------------------------------------------------" << endl;

    for (int i = 0; i < jumlahPembelian; i++) {
        cout << "| " << setw(2) << right << i + 1 << " | "
             << setw(40) << left << pembelian[i].nama
             << "| " << setw(8) << left << pembelian[i].jumlah
             << "| Rp " << setw(13) << left << fixed << setprecision(2) << pembelian[i].hargaTotal << "|" << endl;
    }

    cout << "----------------------------------------------------------------------------" << endl;
}
