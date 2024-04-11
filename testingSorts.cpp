#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <sys/time.h>
#include <iomanip>

using namespace std;

//função para criar vetor aleatório
vector<int> vetorAleatorio() {
    //seta o tamanho maximo do vetor
    int tamanhoVetor;
    cout << "Insira o tamanho do vetor: ";
    cin >> tamanhoVetor;
    vector<int> vetorOriginal(tamanhoVetor);
	cout<<endl;

    //gera um numero pseudoaleatorio
    random_device seed;

    //o algoritmo que calcula numeros aleatorios recebe uma semente aleatoria
    //cria-se o "geradorNum()" o objeto da classe mt19937 (que tem o algoritmo pra fazer os calculos dos numeros aleatorios)
    mt19937 geradorNum(seed());

    //vai gerar um inteiro distribuido uniformemente no intervalo fornecido
    uniform_int_distribution<int> range(0, tamanhoVetor);

    for (int i = 0; i < tamanhoVetor; i++)
    {
        int elemento = range(geradorNum);
        vetorOriginal[i] = elemento;
    }
    return vetorOriginal;
}

//função para trocar elementos
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//--------------------------------algoritmos de ordenação---------------------------
//+++++++++++++++++++++++merge sort++++++++++++++++++++++++++++++
void merge(vector<int> &v, int low, int high, int mid ) {
	int i, j, k;
	static int c[10000000];
	i = low;
	k = low;
	j = mid + 1;
    	while (i <= mid && j <= high) {
        	if (v[i] < v[j]) {
            		c[k] = v[i];
            		k++;
            		i++;
        	}
        	else{
            		c[k] = v[j];
            		k++;
            		j++;
        	}
    	}
    	while (i <= mid) {
        	c[k] = v[i];
        	k++;
        	i++;
    	}
    	while (j <= high) {
        	c[k] = v[j];
        	k++;
        	j++;
    	}
    	for (i = low; i < k; i++) {
        	v[i] = c[i];
    	}
}

void mergeSort(vector<int> &v, int low, int high) {
	if(low<high) {
		int mid;
		mid = (low+high)/2;
		mergeSort(v, low, mid);
		mergeSort(v, mid+1, high);
		merge(v,low,high,mid);
	}

}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++quick sort++++++++++++++++++++++++++++++
int partition(vector<int> &v, int low, int high) {
	int pivot = v[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (v[j] < pivot) {
			i++;
			swap(&v[i], &v[j]);
		}
	}
	swap(&v[i + 1], &v[high]);
	return (i + 1);
}

void quickSort(vector<int> &v, int low, int high) {
	if (low < high) { 
		int pi = partition(v, low, high);
		quickSort(v, low, pi - 1);
		quickSort(v, pi + 1, high);
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




//shell sort
void shellSort(vector<int> &v) {
	/*
		Parametros:
		v = vetor de entrada para ser ordenado
	*/
	int n=v.size();
	for (int h=n/2; h>0;h/=2) {
		for (int i=h;i<n;i+=1) {
			int temp=v[i];
			int j;
			for (j=i;j>=h && v[j-h]>temp;j-=h)
				v[j]=v[j-h];
			v[j]=temp;
		}
	}
}

//insertion sort O(n²)
void insertionSort(vector<int> &v) {
	/*
		Parametros:
		v = vetor de entrada para ser ordenado
	*/
	int n=v.size();
	int i,key,j;
	for(i=1;i<n;i++) {
		key=v[i];
		j=i-1;
		while(j>=0&&v[j]>key) {
			v[j+1]=v[j];
			j=j-1;
		}
		v[j+1]=key;
	}
}


//bubble sort O(n²)
void bubbleSort(vector<int> &v) {
	/*
		Parametros:
		v = vetor de entrada para ser ordenado
	*/
	int n=v.size();
	for(int i=0;i<n-1;i++) {
		for (int j=0;j<n-i-1;j++) {
			if(v[j]>v[j+1]) {
				int temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			} 
		}
	}
}

//selection sort O(n²)
void selectionSort(vector<int> &v) {
	/*
		Parametros:
		v = vetor de entrada a ser ordenado
	*/
	int min_idx;
	int n=v.size();
	for(int i=0;i<n-1;i++) {
		min_idx=i;
		for(int j=i+1;j<n;j++) {
			if(v[j]<v[min_idx])
				min_idx=j;
		}
		if(min_idx!=i) {
			int temp=v[min_idx];
			v[min_idx]=v[i];
			v[i]=temp;
		}
	}
}

//função principal
int main() {
	//cria um vetor aleatório para ser ordenado
	vector<int> v = vetorAleatorio();
    vector<int> w;
	//cria variáveis para para armazenar o momento de início e fim de cada algoritmo
	struct timeval inicio, fim;
	double tempoTotal;

	//configura um número fixo de 6 casas decimais a serem mostradas em valores do tipo double
	cout << fixed;
	cout << setprecision(6);
    
	//armazena os valores do vetor aleatorio em uma variavel temporaria para cada teste
    w = v;
	//armazena o horario referente ao inicio da execução do algoritmo
	gettimeofday(&inicio,NULL);
	bubbleSort(w);
	//armazena o horario referente à conclusão da execução do algoritmo
	gettimeofday(&fim,NULL);
	//calcula e armazena a diferença entre o horário de inicio e fim da execução do algoritmo para encontrar o tempo de execução (em microssegundos)
	tempoTotal = ((fim.tv_sec - inicio.tv_sec) * 1000000) + (fim.tv_usec - inicio.tv_usec);
	//converte o tempo de execução de microssegundos para segundos
	tempoTotal = tempoTotal/1000000;
	cout<<"Tempo decorrido no Bubble Sort: "<<tempoTotal<<" segundos."<<endl<<endl;

    w = v;
	gettimeofday(&inicio,NULL);
	selectionSort(w);
	gettimeofday(&fim,NULL);
	tempoTotal = ((fim.tv_sec - inicio.tv_sec) * 1000000) + (fim.tv_usec - inicio.tv_usec);
	tempoTotal = tempoTotal/1000000;
	cout<<"Tempo decorrido no Selection Sort: " <<tempoTotal<<" segundos."<<endl<<endl;

    w = v;
	gettimeofday(&inicio,NULL);
	insertionSort(w);
	gettimeofday(&fim,NULL);
	tempoTotal = ((fim.tv_sec - inicio.tv_sec) * 1000000) + (fim.tv_usec - inicio.tv_usec);
	tempoTotal = tempoTotal/1000000;
	cout<<"Tempo decorrido no Insertion Sort: "<<tempoTotal<<" segundos."<<endl<<endl;

    w = v;
	gettimeofday(&inicio,NULL);
	shellSort(w);
	gettimeofday(&fim,NULL);
	tempoTotal = ((fim.tv_sec - inicio.tv_sec) * 1000000) + (fim.tv_usec - inicio.tv_usec);
	tempoTotal = tempoTotal/1000000;
	cout<<"Tempo decorrido no Shell Sort: "<<tempoTotal<<" segundos."<<endl<<endl;

    w = v;
	gettimeofday(&inicio,NULL);
	quickSort(w,0,w.size()-1);
	gettimeofday(&fim,NULL);
	tempoTotal = ((fim.tv_sec - inicio.tv_sec) * 1000000) + (fim.tv_usec - inicio.tv_usec);
	tempoTotal = tempoTotal/1000000;
	cout<<"Tempo decorrido no Quick Sort: "<<tempoTotal<<" segundos."<<endl<<endl;
	
    w = v;
	gettimeofday(&inicio,NULL);
	mergeSort(w,0,w.size()-1);
	gettimeofday(&fim,NULL);
	tempoTotal = ((fim.tv_sec - inicio.tv_sec) * 1000000) + (fim.tv_usec - inicio.tv_usec);
	tempoTotal = tempoTotal/1000000;
	cout<<"Tempo decorrido no Merge Sort: "<<tempoTotal<<" segundos."<<endl<<endl;
    
    int sair;
    cout<<"Pressione qualquer numero + enter pra sair: ";
    cin>>sair;

	return 0;
}