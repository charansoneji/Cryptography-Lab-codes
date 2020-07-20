#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<string.h>
 
int encdec1(){
    char message[100];
    char key[20];
    printf("\nEnter the message:");
    scanf("%s",message);
    printf("\nEnter key:");
    scanf("%s",key);
    int messagelength = strlen(message), keyLen = strlen(key), i, j;
    char newKey[messagelength], encrypted[messagelength], decrypted[messagelength];
    for(i = 0, j = 0; i < messagelength; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
    for(i = 0; i < messagelength; ++i)
        encrypted[i] = ((message[i] + newKey[i]) % 26) + 'A';
    encrypted[i] = '\0';
    for(i = 0; i < messagelength; ++i)
        decrypted[i] = (((encrypted[i] - newKey[i]) + 26) % 26) + 'A';
    decrypted[i] = '\0';
    printf("Original Message: %s", message);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encrypted);
    printf("\nDecrypted Message: %s", decrypted);
 
	return 0;
}








int main(){
	printf("\n--------------------Welcome 17BCE2196----------------------\n");
	printf("\nPlease choose the encryption algorithm");
	printf("\n1. Vigenere Cipher Technique");
	printf("\n2. Simple DES Encryption Algorithm");
	printf("\n3. Exit\n");
	int o;
	scanf("%d",&o);
	switch(o){
		case 1: 
			encdec1();
			
}
}
