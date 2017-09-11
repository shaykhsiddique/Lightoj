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
//     fli();
//     flo();
long int arr[1];
memset(arr, 0, sizeof(arr));
arr[0]=1;
cout<<sizeof(arr)<<endl;
for(ll i=1; i<25; i++){
        arr[i]=arr[i-1]*i;
    }

int test;
sf(test);
for(int q=1; q<=test; q++){
    ll n;
    scanf("%lld", &n);
    ll sum=n;
    int num[30];
    memset(num, 0, sizeof(num));
    int k=0; ll check=0;
    bool flag=false;
    for(int i=25; i>=0; i--){
        if(arr[i]>sum)
            continue;
        if(arr[i]>0){
            sum-=arr[i];
         //  debug(sum);
            check+=arr[i];
            //debug(check);
            num[k]=i;
            //debug(num[k]);
            k++;

            if(check==n){
                flag=true;
                    break;
            }
    }
    }
    printf("Case %d: ", q);
    if(flag){
            //debug(k);

        for(int i=k-1; i>=0; i--){
            printf("%d!", num[i]);
            if(i!=0)
                putchar('+');
        }
        bl;
    }
    else{

        printf("impossible\n");
    }
}
    return 0;
}
