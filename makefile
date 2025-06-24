all: compila
compila: main.o listaDuplamenteEnc.o registroDeHumor.o 
	gcc main.o listaDuplamenteEnc.o registroDeHumor.o -o prog
main.o: main.c 
	gcc -c main.c
listaDuplamenteEnc.o: listaDuplamenteEnc.c
	gcc -c listaDuplamenteEnc.c
registroDeHumor.o: registroDeHumor.c
	gcc -c registroDeHumor.c
clean:
	del main.o listaDuplamenteEnc.o registroDeHumor.o prog.exe