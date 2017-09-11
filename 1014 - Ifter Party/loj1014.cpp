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

int ate[100005];

void dive(int l, int m){
    int root=sqrt(m);
    int k=0;
    for(int i=1; i<=root; i++){
        if(m%i==0){
            int div=m/i;
            if(div>l){
                ate[k]=div;
                k++;
            }
            if(i>l && div!=i){
                ate[k]=i;
                k++;
            }
        }
    }
    sort(ate, ate+k);
    for(int i=0; i<k; i++){
        printf("%d", ate[i]);
        if(i!=(k-1))
            printf(" ");
    }
}

int main(){
//fli();
//flo();
int test, p, l, rem, root;
bool check;
sfi(test);
for(int i=1; i<=test; i++){
    int k=0;
    sfi2(p, l);
    rem=p-l;
    pfc(i);
    if(p==0)
        pfn(1);
    else if(rem>l){
    dive(l, rem);bl;
    }else{
        printf("impossible\n");
    }
}
return 0;
}
