#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 17;
const int dx[] = {-1, 0, 1, 0, 0};
const int dy[] = { 0,-1, 0, 1, 0};

int grid[N][N], state[N][N], tmp[N][N], rec[N][N];

int n, m, ans;
void flip(int x, int y) {
    tmp[x][y] = 1;
    int nx, ny;
    for(int i = 0; i < 5; i++) {
        nx = x+dx[i];
        ny = y+dy[i];
        state[nx][ny] = !state[nx][ny];
    }
}

bool isEmpty(int n) {
    for(int j = 1; j <= m; j++) {
        if(state[n][j])
            return false;
    }
    return true;
}

void solve(int st) {
    memcpy(state, grid, sizeof(grid));
    memset(tmp, 0, sizeof(tmp));

    int cnt = 0;
    for(int j = 0; j < m; j++) {
        if((st>>j) & 1) {
            flip(1, j+1);
            cnt++;
        }
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(state[i-1][j] == 1) {
                flip(i, j);
                cnt++;
            }
        }
    }

    if(isEmpty(n) && cnt < ans) {
        ans = cnt;
        memcpy(rec, tmp, sizeof(tmp));
    }
}

int main() {
	freopen("in.txt","r",stdin);
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        ans = INF;
        int end = 1 << m;

        for(int st = 0; st < end; st++)
            solve(st);

        if(ans == INF)
            puts("IMPOSSIBLE");
        else {
            for(int i = 1; i <= n; i++) {
                printf("%d", rec[i][1]);
                for(int j = 2; j <= m; j++)
                    printf(" %d", rec[i][j]);
                puts("");
            }
        }
    }
    return 0;
}
