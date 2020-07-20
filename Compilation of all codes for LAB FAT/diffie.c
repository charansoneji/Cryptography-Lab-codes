#include<stdio.h> 
#include<math.h> 
long long int power(long long int a, long long int b, long long int P) 
{ 
	if (b == 1) 
		return a; 

	else
		return (((long long int)pow(a, b)) % P); 
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
	return 0; 
}
int main() 
{ 	
	printf("The Secret keys for the common example of Alice and Bob shall now be calculated by the method of Diffie Hellman Algorithm\n");
	diffie();
} 

