#!/bin/sh

re2c -o lex.re.cpp lex.re

sources="main.cpp lex.re.cpp re_parser.lalr.cpp"

g++ -O2 -W -Wall -Weffc++ -Wextra $sources -o main
