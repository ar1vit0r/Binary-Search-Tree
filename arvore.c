#include "arvore.h"

struct nodo * inicializa_arvore(int entradas, int * valores){
    node *raiz,*temp1,*temp2;
        int i;

        if(entradas < 1 || valores == NULL)
            return NULL;

        if( ( raiz = malloc(sizeof(node))) == NULL )
            return NULL;
        raiz->valor = valores[0];
        temp1 = raiz;

        if( entradas > 1){
            for(i = 1; i < entradas; i++){
                if( ( temp2 = malloc(sizeof(node))) == NULL )
                    return NULL;

                temp2->valor = valores[i];
                temp2->esq = NULL;
                temp2->dir = NULL;

                if( temp2->valor > temp1->valor)
                    temp1->dir = temp2;
                else
                    temp1->esq = temp2;

                temp1 = temp2;
            }
        }
return raiz;
}

struct nodo * insere_nodo(struct nodo * raiz, int valor){

        if( busca(raiz,valor) != NULL){
            node *temp;

            temp = raiz;
            while (temp != NULL){
                if( valor < temp->valor)
                    temp = temp->esq;
                else
                    temp = temp->dir;
            }
            
            if( valor < temp->valor){
                if( (temp->esq = malloc(sizeof(node)) ) == NULL )
                    return NULL;
                temp->esq->valor = valor;
                temp->esq->esq = NULL;
                temp->esq->dir = NULL;
            }
            else{
                if( (temp->dir = malloc(sizeof(node)) ) == NULL )
                    return NULL;
                temp->dir->valor = valor;
                temp->dir->esq = NULL;
                temp->dir->dir = NULL;
            }
        return raiz;
        }
return NULL
}

struct nodo * remove_nodo(struct nodo * raiz, int valor){

}

int altura(struct nodo * raiz){

}

struct nodo * busca(struct nodo * raiz, int valor){

}

int balanceada(struct nodo * raiz){

}

int numero_elementos(struct nodo * raiz){

}

int abrangencia(struct nodo * raiz, int * resultado){

}

int prefix(struct nodo * raiz, int * resultado){

}

int postfix(struct nodo * raiz, int * resultado){

}

int infix(struct nodo * raiz, int * resultado){

}

void imprime(int * valores, int tamanho){

}

void remove_todos(struct nodo * raiz){

}
