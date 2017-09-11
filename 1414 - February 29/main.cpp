#include<bits/stdc++.h>

/*
    |------------------------------------------------------------------|
    |                                                                  |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█                  |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█                  |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█                  |
    |                                                                  |
    |                                          Country:Bangladesh/EWU  |
    |                                          Problem:LOJ-1414        |
    |------------------------------------------------------------------|
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
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

              // Shaykh Siddique

bool is_leapyr(int yr){
    if(!(yr%100)){
        if(!(yr%400)) return true;
        else return false;
    }else if(!(yr%4)) return true;
    else return false;
}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    string mo[]={"None", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int  test, day, year, day2, year2, cont, id1, id2;
    char month[50], month2[50];
    sfi(test);
    repe(cc, 1, test){
        pfc(cc);
        cont=0;
        scanf("%s %d, %d", month, &day, &year);
        scanf("%s %d, %d", month2, &day2, &year2);
        repe(i, 1, 12){
            if(month==mo[i]){
                id1=i;
                break;
            }
        }

        repe(i, 1, 12){
            if(month2==mo[i]){
                id2=i;
                break;
            }
        }

        cont = (year2/4 - year2/100 + year2/400) - (year/4 - year/100 + year/400);

        if(is_leapyr(year)){
            if(id1==1) cont++;
            else if(id1==2 and day<=29) cont++;
        }

        if(is_leapyr(year2)){

            if(id2==1) cont--;
            else if(id2==2 and day2<29) cont--;
        }
        pfn(cont);

    }

    return 0;
}
