#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <time.h>

using namespace std;

const int maxn=200;

int mo,bi;


void setvalue(int l[]) //为数组赋值，并输出
{
    for(int i=0;i<maxn;i++)
    {
        l[i]=rand()%maxn;
    }
    cout << endl;
}
void printlist(int l[])     //打印数组
{
    for(int i=0;i<maxn;i++)
    {
        i!=maxn-1 ? cout << l[i]<<" ":cout << l[i]<<endl;
    }
}
void bublesort(int l[])      //冒泡排序
{
    for(int j= maxn-1;j>0;j--)
    for(int i=0;i<j;i++)
        if(bi++,l[i]>l[i+1])
        {
            swap(l[i],l[i+1]);
            mo=mo+3;
        }

}
void insertsort(int l[])    //直接插入sort
{
    int j=0;
    for(int i=1;i<maxn;i++)
        if(bi++,l[i]<l[i-1])
        {
            int tem=l[i];
            l[i]=l[i-1]; mo+=3;
            for(j=i-2;l[j]>tem&&j>=0;j--) l[j+1]=l[j],mo++;
            l[j+1]=tem;
        }
}
//简单选择排序
int selectmin(int l[],int i){
    int minn=maxn+1;
    int k=i;
    for(int j=i;j<maxn;j++)
        if(bi++,l[j]<minn)
        {
            minn=l[j];
            k=j;
        }
    return k;
}
void simpleinsertsort(int l[])
{
    for(int i=0;i<maxn;i++)
    {
        int j=selectmin(l,i);
        if(i!=j)swap(l[i],l[j]),mo+=3;
    }
}

//快速排序
int qusort(int l[],int low,int high)
{
    int m=l[low];
    while(bi++,low<high)
    {
        while(low<high && l[high]>=m) high--;
        l[low]=l[high];mo++;
        while(low<high && l[low]<=m)    low++;
        l[high]=l[low];mo++;
    }
    l[low]=m;mo++;
    return low;
}
void quicksort(int l[],int low,int high)
{
    if(low<high)
    {
        int mid=qusort(l,low,high);
        quicksort(l,low,mid-1);
        quicksort(l,mid+1,high);
    }
}
//希尔排序
void shellsort(int l[],int dk)
{
  for(int i=dk;i<maxn;i++)
  {
    if(bi++,l[i]<l[i-dk])
    {
        int m=l[i];
        int j;
        for(j=i-dk;j>=0&&(l[j]>m);j-=dk) l[j+dk]=l[j],mo++;
        l[j+dk]=m;
        mo+=3;
    }
  }
}
void shellrsort(int l[])
{
    int x[]={20,17,15,13,11,9,7,5,3,1};
    int size=sizeof(x)/sizeof(int);
    for(int i=0;i<size;i++)
        shellsort(l,x[i]);
}



//堆排序
//本函数功能是：根据数组array构建大根堆
void HeapAdjust(int array[],int i,int nLength)
{
    int nChild;
    int nTemp;
    for(;bi++,2*i+1<nLength;i=nChild)
    {
        //子结点的位置=2*（父结点位置）+1
        nChild=2*i+1;
        //得到子结点中较大的结点
        if(bi++,nChild<nLength-1&&array[nChild+1]>array[nChild])++nChild;
        //如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
        if(bi++,array[i]<array[nChild])
        {
            nTemp=array[i];
            array[i]=array[nChild];
            array[nChild]=nTemp;
            mo+=3;
        }
        else break; //否则退出循环
    }
}
//堆排序算法
void HeapSort(int array[],int length)
{
    int i;
    //调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    //length/2-1是最后一个非叶节点，此处"/"为整除
    for(i=length/2-1;i>=0;--i)
    HeapAdjust(array,i,length);
    //从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for(i=length-1;i>0;--i)
    {
        //把第一个元素和当前的最后一个元素交换，
        //保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        array[i]=array[0]^array[i];
        array[0]=array[0]^array[i];
        array[i]=array[0]^array[i];

        mo+=3;
        //不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(array,0,i);
    }
}
void arryset(int list[],int ll[])
{
    for(int i=0;i<maxn;i++)
    {
        list[i]=ll[i];
    }
}
int main()
{
    srand(time(0));
    int xx=6;
  while(xx--)
{    int list[maxn],ll[maxn];
    setvalue(ll);
     cout << "生成的数组为 : ";
       printlist(ll);
       int start=0,end=0;


       cout <<"\n冒泡排序: "<< endl;
       mo=0,bi=0;
       arryset(list,ll);
       start=clock();
       bublesort(list);    // 冒泡排序
        end=clock();
       cout << "移动次数　：" << mo<< setw(20) << "比较次数 :" << bi << setw(40)<< "比较所用时间为(ms)　："<< end-start << endl;


       cout <<"\n直接插入排序: "<< endl;
       mo=0,bi=0;
        arryset(list,ll);
         start=clock();
       insertsort(list);   //直接插入排序
        end=clock();
       cout << "移动次数　：" << mo << setw(20) << "比较次数 :" << bi<< setw(40)<< "比较所用时间为(ms)　："<< end-start<< endl;



       cout <<"\n简单选择排序: "<< endl;
       mo=0,bi=0;
       arryset(list,ll); start=clock();
       simpleinsertsort(list);//简单选择排序
        end=clock();
       cout << "移动次数　：" << mo << setw(20) << "比较次数 :" << bi<< setw(40)<< "比较所用时间为(ms)　："<< end-start<< endl;


       cout <<"\n快速排序: "<< endl;
       mo=0,bi=0;
       arryset(list,ll); start=clock();
        quicksort(list,0,maxn-1);    //快速排序
         end=clock();
        cout << "移动次数　：" << mo << setw(20) << "比较次数 :" << bi << setw(40)<< "比较所用时间为(ms)　："<< end-start<< endl;




        cout <<"\n希尔排序: "<< endl;
        mo=0,bi=0;
        arryset(list,ll); start=clock();
        shellrsort(list);    //希尔排序
         end=clock();
        cout << "移动次数　：" << mo << setw(20) << "比较次数 :" << bi<< setw(40)<< "比较所用时间为(ms)　："<< end-start<< endl;


        cout <<"\n堆排序: "<< endl;
        mo=0,bi=0;
        arryset(list,ll); start=clock();
        HeapSort(list,maxn);    //堆排序
         end=clock();
        cout << "移动次数　：" << mo << setw(20) << "比较次数 :" << bi<< setw(40)<< "比较所用时间为(ms)　："<< end-start<< endl;
}
    return 0;
}


