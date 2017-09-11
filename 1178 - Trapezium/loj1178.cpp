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

int main(){
//fli();
    int test;
    double a, b, c, d;
    sfi(test);
    for(int i=1; i<=test; i++){
        sfd2(a, b);sfd2(c, d);
        double tri_a=(a>c?a-c:c-a);
        double s=0.5*(tri_a + b + d);
        double area_tri=sqrt((s*(s-tri_a)*(s-b)*(s-d)));
        double h=((2*area_tri))/tri_a;
        double ans=((a+c)*h)/2;
        pfc(i);
        pfdn(ans);

    }

return 0;
}
