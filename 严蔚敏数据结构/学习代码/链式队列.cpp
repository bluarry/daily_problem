typedef char Elemtype;
typedef struct Qnode{
	Elemtype data;
	struct Qnode *next;
}Qnode,*quen;
typedef struct {
	quen front, rear;
}linkquen;

void initQUen(linkquen *q){
	q->front=q->rear=(quen)malloc(sizeof(Qnode));	
	if(!q->front)exit(0);
	q->front->next=NULL;
	
}
void insertquen(linkquen *q,Elemtype e)
{
	quen p=(quen)malloc(sizeof(Qnode));
	if(!p) exit(0);
	p->data=e;
	p->next=NULL;
	q->rear->next=p;
	q->rear=p;
}
void outquen(linkquen *q,Elemtype *e){
	quen p;
	if(q->front==q->rear)return ;
	p=q->front->next;
	q->front->next=p->next;
	*e=p->data;
	if(q->rear==p)q->rear=q->front;
	free(p);
}
int isempty(linkquen *q)
{
	if(q->rear==q->front)return 0;
	else return 1;
}