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

    if(p==NULL) {
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


int calculaAlturaArvore(NoArv *raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        int esq = calculaAlturaArvore(raiz->esq);
        int dir = calculaAlturaArvore(raiz->dir);
        
        if (esq > dir) {
            return calculaAlturaArvore(raiz->esq) + 1;
        }
            
        return dir + 1;
    }
}


int main() {
    NoArv *raiz = criaArvore(1, criaArvore(2, criaArvoreVazia(), criaArvore(3, criaArvoreVazia(), criaArvoreVazia())), criaArvore(3, criaArvore(5, criaArvoreVazia(), criaArvoreVazia()), criaArvore(6, criaArvoreVazia(), criaArvore(6, criaArvoreVazia(), criaArvoreVazia()))));
    
    cout << "A altura da árvore é " << calculaAlturaArvore(raiz) << endl;

    return 0;
}
