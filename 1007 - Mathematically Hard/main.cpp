#include<bits/stdc++.h>
/*
    |--------------------------------------------------------------|
    |                                                              |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█              |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█              |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█              |
    |                                                              |
    |                                          Country:Bangladesh  |
    |                                          Problem:LOJ-1007    |
    |--------------------------------------------------------------|
*/

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
#define find puts("I am here")
#define loope(n, test) for(int i=n; i<=test; i++)
#define loop(n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

              // Shaykh Siddique


#define sroot 5000000
int phi[sroot+10];

void eulerPhi(){
    for(int i=2; i<=sroot; i++)
        phi[i] = i;

    for(int i =2; i<=sroot; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<=sroot; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}

ull sum[sroot+10];

void calculatesum()
{
    sum[1] = 0;

    for(int i=2; i<=sroot; i++)
    {
        sum[i] = phi[i];
        sum[i]*=phi[i];
//        debug(i);
//cout<<"i: "<<i<<" phi[i] : "<<phi[i]<<endl;
//        debug(phi[i]);
//        debug(sum[i]);
        sum[i]+=sum[i-1];
    }

}


int main(){
//fli();
//flo();

    eulerPhi();
    calculatesum();
    int test, a, b;
    sfi(test);
    for(int cc=1; cc<=test; cc++){
        sfi2(a, b);
        pfc(cc);
        printf("%llu\n", sum[b]-sum[a-1]);
    }
    return 0;
}
