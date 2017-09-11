#include<bits/stdc++.h>

/*
    |--------------------------------------------------------------|
    |                                                              |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█              |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█              |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█              |
    |                                                              |
    |                                          Country:Bangladesh  |
    |                                          Problem:LOJ-1096    |
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
#define MOD 10007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

              // Shaykh Siddique
struct matrix {
  int v[5][5];
  int row, col; // number of row and column
  matrix(int x, int y){row=x, col=y;}
  matrix(){};

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
      ll sum = 0;
      for (int k = 0; k < a.col;  k++) {
        sum =(sum%MOD+((ll)a.v[i][k] * b.v[k][j])%MOD)%MOD;
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
//fli();
//flo();
    int test, n, a, b, c;
    sfi(test);
    for(int i=1; i<=test; i++){
        pfc(i);
        sfi2(n, a);
        sfi2(b, c);
        if(n<=2){
            pfn(0);
            continue;
        }
        matrix base(4,4);
        a%=MOD;
        b%=MOD;
        c%=MOD;
        base.v[0][0]=a;
        base.v[0][1]=0;
        base.v[0][2]=b;
        base.v[0][3]=1;

        base.v[1][0]=1;
        base.v[1][1]=base.v[1][2]=base.v[1][3]=0;

        base.v[2][1]=1;
        base.v[2][0]=base.v[2][2]=base.v[2][3]=0;

        base.v[3][3]=1;
        base.v[3][0]=base.v[3][1]=base.v[3][2]=0;

        matrix mm(4, 1);
        mm.v[0][0]=0;
        mm.v[1][0]=0;
        mm.v[2][0]=0;
        mm.v[3][0]=c;
        matrix ans(4,4);
        ans=power(base, n-2);
        ans=multiply(ans, mm);
        cout<<ans.v[0][0]<<endl;
    }
    return 0;
}
