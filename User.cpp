#include <iostream>
#include "Heading.hpp"

using namespace std;

extern int jumlahItem;
extern double totalHarga;
extern PembelianItem pembelian[];
extern int jumlahPembelian;

void customer(MenuItem menu[], int ukuran, int pilihan) {
    do {
        tampilkanMenu(menu, ukuran);
        cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai) : " ;
        pilihan = mintaPilihan();
        if (pilihan > 0 && pilihan <= ukuran) {
            if (menu[pilihan - 1].stok != 0) {
                cout << "Silahkan masukkan jumlah " << menu[pilihan - 1].nama << " yang ingin Anda pesan : ";
                cin >> jumlahItem;
                if (jumlahItem > menu[pilihan - 1].stok) {
                    cout << "Maaf stok tidak tersedia" << endl;
                } else {
                    menu[pilihan - 1].stok -= jumlahItem;
                    double hargaTotalItem = menu[pilihan - 1].harga * jumlahItem;
                    totalHarga += menu[pilihan - 1].harga * jumlahItem;

                    pembelian[jumlahPembelian] = {pilihan - 1, menu[pilihan - 1].nama, jumlahItem, hargaTotalItem};
                    jumlahPembelian++;
                }
            } else {
                cout << "Pilihan sedang habis stok, coba lagi." << endl;
            }
        }else if (pilihan == 0){
            cout << "Silahkan Lanjut ke menu pembayaran" << endl;
            cout << "----------------------------------" << endl;
        }else {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }    
    } while(pilihan != 0);
}

void pegawai(MenuItem menu[], int ukuran, int pilihan) {
    do {
        tampilkanMenu(menu, ukuran);
        cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai) : " ;
        pilihan = mintaPilihan();
        if (pilihan > 0 && pilihan <= ukuran) {
            cout << "Silahkan tambahkan jumlah stok menu : ";
            cin >> jumlahItem;
            menu[pilihan - 1].stok += jumlahItem;
        } else if (pilihan == 0) {
            cout << "Terima Kasih" << endl;
        } else {
            cout << "Pilihan anda tidak valid" << endl;
        }
    } while(pilihan != 0);
}