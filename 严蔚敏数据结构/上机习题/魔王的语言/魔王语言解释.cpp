#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
//*********************以下为栈的操作集
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
        cout << "栈为空，操作失败\n";
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
//******************栈的操作集结束
//******************队列的操作集
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
        cout << "队列已满，操作失败\n";
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
//*****************队列的操作集结束

int main()
{
    cout << "请输入魔王的语言 : ";
    string tar;
    cin >> tar;
    char ee;
    Stack s=(stack *)malloc(sizeof(stack));
    Queue q=(queue *)malloc(sizeof(queue));
    stack_init(s);
    queue_init(q);

    cout <<"魔王的语言"<<"的翻译结果如下:";

       int len=tar.length();
    for(int i=len-1;i>=0;--i)
    {
        stack_push(s,tar[i]);
    }
    while(!stack_empty(s))
       {
           char tem=stack_pop(s);
           if(tem==')') continue;
           if(tem=='B')    // 大写字母B处理
           {
               cout << "tsaedsae";
           }
           else if(tem=='A')//大写字母A处理
           {
                   cout << "sae";
           }
           else if(tem=='(')   //遇到括号的处理
           {
               ee=stack_pop(s);
               char x=ee;  //得到si‘ta
               while(1)    //将括号里的字母入队
               {
                   x=stack_pop(s);
                   if(x==')') break;
                   queue_push(q,x);
               }
               //出栈结束的标志入栈
                 stack_push(s,')');
               while(!queue_empty(q)) //将队列里的元素顺序入栈
               {
                   char y=queue_pop(q);
                  stack_push(s,y);
               }
               char as='0';    //每个元素加si'ta，出栈
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

