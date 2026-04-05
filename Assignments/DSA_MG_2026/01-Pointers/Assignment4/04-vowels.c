#include <stdio.h>

int main()
{
    char str[]="Hello World";
    int vowels=0, consonants=0;
    char *p =str;

    while(*p != '\0') {
        if((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) 
        {
            if(*p=='a'||*p=='e'||*p=='i'||*p=='o'||*p=='u'||*p=='A'||*p=='E'||*p=='I'||*p=='O'||*p=='U') 
            {
                vowels++;
            } 
            else 
            {
                consonants++;
            }
        }
        p++;
    }
    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", consonants);
    return 0;
}
