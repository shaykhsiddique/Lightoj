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
    |                                          Problem: LOJ-1041       |
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

              // Code starts from here

map<string, int>mp;
int cost[200][200];
vector<int>graph[200];
int dis[200];
int visit[200];
bool check[200];

void dijkstra(int src=1){
    memset(check, 0, sizeof(check));

    int mst=0;
    priority_queue<int>Q;
    rep(i, 0, 200){
        dis[i]=INT_MAX;
        visit[i]=INT_MAX;
    }
    Q.push(src);
    check[src]=true;
    dis[src]=0;
    while(!Q.empty()){
        int u=Q.top();
        Q.pop();
        rep(i, 0, graph[u].size()){
            int v=graph[u][i];
            if(((ll)cost[u][v])<dis[v]){
                dis[v]=cost[u][v];
                check[v]=true;
//                debug(dis[v]);
                Q.push(v);
            }
        }
    }
}

bool connection(int nodes){
    repe(i, 1, nodes){
        if(!check[i]) return false;
    }
    return true;
}

int mst(int nodes){
    int ans=0;
    repe(i, 1, nodes){
        ans+=dis[i];
    }
    return ans;
}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
fli();
flo();
    int test, m, w;
    string u, v;
    cin>>test;
    repe(cc, 1, test){
        cin>>m;
        rep(i, 0, 150){
            rep(j, 0, 150){
                cost[i][j]=INT_MAX;
            }
        }
        int ind=0;
        mp.clear();
        rep(i, 0, m){
            cin>>u>>v>>w;
            if(!mp[u]){
                ind++;
                mp[u]=ind;

            }if(!mp[v]){
                ind++;
                mp[v]=ind;
            }
            int kk=mp[u];
            int mm=mp[v];
            if(cost[kk][mm]>w){
                cost[kk][mm]=w;
                cost[mm][kk]=w;
                graph[mm].pb(kk);
                graph[kk].pb(mm);
            }
        }
        dijkstra();
        cout<<"Case "<<cc<<": ";
        if(connection(ind))
            cout<<mst(ind)<<endl;
        else
            cout<<"Impossible"<<endl;

//        cout<<connection(ind)<<endl;
        rep(i, 0, ind+4){
            graph[i].clear();
        }
    }
    return 0;
}
