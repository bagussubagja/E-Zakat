#include <iostream>
#include <string>
#include <string.h>
#include <limits>
#include <iomanip>
#include <fstream>
#include <chrono> 
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <stdlib.h>
#include "menu.h"
#include "db_muzakki.h"
#include "db_amilzakat.h"
#include "db_masjid.h"
#include "transaksi.h"
#include "scope.h"
#include "antrian.h"
#include "zakatpedia.h"
#include "struktur.h"

using namespace std;

int main(){
    ofstream berkas;
    auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
    struct Graph *graph = createGraph(V, E); 
    create_queue();    

    tampilanawal_aplikasi:                                                                           
    system("CLS");
    menu_peran();                                                                                                                                   
    cin >> dataperan;
    system("CLS");
    if(dataperan == 1){                                
    cout << " +-------------------------------------------+ \n";
    cout << " |             E-Zakat - Muzakki             | \n";
    cout << " +-------------------------------------------+ \n";                               
    cin.ignore(numeric_limits<streamsize>::max(),'\n');                             
    cout << " | Nama          : "; getline(cin, *data_muzakki.nama_muzakki);          
    cout << " | Alamat        : "; getline(cin, data_muzakki.alamat_muzakki);
    cout << " | Kode Pos      : "; cin >> data_muzakki.kode_pos;
    cout << " | Nomor Telepon : "; cin >> data_muzakki.no_telp_muzakki;         
    cout << " | Orang tanggungan zakat keluarga ( 0 = Tidak ada) : ";                       
    cin >> orangtanggungan;
    if(orangtanggungan == 0){                                                      
        goto menuawal_muzakki;
    }else{                                                                          
        for(int i = 0; i < orangtanggungan; i++){
            cout << " | " << i+1 << ". Nama : ";
            data_tanggungan.nama_tanggungan[0] = *data_muzakki.nama_muzakki;
            cin >> data_tanggungan.nama_tanggungan[i+1];
        }
    }   
    }else if(dataperan == 2){                                                           
    cout << " +-------------------------------------------+ \n";
    cout << " |           E-Zakat - Amil Zakat            | \n";
    cout << " +-------------------------------------------+ \n";               
    cin.ignore(numeric_limits<streamsize>::max(),'\n');\                          
    cout << " | Nama Masjid     : "; getline(cin, data_amilzakat.nama_masjid);       
    cout << " | Alamat Masjid   : "; getline(cin, data_amilzakat.alamat_masjid);
    cout << " | Kode Pos Masjid : "; cin >> data_amilzakat.kode_pos;     
    
    if(data_amilzakat.nama_masjid == data_masjid1.nama_masjid1){                        
        if(data_amilzakat.alamat_masjid == data_masjid1.alamat_masjid1){
            if(data_amilzakat.kode_pos == data_masjid1.kode_pos1)
            goto menuawal_amilzakat;                                                    
        }                       
    }else if(data_amilzakat.nama_masjid == data_masjid2.nama_masjid2){                  
        if(data_amilzakat.alamat_masjid == data_masjid2.alamat_masjid2){
            if(data_amilzakat.kode_pos == data_masjid2.kode_pos2)
            goto menuawal_amilzakat;                                                    
        }
    }else if(data_amilzakat.nama_masjid == data_masjid3.nama_masjid3){
        if(data_amilzakat.alamat_masjid == data_masjid3.alamat_masjid3){
            if(data_amilzakat.kode_pos == data_masjid3.kode_pos3){
            goto menuawal_amilzakat;
            }
        }
    }else if(data_amilzakat.nama_masjid == data_masjid1_1.nama_masjid1_1){
        if(data_amilzakat.alamat_masjid == data_masjid1_1.alamat_masjid1_1){
            if(data_amilzakat.kode_pos == data_masjid1_1.kode_pos1_1){
            goto menuawal_amilzakat;
            }
        }
    }else if(data_amilzakat.nama_masjid == data_masjid2_1.nama_masjid2_1){
        if(data_amilzakat.alamat_masjid == data_masjid2_1.alamat_masjid2_1){
            if(data_amilzakat.kode_pos == data_masjid2_1.kode_pos2_1){
            goto menuawal_amilzakat;
            }
        }
    }else if(data_amilzakat.nama_masjid == data_masjid3_1.nama_masjid3_1){
        if(data_amilzakat.alamat_masjid == data_masjid3_1.alamat_masjid3_1){
            if(data_amilzakat.kode_pos == data_masjid3_1.kode_pos3_1){
            goto menuawal_amilzakat;
            }
        }
    }
    else{
        cout << "Akun Amil Zakat yang anda masukkan salah!" << endl;
        Sleep(2000);
        goto tampilanawal_aplikasi;
    }
    }else{
        cout << "Silahkan untuk memilih peran yang ada!" << endl;
        Sleep(2000);
        goto tampilanawal_aplikasi;
    }

    switch(dataperan){
    case 1:                                                                         
        system("CLS");
        menuawal_muzakki:
        char ulang_menu_muzakki;
        system("CLS");
        header();
        cout << " | Selamat Datang, " << *data_muzakki.nama_muzakki << "!"<< "\n";
        cout << " | Alamat        : " << data_muzakki.alamat_muzakki << "\n";
        menu_muzakki();
        cout << " | Pilihan Menu : ";                                               
        cin >> pil_menu_muzakki;
            switch (pil_menu_muzakki){
            case 1:                                                                 
                system("CLS");
                metode_pembayaran();                                                
                cout << " | Pilihan : "; cin >> menu_pil;                           
                switch(menu_pil){
                    case 1:                                                                           
                    system("CLS");
                    mencarimasjid:
                    system("CLS");
                    mencari_masjid();
                    if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                    cout << " Nama Masjid       : " << data_masjid1.nama_masjid1 << endl;
                    cout << " Alamat Masjid     : " << data_masjid1.alamat_masjid1 << endl;
                    cout << " Nomor Rekening    : " << data_masjid1.no_rek_masjid1_bca << " Bank BCA " << endl;
                    cout << "                   : " << data_masjid1.no_rek_masjid1_bri << " Bank BRI Syariah " << endl;
                    cout << "                   : " << data_masjid1.no_rek_masjid1_bni << " Bank BNI " << endl;
                    cout << "                   : " << data_masjid1.no_rek_masjid1_msy << " Bank Mandiri Syariah " << endl;
                    cout << " Narahubung        : " << data_masjid1.no_telp1 << " A/N " << data_masjid1.narahubung1 << endl;
                    Sleep(2000);
                    }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                    cout << " Nama Masjid       : " << data_masjid2.nama_masjid2 << endl;
                    cout << " Alamat Masjid     : " << data_masjid2.alamat_masjid2 << endl;
                    cout << " Nomor Rekening    : " << data_masjid2.no_rek_masjid2_bca << " Bank BCA " << endl;
                    cout << "                   : " << data_masjid2.no_rek_masjid2_bri << " Bank BRI Syariah " << endl;
                    cout << "                   : " << data_masjid2.no_rek_masjid2_bni << " Bank BNI " << endl;
                    cout << "                   : " << data_masjid2.no_rek_masjid2_msy << " Bank Mandiri Syariah " << endl;
                    cout << " Narahubung        : " << data_masjid2.no_telp2 << " A/N " << data_masjid2.narahubung2 << endl;
                    Sleep(2000);
                    }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                    cout << " Nama Masjid       : " << data_masjid3.nama_masjid3 << endl;
                    cout << " Alamat Masjid     : " << data_masjid3.alamat_masjid3 << endl;
                    cout << " Nomor Rekening    : " << data_masjid3.no_rek_masjid3_bca << " Bank BCA " << endl;
                    cout << "                   : " << data_masjid3.no_rek_masjid3_bri << " Bank BRI Syariah " << endl;
                    cout << "                   : " << data_masjid3.no_rek_masjid3_bni << " Bank BNI " << endl;
                    cout << "                   : " << data_masjid3.no_rek_masjid3_msy << " Bank Mandiri Syariah " << endl;
                    cout << " Narahubung        : " << data_masjid3.no_telp3 << " A/N " << data_masjid3.narahubung3 << endl;
                    Sleep(2000);
                    }else{
                    cout << " Mohon maaf, tidak terdapat masjid yang menyelenggarakan di lokasi sekitarmu " << endl;
                    Sleep(1500);
                    goto menuawal_muzakki;
                    }                                                                          
                    cout << endl;
                    bank();
                    cout << " | Pilihan Bank : "; cin >> pil_bank;                                                                          
                            switch (pil_bank)
                            {
                            case 1:
                                system("CLS");                                                   
                                cout << " +----------------------+ \n";
                                cout << " |----- BCA MOBILE -----| \n";
                                cout << " +----------------------+ \n";
                                cout << " Masukan Nomor Rekening Amil Zakat : ";        
                                cin >> no_rek_amilzakat;                               
                                if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                                    if(pil_bank == 1){
                                        if(no_rek_amilzakat != data_masjid1.no_rek_masjid1_bca){
                                        cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                        Sleep(1000);
                                        goto mencarimasjid; 
                                        }else{
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                               
                                    }
                                }
                                        }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                                    if(pil_bank == 1){
                                        if(no_rek_amilzakat != data_masjid2.no_rek_masjid2_bca){
                                        cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                        Sleep(1000);
                                        goto mencarimasjid; 
                                        }else{
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                               
                                    }
                                }
                                        }   
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                                    if(pil_bank == 1){
                                        if(no_rek_amilzakat != data_masjid3.no_rek_masjid3_bca){
                                        cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                        Sleep(1000);
                                        goto mencarimasjid; 
                                        }else{
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                               
                                    }
                                }
                                        }
                                    }
                                }
                            konfirmasi_pembayaran();
                            break;
                            case 2:
                            system("CLS");                                                   
                                cout << " +-----------------------+ \n";
                                cout << " |----- BRI Syariah -----| \n";
                                cout << " +-----------------------+ \n";
                                cout << " Masukan Nomor Rekening Amil Zakat : ";
                                cin >> no_rek_amilzakat;                               
                                if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                                    if(pil_bank == 2){
                                        if(no_rek_amilzakat != data_masjid1.no_rek_masjid1_bri){
                                            cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                            Sleep(1000);
                                            goto mencarimasjid;
                                        }else{
                                            if(orangtanggungan == 0 ){                          
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(*data_muzakki.nama_muzakki ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                            }else{                                              
                                            for(int i = 0; i < orangtanggungan +1; i++){
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                                }
                                            }
                                        }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                                    if(pil_bank ==2){
                                        if(no_rek_amilzakat != data_masjid2.no_rek_masjid2_bri){
                                            cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                            Sleep(1000);
                                            goto mencarimasjid;
                                        }else{
                                            if(orangtanggungan == 0 ){                          
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(*data_muzakki.nama_muzakki ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                            }else{                                              
                                            for(int i = 0; i < orangtanggungan +1; i++){
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                                }
                                            }
                                        }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                                    if(pil_bank == 2){
                                        if(no_rek_amilzakat != data_masjid3.no_rek_masjid3_bri){
                                            cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                            Sleep(1000);
                                            goto mencarimasjid; 
                                        }else{
                                            if(orangtanggungan == 0 ){                          
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(*data_muzakki.nama_muzakki ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                            }else{                                              
                                            for(int i = 0; i < orangtanggungan +1; i++){
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                                }
                                            }
                                        }
                                    }
                                }                          
                            konfirmasi_pembayaran();
                            break;
                            case 3:
                            system("CLS");                                                 
                                cout << " +-----------------------+ \n";
                                cout << " |----- BNI Mobile  -----| \n";
                                cout << " +-----------------------+ \n";
                                cout << " Masukan Nomor Rekening Amil Zakat : ";
                                cin >> no_rek_amilzakat;
                                if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                                    if(pil_bank == 3){
                                        if(no_rek_amilzakat != data_masjid1.no_rek_masjid1_bni){
                                            cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                            Sleep(1000);
                                            goto mencarimasjid;
                                        }else{
                                            if(orangtanggungan == 0 ){                          
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(*data_muzakki.nama_muzakki ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                            }else{                                              
                                            for(int i = 0; i < orangtanggungan +1; i++){
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                                }
                                            }
                                        }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                                    if(pil_bank == 3){
                                        if(no_rek_amilzakat != data_masjid2.no_rek_masjid2_bni){
                                            cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                            Sleep(1000);
                                            goto mencarimasjid;
                                        }else{
                                            if(orangtanggungan == 0 ){                          
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(*data_muzakki.nama_muzakki ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                            }else{                                              
                                            for(int i = 0; i < orangtanggungan +1; i++){
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                                }
                                            }
                                        }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                                    if(pil_bank == 3){
                                        if(no_rek_amilzakat != data_masjid3.no_rek_masjid3_bni){
                                            cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                            Sleep(1000);
                                            goto mencarimasjid; 
                                        }else{
                                            if(orangtanggungan == 0 ){                          
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(*data_muzakki.nama_muzakki ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                            }else{                                              
                                            for(int i = 0; i < orangtanggungan +1; i++){
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                                }
                                            }
                                        }
                                    }
                                }                          
                            konfirmasi_pembayaran();
                            break;
                            case 4:
                            system("CLS");                                                
                                cout << " +---------------------------+ \n";
                                cout << " |----- Mandiri Syariah -----| \n";
                                cout << " +---------------------------+ \n";
                                cout << " Masukan Nomor Rekening Amil Zakat : ";
                                cin >> no_rek_amilzakat;
                                if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                                    if(pil_bank == 4){
                                        if(no_rek_amilzakat != data_masjid1.no_rek_masjid1_msy){
                                            cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                            Sleep(1000);
                                            goto mencarimasjid;
                                        }else{
                                            if(orangtanggungan == 0 ){                          
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(*data_muzakki.nama_muzakki ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                            }else{                                              
                                            for(int i = 0; i < orangtanggungan +1; i++){
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                                }
                                            }
                                        }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                                    if(pil_bank == 4){
                                        if(no_rek_amilzakat != data_masjid2.no_rek_masjid2_msy){
                                            cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                            Sleep(1000);
                                            goto mencarimasjid;
                                        }else{
                                            if(orangtanggungan == 0 ){                          
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(*data_muzakki.nama_muzakki ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                            }else{                                              
                                            for(int i = 0; i < orangtanggungan +1; i++){
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                                }
                                            }
                                        }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                                    if(pil_bank == 4){
                                        if(no_rek_amilzakat != data_masjid3.no_rek_masjid3_msy){
                                            cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                            Sleep(1000);
                                            goto mencarimasjid; 
                                        }else{
                                            if(orangtanggungan == 0 ){                          
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(*data_muzakki.nama_muzakki ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                            }else{                                              
                                            for(int i = 0; i < orangtanggungan +1; i++){
                                            cout << " Masukan Nominal (dalam Rupiah) : ";
                                            cin >> nominal_zakat;
                                            input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                           
                                                }
                                            }
                                        }
                                    }
                                }                          
                                konfirmasi_pembayaran();
                                break;
                                default:
                                break;
                            }
                    break;
                    case 2:                                                                                         
                    system("cls");                                           
                    carimasjid:
                    system("CLS");
                    mencari_masjid();
                    if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                    cout << " Nama Masjid       : " << data_masjid1.nama_masjid1 << endl;
                    cout << " Alamat Masjid     : " << data_masjid1.alamat_masjid1 << endl;
                    cout << " Nomor Rekening    : " << rekening.no1 << " Bank BCA " << endl;
                    cout << "                   : " << rekening.no2 << " Bank BRI Syariah " << endl;
                    cout << "                   : " << rekening.no3 << " Bank BNI " << endl;
                    cout << "                   : " << rekening.no4 << " Bank Mandiri Syariah " << endl;
                    cout << " Narahubung        : " << data_masjid1.no_telp1 << " A/N " << data_masjid1.narahubung1 << endl;
                    Sleep(2000);
                    }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                    cout << " Nama Masjid       : " << data_masjid2.nama_masjid2 << endl;
                    cout << " Alamat Masjid     : " << data_masjid2.alamat_masjid2 << endl;
                    cout << " Nomor Rekening    : " << rekening.no1 << " Bank BCA " << endl;
                    cout << "                   : " << rekening.no2 << " Bank BRI Syariah " << endl;
                    cout << "                   : " << rekening.no3 << " Bank BNI " << endl;
                    cout << "                   : " << rekening.no4 << " Bank Mandiri Syariah " << endl;
                    cout << " Narahubung        : " << data_masjid2.no_telp2 << " A/N " << data_masjid2.narahubung2 << endl;
                    Sleep(2000);
                    }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                    cout << " Nama Masjid       : " << data_masjid3.nama_masjid3 << endl;
                    cout << " Alamat Masjid     : " << data_masjid3.alamat_masjid3 << endl;
                    cout << " Nomor Rekening    : " << rekening.no1 << " Bank BCA " << endl;
                    cout << "                   : " << rekening.no2 << " Bank BRI Syariah " << endl;
                    cout << "                   : " << rekening.no3 << " Bank BNI " << endl;
                    cout << "                   : " << rekening.no4 << " Bank Mandiri Syariah " << endl;
                    cout << " Narahubung        : " << data_masjid3.no_telp3 << " A/N " << data_masjid3.narahubung3 << endl;
                    Sleep(2000);
                    }else{
                    cout << " Mohon maaf, tidak terdapat masjid yang menyelenggarakan di lokasi sekitarmu " << endl;
                    Sleep(1500);
                    goto menuawal_muzakki;
                    }
                    cout << endl;
                    e_wallet();                                                                                     
                    cout << " | Pilihan E-Wallet : "; cin >> pil_ewallet;
                        switch(pil_ewallet){
                        case 1:
                        system("CLS");                                                                                     
                            cout << " +-----------------------+ \n";
                            cout << " |-----    OVO      -----| \n";
                            cout << " +-----------------------+ \n";
                            cout << " Masukan Nomor Rekening Amil Zakat : ";
                            cin >> no_rek_amilzakat;
                            if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                                    if(pil_ewallet == 1){
                                        if(no_rek_amilzakat == rekening.no1 || no_rek_amilzakat == rekening.no2 || no_rek_amilzakat == rekening.no3 || no_rek_amilzakat == rekening.no4){
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                        
                                    }
                                }
                                }else{
                                    cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                    Sleep(1000);
                                    goto carimasjid; 
                                }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                                    if(pil_ewallet == 1){
                                    if(no_rek_amilzakat == rekening.no1 || no_rek_amilzakat == rekening.no2 || no_rek_amilzakat == rekening.no3 || no_rek_amilzakat == rekening.no4){
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                        
                                    }
                                }
                                }else{
                                    cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                    Sleep(1000);
                                    goto carimasjid; 
                                }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                                    if(pil_ewallet == 1){
                                        if(no_rek_amilzakat == rekening.no1 || no_rek_amilzakat == rekening.no2 || no_rek_amilzakat == rekening.no3 || no_rek_amilzakat == rekening.no4){
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                        
                                    }
                                }
                                }else{
                                    cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                    Sleep(1000);
                                    goto carimasjid; 
                                }
                                    }
                                }
                            konfirmasi_pembayaran();
                            break;
                        case 2:
                        system("CLS");                                                                                     
                            cout << " +-----------------------+ \n";
                            cout << " |-----    Gopay    -----| \n";
                            cout << " +-----------------------+ \n";
                            cout << " Masukan Nomor Rekening Amil Zakat : ";
                            cin >> no_rek_amilzakat;
                            if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                                    if(pil_ewallet == 2){
                                        if(no_rek_amilzakat == rekening.no1 || no_rek_amilzakat == rekening.no2 || no_rek_amilzakat == rekening.no3 || no_rek_amilzakat == rekening.no4){
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                        
                                    }
                                }
                                }else{
                                    cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                    Sleep(1000);
                                    goto carimasjid; 
                                }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                                    if(pil_ewallet ==2){
                                        if(no_rek_amilzakat == rekening.no1 || no_rek_amilzakat == rekening.no2 || no_rek_amilzakat == rekening.no3 || no_rek_amilzakat == rekening.no4){
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                        
                                    }
                                }
                                }else{
                                    cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                    Sleep(1000);
                                    goto carimasjid; 
                                }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                                    if(pil_ewallet == 2){
                                        if(no_rek_amilzakat == rekening.no1 || no_rek_amilzakat == rekening.no2 || no_rek_amilzakat == rekening.no3 || no_rek_amilzakat == rekening.no4){
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                        
                                    }
                                }
                                }else{
                                    cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                    Sleep(1000);
                                    goto carimasjid; 
                                }
                                    }
                                }                          
                            konfirmasi_pembayaran();
                            break;
                        case 3:
                        system("CLS");                                                                                   
                            cout << " +-----------------------+ \n";
                            cout << " |-----    DANA     -----| \n";
                            cout << " +-----------------------+ \n";
                            cout << " Masukan Nomor Rekening Amil Zakat : ";
                            cin >> no_rek_amilzakat;
                            if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                                    if(pil_ewallet == 3){
                                        if(no_rek_amilzakat == rekening.no1 || no_rek_amilzakat == rekening.no2 || no_rek_amilzakat == rekening.no3 || no_rek_amilzakat == rekening.no4){
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                        
                                    }
                                }
                                }else{
                                    cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                    Sleep(1000);
                                    goto carimasjid; 
                                }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                                    if(pil_ewallet == 3){
                                        if(no_rek_amilzakat == rekening.no1 || no_rek_amilzakat == rekening.no2 || no_rek_amilzakat == rekening.no3 || no_rek_amilzakat == rekening.no4){
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                        
                                    }
                                }
                                }else{
                                    cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                    Sleep(1000);
                                    goto carimasjid; 
                                }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                                    if(pil_ewallet == 3){
                                        if(no_rek_amilzakat == rekening.no1 || no_rek_amilzakat == rekening.no2 || no_rek_amilzakat == rekening.no3 || no_rek_amilzakat == rekening.no4){
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                        
                                    }
                                }
                                }else{
                                    cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                    Sleep(1000);
                                    goto carimasjid; 
                                }
                                    }
                                }                          
                            konfirmasi_pembayaran();
                            break;
                            break;
                        case 4:
                        system("CLS");                                                                                 
                            cout << " +-----------------------+ \n";
                            cout << " |-----   Link Aja  -----| \n";
                            cout << " +-----------------------+ \n";
                            cout << " Masukan Nomor Rekening Amil Zakat : ";
                            cin >> no_rek_amilzakat;
                            if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                                    if(pil_ewallet == 4){
                                        if(no_rek_amilzakat == rekening.no1 || no_rek_amilzakat == rekening.no2 || no_rek_amilzakat == rekening.no3 || no_rek_amilzakat == rekening.no4){
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                        
                                    }
                                }
                                }else{
                                    cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                    Sleep(1000);
                                    goto carimasjid; 
                                }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                                    if(pil_ewallet == 4){
                                        if(no_rek_amilzakat == rekening.no1 || no_rek_amilzakat == rekening.no2 || no_rek_amilzakat == rekening.no3 || no_rek_amilzakat == rekening.no4){
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                        
                                    }
                                }
                                }else{
                                    cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                    Sleep(1000);
                                    goto carimasjid; 
                                }
                                    }
                                }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                                    if(pil_ewallet == 4){
                                        if(no_rek_amilzakat == rekening.no1 || no_rek_amilzakat == rekening.no2 || no_rek_amilzakat == rekening.no3 || no_rek_amilzakat == rekening.no4){
                                        if(orangtanggungan == 0 ){                              
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(*data_muzakki.nama_muzakki, nominal_zakat, data_muzakki.alamat_muzakki);                               
                                        }else{                                                  
                                        for(int i = 0; i < orangtanggungan +1; i++){
                                        cout << " Masukan Nominal (dalam Rupiah) : ";
                                        cin >> nominal_zakat;
                                        input(data_tanggungan.nama_tanggungan[i] ,nominal_zakat, data_muzakki.alamat_muzakki);                        
                                    }
                                }
                                }else{
                                    cout << "Nomer rekening yang anda masukkan salah!" << endl;
                                    Sleep(1000);
                                    goto carimasjid; 
                                }
                                    }
                                }                          
                            konfirmasi_pembayaran();
                            break;
                        default:
                            break;
                        }
                            break;
                            default:
                            break;
                        }
                    system("CLS");
                    cout << " Ingin cetak bukti pembayaran (y/n) ? ";                                       
                    cin >> cetak;
                        if(cetak == 'y'){                                                               
                            berkas.open("buktizakat.txt", ios::app);
                            if(pil_bank == 1 || pil_ewallet == 1){                                     
                            berkas << " +-----------------------------------------------------+ \n";
                            berkas << " |   --------------- BCA MOBILE ------------------     | \n";
                            berkas << " +-----------------------------------------------------+ \n";
                            }else if(pil_bank == 2 || pil_ewallet == 2){
                            berkas << " +-----------------------------------------------------+ \n";
                            berkas << " |   --------------- BRI Syariah ------------------    | \n";
                            berkas << " +-----------------------------------------------------+ \n";
                            }else if(pil_bank == 3 || pil_ewallet == 3){
                            berkas << " +-----------------------------------------------------+ \n";
                            berkas << " |     -------------- BNI Syariah --------------       | \n";
                            berkas << " +-----------------------------------------------------+ \n";
                            }else if(pil_bank == 4 || pil_ewallet == 4){
                            berkas << " +-----------------------------------------------------+ \n";
                            berkas << " |   -------------- Mandiri Syariah --------------     | \n";
                            berkas << " +-----------------------------------------------------+ \n";
                            }
                            berkas << " +-----------------------------------------------------+ \n";
                            berkas << " | ------------- Bukti Pembayaran Zakat -------------- | \n";
                            berkas << " +-----------------------------------------------------+ \n";
                            berkas << " | Nama             : " << *data_muzakki.nama_muzakki << endl;
                            if(orangtanggungan != 0){
                                for(int x = 1; x <= orangtanggungan; x++){
                                    berkas << " | Nama             : " << data_tanggungan.nama_tanggungan[x] << endl;
                                }
                            }
                            berkas << " | Alamat           : " << data_muzakki.alamat_muzakki << endl;
                            berkas << " | Nominal          : ";
                            berkas << jumlahnominalzakat(head);
                            berkas << endl;
                            if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                            berkas << " | Amil Zakat       : " << data_masjid1.nama_masjid1 << endl;
                            }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                            berkas << " | Amil Zakat       : " << data_masjid2.nama_masjid2 << endl;
                            }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                            berkas << " | Amil Zakat       : " << data_masjid3.nama_masjid3 << endl;
                            }
                            berkas << " | Waktu Pembayaran : " << ctime(&timenow); 
                            berkas << " +-----------------------------------------------------+ \n";
                            berkas << "\n";
                            berkas.close();
                        }else{
                            break;
                        }
                    break;
                break;   
                case 2:
                system("CLS");
                    cout << " Mencari Lokasi Masjid Terdekat.... " << endl;
                    Sleep(3000);
                    cout << " Lokasi Masjid Ditemukan!" << endl;
                    Sleep(1500);
                    if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                    cout << " ======================================================== \n";
                    cout << " 1. Nama Masjid  : " << data_masjid1.nama_masjid1 << endl;
                    cout << "    Jarak Masjid : " << (rand() % 10) + 100 << " meter" << endl;
                    cout << " ======================================================== \n";
                    cout << " 2. Nama Masjid  : " << data_masjid1_1.nama_masjid1_1 << endl;
                    cout << "    Jarak Masjid : " << (rand() % 10) + 175 << " meter" << endl;
                    cout << " ======================================================== \n";
                    }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                    cout << " ======================================================== \n";
                    cout << " 1. Nama Masjid  : " << data_masjid2.nama_masjid2 << endl;
                    cout << "    Jarak Masjid : " << (rand() % 10) + 100 << " meter" << endl;
                    cout << " ======================================================== \n";
                    cout << " 2. Nama Masjid  : " << data_masjid2_1.nama_masjid2_1 << endl;
                    cout << "    Jarak Masjid : " << (rand() % 10) + 175 << " meter" << endl;
                    cout << " ======================================================== \n";
                    }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                    cout << " ======================================================== \n";
                    cout << " 1. Nama Masjid  : " << data_masjid3.nama_masjid3 << endl;
                    cout << "    Jarak Masjid : " << (rand() % 10) + 100 << " meter" << endl;
                    cout << " ======================================================== \n";
                    cout << " 2. Nama Masjid  : " << data_masjid3_1.nama_masjid3_1 << endl;
                    cout << "    Jarak Masjid : " << (rand() % 10) + 175 << " meter" << endl;
                    cout << " ======================================================== \n";
                    }
                    cout << " Pilihan Masjid : "; cin >> pil_masjid;
                    if(data_muzakki.kode_pos == data_amilzakat.kode_pos){
                        if(pil_masjid == 1){
                        inQueue(*data_muzakki.nama_muzakki, data_muzakki.alamat_muzakki, data_muzakki.no_telp_muzakki);
                        cout << " Proses Pembayaran Zakat Fitrah Anda Telah Masuk Antrian! \n";
                        Sleep(2000);
                        cout << " ============================================== \n";
                        cout << " Nama              : " << *data_muzakki.nama_muzakki << endl;
                        cout << " Alamat            : " << data_muzakki.alamat_muzakki << endl;
                        cout << " Jumlah Tanggungan : " << orangtanggungan << " orang" << endl;
                        cout << " ============================================== \n";
                        cout << " Harap untuk mendatangi : \n"; 
                        cout << " Nama Masjid   : " << data_masjid1.nama_masjid1 << "\n";
                        cout << " Alamat Masjid : " << data_masjid1.alamat_masjid1 << "\n";
                        cout << " Waktu         : " << ctime(&timenow);
                        cout << " Untuk membayar zakat secara non-tunai." << endl;
                        cout << " Narahubung    : " << data_masjid1.no_telp1 << " A/N " << data_masjid1.narahubung1 << endl;
                        cout << " ============================================== \n";
                        }else if(pil_masjid == 2){
                        inQueue(*data_muzakki.nama_muzakki, data_muzakki.alamat_muzakki, data_muzakki.no_telp_muzakki);
                        cout << " Proses Pembayaran Zakat Fitrah Anda Telah Masuk Antrian! \n";
                        Sleep(2000);
                        cout << " ============================================== \n";
                        cout << " Nama              : " << *data_muzakki.nama_muzakki << endl;
                        cout << " Alamat            : " << data_muzakki.alamat_muzakki << endl;
                        cout << " Jumlah Tanggungan : " << orangtanggungan << " orang" << endl;
                        cout << " ============================================== \n";
                        cout << " Harap untuk mendatangi : \n"; 
                        cout << " Nama Masjid   : " << data_masjid1_1.nama_masjid1_1 << "\n";
                        cout << " Alamat Masjid : " << data_masjid1_1.alamat_masjid1_1 << "\n";
                        cout << " Waktu         : " << ctime(&timenow);
                        cout << " Untuk membayar zakat secara non-tunai." << endl;
                        cout << " Narahubung    : " << data_masjid1_1.no_telp1_1 << " A/N " << data_masjid1_1.narahubung1_1 << endl;
                        cout << " ============================================== \n";
                        }
                    }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                        if(pil_masjid == 1){
                        inQueue(*data_muzakki.nama_muzakki, data_muzakki.alamat_muzakki, data_muzakki.no_telp_muzakki);
                        cout << " Proses Pembayaran Zakat Fitrah Anda Telah Masuk Antrian! \n";
                        Sleep(2000);
                        cout << " ============================================== \n";
                        cout << " Nama              : " << *data_muzakki.nama_muzakki << endl;
                        cout << " Alamat            : " << data_muzakki.alamat_muzakki << endl;
                        cout << " Jumlah Tanggungan : " << orangtanggungan << " orang" << endl;
                        cout << " ============================================== \n";
                        cout << " Harap untuk mendatangi : \n"; 
                        cout << " Nama Masjid   : " << data_masjid2.nama_masjid2 << "\n";
                        cout << " Alamat Masjid : " << data_masjid2.alamat_masjid2 << "\n";
                        cout << " Waktu         : " << ctime(&timenow);
                        cout << " Untuk membayar zakat secara non-tunai." << endl;
                        cout << " Narahubung    : " << data_masjid2.no_telp2 << " A/N " << data_masjid2.narahubung2 << endl;
                        cout << " ============================================== \n";
                        }else if(pil_masjid == 2){
                        inQueue(*data_muzakki.nama_muzakki, data_muzakki.alamat_muzakki, data_muzakki.no_telp_muzakki);
                        cout << " Proses Pembayaran Zakat Fitrah Anda Telah Masuk Antrian! \n";
                        Sleep(2000);
                        cout << " ============================================== \n";
                        cout << " Nama              : " << *data_muzakki.nama_muzakki << endl;
                        cout << " Alamat            : " << data_muzakki.alamat_muzakki << endl;
                        cout << " Jumlah Tanggungan : " << orangtanggungan << " orang" << endl;
                        cout << " ============================================== \n";
                        cout << " Harap untuk mendatangi : \n"; 
                        cout << " Nama Masjid   : " << data_masjid2_1.nama_masjid2_1 << "\n";
                        cout << " Alamat Masjid : " << data_masjid2_1.alamat_masjid2_1 << "\n";
                        cout << " Waktu         : " << ctime(&timenow);
                        cout << " Untuk membayar zakat secara non-tunai." << endl;
                        cout << " Narahubung    : " << data_masjid2_1.no_telp2_1 << " A/N " << data_masjid2_1.narahubung2_1 << endl;
                        cout << " ============================================== \n";
                        }
                    }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                        if(pil_masjid == 1){
                        inQueue(*data_muzakki.nama_muzakki, data_muzakki.alamat_muzakki, data_muzakki.no_telp_muzakki);
                        cout << " Proses Pembayaran Zakat Fitrah Anda Telah Masuk Antrian! \n";
                        Sleep(2000);
                        cout << " ============================================== \n";
                        cout << " Nama              : " << *data_muzakki.nama_muzakki << endl;
                        cout << " Alamat            : " << data_muzakki.alamat_muzakki << endl;
                        cout << " Jumlah Tanggungan : " << orangtanggungan << " orang" << endl;
                        cout << " ============================================== \n";
                        cout << " Harap untuk mendatangi : \n"; 
                        cout << " Nama Masjid   : " << data_masjid3.nama_masjid3 << "\n";
                        cout << " Alamat Masjid : " << data_masjid3.alamat_masjid3 << "\n";
                        cout << " Waktu         : " << ctime(&timenow);
                        cout << " Untuk membayar zakat secara non-tunai." << endl;
                        cout << " Narahubung    : " << data_masjid3.no_telp3 << " A/N " << data_masjid3.narahubung3 << endl;
                        cout << " ============================================== \n";
                        }else if(pil_masjid == 2){
                        inQueue(*data_muzakki.nama_muzakki, data_muzakki.alamat_muzakki, data_muzakki.no_telp_muzakki);
                        cout << " Proses Pembayaran Zakat Fitrah Anda Telah Masuk Antrian! \n";
                        Sleep(2000);
                        cout << " ============================================== \n";
                        cout << " Nama              : " << *data_muzakki.nama_muzakki << endl;
                        cout << " Alamat            : " << data_muzakki.alamat_muzakki << endl;
                        cout << " Jumlah Tanggungan : " << orangtanggungan << " orang" << endl;
                        cout << " ============================================== \n";
                        cout << " Harap untuk mendatangi : \n"; 
                        cout << " Nama Masjid   : " << data_masjid3_1.nama_masjid3_1 << "\n";
                        cout << " Alamat Masjid : " << data_masjid3_1.alamat_masjid3_1 << "\n";
                        cout << " Waktu         : " << ctime(&timenow);
                        cout << " -----Untuk membayar zakat secara non-tunai-----" << endl;
                        cout << " Narahubung    : " << data_masjid3_1.no_telp3_1 << " A/N " << data_masjid3_1.narahubung3_1 << endl;
                        cout << " ============================================== \n";
                        }
                    }
                    system("CLS");
                    Sleep(1500);
                    cout << " Sistem Memproses Mencetak Bukti Antrian Zakat Fitrah.... " << endl;
                    if(data_muzakki.kode_pos == data_masjid1.kode_pos1){
                        if(pil_masjid == 1){
                    berkas.open("buktiantrian_aljihad.txt", ios::app);
                    berkas << " +-------------------------------------------------+ " << endl;
                    berkas << " |           BUKTI ANTRIAN ZAKAT FITRAH            | " << endl;
                    berkas << " +-------------------------------------------------+ " << endl; 
                    berkas << " | Nama              : " << *data_muzakki.nama_muzakki << endl;
                    berkas << " | Alamat            : " << data_muzakki.alamat_muzakki<< endl;
                    berkas << " | Jumlah Tanggungan : " << orangtanggungan << endl;
                    berkas << " ------------- Harap untuk mendatangi -------------- " << endl;
                    berkas << " | Nama Masjid       : " << data_masjid1.nama_masjid1 << endl;
                    berkas << " | Alamat Masjid     : " << data_masjid1.alamat_masjid1 << endl;
                    berkas << " | Waktu             : " << ctime(&timenow);
                    berkas << " | Narahubung        : " << data_masjid1.narahubung1 << " (" << data_masjid1.no_telp1 << ")" << endl;
                    berkas << " +-------------------------------------------------+ " << endl; 
                        }else if(pil_masjid == 2){
                    berkas.open("buktiantrian_alhidayah.txt", ios::app);
                    berkas << " +-------------------------------------------------+ " << endl;
                    berkas << " |           BUKTI ANTRIAN ZAKAT FITRAH            | " << endl;
                    berkas << " +-------------------------------------------------+ " << endl; 
                    berkas << " | Nama              : " << *data_muzakki.nama_muzakki << endl;
                    berkas << " | Alamat            : " << data_muzakki.alamat_muzakki<< endl;
                    berkas << " | Jumlah Tanggungan : " << orangtanggungan << endl;
                    berkas << " ------------- Harap untuk mendatangi -------------- " << endl;
                    berkas << " | Nama Masjid       : " << data_masjid1_1.nama_masjid1_1 << endl;
                    berkas << " | Alamat Masjid     : " << data_masjid1_1.alamat_masjid1_1 << endl;
                    berkas << " | Waktu             : " << ctime(&timenow);
                    berkas << " | Narahubung        : " << data_masjid1_1.narahubung1_1 << " (" << data_masjid1_1.no_telp1_1 << ")" << endl;
                    berkas << " +-------------------------------------------------+ " << endl;    
                        }
                    }else if(data_muzakki.kode_pos == data_masjid2.kode_pos2){
                        if(pil_masjid == 1){
                    berkas.open("buktiantrian_attosin.txt", ios::app);
                    berkas << " +-------------------------------------------------+ " << endl;
                    berkas << " |           BUKTI ANTRIAN ZAKAT FITRAH            | " << endl;
                    berkas << " +-------------------------------------------------+ " << endl; 
                    berkas << " | Nama              : " << *data_muzakki.nama_muzakki << endl;
                    berkas << " | Alamat            : " << data_muzakki.alamat_muzakki<< endl;
                    berkas << " | Jumlah Tanggungan : " << orangtanggungan << endl;
                    berkas << " ------------- Harap untuk mendatangi -------------- " << endl;
                    berkas << " | Nama Masjid       : " << data_masjid2.nama_masjid2 << endl;
                    berkas << " | Alamat Masjid     : " << data_masjid2.alamat_masjid2 << endl;
                    berkas << " | Waktu             : " << ctime(&timenow);
                    berkas << " | Narahubung        : " << data_masjid2.narahubung2 << " (" << data_masjid2.no_telp2 << ")" << endl;
                    berkas << " +-------------------------------------------------+ " << endl; 
                        }else if(pil_masjid == 2){
                    berkas.open("buktiantrian_alhikmah.txt", ios::app);
                    berkas << " +-------------------------------------------------+ " << endl;
                    berkas << " |           BUKTI ANTRIAN ZAKAT FITRAH            | " << endl;
                    berkas << " +-------------------------------------------------+ " << endl; 
                    berkas << " | Nama              : " << *data_muzakki.nama_muzakki << endl;
                    berkas << " | Alamat            : " << data_muzakki.alamat_muzakki<< endl;
                    berkas << " | Jumlah Tanggungan : " << orangtanggungan << endl;
                    berkas << " ------------- Harap untuk mendatangi -------------- " << endl;
                    berkas << " | Nama Masjid       : " << data_masjid2_1.nama_masjid2_1 << endl;
                    berkas << " | Alamat Masjid     : " << data_masjid2_1.alamat_masjid2_1 << endl;
                    berkas << " | Waktu             : " << ctime(&timenow);
                    berkas << " | Narahubung        : " << data_masjid2_1.narahubung2_1 << " (" << data_masjid2_1.no_telp2_1 << ")" << endl;
                    berkas << " +-------------------------------------------------+ " << endl; 
                        }
                    }else if(data_muzakki.kode_pos == data_masjid3.kode_pos3){
                        if(pil_masjid == 1){
                    berkas.open("buktiantrian_rayarancaekek.txt", ios::app);
                    berkas << " +-------------------------------------------------+ " << endl;
                    berkas << " |           BUKTI ANTRIAN ZAKAT FITRAH            | " << endl;
                    berkas << " +-------------------------------------------------+ " << endl; 
                    berkas << " | Nama              : " << *data_muzakki.nama_muzakki << endl;
                    berkas << " | Alamat            : " << data_muzakki.alamat_muzakki<< endl;
                    berkas << " | Jumlah Tanggungan : " << orangtanggungan << endl;
                    berkas << " ------------- Harap untuk mendatangi -------------- " << endl;
                    berkas << " | Nama Masjid       : " << data_masjid3.nama_masjid3 << endl;
                    berkas << " | Alamat Masjid     : " << data_masjid3.alamat_masjid3 << endl;
                    berkas << " | Waktu             : " << ctime(&timenow);
                    berkas << " | Narahubung        : " << data_masjid3.narahubung3 << " (" << data_masjid3.no_telp3 << ")" << endl;
                    berkas << " +-------------------------------------------------+ " << endl; 
                        }else if(pil_masjid == 2){
                    berkas.open("buktiantrian_nurulfalah.txt", ios::app);
                    berkas << " +-------------------------------------------------+ " << endl;
                    berkas << " |           BUKTI ANTRIAN ZAKAT FITRAH            | " << endl;
                    berkas << " +-------------------------------------------------+ " << endl; 
                    berkas << " | Nama              : " << *data_muzakki.nama_muzakki << endl;
                    berkas << " | Alamat            : " << data_muzakki.alamat_muzakki<< endl;
                    berkas << " | Jumlah Tanggungan : " << orangtanggungan << endl;
                    berkas << " ------------- Harap untuk mendatangi -------------- " << endl;
                    berkas << " | Nama Masjid       : " << data_masjid3_1.nama_masjid3_1 << endl;
                    berkas << " | Alamat Masjid     : " << data_masjid3_1.alamat_masjid3_1 << endl;
                    berkas << " | Waktu             : " << ctime(&timenow);
                    berkas << " | Narahubung        : " << data_masjid3_1.narahubung3_1 << " (" << data_masjid3_1.no_telp3_1 << ")" << endl;
                    berkas << " +-------------------------------------------------+ " << endl; 
                        }
                    }
                    Sleep(2000);
                    cout << " Bukti Antrian Sudah Diproses oleh Sistem! " << endl;
                    break;
                case 3:
                system("CLS");
                kalkulator_zakat();
                cout << " | Masukkan Penghasilan (pertahun) : "; cin >> penghasilan;                                    
                cout << " | Masukkan Harga emas saat ini    : "; cin >> harga_emas;                                     
                cout << " | Zakat yang harus dibayarkan     : " << zakatpenghasilan_penghasilan(penghasilan) << endl;   
                cout << " | Nishab zakat penghasilan        : " << zakatpenghasilan_nishab(harga_emas) << endl;         
                cout << " | ------------------------------- | \n";
                break;
                case 4:
                int pil_zakatpedia;
                system("CLS");
                menu_zakatpedia();
                cin >> pil_zakatpedia;
                switch(pil_zakatpedia){
                    case 1:
                    definisi_zakat();
                    break;
                    case 2:
                    hukum_zakat();
                    break;
                    case 3:
                    dalil_zakat();
                    break;
                    case 4:
                    syarat_zakat();
                    break;
                    case 5:
                    zakatfm();
                    break;
                    case 6:
                    pertanyaan_zakat();
                    break;
                    default:
                    break;
                }
                break;
                case 5:
                goto ulangprogram;
                break;
                default:
                    break;
                }
            ulangprogrammuzakki:
            cout << " Kembali ke menu (y/n) ? : ";
            cin >> ulang_menu_muzakki;
            if(ulang_menu_muzakki == 'y'){
                goto menuawal_muzakki;
            }else if(ulang_menu_muzakki == 'n'){
                goto ulangprogram;
            }
                break;
    case 2:
        system("CLS");                                                                                 
        menuawal_amilzakat:
        char ulang_menu_amilzakat;
        system("CLS");
        header();
        cout << " | Selamat Datang, " << data_amilzakat.nama_masjid << "!"<< "\n";
        cout << " | Alamat        : " << data_amilzakat.alamat_masjid << "\n";
        menu_amilzakat();                                                       
        cin >> pil_menu_amilzakat;
        switch (pil_menu_amilzakat)
        {
        case 1:
        int pil_data_transaksi;
        system("CLS");
        menu_transaksi();
        cin >> pil_data_transaksi;
            switch(pil_data_transaksi){
                case 1:
                if(orangtanggungan == 0){
                data_transaksi();
                cout << " ------------------------------------------------------------------------\n";
                cout << " Total zakat yang terkumpul = " << " Rp" << jumlahnominalzakat(head);
                cout << endl;
                }else if(orangtanggungan != 0){
                data_transaksi();
                cout << " ------------------------------------------------------------------------\n";
                cout << " Jumlah orang yang telah membayar zakat : " << getCount(head) << " orang." << endl;   
                cout << " ------------------------------------------------------------------------\n";
                cout << " Total zakat yang terkumpul = " << " Rp" << jumlahnominalzakat(head);
                cout << endl;
                cout << " ------------------------------------------------------------------------\n";
                }
                break;
                case 2:
                hapusBelakang();
                break;
                case 3:
                deleteList(&head);
                break;
                default:
                break;
            }                                                                             
        break;
        case 2:
        system("CLS");
        int proses_antrian;
        menu_antrian();
        cin >> proses_antrian;
            switch(proses_antrian){
                case 1:
                display();
                break;
                case 2:
                deQueue();
                break;
                case 3:
                cout << " ================================================= \n";
                cout << " Masukan nama yang dicari : "; cin >> cari_nama;
                cout << " ================================================= \n";
                find(cari_nama);
                break;
                default:
                break;
            }
        break;
        case 3:
        system("CLS");
        cout << " ========= Daerah Target Mustahik ========= " << endl;
        cout << " Nama Masjid : ";
        if(data_amilzakat.kode_pos == data_masjid1.kode_pos1){
            if(data_amilzakat.nama_masjid == data_masjid1.nama_masjid1){
                cout << data_masjid1.nama_masjid1;
            }else if(data_amilzakat.nama_masjid == data_masjid1_1.nama_masjid1_1){
                cout << data_masjid1_1.nama_masjid1_1;
            }
        }else if(data_amilzakat.kode_pos == data_masjid2.kode_pos2){
            if(data_amilzakat.nama_masjid == data_masjid2.nama_masjid2){
                cout << data_masjid2.nama_masjid2;
            }else if(data_amilzakat.nama_masjid == data_masjid2_1.nama_masjid2_1){
                cout << data_masjid2_1.nama_masjid2_1;
            }
        }else if(data_amilzakat.kode_pos == data_masjid3.kode_pos3){
            if(data_amilzakat.nama_masjid == data_masjid3.nama_masjid3){
                cout << data_masjid3.nama_masjid3;
            }else if(data_amilzakat.nama_masjid == data_masjid3_1.nama_masjid3_1){
                cout << data_masjid3_1.nama_masjid3_1;
            }
        }
        cout << endl;
        cout << " Lokasi : ";
        if(data_amilzakat.kode_pos == data_masjid1.kode_pos1){
            if(data_amilzakat.nama_masjid == data_masjid1.nama_masjid1){
                cout << data_masjid1.daerah_masjid;
            }else if(data_amilzakat.nama_masjid == data_masjid1_1.nama_masjid1_1){
                cout << data_masjid1_1.daerah_masjid1_1;
            }
        }else if(data_amilzakat.kode_pos == data_masjid2.kode_pos2){
            if(data_amilzakat.nama_masjid == data_masjid2.nama_masjid2){
                cout << data_masjid2.daerah_masjid2;
            }else if(data_amilzakat.nama_masjid == data_masjid2_1.nama_masjid2_1){
                cout << data_masjid2_1.daerah_masjid2_1;
            }
        }else if(data_amilzakat.kode_pos == data_masjid3.kode_pos3){
            if(data_amilzakat.nama_masjid == data_masjid3.nama_masjid3){
                cout << data_masjid3.daerah_masjid3;
            }else if(data_amilzakat.nama_masjid == data_masjid3_1.nama_masjid3_1){
                cout << data_masjid3_1.daerah_masjid3_1;
            }
        }
        cout << endl;
        cout << " Mencari Daerah Target Mustahik Terdekat...... " << endl;
        Sleep(3000);
        cout << " Daerah Target Mustahik Telah Ditemukan! " << endl;
        Sleep(1500);
        cout << endl;
        cout << " Profil Daerah Target Mustahik " << endl;
        Sleep(1000);
        if(data_amilzakat.kode_pos == data_masjid1.kode_pos1){
            if(data_amilzakat.nama_masjid == data_masjid1.nama_masjid1){
                cout << " ====================================================== \n";
                cout << " Nama Daerah            : " << rute_margaasih.daerah << endl;
                cout << " Kecamatan              : " << rute_margaasih.Kecamatan << endl;
                cout << " Kode Pos               : " << rute_margaasih.kode_pos << endl;
                cout << " Jumlah Kepala Keluarga : " << rute_margaasih.jml_kk << endl;
                cout << " ====================================================== \n";
                cout << endl;
                cout << " Menampilkan Rute Perjalanan Menuju Daerah Target Mustahik " << endl;
                graph->edge[0].u = rute_point.r2;
                graph->edge[0].v = rute_point.r1;
                graph->edge[0].w = rute_margaasih.point1_margaasih;

                graph->edge[1].u = rute_point.r1;
                graph->edge[1].v = rute_point.r3;
                graph->edge[1].w = rute_margaasih.point2_margaasih;

                graph->edge[2].u = rute_point.r1;
                graph->edge[2].v = rute_point.r4;
                graph->edge[2].w = rute_margaasih.point3_margaasih;

                graph->edge[3].u = rute_point.r3;
                graph->edge[3].v = rute_point.r4;
                graph->edge[3].w = rute_margaasih.point4_margaasih;

                graph->edge[4].u = rute_point.r2;
                graph->edge[4].v = rute_point.r4;
                graph->edge[4].w = rute_margaasih.point5_margaasih;
                kurskalMST(graph);
                
            }else if(data_amilzakat.nama_masjid == data_masjid1_1.nama_masjid1_1){
                cout << " ====================================================== \n";
                cout << " Nama Daerah            : " << rute_margaasih.daerah << endl;
                cout << " Kecamatan              : " << rute_margaasih.Kecamatan << endl;
                cout << " Kode Pos               : " << rute_margaasih.kode_pos << endl;
                cout << " Jumlah Kepala Keluarga : " << rute_margaasih.jml_kk << endl;
                cout << " ====================================================== \n";
                cout << endl;
                cout << " Menampilkan Rute Perjalanan Menuju Daerah Target Mustahik " << endl;
                graph->edge[0].u = rute_point.r2;
                graph->edge[0].v = rute_point.r1;
                graph->edge[0].w = rute_margaasih.point1_margaasih;

                graph->edge[1].u = rute_point.r1;
                graph->edge[1].v = rute_point.r3;
                graph->edge[1].w = rute_margaasih.point2_margaasih;

                graph->edge[2].u = rute_point.r1;
                graph->edge[2].v = rute_point.r4;
                graph->edge[2].w = rute_margaasih.point3_margaasih;

                graph->edge[3].u = rute_point.r3;
                graph->edge[3].v = rute_point.r4;
                graph->edge[3].w = rute_margaasih.point4_margaasih;

                graph->edge[4].u = rute_point.r2;
                graph->edge[4].v = rute_point.r4;
                graph->edge[4].w = rute_margaasih.point5_margaasih;
                kurskalMST(graph);
            }
        }else if(data_amilzakat.kode_pos == data_masjid2.kode_pos2){
            if(data_amilzakat.nama_masjid == data_masjid2.nama_masjid2){
                cout << " ====================================================== \n";
                cout << " Nama Daerah            : " << rute_cipadung.daerah << endl;
                cout << " Kecamatan              : " << rute_cipadung.kecamatan << endl;
                cout << " Kode Pos               : " << rute_cipadung.kode_pos << endl;
                cout << " Jumlah Kepala Keluarga : " << rute_cipadung.jml_kk << endl;
                cout << " ====================================================== \n";
                cout << endl;
                cout << " Menampilkan Rute Perjalanan Menuju Daerah Target Mustahik " << endl;
                graph->edge[0].u = rute_point.r2;
                graph->edge[0].v = rute_point.r1;
                graph->edge[0].w = rute_cipadung.point1_cipadung;

                graph->edge[1].u = rute_point.r1;
                graph->edge[1].v = rute_point.r3;
                graph->edge[1].w = rute_cipadung.point2_cipadung;

                graph->edge[2].u = rute_point.r1;
                graph->edge[2].v = rute_point.r4;
                graph->edge[2].w = rute_cipadung.point3_cipadung;

                graph->edge[3].u = rute_point.r3;
                graph->edge[3].v = rute_point.r4;
                graph->edge[3].w = rute_cipadung.point4_cipadung;

                graph->edge[4].u = rute_point.r2;
                graph->edge[4].v = rute_point.r4;
                graph->edge[4].w = rute_cipadung.point5_cipadung;
                kurskalMST(graph);
            }else if(data_amilzakat.nama_masjid == data_masjid2_1.nama_masjid2_1){
                cout << " ====================================================== \n";
                cout << " Nama Daerah            : " << rute_cipadung.daerah << endl;
                cout << " Kecamatan              : " << rute_cipadung.kecamatan << endl;
                cout << " Kode Pos               : " << rute_cipadung.kode_pos << endl;
                cout << " Jumlah Kepala Keluarga : " << rute_cipadung.jml_kk << endl;
                cout << " ====================================================== \n";
                cout << endl;
                cout << " Menampilkan Rute Perjalanan Menuju Daerah Target Mustahik " << endl;
                graph->edge[0].u = rute_point.r2;
                graph->edge[0].v = rute_point.r1;
                graph->edge[0].w = rute_cipadung.point1_cipadung;

                graph->edge[1].u = rute_point.r1;
                graph->edge[1].v = rute_point.r3;
                graph->edge[1].w = rute_cipadung.point2_cipadung;

                graph->edge[2].u = rute_point.r1;
                graph->edge[2].v = rute_point.r4;
                graph->edge[2].w = rute_cipadung.point3_cipadung;

                graph->edge[3].u = rute_point.r3;
                graph->edge[3].v = rute_point.r4;
                graph->edge[3].w = rute_cipadung.point4_cipadung;

                graph->edge[4].u = rute_point.r2;
                graph->edge[4].v = rute_point.r4;
                graph->edge[4].w = rute_cipadung.point5_cipadung;
                kurskalMST(graph);
            }
        }else if(data_amilzakat.kode_pos == data_masjid3.kode_pos3){
            if(data_amilzakat.nama_masjid == data_masjid3.nama_masjid3){
                cout << " ====================================================== \n";
                cout << " Nama Daerah            : " << rute_cangkuang.daerah << endl;
                cout << " Kecamatan              : " << rute_cangkuang.kecamatan << endl;
                cout << " Kode Pos               : " << rute_cangkuang.kode_pos << endl;
                cout << " Jumlah Kepala Keluarga : " << rute_cangkuang.jml_kk << endl;
                cout << " ====================================================== \n";
                cout << endl;
                cout << " Menampilkan Rute Perjalanan Menuju Daerah Target Mustahik " << endl;
                graph->edge[0].u = rute_point.r2;
                graph->edge[0].v = rute_point.r1;
                graph->edge[0].w = rute_cangkuang.point1_cangkuang;

                graph->edge[1].u = rute_point.r1;
                graph->edge[1].v = rute_point.r3;
                graph->edge[1].w = rute_cangkuang.point2_cangkuang;

                graph->edge[2].u = rute_point.r1;
                graph->edge[2].v = rute_point.r4;
                graph->edge[2].w = rute_cangkuang.point3_cangkuang;

                graph->edge[3].u = rute_point.r3;
                graph->edge[3].v = rute_point.r4;
                graph->edge[3].w = rute_cangkuang.point4_cangkuang;

                graph->edge[4].u = rute_point.r2;
                graph->edge[4].v = rute_point.r4;
                graph->edge[4].w = rute_cangkuang.point5_cangkuang;
                kurskalMST(graph);
            }else if(data_amilzakat.nama_masjid == data_masjid3_1.nama_masjid3_1){
                cout << " ====================================================== \n";
                cout << " Nama Daerah            : " << rute_cangkuang.daerah << endl;
                cout << " Kecamatan              : " << rute_cangkuang.kecamatan << endl;
                cout << " Kode Pos               : " << rute_cangkuang.kode_pos << endl;
                cout << " Jumlah Kepala Keluarga : " << rute_cangkuang.jml_kk << endl;
                cout << " ====================================================== \n";
                cout << endl;
                cout << " Menampilkan Rute Perjalanan Menuju Daerah Target Mustahik " << endl;
                graph->edge[0].u = rute_point.r2;
                graph->edge[0].v = rute_point.r1;
                graph->edge[0].w = rute_cangkuang.point1_cangkuang;

                graph->edge[1].u = rute_point.r1;
                graph->edge[1].v = rute_point.r3;
                graph->edge[1].w = rute_cangkuang.point2_cangkuang;

                graph->edge[2].u = rute_point.r1;
                graph->edge[2].v = rute_point.r4;
                graph->edge[2].w = rute_cangkuang.point3_cangkuang;

                graph->edge[3].u = rute_point.r3;
                graph->edge[3].v = rute_point.r4;
                graph->edge[3].w = rute_cangkuang.point4_cangkuang;

                graph->edge[4].u = rute_point.r2;
                graph->edge[4].v = rute_point.r4;
                graph->edge[4].w = rute_cangkuang.point5_cangkuang;
                kurskalMST(graph);
            }
        }
        break;
        case 4:
        system("CLS");
        struktur();
        displaystruktur(pohon);
        break;
        case 5:
        goto ulangprogram;
        break;
        default:
            break;
        }
        ulangprogrammamilzakat:
            cout << " Kembali ke menu (y/n) ? : ";
            cin >> ulang_menu_amilzakat;
            if(ulang_menu_amilzakat == 'y'){
                goto menuawal_amilzakat;
            }else if(ulang_menu_amilzakat == 'n'){
                goto ulangprogram;
            }
        break;
    default:
        break;
}
    ulangprogram:
    cout << " Ingin Keluar aplikasi (y/n) ? : ";                                            
    cin >> menu;
    if(menu == 'y'){                                                                        
        goto menuakhir;
    }else if(menu == 'n'){                                                                  
        cout << " Apakah anda ingin berganti peran (y/n) ? : ";                             
        cin >> menu;
            if(menu == 'y'){                                                                
                goto tampilanawal_aplikasi;
            }else if(menu == 'n'){                                                          
                goto ulangprogram;
            }
    }
    menuakhir:
    closing();
    return 0;

}



    