#include <iostream>
#include <string>
using namespace std;

#define MAX_CAMERAS 20

// Struct untuk data penyewaan kamera
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

        if (nama == "Henry" && nim == "2409106070")
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

        if (pilihan == 1)
        {
            if (jumlahSewa >= MAX_CAMERAS)
            {
                cout << "\nMaksimum penyewaan telah tercapai!\n";
                continue;
            }
            cout << "\nMasukkan Nama Penyewa: ";
            cin >> ws;
            getline(cin, daftarSewa[jumlahSewa].namaPenyewa);
            cout << "Masukkan Nama Kamera: ";
            getline(cin, daftarSewa[jumlahSewa].namaKamera);
            cout << "Masukkan Tipe Kamera: ";
            getline(cin, daftarSewa[jumlahSewa].tipeKamera);
            cout << "Masukkan Harga Sewa per Hari: ";
            cin >> daftarSewa[jumlahSewa].hargaSewa;
            cout << "Masukkan Durasi Sewa (hari): ";
            cin >> daftarSewa[jumlahSewa].durasiSewa;
            jumlahSewa++;
            cout << "Penyewaan berhasil ditambahkan!\n";
        }
        else if (pilihan == 2)
        {
            if (jumlahSewa == 0)
            {
                cout << "\nBelum ada data penyewaan!\n";
                continue;
            }
            cout << "\nDaftar Penyewaan:\n";
            cout << "====================================================\n";
            for (int i = 0; i < jumlahSewa; i++)
            {
                cout << i + 1 << ". Nama Penyewa: " << daftarSewa[i].namaPenyewa << "\n";
                cout << "   Kamera: " << daftarSewa[i].namaKamera << " (" << daftarSewa[i].tipeKamera << ") | Harga: " << daftarSewa[i].hargaSewa << " | Durasi: " << daftarSewa[i].durasiSewa << " hari\n";
                cout << "----------------------------------------------------\n";
            }
        }
        else if (pilihan == 3)
        {
            if (jumlahSewa == 0)
            {
                cout << "\nTidak ada data untuk dihapus!\n";
                continue;
            }
            int index;
            cout << "\nMasukkan nomor penyewaan yang ingin dihapus: ";
            cin >> index;
            if (index < 1 || index > jumlahSewa)
            {
                cout << "Nomor tidak valid!\n";
                continue;
            }
            for (int i = index - 1; i < jumlahSewa - 1; i++)
            {
                daftarSewa[i] = daftarSewa[i + 1];
            }
            jumlahSewa--;
            cout << "Penyewaan berhasil dihapus!\n";
        }
        else if (pilihan == 4)
        {
            cout << "Terima kasih telah menggunakan sistem penyewaan kamera!\n";
            break;
        }
        else
        {
            cout << "Pilihan tidak valid!\n";
        }
    }
    return 0;
}
