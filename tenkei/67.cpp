#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

string act(string &sin8) {
    if (sin8 == "0") {
        return "0";
    }
    long long sin9 = 0;
    for (char c : sin8) {
        sin9 = sin9 * 8 + c - '0';
    }
    string t;
    while (sin9) {
        if (sin9 % 9 == 8) {
            t += '5';
        } else {
            t += sin9 % 9 + '0';
        }
        sin9 /= 9;
    }
    reverse(t.begin(), t.end());
    return t;
}


int main() { 
    string N;
    int K;
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        N = act(N);
    }
    cout << N << endl;
    

    return 0;
}
