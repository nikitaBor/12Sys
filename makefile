all: fork.c
	gcc fork.c

clean:
	rm *~
	rm a.out

run: all
	./a.out
