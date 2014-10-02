
resplan: resplan.c
	gcc -std=c99 -ggdb -Wall -o resplan resplan.c

run: 
	./resplan

.PHONY: run
