#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#ifndef _ARVORE_H_
#define _ARVORE_H_

/* IMPLEMENTAÇÃO DE ÁRVORE BINÁRIA DE PESQUISA */

typedef struct nodo {
	int valor; 
	struct nodo * dir, * esq;
}node;

/* Inicializa uma árvore
 * @param entradas número de valores iniciais
 * @param valores vetor com valores a serem inseridos
 * @return raiz da árvore ou NULL se erro
 */ 
struct nodo * inicializa_arvore(int entradas, int * valores);

/* Insere nodo em uma árvore se a chave ainda não existir, sempre como uma folha
 * @param raiz raiz da árvore
 * @param valor o que será inserido 
 * @return raiz da árvore
 */ 
struct nodo * insere_nodo(struct nodo * raiz, int valor);

/* Remove nodo em uma árvore se existir, dando prioridade à subárvore esquerda para novo nodo raiz
 * @param raiz raiz da árvore
 * @param valor o que será removido 
 * @return raiz da árvore
 */ 
struct nodo * remove_nodo(struct nodo * raiz, int valor);

/* Altura de uma árvore
 * @param raiz raiz da árvore
 * @return altura da árvore
 */
int altura(struct nodo * raiz);

/* Consulta se nodo existe
 * @param raiz raiz da árvore 
 * @param valor chave a ser buscada
 * @return ponteiro para nodo, ou NULL se inexistente
 */
struct nodo * busca(struct nodo * raiz, int valor);

/* Busca a menor chave da árvore
 * @param raiz raiz da árvore 
 * @return ponteiro para nodo, ou NULL se inexistente
 */
struct nodo * busca_min(struct nodo * raiz); 

/* Busca a maior chave da árvore
 * @param raiz raiz da árvore 
 * @return ponteiro para nodo, ou NULL se inexistente
 */
struct nodo * busca_max(struct nodo * raiz); 

/* Descobre se uma árvore está balanceada
 * @param raiz da árvore
 * @return diferença das alturas das subárvores
 */
int balanceada(struct nodo * raiz);

/* Número de elementos em uma árvore 
 * @param raiz raiz da árvore
 * @return número de elementos da árvore 
 */
int numero_elementos(struct nodo * raiz);

/* Percorre a árvore em abrangência 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @return número atual de elementos no vetor
 */
int abrangencia(struct nodo * raiz, int * resultado);

/* Passa os parãmetros pro interno por causa do contador 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @return número atual de elementos no vetor
 */
int prefix(struct nodo * raiz, int * resultado);

/* Percorre a árvore de forma pré-fixada 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @param count contador do vetor
 * @return número atual de elementos no vetor
 */
int prefix_count(struct nodo * raiz, int *resultado, int * count);

/* Passa os parãmetros pro interno por causa do contador 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @return número atual de elementos no vetor
 */
int postfix(struct nodo * raiz, int * resultado);

/* Percorre a árvore de forma pós-fixada 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @param count contador do vetor
 * @return número atual de elementos no vetor
 */
int postfix_count(struct nodo * raiz, int *resultado, int * count);

/* Passa os parãmetros pro interno por causa do contador
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @return número atual de elementos no vetor
 */
int infix(struct nodo * raiz, int * resultado);

/* Percorre a árvore de forma infix 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @param count contador do vetor
 * @return número atual de elementos no vetor
 */
int infix_count(struct nodo * raiz, int *resultado, int * count);

/* Imprime na stdio os valores de um caminhamento com um espaço entre cada valor, 
 * máximo de 10 valores por linha
 * @param valores vetor com valores a serem impressos
 * @param tamanho número de entradas no vetor de valores
 */
void imprime(int * valores, int tamanho);

/* Remove todos os nodos
 * @param raiz da árvore
 */
void remove_todos(struct nodo * raiz);



#endif 