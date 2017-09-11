#include<bits/stdc++.h>

/*
    |--------------------------------------------------------------|
    |                                                              |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█              |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█              |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█              |
    |                                                              |
    |                                          Country:Bangladesh  |
    |                                          Problem:LOJ-1174    |
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
#define mem(arr, x) memset(arr, x, sizeof(arr))
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

              // Shaykh Siddique
#define nd_sz 250

vector<int>graph[nd_sz];

bool visit[nd_sz];
int time1[nd_sz];
int time2[nd_sz];

void bfs(int src, int *time){
    queue<int>q;
    q.push(src);
    time[src]=0;
    visit[src]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        rep(i, 0, graph[u].size()){
            int v=graph[u][i];
            if(!visit[v]){
                time[v]=time[u]+1;
                visit[v]=true;
                q.push(v);
            }
        }
    }
}

inline int max_num(int a, int b, int c){
    return max(a, max(b, c));
}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int test, n, r, u, v;
    sfi(test);
    repe(cc, 1, test){
        sfi2(n, r);
        rep(i, 0, n){
            graph[i].clear();
        }
        pfc(cc);
        while(r--){
            sfi2(u, v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        sfi2(u, v);
        mem(time1, 0);
        mem(visit, 0);
        bfs(u, time1);
        mem(time2, 0);
        mem(visit, 0);
        bfs(v, time2);
        int mx_time=0;
        rep(i, 0, n){
            mx_time=max(mx_time, time1[i]+time2[i]);
        }
        pfn(mx_time);
    }

    return 0;
}
