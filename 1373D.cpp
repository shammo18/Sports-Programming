//Bismillahir Rahmanir Rahim

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
        
#include<bits/stdc++.h>
#define ll long long

using namespace std;




void solve(){
     

      int n;
      cin >> n;
      vector<ll> arr(n + 5) , even(n + 5) , odd(n + 5);
      ll ans  , jor_sum = 0;

      for (int i = 0; i < n; ++i)
      {
           cin >> arr[i];
           if(i % 2 == 0){
               jor_sum += arr[i];
           }
      }

      ans = jor_sum;      // Initial Even place gular  sum 


     
      for(int i = 1;i < n;i++){      // CUMSUM of Odd postions
          if(i & 1){
            odd[i] = odd[i - 1] + arr[i];
          }else {
            odd[i] = odd[i - 1];
          }
      }

     even[0] = arr[0];

     for(int i = 1;i < n;i++){       // CUMSUM of Even positions
          if(i %2 ==  0){
            even[i] = even[i - 1] + arr[i];
          }else {
            even[i] = even[i - 1];
          }
          
      }


      ll curr_odd = 0 , curr_even = even[0] - odd[0];

      for(int i = 1;i < n;i++){
            
            ll temp = odd[i] - even[i];    // odd[R] - even[R]

            if(i % 2 == 0){
              
              ans = max(ans , jor_sum + curr_even + temp);
              curr_even = max(curr_even , even[i] - odd[i]);   // even[L] - odd[L]

            }else {

              ans = max(ans , jor_sum + curr_odd + temp);
              curr_odd = max(curr_odd , even[i] - odd[i]);     // even[L] - odd[L]
            }


      }

      cout << ans << endl;


     

}



int main(){
       //IOS;
/*       
    #ifndef ONLINE_JUDGE
      READ;
      WRITE;
    #endif 
*/

   
   int t = 1;
   cin >> t;
   while(t--){
    solve();
   }













return 0;}
