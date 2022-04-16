#include <stdio.h>
#include <stdlib.h>


int size = 0;
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Function to heapify the tree
void heapify(int array[], int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {
    // Find the largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}

// Function to insert an element into the tree
void insert(int array[], int newNum) {
  if (size == 0) {
    array[0] = newNum;
    size += 1;
  } else {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(array, size, i);
    }
  }
}

// Function to delete an element from the tree
void deleteRoot(int array[], int num) {
  int i;
  for (i = 0; i < size; i++) {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
}

// Print the array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}


int minCost(int arr[], int n)
{
    // Crie uma priority queue
    
    // Por padrão 'menos' é usado para ordem decrescente
    // e 'maior' é usado para ordem crescente
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr + n);
 
    // inicializando resultado
    int res = 0;
 
    // Embora o tamanho da fila de prioridade seja superior a 1

    while (pq.size() > 1) {
        // Extraia as duas cordas mais curtas do pq
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
 
        // Conecte as cordas: atualize o resultado e insira a nova corda para pq

        res += first + second;
        pq.push(first + second);
    }
 
    return res;
}
 
// Programa de driver para testar a função acima
int main()
{
    int len[] = { 4, 3, 2, 6 };
    int size = sizeof(len) / sizeof(len[0]);
    printf("Total cost for connecting ropes is ", minCost(len, size));
    return 0;
}
