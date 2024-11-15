#include<bits/stdc++.h>

using namespace std;
int f(int n){
if(n<=1)    return 1;
else    return n*f(n-1);
}
int f1(int n){
if(n<=1)    return 1;

else{
    int f=n;
    while(--n){
        f*=n;

    }return f;
}
}
int main()
{
int n;cin>>n;
cout<<f(n);

cout<<f1(n);
return 0;
}
