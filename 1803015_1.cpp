#include<bits/stdc++.h>
using namespace std;


int main()
{
    
    double start_time = clock();

    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    int x;
    cin>>x;

    int lo=0,hi=n-1;
    int index=-1;
    while(lo<hi)
    {
        int mid=(lo+hi + 1)>>1;

        if(arr[mid]==x)
        {
            index=mid;
            break;
        }

        if(arr[mid]>x)
        {
            hi=mid-1;
        }
        else lo=mid;
    }

    if(index==-1) cout<<"NOT FOUND"<<endl;
    else cout<<"Found at "<<index+1<<endl;

    double end_time = clock();


    cout << fixed << setprecision(5);
    cout << ((end_time - start_time) / (double)CLOCKS_PER_SEC) * 1000<< endl;






}