#include <stdio.h>

// Function to find length of string
int stringLength(char s[]) {
    int i = 0;
    for (i = 0; s[i] != '\0'; i++) {
        // just increment i until \0 is found
    }
    return i;
}

int main() {

    // String declaration
    char s[] = "welcome";
    // Memory: [w][e][l][c][o][m][e][\0]
    //          0  1  2  3  4  5  6   7

    // METHOD 1 — using for loop
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        // empty body — just counting
    }
    printf("Length (method 1): %d\n", i);   // Output: 7

    // METHOD 2 — using function
    printf("Length (method 2): %d\n", stringLength(s));  // Output: 7

    // METHOD 3 — using while loop
    int j = 0;
    while (s[j] != '\0')
        j++;
    printf("Length (method 3): %d\n", j);   // Output: 7

    // METHOD 4 — using library function strlen
    // #include <string.h>
    // printf("Length (strlen): %d\n", strlen(s));

    // Verify with different strings
    char s2[] = "Hello World";
    printf("Length of '%s': %d\n", s2, stringLength(s2));  // Output: 11

    char s3[] = "";   // empty string
    printf("Length of empty string: %d\n", stringLength(s3));  // Output: 0

    return 0;
}

// 𝐇𝐨𝐰 𝐢𝐭 𝐰𝐨𝐫𝐤𝐬 — 𝐬𝐜𝐚𝐧𝐧𝐢𝐧𝐠 𝐮𝐧𝐭𝐢𝐥 \𝟎:

s = "welcome"

Index:  0    1    2    3    4    5    6    7
Char:  'w'  'e'  'l'  'c'  'o'  'm'  'e'  '\0'

i=0: s[0]='w' ≠ '\0' → i++
i=1: s[1]='e' ≠ '\0' → i++
i=2: s[2]='l' ≠ '\0' → i++
i=3: s[3]='c' ≠ '\0' → i++
i=4: s[4]='o' ≠ '\0' → i++
i=5: s[5]='m' ≠ '\0' → i++
i=6: s[6]='e' ≠ '\0' → i++
i=7: s[7]='\0' → STOP

Length = i = 7 ✓

// 𝐖𝐡𝐲 𝐧𝐨𝐭 𝐮𝐬𝐞 𝐚𝐫𝐫𝐚𝐲 𝐬𝐢𝐳𝐞 𝐝𝐢𝐫𝐞𝐜𝐭𝐥𝐲?

char s[20] = "welcome";
// Array size = 20
// String length = 7
// We can't use size 20 as length!
// \0 tells us where the string actually ends