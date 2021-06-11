#include <iostream>
#include <string>

using namespace std;

const int size = 100;
struct data_antrian{        // Data yang akan dimasukan kedalam antrian
    int top;
    string nama[size];
    string alamat[size];
    string no_telp[size];
}antrian;

void create_queue(){
    antrian.top = 0;        // Kondisi dimana antrian kosong
}

int isEmpty(){              // Cek apakah kosong
    if(antrian.top <= 0){   
        return 1;           
    }else{                  
        return 0;           
    }
}

int isFully(){              // Cek Apakah Penuh
    if(antrian.top >= size){
        return 1;           
    }else{
        return 0;     
    }
}

void inQueue(string nama, string alamat, string no_telp){       // Fungsi yang akan memasukkan data ke dalam antrtian
    if(isFully() == 1){
        cout << " Data Antrian Zakat Fitrah Sudah Penuh! " << endl;
    }else{
        antrian.nama[antrian.top] = nama;
        antrian.alamat[antrian.top] = alamat;
        antrian.no_telp[antrian.top] = no_telp;
        cout << " Antrian Zakat Fitrah Kamu Telah Berhasil Disimpan! " << endl;
        antrian.top++;
    }
}

void display(){                                                 // Fungsi yang akan menampilkan data antrian zakat fitrah
    int i = 0;
    system("CLS");
    cout << " =================================================== " << endl;
    cout << "               Data Antrian Zakat Fitrah             "  << endl;
    cout << " =================================================== " << endl;
    cout << " Nama " << "\t\t" << " Alamat " << "\t\t" << " No Telpon " << endl;
    while(i < antrian.top){
        cout << " " << antrian.nama[i] << "\t\t" << " " << antrian.alamat[i] << "\t\t" << " " << antrian.no_telp[i];
        cout << endl;
        i++;
    }
}

void deQueue(){                                                 // Fungsi yang akan memproses data antrian
    if(isEmpty() == 1){
        cout << " Antrian Sudah Penuh " << endl;
    }else{
        string done_nama = antrian.nama[0];
        string done_alamat = antrian.alamat[0];
        string done_no_telp = antrian.no_telp[0];
        int i = 1;
        cout << " Proses Pembayaran dengan data : " << endl;
        cout << " Nama          : " << done_nama << endl;
        cout << " Alamat        : " << done_alamat << endl;
        cout << " Nomor Telepon : " << done_no_telp << endl;
        cout << " Telah diproses!" << endl;
        
        while(i < antrian.top){
            antrian.nama[i-1] = antrian.nama[i];
            antrian.alamat[i-1] = antrian.alamat[i];
            antrian.no_telp[i-1] = antrian.no_telp[i];
            i++;
        }
        antrian.top--; 
    }
}

void find(string cari){                         // Fungsi mencari data antrian berdasarkan nama
    string temp;
    int itemp;
    if(isEmpty() == 1){
        cout << " Data Antrian Zakat Masih Kosong" << endl;
    }else{
        for(int i = 0; i <= antrian.top; i++){
            if(cari == antrian.nama[i]){
                temp = cari;
                itemp = i;
            }
        }
        if(cari == temp){
            cout << " Data dengan nama : " << cari << endl;
            cout << " Ditemukan pada posisi ke-" << itemp+1 << endl;
        }else{
           cout << " Data dengan nama : " << cari << endl;
           cout << " Tidak ditemukan!" << endl; 
        }
    }
}
