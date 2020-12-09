//Bismillahir Rahmanir Rahim

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
		
// #include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define xx first
#define yy second
#define sci(n) scanf("%d",&n)
#define scii(n,m) scanf("%d%d",&n,&m)
#define sciii(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scl(n) scanf("%lld",&n)
#define scll(n,m) scanf("%lld%lld",&n,&m)
#define sclll(n,m,w) scanf("%lld%lld%lld",&n,&m,&w)
#define pf(a)   printf("%d\n",a)
#define CASE(a) printf("Case %d: ",a)
#define dbg(i) printf("yo %d\n", i)
#define endl '\n'
#define READ  freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout);
#define pi acos(-1)
#define mem(a,b) memset(a,b,sizeof(a))
#define SQR(a) (a)*(a)
#define all(v) v.begin(),v.end()
#define pb push_back
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define inf INT_MAX
#define eps 1e-9


using namespace std;


///********************************MY CODE STARTS HERE********************************///


#define mxn 100005

unordered_map<int , bool> vis;
unordered_map<int , int>  dis;

int arr[] = {2 , 3 , 5 , 7 , 11 ,13 , 17 ,19};
bool prime[33];
vector<int> target = {1 , 2 , 3, 4 , 5 , 6 , 7 , 8};

 bool ok(vector<int> temp , vector<int> target){
	for(int i = 0;i < 8;i++){
		if(abs(temp[i]) != abs(target[i])) return false;
	}
	return true;
}

int get_hash(vector<int>& temp){
      int cur = 0;
      for(int i = 0;i < 8;i++){
      	  cur = cur * 10 + abs(temp[i]);
      }

      return cur;
}

int solve(){

	vis.clear();
	dis.clear();

     
     vector<int> v(8);
     for(int i = 0;i < 8;i++){
     	sci(v[i]);
    }

     queue<vector<int> > q;
     q.push(v);
     vis[get_hash(v)] = true;
     dis[get_hash(v)] = 0;
     if(ok(v , target)) return 0;

     while(q.size() > 0){
     	vector<int> u = q.front();
     	q.pop();

     	for(int i = 0;i < 7;i++){
     		for(int j = i + 1;j < 8;j++){

                if(u[i] * u[j] < 0 && prime[abs(u[i]) + abs(u[j])]){
                	vector<int> temp;
                	for(int k = 0;k < i;k++) temp.pb(u[k]);
                	temp.pb(u[j]);
                    for(int k = i;k < 8;k++) if(u[k] != u[j])temp.pb(u[k]);

                    if(!vis[get_hash(temp)]){
                    	vis[get_hash(temp)] = true;
                    	dis[get_hash(temp)] = dis[get_hash(u)] + 1;
                    	if(ok(temp ,target)) return dis[get_hash(temp)];
                    	q.push(temp);
                    }
                    
                    temp.clear();
                    for(int k = 0;k <= i;k++) temp.pb(u[k]);
                	temp.pb(u[j]);
                    for(int k = i + 1;k < 8 ;k++) if(u[k] != u[j])temp.pb(u[k]);

                    if(!vis[get_hash(temp)]){
                    	vis[get_hash(temp)] = true;
                    	dis[get_hash(temp)] = dis[get_hash(u)] + 1;
                    	if(ok(temp ,target)) return dis[get_hash(temp)];
                    	q.push(temp);
                    }


                    temp.clear();
                    for(int k = 0;k < j;k++) if( u[k] != u[i])temp.pb(u[k]);
                	temp.pb(u[i]);
                    for(int k = j;k < 8;k++) temp.pb(u[k]);

                    if(!vis[get_hash(temp)]){
                    	vis[get_hash(temp)] = true;
                    	dis[get_hash(temp)] = dis[get_hash(u)] + 1;
                    	if(ok(temp ,target)) return dis[get_hash(temp)];
                    	q.push(temp);
                    }

                    temp.clear();
                    for(int k = 0;k <= j;k++)if(u[k] != u[i]) temp.pb(u[k]);
                	temp.pb(u[i]);
                    for(int k = j + 1;k < 8;k++) temp.pb(u[k]);

                    if(!vis[get_hash(temp)]){
                        vis[get_hash(temp)] = true;
                    	dis[get_hash(temp)] = dis[get_hash(u)] + 1;
                    	if(ok(temp ,target)) return dis[get_hash(temp)];
                    	q.push(temp);
                    }
                }
     		}
     	}
     }

     return -1;






}

int main(){
       //IOS;
/*       
    #ifndef ONLINE_JUDGE
      READ;
      WRITE;
    #endif 
*/
   
for(int i = 0;i < 8;i++) prime[arr[i]] = true;
   
   // vector<int> lol = target;

   
   int t;
   sci(t);
   int ca = 1;
   while(t--){
   	CASE(ca++);
   	int ans = solve();
   	printf("%d\n", ans);
   }
















return 0;}
