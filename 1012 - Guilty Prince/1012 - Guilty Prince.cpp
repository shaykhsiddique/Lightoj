#include<bits/stdc++.h>
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
#define loope(n, test) for(int i=n; i<=test; i++)
#define loop(n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
using namespace std;

//                    Shaykh Siddique
char grid[25][25];
bool visited[25][25];
int w, h;
int notes;
void dfs(int x,int y){
    if(x+1<h && grid[x+1][y]=='.' && !visited[x+1][y]){

        notes++;
        visited[x+1][y]=true;
        dfs(x+1, y);
    }
    if(x-1>=0 && grid[x-1][y]=='.' && !visited[x-1][y]){
        notes++;
        visited[x-1][y]=true;
        dfs(x-1, y);
    }
    if(y+1<w && grid[x][y+1]=='.' && !visited[x][y+1]){
        notes++;
        visited[x][y+1]=true;
        dfs(x, y+1);
    }
    if(y-1>=0 && grid[x][y-1]=='.' && !visited[x][y-1]){
        notes++;
        visited[x][y-1]=true;
        dfs(x, y-1);
    }
}

//int wow(int i, int j)
//{
//
//	if(i + 1 < h and !visited[i+1][j] and grid[i+1][j] == '.') {
//		visited[i+1][j] = 1;
//		notes++;
//		wow(i+1, j);
//	}
//
//	if(i - 1 >= 0 and !visited[i-1][j] and grid[i-1][j] == '.') {
//		visited[i-1][j] = 1;
//		notes++;
//		wow(i-1, j);
//	}
//
//	if(j + 1 < w and !visited[i][j+1] and grid[i][j+1] == '.') {
//		visited[i][j+1] = 1;
//		notes++;
//		wow(i, j+1);
//	}
//
//	if(j - 1 >= 0 and !visited[i][j-1] and grid[i][j-1] == '.') {
//		visited[i][j-1] = 1;
//		notes++;
//		wow(i, j -1);
//	}
//
//}

int main(){
fli();
int test, x, y;
sfi(test);
for(int i=1; i<=test; i++){
    sfi2(w, h);
    memset(visited, 0, sizeof(visited));
    notes=0;
    for(int j=0; j<h; j++){
        for(int k=0; k<w; k++){
            cin>>grid[j][k];
            if(grid[j][k]=='@'){
                x=j; y=k;
                visited[x][y]=true;
                notes=1;
            }
        }
    }
    dfs(x, y);
    pfc(i);
    pfn(notes);
}

return 0;
}
