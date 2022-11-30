/*
Quest�o 01 [2,5 pontos]:
Pede-se a descri��o de um algoritmo (n�o precisa
implementar) que, dados uma fila F e uma pilha P,
ambas do tipo TLista, determine o n�mero de
elementos iguais entre as duas estruturas.
Observa��es: as regras de manipula��o destas estruturas
(implementa��o cl�ssica) devem ser respeitadas. Ou seja,
apenas o topo � acess�vel na pilha, assim como os
elementos extremos da fila (em um lado, remo��o; no
outro, inser��o). Caso alguma estrutura de dados
auxiliar seja necess�ria, dever� obrigatoriamente ser
uma pilha ou uma fila.
*/

	1� passo: criar uma lista gen�rica contendo valor e prox
	2� passo: criar fun��o empilhar
	3� passo: criar fun��o enfilar
	4� passo: armazenar o primeiro valor da pilha
	5� passo: armazenar o primeiro valor da fila
	5� passo: conferir se o primeiro valor da pilha � o primeiro elemento da fila
		5.1 passo: se for
		 5.1.1 passo: somar mais um na quantidade de elementos daquele valor lido
	5.2 passo: guardar esse primeiro valor de topo
	5.3. passo: guardar esse primeiro elemento da fila (original)
	//Come�ar a manipular os elementos da pilha e fila (ou filha) kksksksk
	5.4 passo: enquanto o topo da pilha n�o for o primeiro topo (o topo antigo)
		5.4.1 passo: levar o topo atual da pilha ao final
		5.4.2 passo: comparar o novo topo com o primeiro elemento da fila
		 // o topo vai se atualizando, o segundo elemento da pilha torna-se o novo topo, pois o atual vai para o final, assim:
	5.5 passo: quando o topo voltar ao primeiro elemento (que foi armazenado no come�o do algoritmo)
		//agora andar com os elementos da fila e realizar a compara��o inversa
		5.5.1 enquanto o primeiro elemento da fila n�o for o primeiro elemento antigo da fila (original)
		5.5.2 passo: comparar se o primeiro elemento da fila � igual ao primeiro elemento da pilha
		5.5.3 passo: se for, levar para o final da fila o at� ent�o primeiro elemento
		 											... Assim sucetivamente ...
	
	RESUMINDO: andar com os elementos da pilha e fila para o final, respeitando suas condi��es e ent�o ir comparando os 
	que est�o no topo da pilha com o do come�o da fila e troc�-los de posi��o ap�s as compara��es, levando em considera��o que, se o n�mero for igual 
	ou n�o, apenas a pilha ou a fila dever�o andar e se caso seja igual, atualizar o contador. Ir nesse fluxo, at� que chegue tanto ao final da pilha quanto no final da fila (ambos em suas posi��es) 
	iniciais e que todos estejam percorridos.
