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
    cout << "-------------------------------------------------------------------" << endl ; 
}

void penguranganKeranjang(PembelianItem pembelian[], int jumlahPembelian, MenuItem menu[]) {
    int nomorItem, jumlahPengurangan;
    cout << "Masukkan nomor item yang ingin dikurangi: ";
    cin >> nomorItem;

    if (nomorItem > 0 && nomorItem <= jumlahPembelian) {
        PembelianItem &item = pembelian[nomorItem - 1];

        cout << "Jumlah yang ingin dikurangi dari " << item.nama << ": ";
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