#include <iostream>
#include <string>

using namespace std;

struct tree{
    int data;
    string jabatan;
    string nama;
    tree *left, *right;
};

tree *pohon, *root;

void definisi_awal(){
    pohon = NULL;
}

void insertjabatan(tree** root, int nilai, string position, string name){
    int i = 0;
    tree *new_node;

    // Jika datanya kosong belum ada pohon
    if((*root) == NULL){
        new_node = new tree;
        new_node -> data = nilai;
        new_node -> jabatan = position;
        new_node -> nama = name;
        new_node -> left = new_node -> right = NULL;

        (*root) = new_node;
        (*root) -> data = nilai;
        (*root) -> jabatan = position;
        (*root) -> nama = name;
        (*root) -> left = (*root) -> right = NULL;
        //cout << "Data " << new_node -> data << " sudah ditambahkan" << endl;
    }
    if((nilai < (*root)-> data)){
        insertjabatan(&(*root) -> left, nilai, position, name);
        //cout << "Data " << nilai << " sudah ditambahkan dikiri" << endl;
    }
    if((nilai > (*root)-> data)){
        insertjabatan(&(*root) -> right, nilai, position, name);
        //cout << "Data " << nilai << " sudah ditambahkan dikanan" << endl;
    }
}

void preOrder(tree *root){
    //cout << "---------------------" << endl;
    if(root != NULL){
        cout << root->nama << " (" << root->jabatan << ") " << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void displaystruktur(tree *root, int tingkat = 1){
    if(root != NULL){
        if(tingkat == 1){
        cout << "\t\t\t\t   ";
        cout << root->nama << " (" << root->jabatan << ") ";
        cout << "\n";
        for(int i = 0; i < 4 + tingkat; i++){
            cout << "     ";
            if(i == 2){
                cout << "\t\t ---------------------------------------- \n";
                cout << "\t\t\t |                                      | \n";
                cout << "\t\t\t v                                      v \n";
            }
        }
        cout << "\t";
    }
    else{
        cout << root->nama << " (" << root->jabatan << ") ";
        if (tingkat % 2 == 0){
            for(int i = 0; i < 4 + tingkat; i++){
                cout << " ";
            }
        } else{
            cout << "\n\t\t";
        }
    }
        tingkat++;
        displaystruktur(root->left, tingkat);
        displaystruktur(root->right, tingkat);
    }
}

void inOrder(tree *root){
    if(root != NULL){
        inOrder(root->left);
        cout << root->nama << " ";
        inOrder(root->right);
    }
}

void postOrder(tree *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->nama << " ";
    }
}

void struktur(){
    insertjabatan(&pohon, 1, "Ketua", "Bagus Subagja");
    insertjabatan(&pohon, 2, "Sekretaris", "Arfi Triawan");
    insertjabatan(&pohon, 3, "Bendahara", "\tBalqis Aqilah");
    insertjabatan(&pohon, 4, "PJ Administrasi", "Faja Sumitra");
    insertjabatan(&pohon, 5, "PJ Transaksi", "Fikri Arif");

    cout << "\t\t\t\t   Struktur Kepengurusan" << endl;
}