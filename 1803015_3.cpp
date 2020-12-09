#include<bits/stdc++.h>
using namespace std;


int main()
{
    
    double start_time = clock();

    int n;
    cin >> n;
    vector<int> arr(n + 5);

    for(int i = 0;i < n;i++){
       cin >> arr[i];
    }    

    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    } 

    double end_time = clock();


    cout << fixed << setprecision(8);
    cout << (end_time - start_time) / (double)CLOCKS_PER_SEC * 1000<< endl;
    
    // for(int i = 0;i < n;i++){
    //    cout << arr[i] <<" ";
    // }    
    // cout << endl;





}