#include<bits/stdc++.h>

/*
    |------------------------------------------------------------------|
    |                                                                  |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█                  |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█                  |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█                  |
    |                                                                  |
    |                                          Country:Bangladesh/EWU  |
    |                                          Problem:LOJ-1019        |
    |------------------------------------------------------------------|
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

              // Code starts from here

vector<int>graph[1010];
int cost[1010][1010];
int dis[1010];

void dijkstra(int src, int des){
    priority_queue<int>q;
    q.push(src);
    dis[src]=0;
    while(!q.empty()){
        int u=q.top();
        q.pop();
        rep(i, 0, graph[u].size()){
            int v=graph[u][i];
            if(dis[u]+cost[u][v]<dis[v]){
                dis[v]=dis[u]+cost[u][v];
                q.push(v);
            }
        }
    }
}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
fli();
//flo();
    int test, n, m, u, v, w;
    sfi(test);
    repe(cc, 1, test){
        pfc(cc);
        sfi2(n, m);
        rep(i, 0, n+1){
            graph[i].clear();
        }
        rep(i, 0, n+5){
        dis[i]=INT_MAX;
    }
        memset(cost, 0, sizeof(cost));
        rep(i, 0, m){
            sfi2(u, v);
            sfi(w);
            graph[u].pb(v);
            graph[v].pb(u);
            cost[u][v]=w;
            cost[v][u]=w;
        }
        dijkstra(1, m);
        if(dis[n]>=INT_MAX or dis[n]<0)
            puts("Impossible");
        else
            pfn(dis[n]);
    }

    return 0;
}
