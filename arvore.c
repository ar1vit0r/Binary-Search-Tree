#include "arvore.h"

struct nodo * inicializa_arvore(int entradas, int * valores){
        if(entradas < 1 || valores == NULL)
            return NULL;
        else{
            node *raiz = NULL;
                raiz = insere_nodo(raiz,valores[0]);
                for( int i = 1; i < entradas; i++)
                    insere_nodo(raiz,valores[i]);
	        return raiz;
        }
return NULL;
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
                    raiz->dir = insere_nodo(raiz->dir,valor); 
                    return raiz;
                }
                else
                    return raiz;
            }
        }
return NULL;
}

struct nodo * remove_nodo(struct nodo * raiz, int valor){
        if( raiz == NULL)
            return NULL;
        else{
            if( raiz->valor > valor)
                raiz->esq = remove_nodo(raiz->esq,valor);
            else{
                if( raiz->valor < valor)
                    raiz->dir = remove_nodo(raiz->dir,valor);
                else{
                    node *temp;

                    if( raiz->dir != NULL && raiz->esq != NULL){ // dois filhos
                        temp = busca_min(raiz->dir); // maior da esquerda ou menor da direita
                        raiz->valor = temp->valor;
                        raiz->dir = remove_nodo(raiz->dir,raiz->valor); 
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
    int ae,ad;
        if (raiz == NULL) 
            return 0;
        else{
            ae = altura(raiz->esq);
            ad = altura(raiz->dir);
            if(ae < ad) 
                return ad + 1;
            else 
                return ae + 1;
   }
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
    if( raiz != NULL){
        if( raiz->esq != NULL)
            return busca_min(raiz->esq);
        else
            return raiz;
    }
return NULL;
}

struct nodo * busca_max(struct nodo * raiz){
    if( raiz != NULL){
        if( raiz->dir != NULL)
            return busca_max(raiz->dir);
        else
            return raiz;
    }
return NULL;
}

int balanceada(struct nodo * raiz){
    int e,d;
        if( raiz == NULL)
            return 0;
        else{
            e = numero_elementos(raiz->esq);
            d = numero_elementos(raiz->dir);
            return e-d;
        }
}

int numero_elementos(struct nodo * raiz){
    int i = 0;
        if( raiz == NULL)
            return 0;
        else{
            i++;
            i+=numero_elementos(raiz->esq);
            i+=numero_elementos(raiz->dir);
        }
return i;
}

int abrangencia(struct nodo * raiz, int * resultado){ 
    int i = 0;
        if( raiz != NULL){
            resultado[i] = raiz->valor;
            i++;
            i+=prefix(raiz->esq,resultado); 
            i+=prefix(raiz->dir,resultado);
        }
return i;
}
/* 
int i = 0;
    struct fila *f;
        f = create();
        if( raiz != NULL){
            enqueue(f,raiz->valor);
            while( !vazia(f)){
                resultado[i] = dequeue(f);
                i++;
                if( raiz->esq != NULL){
                    node *temp = raiz->esq;
                    enqueue(f,temp->valor);
                }
                if( raiz->dir != NULL){
                    node *temp = raiz->dir;
                    enqueue(f,temp->valor);
                }
            }
        }
return i;
*/

int prefix(struct nodo * raiz, int * resultado){
    int i = 0;
        if( raiz != NULL){
            resultado[i] = raiz->valor;
            i++;
            i+=prefix(raiz->esq,resultado); 
            i+=prefix(raiz->dir,resultado);
        }
return i;
}

int infix(struct nodo * raiz, int * resultado){
    int i = 0;
        if( raiz != NULL){
            i+=infix(raiz->esq,resultado); 
            resultado[i] = raiz->valor;
            i++;
            i+=infix(raiz->dir,resultado);
        }
return i;
}

int postfix(struct nodo * raiz, int * resultado){
    int i = 0;
        if( raiz != NULL){
            i+=postfix(raiz->esq,resultado); 
            i+=postfix(raiz->dir,resultado);
            resultado[i] = raiz->valor;
            i++;
        }
return i;
}

void imprime(int * valores, int tamanho){
    int i,n;
        n = 0;
        printf("        "); // ficar bonito...
        for( i = 0; i < tamanho; i++){
            n++;
            printf("%d ",valores[i]);
            if( n == 10){
                n = 0;
                printf("\n");
                printf("        "); // tb
            }
        }
        printf("\n");
return;
}

void remove_todos(struct nodo * raiz){
    if( raiz != NULL){
        remove_todos(raiz->esq);
        remove_todos(raiz->dir);
        free(raiz);
    }
return;
}






