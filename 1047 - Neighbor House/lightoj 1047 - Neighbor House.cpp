#include<bits/stdc++.h>
#define sf(n) scanf("%d", &n)
#define sf2(x, y) scanf("%d %d", &x, &y);
#define pf(n) printf("%d", n)
#define pfn printf("%d\n", n)
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
using namespace std;
int const INF = 1<<24;
vector<int>cost[25];
int dp[25][5];
int n;
int min4(int a, int b, int c, int d){
    return min(a, min(b, min(c, d)));
}


int rec(int r, int c){
    if(r>=n || c>=cost[r].size()) return 0;
    int ans = INF;
    if(dp[r][c]!=-1) return dp[r][c];

    if(r==0)
        return dp[r][c]=min(rec(r+1, c+1), rec(r+1, c+2))+cost[r][c];
    if(r==1)
        return dp[r][c]=min(rec(r+1, c), rec(r+1, c+2))+cost[r][c];
    else if(r==2)
        return dp[r][c]=min(rec(r+1, c), rec(r+1, c+1))+cost[r][c];
}

int main(){
    fli();
    int test;
    sf(test);
    for(int i=1; i<=test; i++){
        memset(dp, -1, sizeof(dp));
        sf(n);
        for(int j=0; j<n; j++){
            cost[j].clear();
            int r, g, b;
            sf2(r, g); sf(b);
            cost[j].pb(r);
            cost[j].pb(g);
            cost[j].pb(b);
        }
        cout<<rec(0, 0)<<endl;
    }
    return 0;
}
