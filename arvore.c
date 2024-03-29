#include "arvore.h"

struct nodo * inicializa_arvore(int entradas, int * valores){
        if(entradas < 1 || valores == NULL)
            return NULL;
        
        node *raiz = NULL;
            raiz = insere_nodo(raiz,valores[0]);
            for( int i = 1; i < entradas; i++)
                insere_nodo(raiz,valores[i]);
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
                        raiz->valor = temp->valor;   // novo pai
                        raiz->dir = remove_nodo(raiz->dir,raiz->valor); //remove pra n ficar 2 chaves iguais
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
return raiz;
}

int altura(struct nodo * raiz){
        if (raiz == NULL) 
            return 0;
        else{
	    int ae,ad;
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
        }
return e-d;
}

int numero_elementos(struct nodo * raiz){
    int e,d;
        if (raiz == NULL){
            return 0;
        }
        else{
            e = numero_elementos(raiz->esq);
            d = numero_elementos(raiz->dir);
        }
return e+d+1;
}

int abrangencia(struct nodo * raiz, int * resultado){ 
    int x = 0;
    int *count;
        count = &x;
        for(int i = 0; i <= altura(raiz); i++)
            abrangencia_count(raiz, resultado, count, i);
return numero_elementos(raiz);
}

void abrangencia_count(struct nodo * raiz, int * resultado, int * count, int andar){
        if(raiz == NULL)
            return;
        if( andar == 1){
            resultado[*count] = raiz->valor;
            (*count)++;
        }
        else{
            if( andar > 1){
                abrangencia_count(raiz->esq, resultado, count, andar-1);
                abrangencia_count(raiz->dir, resultado, count, andar-1);
            }
        }
return;
}

int prefix(struct nodo * raiz, int * resultado){
    int *count;
    int i = 0;
        count = &i;
return prefix_count(raiz, resultado, count);
}

int prefix_count(struct nodo * raiz, int * resultado, int * count){
    if(raiz != NULL){
        resultado[*count] = raiz->valor;
        (*count)++;
        prefix_count(raiz->esq, resultado, count);
        prefix_count(raiz->dir, resultado, count);
    }
return numero_elementos(raiz);
}

int infix(struct nodo * raiz, int * resultado){
    int *count;
    int i = 0;
        count = &i;
return infix_count(raiz, resultado, count);
}

int infix_count(struct nodo * raiz, int * resultado, int * count){
    if(raiz != NULL){
        infix_count(raiz->esq, resultado, count);
        resultado[*count] = raiz->valor;
        (*count)++;
        infix_count(raiz->dir, resultado, count);
    }
return numero_elementos(raiz);
}

int postfix(struct nodo * raiz, int * resultado){
    int *count;
    int i = 0;
        count = &i;
return postfix_count(raiz, resultado, count);
}

int postfix_count(struct nodo * raiz, int * resultado, int * count){
    if(raiz != NULL){
        postfix_count(raiz->esq, resultado, count);
        postfix_count(raiz->dir, resultado, count);
        resultado[*count] = raiz->valor;
        (*count)++;
    }
return numero_elementos(raiz);
}

void imprime(int * valores, int tamanho){
    int i,n;
        n = 0;
        if( tamanho < 1 || valores == NULL)
            return;
        printf("            "); // ficar bonito...
        for( i = 0; i < tamanho; i++){
            n++;
            printf("%d ",valores[i]);
            if( n == 10){
                n = 0;
                printf("\n");
                printf("            "); // tb
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






