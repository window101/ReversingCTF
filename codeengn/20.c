
#include <stdio.h>
#include <string.h>

void main() {
    char key[] = "CodeEngn";
    int BL= 0x41;
    for(int i = 0; i<strlen(key); i++) {
        printf("%x ", key[i] ^ BL);
        BL++;
    }
}