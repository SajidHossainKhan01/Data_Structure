// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟏: 𝐂𝐨𝐦𝐩𝐚𝐫𝐢𝐧𝐠 𝐄𝐚𝐜𝐡 𝐂𝐡𝐚𝐫𝐚𝐜𝐭𝐞𝐫 𝐰𝐢𝐭𝐡 𝐑𝐞𝐬𝐭 — 𝐎(𝐧²)

#include <stdio.h>

int main() {
    char a[] = "finding";
    int i, j;

    for (i = 0; a[i] != '\0'; i++) {
        if (a[i] != '\0') {          // skip already marked
            for (j = i + 1; a[j] != '\0'; j++) {
                if (a[i] == a[j]) {
                    printf("%c is duplicate\n", a[i]);
                    a[j] = '\0';     // mark as visited
                }
            }
        }
    }

    return 0;
}

// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟐: 𝐔𝐬𝐢𝐧𝐠 𝐇𝐚𝐬𝐡 𝐓𝐚𝐛𝐥𝐞 (𝐂𝐨𝐮𝐧𝐭𝐢𝐧𝐠) — 𝐎(𝐧)

#include <stdio.h>

int main() {
    char a[] = "finding";
    int h[26] = {0};     // hash table, initialized to 0
    int i;

    // Step 1: Count occurrences of each alphabet
    for (i = 0; a[i] != '\0'; i++) {
        h[a[i] - 97]++;  // subtract 97 to get index (a=0, b=1, ... z=25)
    }

    // Step 2: Print alphabets appearing more than once
    for (i = 0; i < 26; i++) {
        if (h[i] > 1) {
            printf("%c appears %d times\n", i + 97, h[i]);
        }
    }

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

i appears 2 times
n appears 2 times
