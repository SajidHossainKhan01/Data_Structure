#include <stdio.h>

// Taylor Series for e^x — ITERATIVE version
double e(double x, int n) {
    double s = 1;           // result, starts at 1 (first term)
    double numerator = 1;   // tracks x^i
    double denominator = 1; // tracks i! (factorial)

    for (int i = 1; i <= n; i++) {
        numerator   = numerator * x;    // x^i
        denominator = denominator * i;  // i!
        s = s + numerator / denominator; // add term x^i / i!
    }

    return s;
}

int main() {
    printf("%lf\n", e(1, 10));   // Output: 2.718282  (e^1)
    printf("%lf\n", e(2, 10));   // Output: 7.388879  (e^2)
    printf("%lf\n", e(3, 10));   // Output: 20.079665 (e^3)

    return 0;
}

// 𝐇𝐨𝐰 𝐞𝐚𝐜𝐡 𝐭𝐞𝐫𝐦 𝐢𝐬 𝐛𝐮𝐢𝐥𝐭 (𝐱=𝟏, 𝐧=𝟓):

i=0: s = 1                          (starting value)
i=1: num=1,  den=1,  term=1/1  = 1      → s = 2
i=2: num=1,  den=2,  term=1/2  = 0.5    → s = 2.5
i=3: num=1,  den=6,  term=1/6  = 0.166  → s = 2.666
i=4: num=1,  den=24, term=1/24 = 0.041  → s = 2.708
i=5: num=1,  den=120,term=1/120= 0.008  → s = 2.716
...
i=10: → s = 2.718282 ✓

