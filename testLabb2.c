#include <stdio.h>


/*
 * Swap
 * DESCRIPTION:
 *   Swaps the values of two integer pointers.
 * PRECONDITIONS:
 *   n/a
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array[0], array[1])
 *   OUTPUT:
 *   post: array = {2, 1, 3, 4}
 *
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array[1], array[1])
 *   OUTPUT:
 *   post: array = {1, 2, 3, 4}
 *
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array[0], array[-1])
 *   OUTPUT:
 *   post: array = {VALUE FROM MEMORY, 2, 3, 4}
 */
void swap(int *a, int *b) {
  int temp = *a;

  *a = *b;
  *b = temp;
}

/*
 * sortInner
 * DESCRIPTION:
 *   The inner recursive loop of the negative seperation algoritm.
 *   Checks if the array element of the "previous" index is positive
 *   and if current element is negative. Swaps these elements using "swap"
 *   if this should be the case.
 *   Prints the new state of the array if "swap" is called.
 * PRECONDITIONS:
 *   index and index-1 is within bounds of array
 *   length = length of array
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 4, 1)
 *   OUTPUT: [4],[3],[2],[1],
 *
 *   pre: array = {4, -3, 2, 1}
 *   INPUT: (array, 4, 1)
 *   OUTPUT: [-3],[4],[2],[1],
 *
 *   pre: array = {4, 3, 2, -1}
 *   INPUT: (array, 4, 4)
 *   OUTPUT: [-1],[4],[3],[2],
 *
 *   pre: array = {1, -2, 0, 4}
 *   INPUT: (array, 3, 4)
 *   OUTPUT: [1],[-2],[0],[4],
 *
 *   pre: array = {1, 2, 3, -4}
 *   INPUT: (array, 4, 3)
 *   OUTPUT: [1],[2],[3],[-4],
 */
void sortInner(int *array, int length, int index) {

  // base case
  if(index <= 0 || array[index] >= 0) {
    return;
  }

  if(array[index-1] >= 0) {
    swap(&array[index], &array[index-1]);
    arrayToString(array, length);
  }

  // recursive call with decreased index
  sortInner(array, length, index-1);

}


/*
 * sortOuter
 * DESCRIPTION:
 *   The outer recursive loop of the negative seperation algoritm.
 *   Calls the "sortInner" for each element of the array starting
 *   at "index".
 *   Called by "sort".
 * PRECONDITIONS:
 *   index is within bounds of array
 *   length = length of array
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 4, 1)
 *   OUTPUT: [4],[3],[2],[1],
 *
 *   pre: array = {4, -3, 2, -1}
 *   INPUT: (array, 4, 1)
 *   OUTPUT: [-3],[-1],[4],[2],
 *
 *   pre: array = {4, 3, -2, -1}
 *   INPUT: (array, 4, 4)
 *   OUTPUT: [-1],[4],[3],[-2],
 *
 *   pre: array = {1, -2, 0, 4}
 *   INPUT: (array, 4, 3)
 *   OUTPUT: [1],[-2],[0],[4],
 *
 *   pre: array = {1, 2, -3, 4}
 *   INPUT: (array, 3, 4)
 *   OUTPUT: [1],[2],[-3],[4],
 */
void sortOuter(int *array, int length, int index) {

  // base case
  if(index >= length) {
    return;
  }

  sortInner(array, length, index);

  // recursive call with increased index
  sortOuter(array, length, index+1);

}


int main() {

	int nrElements;
  scanf("%d", &nrElements);

  int elements[nrElements];

  for (int i = 0; i < nrElements; i++) {
    scanf("%d", (elements+i));
  }

  for (int i = nrElements-1; i >= 0; i--) {
    printf("%d\n", *(elements+i));
  }

	return 0;
}
