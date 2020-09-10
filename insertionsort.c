/*
Algoritmo Insertion Sort do Trabalho 1 de PAA
Pedro Vitor Valenca Mizuno
17/0043665
Baseado no Pseudo-Codigo do livro:
Algoritmos - Teoria e Pratica 3a Edicao
*/

#include <stdio.h>

void insertion_sort(int T){
    int N, A[100000];
    int  num, cont = 0, key, i = 0, j, swap = 0;
    while(cont < T){
        scanf("%d", &N);

        for(int a = 0; a < N; a++){
            scanf("%d", &A[a]);
        }

        for(j = 1; j < N; j++){
            key = A[j];
            i = j - 1;
            while(i >= 0 && A[i] > key){
                A[i+1] = A[i];
                i = i - 1;
                swap++;
            }
            A[i + 1] = key;
        }

        printf("%d\n", swap);

        swap = 0;
        cont++;
    }
}


int main(){
    int T;

    scanf("%d", &T);

    insertion_sort(T);

    return 0;
}