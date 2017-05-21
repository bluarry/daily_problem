#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <queue>
#define each(i,n) (int i=1;i<=(n);++i)
#define INF 0x3f3f3f3f

using namespace std;

int row,col;
int arr[20][20];
int flip[20][20],ans[20][20];
int dir[5][2] = {
    0,0, 0,1, 0,-1, -1,0, 1,0 
};

int get(int x,int y) {
    int c = arr[x+1][y+1];
    for(int i = 0;i<5;i++) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx >=0 && dx<row && dy>=0 && dy<col) {
            c+=flip[dx][dy];
        }
    }
    return c&1; // with flip state, if odd return 1
}

int calc() {
    for each(i,row-1) {
        for(int j = 0;j<col;j++) {
            if(get(i-1,j)) ++flip[i][j];
        }
    }
    for(int i=0;i<col;i++) { // check last line
        if(get(row-1,i)) return 0;
    }
    int cnt = 0;
    for (int i=0;i<row;i++) { //统计翻转的次数  
        for (int j=0;j<col;j++) {
            cnt += flip[i][j];  
        }
    }
    return cnt;
}


void doWork() {
    int cnt = INF;
    for(int i=0;i<(1<<col);i++) { //from 0000 to 1111
        memset(flip,0,sizeof(flip));
        for(int j=0;j<col;j++) {
            flip[0][col-j-1] = (i>>j)&1; //get pos state form binary number
        }
        int num = calc();
        if (num<cnt && num!=0) {
            cnt = num;
            memcpy(ans,flip,sizeof(flip));
        }
    }
    if (cnt==INF) printf("IMPOSSIBLE\n");
    else {
        for (int i=0;i<row;i++) {  
            printf("%d",ans[i][0]);  
            for each(j,col-1) {
                printf(" %d",ans[i][j]);
            }
            printf("\n");  
        }
    }
}

int main() {
    
    while(~scanf("%d%d",&row,&col)) {
        memset(arr,0,sizeof(arr));
        for each(i,row) {
            for each(j,col) {
                scanf("%d",&arr[i][j]);
            }
        }
        
        doWork();
    }
    
}