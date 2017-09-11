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
#define LL long long
#define ull unsigned long long
#define debug(x) cerr << #x << " : " << x << endl
#define loope(n, test) for(int i=n; i<=test; i++)
#define loop(n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#define size_n 1000000000
#define size_p 10000000
using namespace std;

#define sroot 1000007
vector <int> prime;

//                    Shaykh Siddique template

int sieve()
{
	bool a[sroot];
	memset(a, 0, sizeof(a));

	for(int i = 2; i <= sroot; i++) {
		if(a[i] == 0) {
			for (int j = i + i; j <= sroot; j = j + i) {
				a[j] = 1;
			}

		}

	}

	for (int i = 2; i <= sroot; i++) {
		if(a[i] == 0) {
			prime.push_back(i);
		}

	}

	sort(prime.begin(), prime.end());

}


ll factorize(ll n){
   ll cont=0, sum=1, h=0;
    ll sqrtn=sqrt(n);
    for(ll i=0;i<=prime.size()-1 && prime[i]<=sqrtn; i++){
        cont=0;
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                cont+=1;
                n/=prime[i];
               // printf("%d", prime[i]);         ///prime fac output
            }
            sqrtn=sqrt(n);
            h=cont+1;
            sum*=h;
        }
    }
    if(n>1){
          //  printf("%d", n);               ///prime fac output
            sum*=2;
    }


    return sum;
}


int main(){
//fli();
sieve();
int test;
sfi(test);
for(int i=1; i<=test; i++){
    ll x;
    sfl(x);
    pfc(i);
    printf("%lld\n", factorize(x)-1);
}
return 0;
}
