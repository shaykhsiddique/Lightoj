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
#define EPS 1e-7
using namespace std;


double binary_s(double x, double y, double c){
    double lo=0, hi=fmin(x, y), mid, range;
    while(fabs(range-c)>EPS){
        mid=(hi-lo)/2+lo;
        range = sqrt(x*x-mid*mid)*sqrt(y*y-mid*mid)/(sqrt(x*x-mid*mid)+sqrt(y*y-mid*mid));
        if(range>c)
            lo=mid;
        else
            hi=mid;
    }
    return mid;
}

int main(){
//fli();
int test;
sfi(test);
for(int i=1; i<=test; i++){
    double x, y, c;
    sfd2(x, y);sfd(c);
    pfc(i);
    printf("%.10f\n", binary_s(x, y, c));
//    cout<<mid<<endl;
}

return 0;
}
