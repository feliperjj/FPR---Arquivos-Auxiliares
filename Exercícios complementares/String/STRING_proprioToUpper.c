/*
PROPRIO TOUPPER
*/

int meu_toupper(int ch) {
	if ((ch >= 'a') && (ch <= 'z')) {
		/* � letra min�scula, mudo para mai�scula */
		return (ch - 'a' + 'A');
	}

	/* n�o � min�scula, mantenho a letra */
	return(ch);
}
