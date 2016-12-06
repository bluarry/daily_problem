#include<iostream>  
#include<string>  
#include<algorithm>  
using namespace std;  
    int main()  
    {  

        string s="123123123123abc";  
        string ::iterator pos=s.begin();  
        pos++;  
        s.insert(pos,'4');  
        cout<<s<<endl;  
        s.erase(s.end()-3,s.end());
        cout << s << endl;

        
        return 0;  
    }  
