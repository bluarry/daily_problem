#define INI_SIZE 100
#define INCREASE_SIZE 10
typedef char Elemtype;

typedef struct Stack{
    Elemtype *top;
    Elemtype *base;
    int StackSize;
}sqStack;


void initstack( sqStack *s )
{
            s->base=(Elemtype *)malloc(sizeof(Elemtype)*INI_SIZE);
               s->top=s->base;
               s->StackSize=INI_SIZE;
}

void push(sqStack *s, Elemtype  e)
{
    if(s->top - s->base==s->StackSize)
       {
           s->base=(Elemtype *)realloc(s->base,(s->StackSize+INCREASE_SIZE)*sizeof(Elemtype));
           if(!s)return ;
           s->top=s->base+s->StackSize;
       }
       *(s->top)=e;
       s->top++;
}

void pop(sqStack *s, Elemtype  *e){
    if(s->base==s->top) {printf("error,the stack is empty\n");exit(1) ;}
        *e=*--(s->top);
}

int stacklen(sqStack *s)
{
    return s->top -  s->base;
}