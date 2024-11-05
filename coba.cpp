#include <iostream>
#include <string>

using namespace std;

struct MenuItem {
    string nama;
    double harga;
};

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

int main() {
    MenuItem menu[] = {
        {"Burger", 25000},
        {"Kentang Goreng", 15000},
        {"Minuman Soda", 10000}
    };
    int pilihan, jumlahItem;
    double totalHarga = 0;
    char konfirmasiPembayaran;

    tampilkanMenu(menu, 3);

    cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai): ";
    cin >> pilihan;

    while (pilihan != 0) {
        if (pilihan > 0 && pilihan <= 3) {
            cout << "Berapa banyak " << menu[pilihan - 1].nama << " yang ingin Anda pesan? ";
            cin >> jumlahItem;
            totalHarga += menu[pilihan - 1].harga * jumlahItem;
        } else {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
        cout << "Pilih item dari menu (masukkan nomor item, 0 untuk selesai): ";
        cin >> pilihan;
    }

    cout << "Total harga pesanan Anda: Rp" << totalHarga << endl;
    cout << "Apakah Anda ingin melanjutkan ke pembayaran? (y/n): ";
    cin >> konfirmasiPembayaran;

    if (konfirmasiPembayaran == 'y' || konfirmasiPembayaran == 'Y') {
        bool pembayaranBerhasil = prosesPembayaran(totalHarga);
        if (pembayaranBerhasil) {
            cout << "Pesanan Anda berhasil diproses. Terima kasih!" << endl;
        } else {
            cout << "Pesanan dibatalkan karena pembayaran gagal." << endl;
        }
    } else {
        cout << "Pesanan dibatalkan." << endl;
    }

    return 0;
}
