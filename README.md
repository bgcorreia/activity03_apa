# Activity 03 - APA - UFPB

## Description

This project intends to implement the ordering algorithm Heap and Max Heap Sort in C ++.

## Compilation/Linker

To compile/linker execute `make` in the clone directory.

Example:

```bash
user@host:~/activity03_apa$ make
Compilando arquivo objeto: heapsort
user@host:~/activity03_apa$
```

## Execution

Then, execute the generated binary:

```bash
user@host:~/activity03_apa$ ./heapsort -h

Uso: ./heapsort [OPÇÕES]

OPÇÕES:

 -t [ms|qs]     Tipo da Ordenação. P/ HeapSort -> HS , MaxHeap -> HM.

                        Ex.: -t hs | -t hm

 -i [Arquivo]   Define o arquivo de entrada, com os valores a serem ordenados.

                        Ex.: -i ./couting.txt | -i ~/ordenar.txt
                        

 -h      Mostra esta tela de ajuda e sai
 -v      Mostra a versão do programa e sai
 
   
Exemplo completo de uso:

./heapsort -t hs -i entrada.txt 
```
