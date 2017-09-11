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
    |                                          Problem: LOJ-1027       |
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

#define sroot 1000007
vector <int> primes;


void sieve(){
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
			primes.push_back(i);
		}
	}
	sort(primes.begin(), primes.end());
}


inline bool is_prime(int num){
    int temp=lower_bound(primes.begin(), primes.end(), num)-primes.begin();
    return (primes[temp]==num?true:false);
}

int dividing(int a, int b){
    int ans=1;
    int ind=0;
    while(a>1 and b>1){
        int te1=sqrt(a)+10;
        int te2=sqrt(b)+10;
        if(is_prime(a) or te1<primes[ind] or te2<primes[ind])
            break;
        if(a%primes[ind]==0 and b%primes[ind]==0){
            a/=primes[ind];
            b/=primes[ind];
            ans*=primes[ind];
        }else
            ind++;
    }
    return ans;
}


int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    sieve();
    int test, n, pos, neg, num, sum;
    sfi(test);
    repe(cc, 1, test){
        pfc(cc);
        sfi(n);
        pos=0;neg=0;sum=0;
        rep(i, 0, n){
            sfi(num);
            if(num<0)
                neg++;
            else
                pos++;
            sum+=abs(num);

        }
        if(pos){
            int di=dividing(sum, pos);
            pf("%d/%d\n", sum/di, pos/di);
        }
        else
            pf("inf\n");

    }

    return 0;
}
