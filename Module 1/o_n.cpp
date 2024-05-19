#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)//o(n)
    {
        cin>>a[i];
    }
    int s=0;
    for(int i=0; i<n; i+=2)//o(n)
    {
        s+=a[i];
    }
    cout<<s<<endl;

  return 0;
 }

 //O(n) Time complexity program.just count for loop...ignore the constant value and  O(1)...Time Complexity is always less than or equal to.