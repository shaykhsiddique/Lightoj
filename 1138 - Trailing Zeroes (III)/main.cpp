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
const long long inf = 1000000000LL;
using namespace std;




#define PAIR pair<int, int>
int dir_x[] = {-1,1,0,0};
int dir_y[] = {0,0,-1,1};
              // Code starts from here

ll zero_last(ll n){
    ll sum=0;
    ll ch=5;
    while(n){
        n/=5;
        sum+=n;
    }
    return sum;
}

ll bs(ll n){
    ll lo=0, hi=inf;
        ll mid;
    while(lo<hi){
        mid=(lo+hi)/2;
        ll ans=zero_last(mid);
        if(abs(hi-lo)<2) return -1;
        if(ans>n){
            hi=mid;
        }else if(ans<n){
            lo=mid;
        }else
            return mid;
    }
}

ll explorer(ll n){
    ll ans;
    ll f=bs(n);
    while(f!=-1){
        ans=zero_last(f);
        if(ans<n) return f+1;
        f--;
    }
    return f;
}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int test;
    ll n;
    sfi(test);
    repe(cc, 1, test){
        sfl(n);
        pfc(cc);
        ll ans=explorer(n);
        if(ans==-1)
            pf("impossible\n");
        else
            pf("%lld\n", ans);
    }

    return 0;
}
