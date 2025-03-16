#include <iostream>
#include <iomanip>
#include <string>

#define MAX_KAMERA 100 // Batas maksimal jumlah kamera

using namespace std;

// Deklarasi array satu dimensi untuk menyimpan data kamera
string kodeKamera[MAX_KAMERA];
string namaKamera[MAX_KAMERA];
int stokKamera[MAX_KAMERA];
int jumlahKamera = 0;

// Fungsi untuk menampilkan tabel kamera
int tampilkanKamera() {
    cout << "\n===========================================================\n";
    cout << setw(10) << left << "Kode" << setw(20) << left << "Nama Kamera" << setw(10) << left << "Stok\n";
    cout << "===========================================================\n";
    if (jumlahKamera == 0) {
        cout << "Tidak ada kamera yang tersedia.\n";
    } else {
        for (int i = 0; i < jumlahKamera; i++) {
            cout << setw(10) << left << kodeKamera[i]
                 << setw(20) << left << namaKamera[i]
                 << setw(10) << left << stokKamera[i] << endl;
        }
    }
    cout << "===========================================================\n";
    return 0;
}

// Fungsi untuk menambah kamera baru
int tambahKamera() {
    if (jumlahKamera < MAX_KAMERA) {
        cout << "\nMasukkan kode kamera: ";
        cin >> kodeKamera[jumlahKamera];
        cout << "Masukkan nama kamera: ";
        cin.ignore();
        getline(cin, namaKamera[jumlahKamera]);
        cout << "Masukkan stok kamera: ";
        cin >> stokKamera[jumlahKamera];
        jumlahKamera++;
        cout << "\nKamera berhasil ditambahkan!\n";
    } else {
        cout << "Kapasitas penyimpanan penuh!\n";
    }
    return 0;
}

// Fungsi untuk mengedit kamera berdasarkan kode
int editKamera() {
    string kode;
    cout << "\nMasukkan kode kamera yang ingin diedit: ";
    cin >> kode;

    for (int i = 0; i < jumlahKamera; i++) {
        if (kodeKamera[i] == kode) {
            cout << "Masukkan nama kamera baru: ";
            cin.ignore();
            getline(cin, namaKamera[i]);
            cout << "Masukkan stok baru: ";
            cin >> stokKamera[i];
            cout << "\nData kamera berhasil diperbarui!\n";
            return 0;
        }
    }
    cout << "\nKamera dengan kode tersebut tidak ditemukan.\n";
    return 0;
}

// Fungsi untuk menghapus kamera berdasarkan kode
int hapusKamera() {
    string kode;
    cout << "\nMasukkan kode kamera yang ingin dihapus: ";
    cin >> kode;

    for (int i = 0; i < jumlahKamera; i++) {
        if (kodeKamera[i] == kode) {
            for (int j = i; j < jumlahKamera - 1; j++) {
                kodeKamera[j] = kodeKamera[j + 1];
                namaKamera[j] = namaKamera[j + 1];
                stokKamera[j] = stokKamera[j + 1];
            }
            jumlahKamera--;
            cout << "\nKamera berhasil dihapus!\n";
            return 0;
        }
    }
    cout << "\nKamera dengan kode tersebut tidak ditemukan.\n";
    return 0;
}

// Fungsi login
int login() {
    string nama, nim;
    int percobaan = 0;
    while (percobaan < 3) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama == "Henry" && nim == "2409106070") {
            return 1; // Login berhasil
        } else {
            cout << "Login gagal! Coba lagi.\n";
            percobaan++;
        }
    }
    cout << "Anda telah salah login 3 kali. Program berhenti.\n";
    return 0; // Login gagal
}

// Fungsi utama
int main() {
    if (!login()) return 0;

    int pilihan;
    do {
        cout << "\n=== Sistem Manajemen Penyewaan Kamera ===\n";
        cout << "1. Tambah Kamera\n";
        cout << "2. Lihat Daftar Kamera\n";
        cout << "3. Edit Kamera\n";
        cout << "4. Hapus Kamera\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tambahKamera();
        } else if (pilihan == 2) {
            tampilkanKamera();
        } else if (pilihan == 3) {
            editKamera();
        } else if (pilihan == 4) {
            hapusKamera();
        } else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan sistem ini!\n";
        } else {
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
