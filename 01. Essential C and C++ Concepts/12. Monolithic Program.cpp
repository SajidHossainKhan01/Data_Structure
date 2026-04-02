#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    // Step 1: Declare and initialize variables
    int length = 0;
    int breadth = 0;

    // Step 2: Take input from user
    printf("Enter length and breadth: ");
    scanf("%d %d", &length, &breadth);

    // Step 3: Calculate area and perimeter
    int area = length * breadth;
    int peri = 2 * (length + breadth);

    // Step 4: Print results
    printf("Area = %d\n", area);
    printf("Perimeter = %d\n", peri);

    return 0;
}
```

**Output:**
```
Enter length and breadth: 10 5
Area = 50
Perimeter = 30