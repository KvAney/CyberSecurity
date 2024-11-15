#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll pow(ll a ,ll b){
   ll sq = 1;
for(ll i=1;i<=b;i++)   sq*=a;
return sq;
}
int main(){
ll g, n;
cin>>g >>n;
// n mod g;
cout<<n<<" mod  "<<g<<endl;

ll Ar = (1 + (rand()%15)  ) ;
ll Br =( 1 + (rand()%15) ) ;
cout<<"A has selected "<<Ar<<" \nB has selected "<<Br;
ll asend = pow(n,Ar) % g;
ll bsend = pow(n,Br) %g;

cout<<"\nA has sent "<<asend<<" to B and \n B has sent "<<bsend<<" to A\n";


long long akey = pow(bsend,Ar) % g;
long long bkey = pow(asend,Br) % g;
cout<<akey<<"\t"<<bkey;
return 0;}
