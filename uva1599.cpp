//Bismillahir Rahmanir Rahim

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
		

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue> 

using namespace std;


#define pii pair<int,int>
#define xx first
#define yy second
#define sci(n) scanf("%d",&n)
#define scii(n,m) scanf("%d%d",&n,&m)
#define sciii(n,m,w) scanf("%d%d%d",&n,&m,&w)

#define all(v) v.begin(),v.end()
#define pb push_back



#define mxn 100005

vector<pii> adj[mxn];
int dis[2][mxn];
vector<int>ans;
int n , m;
bool vis[mxn];
int par[mxn];
int color[mxn];

const int INF = 2e9 + 5;

void bfs(int s,int id){
    
    for(int i = 1;i <= n;i++) dis[id][i] = INF;

	queue<int> q;
	q.push(s);
	dis[id][s] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : adj[u]){
			if(dis[id][v.xx] != INF) continue;
			dis[id][v.xx] = dis[id][u] + 1;
			q.push(v.xx);
		}
	} 

}



void  bfs_path(int s){
     


     queue<int> q;
     q.push(s);
     vis[s] = true;

   while(!q.empty()){ 
     int mn = INF;
     queue<pair<int , pii>> temp;
     
  

     while(!q.empty()){
     	int u = q.front();
     	q.pop();
     	vis[u]  = true;
        
     	for(auto v : adj[u]){
     		if(vis[v.xx]) continue;
     		 //cout << v.xx <<" " <<mp[{u , v.xx}]<< endl;
     		mn = min(mn , v.yy);
     		temp.push({u ,  v });
     	}
        
     }

  //   cout << "mn " << mn << endl;

     bool flag = false;
    
     while(!temp.empty()){
        pair<int , pii> u = temp.front();
     	temp.pop();
         vis[u.yy.xx] = true;
         
        if(u.yy.yy == mn){
            q.push(u.yy.xx) ;
        	// cout << u.yy.xx << endl;
            par[u.yy.xx] = u.xx;
            color[u.yy.xx] = u.yy.yy;


            if(u.yy.xx == n){
            	flag = true;
            	break;
            }
        }


     }



     if(flag) break;


   }


   int x = n;
   // ans.pb(n);
   int y;

   while(x > 1){
   	  y = x;
   	  x = par[x];
   	 //cout << x <<" " << y << endl;
   	  ans.pb(color[y]);
   	  if(y == 1) break;
   }
  

    

    reverse(all(ans));
    printf("%d\n", (int)ans.size());

    for(int i = 0;i < ans.size();i++){
    	if(i > 0)printf(" %d", ans[i]);
    	else printf("%d", ans[i]);
    }
    printf("\n");




}


int main(){
       //IOS;

    int u , v, w;
	while(scii(n , m) == 2){
		
		for(int i = 0;i < m;i++){


		   sciii(u , v, w);
		   adj[u].pb({v,w});
		   adj[v].pb({u,w});


		}
        

		bfs(1 , 0);
		bfs(n , 1);


    for(int i = 1;i <= n;i++){
    	if(dis[0][i] + dis[1][i] != dis[0][n]) vis[i] = true ; //cout << i << endl;
    }
    
    bfs_path(1);

    
    for(int i = 1;i <= n;i++){

    	adj[i].clear();
    	vis[i] =  par[i] = color[i]= 0;
    }

    
    ans.clear();

	}














return 0;}
