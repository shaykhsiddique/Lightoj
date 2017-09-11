#include<bits/stdc++.h>

/*
    |------------------------------------------------------------------|
    |                                                                  |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█                  |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█                  |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█                  |
    |                                                                  |
    |                                          Country:Bangladesh/EWU  |
    |                                          Problem:LOJ-1111        |
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
typedef pair<int, int> Pair;

              // code starts from here

#define node 10000

vector<int>graph[node+5];
vector<int>source;
bool visit[node+5];
int visited[1000+5];

void bfs(int src){
    memset(visit, 0, sizeof(visit));
    queue<int>q;
    q.push(src);
    visited[src]++;
    while(!q.empty()){
        int u= q.front();
        q.pop();
        visit[u]=true;
        rep(i, 0, graph[u].size()){
            int v=graph[u][i];
            if(!visit[v]){
                visit[v]=true;
                visited[v]++;
                q.push(v);
            }
        }
    }
}


int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int test, k, n, m, s, u, v;
    sfi(test);
    repe(cc, 1, test){
        pfc(cc);
        source.clear();
        memset(visited, 0, sizeof(visited));
        sfi2(k, n);sfi(m);
        repe(i, 0, n) graph[i].clear();
        rep(i, 0, k){
            sfi(s);
            source.pb(s);
        }
        while(m--){
            sfi2(u, v);
            graph[u].pb(v);  //because this is an unidirected graph
        }
        rep(i, 0, source.size()){
            bfs(source[i]);
        }
        int cont=0;
        repe(i, 0, n){
            if(visited[i]==k)
                cont++;
        }
        pfn(cont);
    }

    return 0;
}
