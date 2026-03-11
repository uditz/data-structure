#include <bits/stdc++.h>
using namespace std;

/*
============================================================
                BIT MANIPULATION CHEAT SHEET
============================================================

Binary Basics
-------------
Decimal → Binary example:
5 = 101
10 = 1010

Bit positions (0-indexed from right):
Example:
13 = 1101
     3210

bit 0 = 1
bit 1 = 0
bit 2 = 1
bit 3 = 1
*/

/*
============================================================
                BASIC BIT OPERATORS
============================================================

&  → AND
|  → OR
^  → XOR
~  → NOT
<< → Left shift
>> → Right shift
*/

void basicOperators() {

    int a = 5;   // 101
    int b = 3;   // 011

    cout << (a & b) << endl; // 001 = 1
    cout << (a | b) << endl; // 111 = 7
    cout << (a ^ b) << endl; // 110 = 6

    cout << (~a) << endl; // flips all bits

    cout << (a << 1) << endl; // multiply by 2
    cout << (a >> 1) << endl; // divide by 2
}

/*
============================================================
                CHECK IF BIT IS SET
============================================================

Check if kth bit is set or not
*/

bool isKthBitSet(int n, int k) {

    /*
    1 << k creates a mask

    Example:
    n = 5 (101)
    k = 2

    mask = 1 << 2 = 100

    101
    100
    ---
    100 → non-zero → bit is set
    */

    return (n & (1 << k));
}

/*
============================================================
                SET A BIT
============================================================

Turn kth bit into 1
*/

int setBit(int n, int k) {

    /*
    Example:
    n = 5 = 101
    k = 1

    mask = 010

    101
    010
    ---
    111 = 7
    */

    return n | (1 << k);
}

/*
============================================================
                CLEAR A BIT
============================================================

Turn kth bit into 0
*/

int clearBit(int n, int k) {

    /*
    Example:
    n = 7 = 111
    k = 1

    mask = ~(010)

    111
    101
    ---
    101 = 5
    */

    return n & ~(1 << k);
}

/*
============================================================
                TOGGLE A BIT
============================================================

Flip kth bit
*/

int toggleBit(int n, int k) {

    /*
    Example:
    n = 5 = 101
    k = 1

    mask = 010

    101
    010
    ---
    111
    */

    return n ^ (1 << k);
}

/*
============================================================
                REMOVE LAST SET BIT
============================================================

Trick: n & (n-1)

Example:
n = 12 = 1100
n-1 = 11 = 1011

1100
1011
----
1000
*/

int removeLastSetBit(int n) {
    return n & (n - 1);
}

/*
============================================================
                GET LAST SET BIT
============================================================

Trick: n & (-n)

Example:
n = 12 = 1100
-n = two's complement

Result = 0100
*/

int lastSetBit(int n) {
    return n & (-n);
}

/*
============================================================
                CHECK POWER OF TWO
============================================================

Power of two numbers have only ONE set bit.

Example:
8 = 1000
16 = 10000
*/

bool isPowerOfTwo(int n) {

    /*
    Example:
    n = 8 = 1000
    n-1 = 7 = 0111

    1000
    0111
    ----
    0000
    */

    return n && !(n & (n - 1));
}

/*
============================================================
                COUNT SET BITS
============================================================
*/

int countBits(int n) {

    // built-in GCC function
    return __builtin_popcount(n);
}

/*
============================================================
                COUNT LEADING ZEROS
============================================================
*/

int leadingZeros(int n) {

    return __builtin_clz(n);
}

/*
============================================================
                COUNT TRAILING ZEROS
============================================================
*/

int trailingZeros(int n) {

    return __builtin_ctz(n);
}

/*
============================================================
                GENERATE MASK OF N BITS
============================================================

Example:
n = 5

mask = 11111
*/

int maskNbits(int n) {

    return (1 << n) - 1;
}

/*
============================================================
        SET ALL BITS UNTIL HIGHEST SET BIT
============================================================

Example:
n = 10 = 1010

Result:
1111
*/

int fillBits(int x) {

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x;
}

/*
============================================================
                SUBSET ENUMERATION
============================================================

Useful in Bitmask DP
*/

void generateSubsets(int n) {

    /*
    Example:
    n = 3

    subsets = 0 to (1<<n)-1
    */

    for(int mask = 0; mask < (1 << n); mask++) {

        for(int i = 0; i < n; i++) {

            if(mask & (1 << i)) {
                cout << i << " ";
            }
        }

        cout << endl;
    }
}

/*
============================================================
                ITERATE SUBMASKS
============================================================

Very useful trick
*/

void iterateSubmasks(int mask) {

    int sub = mask;

    while(sub) {

        cout << sub << endl;

        sub = (sub - 1) & mask;
    }
}

/*
============================================================
                SWAP USING XOR
============================================================
*/

void xorSwap(int &a, int &b) {

    a ^= b;
    b ^= a;
    a ^= b;
}

/*
============================================================
                FIND UNIQUE ELEMENT
============================================================

If every element appears twice except one
*/

int findUnique(vector<int> &arr) {

    int ans = 0;

    for(int x : arr)
        ans ^= x;

    return ans;
}

/*
============================================================
                FAST MULTIPLY / DIVIDE
============================================================

n << k  = n * 2^k
n >> k  = n / 2^k
*/

int multiplyByPowerOfTwo(int n, int k) {
    return n << k;
}

/*
============================================================
                CHECK EVEN / ODD
============================================================
*/

bool isEven(int n) {
    return !(n & 1);
}

/*
============================================================
                MAIN
============================================================
*/

int main() {

    cout << isKthBitSet(5,2) << endl; // true
    cout << setBit(5,1) << endl;      // 7
    cout << clearBit(7,1) << endl;    // 5
    cout << toggleBit(5,1) << endl;   // 7

    cout << removeLastSetBit(12) << endl; // 8
    cout << lastSetBit(12) << endl;       // 4

    cout << isPowerOfTwo(16) << endl;     // true

    cout << countBits(7) << endl;         // 3

    cout << maskNbits(5) << endl;         // 31

    cout << fillBits(10) << endl;         // 15

    return 0;
}
