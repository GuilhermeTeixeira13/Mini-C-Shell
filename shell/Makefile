#A Simple Example Makefile for soshell
#
# Syntax:
# Alvo: Dependencias
# tab Action 1
# tab Action 2
#
# Variaveis: Compiler, compiler flags, libraries to link, name of of object files
#
CC=cc
FLAGS=-c -Wall
LIBS=-lm -lpthread 
OBS=main.o execute.o parse.o socp.o redirects.o aviso.o socpth.o filesize.o listar.o calc.o imageType.o

#Alvo por defeito é o primeiro
all :  soshell

main.o : shell.h main.c
	$(CC) $(FLAGS) main.c
execute.o : shell.h execute.c
	$(CC) $(FLAGS) execute.c
filesize.o : shell.h filesize.c
	$(CC) $(FLAGS) filesize.c
calc.o : shell.h calc.c
	$(CC) $(FLAGS) calc.c
imageType.o : shell.h imageType.c
	$(CC) $(FLAGS) imageType.c
listar.o : shell.h listar.c
	$(CC) $(FLAGS) listar.c
parse.o : shell.h parse.c
	$(CC) $(FLAGS) parse.c
aviso.o : shell.h aviso.c
	$(CC) $(FLAGS) aviso.c
socpth.o : shell.h socpth.c
	$(CC) $(FLAGS) socpth.c
redirects.o : shell.h redirects.c
	$(CC) $(FLAGS) redirects.c
soshell : $(OBS)
	$(CC)  -o soshell  $(OBS) $(LIBS)
socp.o : shell.h socp.c
	$(CC) $(FLAGS) socp.c
clean limpar:
	rm -f soshell *.o
	rm -f *~
	echo "Limpeza dos ficheiros exectuaveis, objectos e gedit tralha"
