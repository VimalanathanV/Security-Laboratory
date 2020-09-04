Encryption:
#include <stdio.h>
int main()
{
    printf("Enter the key matrix of 3x3 size:\n");
    int key[3][3];
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    scanf("%d ",&key[i][j]);
    printf("Enter the plain text in 3 letters:");
    char string[3];
    scanf("%s",string);
    int plain[3][1];
    int cipher[3][1];
    for(int i=0;i<3;i++)
    {
        plain[i][0]=string[i]-97;
    }
    for(int i = 0; i < 3; i++)
		{ 
		    int j = 0;
		    cipher[i][j]=0;
			for(int k = 0; k < 3; k++)
			{
				cipher[i][j]+= (key[i][k] * plain[k][j]);
				
			}
		}
	printf("Encrypted Text:\n");
	for(int i = 0; i < 3; i++)
		printf("%c", ((cipher[i][0])%26)+65);
}

