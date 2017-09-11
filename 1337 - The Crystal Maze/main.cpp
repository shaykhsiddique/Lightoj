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
    |                                          Problem:Lightoj-1337    |
    |------------------------------------------------------------------|
*/

#define sfi(n) scanf("%d", &n)
#define sf scanf
#define pf printf
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pfc(i) printf("Case %d:\n", i)
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
#define fi first
#define se second
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

#define PAIR pair<int, int>
#define sz 510
int dir_x[] = {-1,1,0,0};
int dir_y[] = {0,0,-1,1};
char grid[sz][sz];
int grid_co[sz][sz];
bool visit[sz][sz];
bool visit2[sz][sz];
int m, n;

int bfs(int i, int j){
    memset(visit2, 0, sizeof(visit2));
    queue<PAIR>q;
    q.push({i, j});
    int max_cy=0;
    int cont_cy=0;
    visit[i][j]=true;
    visit2[i][j]=true;
    while(!q.empty()){
        int x=q.front().fi;
        int y=q.front().se;
        q.pop();
        rep(cc, 0, 4){
            i= x + dir_x[cc];
            j= y + dir_y[cc];
            if(i>-1 and i<m and j>-1 and j<n and grid[i][j]!='#' and !visit[i][j]){
                if(grid[i][j]=='C'){
                    cont_cy++;
                }
                max_cy=max(max_cy, cont_cy);
                visit[i][j]=true;
                visit2[i][j]=true;
                q.push({i, j});
            }
        }
    }
    return max_cy;
}

void graph_update(int mx){
    rep(i, 0, m){
        rep(j, 0, n){
            if(visit2[i][j]){
                grid_co[i][j]=mx;
            }
        }
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//fli();
//flo();
    int test, q, x, y;
    cin>>test;
    repe(cc, 1, test){
        cin>>m>>n>>q;
        rep(i, 0, m){
            rep(j, 0, n){
                cin>>grid[i][j];
            }
        }
        cout<<"Case "<<cc<<":"<<endl;
        memset(visit, 0, sizeof(visit));
        rep(i, 0, q){
            cin>>x>>y;
            if(!visit[x-1][y-1]){
               int mex =bfs(x-1, y-1);
                graph_update(mex);
            }
            cout<<grid_co[x-1][y-1]<<endl;
        }
    }

    return 0;
}
