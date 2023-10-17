#include <iostream>
using namespace std;
int main()
{
    int n,primacif;
cin>>n;
    if(n==0)
primacif=0;
    while(n>9)
    {
        n=n/10;
        primacif=n;
    }
    cout<<primacif;
    return 0;
}
//n=567, cout 5