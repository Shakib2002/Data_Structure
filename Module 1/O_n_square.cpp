#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    int n;
    cin>>n;
    // for(int i=1; i<=n;i++)//o(n*n)
    // {
    //     for(int j=1; j<=n; j++)
    //     {
    //         cout<<"hello"<<endl;
    //     }
    // } 

    for(int i=0; i<=n-1;i++)//o(n*n)
    {
        for(int j=i+1; j<n; j++)
        {
            cout<<"hello"<<endl;
        }
    } 
  return 0;
 }