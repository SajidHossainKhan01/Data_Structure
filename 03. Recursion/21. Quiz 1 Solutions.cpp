#include <stdio.h>

// QUESTION 1 — Static variable in recursion
int f1(int n) {
    static int i = 1;
    if (n >= 5)
        return n;
    n = n + i;
    i++;
    return f1(n);
}

// QUESTION 2 — Digit sum (call by value)
void f2(int n, int sum) {
    if (n == 0)
        return;
    int k = n % 10;
    int j = n / 10;
    sum   = sum + k;
    f2(j, sum);
    printf("%d", k);   // prints at RETURNING time
}

// QUESTION 3 — Call by reference vs call by value (C++)
// int f3(int &x, int c) {
//     c = c - 1;
//     if (c == 0) return 1;
//     x = x + 1;
//     return f3(x, c) * x;
// }

// QUESTION 4 — Complex tree recursion
int f4(int n) {
    int x = 1;
    if (n == 1)
        return x;
    for (int k = 1; k < n; k++)
        x = x + f4(k) * f4(n - k);
    return x;
}

// QUESTION 5 — Static variable with printing
void count(int n) {
    static int d = 1;
    printf("%d", n);    // print n at calling time
    printf("%d", d);    // print d at calling time
    d++;
    if (n > 1)
        count(n - 1);
    printf("%d", d);    // print d at RETURNING time
}

int main() {
    // Q1
    printf("Q1: %d\n", f1(1));       // Output: 7

    // Q2
    int sum = 0;
    f2(2048, sum);
    printf("\nsum = %d\n", sum);     // Output: 8 4 0 2, sum = 0

    // Q3 (C++ only)
    // int p = 5;
    // printf("Q3: %d\n", f3(p, p)); // Output: 6561 (9^4)

    // Q4
    printf("Q4: %d\n", f4(5));       // Output: 51

    // Q5
    count(3);                         // Output: 3 1 2 2 1 3 4 4 4
    printf("\n");

    return 0;
}

// 𝐐𝟏 𝐓𝐫𝐚𝐜𝐞 — 𝐟𝟏(𝟏) 𝐰𝐢𝐭𝐡 𝐬𝐭𝐚𝐭𝐢𝐜 𝐢:

i=1: n=1+1=2,  i→2, call f1(2)
i=2: n=2+2=4,  i→3, call f1(4)
i=3: n=4+3=7,  i→4, call f1(7)
7 >= 5 → return 7 ✓

// 𝐐𝟐 𝐓𝐫𝐚𝐜𝐞 — 𝐟𝟐(𝟐𝟎𝟒𝟖, 𝟎):

CALLING:              RETURNING (prints k):
k=8, sum=8  →        prints 8
k=4, sum=12 →        prints 4
k=0, sum=12 →        prints 0
k=2, sum=14 →        prints 2
n=0  → stop

Output: 8 4 0 2    main sum = 0 (call by value, unchanged)

// 𝐐𝟒 — 𝐁𝐮𝐢𝐥𝐝𝐢𝐧𝐠 𝐭𝐚𝐛𝐥𝐞 𝐟𝐨𝐫 𝐟𝟒(𝐧):

f4(1) = 1
f4(2) = 1 + f4(1)*f4(1)           = 1+1       = 2
f4(3) = 1 + f4(1)*f4(2)
          + f4(2)*f4(1)            = 1+2+2     = 5
f4(4) = 1 + f4(1)*f4(3)
          + f4(2)*f4(2)
          + f4(3)*f4(1)            = 1+5+4+5   = 15
f4(5) = 1 + f4(1)*f4(4)
          + f4(2)*f4(3)
          + f4(3)*f4(2)
          + f4(4)*f4(1)            = 1+15+10+10+15 = 51 ✓

// 𝐐𝟓 𝐓𝐫𝐚𝐜𝐞 — 𝐜𝐨𝐮𝐧𝐭(𝟑) 𝐰𝐢𝐭𝐡 𝐬𝐭𝐚𝐭𝐢𝐜 𝐝:

CALLING:          RETURNING:
n=3, d=1 → 3,1   
d→2               
n=2, d=2 → 2,2   
d→3               
n=1, d=3 → 1,3   
d→4               (n==1, no more calls)
                         prints d=4
                  	 prints d=4
                        prints d=4

Output: 3 1 2 2 1 3 4 4 4
