#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void menu_peran(){
    cout << " +-----------------------------------+ \n";
    cout << " | Selamat Datang di Program E-Zakat | \n";
    cout << " +-----------------------------------+ \n";
    cout << " | Silahkan Pilih Peran Anda :       | \n";
    cout << " | 1. Muzakki                        | \n";
    cout << " | 2. Amil Zakat                     | \n";
    cout << " +-----------------------------------+ \n";
    cout << " | Pilihan : ";
}

void header(){
    cout << " +-------------------------------------------+ \n";                   
    cout << " | Assalamualaikum Warahmatullahi Wabaraktuh | \n";
    cout << " +-------------------------------------------+ \n";
}

void menu_muzakki(){ 
    cout << " +-------------------------------------------+ \n";
    cout << " |             E-Zakat - Muzakki             | \n";
    cout << " +-------------------------------------------+ \n";
    cout << " | 1. Bayar Zakat Maal                       | \n";
    cout << " | 2. Bayar Zakat Fitrah                     | \n";
    cout << " | 3. Kalkulator Zakat                       | \n";
    cout << " | 4. Zakat Pedia                            | \n";
    cout << " | 5. Keluar                                 | \n";
    cout << " +-------------------------------------------+ \n";
}

void mencari_masjid(){
    cout << " Mencari Masjid Penyelanggara Zakat (Amil Zakat) Terdekat......\n";          
    Sleep(5000);                                                                          
    cout << " Masjid penyelenggara zakat (Amil Zakat) terdekat berhasil ditemukan!\n";    
    Sleep(1000);
}

void metode_pembayaran(){ 
    cout << " +----------------------------------------+ \n";
    cout << " |         Metode Pembayaran Zakat        | \n";
    cout << " +----------------------------------------+ \n";
    cout << " | 1. Bank                                | \n";
    cout << " | 2. E-Wallet                            | \n";
    cout << " +----------------------------------------+ \n";
}

void bank(){ 
    cout << " +----------------------------+\n";
    cout << " |         Pilih Bank         |\n";
    cout << " +----------------------------+\n";
    cout << " | 1. BCA Mobile              |\n";
    cout << " | 2. BRI Syariah             |\n";
    cout << " | 3. BNI Mobile              |\n";
    cout << " | 4. Mandiri Syariah         |\n";
    cout << " +----------------------------+\n";
}

void e_wallet(){ 
    cout << " +--------------------------------+\n";
    cout << " |         Pilih E-Wallet         |\n";
    cout << " +--------------------------------+\n";
    cout << " | 1. OVO                         |\n";
    cout << " | 2. Gopay                       |\n";
    cout << " | 3. Dana                        |\n";
    cout << " | 4. Link Aja                    |\n";
    cout << " +--------------------------------+\n";
}

void konfirmasi_pembayaran(){
    cout << " ---- Konfirmasi Pembayaran ---- \n";
    system("pause");
    cout << " Selamat, transaksi pembayaran zakat anda telah berhasil!" << endl; 
}

float zakatpenghasilan_penghasilan(float penghasilan){ 
    return 0.025 * penghasilan;
}

int zakatpenghasilan_nishab(int harga_emas){ 
    return 85 * harga_emas;
}

void kalkulator_zakat(){ 
    cout << " +------------------------------------+ \n";
    cout << " |      E-Zakat - Kalkulator Zakat    | \n";
    cout << " +------------------------------------+ \n";
}

void menu_amilzakat(){ 
    cout << " +-------------------------------------------+ \n";
    cout << " |           E-Zakat - Amil Zakat            | \n";
    cout << " +-------------------------------------------+ \n";
    cout << " | 1. Data Transaksi                         | \n";
    cout << " | 2. Data Antrian Muzakki                   | \n";
    cout << " | 3. Mencari Daerah Mustahik                | \n";
    cout << " | 4. Struktur Kepengurusan Amil Zakat       | \n";
    cout << " | 5. Keluar                                 | \n";
    cout << " +-------------------------------------------+ \n";
    cout << " | Pilihan Menu : ";
}

void menu_transaksi(){
    cout << " +----------------------------------+ \n";
    cout << " |       Menu Data Transaksi        | \n";
    cout << " +----------------------------------+ \n";
    cout << " | 1. Tampilkan Data Transaksi      | \n";
    cout << " | 2. Proses Data Transaksi         | \n";
    cout << " | 3. Hapus Semua Riwayat Transaksi | \n";
    cout << " +----------------------------------+ \n";
    cout << " | Pilihan : ";
}

void menu_antrian(){
    cout << " +---------------------------------+ \n";
    cout << " |   Menu Data Antrian Amil Zakat  | \n";
    cout << " +---------------------------------+ \n";
    cout << " | 1. Menampilkan Data Antrian     | \n";
    cout << " | 2. Proses Data Antrian          | \n";
    cout << " | 3. Cari data berdasarkan nama   | \n";
    cout << " +---------------------------------+ \n";
    cout << " | Pilihan : "; 
}

void closing(){
    cout << "----------------------------------------------\n";                             
    cout << "  Terima Kasih Sudah Menggunakan Program ini  \n";
    cout << "----------------------------------------------\n";
}