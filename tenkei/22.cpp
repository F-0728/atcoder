#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() { 
    long long A, B, C;
    cin >> A >> B >> C;
    long long gcd2 = gcd(A, B);
    long long gcd3 = gcd(gcd2, C);
    long long Abl, Bbl, Cbl;
    Abl = A / gcd3;
    Bbl = B / gcd3;
    Cbl = C / gcd3;
    cout << Abl + Bbl + Cbl - 3 << endl;

    return 0;
}
