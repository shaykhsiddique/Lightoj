#include<bits/stdc++.h>

/*
    |------------------------------------------------------------------|
    |                                                                  |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█                  |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█                  |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█                  |
    |                                                                  |
    |                                          Country:Bangladesh/EWU  |
    |                                          Problem:LOJ-1129        |
    |------------------------------------------------------------------|
*/

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
#define find puts("I am here")
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

              // Shaykh Siddique


bool str_cmp(string a, string b){
    if(b.size()<a.size()) return false;
    rep(i, 0, a.size()){
        if(a[i]!=b[i]) return false;
    }
    return true;
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//    fli();
//    flo();
    string str[10000];
    int test, n;
    cin>>test;
    repe(cc, 1, test){
        pfc(cc);
        cin>>n;
        rep(i, 0, n)
            cin>>str[i];
        sort(str, str+n);
        bool check=true;
        rep(i, 0, n-1){
            if(str_cmp(str[i], str[i+1])){
                check=false;
                break;
            }
        }
        if(check)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
