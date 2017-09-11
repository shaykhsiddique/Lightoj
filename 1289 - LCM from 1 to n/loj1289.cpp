#include<bits/stdc++.h>
#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pf(n) printf("%d", n)
#define pfc(i) printf("Case %d:", i)
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

ull fac(int n){
    ull ans=1;
    for(int i=n; i>0; i--){
        ans*=i;
    }
    return ans;
}
int main(){
//fli();
//flo();
int test, n, k;
sfi(test);
for(int i=1; i<=test; i++){
    sfi2(n, k);
    string alp;
    char c='A';
    for(int j=0; j<n; j++){
        alp.pb(c);
        c++;
    }
    ull total=fac(n);
    pfc(i);bl;
    if(k<=total){
        for(int j=0; j<k; j++){
            cout<<alp<<endl;
            next_permutation(alp.begin(), alp.end());
        }
    }else{
        for(int j=0; j<total; j++){
            cout<<alp<<endl;
            next_permutation(alp.begin(), alp.end());
        }
    }
}

return 0;
}
