#include <stdio.h>
#include <ctype.h>
#include <assert.h>

int
main(void)
{
	FILE *fp = fopen("AZ.txt", "w+");
	assert(fp != NULL);

	for (char c = 'A'; c <= 'Z'; c++) {
		assert(fwrite(&c, sizeof (c), 1, fp) == 1);
		fseek(fp, 3, SEEK_CUR);
	}

	/*
	 * Examine the file size as reported by the file system and note
	 * the discrepancy with the number from ftell().
	 * What would have to be changed to make them the same ?
	 */
	size_t size = ftell(fp);
	printf("file size = %zu\n", size);

	fseek(fp, 0, SEEK_SET);
	for (size_t i = 0; i < size; i++) {
		char c = fgetc(fp);
		if (feof(fp) || ferror(fp))
			break;
		if (isprint(c))
			printf("%c ", c);
		else
			printf("0x%x ", c);
	}
	printf("\n");

	fclose(fp);
}
