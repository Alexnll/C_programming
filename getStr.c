/* print each line of its input */
/* that contains a particular "pattern"*/
/* or string of character. */
#include <stdio.h>
#define MAXLINE 1000          /* maximum line */

char pattern[] = "play";      /* the pattern we want to serach */

int getTheLine(char line[], int maxline);     /* read a line and return the length of the line */
int strInLine(char line[], char pattern[]);  /* return the index of pattern appeared */

int main(){
	char line[MAXLINE];
	int found = 0;

	while(getTheLine(line, MAXLINE) > 0){               /* Still no-process lines existed */
		if(strInLine(line, pattern) >= 0){  /* If the pattern in the line */
			printf("%d) %s\n", found, line);     /* print the line */
		}
		found++;
	}
	return found;
}

/* read a line and return the length of the line */
int getTheLine(char line[], int restLine){
	int c, i;

	i = 0;
	while(--restLine > 0 && (c = getchar()) != EOF &&  c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

/* return the index of pattern appeared */
int strInLine(char line[], char pattern[]){
	int i, j, k;

	for(i = 0; line[i] != '\0'; i++){
		for (j = i, k = 0; pattern[k] != '\0' && line[j] == pattern[k]; j++, k++)
			;
		if (pattern[k] == '\0' && k > 0)
			return i;
	}
	return -1;
}