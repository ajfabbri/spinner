#include <stdlib.h>


#define LOG2_BUSY_LOOP_ITER	18	/* 2^x iterations, then sleep */
#define USLEEP_VAL		2

int main(int argc, char *argv[])
{
	unsigned long i;
	int j = 100;
	for (i = 0; ; i++) {
		if (i < j) 
			j--;
		if ((i & ((1<<12)-1)) == 0) 
			usleep(USLEEP_VAL);
	}
	return EXIT_SUCCESS;
}

