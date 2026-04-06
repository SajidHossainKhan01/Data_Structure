// 𝐂𝐨𝐦𝐩𝐚𝐫𝐢𝐧𝐠 𝐓𝐰𝐨 𝐒𝐭𝐫𝐢𝐧𝐠𝐬

#include <stdio.h>

int main() {
    char a[] = "painter";
    char b[] = "painting";
    int i, j;

    // Compare character by character
    for (i = 0, j = 0; a[i] != '\0' && b[j] != '\0'; i++, j++) {
        if (a[i] != b[j])
            break;  // stop on mismatch
    }

    // Check result
    if (a[i] == b[j])
        printf("Equal");
    else if (a[i] < b[j])
        printf("Smaller");  // first string comes first in dictionary
    else
        printf("Greater");  // first string comes later in dictionary

    return 0;
}

// 𝐏𝐚𝐥𝐢𝐧𝐝𝐫𝐨𝐦𝐞 — 𝐌𝐞𝐭𝐡𝐨𝐝 𝟏: 𝐔𝐬𝐢𝐧𝐠 𝐄𝐱𝐭𝐫𝐚 𝐀𝐫𝐫𝐚𝐲

#include <stdio.h>

int main() {
    char a[] = "madam";
    char b[10];
    int i, j;

    // Step 1: Reach end of string
    for (i = 0; a[i] != '\0'; i++);

    // Step 2: Reverse copy into b
    i = i - 1;
    for (j = 0; i >= 0; i--, j++) {
        b[j] = a[i];
    }
    b[j] = '\0';

    // Step 3: Compare a and b
    for (i = 0, j = 0; a[i] != '\0' && b[j] != '\0'; i++, j++) {
        if (a[i] != b[j])
            break;
    }

    if (a[i] == b[j])
        printf("Palindrome");
    else
        printf("Not a Palindrome");

    return 0;
}

// 𝐏𝐚𝐥𝐢𝐧𝐝𝐫𝐨𝐦𝐞 — 𝐌𝐞𝐭𝐡𝐨𝐝 𝟐: 𝐖𝐢𝐭𝐡𝐨𝐮𝐭 𝐄𝐱𝐭𝐫𝐚 𝐀𝐫𝐫𝐚𝐲 (𝐒𝐭𝐮𝐝𝐞𝐧𝐭 𝐂𝐡𝐚𝐥𝐥𝐞𝐧𝐠𝐞)

#include <stdio.h>

int main() {
    char a[] = "madam";
    int i, j;

    // Step 1: Move j to last character
    for (j = 0; a[j] != '\0'; j++);
    j = j - 1;

    // Step 2: Compare from both ends moving inward
    for (i = 0; i < j; i++, j--) {
        if (a[i] != a[j])
            break;
    }

    if (i >= j)
        printf("Palindrome");
    else
        printf("Not a Palindrome");

    return 0;
}
