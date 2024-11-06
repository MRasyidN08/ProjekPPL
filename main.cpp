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
char statusMenu;

void resetPembelian() {
    jumlahPembelian = 0;
    totalHarga = 0;
    for (int i = 0; i < 10; i++) {
        pembelian[i] = PembelianItem{};
    }
}

void kembalikanStok(MenuItem menu[], PembelianItem pembelian[], int jumlahPembelian) {
    for (int i = 0; i < jumlahPembelian; i++) {
        int id = pembelian[i].Id;
        int jumlahPesanan = pembelian[i].jumlah;
        menu[id].stok += jumlahPesanan; // Mengembalikan stok ke menu
    }
}

int mintaPilihan() {
    int pilihan;
    while (true) {
        if (cin >> pilihan) {
            return pilihan;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid, silakan masukkan angka yang sesuai!" << endl;
            cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai) : ";
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
    cout << "Customer atau Pegawai? (c/p) : ";
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
    cout << "----------------------------------------------------------------------------" << endl;

    do {
        cout << " 1 Pembayaran\n 2 Mengurangi Pesanan\n 3 Menambah Pesanan\n 4 Membatalkan Pesnaan\n ";
        cout << "Silahkan konfirmasi pesanan : " ;
        konfirmasiPembayaran = mintaPilihan();
        switch (konfirmasiPembayaran) {
            case 1:
                i++;
                queue++;
                pembelian[i].queue = queue;
                cout << endl;
                cout << "----------------------------------------------------------------------------" << endl;
                cout << "Queue number : " << pembelian[i].queue << endl;
                cout << "Total harga pesanan Anda: Rp." << totalHarga << endl;
                cout << "----------------------------------------------------------------------------" << endl;
                cout << endl;
                   do {
                     cout << "Tekan (y) untuk kembali ke menu : ";
                    cin >> statusMenu;
                    if (statusMenu == 'y') {
                        resetPembelian();
                        goto ulang; // Kembali ke menu jika input adalah 'y'
                    }
                } while (statusMenu != 'y'); // Ulangi sampai statusMenu adalah 'y'
            break;        

            case 2:
                penguranganKeranjang(pembelian, jumlahPembelian, menu);
                tampilkanRincianPembelian(pembelian, jumlahPembelian);
                cout << "Total harga setelah update: Rp." << totalHarga << endl;
                break;

            case 3:
                goto ulang;
                break;

            case 4:
                cout << "Pesanan dibatalkan." << endl;
                kembalikanStok(menu, pembelian, jumlahPembelian);
                resetPembelian();
                goto ulang;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
        
    } while (konfirmasiPembayaran != 1 && konfirmasiPembayaran != 4);
    return 0;
}
