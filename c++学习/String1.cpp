    #include<iostream>  
    #include<string>  
    #include<cstdio>  
    #include<algorithm>  
    using namespace std;  
      
    int main()  
    {  
        string s="test";  
        //在尾部添加一个字符  
        s=s+'1';  
        cout<<s<<endl;  
        //尾部添加字符串（直接添加）  
        s=s+"234";  
        cout<<s<<endl;  
        //尾部添加字符串（append方式添加）  
        s.append("678");  
        cout<<s<<endl;  
        return 0;  
    }  