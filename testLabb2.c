#include <stdio.h>

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
