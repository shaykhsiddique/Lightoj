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
    |                                          Problem: LOJ-1212       |
    |------------------------------------------------------------------|
*/

#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pf printf
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

              // Code starts from here


class que{
public:
    int value[100];
    int left_id, right_id, siz;

    void clr(){
        left_id=50;
        right_id=50;
        siz=0;
        memset(value, 0, sizeof(value));
    }

    void push_left(int va, int sz){
        if(sz==siz)
            cout<<"The queue is full"<<endl;
        else{
            siz++;
            left_id--;
            value[left_id]=va;
            cout<<"Pushed in left: "<<va<<endl;
        }
    }
    void push_right(int va, int sz){
        if(sz==siz)
            cout<<"The queue is full"<<endl;
        else{
            siz++;
            value[right_id]=va;
            cout<<"Pushed in right: "<<va<<endl;
            right_id++;
        }
    }

    void pop_left(){
        if(siz==0)
            cout<<"The queue is empty"<<endl;
        else{
            siz--;
            cout<<"Popped from left: "<<value[left_id]<<endl;
            value[left_id]=0;
            left_id++;
        }
    }

    void pop_right(){
        if(siz==0)
            cout<<"The queue is empty"<<endl;
        else{
            siz--;
            right_id--;
            cout<<"Popped from right: "<<value[right_id]<<endl;
            value[right_id]=0;
        }
    }
};


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//fli();
//flo();
    int test, psd, n, m;
    que Q;
    string cmd;
    cin>>test;
    repe(cc, 1, test){
        cout<<"Case "<<cc<<":"<<endl;
        cin>>n>>m;
        Q.clr();
        rep(i, 0, m){
            cin>>cmd;
            if(cmd[1]=='u'){
                cin>>psd;
                if(cmd[4]=='L')
                    Q.push_left(psd, n);
                else
                    Q.push_right(psd, n);
            }else{
                if(cmd[3]=='L')
                    Q.pop_left();
                else
                    Q.pop_right();
            }
        }
    }
    return 0;
}
