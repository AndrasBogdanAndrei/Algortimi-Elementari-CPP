#include <iostream>
using namespace std;
int main()
{
    int n,nrd,s,d;
    cin >> n; 
    for(d = 2; d <= n / 2; d++)
        if(n % d == 0){
            cout << d << " ";
        }
        return 0;
}