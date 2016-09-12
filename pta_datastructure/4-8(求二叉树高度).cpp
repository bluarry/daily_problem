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

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
/* 你的代码将被嵌在这里 */
//1
int GetHeight( BinTree BT )
{
	if(BT==NULL) return 0;  
    else  
    {  
        int m = GetHeight(BT->Left );  
        int n = GetHeight(BT->Right);  
        return (m > n) ? (m+1) : (n+1);   
    }  
}
//2
#define max(a,b)  a>b?a:b; 
int GetHeight( BinTree BT )
{
	if(BT==NULL)
		return 0;
	else
		return max(GetHeight(BT->Left)+1,GetHeight(BT->Right)+1);
}
