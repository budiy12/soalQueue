#include <iostream>
#include <string.h>
using namespace std;

struct ElemenQueue {
    string nama;
    string jus;
    //lower value higher priority
    int priority;
    ElemenQueue* next;
};
typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue {
    List Head;
    List Tail;
};
Queue Q,Berdiri;

void createQueue(Queue& Q){
    Q.Head = NULL;
    Q.Tail = NULL;
}

void createElemen(pointer& p,string nama, string jus, int prior){
    p = new ElemenQueue;
    p->nama = nama;
    p->jus = jus;
    p->priority = prior;
    p->next = NULL;
}

void insertQueue( Queue& Q, pointer pBaru){
    if (Q.Head==NULL && Q.Tail==NULL) { // kosong
        Q.Head = pBaru;
        Q.Tail = pBaru;
    } 
    else{ 
        pointer start = Q.Head;
        if (Q.Head->priority>pBaru->priority){
            pBaru->next = Q.Head;
            Q.Head = pBaru;
        }
        else{
            while(start->next!=NULL&&
            start->next->priority<=pBaru->priority){
                start = start->next;
            }
            pBaru->next = start->next;
            start->next = pBaru;
        }
    }
}
// Tdk digunakan
void deleteQueue(Queue& Q, pointer& pHapus){
    cout<<"Delete Queue"<<endl;
    if (Q.Head==NULL && Q.Tail==NULL) { //kasus kosong
        pHapus=NULL;
        cout<<"List Queue kosong "<<endl;
    }
    else if (Q.Head->next==NULL) { // kasus isi 1 elemen
        pHapus=Q.Head;
        Q.Head=NULL;
        Q.Tail=NULL;
    }
    else { // kasus > 1 elemen
        pHapus=Q.Head;
        Q.Head=Q.Head->next;
        pHapus->next=NULL;
    }
}

void traversal(Queue Q){
    pointer pBantu = Q.Head;
    while(pBantu!=NULL){
        cout<<pBantu->nama<<" ("<<pBantu->jus<<") \n";
        pBantu = pBantu->next;
    }
}

int main(){
    pointer p,h;
    string nama, jus;
    string buah[5];
    int byk_pelanggan, jml_pesanan;
    createQueue(Q);

    cout<<"Banyak Pelanggan: ";cin>>byk_pelanggan;
    for (int i=0;i<byk_pelanggan;i++){
        cout<<"Nama  : ";cin>>nama;
        cout<<"Jumlah: ";cin>>jml_pesanan;
        for (int j=0;j<jml_pesanan;j++){
            cout<<"Jus: ";cin>>jus;
            int h = 0;
            while(buah[h]!=""&&buah[h]!=jus){
                h++;
            }
            buah[h]=jus;
            createElemen(p,nama,jus,h);
            insertQueue(Q,p);
        }
    }
    cout<<"\nUrutan yang dilayani:\n";
    traversal(Q);
}