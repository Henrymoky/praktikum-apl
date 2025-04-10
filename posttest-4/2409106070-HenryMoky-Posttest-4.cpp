#include <iostream>
#include <string>
using namespace std;

#define MAX_CAMERAS 20

struct Penyewaan
{
    string namaPenyewa;
    string namaKamera;
    string tipeKamera;
    int hargaSewa;
    int durasiSewa;
};

Penyewaan daftarSewa[MAX_CAMERAS];
int jumlahSewa = 0;

// Fungsi login
bool login(const string &username, const string &nim)
{
    return username == "Henry" && nim == "2409106070";
}

// Prosedur menambahkan penyewaan
void tambahPenyewaan(Penyewaan daftar[], int &jumlah)
{
    if (jumlah >= MAX_CAMERAS)
    {
        cout << "\nMaksimum penyewaan telah tercapai!\n";
        return;
    }

    cout << "\nMasukkan Nama Penyewa: ";
    cin >> ws;
    getline(cin, daftar[jumlah].namaPenyewa);
    cout << "Masukkan Nama Kamera: ";
    getline(cin, daftar[jumlah].namaKamera);
    cout << "Masukkan Tipe Kamera: ";
    getline(cin, daftar[jumlah].tipeKamera);
    cout << "Masukkan Harga Sewa per Hari: ";
    cin >> daftar[jumlah].hargaSewa;
    cout << "Masukkan Durasi Sewa (hari): ";
    cin >> daftar[jumlah].durasiSewa;

    jumlah++;
    cout << "Penyewaan berhasil ditambahkan!\n";
}

// Prosedur menampilkan daftar penyewaan
void tampilkanPenyewaan(const Penyewaan daftar[], int jumlah)
{
    if (jumlah == 0)
    {
        cout << "\nBelum ada data penyewaan!\n";
        return;
    }

    cout << "\nDaftar Penyewaan:\n";
    cout << "====================================================\n";
    for (int i = 0; i < jumlah; i++)
    {
        cout << i + 1 << ". Nama Penyewa: " << daftar[i].namaPenyewa << "\n";
        cout << "   Kamera: " << daftar[i].namaKamera << " (" << daftar[i].tipeKamera << ") | Harga: "
             << daftar[i].hargaSewa << " | Durasi: " << daftar[i].durasiSewa << " hari\n";
        cout << "----------------------------------------------------\n";
    }
}

// Prosedur untuk menghapus data penyewaan
void hapusPenyewaan(Penyewaan daftar[], int &jumlah)
{
    if (jumlah == 0)
    {
        cout << "\nTidak ada data untuk dihapus!\n";
        return;
    }

    int index;
    cout << "\nMasukkan nomor penyewaan yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > jumlah)
    {
        cout << "Nomor tidak valid!\n";
        return;
    }

    for (int i = index - 1; i < jumlah - 1; i++)
    {
        daftar[i] = daftar[i + 1];
    }

    jumlah--;
    cout << "Penyewaan berhasil dihapus!\n";
}

int main()
{
    string nama, nim;
    int attempts = 3;

    while (attempts > 0)
    {
        cout << "\nMasukkan Nama: ";
        cin >> ws;
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (login(nama, nim))
        {
            cout << "Login berhasil!\n";
            break;
        }
        else
        {
            cout << "Login gagal! Sisa percobaan: " << --attempts << "\n";
        }
    }

    if (attempts == 0)
    {
        cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    int pilihan;
    while (true)
    {
        cout << "\n1. Tambah Penyewaan\n2. Tampilkan Penyewaan\n3. Hapus Penyewaan\n4. Keluar\nPilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahPenyewaan(daftarSewa, jumlahSewa);
            break;
        case 2:
            tampilkanPenyewaan(daftarSewa, jumlahSewa);
            break;
        case 3:
            hapusPenyewaan(daftarSewa, jumlahSewa);
            break;
        case 4:
            cout << "Terima kasih telah menggunakan sistem penyewaan kamera!\n";
            return 0;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}
