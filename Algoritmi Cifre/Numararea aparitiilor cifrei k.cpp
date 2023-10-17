#include <iostream>
using namespace std;
int main()
{
    int n,k,nrap,cif;
    cin>>n>>k;
    nrap=0;
    if (n==0 && k==0)
     nrap = 1;
    while(n>0)
    {
        cif=n%10;
        if(cif==k)
        nrap++;
        n=n/10;
    }
    cout<<nrap;
    return 0;
}
