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

int cekPrior(char kode){
    if (kode=='H') return 0;
    if (kode=='L') return 1;
    if (kode=='D') return 2;
    if (kode=='N') return 3;
}

void createElemen(pointer& p){
    p = new ElemenQueue;
    cout<<"Nama : ";cin>>p->nama;
    cout<<"Jus  : ";cin>>p->jus;
    p->priority = 0;
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
    int byk_pelanggan, jml_pesanan;
    createQueue(Q);

    cout<<"Banyak Pelanggan: ";cin>>byk_pelanggan;
    for (int i=0;i<byk_pelanggan;i++){
        createElemen(p);
        insertQueue(Q,p);
    }
    cout<<"\nUrutan yang dilayani:\n";
    traversal(Q);
}