# Variáveis de compilação
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11
OBJ = prog16.o splitFields.o separator_unify.o strcmp_ic.o errors.o
TARGET = prog16

# Regra principal: Compila o executável
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regras para os ficheiros objeto
prog16.o: prog16.c splitFields.h separator_unify.h strcmp_ic.h errors.h
	$(CC) $(CFLAGS) -c prog16.c

splitFields.o: splitFields.c splitFields.h
	$(CC) $(CFLAGS) -c splitFields.c

separator_unify.o: separator_unify.c separator_unify.h
	$(CC) $(CFLAGS) -c separator_unify.c

strcmp_ic.o: strcmp_ic.c strcmp_ic.h
	$(CC) $(CFLAGS) -c strcmp_ic.c

errors.o: errors.c errors.h
	$(CC) $(CFLAGS) -c errors.c

# Limpeza de ficheiros temporários
clean:
	rm -f $(TARGET) *.o test_input.txt

# Regra de teste automatizada
test: all
	@echo ">>> Criando ficheiro de teste..."
	@echo "ISEL ; Lisboa" > test_input.txt
	@echo "  isel  ; Porto" >> test_input.txt
	@echo "Engenharia ; Faro" >> test_input.txt
	@echo "Isel; Coimbra" >> test_input.txt
	@echo "Outra Coisa; Braga" >> test_input.txt
	@echo ">>> Executando prog16 (Filtro: Campo 1, valor 'isel')..."
	@echo ">>> Resultado esperado: As linhas que contêm ISEL/isel no 1º campo."
	@echo "--------------------------------------------------"
	./$(TARGET) 1 "isel" < test_input.txt
	@echo "--------------------------------------------------"
	@rm test_input.txt