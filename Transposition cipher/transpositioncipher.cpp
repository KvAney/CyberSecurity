#include<bits/stdc++.h>
using namespace std;

string encrypt(string inp,int step)
{
    int k = 0;
    string ans ;

    while(k<step)
    {
        for(int i = 0;i<inp.length()/step ; i++){
            ans +=inp[step * i + k];
        }
        k++;
    }
    return ans;
}

string decrypt(string enc,int step)
{
    string ans;
    for(int i = 0 ; i<enc.length()/ step ; i++)
    {
        ans+=enc[i];
        ans+=enc[i + (enc.length()/step)];
    }
    return ans;
}
int main(){

string inp;
getline(cin,inp);
int step ;cin>>step;
cout<<encrypt(inp,step);
cout<<endl;

cout<<decrypt(encrypt(inp,step),step);

return 0;
}
