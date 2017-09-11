#include<bits/stdc++.h>
#define sf(n) scanf("%d", &n)
#define sf2(x, y) scanf("%d %d", &x, &y);
#define pf(n) printf("%d", n)
#define pfn printf("%d\n", n)
#define pb push_back
#define popb pop_back
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


int main()
{
//    fli();
//    flo();
   int test;
   scanf("%d",&test);
   for(int i=1;i<=test;i++)
   {
       stack<string>F,B;
       string str="http://www.lightoj.com/",cm;
       printf("Case %d:\n",i);
       while(cin>>cm&&cm!="QUIT")
       {
           if(cm=="BACK")
           {
               if(B.empty())
                   printf("Ignored\n");
               else
               {
                   F.push(str);
                   str=B.top();
                   B.pop();
                   cout<<str<<endl;
               }
           }
           else if(cm=="FORWARD")
           {
               if(F.empty())
                   printf("Ignored\n");
               else
               {
                   B.push(str);
                   str=F.top();
                   F.pop();
                   cout<<str<<endl;
               }
           }
           else
           {
               B.push(str);
               cin>>str;
               cout<<str<<endl;
               while(F.size())
                   F.pop();
           }
       }
   }
   return 0;
}
