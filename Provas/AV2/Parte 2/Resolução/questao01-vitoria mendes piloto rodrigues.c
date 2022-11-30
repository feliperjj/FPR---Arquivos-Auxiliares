/*
Questão 01 [2,5 pontos]:
Pede-se a descrição de um algoritmo (não precisa
implementar) que, dados uma fila F e uma pilha P,
ambas do tipo TLista, determine o número de
elementos iguais entre as duas estruturas.
Observações: as regras de manipulação destas estruturas
(implementação clássica) devem ser respeitadas. Ou seja,
apenas o topo é acessível na pilha, assim como os
elementos extremos da fila (em um lado, remoção; no
outro, inserção). Caso alguma estrutura de dados
auxiliar seja necessária, deverá obrigatoriamente ser
uma pilha ou uma fila.
*/

	1° passo: criar uma lista genérica contendo valor e prox
	2° passo: criar função empilhar
	3° passo: criar função enfilar
	4° passo: armazenar o primeiro valor da pilha
	5° passo: armazenar o primeiro valor da fila
	5° passo: conferir se o primeiro valor da pilha é o primeiro elemento da fila
		5.1 passo: se for
		 5.1.1 passo: somar mais um na quantidade de elementos daquele valor lido
	5.2 passo: guardar esse primeiro valor de topo
	5.3. passo: guardar esse primeiro elemento da fila (original)
	//Começar a manipular os elementos da pilha e fila (ou filha) kksksksk
	5.4 passo: enquanto o topo da pilha não for o primeiro topo (o topo antigo)
		5.4.1 passo: levar o topo atual da pilha ao final
		5.4.2 passo: comparar o novo topo com o primeiro elemento da fila
		 // o topo vai se atualizando, o segundo elemento da pilha torna-se o novo topo, pois o atual vai para o final, assim:
	5.5 passo: quando o topo voltar ao primeiro elemento (que foi armazenado no começo do algoritmo)
		//agora andar com os elementos da fila e realizar a comparação inversa
		5.5.1 enquanto o primeiro elemento da fila não for o primeiro elemento antigo da fila (original)
		5.5.2 passo: comparar se o primeiro elemento da fila é igual ao primeiro elemento da pilha
		5.5.3 passo: se for, levar para o final da fila o até então primeiro elemento
		 											... Assim sucetivamente ...
	
	RESUMINDO: andar com os elementos da pilha e fila para o final, respeitando suas condições e então ir comparando os 
	que estão no topo da pilha com o do começo da fila e trocá-los de posição após as comparações, levando em consideração que, se o número for igual 
	ou não, apenas a pilha ou a fila deverão andar e se caso seja igual, atualizar o contador. Ir nesse fluxo, até que chegue tanto ao final da pilha quanto no final da fila (ambos em suas posições) 
	iniciais e que todos estejam percorridos.
