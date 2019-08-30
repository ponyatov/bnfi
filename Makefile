
C = bnfi.c lex.yy.c
test: ./bnfi$(EXE)
	cat $(C) | ./$< "`cat bnfi.grammar`"
./bnfi$(EXE): $(C) $(H) Makefile
	$(CC) $(CFLAGS) -o $@ $(C)
lex.yy.c: bnfi.lex
	flex -o $@ $<
