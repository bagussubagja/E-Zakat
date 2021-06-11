#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct node // Data yang digunakan untuk pembayaran zakat maal
{
    int uang_zakat; 
    string nama;
    string alamat;
    node *next; // pointer penunjuk alamat node selanjutnya
};
node *head;

void mulai()
{
    head = NULL;
}
bool cekKosong()
    {
    if (head==NULL)
        return true;
    return false;
    }

void deleteList(node** head_ref) // Fungsi untuk menghapus seluruh data transaksi
{
 
    node* current = *head_ref;
    node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
 
    *head_ref = NULL;
    cout << " Data Sudah Dihapuskan! " << endl;
}

void input(string name ,int dana_zakat, string address) // Fungsi untuk menambahkan data transaksi yang telah dilakukan oleh user
{
    node *new_node, *tmp;
    new_node = new node;
    new_node->nama = name;
    new_node->uang_zakat = dana_zakat;
    new_node->alamat = address;
    new_node->next = NULL;
    if (cekKosong())
    {
        head = new_node;
        head->next = NULL;
    }else{
        tmp = head;
        while (tmp->next!=NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}

void data_transaksi(){ // Fungsi untuk menampilkan data transaksi
if(!cekKosong()){ 
    node *tmp;
    tmp = head;
    cout << " ------------------------------------------------------------------------\n";
    cout << " Nama " << "\t" << "\t" << " Nominal " << "\t" << "\t" << " Alamat " << endl;
    while(tmp!=NULL){
        cout << " " << tmp->nama << "\t" << "\t" << "Rp" << tmp->uang_zakat << "\t" << "\t" << tmp->alamat;
        tmp = tmp->next;
        cout << endl;
    }
  }
}

void pop_front() { 
    cout << " ------------------------------------------------------------------------\n";
    cout << " Nama " << "\t" << "\t" << " Nominal " << "\t" << "\t" << " Alamat " << endl;
    cout << " " << head->nama << "\t" << "\t" << "Rp" << head->uang_zakat << "\t" << "\t" << head->alamat << endl;   
    cout << " Telah diproses oleh sistem!" << endl;
    if(head != NULL) {
    node* temp = head;
    head = head->next; 
    free(temp); 
    }
}

void pertambahan_node(struct node* head, int* sum) 
{
    // Jika Head = NULL
    if (!head)
        return;
  
    // Pertambahan Node secara rekursif
    pertambahan_node(head->next, sum);
  
    // Akumulasikan Jumlah Node
    *sum = *sum + head->uang_zakat;
}

int jumlahnominalzakat(struct node* head) // Fungsi untuk mengetahui jumlah nominal zakat yang telah masuk
{
    int sum = 0;
    pertambahan_node(head, &sum);
    return sum;
}

int getCount(node* head) // Fungsi untuk mengetahui berapa orang yang telah melakukan transaksi
{
	int count = 0; 
	node* current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

void hapusBelakang(){ // Fungsi untuk memproses data transaksi dengan menggunakan prinsip stack FILO
    node *hapus, *bantu;
    int tmp_uangzakat;
    string tmp_nama;
    string tmp_alamat;
    if(!cekKosong()){
        if(head->next!=NULL){
            bantu = head;
            while(bantu->next->next!=NULL){
                bantu = bantu -> next;
            }
            hapus = bantu -> next;
            tmp_uangzakat = hapus ->uang_zakat;
            tmp_nama = hapus ->nama;
            tmp_alamat = hapus->alamat;
            bantu->next=NULL;
            delete hapus;
        }
        else{
            tmp_uangzakat=head->uang_zakat;
            tmp_nama = head->nama;
            tmp_alamat = head->alamat;
            head = NULL;
        }
        cout << " ------------------------------------------------------------------------\n";
        cout << " Nama " << "\t" << "\t" << " Nominal " << "\t" << "\t" << " Alamat " << endl;
        cout << " " << tmp_nama << "\t" << "\t" << "Rp" << tmp_uangzakat << "\t" << "\t" << tmp_alamat << endl;   
        cout << " Telah diproses oleh sistem!" << endl;
    }
    else
    {
        cout << "Masih Kosong" << endl;
    }
}