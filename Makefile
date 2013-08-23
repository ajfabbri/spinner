default: spinner

spinner: spinner.c
	$(CC) -Wall -g -O0 -o spinner spinner.c
clean:
	rm -f spinner 

