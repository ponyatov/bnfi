#include <stdio.h>
#include <assert.h>

#define BNF ""

void compiler(char *bnf)
{
    printf("\n\ngrammar: %s\n\n",bnf);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        compiler(BNF);
    else
        compiler(argv[1]);
}
