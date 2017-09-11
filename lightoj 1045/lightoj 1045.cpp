#include<bits/stdc++.h>
#define sf(n) scanf("%d", &n)
#define sf2(x, y) scanf("%d %d", &x, &y);
#define pf(n) printf("%d", n)
#define pfn(n) printf("%d\n", n)
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


int test;
ll i,n,b;
double num[1000010];
int main()
{
//    fli();
    scanf("%d",&test);
   // num[0]=1;
    for(i=1;i<=1000000;i++)
        num[i]=log((i))+num[i-1];
    loope(1, test){
        scanf("%lld%lld",&n,&b);
        printf("Case %d: %lld\n",i ,(ll)(num[n]/(num[b]-num[b-1]))+1);
    }
    return 0;
}
