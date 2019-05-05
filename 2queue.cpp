#include <iostream>
#include <string.h>
using namespace std;

struct ElemenQueue {
    string nama;
    char kode;
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
    cout<<"Nama         : ";cin>>p->nama;
    cout<<"Kode(H/L/D/N): ";cin>>p->kode;
    p->priority = cekPrior(p->kode);
    p->next = NULL;
}

void createNullElemen(pointer& p){
    p = new ElemenQueue;
    p->nama = "0";
    p->kode = '-';
    p->priority = 100;
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

void traversal(Queue Q, int dari, int sampai){
    pointer pBantu = Q.Head;
    int count = 0;

    while(pBantu!=NULL){
        if (count>=dari&&count<sampai){
            cout<<pBantu->nama<<" ";
        }
        pBantu = pBantu->next;
        count++;
    }
}

int main(){
    pointer p,h;
    int penumpang,maks_kursi;
    cout<<"Maksimal Kursi    : ";cin>>maks_kursi;
    cout<<"Banyak Penumpang  : ";cin>>penumpang;
    
    createQueue(Q);
    if (maks_kursi>penumpang){
        for (int i=0;i<penumpang;i++){
            createElemen(p);
            insertQueue(Q,p);
        }
        for (int i=penumpang;i<maks_kursi;i++){
            createNullElemen(p);
            insertQueue(Q,p);
        }
    }
    else{
        for (int i=0;i<penumpang;i++){
            createElemen(p);
            insertQueue(Q,p);
        }
    }
    
    cout<<"\nSKEMA DUDUK:\n";
    cout<<"Keluar<--";
    traversal(Q,0,maks_kursi);
    cout<<"<--Masuk";
    if (maks_kursi<penumpang){
        cout<<"\nBerdiri: ";
        traversal(Q,maks_kursi,penumpang);
    }
}