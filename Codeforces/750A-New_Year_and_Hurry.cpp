#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a = 5;
    int d = 5;
    
    int sum = (n * (2 * a + (n - 1) * d)) / 2;

    vector<int> minutes(n);
    for(int i = 0; i < n; i++) {
        minutes[i] = a * (i + 1);  
    }

    int aa = n;
    while((sum + k) > 240 && aa > 0) {
        sum -= minutes[aa - 1];
        aa--;
    }

    cout << aa;
    return 0;
}
