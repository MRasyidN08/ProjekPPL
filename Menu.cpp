// Menu.cpp
#include <iostream>
#include <iomanip>
#include "Heading.hpp"

using namespace std;

void tampilkanMenu(MenuItem menu[], int ukuran) {
    cout << setw(28) << "------ Menu ------" << endl;
    for (int i = 0; i < ukuran; i++) {
        cout << i + 1 << ". " << menu[i].nama << " - Rp" << menu[i].harga << " Stok tersisa: "<< menu[i].stok << endl;
    }
}
// jadikan file pembayaran
bool prosesPembayaran(double totalHarga) {
    double bayar;
    cout << "Total harga: Rp" << totalHarga << endl;
    cout << "Masukkan jumlah pembayaran: Rp";
    cin >> bayar;

    if (bayar >= totalHarga) {
        cout << "Pembayaran berhasil. Kembalian: Rp" << bayar - totalHarga << endl;
        return true;
    } else {
        cout << "Pembayaran gagal. Jumlah yang dibayarkan kurang." << endl;
        return false;
    }
}

void isiMenu(MenuItem menu[], int& ukuran) {
    // Mengisi data menu
    menu[0] = {"Burger (Big mac)", 42000, menu[0].stok};
    menu[1] = {"Cheeseburger", 35000, menu[1].stok};
    menu[2] = {"Double Cheesburger", 41000, menu[2].stok};
    menu[3] = {"Chicken Burger", 33000, menu[3].stok};
    menu[4] = {"Chicken Burger", 33000, menu[4].stok};
    menu[5] = {"Panas Special (Ayam,Nasi,Telur,Minum)", 47000, menu[5].stok};
    menu[6] = {"Panas 1 (Ayam,Nasi,Minum)", 39000, menu[6].stok};
    menu[7] = {"Pamer 5 (Ayam 5,Nasi 5,Minum 5)", 132500, menu[7].stok};
    menu[8] = {"Pamer 7 (Ayam 7,Nasi 7,Minum 7)", 185000, menu[8].stok};
    ukuran = 9; // Mengatur ukuran menu
}

void GetStock(MenuItem menu[]){
    menu[0].stok = 10;
    menu[1].stok = 10;
    menu[2].stok = 10;
    menu[3].stok = 10;
    menu[4].stok = 10;
    menu[5].stok = 10;
    menu[6].stok = 10;
    menu[7].stok = 10;
    menu[8].stok = 10;
}
