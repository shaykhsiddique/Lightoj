#include<bits/stdc++.h>

/*
    |--------------------------------------------------------------|
    |                                                              |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█              |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█              |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█              |
    |                                                              |
    |                                          Country:Bangladesh  |
    |                                          Problem:            |
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
#define MOD 18446744073709551616
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

              // Shaykh Siddique

struct matrix{
    ll v[5][5];
    int row, col;
    matrix(int x, int y){row=x; col=y;}
    matrix(){}

    void print(){
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j)
                cout << v[i][j] << " ";
      cout << endl;
    }
  }
};

matrix multiply(matrix a, matrix b) {
  assert(a.col == b.row);
  matrix r;
  r.row = a.row;
  r.col = b.col;
  for (int i = 0; i < r.row; i++) {
    for (int j = 0; j < r.col; j++) {
      ull sum = 0;
      for (int k = 0; k < a.col;  k++) {
        sum =(sum+((ll)a.v[i][k] * b.v[k][j]));
//        debug(sum);
      }
      r.v[i][j] = sum;
    }
  }
  return r;
}

// returns mat^p
matrix power(matrix mat, int p) {
  assert(p >= 1);
  if (p == 1) return mat;
  if (p % 2 == 1)
    return multiply(mat, power(mat, p - 1));
  matrix ret = power(mat, p / 2);
  ret = multiply(ret, ret);
  return ret;
}

int main(){
fli();
flo();
    int test;
    ll p, q, n;
    sfi(test);
    for(int i=1; i<=test; i++){
        pfc(i);
        sfl2(p, q); sfl(n);
        if (n == 0) {
            printf("2\n");
            continue;
        }else if(n==1){
            pfn(p);
            continue;
        }
        matrix base(2, 2);
        base.v[0][0]=p;
        base.v[0][1]=-q;
        base.v[1][0]=1;
        base.v[1][1]=0;
        matrix ans(2, 2);
        ans=power(base, n-1);
        ull sol = ((ull)(ans.v[0][0]*p) + (ans.v[0][1]*2));
        cout<<sol<<endl;
    }

return 0;
}
