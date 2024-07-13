#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() { 
    int N, A, B;
    cin >> N >> A >> B;
    int sum = 0;
    for (int i = 1; i < N+1; i++) {
        int a4 = i/10000;
        int a3 = (i%10000)/1000;
        int a2 = (i%1000)/100;
        int a1 = (i%100)/10;
        int a0 = i%10;
        int bitsum = a4 + a3 + a2 + a1 + a0;
        if (A <= bitsum && bitsum <= B) {
            sum += i;
        }
    }
    cout << sum << endl;

    return 0;
}
