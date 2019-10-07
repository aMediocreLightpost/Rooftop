#include <stdio.h>

int main() {

	char c;

	while(c != EOF) {
		c = getchar();

		if(c == 'a') {
			putchar('X');
		} else {
			putchar(c);
		}

	}

	return 0;
}
