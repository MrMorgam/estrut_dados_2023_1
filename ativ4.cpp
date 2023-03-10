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

    if (p == NULL) {
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


int igual(NoArv* a, NoArv* b) {
    // função
}


int main() {
    NoArv *raiz1 = criaArvore(1, criaArvore(2, criaArvoreVazia(), criaArvore(3, criaArvoreVazia(), criaArvoreVazia())), criaArvore(3, criaArvore(5, criaArvoreVazia(), criaArvoreVazia()), criaArvore(6, criaArvoreVazia(), criaArvore(6, criaArvoreVazia(), criaArvoreVazia()))));
    NoArv *raiz2 = criaArvore(1, criaArvore(2, criaArvoreVazia(), criaArvore(3, criaArvoreVazia(), criaArvoreVazia())), criaArvore(3, criaArvore(5, criaArvoreVazia(), criaArvoreVazia()), criaArvore(6, criaArvoreVazia(), criaArvore(6, criaArvoreVazia(), criaArvoreVazia()))));

    int arv_iguais = igual(raiz1, raiz2);

    if (arv_iguais == 1) {
        cout << "As árvores são iguais" << endl;
    } else {
        cout << "As árvores não são iguais" << endl;
    }

    return 0;
}