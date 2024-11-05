// Heading.hpp
#ifndef HEADING_HPP
#define HEADING_HPP

#include <string>
using namespace std;

struct MenuItem {
    string nama;
    double harga;
    int stok;
};

struct PembelianItem {
    string nama;
    int jumlah;
    double hargaTotal;
};

void tampilkanMenu(MenuItem menu[], int ukuran);
double prosesPembayaran(double totalHarga);
void isiMenu(MenuItem menu[], int& ukuran);
void GetStock(MenuItem menu[]);
void tampilkanRincianPembelian(PembelianItem pembelian[], int jumlahPembelian);

#endif