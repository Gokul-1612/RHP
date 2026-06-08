#include <iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int flag=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a'&& s[i]<='z'){
            flag=flag|(1<<(s[i]-'a'));
        }
    }
    if(flag == (1<<26)-1){
        cout<<"It is pangram";
    }
    else{
        cout<<"It is not pangram";
    }

    return 0;
}