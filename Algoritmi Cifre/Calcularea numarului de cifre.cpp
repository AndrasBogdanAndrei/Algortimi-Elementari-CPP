#include <iostream>
using namespace std;
int main()
{
    int n,nrcifre;
    cin>>n;
    nrcifre=0;
    if(n==0)
    nrcifre=1;
    while(n>0)
    {
        nrcifre++;
        n=n/10;
    }
    cout<<nrcifre;
    return 0;
}