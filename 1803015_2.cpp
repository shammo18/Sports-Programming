#include<bits/stdc++.h>
using namespace std;


int main()
{


    
    int n;
    cin >> n;
    vector<int> num(n + 5);

    for(int i = 1;i <= n;i++){
       cin >> num[i];
    }
    
    double start_time = clock();

    for ( int i = 1 ; i <= n ; i ++ )
    {
        for ( int j = 1 ; j < n ; j ++)
            if ( num [j + 1] < num [j] )
            {
                int temp = num [j] ;
                
                num [j] = num [j + 1] ;
                num [j + 1] = temp ;
            }
    }



    double end_time = clock();
    cout << fixed << showpoint <<  setprecision(5);
    cout << ((end_time - start_time) / (double)CLOCKS_PER_SEC )* 1000 << endl;

    // for(int i = 1;i <= n;i++){
    //    cout << num[i] <<" ";
    // }    
    // cout << endl;




}