#include<bits/stdc++.h>

/*
    |--------------------------------------------------------------|
    |                                                              |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█              |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█              |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█              |
    |                                                              |
    |                                          Country:Bangladesh  |
    |                                          Problem:LOJ-1238    |
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

              // Code starts from here........
#define sz 25
#define PAIR pair<int, int>
int dir_x[] = {-1,1,0,0};
int dir_y[] = {0,0,-1,1};

char grid[sz][sz];
bool visit[sz][sz];
int dis[sz][sz], r, c;

void bfs(int i, int j){
    memset(visit, 0, sizeof(visit));
    rep(x, 0, r){
        rep(y, 0, c){
            dis[x][y]=INT_MAX;
        }
    }
    visit[i][j]=true;
    dis[i][j]=0;
    queue<PAIR>q;
    q.push({i, j});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        rep(cc, 0, 4){
            i= x + dir_x[cc];
            j= y + dir_y[cc];
            if(i>-1 and i<r and j>-1 and j<c and grid[i][j]!='#' and grid[i][j]!='m' and !visit[i][j]){
                dis[i][j]=min(dis[x][y]+1, dis[i][j]);
                visit[i][j]=true;
                q.push({i, j});
            }
        }
    }
}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
fli();
//flo();
    int test, h_x, h_y, a_x, a_y, b_x, b_y, c_x, c_y;
    sfi(test);
    repe(cc, 1, test){
        sfi2(r, c);
        rep(i, 0, r){
            rep(j, 0, c){
                cin>>grid[i][j];
                if(grid[i][j]=='h'){
                    h_x=i;
                    h_y=j;

                }else if(grid[i][j]=='a'){
                    a_x=i;
                    a_y=j;

                }else if(grid[i][j]=='b'){
                    b_x=i;
                    b_y=j;

                }else if(grid[i][j]=='c'){
                    c_x=i;
                    c_y=j;
                }
            }
        }

        int mx_a, mx_b, mx_c;

        bfs(a_x, a_y);
        mx_a=dis[h_x][h_y];

        bfs(b_x, b_y);
        mx_b=dis[h_x][h_y];

        bfs(c_x, c_y);
        mx_c=dis[h_x][h_y];

        pfc(cc);
        pfn(max(mx_a, max(mx_b, mx_c)));
    }

    return 0;
}
