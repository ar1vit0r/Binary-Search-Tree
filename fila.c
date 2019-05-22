#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

struct fila * create(){
    struct fila *f;
        f = malloc(sizeof(struct fila));
        if(f == NULL)
            return NULL;
        f->fila = create_l();
        return f;  
}

int makenull(struct fila * f){ 
    struct llist * temp;
        temp = f->fila;
        if( !vazia(f)){
			while( temp->tam > 0 ){
                delete_l(temp,NULL); // removendo a cabe�a
            }
		return 1;
		}
        else
		    return 0;
}

int dequeue(struct fila * f){ 
    struct llist * temp;
        elem *head;
        int val;
        temp = f->fila;
        if( !vazia(f)){
            head = temp->cabeca; // ou get_l(temp,1);
            val = head->val;
            delete_l(temp,NULL); // remove a cabe�a
		    return val;
		}
        else
		    return 0;
}

int enqueue(struct fila * f, int val){
    struct llist *temp;
        elem *aux;
        int key;
        temp = f->fila;
        aux = create_node(val);
        key = insert_l(temp, temp->tail , aux);
        free(aux);
        return key;
}

int vazia(struct fila * f){
    struct llist *temp;
        temp = f->fila;
        if( temp->tam > 0)
            return 0;
        else{
            printf("Fila Vazia \n");
        return 1;
        }
 }

void destroy(struct fila * f){
      if( !vazia(f))
            makenull(f);
    free(f);
    return;
}