/*
UFPB - CENTRO DE INFORMATICA
DISCIPLINA: ANÁLISE E PROJETO DE ALGORITMOS
AUTOR: BRUNO CORREIA
DATA: 14/03/2018
VERSÃO: 0.001
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// CLASSE MENSAGEM
class mensagem{
public:

	void versao(){
		cout<<"Versão 0.001"<<endl<<endl;
	}

	void ajuda(){
		cout<<"\nUso: ./heapsort [OPÇÕES]\n\nOPÇÕES:\n\n -t [hs|mh]     Tipo da Ordenação. P/ HeapSort -> HS , HeapMax -> HM.\n\n                        Ex.: -t hs | -t hm\n\n -i [Arquivo]   Define o arquivo de entrada, com os valores a serem ordenados.\n\n                        Ex.: -i ./couting.txt | -i ~/ordenar.txt\n\n\n -h      Mostra esta tela de ajuda e sai\n -v      Mostra a versão do programa e sai\n\n\nExemplo completo de uso:\n\n./heapsort -t hs -i entrada.txt\n\n";
	}

	void erro(){
		cout<<"Opção inválida, tente novamente. Use -h para ajuda."<<endl<<endl;
    }
    
};

/* HEAPSORT - INICIO */

void heapify(int arr[], int n, int i)
{
    int largest = i, l = 2*i + 1, r = 2*i + 2;
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i){

        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n){
   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    
    for (int i=n-1; i>=0; i--){
        
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }

}

/* HEAPSORT - FIM */

/* HEAPMAX - INICIO */

void max_heapify(int *a, int i, int n){
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j + 1;
        if (temp > a[j])
            break;
        else if (temp <= a[j]){
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}

void maxHeap(int *a,int n){
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a,i,n);
    }
}

/* HEAPMAX - INICIO */


int main(int argc, char *argv[]){

	mensagem exibir;

	int i, numParametros = argc;

	string	nomePrograma=argv[0], tipo, arquivoEntrada, arquivoSaida;


	if ( numParametros == 2 ){

		if (argv[1][0] == '-' ){

			switch(argv[1][1]){

				case 'v':
				case 'V':
					exibir.versao();
					return 0;
					break;

				case 'h':
				case 'H':
					exibir.ajuda();
					return 0;
					break;

				default:
					exibir.erro();
					return 1;
			}

		}

	} else if ( numParametros == 5 ){

			while ((++argv)[0]){

				if (argv[0][0] == '-' ){

					switch(argv[0][1]){

						case 't':
							tipo = argv[1];
							break;

						case 'i':
							arquivoEntrada = argv[1];
							break;

						default:
							exibir.erro();
							return 1;
					}

				}

			}

		// EXECUTION PROGRAM
		ifstream contar(arquivoEntrada.c_str());

		int N_LINHAS = 0;

		if(!contar.is_open()){
			cout << "Arquivo não pode ser aberto, verifique se o mesmo existe." << "\n\n";
			return 1;
		} else {
			string linha;

			while(getline(contar,linha)){
				++N_LINHAS;
			}

			contar.close();
		}

		int array[N_LINHAS];

		ifstream arquivo(arquivoEntrada.c_str());

		if(!arquivo.is_open()){
			cout << "Arquivo não pode ser aberto, verifique se o mesmo existe." << "\n\n";
			return 1;
		}

		for( i=0 ; i < N_LINHAS ; i++ ){
			arquivo >> array[i];
		}

		arquivo.close();

		if ( tipo == "HS" || tipo == "hs" ) {
			
		    cout << endl << "Heap Sort" << endl << endl;
		    cout << "Antes de ordenar:" << endl;

		    for (int i = 0;i < N_LINHAS; i++)
		        cout << array[i] << " ";

		    cout << endl;

		    heapSort(array,(N_LINHAS-1));

		    cout << endl << "Depois de ordenar:" << endl;
		    for (int i = 0; i < N_LINHAS; i++)
		        cout << array[i] << " ";
		    
		    cout << endl << endl;
		    

		} else if ( tipo == "HM" || tipo == "hm" ){
			
		    cout << endl << "Heap Max" << endl << endl;
		    cout << "Antes de ordenar:" << endl;

		    for (int i = 0;i < N_LINHAS; i++)
		        cout << array[i] << " ";

		    maxHeap(array,(N_LINHAS-1));

		    cout << endl << endl << "Depois de ordenar:" << endl;
		    for (int i = 0;i < N_LINHAS; i++)
		        cout << array[i] << " ";
		    cout << endl << endl;

		} else {

			cout << "Tipo inválido, use" << nomePrograma << " -h para ajuda." << "\n\n";
			return 1;

		}

	} else {

		exibir.erro();
		return 1;
	
	}

	return 0;

}