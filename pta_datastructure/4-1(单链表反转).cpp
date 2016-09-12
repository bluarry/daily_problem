#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */

//没有头结点
List Reverse( List L )
{
	List now,pre,nex;
	if(L==NULL) return L;
	if(L->Next==NULL) return L;
	pre=L;
	now=pre->Next;
	nex=now;
	while(now!=NULL)
	{
		nex=nex->Next;
		now->Next=pre;
		pre=now;
		now=nex;
	}
	L->Next=NULL;
	L=pre;
	return L;
}
