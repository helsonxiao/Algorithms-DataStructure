#include <stdio.h>

int main()
{
    float f = 0.0;
    int i = 5;
    f = (float)i;
    printf("%f\n", f); // 5.000000
    f = *&i;
    printf("%f\n", f); // 0.000000
    return 0;
}
