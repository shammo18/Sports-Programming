//Bismillahir Rahmanir Rahim

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
		
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

using namespace __gnu_pbds;
using namespace std;


///********************************MY CODE STARTS HERE********************************///


#define mxn 500005

vector<int> g[mxn];

int st[mxn] , et[mxn] , T = -1;
vector<int> arr;
int pos[mxn];
int vis[mxn];

void dfs(int u , int p){
    
    st[u] = ++T;

	for(auto v : g[u]){
		if(v == p) continue;
		dfs(v , u);
	}

	arr.pb(u);
	pos[u] = (int)arr.size() - 1;
	et[u] = T;

}

struct info{
     int up;
     int lazy;
}seg_type_1[4 * mxn] , seg_type_2[4 * mxn];

void update_type_1(int node,int b,int e,int i, int j, int cur){

     if(b > j || e < i) return;
     if(b >= i && e <= j){
        seg_type_1[node].up = max(seg_type_1[node].up , cur);
        seg_type_1[node].lazy = seg_type_1[node].up;
        return;
     }

     int left = 2 * node;
     int right = left + 1;
     int mid = (b + e) / 2;


     if(seg_type_1[node].lazy != 0){

        seg_type_1[left].lazy = max(seg_type_1[left].lazy , seg_type_1[node].lazy);
        seg_type_1[right].lazy = max(seg_type_1[right].lazy , seg_type_1[node].lazy);

        seg_type_1[left].up = max(seg_type_1[left].up , seg_type_1[node].lazy);
        seg_type_1[right].up = max(seg_type_1[right].up ,  seg_type_1[node].lazy);
        seg_type_1[node].lazy = 0;
     }

     update_type_1(left,b,mid,i,j,cur);
     update_type_1(right,mid + 1,e,i,j,cur);

     seg_type_1[node].up = max(seg_type_1[left].up  ,  seg_type_1[right].up);

}

void update_type_2(int node,int b,int e,int i, int j, int cur){

     if(b > j || e < i) return;
     if(b >= i && e <= j){
        seg_type_2[node].up = max(seg_type_2[node].up , cur);
        seg_type_2[node].lazy = seg_type_2[node].up;
        return;
     }

     int left = 2 * node;
     int right = left + 1;
     int mid = (b + e) / 2;


     if(seg_type_2[node].lazy != 0){

        seg_type_2[left].lazy = max(seg_type_2[left].lazy , seg_type_2[node].lazy);
        seg_type_2[right].lazy = max(seg_type_2[right].lazy , seg_type_2[node].lazy);

        seg_type_2[left].up = max(seg_type_2[left].up , seg_type_2[node].lazy);
        seg_type_2[right].up = max(seg_type_2[right].up ,  seg_type_2[node].lazy);
        seg_type_2[node].lazy = 0;
     }

     update_type_2(left,b,mid,i,j,cur);
     update_type_2(right,mid + 1,e,i,j,cur);

     seg_type_2[node].up = max(seg_type_2[left].up  ,  seg_type_2[right].up);

}



int query_type_1(int node,int b,int e,int i, int j){

   if(b > j || e < i) return 0;
   if(b >= i && e <= j){
        return seg_type_1[node].up;
   }

   int left = node * 2;
   int right = left + 1;
   int mid = (b + e) / 2;


     if(seg_type_1[node].lazy != 0){

        seg_type_1[left].lazy = max(seg_type_1[left].lazy , seg_type_1[node].lazy);
        seg_type_1[right].lazy = max(seg_type_1[right].lazy , seg_type_1[node].lazy);

        seg_type_1[left].up = max(seg_type_1[left].up , seg_type_1[node].lazy);
        seg_type_1[right].up = max(seg_type_1[right].up ,  seg_type_1[node].lazy);
        seg_type_1[node].lazy = 0;
     }

   int x = query_type_1(left,b,mid,i,j);
   int y = query_type_1(right,mid + 1,e,i,j);

   return max(x , y);
}

int query_type_2(int node,int b,int e,int i, int j){

   if(b > j || e < i) return 0;
   if(b >= i && e <= j){
        return seg_type_2[node].up;
   }

   int left = node * 2;
   int right = left + 1;
   int mid = (b + e) / 2;


     if(seg_type_2[node].lazy != 0){

        seg_type_2[left].lazy = max(seg_type_2[left].lazy , seg_type_2[node].lazy);
        seg_type_2[right].lazy = max(seg_type_2[right].lazy , seg_type_2[node].lazy);

        seg_type_2[left].up = max(seg_type_2[left].up , seg_type_2[node].lazy);
        seg_type_2[right].up = max(seg_type_2[right].up ,  seg_type_2[node].lazy);
        seg_type_2[node].lazy = 0;
     }

   int x = query_type_2(left,b,mid,i,j);
   int y = query_type_2(right,mid + 1,e,i,j);

   return max(x , y);
}





int main(){
       IOS;
    
    int n , u , v;
    cin >> n;
    for(int i = 1;i <= n - 1;i++){
        cin >>u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    dfs(1 , 0);



    int q;
    cin >> q;
    for(int idx = 1;idx <= q;idx++){
    	int t , l , r;
    	cin >> t >> v;
    	  r = pos[v];
    	  l = r - et[v] + st[v];

    	if(t == 1){

          update_type_1(1 , 0 , n - 1 , l , r , idx);

    	}else if(t == 2){
          
          update_type_2(1 , 0 , n - 1 , r , r , idx);

    	}else{
          u = query_type_1(1 , 0 , n - 1 , r , r);
          v = query_type_2(1 , 0 , n - 1 , l , r);
          if(u == 0 || v > u) cout << 0 << endl;
          else cout << 1 << endl;
    	}

    }












return 0;}
