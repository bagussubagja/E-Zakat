#include <iostream>
#include <string>

using namespace std;

struct muzakki // Data Muzakki
{
    string* nama_muzakki = new string[100];
    string alamat_muzakki;
    int kode_pos;
    string no_telp_muzakki;
}data_muzakki;

struct tanggungan // Data orang tanggungan yang dimiliki oleh muzakki
{
    string nama_tanggungan[100];
    string alamat_tanggungan[100];
}data_tanggungan;

