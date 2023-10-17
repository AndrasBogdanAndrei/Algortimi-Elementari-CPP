#include <iostream>
using namespace std;
int main()
{
    int n,p,cif;
    cin>>n;
    p=1;
    while(p*10<=n)
        p=p*10;
    while(n>0)
    {
        cif=n/p;
        //prelucreaza cifra cif;
        cout<<cif<<" ";
        n=n%p;
        p=p/10;
    }
    return 0;
    cout<<p;
}
    