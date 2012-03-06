#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int c, atual = 0;
    char aspas[2][3] = {"``", "''"};
        while((c = getchar()) != EOF)
            if(c == '"'){
                printf("%s", aspas[atual]);
                atual = (atual + 1) % 2;
            } else {
                putchar(c);
            }
    return 0;
}
