#include <iostream>
#include "Heading.hpp"

using namespace std;

extern int jumlahItem;
extern double totalHarga;
extern PembelianItem pembelian[];
extern int jumlahPembelian;

void customer(MenuItem menu[], int ukuran, int pilihan) {
    if (menu[pilihan - 1].stok != 0) {
        cout << "Silahkan masukkan jumlah " << menu[pilihan - 1].nama << " yang ingin Anda pesan: ";
        cin >> jumlahItem;
        if (jumlahItem > menu[pilihan - 1].stok) {
            cout << "Maaf stok tidak tersedia" << endl;
        } else {
            menu[pilihan - 1].stok -= jumlahItem;
            double hargaTotalItem = menu[pilihan - 1].harga * jumlahItem;
            totalHarga += menu[pilihan - 1].harga * jumlahItem;

            pembelian[jumlahPembelian] = {menu[pilihan - 1].nama, jumlahItem, hargaTotalItem};
            jumlahPembelian++;
        }
    } else {
        cout << "Pilihan sedang habis stok, coba lagi." << endl;
    }
}

void pegawai(MenuItem menu[], int ukuran, int pilihan) {
    if (pilihan > 0 && pilihan <= ukuran) {
        cout << "Silahkan tambahkan jumlah stok menu: ";
        cin >> jumlahItem;
        menu[pilihan - 1].stok += jumlahItem;
    } else if (pilihan == 0) {
        cout << "Terima Kasih" << endl;
    } else {
        cout << "Pilihan anda tidak valid" << endl;
    }
}