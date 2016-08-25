#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
/*
本题要求实现给定二叉搜索树的5种常用操作。
函数接口定义：

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );
函数Insert将X插入二叉搜索树BST并返回结果树的根结点指针；
函数Delete将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回
原树的根结点指针；
函数Find在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针；
函数FindMin返回二叉搜索树BST中最小元结点的指针；
函数FindMax返回二叉搜索树BST中最大元结点的指针。
*/
Position Find( BinTree BST, ElementType X )
{
    while(BST)
    {
         if(X > BST->Data)
            BST=BST->Right;
         else if(X < BST->Data)
            BST=BST->Left;
        else 
            return BST;
    }
    return NULL;
}
Position FindMin( BinTree BST )
{
    if(!BST)
      return NULL;
    else if(!BST->Left)
      return BST;
    else
        return FindMin(BST->Left);
}
Position FindMax( BinTree BST ){
    if(BST)
        while(BST->Right!=NULL) BST=BST->Right;

    return BST;
}

BinTree Insert( BinTree BST, ElementType X )
{
    if(!BST)
    {
        BST=(BinTree)malloc(sizeof( struct TNode));
        BST->Right=BST->Left=NULL;
        BST->Data=X;
    }
    else
    {
        if(X > BST->Data)
            BST->Right= Insert( BST->Right,X );
        else if(X< BST->Data)
            BST->Left= Insert(BST->Left,X);
    }
    return BST;
}
BinTree Delete( BinTree BST, ElementType X ){
    Position tep;
    if(!BST) printf("Not Found\n");
    else{
        if(X < BST->Data)
            BST->Left=Delete(BST->Left,X);
        else if(X  >  BST->Data)
            BST ->Right= Delete(BST->Right,X); 
        else
        {
            if(BST->Left && BST -> Right) //左右都不空
            {
                //将问题转化为，在右子树找到最小元素，替换该元素，并删除右子树中该最小元
                tep=FindMin(BST->Right);
                BST->Data=tep->Data;
                BST->Right=Delete(BST->Right,tep->Data);
            }
            else
            {
                tep=BST;
                if(!BST->Left)
                    BST=BST->Right;
                else if(!BST->Right)
                    BST=BST->Left;
                free(tep);
            }
        }
    }
    return BST;
}
