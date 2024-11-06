// main.cpp
#include <iostream>
#include <limits>
#include <iomanip>
#include "Heading.hpp"

using namespace std;

int jumlahItem;
double totalHarga;
PembelianItem pembelian[10];
int jumlahPembelian = 0;

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
            cout << "Input tidak valid, silakan masukkan angka yang sesuai!!" << endl;
            cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai) : " ;
        }
    }
}


int main() {
    MenuItem menu[10]; // Array untuk menu
    int ukuran;
    int pilihan;
    isiMenu(menu, ukuran); // Memanggil fungsi untuk mengisi menu
    GetStock(menu); 
    char konfirmasiPembayaran, orang;

    start:
    cout << "Customer atau Pegawai? (c/p)";
    cin >> orang;

    if (orang == 'p')
    {
        do {
            tampilkanMenu(menu, ukuran);
            cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai) : " ;
            pilihan = mintaPilihan();
            if (pilihan > 0 && pilihan <= ukuran) {
                pegawai(menu, ukuran, pilihan);
            } else if (pilihan == 0){
               cout << "Terimakasih" << endl;
            }else {
                cout << "Pilihan tidak valid, coba lagi." << endl;
            }
        } while (pilihan != 0);
        goto start;
    } else if (orang == 'c'){
        next:
        do {
            cout << setw(40) <<  "------ Selamat Datang Di Mcdonald ------" << endl;
            tampilkanMenu(menu, ukuran);
            cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai): ";
            pilihan = mintaPilihan();
            
            if (pilihan > 0 && pilihan <= ukuran) {
                customer(menu, ukuran, pilihan);
            } else if (pilihan == 0){
               cout << "----------------------------------" << endl;
               cout << "Silahkan Lanjut ke menu pembayaran" << endl;
            }else {
                cout << "Pilihan tidak valid, coba lagi." << endl;
            }
        } while (pilihan != 0);
    }
// ini sampai bawah masukin file pembayaran
    cout << "Total harga pesanan Anda: Rp." << totalHarga << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Apakah Anda ingin melanjutkan ke pembayaran? (y/n): ";
    cin >> konfirmasiPembayaran;

    if (konfirmasiPembayaran == 'y' || konfirmasiPembayaran == 'Y') {
        int i;
        i++;
        int queue = 0;
        queue++;
        pembelian[i].queue = queue;
        tampilkanRincianPembelian(pembelian, jumlahPembelian);
        cout << endl;
        cout << "Queue number: " << pembelian[i].queue << endl;
        cout << "Total harga pesanan Anda: Rp" << totalHarga << endl;
    } else {
        cout << "Pesanan dibatalkan." << endl;
        goto next;
    }

    return 0;
}