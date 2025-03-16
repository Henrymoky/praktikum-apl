#include <iostream>
using namespace std;

// Fungsi Login
bool login()
{
    string inputUser, inputPass;
    int attempts = 0;
    const string correctUser = "Henry";
    const string correctPass = "2409106070";

    while (attempts < 3)
    {
        cout << "\nUsername: ";
        cin >> inputUser;
        cout << "Password: ";
        cin >> inputPass;

        if (inputUser == correctUser && inputPass == correctPass)
        {
            return true;
        }
        else
        {
            cout << "Login gagal! Coba lagi.\n";
            attempts++;
        }
    }
    cout << "Login gagal 3 kali. Program berhenti.\n";
    return false;
}

// Fungsi Konversi Mata Uang
void konversiMataUang()
{
    int pilihan;
    double jumlah;
    while (true)
    {
        system("clear");
        cout << "\n=== Konversi Mata Uang ===\n";
        cout << "1. Rupiah ke Dolar AS\n2. Rupiah ke Euro\n3. Dolar AS ke Rupiah\n";
        cout << "4. Dolar AS ke Euro\n5. Euro ke Rupiah\n6. Euro ke Dolar AS\n7. Kembali\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 7)
            break;

        cout << "Masukkan jumlah: ";
        cin >> jumlah;

        switch (pilihan)
        {
        case 1:
            cout << "Hasil: " << jumlah / 15000 << " USD\n";
            break;
        case 2:
            cout << "Hasil: " << jumlah / 16500 << " EUR\n";
            break;
        case 3:
            cout << "Hasil: " << jumlah * 15000 << " IDR\n";
            break;
        case 4:
            cout << "Hasil: " << jumlah * 0.91 << " EUR\n";
            break;
        case 5:
            cout << "Hasil: " << jumlah * 16500 << " IDR\n";
            break;
        case 6:
            cout << "Hasil: " << jumlah / 0.91 << " USD\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
        cout << "\nTekan Enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
    }
}

// Fungsi Konversi Jarak
void konversiJarak()
{
    int pilihan;
    double jumlah;
    while (true)
    {
        system("clear");
        cout << "\n=== Konversi Jarak ===\n";
        cout << "1. Kilometer ke Meter\n2. Kilometer ke Centimeter\n3. Meter ke Kilometer\n";
        cout << "4. Meter ke Centimeter\n5. Centimeter ke Kilometer\n6. Centimeter ke Meter\n7. Kembali\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 7)
            break;

        cout << "Masukkan jarak: ";
        cin >> jumlah;

        switch (pilihan)
        {
        case 1:
            cout << "Hasil: " << jumlah * 1000 << " meter\n";
            break;
        case 2:
            cout << "Hasil: " << jumlah * 100000 << " cm\n";
            break;
        case 3:
            cout << "Hasil: " << jumlah / 1000 << " km\n";
            break;
        case 4:
            cout << "Hasil: " << jumlah * 100 << " cm\n";
            break;
        case 5:
            cout << "Hasil: " << jumlah / 100000 << " km\n";
            break;
        case 6:
            cout << "Hasil: " << jumlah / 100 << " meter\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
        cout << "\nTekan Enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
    }
}

// Fungsi Konversi Waktu
void konversiWaktu()
{
    int pilihan;
    double jumlah;
    while (true)
    {
        system("clear");
        cout << "\n=== Konversi Waktu ===\n";
        cout << "1. Jam ke Menit\n2. Jam ke Detik\n3. Menit ke Jam\n";
        cout << "4. Menit ke Detik\n5. Detik ke Jam\n6. Detik ke Menit\n7. Kembali\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 7)
            break;

        cout << "Masukkan waktu: ";
        cin >> jumlah;

        switch (pilihan)
        {
        case 1:
            cout << "Hasil: " << jumlah * 60 << " menit\n";
            break;
        case 2:
            cout << "Hasil: " << jumlah * 3600 << " detik\n";
            break;
        case 3:
            cout << "Hasil: " << jumlah / 60 << " jam\n";
            break;
        case 4:
            cout << "Hasil: " << jumlah * 60 << " detik\n";
            break;
        case 5:
            cout << "Hasil: " << jumlah / 3600 << " jam\n";
            break;
        case 6:
            cout << "Hasil: " << jumlah / 60 << " menit\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
        cout << "\nTekan Enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
    }
}

// Program Utama
int main()
{
    if (!login())
        return 0;

    int pilihan;
    while (true)
    {
        system("clear");
        cout << "\n=== Menu Utama ===\n";
        cout << "1. Konversi Mata Uang\n2. Konversi Jarak\n3. Konversi Waktu\n4. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            konversiMataUang();
            break;
        case 2:
            konversiJarak();
            break;
        case 3:
            konversiWaktu();
            break;
        case 4:
            cout << "Logout berhasil! Program selesai.\n";
            return 0;
        default:
            cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    }
}
