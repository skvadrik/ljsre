#!/bin/sh

re2c -o lex.re.cpp lex.re

sources="main.cpp lex.re.cpp parser.lalr.cpp nfa_show.cpp"

g++ -O2 -W -Wall -Weffc++ -Wextra $sources -o main
