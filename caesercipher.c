ENCRYPTION:
#include <stdio.h>
int main()
{
 char str[1001];
 printf("Enter plain text in lowercase letters:\n");
 scanf("%[^\n]s",str);
 printf("\nCipher Text:");
 int key=3;
 for(int i=0;i<strlen(str);i++)
 {
 if(str[i]>='a' && str[i]<='z')
 {
 char ch=((str[i]+key)-'a')%26;
 printf("%c",ch+'A');
 }
 else
 {
 printf("%c",str[i]);
 }
 }
 return 0;
}
DECRYPTION:
#include <stdio.h>
int main()
{
 char str[1001];
 printf("Enter cipher text in uppercase letters:\n");
 scanf("%[^\n]s",str);
 printf("\nPlain Text:");
 int key=3;
 for(int i=0;i<strlen(str);i++)
 {
 if(str[i]>='A' && str[i]<='Z')
 {
 char ch=((str[i]-key)+'A')%26;
 printf("%c",ch+'a');
 }
 else
 {
 printf("%c",str[i]);
 }
 }
 return 0;
}
