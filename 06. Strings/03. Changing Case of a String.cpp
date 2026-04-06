#include <stdio.h>

int main() {

    // ============ UPPERCASE TO LOWERCASE ============
    // Add 32 to convert uppercase to lowercase

    char a[] = "WELCOME";
    printf("Original:   %s\n", a);

    for (int i = 0; a[i] != '\0'; i++) {
        a[i] = a[i] + 32;   // add 32 to get lowercase
    }
    printf("Lowercase:  %s\n", a);   // Output: welcome


    // ============ LOWERCASE TO UPPERCASE ============
    // Subtract 32 to convert lowercase to uppercase

    char b[] = "welcome";
    printf("\nOriginal:   %s\n", b);

    for (int i = 0; b[i] != '\0'; i++) {
        b[i] = b[i] - 32;   // subtract 32 to get uppercase
    }
    printf("Uppercase:  %s\n", b);   // Output: WELCOME


    // ============ TOGGLE CASE ============
    // Uppercase → lowercase, lowercase → uppercase

    char c[] = "wElComE";
    printf("\nOriginal:   %s\n", c);

    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] >= 65 && c[i] <= 90)        // uppercase A-Z
            c[i] += 32;                        // convert to lowercase
        else if (c[i] >= 97 && c[i] <= 122)   // lowercase a-z
            c[i] -= 32;                        // convert to uppercase
        // other symbols (digits, spaces) unchanged
    }
    printf("Toggled:    %s\n", c);   // Output: WeLcOMe


    // ============ ASCII CODE REFERENCE ============
    printf("\nASCII reference:\n");
    printf("'A' = %d, 'Z' = %d\n", 'A', 'Z');   // 65, 90
    printf("'a' = %d, 'z' = %d\n", 'a', 'z');   // 97, 122
    printf("Difference = %d\n", 'a' - 'A');       // 32

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

Original:   WELCOME
Lowercase:  welcome

Original:   welcome
Uppercase:  WELCOME

Original:   wElComE
Toggled:    WeLcOMe

ASCII reference:
'A' = 65, 'Z' = 90
'a' = 97, 'z' = 122
Difference = 32

// 𝐀𝐒𝐂𝐈𝐈 𝐫𝐞𝐥𝐚𝐭𝐢𝐨𝐧𝐬𝐡𝐢𝐩 𝐛𝐞𝐭𝐰𝐞𝐞𝐧 𝐜𝐚𝐬𝐞𝐬:

Uppercase: A=65  B=66  C=67 ... Z=90
                  +32  +32  +32
Lowercase: a=97  b=98  c=99 ... z=122

Difference is always 32
uppercase + 32 = lowercase
lowercase - 32 = uppercase

//  𝐓𝐨𝐠𝐠𝐥𝐞 𝐜𝐚𝐬𝐞 𝐥𝐨𝐠𝐢𝐜:

Character    Range       Action
---------    ---------   ------
A-Z (65-90)  uppercase → add 32    → becomes a-z
a-z (97-122) lowercase → subtract 32 → becomes A-Z
Others       digits,    → unchanged
             spaces,
             symbols

//  𝐔𝐬𝐢𝐧𝐠 𝐜𝐡𝐚𝐫𝐚𝐜𝐭𝐞𝐫 𝐥𝐢𝐭𝐞𝐫𝐚𝐥𝐬 𝐢𝐧𝐬𝐭𝐞𝐚𝐝 𝐨𝐟 𝐧𝐮𝐦𝐛𝐞𝐫𝐬:

// These are equivalent:
if (c[i] >= 65  && c[i] <= 90)   // using numbers
if (c[i] >= 'A' && c[i] <= 'Z')  // using char literals (cleaner)

if (c[i] >= 97  && c[i] <= 122)
if (c[i] >= 'a' && c[i] <= 'z')  // more readable
