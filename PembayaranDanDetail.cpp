// PembayaranDanDetail.cpp
#include <iostream>
#include <iomanip>
#include "Heading.hpp"

using namespace std;

double prosesPembayaran(double totalHarga) {
    double bayar;
    double kembalian;
    cout << "Total harga: Rp" << fixed << setprecision(2) << totalHarga << endl;
    cout << "Masukkan jumlah pembayaran: Rp";
    cin >> bayar;

    kembalian = bayar - totalHarga;

    if (bayar >= totalHarga) {
        cout << "----------------------------------" << endl ;
        cout << "Pembayaran berhasil. Kembalian: Rp" << fixed << setprecision(2) << kembalian << endl;
        return kembalian;
    } else {
        cout << "Pembayaran gagal. Jumlah yang dibayarkan kurang." << endl;
        return kembalian;
    }
}

void tampilkanRincianPembelian(PembelianItem pembelian[], int jumlahPembelian) {
    cout << "\nRincian Pembelian Anda:\n";
    for (int i = 0; i < jumlahPembelian; i++) {
        cout << i + 1 << ". " << pembelian[i].nama << " - Jumlah: " << pembelian[i].jumlah 
             << " - Harga Total: Rp" << pembelian[i].hargaTotal << endl;
    }
    cout << endl;
}