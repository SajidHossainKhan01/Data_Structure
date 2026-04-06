// 𝐁𝐢𝐭𝐰𝐢𝐬𝐞 𝐂𝐨𝐧𝐜𝐞𝐩𝐭𝐬 𝐔𝐬𝐞𝐝

// Left Shift
h = 1 << 5;   // moves 1 five places left → 32 (bit 5 is ON)

// Masking (checking if a bit is ON)
if (x & h)    // non-zero = bit is ON, zero = bit is OFF

// Merging (setting a bit ON)
h = x | h;    // sets the bit ON in h

// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟑: 𝐅𝐢𝐧𝐝𝐢𝐧𝐠 𝐃𝐮𝐩𝐥𝐢𝐜𝐚𝐭𝐞𝐬 𝐔𝐬𝐢𝐧𝐠 𝐁𝐢𝐭𝐬 — 𝐎(𝐧)

#include <stdio.h>

int main() {
    char a[] = "finding";
    long int h = 0;    // 4 bytes = 32 bits, all initialized to 0
    long int x;
    int i;

    for (i = 0; a[i] != '\0'; i++) {

        // Step 1: Set x = 1, then shift left by (a[i] - 97) places
        x = 1;
        x = x << (a[i] - 97);   // brings the bit to correct position

        // Step 2: Masking — check if that bit is already ON in h
        if (x & h) {
            printf("%c is duplicate\n", a[i]);  // bit already ON = duplicate
        } else {
            // Step 3: Merging — set that bit ON in h
            h = x | h;
        }
    }

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

i is duplicate
n is duplicate
