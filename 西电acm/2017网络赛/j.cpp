#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=1000;
const int INF=9999999;
struct Edge{
    int f,t,d;
};
struct HeapNode{
    int d,u;
    bool operator < (const HeapNode &H)const {
        return d > H.d;
    }
};
struct Dijkstra{
    int n,m,d[maxn];
    bool done[maxn];
    vector<Edge>edges;
    vector<int> G[maxn];
    void init(int n){
        this->n=n;
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int f,int t , int d){
        edges.push_back((Edge){f,t,d});
        int m=edges.size();
        G[f].push_back(m-1);
    }
    void solve(int s){
        priority_queue<HeapNode> Q;
        for(int i=0;i<n;i++) d[i]=INF;
        d[s]=0;
        memset(done,0,sizeof(done));
        Q.push((HeapNode){0,s});
        while (!Q.empty()){
            HeapNode x=Q.top();Q.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]=true;
            for(int i=0;i<G[u].size();i++)
            {
                Edge &e=edges[G[u][i]];
                if(d[e.t] > d[u]+e.d)
                {
                    d[e.t]=d[u]+e.d;
                    Q.push((HeapNode){d[e.t],e.t});
                }
            }
        }
    }
}H;

int main()
{
    // Dijkstra H;
    int n,m;
    int count;
    cin >>count;
    while(count --){
        cin >> m;
        n=m;
        H.init(100);
        while(m--){
            int f,t,d;
            cin >> f >> t >> d;
            H.AddEdge(f-1,t-1,d);
            H.AddEdge(t-1,f-1,d);
        }
        int fr,to;
        cin >> fr >> to;
        H.solve(fr-1);
        cout << H.d[to-1] *2 << endl;

    }
    return 0;
}
