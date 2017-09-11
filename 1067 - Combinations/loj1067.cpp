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
#define MOD 1000003
using namespace std;
ll fac_n[1000010];
long long modInverse(long long b,long long p)
{           // p will be MOD-2
    if(p==1)
        return b;
    if(p%2==1)
        return(modInverse(b,p-1)*b)%MOD;
    else
    {
        long long res=modInverse(b,p/2);
        return (res*res)%MOD;
    }
}

void fac(){
    fac_n[0]=1;
    for(int i=1; i<=1000000; i++){
        fac_n[i]=((i%MOD)*(fac_n[i-1]%MOD))%MOD;
    }
}

ll nCr(int n, int r){
    ll below=((fac_n[r]%MOD)*(fac_n[n-r]%MOD))%MOD;
    return (fac_n[n]*modInverse(below, MOD-2)%MOD);
}

int main(){
//fli();
//flo();
int test, a, b;
sf(test);
fac();
for(int i=1; i<=test; i++){
    sf2(a, b);
    if(a<b)
        printf("Case %d: %lld\n", i, 0);
    else if(a==b || b==0)
        printf("Case %d: %lld\n", i, 1);
    else
        printf("Case %d: %lld\n", i, nCr(a, b));
}
return 0;
}
