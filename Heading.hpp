// MenuItem.h
#ifndef HEADING_HPP
#define HEADING_HPP

#include <string>
using namespace std;

struct MenuItem {
    string nama;
    double harga;
};

void tampilkanMenu(MenuItem menu[], int ukuran);
bool prosesPembayaran(double totalHarga);
void isiMenu(MenuItem menu[], int& ukuran);

#endif
