#include<bits/stdc++.h>

/*
    |--------------------------------------------------------------|
    |                                                              |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█              |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█              |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█              |
    |                                                              |
    |                                          Country:Bangladesh  |
    |                                          Problem:LOJ1094     |
    |--------------------------------------------------------------|
*/

#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pf(n) printf("%d", n)
#define pfc(i) printf("Case %d: ", i)
#define pfn(n) printf("%d\n", n)
#define pfdn(n) printf("%f\n", n)
#define pb push_back
#define bl printf("\n")
#define spc putchar(' ')
#define fli() freopen("in.txt","r",stdin)
#define flo() freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define debug(x) cerr << #x << " : " << x << endl
#define find puts("I am here")
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

              // Shaykh Siddique
#define size_n 30010
vector<int>cost[size_n];
bool visit[size_n];
int path_dis[size_n];
vector<int>graph[size_n];

int bfs(int src=0){
    queue<int>q;
    q.push(src);
    int mx_dis=0;
    path_dis[src]=0;
    int far_node;
    while(!q.empty()){
        int u= q.front();
        q.pop();
        visit[u]=true;
        rep(i, 0, graph[u].size()){
            int v = graph[u][i];
            if(!visit[v]){
                q.push(v);
                int wt=cost[u][i];
                path_dis[v]=path_dis[u]+wt;
                if(path_dis[v]>mx_dis){
                    mx_dis=path_dis[v];
                    far_node=v;
                }
            }
        }
    }
    return far_node;
}

int bfs2(int src){
    queue<int>q;
    q.push(src);
    int mx_dis=0;
    path_dis[src]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        visit[u]=true;
        rep(i, 0, graph[u].size()){
            int v=graph[u][i];
            if(!visit[v]){
                int wt=cost[u][i];
                path_dis[v]=path_dis[u]+wt;
                if(path_dis[v]>mx_dis){
                    mx_dis=path_dis[v];
                }
                q.push(v);
            }
        }
    }
    return mx_dis;
}



int main(){
//fli();
//flo();
    int test, u, v, w, n;
    sfi(test);
    repe(cc, 1, test){
        sfi(n);
        rep(i, 0, n+5){
            graph[i].clear();
            cost[i].clear();
        }
        rep(i, 0, n-1){
            sfi2(u,v); sfi(w);
            graph[u].pb(v);
            graph[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        memset(visit, 0, sizeof(visit));
        int far_dis=bfs(0);
        memset(visit, 0, sizeof(visit));
        int mx_wt=bfs2(far_dis);
        pfc(cc);
        pfn(mx_wt);


    }
    return 0;
}
