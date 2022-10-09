# Nome do projeto
PROJ_NAME=Forca

# Arquivos .c
C_SOURCE=$(wildcard *.c)

# Arquivos .h
H_SOURCE=$(wildcard *.h)

# Arquivos .o (Object files)
OBJ=$(C_SOURCE:.c=.o)

# Nome do compilador
CC=gcc

# Flags para o compilador
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -ansi      \
         -pedantic	\
         -std=c11

#
# Compilação e linking
#
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

main.o: main.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf *.o $(PROJ_NAME) *~