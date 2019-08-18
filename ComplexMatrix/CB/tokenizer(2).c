#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int no_of_tokens(char*);
char* scopy(char*);
char** tokenizer(char*,char**,int);

int token()
{
    char string[] = "You are in EE 222";
    char *str2;
    char **tokens;
    int tok, i;

    str2 = scopy(string);
    tok = no_of_tokens(string);
    tokens = tokenizer(str2,tokens,tok);

    printf("no of tokens = %d\n\n",tok);
    printf("The tokens are: \n");
    for (i = 0; i<tok; i++){
        printf("%s\n",tokens[i]);
    }

    return 0;
}

int no_of_tokens(char* s){
    char *tokenptr;
    int tokens = 0;

    tokenptr = strtok(s," ");
    while(tokenptr){
        tokens++;
        tokenptr = strtok(NULL," ");
    }
    return tokens;
}

char* scopy(char* s){
    int n = strlen(s);
    int i;
    char *c;
    c = (char*) malloc(sizeof(char)*(n+1));

    for(i = 0; i <= n; i++){
        c[i] = s[i];
    }
    return c;
}

char** tokenizer(char* s,char** t,int n){
    char *p; int i = 0;

    t = (char**) malloc(sizeof(char*)*n);
    p = strtok(s," ");
    while(p){
        t[i] = (char*) malloc(strlen(p)+1);
        strcpy(t[i++],p);
        p = strtok(NULL," ");
    }
    return t;
}
