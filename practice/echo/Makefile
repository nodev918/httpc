run: server
	./echo

server: echo.o
	gcc -c -o echo $^

echo.o: echo.c
	gcc -c -o echo.o echo.c
