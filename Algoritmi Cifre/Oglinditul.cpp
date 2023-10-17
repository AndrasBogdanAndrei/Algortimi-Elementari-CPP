#include <iostream>
using namespace std;
int main()
{
    int n,cif,ogl;
    cin>>n;
    ogl=0;
    while(n>0)
    {
        cif=n%10;
        ogl=ogl*10+cif;
        n=n/10;
    }
    cout<<ogl;
    return 0;
}
// n=2134 cout 4312