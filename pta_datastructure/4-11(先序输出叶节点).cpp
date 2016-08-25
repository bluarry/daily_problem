#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void CreatbiTree(BinTree *T){
	char c;
	
	scanf("%c",&c);
	if(' '==c)
	{
		*T=NULL;
	}
	else{
		*T=(struct TNode *)malloc(sizeof(struct TNode));
		(*T)->Data=c;
		CreatbiTree(&(*T)->Left);
		CreatbiTree(&(*T)->Right);
	}
}

BinTree CreatBinTree() /* 实现细节忽略 */
{
	BinTree BT;
	CreatbiTree(&BT);
	return BT;
}
void PreorderPrintLeaves( BinTree BT );

int main()
{
	freopen("D:\\in.txt","r",stdin);
    BinTree BT = CreatBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
void visit( BinTree BT )
{
	printf(" %c", BT->Data);
}
void PreorderPrintLeaves( BinTree BT )
{
	if(BT==NULL)
		return;
	else
	{
		if(BT->Left==NULL && BT->Right==NULL)
			visit(BT);
		PreorderPrintLeaves(BT->Left);
		PreorderPrintLeaves(BT->Right);
	}
}
