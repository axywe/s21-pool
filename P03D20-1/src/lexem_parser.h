#ifndef LEXEM_PARSER_H
#define LEXEM_PARSER_H
#define SEPARATORS "+-*/()sctCSl"
t_list* main_parser();
t_list* split(char* input, char* seperators);
#endif
