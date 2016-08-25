#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List Tbl, ElementType K );

int main()
{
    List Tbl;
    ElementType K;
    Position P;

    Tbl = ReadInput();
    scanf("%d", &K);
    P = BinarySearch( Tbl, K );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */

/*
Tbl是用户传入的一个线性表，其中ElementType元素可以通过>、====、<进行比较，
并且题目保证传入的数据是递增有序的。函数BinarySearch要查找K在Tbl中的位置，
即数组下标（注意：元素从下标1开始存储）。找到则返回下标，否则返回一个特殊的失败标记NotFound。
*/
Position BinarySearch( List Tbl, ElementType K )
{
    Position low=1,high=Tbl->Last,mid;
    while(low <= high)
    {
        mid=(low+high)/2;
        if(Tbl->Data[mid] < K )
        {
            low=mid+1;
        }
        else if(Tbl->Data[mid]>K)
        {
            high=mid-1;
        }
        else if(Tbl->Data[mid] == K)
        {
            return mid;
        }
    }
    return NotFound;
}
