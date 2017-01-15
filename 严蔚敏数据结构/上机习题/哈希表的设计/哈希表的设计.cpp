#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;
const long maxn=327673276;

typedef struct datasrc
{
    long key;
    char* name;
}datasrc;
typedef struct hashtable{
    long key;      //存当前哈希表所存元素的key值
    char *name;
    int asl;
}hastable;


void init(datasrc* name)
{
    ifstream fin("in.txt");
    for(int i=0;i<30;i++)
    {
        name[i].name=new char[20];
        fin >> name[i].name;
    }
    fin.close();
}
void transkey(datasrc* name)
{
    long long sum =1;
    for(int i=0;i<30;i++)
    {
        sum=1;
        for(int j=0;name[i].name[j]!='\0';j++)
        {
            sum = (sum * toascii( name[i].name[j] ) ) % maxn;
        }
        name[i].key=sum;
    }

//    cout << "/***********************哈希表的key值为*********************/"<< endl;
//            for(int i=0;i<30;i++)
//                cout << setw(35)<< name[i].key << endl;
//     cout << "/*********************************************************/" << endl;

}

 void start_hash(hashtable* H,datasrc* name)
 {
    for(int i=0;i<30;i++)
    {
        int hs=name[i].key%47; //哈希函数
        int rehs=((name[i].key)%9009*3)%10+1; //伪随机探测在散列
        int sum =1;
        if(!H[hs].name)
        {
              H[hs].key=name[i].key;
              H[hs].name=name[i].name;
              H[hs].asl=sum;
        }
        else
        {
            int x;
            while (H[hs].name)
            {
                x=(hs+rehs)%50;
                hs=x;
                sum++;
            }
            H[hs].key=name[i].key;
            H[hs].name=name[i].name;
            H[hs].asl=sum;
        }
    }//for
 }




long long get_key(char *name)
{
    long long sum =1;
        for(int j=0;name[j]!='\0';j++)
        {
            sum = (sum * toascii( name[j] ) ) % maxn;
        }
        return sum;
}

 void find(hashtable *H)
 {
    char c=' ';
    while (c!='n' && c!='N') {
        char name[20];
       cout << "输入查询人员的名字的拼音 : ";
       fflush(stdin);
       cin >> name;
        long long key=get_key(name); //得到key的哈希值

        int hs=key%47; //哈希函数
        int hss=hs;
        int rehs=(key%9009*3)%10+1; //伪随机探测在散列


        int x;
        int visit[50];
        memset(visit,0,sizeof(visit));
        int i=0;//标志着结束
        while (H[hs].key!=key && i<30) //最多才30元素
        {
            x=(hs+rehs)%50;
            hs=x;
            i++;
        }
        if(H[hs].key==key)
        {
            cout << "初始哈希下标为 : " << hss << endl;
            cout << "在哈希的下标为 :" << hs << endl;
            cout << "查找长度为 ： " << H[hs].asl << endl;
        }
        else
            cout << "此人不存在" << endl;

        cout  << "是否继续查询?(是 : y/Y | 否 : n/N) : ";
        fflush(stdin);                              //清楚键盘缓冲区的字符，防止非法输入引起的错误
        cin >> c;
        fflush(stdin);
    }
 }



int main()
{
    datasrc name[30];
    hashtable H[50];
    init(name); //将数据来源从文件中输入


    transkey(name); //根据名字得到key

    for(int i=0;i<50;i++)
    {
        H[i].asl=0;
        H[i].key=-1;
        H[i].name=NULL;
    }


    start_hash(H,name);//开始hash

    double sum=0;
    cout << "哈希表内容如下 :"<< endl;
    cout <<setw(15) <<"key值" << setw(10) <<"下标"<<setw(25)<<"人名" << setw(15) << "查找长度" << endl;

        for(int i=0;i<50;i++)
        {
            if(H[i].name)
                cout <<setw(15) <<H[i].key << setw(10) <<i<<setw(25)<< H[i].name << setw(10) << H[i].asl << endl;
                sum+=H[i].asl;
        }

    cout << "平均查找长度为 " << sum/30.0 << endl;

    find(H);
    return 0;
}


