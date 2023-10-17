#include <iostream>
using namespace std;
int main()
{
    int p,n,nr,cif;
    cin>>n;
    p=1;
    nr=0;
    while(n>0)
    {
        cif = n % 10;
        if(cif % 2!=0)
        {
            nr = nr + cif*p;
            p = p * 10;
        }
        n=n/10;
    }
    cout<<nr;
    return 0;
}