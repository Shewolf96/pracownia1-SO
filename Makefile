all:
	gcc -o main main.c -pthread
run:
	./main
clean:
	rm -f main
