#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Peminjaman {
    string namaPeminjam;
    string namaBuku;
    string tanggalPinjam;
    string tanggalKembali;
};

class Perpustakaan {
private:
    vector<Peminjaman> daftarPeminjaman;

public:
    void tambahPeminjaman() {
        Peminjaman peminjaman;
        cout << "Masukkan Nama Peminjam: ";
        cin.ignore();
        getline(cin, peminjaman.namaPeminjam);
        cout << "Masukkan Nama Buku: ";
        getline(cin, peminjaman.namaBuku);
        cout << "Masukkan Tanggal Pinjam (YYYY-MM-DD): ";
        getline(cin, peminjaman.tanggalPinjam);
        cout << "Masukkan Tanggal Kembali (YYYY-MM-DD): ";
        getline(cin, peminjaman.tanggalKembali);
        daftarPeminjaman.push_back(peminjaman);
        cout << "Data peminjaman berhasil ditambahkan!\n" << endl;
    }

    void tampilkanDaftarPeminjaman() {
        if (daftarPeminjaman.empty()) {
            cout << "Belum ada data peminjaman." << endl;
            return;
        }

        cout << setw(20) << left << "Nama Peminjam"
             << setw(20) << left << "Nama Buku"
             << setw(15) << left << "Tanggal Pinjam"
             << setw(15) << left << "Tanggal Kembali" << endl;
        cout << string(70, '-') << endl;

        for (const auto& peminjaman : daftarPeminjaman) {
            cout << setw(20) << left << peminjaman.namaPeminjam
                 << setw(20) << left << peminjaman.namaBuku
                 << setw(15) << left << peminjaman.tanggalPinjam
                 << setw(15) << left << peminjaman.tanggalKembali << endl;
        }
    }

    void menu() {
        int pilihan;
        do {
            cout << "\n=== Menu Perpustakaan ===" << endl;
            cout << "1. Tambah Peminjaman" << endl;
            cout << "2. Tampilkan Daftar Peminjaman" << endl;
            cout << "3. Keluar" << endl;
            cout << "Pilih opsi (1-3): ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    tambahPeminjaman();
                    break;
                case 2:
                    tampilkanDaftarPeminjaman();
                    break;
                case 3:
                    cout << "Terima kasih! Sampai jumpa." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        } while (pilihan != 3);
    }
};

int main() {
    Perpustakaan perpustakaan;
    perpustakaan.menu();
    return 0;
}
