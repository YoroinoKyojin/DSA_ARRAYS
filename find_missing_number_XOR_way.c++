// Two important properties of XOR are the following:

// XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
// XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

// Now, let’s XOR all the numbers between 1 to N.
// xor1 = 1^2^…….^N

// Let’s XOR all the numbers in the given array.
// xor2 = 1^2^……^N (contains all the numbers except the missing one).

// Now, if we again perform XOR between xor1 and xor2, we will get:
// xor1 ^ xor2 = (1^1)^(2^2)^……..^(missing Number)^…..^(N^N)

// Here all the numbers except the missing number will form a pair and each pair will result in 0 according to the XOR property. The result will be = 0 ^ (missing number) = missing number (according to property 2).

// So, if we perform the XOR of the numbers 1 to N with the XOR of the array elements, we will be left with the missing number.


#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int N) {

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}