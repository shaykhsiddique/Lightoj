#include<bits/stdc++.h>

/*
    |------------------------------------------------------------------|
    |             Bismillah Hir Rahman Nir Raheem                      |
    |------------------------------------------------------------------|
    |                                                                  |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█                  |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█                  |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█                  |
    |                                                                  |
    |                                          Country:Bangladesh/EWU  |
    |                                          Problem: LOJ-1049       |
    |------------------------------------------------------------------|
*/

#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pf printf
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

vector<int>graph[120];
bool in_degree[200];
bool out_degree[200];
int cost[150][150];
int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int test, n, u, v, w;
    sfi(test);
    repe(cc, 1, test){
        memset(in_degree, 0, sizeof(in_degree));
        memset(out_degree, 0, sizeof(out_degree));
        int left_dis=0, right_dis=0;
        memset(cost, 0, sizeof(cost));
        int total_dis=0;
        sfi(n);
        rep(i, 0, n){
            sfi2(u, v); sfi(w);
            graph[u].pb(v);

            if(!in_degree[u] and !out_degree[v]){
                in_degree[u]=out_degree[v]=true;
                left_dis+=w;
            }else{
                in_degree[v]=out_degree[u]=true;
                right_dis+=w;

            }
        }
        pfc(cc);
        pf("%d\n", min(left_dis, right_dis));
        repe(i, 0, n+2){
            graph[i].clear();
        }
    }

    return 0;
}
