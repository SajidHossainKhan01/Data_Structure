#include <stdio.h>

int main() {

    // ============ CHARACTER VARIABLE ============
    char temp = 'A';
    printf("%c\n", temp);   // Output: A (prints character)
    printf("%d\n", temp);   // Output: 65 (prints ASCII code)


    // ============ CHARACTER ARRAY (not a string) ============

    // Method 1 — with size and initialization
    char x[5] = {'a', 'b', 'c', 'd', 'e'};

    // Method 2 — without size (auto size = 5)
    char y[] = {'a', 'b', 'c', 'd', 'e'};

    // Method 3 — using ASCII codes directly
    char z[5] = {65, 66, 67, 68, 69};   // same as A B C D E

    // Method 4 — partial initialization (rest = 0)
    char w[5] = {'a', 'b'};   // w = {a, b, 0, 0, 0}


    // ============ STRING (character array + \0) ============

    // Method 1 — with size and \0 explicitly
    char name1[10] = {'J', 'o', 'h', 'n', '\0'};

    // Method 2 — without size (\0 auto included, size = 5)
    char name2[] = {'J', 'o', 'h', 'n', '\0'};

    // Method 3 — double quotes (best way, \0 auto added)
    char name3[10] = "John";

    // Print string
    printf("%s\n", name3);   // Output: John


    // ============ ASCII CODE EXPLORATION ============
    printf("\nASCII codes:\n");
    printf("A = %d\n", 'A');   // Output: 65
    printf("Z = %d\n", 'Z');   // Output: 90
    printf("a = %d\n", 'a');   // Output: 97
    printf("z = %d\n", 'z');   // Output: 122
    printf("0 = %d\n", '0');   // Output: 48
    printf("9 = %d\n", '9');   // Output: 57


    // ============ READING STRINGS ============

    char input[20];

    // scanf — reads single word only
    printf("\nEnter a name (single word): ");
    scanf("%s", input);
    printf("You entered: %s\n", input);

    // gets — reads entire line including spaces
    // gets(input);   // reads until Enter key
    // printf("%s\n", input);


    // ============ MEMORY LAYOUT ============
    // name3[10] = "John"
    // Index:  0    1    2    3    4    5...9
    // Value: 'J'  'o'  'h'  'n'  '\0'  0...0
    //         74  111  104  110    0    0...0

    printf("\nCharacters in name3:\n");
    for (int i = 0; name3[i] != '\0'; i++)
        printf("name3[%d] = %c (ASCII: %d)\n",
                i, name3[i], name3[i]);

    return 0;
}

// 𝐀𝐒𝐂𝐈𝐈 𝐂𝐨𝐝𝐞 𝐓𝐚𝐛𝐥𝐞 (𝐢𝐦𝐩𝐨𝐫𝐭𝐚𝐧𝐭 𝐨𝐧𝐞𝐬):

Uppercase A-Z:  65 to 90
Lowercase a-z:  97 to 122
Digits 0-9:     48 to 57
Space:          32
Enter (\n):     10
Escape:         27
Null (\0):       0

// 𝐂𝐡𝐚𝐫𝐚𝐜𝐭𝐞𝐫 𝐚𝐫𝐫𝐚𝐲 𝐯𝐬 𝐒𝐭𝐫𝐢𝐧𝐠:

Character array (no \0):
char x[] = {'J','o','h','n'};
[J][o][h][n]  ← no terminator, NOT a string

String (with \0):
char name[] = {'J','o','h','n','\0'};
[J][o][h][n][\0]  ← IS a string

// 𝐓𝐡𝐫𝐞𝐞 𝐰𝐚𝐲𝐬 𝐭𝐨 𝐝𝐞𝐜𝐥𝐚𝐫𝐞 𝐬𝐭𝐫𝐢𝐧𝐠𝐬:

char name[10] = {'J','o','h','n','\0'};  // explicit \0
char name[]   = {'J','o','h','n','\0'};  // auto size = 5
char name[10] = "John";                   // best — \0 auto added