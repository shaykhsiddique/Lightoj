#include<bits/stdc++.h>
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
#define loope(n, test) for(int i=n; i<=test; i++)
#define loop(n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
using namespace std;
int phi[1000006], mark[1000006];

void sievephi(){
    int i, j;
    for(i=1; i<=1000006; i++) phi[i]=i;
    phi[1]=1;
    mark[1]=1;
    for(i=2; i<=1000006; i++){
        if(!mark[i]){
            for(j=1; j<=1000006; j+=i){
                mark[j]=1;
                phi[j]=phi[j]/i*(i-1);
                cout<<phi[j]<<endl;
            }
        }
    }
}

int main(){
fli();
flo();
int test;
sfi(test);
sievephi();
for(int i=1; i<=test; i++){
    int a, b;
    sfi2(a, b);
    ull ans=0;
//    for(ll j=a; j<=b; j++){
//
//        ans+=(phi(j)*phi(j));
//    }
    pfc(i);
   cout<<phi[a]<<endl;
}
return 0;
}
