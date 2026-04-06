// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟏: 𝐑𝐞𝐯𝐞𝐫𝐬𝐞 𝐂𝐨𝐩𝐲 𝐢𝐧𝐭𝐨 𝐀𝐧𝐨𝐭𝐡𝐞𝐫 𝐀𝐫𝐫𝐚𝐲

#include <stdio.h>

int main() {
    char a[] = "python";
    char b[10];
    int i, j;

    // Step 1: Move i to the end (null character)
    for (i = 0; a[i] != '\0'; i++);

    // Step 2: Start from last character
    i = i - 1;

    // Step 3: Copy in reverse into array b
    for (j = 0; i >= 0; i--, j++) {
        b[j] = a[i];
    }

    // Step 4: Add null terminator
    b[j] = '\0';

    printf("%s", b);  // Output: nohtyp

    return 0;
}

// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟐: 𝐑𝐞𝐯𝐞𝐫𝐬𝐞 𝐈𝐧-𝐏𝐥𝐚𝐜𝐞 (𝐒𝐰𝐚𝐩 𝐂𝐡𝐚𝐫𝐚𝐜𝐭𝐞𝐫𝐬)

#include <stdio.h>

int main() {
    char a[] = "python";
    int i, j;
    char t;

    // Step 1: Move j to null character
    for (j = 0; a[j] != '\0'; j++);

    // Step 2: Move j to last character
    j = j - 1;

    // Step 3: Swap characters from both ends moving inward
    for (i = 0; i < j; i++, j--) {
        t    = a[i];   // swap
        a[i] = a[j];
        a[j] = t;
    }

    printf("%s", a);  // Output: nohtyp

    return 0;
}
