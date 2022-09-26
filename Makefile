run: bin
	@rm -rf src/*.o
	bin/httpc

bin: src/main.o src/httpd.o
	mkdir -p bin
	gcc -o bin/httpc $^

main.o: src/main.c src/httpd.h
	gcc -c -o src/main.o src/main.c

httpd.o: src/httpd.c src/httpd.h
	gcc -c -o src/httpd.o src/httpd.c


clean:
	@rm -rf src/*.o
	@rm -rf bin

git: clean
	echo git
	git add .
	git commit -m "makefile commit"
	git push