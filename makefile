all: lab2 
lab2: main.c intVector.c 
 gcc -Wall -o lab2 main.c intVector.c 
clean: 
 rm lab2 
run: 
 ./lab2