
test: ./bnfi$(EXE)
	ls -la | ./$< ""
C = bnfi.c
./bnfi$(EXE): $(C) $(H) Makefile
	$(CC) $(CFLAGS) -o $@ $(C)