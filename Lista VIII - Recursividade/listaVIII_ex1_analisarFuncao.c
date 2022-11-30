/*
Questão 01:
Analise a seguinte função recursiva:

int funcao (int A, int B)
{
	if (A >= B)
	{
		return funcao (A-B, B);
	}
	else
	{
		return A;
	}
}

O que é armazenado na variável x quando o
comando x = funcao (32, 6); for executado?
Observação: apresentar a sequência de
chamadas recursivas disparadas pela execução
do comando acima.
*/

//Resposta: A função irá diminuir A de B até que B seja maior que A, e consequentemente, A menor que B, não podendo ocorrer mais divisões.
