#include <stdio.h>
#include <string.h>

int main()	{
	
	char plainText[100], key[100];
	
	printf("Enter the text to encrypt: ");
	fgets(plainText, 100, stdin);
	printf("Enter the key: ");
	fgets(key, 100, stdin);
	
	printf("\n");
	printf("Plain Text: %s\n", plainText);
	printf("Key: %s\n", key);
	
	int asciiText[strlen(plainText)];
	int asciiKey[strlen(key)];
	printf("Converting to ASCII...\n");
	printf("Subtracting 64...\n");
	
	for (int i = 0; i < strlen(plainText)-1; i++)	{					// converting plainText to its ascii values
		if ((int)plainText[i] != 32)	{
			asciiText[i] = (int)plainText[i]-64;					// subtracting 64 asw
		}	else	{												// space char needs to be 20
			asciiText[i] = 20;
		}
	}
	
	printf("\n");
	printf("Plain Text: ");
	for (int i = 0; i < strlen(plainText)-1; i++)	{				
		printf("%d ", asciiText[i]);
	}
	printf("\n");
	
	
//	for (int i = 0; i < strlen(plainText)-1; i++)	{				// test - to print asciiText
//		printf("%d\n", asciiText[i]);
//	}
	for (int i = 0; i < strlen(key)-1; i++)	{						// converting key to its ascii values the same way
		if ((int)key[i] != 32)	{
			asciiKey[i] = (int)key[i]-64;							// subtracting 64 asw
		}	else	{												// space 20
			asciiKey[i] = 20;
		}
	}
	
	printf("Key: ");
	int keyIndex = 0;	
	for (int j = 0; j < strlen(plainText)-1; j++)	{
		if (keyIndex ==	strlen(key)-1)	{							// keyIndex iterates through the key and turns back to 0
			keyIndex = 0;
		}
		printf("%d ", asciiKey[keyIndex]);
		keyIndex++;
	}
	
//	for (int i = 0; i < strlen(key)-1; i++)	{						// test - to print asciiKey
//		printf("%d\n", asciiKey[i]);
//	}
	
	int sum[strlen(plainText)];
	
	keyIndex = 0;
		
	for (int j = 0; j < strlen(plainText)-1; j++)	{
		if (keyIndex ==	strlen(key)-1)	{							// keyIndex iterates through the key and turns back to 0
			keyIndex = 0;
		}
		sum[j] = asciiText[j] + asciiKey[keyIndex];					// add the values
		keyIndex++;
	}
	
	printf("\n");
	printf("\n");
	printf("Adding values vertically...\n");
	printf("\n");
	printf("Cipher: ");
	for (int j = 0; j < strlen(plainText)-1; j++)	{				// test - to print sum
		printf("%d ", sum[j]);
	}
	
	for (int j = 0; j < strlen(plainText)-1; j++)	{				// sum modulus 26
		sum[j] = sum[j] % 26;
	}
	printf("\n");
	printf("\n");
	printf("Taking mod 26...\n");
	printf("\n");
	printf("Cipher mod 26: ");
	for (int j = 0; j < strlen(plainText)-1; j++)	{				// test - to print sum
		printf("%d ", sum[j]);
	}
	printf("\n");
	
	int cipherInt[strlen(plainText)];	
	for (int j = 0; j < strlen(plainText)-1; j++)	{			
		cipherInt[j] = sum[j] + 64;									// add 64
	}
	printf("\n");
	printf("Adding 64...\n");
	printf("\n");
	printf("Final Cipher: ");
	for (int j = 0; j < strlen(plainText)-1; j++)	{			
		printf("%d ", cipherInt[j]);									
	}
	
	
	char cipher[strlen(plainText)-1];
	
	for (int j = 0; j < strlen(plainText)-1; j++)	{			
		cipher[j] = (char)cipherInt[j];								// convert ascii to string
	}
	printf("\n");
	printf("\n");
	printf("Converting ASCII to string...\n");
	printf("\n");
	printf("Final Cipher Text:\t");
	for (int j = 0; j < strlen(plainText)-1; j++)	{			
		printf("%c ", cipher[j]);									
	}
	
	return 0;
}