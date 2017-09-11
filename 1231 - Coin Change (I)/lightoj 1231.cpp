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
#define mem(n, k) memset(n, k, sizeof(n))
#define MOD 100000007
using namespace std;

int coin[200], rem[200];
int n, k;
int dp[1005][55];

int rec(int amount, int inx){
//    debug(amount);
//    debug(inx);
    if(inx>n){
        if(amount==k) return 1;
        else return 0;
    }
    if(amount>k) return 0;
    if(amount==k) return 1;
    if(dp[amount][inx]!=-1) return dp[amount][inx];
    int make=0;
    for(int i=1; i<=rem[inx]; i++){
        int value=coin[inx]*i;
        if(amount+value<=k)
            make+=rec(amount+value, inx+1)%MOD;
        else break;
    }
    make+=rec(amount, inx+1)%MOD;
    return dp[amount][inx]=make%MOD;
}

int main(){
//fli();
//flo();
    int test;
    sf(test);
    for(int i=1; i<=test; i++){
        mem(dp, -1);
        sf2(n, k);
        for(int j=1; j<=n; j++)
            sf(coin[j]);
        for(int j=1; j<=n; j++)
            sf(rem[j]);
        int ans=rec(0, 1)%MOD;
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}
