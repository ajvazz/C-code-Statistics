CC = g++
CPPFLAGS = -std=c++11

parser: lex.yy.o parser.tab.o ast.o
	$(CC) $(CPPFLAGS) -o $@ $^

lex.yy.o: lex.yy.c parser.tab.hpp ast.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

lex.yy.c: lexer.lex
	flex $<

parser.tab.o: parser.tab.cpp parser.tab.hpp ast.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<

ast.o: ast.cpp ast.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean


clean:
	rm -f *~ *.o parser *.output *tab* lex.yy.c