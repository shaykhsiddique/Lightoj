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
#define loope(n, test) for(int i=n; i<=test; i++)
#define loop(n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
using namespace std;

//                    Shaykh Siddique
vector<int>graph[100010];
int visit[100005];
int mycheck[100005];
bool check;
int cont_v=0;
int cont_l=0;
void bfs(int src){
    queue<int>q;
    q.push(src);
    visit[src]=-1;
    cont_v++;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<graph[u].size(); i++){
            if(visit[graph[u][i]]==0){
                if(visit[u]==-1){
                    visit[graph[u][i]]=1;
                    cont_l++;
                }else if(visit[u]==1){
                    visit[graph[u][i]]=-1;
                    cont_v++;
                }
                q.push(graph[u][i]);
            }
        }
    }
}



int main(){
//fli();
//flo();
    int test, n, a, b;
    sfi(test);
    for(int i=1; i<=test; i++){
        sfi(n);
        for(int j=0; j<=100000; j++) graph[j].clear();
        memset(visit, 0, sizeof(visit));
        memset(mycheck, 0, sizeof(mycheck));
        check=false;
        for(int j=0; j<n; j++){
            sfi2(a, b);
            graph[a].pb(b);
            graph[b].pb(a);
            mycheck[a]=1;
            mycheck[b]=1;
        }
        int cont=0;
        for(int j=1; j<=20000; j++){
//            debug(visit[j]);
            if(visit[j])continue;
            if(!mycheck[j])continue;
            cont_l=0;
            cont_v=0;
            bfs(j);
            cont+=max(cont_l, cont_v);
            }
        pfc(i);
        pfn(cont);
    }
return 0;
}
