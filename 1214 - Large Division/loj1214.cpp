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
#define MOD 1000000007
using namespace std;

int main(){
//fli();
//flo();
int test, dev;
string num;
sf(test);
for(int i=1; i<=test; i++){
    cin>>num;
    sf(dev);
    ll sum=0;
    for(int j=0; j<num.size(); j++){
        if(num[j]=='-')
            continue;
        sum=(sum*10)+(num[j]-'0');
        sum%=dev;
    }
    printf("Case %d: ", i);
    if(!sum)
        cout<<"divisible"<<endl;
    else
        cout<<"not divisible"<<endl;
}
return 0;
}
