#include <stdio.h>

int main() {
    printf("Enter the value for x: ");
    int var1;
    scanf("%d", &var1);
    printf("Enter the value for y: ");
    int var2;
    scanf("%d", &var2);
    int var3 = var1 + var2;
    printf("The value of var3 is: %d\n", var3);
    return 0;
}
