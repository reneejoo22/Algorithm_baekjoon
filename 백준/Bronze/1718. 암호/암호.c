#include <stdio.h>
#include <string.h>

char plain_text[30005], cipher_text[30005], key[30005], tmp;

int main(void)
{

	gets(plain_text);
	scanf("%s", key);

	for (int i = 0; i < strlen(plain_text); i++)
	{
		if (plain_text[i] == ' ')
			cipher_text[i] = ' ';
		else
		{
			char tmp = plain_text[i] - (key[i % strlen(key)] - 'a') - 1;
			if (tmp < 'a')
				tmp += 26;
			cipher_text[i] = tmp;
		}
	}

	cipher_text[strlen(plain_text)] = '\0';
	printf("%s", cipher_text);
	return 0;
}