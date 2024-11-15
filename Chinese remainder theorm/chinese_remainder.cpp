//chinese modulus
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
int a[n];
int m[n];
int M=1;
for(int i=0;i<n;i++)    cin>>a[i];
for(int i=0;i<n;i++)    {cin>>m[i];M*=m[i];}

int Mm[n],Mmi[n];
for(int i=0;i<n;i++)
    {
        Mm[i] = M/m[i];
        Mmi[i] = Mm[i]%m[i];
}

int resX = 0;
for(int i=0;i<n;i++)
{
    resX+=a[i] * Mm[i] * Mmi[i];
}
cout<<resX % M;
return 0;
}
