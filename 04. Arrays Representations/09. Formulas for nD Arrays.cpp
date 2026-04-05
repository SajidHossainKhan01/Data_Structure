#include <stdio.h>

int main() {

    // 4D array example — dimensions D1=2, D2=3, D3=4, D4=5
    int a[2][3][4][5];

    // Printing address of an element to verify formula
    printf("Base address L0:        %u\n", &a[0][0][0][0]);
    printf("Address of a[1][2][3][4]: %u\n", &a[1][2][3][4]);
    printf("Word size W = %lu bytes\n", sizeof(int));

    // 3D array example — dimensions D1=2, D2=3, D3=4
    int b[2][3][4];
    printf("\n3D Base address L0:       %u\n", &b[0][0][0]);
    printf("Address of b[1][2][3]:    %u\n", &b[1][2][3]);

    return 0;
}

// 𝐑𝐨𝐰 𝐌𝐚𝐣𝐨𝐫 𝐅𝐨𝐫𝐦𝐮𝐥𝐚 — 𝟒𝐃 𝐚𝐫𝐫𝐚𝐲 𝐚[𝐃𝟏][𝐃𝟐][𝐃𝟑][𝐃𝟒]:

Address of a[i1][i2][i3][i4] =
L0 + (i1*D2*D3*D4 + i2*D3*D4 + i3*D4 + i4) * W

// 𝐂𝐨𝐥𝐮𝐦𝐧 𝐌𝐚𝐣𝐨𝐫 𝐅𝐨𝐫𝐦𝐮𝐥𝐚 — 𝟒𝐃 𝐚𝐫𝐫𝐚𝐲:

Address of a[i1][i2][i3][i4] =
L0 + (i4*D1*D2*D3 + i3*D1*D2 + i2*D1 + i1) * W

// 𝐆𝐞𝐧𝐞𝐫𝐚𝐥 𝐑𝐨𝐰 𝐌𝐚𝐣𝐨𝐫 𝐅𝐨𝐫𝐦𝐮𝐥𝐚 — 𝐍 𝐝𝐢𝐦𝐞𝐧𝐬𝐢𝐨𝐧𝐬:

Address = L0 + W * Σ(p=1 to n) [ ip * Π(q=p+1 to n) Dq ]

Where:
  ip = index in dimension p
  Dq = size of dimension q
  W  = word size

// 𝐀𝐩𝐩𝐥𝐲𝐢𝐧𝐠 𝐇𝐨𝐫𝐧𝐞𝐫'𝐬 𝐑𝐮𝐥𝐞 𝐭𝐨 𝐫𝐞𝐝𝐮𝐜𝐞 𝐦𝐮𝐥𝐭𝐢𝐩𝐥𝐢𝐜𝐚𝐭𝐢𝐨𝐧𝐬:

ORIGINAL (right to left):
i4 + i3*D4 + i2*D3*D4 + i1*D2*D3*D4

STEP 1 — factor out D4:
i4 + D4*(i3 + i2*D3 + i1*D2*D3)

STEP 2 — factor out D3:
i4 + D4*(i3 + D3*(i2 + i1*D2))

STEP 3 — fully factored (Horner's Rule):
i4 + D4*(i3 + D3*(i2 + D2*i1))

// 𝟑𝐃 𝐑𝐨𝐰 𝐌𝐚𝐣𝐨𝐫 𝐟𝐨𝐫𝐦𝐮𝐥𝐚 (𝐝𝐞𝐫𝐢𝐯𝐞𝐝 𝐬𝐚𝐦𝐞 𝐰𝐚𝐲):

Address of a[i][j][k] = L0 + (i*D2*D3 + j*D3 + k) * W

With Horner's Rule:
= L0 + (i*D2 + j)*D3 + k) * W