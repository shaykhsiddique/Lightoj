#include<bits/stdc++.h>
#define sf(n) scanf("%d", &n)
#define sf2(x, y) scanf("%d %d", &x, &y);
#define pf(n) printf("%d", n)
#define pfn printf("%d\n", n)
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
using namespace std;

int main(){
//fli();
//flo();
int test, n, m, i, a[128], v;
	char opt[2];
	scanf("%d", &test);
	for(int p = 1; p <= test; p++) {
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		while(m--) {
			scanf("%s", opt);
			switch(opt[0]) {
				case 'S':
					sf(v);
					for(i = 0; i < n; i++)
                        a[i] += v;
					break;
				case 'M':
					sf(v);
					for(i = 0; i < n; i++)
                        a[i] *= v;
					break;
				case 'D':
					sf(v);
					for(i = 0; i < n; i++)
                        a[i] /= v;
					break;
				case 'R':
					reverse(a, a + n);
					break;
				case 'P':
					sf2(i, v);
					swap(a[i], a[v]);
			}
		}
		printf("Case %d:\n%d", p, a[0]);
		for(i = 1; i < n; i++)
            printf(" %d", a[i]);bl;
	}
return 0;
}
