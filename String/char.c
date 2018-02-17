#include <stdio.h>

int main()
{
    char *e;

    char S[] = "abcd";
    printf("%s\n", S);
    printf("%p\n", S); // S 中的地址就是 a 的地址(同时也是 S 变量的地址)
    e = S;
    printf("%c\n", *e);
    printf("\n");

    char *T;
    T = "asdf"; // 存入 a 的地址
    printf("%s\n", T);
    printf("%p\n", T); // T 中的地址就是 a 的地址
    e = T;
    printf("%c\n", *e);
    printf("\n");

    char *names[] = {"Zara Ali", "Hina Ali", "Nuha Ali", "Sara Ali"};
    printf("Value of names[1] = %s\n", names[1]); // names[1] 相当于 int *ptr 的 *ptr[i]

    double *p;
    double balance[10];
    p = balance; // *(balance + 4) == balance[4];

    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("%s\n", greeting);
}