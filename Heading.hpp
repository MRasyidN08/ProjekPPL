// Heading.hpp
#ifndef HEADING_HPP
#define HEADING_HPP

#include <string>
using namespace std;

extern double totalHarga;

struct MenuItem {
    string nama;
    double harga;
    int stok;
};

struct PembelianItem {
    int Id;
    string nama;
    int jumlah;
    double hargaTotal;
    int queue;
};

void tampilkanMenu(MenuItem menu[], int ukuran);
void isiMenu(MenuItem menu[], int& ukuran);
void GetStock(MenuItem menu[]);
void tampilkanRincianPembelian(PembelianItem pembelian[], int jumlahPembelian);
void penguranganKeranjang(PembelianItem pembelian[], int jumlahPembelian, MenuItem menu[]);

void pegawai(MenuItem menu[], int ukuran, int pilihan);
void customer(MenuItem menu[], int ukuran, int pilihan);
int mintaPilihan();


#endif
