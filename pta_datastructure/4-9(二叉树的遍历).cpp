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
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
	freopen("D:\\in.txt","r",stdin);
    BinTree BT = CreatBinTree();
    //printf("Preorder:");   PreorderTraversal(BT);   printf("\n");	//前序遍历
    printf("Inorder:");    InorderTraversal(BT);    printf("\n"); //中序遍历
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");	//前序遍历
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");	//后续遍历
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */
/*

要求4个函数分别按照访问顺序打印出结点的内容，格式为一个空格跟着一个字符。
*/
#define MaxSize 100
char str[100];
void visit(BinTree B)
{
	printf(" %c", B->Data);
}

//***********************************************************定义队列
typedef BinTree elemtype;

typedef struct
{
	elemtype *base;
	int front;
	int rear;
}QNode,quen;

void initQUen(quen *q){
	q->base=(elemtype *)malloc(sizeof(elemtype)* MaxSize);
	if(!q->base)return ;
	q->rear=q->front=0;
}
void insertquen(quen *q,elemtype e)
{
	if(((q->rear)+1)%MaxSize==q->front) return;
	q->base[q->rear]=e;
	q->rear=((q->rear)+1)%MaxSize;
}
void outquen(quen *q,elemtype *e){
	if(q->rear==q->front)return;
	*e=q->base[q->front];
	q->front=((q->front)+1)%MaxSize;
}
int isimpty(quen *s)
{
	if(s->front==s->rear)return 0;
	else return 1;
}
//****************************************************以上队列及其操作集
void LevelorderTraversal( BinTree BT )//层序遍历  bfs
{
	quen q;
	initQUen(&q);
	insertquen(&q,BT);
	while(isimpty(&q))
	{
		BinTree tmp;
		outquen(&q,&tmp); if(tmp==NULL) continue;
		insertquen(&q,tmp->Left);
		insertquen(&q,tmp->Right);
		visit(tmp);
	}
}


void InorderTraversal( BinTree BT ) //中序遍历
{
	if(BT!=NULL)
	{
		InorderTraversal(BT->Left);
		visit(BT);
		InorderTraversal(BT->Right);
	}
}
void PreorderTraversal( BinTree BT ) //先序遍历
{
	if(BT!=NULL)
	{
		visit(BT);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}
void PostorderTraversal( BinTree BT )//后序遍历
{
	if(BT!=NULL)
	{
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		visit(BT);
	}
}

