#include <bits/stdc++.h>

using namespace std;
 
// Function to find the

long long minDigits(long long n)
{

    vector<char> str;

    // Convert number long longo string

    long long i = 0;

    while (n != 0) {

        long long rem = n % 10;
 

        // convert long long long longo char

        // by adding '0'

        char ch = (rem + '0');

        str.push_back(ch);

        n /= 10;

    }
 

    // Reverse string

    reverse(str.begin(), str.end());
 

    long long ans = INT_MAX;

    long long N = str.size();

    for (long long i = 0; i < N; i++) {

        for (long long j = i + 1; j < N; j++) {
 

            // Number formed by

            // last two digits

            long long num = (str[i] - '0')

                          * 10

                      + (str[j] - '0');
 

            if (num % 25 == 0) {
 

                // Count of unwanted digits

                // between i and j

                long long a = j - i - 1;
 

                // Count of unwanted

                // digits after j

                long long b = N - (j + 1);

                ans = min(ans, a + b);

            }

        }

    }
 

    return ans;
}
 
// Driver Code

int main()
{
long long m;
cin >> m;
while(m--){
    long long n;
    cin >> n;

    long long ans = minDigits(n);

        cout << ans << endl;

    }

    return 0;
}