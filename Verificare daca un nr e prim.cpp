#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool prim = true; //bool functioneaza si ca int
    if(n < 2)
        prim = false;
    for(int d =2 ; d * d <= n ; d ++) //ruleaza pana d*d<=n e fals
        if(n % d == 0) //se folosesc toate d-urile din for, Dacă se găsește un d care împarte pe n, atunci se oprește verificarea și se declară că n nu este prim. Dacă nu se găsește niciun d care împarte pe n, atunci se declară că n este prim.
            prim = false;
    if(prim)
    cout << n << " este prim";
    else
    cout << n << " nu este prim";
    return 0;
}