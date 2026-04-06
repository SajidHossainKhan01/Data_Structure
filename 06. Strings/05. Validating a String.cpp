#include <stdio.h>

// VALIDATE — checks if string contains only alphabets and digits
// Returns 1 (valid) or 0 (invalid)
int validate(char *name) {
    int i;
    for (i = 0; name[i] != '\0'; i++) {

        // Check if character is NOT in any valid range
        if (!(name[i] >= 65  && name[i] <= 90)  &&   // NOT uppercase A-Z
            !(name[i] >= 97  && name[i] <= 122) &&   // NOT lowercase a-z
            !(name[i] >= 48  && name[i] <= 57)) {     // NOT digit 0-9

            return 0;   // invalid character found
        }
    }
    return 1;           // all characters valid
}

int main() {

    // Valid string — only alphabets and digits
    char name1[] = "Hello123";
    if (validate(name1))
        printf("'%s' is a VALID string\n", name1);   // Output: VALID
    else
        printf("'%s' is an INVALID string\n", name1);

    // Invalid string — contains special character
    char name2[] = "Hello?123";
    if (validate(name2))
        printf("'%s' is a VALID string\n", name2);
    else
        printf("'%s' is an INVALID string\n", name2);  // Output: INVALID

    // More test cases
    char name3[] = "AbCdEf";
    if (validate(name3))
        printf("'%s' is a VALID string\n", name3);   // Output: VALID
    else
        printf("'%s' is an INVALID string\n", name3);

    char name4[] = "Hello World";   // space is invalid
    if (validate(name4))
        printf("'%s' is a VALID string\n", name4);
    else
        printf("'%s' is an INVALID string\n", name4);  // Output: INVALID

    char name5[] = "Pass@word1";    // @ is invalid
    if (validate(name5))
        printf("'%s' is a VALID string\n", name5);
    else
        printf("'%s' is an INVALID string\n", name5);  // Output: INVALID

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

'Hello123'    is a VALID string
'Hello?123'   is an INVALID string
'AbCdEf'      is a VALID string
'Hello World' is an INVALID string
'Pass@word1'  is an INVALID string

// 𝐕𝐚𝐥𝐢𝐝 𝐜𝐡𝐚𝐫𝐚𝐜𝐭𝐞𝐫 𝐫𝐚𝐧𝐠𝐞𝐬:

Uppercase A-Z: ASCII 65  to 90
Lowercase a-z: ASCII 97  to 122
Digits 0-9:    ASCII 48  to 57

Everything else = INVALID (spaces, ?, @, #, !, etc.)

// 𝐇𝐨𝐰 𝐯𝐚𝐥𝐢𝐝𝐚𝐭𝐢𝐨𝐧 𝐰𝐨𝐫𝐤𝐬 — 𝐭𝐫𝐚𝐜𝐞 𝐟𝐨𝐫 "𝐇𝐞𝐥𝐥𝐨?𝟏𝟐𝟑":

H - 72,  in A-Z (65-90)   ✓
e - 101, in a-z (97-122)  ✓
l - 108, in a-z           ✓
l - 108, in a-z           ✓
o - 111, in a-z           ✓
? - 63,  NOT in any range ✗ → return 0 (INVALID)
(stop — no need to check rest)

// 𝐋𝐨𝐠𝐢𝐜 𝐨𝐟 𝐭𝐡𝐞 𝐜𝐨𝐧𝐝𝐢𝐭𝐢𝐨𝐧 𝐞𝐱𝐩𝐥𝐚𝐢𝐧𝐞𝐝:

// Character is INVALID if it is:
if (
    !(in uppercase range) &&    // NOT A-Z
    !(in lowercase range) &&    // NOT a-z
    !(in digit range)           // NOT 0-9
)
    return 0;   // invalid

// ALL three must be false for it to be invalid
// If ANY range matches → valid character → continue

// 𝐔𝐬𝐢𝐧𝐠 𝐜𝐡𝐚𝐫𝐚𝐜𝐭𝐞𝐫 𝐥𝐢𝐭𝐞𝐫𝐚𝐥𝐬 (𝐦𝐨𝐫𝐞 𝐫𝐞𝐚𝐝𝐚𝐛𝐥𝐞):

// Equivalent, cleaner version:
if (!(name[i] >= 'A' && name[i] <= 'Z') &&
    !(name[i] >= 'a' && name[i] <= 'z') &&
    !(name[i] >= '0' && name[i] <= '9'))
    return 0;




