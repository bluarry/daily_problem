#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
//*********************����Ϊջ�Ĳ�����
typedef struct stack{
    char *top;
    char *base;
    int stacksize;
}stack,*Stack;

void stack_init(stack *s){
    s->base=(char *)malloc(100*sizeof(char));
    s->top=s->base;
    s->stacksize=100;
}

void stack_push(stack* s,char e)
{
    if(s->top - s->base == s->stacksize){
        s->base=(char *)realloc(s->base,(s->stacksize+10)*sizeof(char));
        if(!s->base) exit(0);
        s->top=s->base+s->stacksize;
    }
    *(s->top)=e;
    s->top++;
}
char stack_pop(stack* s){
    if(s->top==s->base){
        cout << "ջΪ�գ�����ʧ��\n";
        exit(0);
    }
    return *--(s->top);
}
int stack_empty(stack* s){
    if(s->top == s->base)
        return 1;
    else
        return 0;
}
//******************ջ�Ĳ���������
//******************���еĲ�����
typedef struct queue{
    char *base;
    int front;
    int rear;
}queue,*Queue;

void queue_init(queue* q){
    q->base=(char *)malloc(sizeof(char)*100);
    if(!q->base) exit(0);
    q->front=q->rear=0;
}

void queue_push(queue* q,char e){
    if((q->rear+1)%100 == q->front)
    {
        cout << "��������������ʧ��\n";
        exit(0);
    }
    q->base[q->rear]=e;

    q->rear=(q->rear +1)%100;
}
char queue_pop(queue* q){
    char tep;
    tep=q->base[q->front];
    q->front=(q->front+1)%100;
    return tep;
}

int queue_empty(queue* q){
    if(q->front == q->rear) return 1;
    else return 0;
}
//*****************���еĲ���������

int main()
{
    cout << "������ħ�������� : ";
    string tar;
    cin >> tar;
    char ee;
    Stack s=(stack *)malloc(sizeof(stack));
    Queue q=(queue *)malloc(sizeof(queue));
    stack_init(s);
    queue_init(q);

    cout <<"ħ��������"<<"�ķ���������:";

       int len=tar.length();
    for(int i=len-1;i>=0;--i)
    {
        stack_push(s,tar[i]);
    }
    while(!stack_empty(s))
       {
           char tem=stack_pop(s);
           if(tem==')') continue;
           if(tem=='B')    // ��д��ĸB����
           {
               cout << "tsaedsae";
           }
           else if(tem=='A')//��д��ĸA����
           {
                   cout << "sae";
           }
           else if(tem=='(')   //�������ŵĴ���
           {
               ee=stack_pop(s);
               char x=ee;  //�õ�si��ta
               while(1)    //�����������ĸ���
               {
                   x=stack_pop(s);
                   if(x==')') break;
                   queue_push(q,x);
               }
               //��ջ�����ı�־��ջ
                 stack_push(s,')');
               while(!queue_empty(q)) //���������Ԫ��˳����ջ
               {
                   char y=queue_pop(q);
                  stack_push(s,y);
               }
               char as='0';    //ÿ��Ԫ�ؼ�si'ta����ջ
               while(1)
               {
                   as=stack_pop(s);
                   if(as==')') break;
                   if(as=='B'){
                       cout << ee << "tsaedsae";
                   }
                   else if (as=='A')
                   {
                          cout <<ee <<"sae";
                   }
                   else
                    if (ee!=as)
                    cout << ee << as ;
            		else
            		cout << ee;
               }
           }
           else
           {
               cout << tem;
           }
       }
    cout << endl;
    return 0;
}

