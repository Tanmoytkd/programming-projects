#include <stdio.h>

char convert(char ch) {
    switch(ch) {
    case '2': return '`';
    case '3': return '1';
    case '4': return '2';
    case '5': return '3';
    case '6': return '4';
    case '7': return '5';
    case '8': return '6';
    case '9': return '7';
    case '0': return '8';
    case '-': return '9';
    case '=': return '0';
    case 'e': return 'q';
    case 'r': return 'w';
    case 't': return 'e';
    case 'y': return 'r';
    case 'u': return 't';
    case 'i': return 'y';
    case 'o': return 'u';
    case 'p': return 'i';
    case '[': return 'o';
    case ']': return 'p';
    case 'd': return 'a';
    case 'f': return 's';
    case 'g': return 'd';
    case 'h': return 'f';
    case 'j': return 'g';
    case 'k': return 'h';
    case 'l': return 'j';
    case ';': return 'k';
    case '\'': return 'l';
    case 'c': return 'z';
    case 'v': return 'x';
    case 'b': return 'c';
    case 'n': return 'v';
    case 'm': return 'b';
    case ',': return 'n';
    case '.': return 'm';
    case '/': return ',';
    default: return ch;
    }
}

int main() {
    char ch;

    while(scanf("%c", &ch)==1) {
        if(isupper(ch)) {
            ch=convert(tolower(ch));
        }
        else ch=convert(ch);

        printf("%c", ch);
    }

    return 0;
}
