//Bismillahir Rahmanir Rahim

// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")
		
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

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

// using namespace __gnu_pbds;
using namespace std;


///********************************MY CODE STARTS HERE********************************///


#define mxn 100005

int n , m , s , f , r;
vector<int> adj[mxn];
int dis[3][mxn];
int maxx[mxn];

// bool vis[mxn], active[mxn];
bool [mxn];                                  // id ->      0 = s      1 = f     2 = r
                       
void bfs(int s , int id){
     
     for(int i = 1;i <= n;i++) dis[id][i] = inf;

     queue<int> q;
     q.push(s);
     dis[id][s] = 0;

     
     while(!q.empty()){
     	int u = q.front();
     	q.pop();

     	for(int v : adj[u]){
     		if(dis[id][v] == inf){
     			dis[id][v] = dis[id][u] + 1;

     		    q.push(v);
     		}
     	}
     }     

}


// int bfs_path(int s){
     
//      active[s] = true;
//      queue<int> q;
//      q.push(s);
//      vis[s] = true;

//    while(!q.empty()){ 
//      int mx = -1;
//      queue<int> temp;
     
  

//      while(!q.empty()){
//      	int u = q.front();
//      	q.pop();
        
//      	for(auto v : adj[u]){
//      		if(vis[v]) continue;
//      		vis[v] = true;
//      		// cout << v << endl;
//      		mx = max(mx , dis[2][v]);
//      		temp.push(v);
//      	}
        
//      }

//      bool flag = false;
    
//      while(!temp.empty()){
//      	int u = temp.front();
//      	temp.pop();

//         if(dis[2][u] == mx){
//         	active[u] = true , q.push(u) ;
//         	// cout << u << endl;
//             if(u == f){
//             	flag = true;
//             	break;
//             }
//         }
//      }
//      if(flag) break;
//     // cout << endl;

//    }
  
//    //cout << q.size() << endl;
//    q.push(f);
//    int ans = dis[2][f];

   
//    while(!q.empty()){
//      	int u = q.front();
//      	q.pop();

//      	for(int v : adj[u]){
//            if(active[v]){
//                // cout << v << endl;
//            	   ans = min(ans , dis[2][v]);
//            	   q.push(v);
//            	   active[u] = false;
//            	   break;
//            }
//      	}
//      } 

//      return max(0 , ans);







// }


int func(int f){

	queue<int> q;
	q.push(f);
	[f] = true;

    
    // for(int i = 1;i <= n;i++){
    // 	maxx[i] = -1;
    // 	//cout << dis[2][i] <<" ";
    // }

    maxx[f] = dis[2][f];

  while(!q.empty()){
    
    queue<int> temp;

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(auto v : adj[u]){
			if([v]) continue;
			//cout << u <<"  "<< v << endl;
			maxx[v] = max(maxx[v] , dis[2][u]);
			temp.push(v); 
		}
		//cout << endl;
	}
   // cout << endl;

	  while(!temp.empty()){
     	int u = temp.front();
     	temp.pop();

     	if([u]) continue;

     	//cout << "here " << u << endl;
         
		  dis[2][u] = min(dis[2][u] , maxx[u]);
		  [u] = true;
		  q.push(u);

          }

	if([s])break;



  }
    //   for(int i = 1;i <= n;i++){
    // 	//maxx[i] = -1;
    // 	cout << dis[2][i] <<" ";
    // }
    //cout << "hi " << dis[2][2] << endl;
    return dis[2][s];

}


int main(){
       //IOS;
    
    scii(n , m);
    int u , v;
    for(int i = 0;i < m;i++){
    	scii(u , v);
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    sciii(s , f , r);

    bfs(s , 0);
    bfs(f , 1);
    bfs(r , 2);

   //  cout << dis[0][f] << endl;

    for(int i = 1;i <= n;i++){
    	//cout << dis[1][i] << endl;
    	if(dis[0][i] + dis[1][i] != dis[0][f]) [i] = true ;// cout << i << endl;
    }

    // func(f);
     
   // int ans = bfs_path(s);
    int ans = func(f);
   printf("%d\n", ans);






    


    











return 0;}
