// main.cpp
#include <iostream>
#include "Heading.hpp"

using namespace std;

int main() {
    MenuItem menu[10]; // Array untuk menu
    int ukuran;
    int pilihan, jumlahItem;
    double totalHarga = 0;
    char konfirmasiPembayaran;

    isiMenu(menu, ukuran); // Memanggil fungsi untuk mengisi menu
    tampilkanMenu(menu, ukuran);

    cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai): ";
    cin >> pilihan;

    while (pilihan != 0) {
        if (menu[pilihan - 1].stok != 0){
            if (pilihan > 0 && pilihan <= ukuran) {
                cout << "Berapa banyak " << menu[pilihan - 1].nama << " yang ingin Anda pesan? ";
                cin >> jumlahItem;
                menu[pilihan - 1].stok -= jumlahItem;
                totalHarga += menu[pilihan - 1].harga * jumlahItem;
                cout << menu[pilihan - 1].stok;
            } else {
                cout << "Pilihan tidak valid, coba lagi." << endl;
            }
        } else {
            cout << "Pilihan sedang habis stok, coba lagi." << endl;
        }
        cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai): ";
        cin >> pilihan;
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
