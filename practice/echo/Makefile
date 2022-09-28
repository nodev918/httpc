run-server: server
	./server

server: server.o
	gcc -o server $^

server.o: server.c Makefile
	gcc -c -o server.o server.c 


run-client: client
	./client

client: client.o
	gcc -o client $^

client.o: client.c Makefile
	gcc -c -o client.o client.c 

clean:
	rm -rf *.o
