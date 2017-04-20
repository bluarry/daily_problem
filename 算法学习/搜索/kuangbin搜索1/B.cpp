//#define TEST
#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <queue>
using namespace std;
int l,c,r;
int i_map[30][30][30];
int s_x,s_y,s_z;
int e_x,e_y,e_z;
int dir_x[]={1,-1,0,0,0,0};
int dir_y[]={0,0,1,-1,0,0};
int dir_z[]={0,0,0,0,1,-1};

struct Node
{
	int x,y,z,tot;
};

void readmap()
{
	memset(i_map,0,sizeof(i_map));

	for(int k=0;k<l;k++)
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				char c;
				cin >> c;
				if(c=='S') s_x=i,s_y=j,s_z=k,i_map[i][j][k]=1;
				else if(c=='E') e_x=i,e_y=j,e_z=k,i_map[i][j][k]=1;
				else if(c=='.') i_map[i][j][k]=1;
			}
}

int bfs(int x,int y,int z)
{
	queue<Node> Q;

	Q.push((Node){x,y,z,0});


	while(!Q.empty())
	{
		Node N=Q.front();Q.pop();
		int xx=N.x,yy=N.y,zz=N.z;
		if(xx==e_x && yy== e_y && zz== e_z)
		{
			return N.tot;
		}
		for(int q=0;q<6;q++)
		{
			int newx=xx+dir_x[q],newy=yy+dir_y[q],newz=zz+dir_z[q];
			if(newx>=0 && newx<r && newy >=0 && newy <c && newz >=0&& newz <l && i_map[newx][newy][newz])
			{
				i_map[newx][newy][newz]=0;
				Q.push((Node){newx,newy,newz,N.tot+1});
			}		

		}
	}
	return -1;
}


int main()
{
	#ifdef TEST
	freopen("in.txt","r",stdin);
	#endif
	//int start=clock();
	while(cin >> l >> r >> c,l&&c&&r)
	{

		readmap();			
		int tot=bfs(s_x,s_y,s_z);
		if(tot!=-1){
			cout <<"Escaped in "<< tot <<" minute(s)."<< endl;
		}
		else 
			cout<< "Trapped!" << endl;

			
	}

//
//	int end=clock();
	//cout << "The running time is " << end-start << "ms\n";
	return 0;
}
