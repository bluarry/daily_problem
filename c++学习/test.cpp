#include <cstdio>
#include <ctime>
#include <string>
#include <cstdlib>
#include <cstring>
#include <conio.h>
int mines[10][10];//用于计算的地雷图
int h,w,num,cmd,cnt_nice,cnt_have;//代表地图的高，宽和地雷的数量,宽和高的范围为1~9
bool visit[10][10];
char a[10][24];//用于输出的地雷图
const int dx[8]={1,0,-1,-1,-1,0,1,1};
const int dy[8]={1,1,1,0,-1,-1,-1,0};
//初始化地雷图
void init(){
    a[0][0]=a[0][1]=' ';//这些操作都只是为了输出对齐
    for(int j=2;j<=2*w;j++){
        if(j&1) a[0][j]=' ';
        else a[0][j]=j/2 + 48;
    }
    a[0][2*w+1]='\n';
    //初始化输出的数组
    for(int i=1;i<=h;i++){
        a[i][0]=i+48;
        a[i][1]='|';
        for(int j=2;j<=2*w;j++){
            if(j&1) a[i][j]=' ';
            else a[i][j]='*';
        }
        a[i][2*w+1]='\n';
    }
    cnt_nice=0;//实处的数量
    cnt_have=0;//已经翻开的实处的数量
    for(int i=4;i>=0;i--){//设置实处数量最多为地雷数的四倍
        if(i*num + num < h*w){
            cnt_nice=i*num;
            break;
        }
    }
    memset(visit,false,sizeof(visit));//初始化所有的点都未访问过
    memset(mines,0,sizeof(mines));//初始化所有的点都是空
    srand((unsigned)time(NULL));
    //随机生成实处
    for(int k=0;k<cnt_nice;){
        int i=rand()%h + 1;
        int j=rand()%w + 1;
        if(mines[i][j]==0) mines[i][j]=1;
        else continue;
        k++;
    }
    //随机生成地雷
    for(int k=0;k<num;){
        int i=rand()%h + 1;
        int j=rand()%w + 1;
        if(mines[i][j]==0) mines[i][j]=2;
        else continue;
        k++;
    }
}
//处理读入的操作
void _scanf(){
    printf("请输入你希望的地图的高度(1~9):");
    while(scanf("%d",&h)==1 && (h<1 || h>9)) printf("输入非法,请重新输入地图的高度\n");
    printf("请输入你希望的地图的宽度(1~9):");
    while(scanf("%d",&w)==1 && (w<1 || w>9)) printf("输入非法,请重新输入地图的宽度\n");
    printf("请输入你希望的地雷的数量:");
    while(scanf("%d",&num)==1 && (num<0 || num>=h*w/4)) printf("输入非法,请重新输入地雷的数量\n");
}
void dfs(int x,int y){
    //设置位移数组
    int fx[4]={1,0,0,-1};
    int fy[4]={0,1,-1,0};
    for(int i=0;i<4;i++){
        //下一步要移向的位置
        int nowx=x+fx[i],nowy=y+fy[i];
        if(nowx>0 && nowx <=h && nowy>0 && nowy<=w &&!visit[nowx][nowy] && mines[nowx][nowy]==0){
            visit[nowx][nowy]=true;//设置成已经访问过了
            a[nowx][2*nowy]=' ';//修改对应位置的字符以便于显示
            dfs(nowx,nowy);
        }
    }
}
//输出当前地图的样子
void display(){
    for(int j=0;j<=2*w+1;j++) printf("%c",a[0][j]);
    printf("  ");
    for(int j=2;j<=2*w;j++) printf("_");
    printf("\n");
    for(int i=1;i<=h;i++)
        for(int j=0;j<=2*w+1;j++)
            printf("%c",a[i][j]);
    printf("请输入你想点开的位置:");
}
int main(){
    while(true){
        printf("1:开始游戏\n");
        printf("0:退出游戏\n");
        scanf("%d",&cmd);
        if(!cmd) break;
        _scanf();
        init();
        display();
        do{
            int x,y;
            scanf("%d%d",&x,&y);
            if(mines[x][y]==2){//触到地雷
                printf("Game Over!\n");
                break;
            }
            else if(mines[x][y]==0){//此时点到了空处
                visit[x][y]=true;
                a[x][2*y]=' ';
                dfs(x,y);
            }
            else{//此时点到了某一个实处
                cnt_have++;
                if(cnt_have==h*w-num){//如果找出了所有的实处就成功了
                    printf("Congratulations!You Win!\n");
                    break;
                }
                visit[x][y]=true;
                int tnum=0;
                //寻找四周的地雷的数量
                for(int i=0;i<8;i++){
                    int nowx=x+dx[i];
                    int nowy=y+dy[i];
                    if(nowx>0 && nowx<=h && nowy>0 && nowy<=w && mines[nowx][nowy]==2) tnum++;
                }
                a[x][2*y]=tnum+48;
            }
            system("cls");//清除当前的屏幕
            display();
        }while(true);
    }
    return 0;
}
