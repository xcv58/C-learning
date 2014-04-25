all: 
	gcc -c hello.c && gcc hello.o -o hello

gdb: 
	gcc -c -g hello.c && gcc hello.o -o hello

pipe: 
	gcc -DPIPE -c hello.c && gcc hello.o -o hello

clean:
	-rm -rf *.o a.out hello test *.dSYM 
