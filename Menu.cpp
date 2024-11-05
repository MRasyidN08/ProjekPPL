// Menu.cpp
#include <iostream>
#include "Heading.hpp"

using namespace std;

void tampilkanMenu(MenuItem menu[], int ukuran) {
    cout << "---- Menu ----" << endl;
    for (int i = 0; i < ukuran; i++) {
        cout << i + 1 << ". " << menu[i].nama << " - Rp" << menu[i].harga << endl;
    }
}

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
    menu[0] = {"Burger", 25000};
    menu[1] = {"Kentang Goreng", 15000};
    menu[2] = {"Minuman Soda", 10000};
    ukuran = 3; // Mengatur ukuran menu
}