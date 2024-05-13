#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() { 
    ll sum = 0;
    rep(i, 100000) {
        sum += i;
    }
    sum %= 1000000007;
    sum *= 5;
    sum %= 1000000007;
    cout << sum << endl;
    return 0; }
