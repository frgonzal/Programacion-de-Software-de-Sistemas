#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//P1
void to_lower(char* s);
void to_upper(char* s);

//P2
int palindromo(char* s);

//P3
void reverse(char* s);

//P4
char mas_repetido(char* s);

int main(int args, char **argv){
    char s[] = "Hola";

    to_lower(s);
    printf("%s\n",s);

    to_upper(s);
    printf("%s\n",s);

    //printf("%d\n",palindromo("abcdcba"));

    reverse(s);
    printf("%s\n",s);


    printf("%c\n",mas_repetido("HOlaaaaa"));

    return 0;
}

//int strlen(char *s){
//    char *p = s;
//    while(*p++)
//        ;
//    return p-s-1;
//}

void to_lower(char* s){
    while(*s){
        if('A'<=*s && *s<='Z')
            *s += 'a'-'A';
        s++;
    }
}

void to_upper(char* s){
    while(*s){
        if('a'<=*s && *s<='z')
            *s -= 'a'-'A';
        s++;
    }
}

int palindromo(char* s){
    char *p;
    for(p=s+strlen(s)-1; 0<p-s; s++, p--){
        if(*s!=*p)
            return 0;
    }
    return 1;
}

void reverse(char* s){
    for(char* p=s+strlen(s)-1; 0<p-s; s++,p--){
        char t  = *s;
        *s = *p;
        *p =  t;
    }
}


char mas_repetido(char *s){
    int cnt[256] = {0};
    while(*s){
        *(cnt + *s)++;//??? probar despues...
        s++;
    }

    //char mrep = 0;
    //for(int i=0; i<256; i++){
    //    if(*(cnt+mrep) < *(cnt+i))
    //        mrep = i;
    //}
    //return mrep;

    int *mrep = cnt;
    for(int i=0; i<256; i++){
        if(*(mrep) < *(cnt+i))
            mrep = cnt+i;
    }
    return mrep-cnt;
}