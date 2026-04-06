// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟏: 𝐔𝐬𝐢𝐧𝐠 𝐅𝐥𝐚𝐠 𝐀𝐫𝐫𝐚𝐲 (𝐁𝐚𝐜𝐤𝐭𝐫𝐚𝐜𝐤𝐢𝐧𝐠)

#include <stdio.h>

void perm(char *s, int k) {
    static int a[10] = {0};      // flag array — 0=available, 1=taken
    static char result[10];      // stores current permutation
    int i;

    if (s[k] == '\0') {
        // Base case: reached end — print result
        result[k] = '\0';
        printf("%s\n", result);
    } else {
        // Scan through entire string
        for (i = 0; s[i] != '\0'; i++) {
            if (a[i] == 0) {             // if alphabet is available
                result[k] = s[i];        // copy alphabet to result
                a[i] = 1;               // mark as taken
                perm(s, k + 1);         // recursive call for next position
                a[i] = 0;               // unmark (backtrack)
            }
        }
    }
}

int main() {
    char s[] = "abc";
    perm(s, 0);
    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

abc
acb
bac
bca
cab
cba

// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟐: 𝐔𝐬𝐢𝐧𝐠 𝐒𝐰𝐚𝐩𝐩𝐢𝐧𝐠 (𝐍𝐨 𝐄𝐱𝐭𝐫𝐚 𝐀𝐫𝐫𝐚𝐲)

#include <stdio.h>

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void pm(char *s, int low, int high) {
    int i;

    if (low == high) {
        // Base case: print the permutation
        printf("%s\n", s);
    } else {
        // Scan from low to high
        for (i = low; i <= high; i++) {
            swap(&s[low], &s[i]);    // swap to bring each letter to front
            pm(s, low + 1, high);   // recursive call for next position
            swap(&s[low], &s[i]);   // swap back (backtrack)
        }
    }
}

int main() {
    char s[] = "abc";
    int n = 0;
    while (s[n] != '\0') n++;       // find length
    pm(s, 0, n - 1);
    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

abc
acb
bac
bca
cba
cab