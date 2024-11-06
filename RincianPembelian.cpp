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

void penguranganKeranjang(PembelianItem pembelian[], int jumlahPembelian, MenuItem menu[]) {
    int nomorItem, jumlahPengurangan;
    cout << "Masukkan nomor item yang ingin dikurangi : ";
    cin >> nomorItem;

    if (nomorItem > 0 && nomorItem <= jumlahPembelian) {
        PembelianItem &item = pembelian[nomorItem - 1];

        cout << "Jumlah yang ingin dikurangi dari " << item.nama << " : ";
        cin >> jumlahPengurangan;

        if (jumlahPengurangan > 0 && jumlahPengurangan <= item.jumlah) {
            menu[item.Id].stok += jumlahPengurangan;
            item.jumlah -= jumlahPengurangan;
            item.hargaTotal -= menu[item.Id].harga * jumlahPengurangan;
            totalHarga -= menu[item.Id].harga * jumlahPengurangan;

            if (item.jumlah == 0) {
                for (int i = nomorItem - 1; i < jumlahPembelian - 1; i++) {
                    pembelian[i] = pembelian[i + 1];
                }
                jumlahPembelian--;
            }
        } else {
            cout << "Jumlah pengurangan tidak valid." << endl;
        }
    } else {
        cout << "Nomor item tidak valid." << endl;
    }
}

void kembalikanStok(MenuItem menu[], PembelianItem pembelian[], int jumlahPembelian) {
    for (int i = 0; i < jumlahPembelian; i++) {
        int id = pembelian[i].Id;
        int jumlahPesanan = pembelian[i].jumlah;
        menu[id].stok += jumlahPesanan; // Mengembalikan stok ke menu
    }
}