#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    char pha;
   struct node *left,*right;
    node ()
    {
        pha='#';
        left=right=NULL;
    }
}node,*Tree;

void creatTree(Tree& T){
    string s;
    cin >> s;
    int k=0;
    T=new node();
    queue<Tree> q;
    q.push(T);
    while(!q.empty() && k<s.length() )
    {
        Tree h=q.front();
        q.pop();
        h->left=new node();
        q.push(h->left);
        h->right=new node();
        q.push(h->right);
        h->pha=s[k++];
    }
}
void pre(Tree T){
    if(T)
    {
        if(T->pha!='#')
        cout << T->pha;
        pre(T->left);
        pre(T->right);
    }
}


int main()
{
   Tree T;
    creatTree(T);
    pre(T);cout<< endl;
    return 0;
}
