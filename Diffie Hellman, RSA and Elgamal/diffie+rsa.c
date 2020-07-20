#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long int p,q,n,t,flag,e[100],d[100],temp[100],j,m[100],en[100],i;
char msg[100];
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();
long long int power(long long int a, long long int b, long long int P)
{ 
	if (b == 1) 
		return a; 
	else
		return (((long long int)pow(a, b)) % P); 
} 

int main() {
	printf("----------------------Welcome 17BCE2196---------------------------\n");
	int o;
	printf("\nPlease choose the encryption algorithm");
	printf("\n1. RSA Public Key Cryptosystem");
	printf("\n2. Diffie Hellman Key Exchange Algorithm");	
	printf("\n3. Exit\n");
	scanf("\n%d",&o);
	switch(o){
		case 1:
			rsam();
			break;
		case 2:
			printf("The Secret keys for the common example of Alice and Bob shall now be calculated by the method of Diffie Hellman Algorithm\n");
			diffie();
			break;
		case 3:
			break;
}
}
void diffie(){
	long long int P, G, x, a, y, b, ka, kb; 
	printf("Enter the value of P(Prime number):");
	scanf("%d",&P); 
	printf("The value of P : %lld\n", P); 
	printf("Enter the value of G(Prime number):");
	scanf("%d",&G); 
	printf("The value of G : %lld\n", G); 
	printf("Enter the private key chosen by Alice\n");
	scanf("%d",&a);
	printf("The private key a for Alice : %lld\n", a); 
	x = power(G, a, P); 
	printf("Enter the private key chosen by Bob\n");
	scanf("%d",&b);
	printf("The private key b for Bob : %lld\n", b); 
	y = power(G, b, P);
	ka = power(y, a, P); 
	kb = power(x, b, P); 
	printf("The keys generated have now been exchanged\n");
	printf("Secret key for the Alice is : %lld\n", ka); 
	printf("Secret Key for the Bob is : %lld\n", kb); 
}

int rsam(){
	printf("Encryption and Decryption in RSA algorithm shall now be performed\n");
	printf("Enter the value of p(First Prime number):");
	scanf("%d",&p);
	flag=prime(p);
	if(flag==0) {
		printf("Invalid Input");
		getch();
		exit(1);
	}
	printf("Enter the value of q(Second prime number):");
	scanf("%d",&q);
	flag=prime(q);
	if(flag==0||p==q) {
		printf("Invalid Input\n");
		getch();
		exit(1);
	}
	printf("Enter Message");
	fflush(stdin);
	scanf("%s",msg);
	for (i=0;msg[i] !=NULL;i++)
		m[i]=msg[i];
	n=p*q;
	t=(p-1)*(q-1);
	ce();
	printf("Possible values of e and d are:");
	for (i=0;i<j-1;i++)
		printf("\n%ld\t%ld",e[i],d[i]);
	encrypt();
	decrypt();
	getch();
}
int prime(long int pr) {
	int i;
	j=sqrt(pr);
	for (i=2;i<=j;i++) {
		if(pr%i==0)
		    return 0;
	}
	return 1;
}
void ce() {
	int k;
	k=0;
	for (i=2;i<t;i++) {
		if(t%i==0)
		    continue;
		flag=prime(i);
		if(flag==1&&i!=p&&i!=q) {
			e[k]=i;
			flag=cd(e[k]);
			if(flag>0) {
				d[k]=flag;
				k++;
			}
			if(k==99)
			        break;
		}
	}
}
long int cd(long int x) {
	long int k=1;
	while(1) {
		k=k+t;
		if(k%x==0)
		    return(k/x);
	}
}
void encrypt() {
	long int pt,ct,key=e[0],k,len;
	i=0;
	len=strlen(msg);
	while(i!=len) {
		pt=m[i];
		pt=pt-96;
		k=1;
		for (j=0;j<key;j++) {
			k=k*pt;
			k=k%n;
		}
		temp[i]=k;
		ct=k+96;
		en[i]=ct;
		i++;
	}
	en[i]=-1;
	printf("\nThe Encrypted message is:");
	for (i=0;en[i]!=-1;i++)
	printf("%c",en[i]);
}
void decrypt() {
	long int pt,ct,key=d[0],k;
	i=0;
	while(en[i]!=-1) {
		ct=temp[i];
		k=1;
		for (j=0;j<key;j++) {
			k=k*ct;
			k=k%n;
		}
		pt=k+96;
		m[i]=pt;
		i++;
	}
	m[i]=-1;
	printf("\nThe Decrypted message is:");
	for (i=0;m[i]!=-1;i++)
		printf("%c",m[i]);
}
 
