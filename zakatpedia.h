#include <iostream>
#include <string>

using namespace std;

void menu_zakatpedia(){
cout << " +-----------------------------------------------------+ " << endl;
cout << " |                 E-Zakat ZakatPedia                  | " << endl;
cout << " +-----------------------------------------------------+ " << endl;
cout << " | 1. Definisi Zakat                                   | " << endl;
cout << " | 2. Hukum Menunaikan Zakat                           | " << endl;
cout << " | 3. Dalil-dalil Mengenai Zakat                       | " << endl;
cout << " | 4. Syarat Bayar Zakat                               | " << endl;
cout << " | 5. Zakat Fitrah dan Zakat Maal                      | " << endl;
cout << " | 6. Pertanyaan Seputar Zakat                         | " << endl;
cout << " +-----------------------------------------------------+ " << endl;
cout << " | Pilihan : ";
}

void definisi_zakat(){
cout << " +-----------------------------------------------------+ " << endl;
cout << " |                 E-Zakat ZakatPedia                  | " << endl;
cout << " +-----------------------------------------------------+ " << endl;
cout << " |                   Definisi Zakat                    | " << endl;
cout << " |                       ------                        | " << endl;
cout << " | Kata zakat, secara bahasa, memiliki beberapa arti,  | " << endl; 
cout << " | di antaranya: tumbuh, bertambah, berkembang, atau   | " << endl;
cout << " | sesuatu yang terbaik (pilihan).                     | " << endl;
cout << " | Sedangkan pengertian zakat menurut istilah adalah   | " << endl;
cout << " | ukuran harta tertentu yang wajib dikeluarkan kepada | " << endl;
cout << " | orang yang membutuhkan atau yang berhak menerima    | " << endl;
cout << " | dengan beberapa syarat sesuai dengan syariat islam. | " << endl;
cout << " | Sumber : Yufidia.com                                : " << endl;
cout << " +-----------------------------------------------------+ " << endl;
}

void hukum_zakat(){
cout << " +-----------------------------------------------------+ " << endl;
cout << " |                 E-Zakat ZakatPedia                  | " << endl;
cout << " +-----------------------------------------------------+ " << endl;
cout << " |                    Hukum Zakat                      | " << endl;
cout << " |                       -----                         | " << endl;
cout << " | Zakat merupakan bagian dari rukun Islam yang lima,  | " << endl;
cout << " | merupakan kewajiban yang sudah ditetapkan bagi yang | " << endl;
cout << " | sudah terpenuhi syarat-syaratnya.                   | " << endl;
cout << " | Allah Ta'ala berfirman,                             | " << endl;
cout << " | “Dan dirikanlah shalat, tunaikanlah zakat dan       | " << endl;
cout << " | ruku’lah beserta orang-orang yang ruku’.”           | " << endl;
cout << " | (QS. Al-Baqarah: 43)                                | " << endl;
cout << " | Sumber : Rumaysho.com                               | " << endl;
cout << " +-----------------------------------------------------+ " << endl;
}

void dalil_zakat(){
cout << " +-----------------------------------------------------+ " << endl;
cout << " |                 E-Zakat ZakatPedia                  | " << endl;
cout << " +-----------------------------------------------------+ " << endl;
cout << " |             Dalil-dalil Mengenai Zakat              | " << endl;
cout << " |                       ------                        | " << endl;
cout << " | 1. QS. At-Taubah : 103                              | " << endl;
cout << " | “Ambillah zakat dari sebagian harta mereka, dengan  | " << endl;
cout << " | zakat itu kamu membersihkan dan mensucikan mereka   | " << endl;
cout << " | dan mendoalah untuk mereka. Sesungguhnya doa kamu   | " << endl;
cout << " | itu (menjadi) ketenteraman jiwa bagi mereka. Dan    | " << endl; 
cout << " | Allah Maha Mendengar lagi Maha Mengetahui.”         | " << endl;
cout << " | 2. (HR. Bukhari, no. 1395 dan Muslim, no. 19)       | " << endl;
cout << " | ... beritahukanlah pada mereka bahwa Allah telah    | " << endl; 
cout << " | mewajibkan kepada mereka zakat yang wajib dari harta| " << endl; 
cout << " | mereka diambil dari orang kaya di antara mereka dan | " << endl; 
cout << " | disalurkan pada orang miskin di tengah-tengah       | " << endl;
cout << " | mereka.”                                            | " << endl;
cout << " | Sumber : Rumaysho.com                               | " << endl;
cout << " +-----------------------------------------------------+ " << endl; 
}

void syarat_zakat(){
cout << " +-----------------------------------------------------+ " << endl;
cout << " |                 E-Zakat ZakatPedia                  | " << endl;
cout << " +-----------------------------------------------------+ " << endl;
cout << " |                 Syarat Bayar Zakat                  | " << endl;
cout << " |                      -------                        | " << endl;
cout << " | Yang wajib mengeluarkan zakat adalah yang Islam dan | " << endl;
cout << " | merdeka, tidak dipersyaratkan harus baligh dan      | " << endl;
cout << " | berakal. Karena orang gila dan anak kecil jika      | " << endl;
cout << " | memang memiliki harta yang sudah memenuhi syarat    | " << endl;
cout << " | juga tetap dikeluarkan zakatnya.                    | " << endl;
cout << " | Berkaitan dengan harta yang dikeluarkan, syarat yang| " << endl;
cout << " | harus dipenuhi adalah :                             | " << endl; 
cout << " | (1) harta tersebut dimiliki secara sempurna,        | " << endl; 
cout << " | (2) harta tersebut adalah harta yang berkembang,    | " << endl; 
cout << " | (3) harta tersebut telah mencapai nishab,           | " << endl;
cout << " | (4) harta tersebut bertahan selama setahun,         | " << endl;
cout << " | (5) harta tersebut kelebihan dari kebutuhan pokok.  | " << endl;
cout << " | Sumber : Rumaysho.com                               | " << endl;
cout << " +-----------------------------------------------------+ " << endl;
}

void zakatfm(){
char zakatfm;
string url = "https://rumaysho.com/15929-panduan-singkat-zakat-maal-dan-zakat-fitrah.html";
cout << " +------------------------------------------------------------------+ " << endl;
cout << " |                       E-Zakat ZakatPedia                         | " << endl;
cout << " +------------------------------------------------------------------+ " << endl;
cout << " |                   Zakat Fitrah dan Zakat Maal                    | " << endl;
cout << " |                            -------                               | " << endl;
cout << " | Zakat fitrah adalah zakat yang harus ditunaikan bagi seorang     | " << endl;
cout << " | muzakki yang telah memiliki kemampuan untuk menunaikannya.       | " << endl;
cout << " | Zakat fitrah adalah zakat wajib yang harus dikeluarkan sekali    | " << endl;
cout << " | setahun yaitu saat bulan ramadhan menjelang idul fitri.          | " << endl;
cout << " | Zakat maal berarti zakat yang dikenakan atas segala jenis        | " << endl;
cout << " | harta, yang secara zat maupun substansi perolehannya tidak       | " << endl;
cout << " | bertentangan dengan ketentuan agama.                             | " << endl;
cout << " | Tekan y untuk pembahasan lengkap : "; cin >> zakatfm;
if(zakatfm == 'y'){
system(std::string("start " + url).c_str());
cout << endl;
}else{
    cout << endl;
}
}

void pertanyaan_zakat(){
string url_question = "https://islamqa.info/id/categories/topics/103/zakat-fitrah";
cout << " +------------------------------------------------------------------+ " << endl;
cout << " |                       E-Zakat ZakatPedia                         | " << endl;
cout << " +------------------------------------------------------------------+ " << endl;
cout << " |                     Pertanyaan Seputar Zakat                     | " << endl;
cout << " |                          ------------                            | " << endl;
cout << " |   Anda akan segera dipindahkan menuju laman kumpulan pertanyaan  | " << endl;
for(int i = 3; i > 0 ; i-- ){
        Sleep(1500);
        cout << " | "  <<i << endl;
    }
system(std::string("start " + url_question).c_str());
}