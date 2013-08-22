default: spinner

spinner: spinner.c
	$(CC) -g -O0 -o spinner spinner.c
clean:
	rm -f spinner 

