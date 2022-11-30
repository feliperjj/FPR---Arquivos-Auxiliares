/*
PROPRIO TOUPPER
*/

int meu_toupper(int ch) {
	if ((ch >= 'a') && (ch <= 'z')) {
		/* é letra minúscula, mudo para maiúscula */
		return (ch - 'a' + 'A');
	}

	/* não é minúscula, mantenho a letra */
	return(ch);
}
