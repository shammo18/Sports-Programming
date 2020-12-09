#include <bits/stdc++.h>
#define ll long long
#define fastandfurious ios_base::sync_with_stdio(false);cin.tie(0);
#define pf printf(" OK \n")
#define MAX 2000005LL
#define pii pair<ll,ll>
#define ff first
#define ss second
const ll blk_sz=ceil(sqrt((double)MAX));
using namespace std;
vector <ll> arr(MAX),cnt(2000010),ans(MAX);
pair <pii, ll > query[MAX];
ll answer =0;
bool cmp(pair<pii,ll> a, pair<pii,ll> b)
{
    if(a.ff.ff/blk_sz == b.ff.ff/blk_sz)return  (a.ff.ss<b.ff.ss)^((a.ff.ff/blk_sz)%2);
    return (a.ff.ff/blk_sz < b.ff.ff/blk_sz);
}
 
void add(ll val)
{
    cnt[val]++;
    if(cnt[val] & 1)
    answer = answer - val*((cnt[val]-1) / 2)*((cnt[val]-1) /2) + val*(cnt[val] / 2 + 1)*(cnt[val] / 2 + 1);
    else
   answer = answer - val*((cnt[val]-1) / 2 + 1)*((cnt[val]-1) /2 + 1) + val*(cnt[val] / 2)*(cnt[val] / 2);


}
void remov(ll val)
{   
    if(cnt[val] & 1){
    answer = answer + val*((cnt[val]-1) / 2)*((cnt[val]-1) /2) - val*(cnt[val] / 2 + 1)*(cnt[val] / 2 + 1);cnt[val]--;
    }
    else
    {
    answer = answer + val*((cnt[val]-1) / 2 + 1)*((cnt[val]-1) /2 + 1) - val*(cnt[val] / 2)*(cnt[val] / 2);cnt[val]--;

    }
}
 
int main()
{   fastandfurious


    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)cin>>arr[i];

    for(ll i=1;i<=q;i++){
        ll l,r;
        cin>>l>>r;
        query[i].ff.ff = l;
        query[i].ff.ss = r;
        query[i].ss = i;
    }
    sort(query,query + q,cmp);
    ll curr_left=1,curr_right=1;
    for(ll i=1;i<=q;i++){
        ll left  = query[i].ff.ff;
        ll right = query[i].ff.ss;
        ll idx   = query[i].ss;
        while(curr_left < left){


            remov(arr[curr_left]);curr_left++;}
        while(curr_left > left){
            --curr_left;


            add(arr[curr_left]);}
        while(curr_right <= right){


            add(arr[curr_right]);curr_right++;}
        while(curr_right > right+1){
           --curr_right; 

            remov(arr[curr_right]);}
        ans[idx] = answer;
 
    }
    for(ll i=1;i<=q;i++)
       cout<<ans[i]<<endl;  
    return 0;
}