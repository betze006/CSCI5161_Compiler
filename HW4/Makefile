TARGET = parser
OBJECT = parser.tab.c parser.tab.o lex.yy.c semantic_routines.o symbol_tables.o nesting.o
CC = gcc
LEX = flex
YACC = bison -v
YACCFLAG = 
LIBS = -lfl 

parser: parser.tab.o semantic_routines.o symbol_tables.o nesting.o
	$(CC) -o $(TARGET) parser.tab.o semantic_routines.o symbol_tables.o nesting.o $(LIBS)

parser.tab.o: parser.tab.c lex.yy.c
	$(CC) -c parser.tab.c

semantic_routines.o: semantic_routines.c
	$(CC) -c semantic_routines.c

symbol_tables.o: symbol_tables.c
	$(CC) -c symbol_tables.c

nesting.o: nesting.c
	$(CC) -c nesting.c

lex.yy.c: lexer3.l
	$(LEX) lexer3.l

parser.tab.c: parser.y
	$(YACC) $(YACCFLAG) parser.y

clean:
	rm -f $(TARGET) $(OBJECT) 

