# Trabalho II de CPDA
#### Relatório da implementação dos algoritmos de transformação de chave hashing em C++ Cefet-MG Campus Leopoldina Minas Gerais Disciplina de Classificação e pesquisa de dados Ministrada pelo Professor Cleiston Silva.
Feito por: Lucas Thomaz Pimentel e Michael André Souza da Costa

## **Experimento I**
**1) Introdução**
<p align="justify"> Foram implementados 2 algoritmos de transformação de chave (hashing) usando listas encadeadas e endereçamento aberto. Esses algoritmos são usados para tentar diminuir a ocorrência de colisões. O endereçamento aberto funciona da seguinte forma. Um certo valor passa pela função hash, e é gerado um valor hash e seu endereço, ele verifica se o endereço está vazio ou não, caso esteja ocupado quer dizer que ocorreu uma colisão. Para resolver isso, ele procura na posição seguinte se está vazia, se estiver, o valor é armazenado se não ele continua até procurar uma posição vazia. Esse processo ocorre também para a busca de um elemento. Na lista encadeada temos uma tabela hash que tem apenas ponteiros que apontam para uma lista linear onde os dados serão armazenados que cresce com a necessidade. Se ao armazenar um dado, a posição estiver ocupada, se cria um novo nó no final da lista.
</p>

**2) Desenvolvimento**
<p align="justify"> Para o endereçamento aberto foram utilizados N < M sendo que N é o intervalo dos valores gerados aleatoriamente, e M é o tamanho do vetor de (hashing). E a lista encadeada M > N sendo que M é tamanho do vetor e P o range de valores gerados aleatoriamente. Os resultados se encontram em segundos na tabela a seguir.
</p>

|      Algoritmos      | Inserindo | Mostrando |
|:--------------------:|-----------|-----------|
| Endereçamento aberto | 0.000265  | 0.040369  |
| Lista encadeada      | 0.000583  | 0.040121  |


**3) Conclusão**
<p align="justify">Foi observado que o endereçamento aberto teve um menor tempo na inserção comparado com a lista encadeada visto que sua inserção se dá através da geração de hash que representa um índice que é armazenado o endereço da hash na tabela. Já na lista encadeada, temos uma Head que é a tabela hash com ponteiros que apontam para outra tabela, levando ao maior tempo de inserção. A lista encadeada é mais rápida na busca, pois temos uma uma tabela hash já com os ponteiros que apontam para as hash armazenadas. Houveram oscilações nos tempos aferidos, às vezes os valores se inverteram, mas esses dados foram o de maior ocorrência em nossos experimentos.</p>

## **Experimento II**
**1) Introdução**
<p align="justify">
Foram implementados 2 algoritmos do tipo árvore. Árvore binária de busca balanceada (AVL) e desbalanceada. A ideia geral da árvore binária sem balanceamento é que a cada valor inserido na árvore um nó é criado é feito uma comparação que começa na raiz verificando se o valor que queremos inserir é menor ou maior que o nó atual, se formos maior vai para a direita e se for menor vai para a esquerda, assim se concentrando os elementos maiores que o valor da raiz na direita e os menores a esquerda. Seu problema é que podemos ter uma árvore degenerada que é quando temos apenas um dos lados da árvore preenchido formando apenas um vetor linear. A árvore AVL tem uma característica muito importante que é seu balanceamento que a cada inserção e remoção é feita uma verificação para vermos se o balanceamento permanece caso houver o desbalanceamento, rotações são feitas nos nós para mantermos sua propriedade. </p>

**2) Desenvolvimento**
<p align="justify">
Para a árvore de busca binária foram utilizados N < M sendo que N é o intervalo de valores aleatoriamente que está sendo gerado e M é o tamanho da árvore, assim como na árvore binário de busca balanceada. Os resultados se encontram em segundos na tabela a seguir. </p>

|     Algoritmos    | Inserindo | Mostrando | Removendo |
|:-----------------:|-----------|-----------|-----------|
| Árvore Binária    | 0.000292  | 0.000202  | 0.000130  |
| Árvore Balanceada | 0.000382  | 0.000173  | 0.000193  |

**3) Conclusão**
<p align="justify">
Foi observado que utilizando a árvore binária não balanceada houve um menor tempo na inserção, porém na busca ela demandou um tempo maior comparado a árvore binária de busca balanceada a qual na inserção demandou um pouco mais de tempo devido a comparação que ela realiza para manter o balanceamento, fazendo com que seu tempo de busca seja melhor devido a maneira a qual ela trabalha com as inserções otimizando a busca. A árvore binária desbalanceada teve um melhor tempo na remoção dos elementos pois como ele não tem o balanceamento, após removermos um nó, o nó antecessor apontará para o sucessor do nó removido apenas. Já a árvore balanceada, após removermos um nó, deverá ser feita a verificação se a regra do balanceamento se mantém, senão, o balanceamento ocorre a fim de manter sua regra. Para o valor de N e M igual a 99954 e N igual a 10000. Houveram oscilações nos tempos aferidos, às vezes os valores se inverteram, mas esses dados foram o de maior ocorrência em nossos experimentos. </p>

## Referências
ASCENCIO, Ana Fernanda Gomes; ARAÚJO, Graziela Santos de. Estruturas de Dados: algoritmos, análise da complexidade e implementações em JAVA e C/C++. **São Paulo: Perarson Prentice Halt**, v. 3, 2010.
