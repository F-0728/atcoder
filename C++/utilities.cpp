#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

string baseNtoM(string &s, int n, int m) {
    if (s == "0") {
        return "0";
    }
    long long t = 0;
    for (char c : s) {
        t = t * n + c - '0';
    }
    string r;
    while (t) {
        r += t % m + '0';
        t /= m;
    }
    std::reverse(r.begin(), r.end());
    return r;
}
