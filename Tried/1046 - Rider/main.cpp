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
    |                                          Problem:                |
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

#define PAIR pair<int, int>
#define sz 20
int dir_x[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dir_y[] = {2, -2, 1, -1, 2, -2, 1, -1};

              // Code starts from here
struct two_int{
    int step, num;
};

int dim3[120][120][120];
int ro, co;
char grid[sz][sz];
int visit[sz][sz];
two_int new_grid[sz][sz];

inline bool valid(int i, int j){
    if(i>-1 and i<ro and j>-1 and j<co)
        return true;
    else return false;
}

inline void new_grid_clr(){
    rep(i, 0, ro){
            rep(j, 0, co){
                new_grid[i][j].step=0;
                new_grid[i][j].num=0;
            }
    }
}


void print_gr(){
    bl;bl;
    rep(i, 0, ro){
            rep(j, 0, co){
//                if(grid[i][j]!='.'){
//
//                }
                cout<<new_grid[i][j].step<<" ";
            }bl;
        }
}

bool visited[sz][sz];
void bfs(int s_i, int s_j, int step, int no){
    int start=0;

    memset(visited, 0, sizeof(visited));
    queue<PAIR>Q;
    Q.push({s_i, s_j});
//    visited[s_i][s_j]=true;
    while(!Q.empty()){
        int x=Q.front().fi;
        int y=Q.front().se;
        Q.pop();
        start++;
        int old_step=new_grid[x][y].step;
        rep(cc, 0, 8){
            int i=x+dir_x[cc];
            int j=y+dir_y[cc];
            if(valid(i, j) and !visited[i][j]){
                    visited[i][j]=true;
                    dim3[no][i][j]=dim3[no][x][y]+1;
                    new_grid[i][j].num++;
                    cout<<"i-j: "<<i<<" "<<j<<" "<<new_grid[i][j].step<<endl;
                    Q.push({i, j});
                    print_gr();
                //step cont
            }
        }
    }
}


void update_grid(int cont, int step){
    repe(cc, 1, cont){
        rep(i, 0, ro){
            rep(j, 0, co){
                if(dim3[cc][i][j]%step==0)
                    dim3[cc][i][j]=dim3[cc][i][j]/step;
                else
                    dim3[cc][i][j]=(dim3[cc][i][j]/step)+1;

                    new_grid[i][j].step+=dim3[cc][i][j];
            }
        }
    }


}


int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
fli();
//flo();
    int test;
    cin>>test;
    repe(cc, 1, test){
        new_grid_clr();
        int knight=0;
        cin>>ro>>co;
        rep(i, 0, ro){
            rep(j, 0, co){
                cin>>grid[i][j];
                if(grid[i][j]!='.')
                    knight++;
            }
        }
        int hh=0;
        rep(i, 0, ro){
            rep(j, 0, co){
                if(grid[i][j]!='.'){
                    hh++;
                    cout<<"Rider: "<<i<<" "<<j<<endl;
                    bfs(i, j, grid[i][j]-'0', hh);
                    update_grid(knight,grid[i][j]-'0');
                }
            }
        }
            bl;bl;
        rep(i, 0, ro){
            rep(j, 0, co){
//                if(grid[i][j]!='.'){
//
//                }
                cout<<new_grid[i][j].step<<" ";
            }bl;
        }
    }

    return 0;
}
