#include <stdio.h>

// TOWER OF HANOI
void TOH(int n, int a, int b, int c) {
    if (n > 0) {
        TOH(n - 1, a, c, b);        // move n-1 disks from A to B using C
        printf("(%d, %d)\n", a, c); // move nth disk from A to C
        TOH(n - 1, b, a, c);        // move n-1 disks from B to C using A
    }
}

int main() {
    // 1 disk
    TOH(1, 1, 2, 3);
    printf("\n");

    // 2 disks
    TOH(2, 1, 2, 3);
    printf("\n");

    // 3 disks
    TOH(3, 1, 2, 3);
    printf("\n");

    // 4 disks
    TOH(4, 1, 2, 3);

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭 𝐟𝐨𝐫 𝐓𝐎𝐇(𝟑, 𝟏, 𝟐, 𝟑):

(1, 3)
(1, 2)
(3, 2)
(1, 3)
(2, 1)
(2, 3)
(1, 3)

// 𝐇𝐨𝐰 𝐢𝐭 𝐰𝐨𝐫𝐤𝐬 𝐟𝐨𝐫 𝟑 𝐝𝐢𝐬𝐤𝐬 (𝐀=𝟏, 𝐁=𝟐, 𝐂=𝟑):

Step 1: Move disk 1 → Tower 1 to Tower 3
Step 2: Move disk 2 → Tower 1 to Tower 2
Step 3: Move disk 1 → Tower 3 to Tower 2
Step 4: Move disk 3 → Tower 1 to Tower 3  ← biggest disk
Step 5: Move disk 1 → Tower 2 to Tower 1
Step 6: Move disk 2 → Tower 2 to Tower 3
Step 7: Move disk 1 → Tower 1 to Tower 3

// 𝐑𝐞𝐜𝐮𝐫𝐬𝐢𝐨𝐧 𝐓𝐫𝐞𝐞 𝐟𝐨𝐫 𝐓𝐎𝐇(𝟑):

TOH(3, A→C)
           /            \
     TOH(2, A→B)      TOH(2, B→C)
      /       \         /        \
 TOH(1,A→C) TOH(1,B→A) TOH(1,B→A) TOH(1,A→C)