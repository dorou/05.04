#include <stdio.h>

int main (void)
{
	FILE *in, *out;
	char input[81], output[81];
	int c;

	printf("Введите имя первого файла: ");
	scanf("%s", input);
	printf("Введите имя второго файла: ");
	scanf("%s", output);

	if ((in = fopen (input, "r")) == NULL) {
		printf("Unable to open %s\n", input);
		return 1;
	}
	if ((out = fopen (output, "w")) == NULL) {
		printf("Unable to open %s\n", output);
		return 1;
	}
	while ((c = getc(in)) != EOF) {
		if (c >= (int) 'a' && c <= (int) 'z') {
			c = c - 'a' + 'A';
			putc(c, out);
		} else {
			putc(c, out);
		}
	}
	fclose(in);
	fclose(out);

	return 0;
}