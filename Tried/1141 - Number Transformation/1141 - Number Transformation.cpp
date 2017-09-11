#include<bits/stdc++.h>

/*
    |------------------------------------------------------------------|
    |                                                                  |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█                  |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█                  |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█                  |
    |                                                                  |
    |                                          Country:Bangladesh/EWU  |
    |                                          Problem:LOJ-1141        |
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

              // Shaykh Siddique
#define PAIR pair<int, int>
#define sroot 1229
vector <int> primes;


void sieve(){
	bool a[sroot];
	memset(a, 0, sizeof(a));
	for(int i = 2; i <= sroot; i++){
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

bool visit[10001];

int bfs(int src, int des){
    memset(visit, 0, sizeof(visit));
    queue<PAIR>Q;
    Q.push({src, 0});
    while(!Q.empty()){
        int cr=Q.front().fi;
        int di=Q.front().se;
//        debug(cr);
        visit[cr]=true;
        Q.pop();
        if(cr==des) return di;
        else if(cr<des){
            for(int i=0; primes[i]<cr; i++){
                    int u=cr+primes[i];
//                    debug(u);
                if(cr%primes[i]==0 and u<=des and !visit[u]){
                    Q.push({u, di+1});
                }
            }
        }
    }
    return -1;
}



int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    sieve();
    int test, u, v;
    sfi(test);
    repe(cc, 1, test){
        sfi2(u, v);
        pfc(cc);
        pfn(bfs(u, v));
    }
    return 0;
}
