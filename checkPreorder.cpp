#include<iostream>
#include<stack>
using namespace std;

bool func(int a[], int n)
{
    int root=-999;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(root>a[i])
         return false;

         while(!s.empty() && s.top()<a[i])
         {
             root = s.top();
             s.pop();
         }

        s.push(a[i]);

    }
    return true;


}

int main()
{
    int a[]={40,30,35,80,100};
    int n=sizeof(a)/sizeof(a[0]);
    bool val=func(a,n);
    cout<<val;

    cout<<n;
}
