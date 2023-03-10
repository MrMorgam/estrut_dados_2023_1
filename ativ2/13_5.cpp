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

    if( p==NULL) {
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


int contaRepeticoesItem(NoArv *raiz, int Item) {
    if (!arvoreEstaVazia(raiz)) {
        if (raiz->info == Item) {
            return 1;
        } else {
            return 0 + contaRepeticoesItem(raiz->esq,Item) + contaRepeticoesItem(raiz->dir,Item);
        }

    } else {
        return 0;
    }
}


int main() {
    NoArv *raiz = criaArvore(1, criaArvore(2, criaArvoreVazia(), criaArvore(3, criaArvoreVazia(), criaArvoreVazia())), criaArvore(3, criaArvore(5, criaArvoreVazia(), criaArvoreVazia()), criaArvore(6, criaArvoreVazia(), criaArvore(6, criaArvoreVazia(), criaArvoreVazia()))));
    
    if (contaRepeticoesItem(raiz , 9)) {
        cout << "Item está na arvore" << endl;
    } else {
        cout << "Item não está na arvore" << endl;
    }
    
    return 0;
}