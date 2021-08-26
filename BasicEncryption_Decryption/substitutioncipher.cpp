#include<bits/stdc++.h>

using namespace std;
string encrypt(string s,int k){
    string ans = "";
for(char i : s){
if(i == ' ')    ans+= " ";
else    ans += char((int(i) + k - int ('a')  )% 26    + int('a'));// firstly making 'a' as origin then we want % to be under 26 and then add 'a' ascii again
}
return ans;
}

string decrypt(string s,int k){
    string ans = "";
for(char i : s){
if(i == ' ')    ans+= " ";
else    ans += char((int(i) - k - int ('a') +26 )% 26    + int('a'));//if int(i) -k-int('a') is negative....we generally add 26 and if it is +ve due to % operation +26 will have no effect
}
return ans;
}

int  main(){

string s;
int k;
bool exit = false,flag = false;
do{
cout<<"\nMenu - \n 1.Enter Sentence \n 2. Encrypt \n 3.Decrypt \n 4.Exit:";
int choice;
cin>>choice;
switch(choice){
case 1:
    cout<<"Input the Sentence you want to encrypt :";
    getline(cin,s);//takes sentence//it takes \n from the previous cout hence we have to take it again
    getline(cin,s);//takes sentence
    transform(s.begin(), s.end(), s.begin(), ::tolower);//to make things simpler
    cout<<" Conveted into lowercase for simplicity "<<s<<endl;
    flag = true;
    cout<<"Enter Key you want to shift : ";cin>>k;
    break;

case 2:
    if(flag)    cout<<encrypt(s,k);
    else    cout<<"Fill up sentence first!\n";
    break;

case 3:
    if(flag)    cout<<decrypt(encrypt(s,k),k);
    else    cout<<"Fill up sentence first!\n";
    break;

case 4:
    exit=true;
    break;
}
}while(!exit);
return 0;
}
