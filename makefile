all:
	yacc -d compilator.y
	lex compilator.l 
	gcc lex.yy.c y.tab.c -o ex
	./ex test.txt