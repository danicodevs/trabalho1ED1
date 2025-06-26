EXEC = prog
RM = rm -f
ifeq ($(OS),Windows_NT)
    RM = del
    EXEC = prog.exe
endif
all: compila executa
compila: main.o listaDuplamenteEnc.o registroDeHumor.o 
	gcc main.o listaDuplamenteEnc.o registroDeHumor.o -o $(EXEC)
main.o: main.c
	gcc -c main.c
listaDuplamenteEnc.o: listaDuplamenteEnc.c
	gcc -c listaDuplamenteEnc.c
registroDeHumor.o: registroDeHumor.c
	gcc -c registroDeHumor.c
executa:
	./$(EXEC)
clean:
	$(RM) main.o listaDuplamenteEnc.o registroDeHumor.o $(EXEC)