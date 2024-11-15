//chinese modulus
#include<bits/stdc++.h>
using namespace std;
//doing captial letters
class all{
char m[5][5];
public :
    string encrypt(string);
    string Decrypt(string);
    void printMat();
    void createMat(string);
};

string all::encrypt(string s)
{
    //two are in column
    //twp are in same row
    // two form a box

    string ans="";
    if(s.length() %2 != 0)  s+='X';  // if odd then add X at the end
    for(int i = 0;i<s.length()-1;i+=2)
        {
            char a = s[i] , b = s[i+1];
            int ra,ca,rb,cb; // stores where is a , b is located in the matrix row, column
            //for a
                                                            for(int ri=0;ri<5;ri++)
                                                            {
                                                                for(int ci=0;ci<5;ci++)
                                                                {
                                                                    if(m[ri][ci] == a)  {ra=ri;ca=ci;break;}
                                                                    }
                                                                }
            //for b
                                                            for(int ri=0;ri<5;ri++)
                                                            {
                                                                for(int ci=0;ci<5;ci++)
                                                                {
                                                                    if(m[ri][ci] == b)  {rb=ri;cb=ci;break;}
                                                                    }
                                                                }

                        if(ra == rb) // sliding one step forward   column++
                            {
                                ca = (ca+1)%5;cb = (cb+1)%5;
                                ans+=m[ra][ca];
                                ans+=m[rb][cb];
                            }

                        else if(ca == cb) // sliding one step forward   column++
                            {
                                ra = (ra+1)%5;rb = (rb+1)%5;
                                ans+=m[ra][ca];
                                ans+=m[rb][cb];
                            }
                            else
                            {
                                ans+=m[ra][cb];
                                ans+=m[rb][ca];
                            }
                }
return ans;
}

string all::Decrypt(string s)
{
    //two are in column
    //twp are in same row
    // two form a box

    string ans="";
    if(s.length() %2 != 0)  s+='X';  // if odd then add X at the end
    for(int i = 0;i<s.length()-1;i+=2)
        {
            char a = s[i] , b = s[i+1];
            int ra,ca,rb,cb; // stores where is a , b is located in the matrix row, column
            //for a
                                                            for(int ri=0;ri<5;ri++)
                                                            {
                                                                for(int ci=0;ci<5;ci++)
                                                                {
                                                                    if(m[ri][ci] == a)  {ra=ri;ca=ci;break;}
                                                                    }
                                                                }
            //for b
                                                            for(int ri=0;ri<5;ri++)
                                                            {
                                                                for(int ci=0;ci<5;ci++)
                                                                {
                                                                    if(m[ri][ci] == b)  {rb=ri;cb=ci;break;}
                                                                    }
                                                                }

                        if(ra == rb) // sliding one step forward   column++
                            {
                                ca = (ca-1)%5;cb = (cb-1)%5;
                                ans+=m[ra][ca];
                                ans+=m[rb][cb];
                            }

                        else if(ca == cb) // sliding one step forward   column++
                            {
                                ra = (ra-1)%5;rb = (rb-1)%5;
                                ans+=m[ra][ca];
                                ans+=m[rb][cb];
                            }
                            else
                            {
                                ans+=m[ra][cb];
                                ans+=m[rb][ca];
                            }
                }
return ans;
}

void all::printMat()
{
    for(int i = 0;i<5 ;i++)
    {
        for(int j = 0;j<5 ;j++) cout<<m[i][j]<<" ";
        cout<<endl;
    }

}
void all::createMat(string keyword)
{
     vector<bool>v(26,false);// to check the if the letter is repeated and if repeated then apply necessary process
    //ascii A=65 to 90
      int row=0,col=0;
    //fill keyword first

    for(int i=0;i<keyword.length();i++)
        {
            if(!v[int(keyword[i]) - int('A')])
                {
                    v[int(keyword[i]) - int('A')]=true;
                    m[row][col]=keyword[i];

                    col = (col+1) %5;
                    if(col  == 0)   row=(row+1) %5;//lets see mod 5 ki garaj haii ki ni
                }
        }

        //
        int ascii = 0;//// 'a'  = 97 ,'A' =65

     bool isFirstItr = false;// once it follows column = col and then  it follows from zero
     int tempcol = col;

    for(int i=row;i<5;i++){//for row
            if(isFirstItr)    tempcol = 0;
            else {tempcol = col;isFirstItr=true;}

            for(int j=tempcol;j<5;j++){//for column
                    if(ascii ==9)   ascii++;
                    while(v[ascii])
                        {
                            ascii++;
                            if(ascii==9) ascii++;//elimination of 'J'
                    }
                if(!v[ascii])   m[i][j] = char(ascii+int('A'))   ;
                ascii++;
            }
    }

}

string filter_sent(string s){//capital small letters validation remaining
    string ans ="";
    for(char c : s)
        {
            if(c == ' ')    continue;
            else    ans+=c;
    }
return ans;
}

int main(){
    string keyword ;
    cin>>keyword;
    all a1;

a1.createMat(keyword);

a1.printMat();
   string sent;
    getline( cin , sent);
    getline( cin , sent);
   string nsen = filter_sent(sent);
cout<<nsen;

    string encrypted = a1.encrypt(nsen);
    cout<<"\nencrypted :"<<encrypted;

    string Decrypted = a1.Decrypt(encrypted);
    cout<<"\nDecrypted"<<Decrypted;
return 0;
}
