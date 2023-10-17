#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int nrdiv = 0;
    for(int d = 1; d <= n; d++) {
        if(n % d == 0) 
        {
            nrdiv++;
        }
    }
    cout << nrdiv;
    return 0;
}
