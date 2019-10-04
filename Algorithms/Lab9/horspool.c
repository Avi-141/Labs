#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *text;
char *pattern;
int n, m;

int i, j;
int horspool (int *count) {

	int shift[256];
	for (i = 0; i <256; ++i) {
		shift[i] = m;
	}

	for (i = 0; i < m - 1; ++i) {
		shift[pattern[i]] = m - 1 - i;
	}
    j = 0;
	while (j + m <= n) {
		*count += 1;
		if (pattern[m-1] == text[j+m-1]) {
			i = m - 2;
			while (i >= 0 && pattern[i] == text[j+i]) {
				*count += 1;
				i -= 1;
			}
			if (i == -1)
				return j;
		}
		j += shift[text[j+m-1]];
	}
	return -1;

}

int main (){
	text = (char *)malloc(100* sizeof(char));
	pattern = (char *)malloc(40 * sizeof(char));
	printf("Text?: ");
	scanf(" %s", text);
	n = strlen(text);
	printf("Pattern?: ");
	scanf(" %s", pattern);
	m = strlen(pattern);
	int count = 0;
	int idx = horspool(&count);
	if(idx==-1)
		printf("Doesnt exits, Comparisions = %2d\n",count);
	else
	printf("Found at %2d, Comparions: %d\n", idx, count);
	return 0;
}