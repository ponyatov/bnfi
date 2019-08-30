#include <stdio.h>
#include <assert.h>

extern int yylex();
extern int yylineno;
extern char *yytext;

extern int yy_scan_string(char*);

#define BNF \
    "nop bye"

#define Msz 0x1000
#define Dsz 0x10

int M[Msz];     // bytecode memory
int Cp=0;
int Ip=0;

int D[Dsz];     // data stack
int Dp=0;

enum op {       // opcodes
    nop = 0x00,
    bye = 0xFF
};

void compiler(char *bnf)
{
    yy_scan_string(bnf);
    printf("\n\ngrammar: %s %s\n\n",bnf,yylex());
}

void parse(FILE *in) {
    while (!feof(in)) {
        char c = fgetc(in); printf("%c ",c);
    }
        printf("\n");
}

int main(int argc, char *argv[])
{
    FILE *in;
    assert(argc==2);
    if (argc != 2) {
        compiler(BNF);
        in = fopen(__FILE__,"r");
    } else {
        compiler(argv[1]);
        in = stdin;
    }
    // parse(in);
}
