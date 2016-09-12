/*************************顺序表及其操作集*****************************/
typedef int Status;
#define ERROR 0
#define OK 1
#define LIST_INIT_SIZE 100
#define LISTINCREASE 10
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;


void IniList(SqList &L){ //初始化线性表
	L.elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if(!L.elem) exit(0);
	L.length=0;
	L.listsize=0;
}

void DestroyList(SqList &L){ 	//若线性表L存在，销毁它
	free(L.elem);
	L.elem=NULL;
	L.length=0;
	L.listsize=0;
}
void ClearList(SqList& L){ 	//清空线性表
	L.length=0;
}
Status ListEmpty(SqList &L) //判断线性表是不是空表
{
	if(L.length==0)
		return true;
	else
		return false;
}
int ListLength(SqList L) //返回线性表的长度
{	
	return L.length;
}

Status GetElem(SqList L,int i,ElemType &e){  //同e返回要查找的的第i个元素
	if(i<1 || i> L.length)
		return ERROR;
	e=*(L.elem+i-1);
	return OK;
}

//在线性表中查找和e相等的元素的位置
int LocateElem(SqList L,ElemType e){
	int i=1;
	ElemType *p=L.elem;
	while(i<L.length && (*p++) != e)
	{	
		i++;
	}
	if(i<L.length)
		return i;
	else
		return 0;

}
//若pre_e是线性表的元素，并且不是第一个元素，那么就返回它的前驱结点，否则，操作失败
 Status PriiorELem(SqList L,ElemType cur_e,ElemType &pre_e){
 	int i=2;
 	ElemType *p =L.elem+1;
 	while(i<L.length && *p!=cur_e)
 	{
 		p++;i++;
 	}
 	if(i>L.length) return ERROR;
 	else
 	{
 		pre_e=*p--;
 		return OK;
 	}

 }
//返回cur_e的后继节点
 Status NextElem(SqList L,ElemType cur_e,ElemType &next_e){
 	int i=1;
 	ElemType *p=L.elem;
 	while(i<L.length && *p!=cur_e)
 	{
 		p++;i++;
 	}
 	if(i>L.length) return ERROR;
 	else 
 	{
 		next_e=* ++p;
 		return OK;
 	}

 }

//在线性表中插入e
Status ListInsert(SqList &L, int i,ElemType e)
{
	ElemType *newbase,*q,*p;
	if(i<0||i>L.length) return ERROR;
	if(L.length==L.listsize)
	{
		newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREASE)*sizeof(ElemType));
		if(!newbase) exit(0);
		L.elem=newbase;
		L.listsize+=LISTINCREASE;
	}
	q=L.elem+i-1;
	for(p=L.elem+L.length-1;p>=q;p--)
		*(p+1)=*p;
		*q=e;
		L.length++;
		return OK;
}
//线性表中删除元素i,并用e返回
Status ListDelete(SqList &L,int i,ElemType &e)
{
	ElemType *p,*q;
	if(i<1 || i>L.length)
		return ERROR;
	p=L.elem+i-1;
	e=*p;
	q=L.elem+L.length-1;
	for(p++;p<=q;p++)
		*(p-1)=*p;
	L.length--;
	return OK;
}









