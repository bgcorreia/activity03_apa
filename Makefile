all: heapsort

heapsort: heapsort.cpp
	@echo "Compilando arquivo objeto: heapsort"
	@g++ -o heapsort heapsort.cpp

install: heapsort
	@echo "Instalando no Sistema."
	@sudo cp heapsort /usr/local/bin/heapsort

clean:
	@echo "Limpando arquivos"
	-@rm -f heapsort
