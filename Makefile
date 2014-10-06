FLAGS = gcc -std=c99 -ggdb -Wall


resplan: resplan.c myListModule.h
	$(FLAGS) -o resplan resplan.c

run: 
	./resplan

.PHONY: run
