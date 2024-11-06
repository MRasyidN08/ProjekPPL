#include <iostream>
#include <iomanip>
#include "Heading.hpp"

using namespace std;

double prosesPembayaran(double totalHarga) {
    double bayar;
    double kembalian;
    cout << endl ;
    cout << "----------------------------------" << endl;
    cout << "Total harga: Rp." << fixed << setprecision(2) << totalHarga << endl;
    cout << "Masukkan jumlah pembayaran: Rp.";
    cin >> bayar;
    
    kembalian = bayar - totalHarga;

    if (bayar >= totalHarga) {
        cout << endl;
        cout << "----------------------------------" << endl ;
        cout << "Pembayaran berhasil. Kembalian: Rp." << fixed << setprecision(2) << kembalian << endl;
        return kembalian;
    } else {
        cout << "Pembayaran gagal. Jumlah yang dibayarkan kurang." << endl;
        return kembalian;
    }
}

void tampilkanRincianPembelian(PembelianItem pembelian[], int jumlahPembelian) {
    cout << "\nRincian Pembelian Anda:\n";
    cout << "------------------------------------------------" << endl;
    cout << "| No | " << setw(15) << left << "Pesanan"
         << "| " << setw(8) << left << "Jumlah"
         << "| " << setw(12) << left << "Harga" << " |" << endl;
    cout << "------------------------------------------------" << endl;

    for (int i = 0; i < jumlahPembelian; i++) {
        cout << "| " << setw(2) << right << i + 1 << " | "
             << setw(15) << left << pembelian[i].nama
             << "| " << setw(8) << left << pembelian[i].jumlah
             << "| Rp " << setw(10) << left << fixed << setprecision(2) << pembelian[i].hargaTotal << "|" << endl;
    }

    cout << "------------------------------------------------" << endl;
}