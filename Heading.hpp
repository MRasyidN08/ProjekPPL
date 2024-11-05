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
    long double hargaTotal;
};

void tampilkanMenu(MenuItem menu[], int ukuran);
long double prosesPembayaran(double totalHarga);
void isiMenu(MenuItem menu[], int& ukuran);
void GetStock(MenuItem menu[]);
void tampilkanRincianPembelian(PembelianItem pembelian[], int jumlahPembelian);

#endif
