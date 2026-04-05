#include <stdio.h>

int main() {

    // 3D array — dimensions L=2, M=3, N=4
    int a[2][3][4];

    // Fill with some values
    int val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 4; k++)
                a[i][j][k] = val++;

    // Access specific element
    printf("a[1][2][3] = %d\n", a[1][2][3]);

    // Print base address and element address
    printf("Base address L0      = %u\n", &a[0][0][0]);
    printf("Address of a[1][2][3]= %u\n", &a[1][2][3]);
    printf("Word size W          = %lu bytes\n", sizeof(int));

    // Print all elements with addresses
    printf("\nAll elements:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 4; k++)
                printf("a[%d][%d][%d] = %2d  address = %u\n",
                        i, j, k, a[i][j][k], &a[i][j][k]);

    return 0;
}

// 𝐑𝐨𝐰 𝐌𝐚𝐣𝐨𝐫 𝐅𝐨𝐫𝐦𝐮𝐥𝐚 — 𝟑𝐃 𝐚𝐫𝐫𝐚𝐲 𝐚[𝐋][𝐌][𝐍]:

Address of a[i][j][k] = L0 + (i*M*N + j*N + k) * W

Steps (left to right):
  i → multiply remaining dims → M*N
  j → multiply remaining dims → N
  k → last index, no more dims

// 𝐂𝐨𝐥𝐮𝐦𝐧 𝐌𝐚𝐣𝐨𝐫 𝐅𝐨𝐫𝐦𝐮𝐥𝐚 — 𝟑𝐃 𝐚𝐫𝐫𝐚𝐲 𝐚[𝐋][𝐌][𝐍]:

Address of a[i][j][k] = L0 + (k*L*M + j*L + i) * W

Steps (right to left):
  k → multiply preceding dims → L*M
  j → multiply preceding dims → L
  i → first index, no more dims

// 𝐕𝐞𝐫𝐢𝐟𝐢𝐜𝐚𝐭𝐢𝐨𝐧 𝐰𝐢𝐭𝐡 𝐋𝟎=𝟐𝟎𝟎, 𝐋=𝟐, 𝐌=𝟑, 𝐍=𝟒, 𝐖=𝟐:

Row Major a[1][2][3]:
= 200 + (1*3*4 + 2*4 + 3) * 2
= 200 + (12 + 8 + 3) * 2
= 200 + 23*2
= 246

Column Major a[1][2][3]:
= 200 + (3*2*3 + 2*2 + 1) * 2
= 200 + (18 + 4 + 1) * 2
= 200 + 23*2
= 246

// 𝐀𝐩𝐩𝐥𝐲𝐢𝐧𝐠 𝐇𝐨𝐫𝐧𝐞𝐫'𝐬 𝐑𝐮𝐥𝐞 𝐭𝐨 𝐫𝐞𝐝𝐮𝐜𝐞 𝐦𝐮𝐥𝐭𝐢𝐩𝐥𝐢𝐜𝐚𝐭𝐢𝐨𝐧𝐬:

Row Major (original):
i*M*N + j*N + k          → 3 multiplications

Row Major (Horner's Rule):
(i*M + j)*N + k          → 2 multiplications

// 𝟑𝐃 𝐑𝐨𝐰 𝐌𝐚𝐣𝐨𝐫 𝐟𝐨𝐫𝐦𝐮𝐥𝐚 (𝐝𝐞𝐫𝐢𝐯𝐞𝐝 𝐬𝐚𝐦𝐞 𝐰𝐚𝐲):

Address of a[i][j][k] = L0 + (i*D2*D3 + j*D3 + k) * W

With Horner's Rule:
= L0 + (i*D2 + j)*D3 + k) * W