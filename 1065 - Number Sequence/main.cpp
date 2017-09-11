#include<bits/stdc++.h>
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
struct matrix{
    int v[5][5];
    int row, col;
    matrix(int _r, int _c) : row (_r), col(_c) {
    memset(v, 0, sizeof (v));
  };
    matrix(): row (2), col(2){};
    void print(){
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j)
                cout << v[i][j] << " ";
      cout << endl;
    }
  }

};
int mod;
matrix multiply(matrix a, matrix b) {
  assert(a.col == b.row);
  matrix r;
  r.row = a.row;
  r.col = b.col;
  for (int i = 0; i < r.row; i++) {
    for (int j = 0; j < r.col; j++) {
      int sum = 0;
      for (int k = 0; k < a.col;  k++) {
        sum =(sum%mod+(a.v[i][k] * b.v[k][j])%mod)%mod;
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
    int test, a, b, n, m;
    matrix base(2,2);
    sfi(test);
    for(int i=1; i<=test; i++){
        pfc(i);
        sfi2(a, b);sfi2(n, m);
        mod=1;
        while(m--){
            mod*=10;
        }
        base.v[0][0]=1;
        base.v[0][1]=1;
        base.v[1][0]=1;
        base.v[1][1]=0;
        if(!n){
            pfn(a%mod);
            continue;
        }else if(n==1){
            pfn(b%mod);
            continue;
        }
        matrix ans=power(base, n-1);
//        bl;ans.print();
        pfn(((ans.v[0][0]*b)%mod+(ans.v[0][1]*a)%mod)%mod);
    }
    return 0;
}
