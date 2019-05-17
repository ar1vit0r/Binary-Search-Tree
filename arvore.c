#include "arvore.h"

struct nodo * inicializa_arvore(int entradas, int * valores){
    node *raiz;

        if(entradas < 1 || valores == NULL)
            return NULL;

        if( ( raiz = malloc(sizeof(node))) == NULL )
            return NULL;
        raiz->valor = valores[0];
        raiz->dir = NULL;
        raiz->esq = NULL;

        if( entradas > 1){
            node *temp1,*temp2;
            temp1 = raiz;
            for(int i = 1; i < entradas; i++){
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
        if( raiz == NULL){
            node *temp;
                if( ( temp = malloc(sizeof(node))) == NULL)
                    return NULL;
                temp->valor = valor;
                temp->dir = NULL;
                temp->esq = NULL;
            return temp;
        }
        else{
            if( raiz->valor > valor){
                raiz->esq = insere_nodo(raiz->esq,valor);
                return raiz;
            }
            else{
                if( raiz->valor < valor){
                    raiz->dir = insere_nodo(raiz->dir,valor); // se der ruim, tentar com raiz->esq
                    return raiz;
                }
                else
                    return raiz;
            }
        }
return NULL;
}

struct nodo * remove_nodo(struct nodo * raiz, int valor){
    node *temp;
        if( raiz == NULL)
            return NULL;
        else{
            if( raiz->valor > valor)
                raiz->esq = remove_nodo(raiz->esq,valor);
            else{
                if( raiz->valor < valor)
                    raiz->dir = remove_nodo(raiz->dir,valor);
                else{
                    if( raiz->dir != NULL && raiz->esq != NULL){ // dois filhos
                        // pode dar problema, no slide, pref é da direita...
                        temp = busca_min(raiz->esq); // maior da esquerda ou menor da direita
                        raiz->valor = temp->valor;
                        raiz->esq = remove_nodo(raiz->esq,raiz->valor); 
                    }
                    else{
                        if( raiz->dir == NULL)
                            temp = raiz->esq;
                        else
                            temp = raiz->dir;

                        free(raiz);
                        return temp;
                    }
                }
            }
            
        }
return NULL;
}

int altura(struct nodo * raiz){

}

struct nodo * busca(struct nodo * raiz, int valor){
        if( raiz == NULL)
            return NULL;
        else{
            if( raiz->valor == valor )
                return raiz;
            else{
                if( raiz->valor > valor)
                    return busca(raiz->esq,valor);
                else
                    return busca(raiz->dir,valor);
            }
        }
return NULL;
}

struct nodo * busca_min(struct nodo * raiz){
    node *temp;
    int i;

        for( i = 0; i <= 100; i++){
            temp = busca(raiz,i);
            if( temp != NULL)
                return temp;
        }
printf("\n Não Encontrou um min entre 0 e 100. \n");
return NULL;
}

int balanceada(struct nodo * raiz){

}

int numero_elementos(struct nodo * raiz){

}

int abrangencia(struct nodo * raiz, int * resultado){

}

int prefix(struct nodo * raiz, int * resultado){
        if( raiz == NULL)
            return NULL;
        else{
            if( )
                
            else

        }
}

int postfix(struct nodo * raiz, int * resultado){

}

int infix(struct nodo * raiz, int * resultado){

}

void imprime(int * valores, int tamanho){
    int i;
        for( i = 0; i < tamanho; i++){
            printf("\n Valor %d: %d ",i+1,valores[i]);
            if( i % 10 == 0)
                printf("\n");
        }
return;
}

void remove_todos(struct nodo * raiz){
        if( raiz != NULL){
            while( raiz != NULL)
                remove_nodo(raiz,raiz->valor);
        }
return;
}
