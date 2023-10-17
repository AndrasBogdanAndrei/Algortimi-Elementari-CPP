#include <iostream>
using namespace std;
int main()
{
    int x,y,c,ucif;
    cin>>x>>y;
    c = x % 10;
if (y % 4 == 1) ucif = c;
else if (y % 4 == 2) ucif = (c*c)%10;
else if (y % 4 == 3) ucif = (c*c*c)%10;
else if (y % 4 == 1) ucif = (c*c*c*c)%10;
    cout<<ucif;
    return 0;
}