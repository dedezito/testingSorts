# Teste e Comparação de Algoritmos de Ordenação

## O que é?

O presente projeto faz parte de um estudo acadêmico dirigido que, como o nome sugere, visa o teste e comparação de diferentes tipos de algoritmos de ordenação, de modo que se possa relacionar sua complexidade computacional com seu tempo de execução. Para tal, este programa gera um vetor desordenado aleatoriamente e cronometra o tempo necessário para cada algoritmo ordená-lo. O tamanho do vetor é selecionado pelo usuário no início da execução do programa, permitindo maior versatilidade aos testes.

## Como funciona?

### O gerador de vetor aleatório (função vetorAleatorio)

Primeiramente, o programa pede para que o usuário forneça um valor númerico natural entre 1 e 10.000.000 para definir o tamanho do vetor a ser criado.

Em seguida, é gerado um número aleatório não-determinístico através da classe _random_device_, que será utilizado como semente para um gerador de números pseudoaleatórios da classe _mt19937_. Esse passo é importante, pois embora seja possível utilizar o _random_device_ para gerar os números aleatórios do vetor por conta própria, é muito mais viável em termos de velocidade e recursos computacionais utilizá-lo apenas como gerador de semente aleatória para o _mt19937_.

Depois disso, é gerado um inteiro distribuído uniformemente através da classe _uniform_int_distribution_, que é utilizado para mapear o intervalo de números que serão obtidos a partir do gerador de números pseudoaleatórios. Por questões de praticidade, foi decidido que o intervalo iria sempre do 0 até o tamanho do vetor, permitindo uma variabilidade adequada para os números. É importante ressaltar que sem a distribuição não é possível gerar os números pseudoaleatórios, já que é ela quem retorna os valores númericos propriamente ditos através de uma função.

Por fim, é feito um _loop_ para iterar pelas posições do vetor e assim preenchê-lo com os valores pseudoaleatórios. A função então retorna o vetor e o programa prossegue para a próxima etapa.

### O bubble sort (função bubbleSort)

O _bubble sort_ se trata de um algoritmo de ordenação conhecido por sua baixa eficiência computacional. Ele inicia sua análise comparando o primeiro elemento da lista que o é passado com o segundo elemento. Se o primeiro elemento for maior que o segundo, os dois trocam de lugar. Isso se repete com cada posição da lista até que o maior número suba como uma bolha de ar em um copo d'água até o topo (por isso o nome _"bubble" sort_). Como esse processo de iteração só garante que um dos números seja colocado em sua posição de cada vez, é necessário que isso se repita para cada elemento que houver na lista.

### O selection sort (função selectionSort)

O _selection sort_ é um algoritmo de ordenação que se baseia em selecionar o menor número dentro da lista e colocá-lo na posição mais à esquerda. Alternativamente, o mesmo também pode ser feito selecionando o maior número e colocando-o na posição mais à direita. Para resumir seu funcionamento na prática, o programa inicia iterando pelos elementos da lista, guardando na memória a posição do de menor valor. Ao final da primeira iteração, ele troca de lugar o elemento que está na primeira posição (index 0) pelo de menor valor. Esse processo se repete para cada posição da lista, com cada iteração subsequente ignorando o último elemento ordenado durante a busca e trocando o elemento de menor valor encontrado pelo da posição à frente da última.

### O insertion sort (função insertionSort)

O _insertion sort_ é um algoritmo de ordenação que funciona colocando iterativamente cada elemento da lista em sua posição correta. Ele inicia o seu funcionamento a partir do segundo elemento da lista, o qual chamaremos de chave (ou _key_), e vai o comparando com todos os elementos que estão à sua esquerda. Sempre que o programa identifica um elemento maior que o da chave à sua esquerda, este é movido uma posição para a direita. Ao final de cada iteração, o valor da chave é colocado na antiga posição do último elemento movido, inserindo-a em sua posição correta. Isto é feito com cada elemento da lista.

### O shell sort (função shellSort)

O _shell sort_ é basicamente um algoritmo de ordenação que busca servir como uma melhoria ao sistema implementado pelo _insertion sort_. Nele, o algoritmo inicia sua execução definindo um espaçamento (ou _gap_) que dita quais elementos serão considerados para o código durante esta iteração. O programa então deverá ordenar os elementos selecionados entre si, ignorando todos os demais. Utilizando esse mesmo espaçamento, o progrma deverá passar por todas as posições da lista. Toda vez que uma iteração é concluída, o programa reduz o tamanho do espaçamento até que o espaçamento seja igual a 1.

### O quick sort (funções quickSort, partition e swap)

O _quick sort_ é um dos algoritmos de ordenação conhecidos por usar uma estratégia conhecida como "dividir para conquistar". Ele inicia sua execução determinando um elemento para ser o "pivô", que será utilizado como base para todas as comparações de cada etapa. Esse pivô pode ser determinado de diversas formas diferentes, mas uma das mais comuns é escolhendo o último elemento disponível da lista. Assim que o pivô é escolhido, o algoritmo deverá iterar pelos elementos da lista, colocando aqueles que são menores que o pivô para a esquerda e os que são maiores para a direita. Depois disso, o programa divide a lista em duas, uma referente aos elementos à esquerda do pivô e uma referente aos elementos à direita do pivô. O processo então se repete para cada uma das listas menores até que a lista inteira seja ordenada.

### O merge sort (funções mergeSort e merge)

O _merge sort_ é outro dos algoritmos de ordenação que se baseia na estratégia de "dividir para conquistar". Nesse algoritmo de ordenação, o primeiro passo a ser feito é dividir a lista a ser ordenada em duas partes, e dividir cada uma dessas partes recursivamente até que a lista se transforme em conjunto de várias listas de um elemento cada. Após isso, o programa irá comparar duas listas de cada vez para mesclá-las em uma única lista ordenada. Ele faz isso iterando pelas duas listas ao mesmo tempo e checando em que ordem que os números devem ser adicionados à lista mesclada.

### O cronômetro (biblioteca <sys/time.h>)

Como mencionado anteriormente, esse projeto tem como foco a comparação do tempo de execução de um grupo seleto de algoritmos de ordenação, e para tal, era necessário encontrar meios de encontrar esses valores dentro do código. Sendo assim, devido à sua alta precisão de medida, foi selecionada a biblioteca _<sys/time.h>_ para realizar a cronometragem de cada aplicação.

Na prática, a implementação do cronômetro foi feita da seguinte forma: primeiramente, são criados dois objetos da classe _timeval_ que serão utilizados pela função _gettimeofday_ para armazenar o momento de início e fim de cada algoritmo. Como as informações referentes aos segundos e microssegundos são armazenados em atributos diferentes dos objetos (_tv_sec_ e _tv_usec_), é necessário converter os segundos para microssegundos para que se possa somar os dois valores. Por fim, basta calcular a diferença do momento de início e fim do algoritmo e converter o resultado para segundos (para melhor compreensão).