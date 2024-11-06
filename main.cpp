#include <iostream>
#include <limits>
#include <iomanip>
#include "Heading.hpp"

using namespace std;

int jumlahItem;
double totalHarga;
PembelianItem pembelian[10];
int jumlahPembelian = 0;
int queue = 0;
int i;

int mintaPilihan() {
    int pilihan;
    while (true) {
        if (cin >> pilihan) {
            return pilihan;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid, silakan masukkan angka yang sesuai!" << endl;
            cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai): ";
        }
    }
}

int main() {
    MenuItem menu[10];
    int ukuran, pilihan, konfirmasiPembayaran;
    isiMenu(menu, ukuran);
    GetStock(menu);
    char orang;

    start:
    cout << "Customer atau Pegawai? (c/p): ";
    cin >> orang;

    if (orang == 'p') {
        pegawai(menu, ukuran, pilihan);
        goto start;
    } else if (orang == 'c') {
        ulang:
        customer(menu, ukuran, pilihan);
    } else {
        cout << "Pilihan tidak valid." << endl;
        return 0;
    }

    tampilkanRincianPembelian(pembelian, jumlahPembelian);
    cout << endl;
    cout << "Total harga pesanan Anda: Rp." << totalHarga << endl;
    cout << "------------------------------------------------" << endl;

    do {
        cout << "Apakah Anda ingin melanjutkan ke pembayaran? (1 untuk Ya, 2 untuk Mengurangi Pesanan, 3 untuk nambah, 4 untuk batal): ";
        konfirmasiPembayaran = mintaPilihan();
        switch (konfirmasiPembayaran) {
            case 1:
                
                i++;
                
                queue++;
                pembelian[i].queue = queue;
                tampilkanRincianPembelian(pembelian, jumlahPembelian);
                cout << "Queue number: " << pembelian[i].queue << endl;
                cout << "Total harga pesanan Anda: Rp" << totalHarga << endl;
                goto ulang;

            case 2:
                penguranganKeranjang(pembelian, jumlahPembelian, menu);
                tampilkanRincianPembelian(pembelian, jumlahPembelian);
                cout << "Total harga setelah update: Rp" << totalHarga << endl;

                break;

            case 3:
                goto ulang;
                break;

            case 4:
                cout << "Pesanan dibatalkan." << endl;
                return 0;

            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
        
    } while (konfirmasiPembayaran != 1 && konfirmasiPembayaran != 4);
    return 0;
}
