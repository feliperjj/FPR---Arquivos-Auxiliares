/*
Quest�o 01:
Analise a seguinte fun��o recursiva:

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

O que � armazenado na vari�vel x quando o
comando x = funcao (32, 6); for executado?
Observa��o: apresentar a sequ�ncia de
chamadas recursivas disparadas pela execu��o
do comando acima.
*/

//Resposta: A fun��o ir� diminuir A de B at� que B seja maior que A, e consequentemente, A menor que B, n�o podendo ocorrer mais divis�es.
