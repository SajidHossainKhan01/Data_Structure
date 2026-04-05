#include <stdio.h>

// Taylor Series for e^x
// e^x = 1 + x/1! + x²/2! + x³/3! + ... (n terms)
double e(double x, int n) {
    static double p = 1;   // stores power of x (x^n)
    static double f = 1;   // stores factorial (n!)
    double r;

    if (n == 0)
        return 1;

    r = e(x, n - 1);       // recursive call first (head recursion)
    p = p * x;             // update power at returning time
    f = f * n;             // update factorial at returning time

    return r + p / f;      // add current term
}

int main() {
    printf("%lf\n", e(1, 10));   // Output: 2.718282  (e^1)
    printf("%lf\n", e(3, 10));   // Output: 20.079665 (e^3)
    printf("%lf\n", e(4, 10));   // Output: 54.440000 (e^4)
    printf("%lf\n", e(4, 15));   // Output: 54.597754 (more precise)

    return 0;
}

// 𝐇𝐨𝐰 𝐭𝐡𝐞 𝐓𝐚𝐲𝐥𝐨𝐫 𝐒𝐞𝐫𝐢𝐞𝐬 𝐰𝐨𝐫𝐤𝐬:

e^x = 1 + x/1! + x²/2! + x³/3! + x⁴/4! + ...

For e^1 (x=1, n=10):
= 1 + 1/1 + 1/2 + 1/6 + 1/24 + 1/120 + ...
= 2.718282...

// 𝐓𝐫𝐚𝐜𝐢𝐧𝐠 𝐟𝐨𝐫 𝐞(𝟏, 𝟑):

CALLING (descending — nothing computed yet):
e(1,3) → e(1,2) → e(1,1) → e(1,0) = 1

RETURNING (ascending — terms added):
e(1,0) = 1
e(1,1) = 1 + (p=1*1)/(f=1*1) = 1 + 1/1  = 2
e(1,2) = 2 + (p=1*1)/(f=2*2) = 2 + 1/2  = 2.5
e(1,3) = 2.5 + (p=1*1)/(f=1*3)= 2.5+1/6 = 2.666...

// 𝐖𝐡𝐲 𝐬𝐭𝐚𝐭𝐢𝐜 𝐯𝐚𝐫𝐢𝐚𝐛𝐥𝐞𝐬 𝐚𝐫𝐞 𝐮𝐬𝐞𝐝:

p and f must PERSIST across returning calls
— they accumulate x^n and n! progressively
— normal local variables would reset each call
