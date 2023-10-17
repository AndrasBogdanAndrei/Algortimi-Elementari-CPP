#include <iostream>
using namespace std;
int main()
{
    int n,cifc=0;
    cin>>n;
      if(n==0)
        cifc=0;
    else
      if(n%9==0) 
        cifc=9;
    else
        cifc=n%9;
    
    cout<<cifc;
    return 0;
}
