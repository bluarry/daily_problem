#include <cstdio>
#include <ctime>
#include <string>
#include <cstdlib>
#include <cstring>
#include <conio.h>
int mines[10][10];//���ڼ���ĵ���ͼ
int h,w,num,cmd,cnt_nice,cnt_have;//�����ͼ�ĸߣ���͵��׵�����,��͸ߵķ�ΧΪ1~9
bool visit[10][10];
char a[10][24];//��������ĵ���ͼ
const int dx[8]={1,0,-1,-1,-1,0,1,1};
const int dy[8]={1,1,1,0,-1,-1,-1,0};
//��ʼ������ͼ
void init(){
    a[0][0]=a[0][1]=' ';//��Щ������ֻ��Ϊ���������
    for(int j=2;j<=2*w;j++){
        if(j&1) a[0][j]=' ';
        else a[0][j]=j/2 + 48;
    }
    a[0][2*w+1]='\n';
    //��ʼ�����������
    for(int i=1;i<=h;i++){
        a[i][0]=i+48;
        a[i][1]='|';
        for(int j=2;j<=2*w;j++){
            if(j&1) a[i][j]=' ';
            else a[i][j]='*';
        }
        a[i][2*w+1]='\n';
    }
    cnt_nice=0;//ʵ��������
    cnt_have=0;//�Ѿ�������ʵ��������
    for(int i=4;i>=0;i--){//����ʵ���������Ϊ���������ı�
        if(i*num + num < h*w){
            cnt_nice=i*num;
            break;
        }
    }
    memset(visit,false,sizeof(visit));//��ʼ�����еĵ㶼δ���ʹ�
    memset(mines,0,sizeof(mines));//��ʼ�����еĵ㶼�ǿ�
    srand((unsigned)time(NULL));
    //�������ʵ��
    for(int k=0;k<cnt_nice;){
        int i=rand()%h + 1;
        int j=rand()%w + 1;
        if(mines[i][j]==0) mines[i][j]=1;
        else continue;
        k++;
    }
    //������ɵ���
    for(int k=0;k<num;){
        int i=rand()%h + 1;
        int j=rand()%w + 1;
        if(mines[i][j]==0) mines[i][j]=2;
        else continue;
        k++;
    }
}
//�������Ĳ���
void _scanf(){
    printf("��������ϣ���ĵ�ͼ�ĸ߶�(1~9):");
    while(scanf("%d",&h)==1 && (h<1 || h>9)) printf("����Ƿ�,�����������ͼ�ĸ߶�\n");
    printf("��������ϣ���ĵ�ͼ�Ŀ��(1~9):");
    while(scanf("%d",&w)==1 && (w<1 || w>9)) printf("����Ƿ�,�����������ͼ�Ŀ��\n");
    printf("��������ϣ���ĵ��׵�����:");
    while(scanf("%d",&num)==1 && (num<0 || num>=h*w/4)) printf("����Ƿ�,������������׵�����\n");
}
void dfs(int x,int y){
    //����λ������
    int fx[4]={1,0,0,-1};
    int fy[4]={0,1,-1,0};
    for(int i=0;i<4;i++){
        //��һ��Ҫ�����λ��
        int nowx=x+fx[i],nowy=y+fy[i];
        if(nowx>0 && nowx <=h && nowy>0 && nowy<=w &&!visit[nowx][nowy] && mines[nowx][nowy]==0){
            visit[nowx][nowy]=true;//���ó��Ѿ����ʹ���
            a[nowx][2*nowy]=' ';//�޸Ķ�Ӧλ�õ��ַ��Ա�����ʾ
            dfs(nowx,nowy);
        }
    }
}
//�����ǰ��ͼ������
void display(){
    for(int j=0;j<=2*w+1;j++) printf("%c",a[0][j]);
    printf("  ");
    for(int j=2;j<=2*w;j++) printf("_");
    printf("\n");
    for(int i=1;i<=h;i++)
        for(int j=0;j<=2*w+1;j++)
            printf("%c",a[i][j]);
    printf("����������㿪��λ��:");
}
int main(){
    while(true){
        printf("1:��ʼ��Ϸ\n");
        printf("0:�˳���Ϸ\n");
        scanf("%d",&cmd);
        if(!cmd) break;
        _scanf();
        init();
        display();
        do{
            int x,y;
            scanf("%d%d",&x,&y);
            if(mines[x][y]==2){//��������
                printf("Game Over!\n");
                break;
            }
            else if(mines[x][y]==0){//��ʱ�㵽�˿մ�
                visit[x][y]=true;
                a[x][2*y]=' ';
                dfs(x,y);
            }
            else{//��ʱ�㵽��ĳһ��ʵ��
                cnt_have++;
                if(cnt_have==h*w-num){//����ҳ������е�ʵ���ͳɹ���
                    printf("Congratulations!You Win!\n");
                    break;
                }
                visit[x][y]=true;
                int tnum=0;
                //Ѱ�����ܵĵ��׵�����
                for(int i=0;i<8;i++){
                    int nowx=x+dx[i];
                    int nowy=y+dy[i];
                    if(nowx>0 && nowx<=h && nowy>0 && nowy<=w && mines[nowx][nowy]==2) tnum++;
                }
                a[x][2*y]=tnum+48;
            }
            system("cls");//�����ǰ����Ļ
            display();
        }while(true);
    }
    return 0;
}
