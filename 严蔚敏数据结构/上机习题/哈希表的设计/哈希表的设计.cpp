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
    long key;      //�浱ǰ��ϣ������Ԫ�ص�keyֵ
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

//    cout << "/***********************��ϣ���keyֵΪ*********************/"<< endl;
//            for(int i=0;i<30;i++)
//                cout << setw(35)<< name[i].key << endl;
//     cout << "/*********************************************************/" << endl;

}

 void start_hash(hashtable* H,datasrc* name)
 {
    for(int i=0;i<30;i++)
    {
        int hs=name[i].key%47; //��ϣ����
        int rehs=((name[i].key)%9009*3)%10+1; //α���̽����ɢ��
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
       cout << "�����ѯ��Ա�����ֵ�ƴ�� : ";
       fflush(stdin);
       cin >> name;
        long long key=get_key(name); //�õ�key�Ĺ�ϣֵ

        int hs=key%47; //��ϣ����
        int hss=hs;
        int rehs=(key%9009*3)%10+1; //α���̽����ɢ��


        int x;
        int visit[50];
        memset(visit,0,sizeof(visit));
        int i=0;//��־�Ž���
        while (H[hs].key!=key && i<30) //����30Ԫ��
        {
            x=(hs+rehs)%50;
            hs=x;
            i++;
        }
        if(H[hs].key==key)
        {
            cout << "��ʼ��ϣ�±�Ϊ : " << hss << endl;
            cout << "�ڹ�ϣ���±�Ϊ :" << hs << endl;
            cout << "���ҳ���Ϊ �� " << H[hs].asl << endl;
        }
        else
            cout << "���˲�����" << endl;

        cout  << "�Ƿ������ѯ?(�� : y/Y | �� : n/N) : ";
        fflush(stdin);                              //������̻��������ַ�����ֹ�Ƿ���������Ĵ���
        cin >> c;
        fflush(stdin);
    }
 }



int main()
{
    datasrc name[30];
    hashtable H[50];
    init(name); //��������Դ���ļ�������


    transkey(name); //�������ֵõ�key

    for(int i=0;i<50;i++)
    {
        H[i].asl=0;
        H[i].key=-1;
        H[i].name=NULL;
    }


    start_hash(H,name);//��ʼhash

    double sum=0;
    cout << "��ϣ���������� :"<< endl;
    cout <<setw(15) <<"keyֵ" << setw(10) <<"�±�"<<setw(25)<<"����" << setw(15) << "���ҳ���" << endl;

        for(int i=0;i<50;i++)
        {
            if(H[i].name)
                cout <<setw(15) <<H[i].key << setw(10) <<i<<setw(25)<< H[i].name << setw(10) << H[i].asl << endl;
                sum+=H[i].asl;
        }

    cout << "ƽ�����ҳ���Ϊ " << sum/30.0 << endl;

    find(H);
    return 0;
}


