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
typedef pair<int, int>s;

struct my{
    ll x, y;
};


bool cmp(my a, my b)
{
    if(a.x==b.x)
    {
        return a.y>b.y;
    }
    else return a.x<b.x;
}

int main(){
//    fli();
//    flo();
    my data[1024];
    for(int i=0; i<1000; i++){
        ll cnt=0;
        for(ll j=1;j<i+1;j++)
     {
         if((i+1)%j==0)
         {
             cnt++;
         }
     }
        data[i].x=cnt;
        data[i].y=i+1;
    }
    sort(data,data+1000,cmp);
    ll test;
    scanf("%lld", &test);
    for(ll i=1; i<=test; i++){
        ll n;
        scanf("%lld", &n);
        printf("Case %lld: %lld\n", i, data[n-1].y);
    }
    return 0;
}
