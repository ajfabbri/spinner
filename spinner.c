#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	int j = 100;
	for (i = 0; ; i++) {
		if (i < j) 
			j--;
	}
	return EXIT_SUCCESS;
}

