run: bin
	fold/hello

bin: fold/hello.o
	gcc -o fold/hello $^

hello.o: fold/hello.c
	gcc -c -o fold/hello.o fold/hello.c