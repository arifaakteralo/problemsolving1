#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    vector<int> price(n);
    cout << "Enter the prices for each piece length (1 to " << n << "): ";
    for (int i = 0; i < n; i++)
        cin >> price[i];

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {     
        for (int j = 1; j <= i; j++) {   
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
        }
    }

    cout << "Maximum obtainable value: " << dp[n];
    return 0;
}
