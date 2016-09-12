/*

醉了这道题，怎么看怎么对，到最后发现是MAXSIZE的问题，可能给的程序MAXSIZE会变，这就尴尬了，
害的我一直是错误
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
#define ERROR -1
//typedef enum{false=0, true=1} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    freopen("D:\\in.txt","r",stdin);
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();       
    
	scanf("%d", &N);
    
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }

 

    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }

/*printf("\nThe data are as fllowing :");
    for(int i=0;i<=L->Last;i++)
    {
        printf("%d ",L->Data[i]);
    }
    printf("\n\n");
*/

    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
            
       /*      printf("\nThe data are as fllowing :");
    for(int i=0;i<=L->Last;i++)
    {
        printf("%d ",L->Data[i]);
    }
    printf("\n\n");*/

    }
/* printf("\nThe data are as fllowing :");
    for(int i=0;i<=L->Last;i++)
    {
        printf("%d ",L->Data[i]);
    }
    printf("\n\n");
*/
    return 0;
}

/* 你的代码将被嵌在这里 */
/**
List MakeEmpty()：创建并返回一个空的线性表；
Position Find( List L, ElementType X )：返回线性表中X的位置。若找不到则返回ERROR；
bool Insert( List L, ElementType X, Position P )：将X插入在位置P并返回true。若空间已满，
则打印“FULL”并返回false；如果参数P指向非法位置，则打印“ILLEGAL POSITION”并返回false；
bool Delete( List L, Position P )：将位置P的元素删除并返回true。若参数P指向非法位置，
则打印“POSITION P EMPTY”（其中P是参数值）并返回false。
*/


List MakeEmpty()
{
    List L=(List)malloc( sizeof(struct LNode) );
    L->Last=-1;
    return L;
}
Position Find( List L, ElementType X )
{
    for(int i= L->Last;i>=0;i--)
    {
        if(L->Data[i]==X)
            return i;
    }
    return ERROR;
}
bool Insert( List L, ElementType X, Position P )
{
    if(L->Last+1==MAXSIZE)
    {
          printf("FULL");
        return false;
    }
    if(P<0||P>(L->Last+1)) 
    {
        printf("ILLEGAL POSITION");
        return false;
    }
    for(int i=L->Last+1; i>P ;i-- )
        L->Data[i]=L->Data[i-1];
    L->Data[P]=X;
    L->Last++; 
    return true;
}
bool Delete( List L, Position P ){
    if(P<0||P>L->Last)
    {
        printf("POSITION %d EMPTY",P);
        return false;
    }
    for(int i=P;i<L->Last;i++)
        L->Data[i]=L->Data[i+1];
    L->Last--;
    return true;
}
