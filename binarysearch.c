/*
Algoritmo de Busca Binaria do Trabalho 1 de PAA
Pedro Vitor Valenca Mizuno
17/0043665
Baseado no Pseudo-Codigo do link:
https://www.tutorialspoint.com/data_structures_algorithms/binary_search_algorithm.htm
*/

#include <stdio.h>
#include <math.h>

void binary_search(int N, int Q){
    int A[N], i, num, encontrado = 0;
    int meio, inicio, fim;
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for(i = 0; i < Q; i++) {
        scanf("%d", &num);
        inicio = 0;
        fim = N-1;
        while(encontrado == 0 && fim >= inicio) {
            meio = floor(inicio + (fim - inicio)/2);

            if(A[meio] < num)
                inicio = meio+1;
            if(A[meio] > num)
                fim = meio-1;
            if(A[meio] == num) {
                encontrado = 1;
                if(meio > 0 && A[meio-1] == num){
                    fim = meio - 1;
                    encontrado = 0;
                }
            }
        }

        if(encontrado == 0)
            printf("-1\n");
        else
            printf("%d\n", meio);
        encontrado = 0;
    }
}

int main(){
    int N, Q;
    scanf("%d", &N);
    scanf("%d", &Q);
    binary_search(N, Q);
}