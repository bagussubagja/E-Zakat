#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct amilzakat // Data Amil Zakat
{
    string nama_masjid;
    string alamat_masjid;
    int kode_pos;
}data_amilzakat;

struct cangkuang{   // Data Daerah Target Mustahik apabila user memasukan kode pos 40394
    string daerah = "Cangkuang";
    string kecamatan = "Rancaekek";
    int kode_pos = 40394;
    int jml_kk = 43;
    string rute1 = "Dangdeur";
    string rute2 = "Cipanas";
    string rute3 = "Rancadarah";
    int point1_cangkuang = 40;
    int point2_cangkuang = 24;
    int point3_cangkuang = 20;
    int point4_cangkuang = 16;
    int point5_cangkuang = 60;
}rute_cangkuang;

struct margaasih{ // Data Daerah Target Mustahik apabila user memasukan kode pos 40392
    string daerah = "Margaasih";
    string Kecamatan = "Cicalengka";
    int kode_pos = 40392;
    int jml_kk = 54;
    string rute1 = "Cikopo";
    string rute2 = "Babakan Asih";
    string rute3 = "Warung Lahang";
    int point1_margaasih = 50;
    int point2_margaasih = 30;
    int point3_margaasih = 25;
    int point4_margaasih = 20;
    int point5_margaasih = 75;
}rute_margaasih;

struct cipadung{ // Data Daerah Target Mustahik apabila user memasukan kode pos 40614
    string daerah = "Cipadung";
    string kecamatan = "Cibiru";
    int kode_pos = 40614;
    int jml_kk = 39;
    string rute1 = "Sindangrasa";
    string rute2 = "Cibiru Hilir";
    string rute3 = "Jl. A.H Nasution";
    int point1_cipadung = 60;
    int point2_cipadung = 36;
    int point3_cipadung = 30;
    int point4_cipadung = 24;
    int point5_cipadung = 90;
}rute_cipadung;

struct rute_point{ // Rute poin atau vertex yang digunakan pada implementasi graf
    int r1 = 1;
    int r2 = 2;
    int r3 = 3;
    int r4 = 4;
}rute_point;


/* IMPLEMENTASI GRAF  */
struct Edge
{
    int u, v, w;
};

struct Graph
{
    int V, E;

    Edge *edge;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];

    return graph;
};

struct Subset
{
    int parent, rank;
};

int myComp(const void *a, const void *b)
{
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;
    return a1->w > b1->w;
}

int find(Subset subsets[], int i)
{
    // # Setiap node dijadikan root
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }

    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[y].rank)
    {
        subsets[xroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[yroot].rank++;
    }
}

void kurskalMST(Graph *graph)
{
    int V = graph->V;
    Edge hasil[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    //Subset *subsets = new Subset;
    struct Subset *subsets = (struct Subset*) malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1)
    {
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);
        // Membandingkan 2 buah nilai x dan y
        if (x != y)
        {
            hasil[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout << " Mencari Jarak Tempuh Tercepat...\n";
    Sleep(1500);
    int total = 0;
    for (i = 0; i < e; i++)
    {
        total = total + hasil[i].w;
    }
    cout << " - Pertama, ";
    if(data_amilzakat.kode_pos == 40392){
        cout << "menuju daerah " << rute_margaasih.rute1 << " sejauh " << hasil[0].w << " meter." << endl; 
    }else if(data_amilzakat.kode_pos == 40614){
        cout << "menuju daerah " << rute_cipadung.rute1 << " sejauh " << hasil[0].w << " meter." << endl;
    }else if(data_amilzakat.kode_pos == 40394){
        cout << "menuju daerah " << rute_cangkuang.rute1 << " sejauh " << hasil[0].w << " meter." << endl;
    }
    Sleep(1500);
    cout << " - Kedua, ";
    if(data_amilzakat.kode_pos == 40392){
        cout << "menuju daerah " << rute_margaasih.rute2 << " sejauh " << hasil[1].w << " meter." << endl;
    }else if(data_amilzakat.kode_pos == 40614){
        cout << "menuju daerah " << rute_cipadung.rute2 << " sejauh " << hasil[1].w << " meter." << endl;
    }else if(data_amilzakat.kode_pos == 40394){
        cout << "menuju daerah " << rute_cangkuang.rute2 << " sejauh " << hasil[1].w << " meter." << endl;
    }
    Sleep(1500);
    cout << " - Ketiga, ";
    if(data_amilzakat.kode_pos == 40392){
        cout << "menuju daerah " << rute_margaasih.daerah << " sejauh " << hasil[2].w << " meter." << endl;
    }else if(data_amilzakat.kode_pos == 40614){
        cout << "menuju daerah " << rute_cipadung.daerah << " sejauh " << hasil[2].w << " meter." << endl;
    }else if(data_amilzakat.kode_pos == 40394){
        cout << "menuju daerah " << rute_cangkuang.daerah << " sejauh " << hasil[2].w << " meter." << endl;
    }
    cout << " Total Jarak Tempuh Menuju Lokasi = " << total << " Meter" << endl;
}

