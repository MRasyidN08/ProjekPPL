// main.cpp
#include <iostream>
#include <limits>
#include <iomanip>
#include "Heading.hpp"

using namespace std;

int jumlahItem;
long double totalHarga;
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

void pegawai(MenuItem menu[], int ukuran, int pilihan) {
    if (pilihan > 0 && pilihan <= ukuran){
        cout << "Silahkan tambahkan jumlah stok menu! ";
        cin >> jumlahItem;
        menu[pilihan - 1].stok += jumlahItem;
    } else if(pilihan == 0){
        cout << "Terima Kasih"<<endl;
    } else {
        cout << "Pilihan anda tidak valid";
    }
}

void customer(MenuItem menu[], int ukuran, int pilihan){
    if (menu[pilihan - 1].stok != 0){
        cout << "Sialahkan masukkan jumlah " << menu[pilihan - 1].nama << " yang ingin Anda pesan?!";
        cin >> jumlahItem;
        if (jumlahItem > menu[pilihan - 1].stok){
            cout << "Maaf stok tidak tersedia";
        } else{
            menu[pilihan - 1].stok -= jumlahItem;
            long double hargaTotalItem = menu[pilihan - 1].harga * jumlahItem;
            totalHarga += menu[pilihan - 1].harga * jumlahItem;
            
            pembelian[jumlahPembelian] = {menu[pilihan - 1].nama, jumlahItem, hargaTotalItem};
            jumlahPembelian++;
        }
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
        do {
            cout << setw(40) <<  "------ Selamat Datang Di Mcdonald ------" << endl;
            tampilkanMenu(menu, ukuran);
            cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai): ";
            pilihan = mintaPilihan();
            
            if (pilihan > 0 && pilihan <= ukuran) {
                customer(menu, ukuran, pilihan);
            } else if (pilihan == 0){
               cout << "Silahkan Lanjut ke menu pembayaran" << endl;
            }else {
                cout << "Pilihan tidak valid, coba lagi." << endl;
            }
        } while (pilihan != 0);
    }

    tampilkanRincianPembelian(pembelian, jumlahPembelian);
    cout << "Total harga pesanan Anda: Rp" << totalHarga << endl;
    cout << "Apakah Anda ingin melanjutkan ke pembayaran? (y/n): ";
    cin >> konfirmasiPembayaran;

    if (konfirmasiPembayaran == 'y' || konfirmasiPembayaran == 'Y') {
        long double pembayaranBerhasil = prosesPembayaran(totalHarga);
        if (pembayaranBerhasil >= 0) {
            cout << "Pesanan Anda berhasil diproses. Terima kasih!" << endl;
        } else {
            cout << "Pesanan dibatalkan karena pembayaran gagal." << endl;
        }
    } else {
        cout << "Pesanan dibatalkan." << endl;
    }

    return 0;
}