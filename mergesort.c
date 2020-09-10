/*
Algoritmo Merge-Sort do Trabalho 1 de PAA
Pedro Vitor Valenca Mizuno
17/0043665
Baseado no Pseudo-Codigo do livro:
Algoritmos - Teoria e Pratica 3a Edicao
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void merge(int A[100000], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1+1], R[n2+1], i, j;

    for(i = 0; i < n1; i++)
        L[i] = A[p + i];
    for(j = 0; j < n2; j++)
        R[j] = A[q + j + 1];

    L[n1] = 2147483000;
    R[n2] = 2147483000;
    i = 0;
    j = 0;

    for(int k = p; k <= r; k++) {
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergesort(int A[100000], int p, int r){
    if(p < r) {
        int q = floor((p + r)/2);
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main(){
    // Versao para testar no terminal
    /*char str[1000];
    char * number;
    int32_t aux[100000], i = 0;

    fgets(str, 1000, stdin);
    number = strtok(str, " ");
    while(number != NULL){
        aux[i] = atoi(number);
        i++;
        number = strtok(NULL, " ");
    }*/

    // Versao para o spoj
    int32_t aux[100000], i = 0, n;
    while(scanf("%d", &n) != EOF)
        aux[i++] = n;
    

    mergesort(aux, 0, i-1);

    for(int j = 0; j < i; j++){
        if(j+1 != i)
            printf("%d ", aux[j]);
        else
            printf("%d", aux[j]);
    }
    printf("\n");

    return 0;
}