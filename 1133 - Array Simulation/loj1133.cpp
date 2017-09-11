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

typedef pair<int, string>s;
vector<s>V;

int main(){
//fli();
//flo();
int test;
sf(test);
for(int k=1; k<=test; k++){
    V.clear();
    int n, a, b, c;
    string name;
    sf(n);
    for(int j=0; j<n; j++){
        cin>>name;sf2(a, b);sf(c);
        V.pb(s(a*b*c, name));
    }
    sort(V.begin(), V.end());
    if(V[0].first == V[n-1].first)
        printf("Case %d: no thief\n", k);
    else
        printf("Case %d: %s took chocolate from %s\n", k, V[n-1].second.c_str(), V[0].second.c_str());
}
return 0;
}
