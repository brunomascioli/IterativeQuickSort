#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
Considere o texto abaixo e discuta com o grupo. No início do
arquivo principal, coloque como comentário se a estratégia
faz sentido e se ela foi implementada

"A estratégia iterativa do algoritmo Quicksort oferece uma vantagem 
ao estabelecer limites para o tamanho da pilha. Em contraste com a
abordagem recursiva, que insere duas partições na pilha de execução 
em ordem arbitrária, a versão iterativa verifica os tamanhos das partições 
antes de adicionar à pilha. Além disso, ao adotar uma política 
que prioriza a inserção dos índices da partição maior do vetor antes 
dos índices da partição menor, permite que o lado menor seja processado 
antes do lado maior. Como resultado, o tamanho da pilha é da ordem de O(log(n))."

Resposta:
A estratégia faz sentido, e nós a implementamos.
A versão iterativa do Quicksort, ao priorizar a inserção da maior partição na pilha, 
assegura que o espaço usado pela pilha seja minimizado, aproximando-se de O(log(n)). 
Esta abordagem é eficiente e previne estouros de pilha, comuns na versão recursiva 
quando o tamanho do array é grande, pois no caso do QuickSort recursivo, em um cenário 
desfavorável, como quando o array já está ordenado ou quase ordenado, a escolha do pivô pode
resultar em partições altamente desbalanceadas, significando que uma partição
pode ser muito maior do que a outra, levando a um grande número de chamadas
recursivas aninhadas. 
*/

void swap(int* i, int* j) {
    int aux = *i;
    *i = *j;
    *j = aux;
}

int partition_array(int array[], int start, int end) { 
    int pivot = array[end]; 
    int i = (start - 1); 
  
    for (int j = start; j <= end - 1; j++) { 
        if (array[j] <= pivot) { 
            i++; 
            swap(&array[i], &array[j]); 
        } 
    } 
    swap(&array[i + 1], &array[end]); 
    
    return (i + 1); 
} 

void iterative_quick_sort(int array[], int start, int end) { 
    t_stack* stack = create_stack(end - start + 1);

    push(stack, start);
    push(stack, end);

    while (!is_empty(stack)) {
        top(stack, &end);
        pop(stack);
        top(stack, &start);
        pop(stack);
  
        int index_pivot = partition_array(array, start, end); 
  
        if (index_pivot - 1 > start) { 
            push(stack, start); 
            push(stack, index_pivot - 1); 
        } 
  
        if (index_pivot + 1 < end) { 
            push(stack, index_pivot + 1); 
            push(stack, end); 
        } 
    }
    destroy_stack(stack);
} 

int main(){
    int len;
    
    scanf("%d", &len);
    int array[len];
    for(int i = 0; i < len; i++) 
        scanf("%d", &array[i]);
    
    iterative_quick_sort(array, 0, len - 1);

    for (int i = 0; i < len; ++i)
         printf("%d ", array[i]); 
    
    printf("\n");
    return 0;
}
