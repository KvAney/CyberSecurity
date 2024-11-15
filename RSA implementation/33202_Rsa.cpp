#include<bits/stdc++.h>
using namespace std;
// find gcd
int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}

class rsa{

   //2 random prime numbers
   double p = 13;
   double q = 11;
   double n=p*q;//calculate n
   double track;
   double phi= (p-1)*(q-1);//calculate phi
   //public key
   //e stands for encrypt
   double e=7,d;

   public:
       rsa();

};
rsa::rsa(){

 while(e<phi) {
      track = gcd(e,phi);
      if(track==1)
         break;
      else
         e++;
   }
   //private key
   //d stands for decrypt
   //choosing d such that it satisfies d*e = 1 mod phi
   double d1=1/e;
   d=fmod(d1,phi);

}
vector<int>encrypt(string s,double e,double N){
vector<int>v;
for(char i : s)
{    double c = pow(i,e); //encrypt the message
   c=fmod(c,N);
   v.push_back(int(c));
    }
    return v;
}

vector<int> decrypt(vector<int> enc,double d,double N){
vector<int>v;
for(int i : enc){



   double c = pow(i,7); //encrypt the message
   double m = pow(c,d);

   m=fmod(m,N);
v.push_back(m+1);
}
return v;
}
int main() {

   //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.

   char a;cin>>a;
   double message = int(a);
   double c = pow(message,e); //encrypt the message
   double m = pow(c,d);
   c=fmod(c,n);
   m=fmod(m,n);


   cout<<"Original Message = "<<message;
   cout<<"\n"<<"p = "<<p;
   cout<<"\n"<<"q = "<<q;
   cout<<"\n"<<"n = pq = "<<n;
   cout<<"\n"<<"phi = "<<phi;
   cout<<"\n"<<"e = "<<e;
   cout<<"\n"<<"d = "<<d;
   cout<<"\n"<<"Encrypted message = "<<c;
   cout<<"\n"<<"Decrypted message = "<<m;

cout<<"HERE\n";
   string aa;
   getline(cin,aa);
   getline(cin,aa);
   vector<int>en = encrypt(aa,e,n);
   cout<<"HERE\n";
   for(int encry : en)   cout<<encry<<"\t";
   vector<int>dec = decrypt(en,d,n);
   cout<<endl;
   for(int decry : dec)   cout<<decry<<"\t";

   return 0;
}
