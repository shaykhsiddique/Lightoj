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
using namespace std;

              // Code starts from here

inline int count_digit(int num, int n){
    int dd=n, cont=1;
    while(true){
        if(dd<num){
            dd=dd*10+n;
            cont++;
        }
        if(dd%num==0)
            break;
        else
            dd=dd%num;
    }
    return cont;
}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int test, num, n, cont;
    sfi(test);
    string checker;
    repe(cc, 1, test){
        sfi2(num, n);

        pfc(cc);
        pfn(count_digit(num, n));
    }
    return 0;
}
