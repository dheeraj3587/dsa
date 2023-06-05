#include <bits/stdc++.h>
using namespace std;

// Function to count the number of prime numbers up to 'n'
int Prime(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    // Sieve of Eratosthenes algorithm
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]){
            count++;
        }
    }
    return count;
}

int main() {
    int n = 100; // Static input for the limit

    int count = Prime(n);

    cout << "The number of primes up to " << n << " is " << count << endl;

    return 0;
}
