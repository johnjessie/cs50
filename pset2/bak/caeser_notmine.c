    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>

    int encode(int ch, int key) { 
            if (islower(ch)) {
                    ch = (ch -'a' + key) % 26 + 'a';
                    ch += (ch < 'a') ? 26 : 0;
            }
            else if (isupper(ch)) {
                    ch = (ch-'A' + key) % 26 + 'A';
                    ch += (ch < 'A') ? 26 : 0;
            }
            return ch;
    }

    int decode(int ch, int key) { 
            return encode(ch, - key);
    }

    int main(int argc, char **argv) { 
            int ch;
            int key;

            if (argc < 2) {
                    printf("USAGE: cipher <integer key> <encode | decode>\n");
                    printf("Then, just type your text and it will automatically output the en/de crypted text! :)\n");
                    return 1;
            }

            key = atoi(argv[1]);
            if (key < 1 || key > 25) {
                    printf("Key is invalid, or out of range. Valid keys are integers 1 through 25.\n");
                    return 1;
            }

            int (*f)(int, int) = (argv[2][0] == 'd') ? 
                    decode : 
                    encode;

            while (EOF != (ch=getchar()))
                    putchar(f(ch, key));

            return 0;
    }