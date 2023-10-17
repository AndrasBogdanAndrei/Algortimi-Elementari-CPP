#include <iostream>
using namespace std;

int main()
{
    int n, a = 1, b = 1, c = a + b;
    cin >> n;   
    while (c <= n)
    {
        a = b;
        b = c;
        c = a + b;
    }
    
    cout << a << endl;
    
    return 0;
}
