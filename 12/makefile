all: temp

temp: main.o temp.o
	gcc -o temp main.o temp.o 
main.o: main.c
	gcc -c -o main.o main.c
temp.o: temp.c
	gcc  -c -o temp.o temp.c
clean:
	rm -rf *.o temp
