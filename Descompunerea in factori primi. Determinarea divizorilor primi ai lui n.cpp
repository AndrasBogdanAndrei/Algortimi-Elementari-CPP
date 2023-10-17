#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d = 2;
    while (n > 1)
    {
        int p = 0;
        while (n % d == 0)
        {
            n = n / d;
            p++;
        }
        
        if (p > 0)
        {
            cout << d << "^" << p << " ";
        }
        
        d++;
    }
    
    cout << endl;
    
    return 0;
}
