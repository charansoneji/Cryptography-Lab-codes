#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
string inp,op="\0";
int n,x=0,v,w[100];
float matr[100][200],t;

main(){
int sk,i,j,option,m=0,ip,q,h;
int k[100][100]={'\0'},p[100][1]={'\0'},c[100][1]={'\0'};
while(1){
    cout<<endl<<"-------------------WELCOME 17BCE2196---------------------------------"<<endl;
cout<<"Please enter your choice\n";
 cout<<"1.Encryption\n";
 cout<<"2.Decryption\n";
 cout<<"3.Exit\n";
 cin>>option;
 switch(option){
case(2):
    x=0;
    cout<<"Enter the message which needs to be decrypted:";
   cin>>inp;
 cout<<"Enter the size of key matrix:";
 cin>>sk;
 while((inp.length())%sk !=0){
    cout<<"Please Enter the size such that (length of message)%(size of key matrix)==0!";
    cin>>sk;
 }
n=sk;
   cout<<"Enter the elements of matrix"<<endl;
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
         cin>>matr[i][j];
    for(i=0;i<n;i++)
   {
      for(j=n;j<2*n;j++)
      {
          if(i==j-n)
             matr[i][j]=1;
         else
             matr[i][j]=0;
       }
   }
   for(i=0;i<n;i++)
   {
      t=matr[i][i];
      for(j=i;j<2*n;j++)
          matr[i][j]=matr[i][j]/t;
      for(j=0;j<n;j++)
      {
         if(i!=j)
         {
            t=matr[j][i];
            for(v=0;v<2*n;v++)
                matr[j][v]=matr[j][v]-t*matr[i][v];
          }
      }
   }
   //cout<<"\n\nInverse matrix\n\n";
   for(i=0;i<n;i++)
   {
      for(j=n;j<2*n;j++){
        // cout<<"\t"<<matr[i][j];
         w[x]=(int)matr[i][j];
         if(w[x]<0){w[x]=26+w[x];}
         x++;
      }
      //cout<<"\n";
    }
    x=0;
for(i=0;i<sk;i++){
    for(j=0;j<sk;j++){
        k[i][j]=(w[x]);
        x++;
    }
}
   for(m=0;m<inp.length();m=m+sk){
         ip=0;
      for(h=m;h<m+sk;h++){
      p[ip][0]=int(inp[h])-97;
       ip++;
   }
     for (i = 0; i < sk; i++)
    {
        for (j = 0; j <1; j++)
        {
            c[i][j] = 0;
            for (q = 0; q < sk; q++)
            {
                 c[i][j] += k[i][q]*p[q][j];
            }
           c[i][j]=c[i][j]%26;
           op=op+char(c[i][j]+97);
        }
    }
   }
   cout<<"Decrypted message:"<<op;
   op="\0";
cout<<endl;
break;
case(1):
     cout<<"Enter the message:";
   cin>>inp;
 cout<<"Enter size of the key matrix:";
 cin>>sk;
 while((inp.length())%sk !=0){

    cout<<"Please Enter the size such that (length of message)%(size of key matrix)==0";
    cin>>sk;
 }
 for(i=0;i<sk;i++){
     for(j=0;j<sk;j++){
         cout<<"Enter element of the matrix:";
         cin>>k[i][j];
     }
   }
   for(m=0;m<inp.length();m=m+sk){
         ip=0;
      for(t=m;t<m+sk;t++){
      p[ip][0]=int(inp[t])-97;
       ip++;
   }
     for (i = 0; i < sk; i++)
    {
        for (j = 0; j <1; j++)
        {
            c[i][j] = 0;
            for (q = 0; q < sk; q++)
            {
                 c[i][j] += k[i][q]*p[q][j];
            }
           c[i][j]=c[i][j]%26;
           op=op+char(c[i][j]+97);
        }
    }
   }
   cout<<"Encrypted message:"<<op;
   op="\0";
cout<<endl;
    break;
case(3):
    exit(0);
}}}

