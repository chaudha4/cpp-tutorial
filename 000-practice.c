#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void func1(int ii) {
    printf("%d\n", ii);
    return;
}

int main() {
    printf("\n");

    int ii = 10;
    func1(++ii);
    printf("%d\n", ii);

    printf("\n");
    return 0;
}