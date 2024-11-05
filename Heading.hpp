// MenuItem.h
#ifndef HEADING_HPP
#define HEADING_HPP

#include <string>
using namespace std;

struct MenuItem {
    string nama;
    double harga;
    int stok;
};

void tampilkanMenu(MenuItem menu[], int ukuran);
bool prosesPembayaran(double totalHarga);
void isiMenu(MenuItem menu[], int& ukuran);
void GetStock(MenuItem menu[]);

#endif
