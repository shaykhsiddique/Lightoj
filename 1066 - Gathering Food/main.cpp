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
    |                                          Problem:Lightoj-1066    |
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
#define sz 15
int dir_x[] = {-1, 0, 0, 1};
int dir_y[] = {0, -1, 1, 0};

char ch[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char grid[sz][sz];
bool visit[sz][sz];
int dist[sz][sz];
int n, ind_x, ind_y;

int bfs(int s_x, int s_y, char des){
    memset(visit, 0, sizeof(visit));
    memset(dist, 0, sizeof(dist));
    queue<PAIR>Q;
    Q.push({s_x, s_y});
    grid[s_x][s_y]='.';
    visit[s_x][s_y]=true;
    while(!Q.empty()){
        int x=Q.front().fi;
        int y=Q.front().se;
        Q.pop();
        rep(cc, 0, 4){
            int i= x + dir_x[cc];
            int j= y + dir_y[cc];
            if(i>-1 and i<n and j>-1 and j<n and !visit[i][j]){
                if(grid[i][j]=='.' or grid[i][j]==des){
                    visit[i][j]=true;
                    dist[i][j] = dist[x][y] + 1;
                    if(grid[i][j]==des){
                        grid[i][j]='.';
                        ind_x=i;
                        ind_y=j;
                        return dist[i][j];
                    }
                    Q.push({i, j});
                }
            }
        }
    }
    return -10;
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//fli();
//flo();
    int test, cont_ch=0;
    cin>>test;
    repe(cc, 1, test){
        cin>>n;
        cont_ch=0;
        rep(i, 0, n){
            rep(j, 0, n){
                cin>>grid[i][j];
                if(grid[i][j]=='A'){
                    ind_x=i;
                    ind_y=j;
                }
                if(grid[i][j]!='.' and grid[i][j]!='#')
                    cont_ch++;
            }
        }
        int ans=0;
        bool valid=true;
        rep(i, 1, cont_ch){
            int temp=bfs(ind_x, ind_y, ch[i]);
            if(temp==-10){
                valid=false;
                break;
            }
            ans+=temp;
        }
        cout<<"Case "<<cc<<": ";
        if(!valid)
            cout<<"Impossible"<<endl;
        else
            cout<<ans<<endl;
    }
return 0;
}
