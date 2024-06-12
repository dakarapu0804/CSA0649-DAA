#include <stdio.h>

void copy_string(char *src, char *dst) {
    if (*src == '\0') {
        *dst = '\0';
        return;
    }
    *dst = *src;
    copy_string(src + 1, dst + 1);
}

int main() {
    char src[] = "Hello, World!";
    char dst[20]; 

    copy_string(src, dst);

    printf("Copied string: %s\n", dst);

    return 0;
}
