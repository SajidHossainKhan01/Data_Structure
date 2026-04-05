#include <stdio.h>

// Taylor Series for e^x using Horner's Rule
// e^x = 1 + x/1! + x²/2! + ... 
// Horner's form: 1 + x/1(1 + x/2(1 + x/3(...)))
double e(double x, int n) {
    static double s = 1;

    if (n == 0)
        return s;

    s = 1 + x * s / n;         // Horner's rule — update at calling time
    return e(x, n - 1);        // tail recursion
}

int main() {
    printf("%lf\n", e(1, 10));   // Output: 2.718282  (e^1)
    printf("%lf\n", e(2, 10));   // Output: 7.388871  (e^2)

    return 0;
}

// 𝐇𝐨𝐰 𝐇𝐨𝐫𝐧𝐞𝐫'𝐬 𝐑𝐮𝐥𝐞 𝐰𝐨𝐫𝐤𝐬:

Normal Taylor:  1 + x/1! + x²/2! + x³/3! + ...

Horner's form:  1 + x/1(1 + x/2(1 + x/3(1 + x/4(...))))

// 𝐓𝐫𝐚𝐜𝐢𝐧𝐠 𝐞(𝟏, 𝟑):

CALLING (s updated each call):
s = 1
e(1,3): s = 1 + 1*1/3 = 1.333...  → calls e(1,2)
e(1,2): s = 1 + 1*1.333/2 = 1.666 → calls e(1,1)
e(1,1): s = 1 + 1*1.666/1 = 2.666 → calls e(1,0)
e(1,0): n==0 → return s = 2.666 ✓