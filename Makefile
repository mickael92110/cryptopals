CC=gcc
CFLAGS=-Wall -O
LDFLAGS=
EXEC=exec
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)


all: $(EXEC)

exec: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: challenge_1.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o core

mrproper: clean
	rm -f $(EXEC)
