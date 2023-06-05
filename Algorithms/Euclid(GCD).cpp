// Algorithm: Euclidean Algorithm for finding the Greatest Common Divisor (GCD)

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the GCD of two numbers using the Euclidean Algorithm
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }

    // Apply Euclidean Algorithm until a and b become equal
    while (a != b) {
        if (a < b) {
            b = b - a;
        } else {
            a = a - b;
        }
    }

    return a; // Return the GCD
}

int main() {
    int a = 36; // First number
    int b = 48; // Second number

    int res = gcd(a, b);

    cout << "The gcd of " << a << " and " << b << " is " << res << endl;

    return 0;
}
