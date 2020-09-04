#include <stdio.h>
int modInverse(int a, int m) 
{ 
    a = a%m; 
    for (int x=1; x<m; x++) 
       if ((a*x) % m == 1) 
          return x; 
} 
int main()
{
    printf("Enter the key matrix of 3x3 size:\n");
    int key[3][3],kinverse[3][3];
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
        scanf("%d ",&key[i][j]);
    }
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
	printf("\nEncrypted Text:\n");
	for(int i = 0; i < 3; i++)
		printf("%c", ((cipher[i][0])%26)+65);
	int determinant=0;
	for(int i = 0; i < 3; i++)
	determinant = determinant + (key[0][i] * (key[1][(i+1)%3] * key[2][(i+2)%3] - key[1][(i+2)%3] * key[2][(i+1)%3]));
   determinant=determinant%26;
   if (determinant<0)
   determinant=26+determinant;
   int detinverse=modInverse(determinant,26);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
		{
			int x=((key[(j+1)%3][(i+1)%3] * key[(j+2)%3][(i+2)%3]) - (key[(j+1)%3][(i+2)%3] * key[(j+2)%3][(i+1)%3]));
			x=((x%26)*detinverse)%26;
			if (x<0)
			x=26+x;
			kinverse[i][j]=x;
		}
	}
	int decrypt[3][1];
	for(int i = 0; i < 3; i++)
		{ 
		    int j = 0;
		    decrypt[i][j]=0;
			for(int k = 0; k < 3; k++)
			{
				decrypt[i][j]+= (kinverse[i][k] * cipher[k][j]);
				
			}
		}
	printf("\nDecrypted Text:");
	for(int i=0;i<3;i++)
	{
	    for(int j=0;j<1;j++)
	    {
	        printf("%c",decrypt[i][j]%26+97);
	    }
	}
}
