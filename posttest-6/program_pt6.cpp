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

bool login(const string &username, const string &nim)
{
    return username == "Henry" && nim == "2409106070";
}

void tambahPenyewaan(Penyewaan *daftar, int *jumlah)
{
    if (*jumlah >= MAX_CAMERAS)
    {
        cout << "\nMaksimum penyewaan telah tercapai!\n";
        return;
    }

    cout << "\nMasukkan Nama Penyewa: ";
    cin >> ws;
    getline(cin, daftar[*jumlah].namaPenyewa);
    cout << "Masukkan Nama Kamera: ";
    getline(cin, daftar[*jumlah].namaKamera);
    cout << "Masukkan Tipe Kamera: ";
    getline(cin, daftar[*jumlah].tipeKamera);
    cout << "Masukkan Harga Sewa per Hari: ";
    cin >> daftar[*jumlah].hargaSewa;
    cout << "Masukkan Durasi Sewa (hari): ";
    cin >> daftar[*jumlah].durasiSewa;

    (*jumlah)++;
    cout << "Penyewaan berhasil ditambahkan!\n";
}

void tampilkanPenyewaan(Penyewaan daftar[], int jumlah)
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

void editPenyewaan(Penyewaan *daftar, int jumlah)
{
    if (jumlah == 0)
    {
        cout << "\nBelum ada data untuk diedit!\n";
        return;
    }

    int index;
    cout << "\nMasukkan nomor penyewaan yang ingin diedit: ";
    cin >> index;

    if (index < 1 || index > jumlah)
    {
        cout << "Nomor tidak valid!\n";
        return;
    }

    Penyewaan *data = &daftar[index - 1];

    cout << "Masukkan Nama Penyewa baru: ";
    cin >> ws;
    getline(cin, data->namaPenyewa);
    cout << "Masukkan Nama Kamera baru: ";
    getline(cin, data->namaKamera);
    cout << "Masukkan Tipe Kamera baru: ";
    getline(cin, data->tipeKamera);
    cout << "Masukkan Harga Sewa baru per Hari: ";
    cin >> data->hargaSewa;
    cout << "Masukkan Durasi Sewa baru (hari): ";
    cin >> data->durasiSewa;

    cout << "Data penyewaan berhasil diperbarui!\n";
}

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

// ======== Sorting ========
void sortNamaKameraDescending(Penyewaan daftar[], int jumlah)
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = i + 1; j < jumlah; j++)
        {
            if (daftar[i].namaKamera < daftar[j].namaKamera)
            {
                swap(daftar[i], daftar[j]);
            }
        }
    }
}

void sortHargaAscending(Penyewaan daftar[], int jumlah)
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = i + 1; j < jumlah; j++)
        {
            if (daftar[i].hargaSewa > daftar[j].hargaSewa)
            {
                swap(daftar[i], daftar[j]);
            }
        }
    }
}

void sortDurasiDescending(Penyewaan daftar[], int jumlah)
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = i + 1; j < jumlah; j++)
        {
            if (daftar[i].durasiSewa < daftar[j].durasiSewa)
            {
                swap(daftar[i], daftar[j]);
            }
        }
    }
}

void menuTampilkanSorted()
{
    int pilih;
    cout << "\n=== Pilih Metode Sorting ===\n";
    cout << "1. Sorting Nama Kamera (Z - A)\n";
    cout << "2. Sorting Harga Sewa (Termurah - Termahal)\n";
    cout << "3. Sorting Durasi Sewa (Terlama - Terpendek)\n";
    cout << "Pilih: ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
        sortNamaKameraDescending(daftarSewa, jumlahSewa);
        break;
    case 2:
        sortHargaAscending(daftarSewa, jumlahSewa);
        break;
    case 3:
        sortDurasiDescending(daftarSewa, jumlahSewa);
        break;
    default:
        cout << "Pilihan tidak valid. Menampilkan tanpa sorting.\n";
    }
    tampilkanPenyewaan(daftarSewa, jumlahSewa);
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
        cout << "\n=== Sistem Manajemen Penyewaan Kamera ===\n";
        cout << "1. Tambah Kamera\n";
        cout << "2. Lihat Daftar Kamera\n";
        cout << "3. Edit Kamera\n";
        cout << "4. Hapus Kamera\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahPenyewaan(daftarSewa, &jumlahSewa);
            break;
        case 2:
            menuTampilkanSorted();
            break;
        case 3:
            editPenyewaan(daftarSewa, jumlahSewa);
            break;
        case 4:
            hapusPenyewaan(daftarSewa, jumlahSewa);
            break;
        case 5:
            cout << "Terima kasih telah menggunakan sistem ini!\n";
            return 0;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}
