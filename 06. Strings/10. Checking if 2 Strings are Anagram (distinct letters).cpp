// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟏: 𝐋𝐢𝐧𝐞𝐚𝐫 𝐒𝐞𝐚𝐫𝐜𝐡 — 𝐎(𝐧²)

(Take each letter from string A and search in string B)
No code written — refer to linear search logic. Time is O(n²).

// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟐: 𝐔𝐬𝐢𝐧𝐠 𝐇𝐚𝐬𝐡 𝐓𝐚𝐛𝐥𝐞 — 𝐎(𝐧)

#include <stdio.h>

int main() {
    char a[] = "decimal";
    char b[] = "medical";
    int h[26] = {0};    // hash table initialized to 0
    int i;

    // Step 1: Scan first string — increment count
    for (i = 0; a[i] != '\0'; i++) {
        h[a[i] - 97]++;
    }

    // Step 2: Scan second string — decrement count
    for (i = 0; b[i] != '\0'; i++) {
        h[b[i] - 97]--;

        // If count goes below 0 — letter not in first string
        if (h[b[i] - 97] < 0) {
            printf("Not Anagram\n");
            break;
        }
    }

    // Step 3: If we reached end of second string — anagram confirmed
    if (b[i] == '\0') {
        printf("Anagram\n");
    }

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

Anagram
