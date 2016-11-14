#include <stdio.h>	// Input-Output requests

int main(int argc, char** argv) {
	char *paren = argv[1];
	int counter = 0; // Counters for these
	
	while (*paren != '\0') {
		switch(*paren) {
			case '{':
				counter++;
				break;
			case '(':
				counter++;
				break;
			case '[':
				counter++;
				break;
			case '}':
				counter--;
				break;
			case ')':
				counter--;
				break;
			case ']':
				counter--;
				break;
		}
		paren++;	
	}

	if (counter == 0)
		printf("String is balanced\n");
	else
		printf("String is not balanced.\n");		
		
	return 0;	// Successfully quit.
}
