#include <iostream>
using namespace std;
int main()
{
  int n,cif;
  cin>>n;
  while(n!=0)
  {
    cif=n%10;
    n=n/10;
    cout<<cif<<" ";
  }
  return 0;
}
// n=6789, cout 9 8 7 6