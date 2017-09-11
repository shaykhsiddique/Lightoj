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

int coin[200];
int n, k;
int dp[10001];

int main(){
//fli();
//flo();
    int test;
    sf(test);
    for(int j=1; j<=test; j++){
        mem(dp, 0);
        sf2(n, k);
        for(int i=1; i<=n; i++)
            sf(coin[i]);
            dp[0]=1;
        loope(1, n){
            for(int j=coin[i]; j<=k; j++){
                if(coin[i]<=j)
                    dp[j]+=dp[j-coin[i]]%MOD;
                if(dp[j] > MOD)
                dp[j] %= MOD;
            }
        }
        printf("Case %d: %d\n", j, dp[k]%MOD);
    }
    return 0;
}
