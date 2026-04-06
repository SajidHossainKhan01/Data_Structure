#include <stdio.h>

int main() {

    char a[] = "How are you";

    int vCount = 0;    // vowel counter
    int cCount = 0;    // consonant counter
    int words  = 1;    // word counter (start at 1)

    for (int i = 0; a[i] != '\0'; i++) {

        // ============ COUNT VOWELS ============
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' ||
            a[i] == 'o' || a[i] == 'u' ||
            a[i] == 'A' || a[i] == 'E' || a[i] == 'I' ||
            a[i] == 'O' || a[i] == 'U') {
            vCount++;
        }

        // ============ COUNT CONSONANTS ============
        else if ((a[i] >= 65 && a[i] <= 90) ||   // uppercase A-Z
                 (a[i] >= 97 && a[i] <= 122)) {   // lowercase a-z
            cCount++;   // not a vowel but is alphabet = consonant
        }

        // ============ COUNT WORDS ============
        // count spaces, but not multiple consecutive spaces
        if (a[i] == ' ' && a[i - 1] != ' ') {
            words++;
        }
    }

    printf("String:     %s\n", a);
    printf("Vowels:     %d\n", vCount);     // Output: 5
    printf("Consonants: %d\n", cCount);     // Output: 5
    printf("Words:      %d\n", words);      // Output: 3

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

String:     How are you
Vowels:     5
Consonants: 5
Words:      3

// 𝐕𝐨𝐰𝐞𝐥 𝐜𝐨𝐮𝐧𝐭𝐢𝐧𝐠 𝐭𝐫𝐚𝐜𝐞 𝐟𝐨𝐫 "𝐇𝐨𝐰 𝐚𝐫𝐞 𝐲𝐨𝐮":

H - consonant
o - VOWEL     vCount=1
w - consonant
  - space
a - VOWEL     vCount=2
r - consonant
e - VOWEL     vCount=3
  - space
y - consonant
o - VOWEL     vCount=4
u - VOWEL     vCount=5

Total vowels = 5 ✓ (o, a, e, o, u)

// 𝐖𝐨𝐫𝐝 𝐜𝐨𝐮𝐧𝐭𝐢𝐧𝐠 — 𝐡𝐚𝐧𝐝𝐥𝐢𝐧𝐠 𝐦𝐮𝐥𝐭𝐢𝐩𝐥𝐞 𝐬𝐩𝐚𝐜𝐞𝐬:

Normal:   "How are you"    → 2 spaces → words = 3 ✓
Problem:  "How  are  you"  → 4 spaces → naive count = 5 ✗

Fix: only count space if previous char is NOT a space
     a[i]==' ' && a[i-1]!=' '

"How  are  you":
i=3: ' ', prev='w' (not space) → words++ = 2
i=4: ' ', prev=' ' (space!)    → skip
i=8: ' ', prev='e' (not space) → words++ = 3
i=9: ' ', prev=' ' (space!)    → skip
Result: 3 words ✓