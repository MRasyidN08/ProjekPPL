// main.cpp
#include <iostream>
#include <limits>
#include "Heading.hpp"

using namespace std;

int jumlahItem;
double totalHarga;

int mintaPilihan() {
    int pilihan;
    while (true) {
        if (cin >> pilihan) {
            // Jika input valid (integer)
            return pilihan;
        } else {
            // Jika input tidak valid
            cin.clear(); // Menghapus status error dari cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membuang input yang tidak valid
            cout << "Input tidak valid, silakan masukkan angka." << endl;
        }
    }
}

void pegawai(MenuItem menu[], int ukuran, int pilihan) {
    if (pilihan > 0 && pilihan <= ukuran){
        cout << "Berapa banyak?";
        cin >> jumlahItem;
        menu[pilihan - 1].stok += jumlahItem;
        cout << "Stok anda ada: ";
        cout << menu[pilihan - 1].stok;
    } else if(pilihan == 0){
        cout << "Terima Kasih"<<endl;
    } else {
        cout << "Pilihan anda tidak valid";
    }
}

void customer(MenuItem menu[], int ukuran, int pilihan){
    if (menu[pilihan - 1].stok != 0){
        cout << "Berapa banyak " << menu[pilihan - 1].nama << " yang ingin Anda pesan? ";
        cin >> jumlahItem;
        menu[pilihan - 1].stok -= jumlahItem;
        totalHarga += menu[pilihan - 1].harga * jumlahItem;
        cout << menu[pilihan - 1].stok;
    } else {
        cout << "Pilihan sedang habis stok, coba lagi." << endl;
    }    
}

int main() {
    MenuItem menu[10]; // Array untuk menu
    int ukuran;
    int pilihan;
    isiMenu(menu, ukuran); // Memanggil fungsi untuk mengisi menu
    GetStock(menu); 
    char konfirmasiPembayaran, orang;
    bool konfirm;

    start:
    cout << "Customer atau Pegawai? (c/p)";
    cin >> orang;

    if (orang == 'p')
    {
        do {
            tampilkanMenu(menu, ukuran);
            cout << "Ingin menambah stok makanan apa? (masukkan nomor item, 0 untuk selesai):";
            pilihan = mintaPilihan();
            pegawai(menu, ukuran, pilihan);
        } while (pilihan != 0);
        cout << "Terima kasih";
        goto start;
    } else if (orang == 'c'){
        do {
            tampilkanMenu(menu, ukuran);
            cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai): ";
            pilihan = mintaPilihan();
            
            if (pilihan > 0 && pilihan <= ukuran) {
                customer(menu, ukuran, pilihan);
            } else {
                cout << "Pilihan tidak valid, coba lagi." << endl;
            }
        } while (pilihan != 0);
    }

    cout << "Total harga pesanan Anda: Rp" << totalHarga << endl;
    cout << "Apakah Anda ingin melanjutkan ke pembayaran? (y/n): ";
    cin >> konfirmasiPembayaran;

    if (konfirmasiPembayaran == 'y' || konfirmasiPembayaran == 'Y') {
        bool pembayaranBerhasil = prosesPembayaran(totalHarga);
        if (pembayaranBerhasil) {
            cout << "Pesanan Anda berhasil diproses. Terima kasih!" << endl;
        } else {
            cout << "Pesanan dibatalkan karena pembayaran gagal." << endl;
        }
    } else {
        cout << "Pesanan dibatalkan." << endl;
    }

    return 0;
}
