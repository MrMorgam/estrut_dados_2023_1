#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;


typedef struct noArv {
    int info;
    struct noArv* esq;
    struct noArv* dir;
} NoArv;


NoArv* criaArvore(int c, NoArv* e, NoArv* d) {
    NoArv* p = (NoArv*)malloc(sizeof(NoArv));
    
    if (p==NULL) {
        exit(1);
    }

    p->info = c;
    p->esq = e;
    p->dir = d;

    return p;
}


NoArv* criaArvoreVazia(void) {
    return NULL;
}


int arvoreEstaVazia(NoArv* a) {
    return a == NULL;
}


int contaNos(NoArv *raiz) {
    if(arvoreEstaVazia(raiz)) {
        return 0;
    } else {
        return 1 + contaNos(raiz->esq) + contaNos(raiz->dir);
    }
}


int main() {
    NoArv *raiz = criaArvore(1, criaArvore(2,  criaArvoreVazia(), criaArvore(3, criaArvoreVazia(), criaArvoreVazia())), criaArvore(3, criaArvore(5, criaArvoreVazia(), criaArvoreVazia()), criaArvore(6, criaArvoreVazia(), criaArvore(6, criaArvoreVazia(), criaArvoreVazia()))));

    int total = contaNos(raiz);
    
    cout << total << endl;
    
    return 0;
}