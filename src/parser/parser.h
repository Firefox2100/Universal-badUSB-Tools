#ifndef _PARSER_H
#define _PARSER_H

#define TOKEN_MAX_LENGTH 100
#define LINE_MAX_LENGTH 500

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "token_types.h"

extern FILE *input_script;
extern int line_index;          //The current processed position in a line
extern int line_lenth;          //The length of a line
extern int line;                //The index number of the line
extern long int_temp;           //Temporary variable to hold a int value or a char
extern char line_proc[];        //The line of code that is being processed
extern char char_temp;          //The character that got input
extern char token;              //The processing token

int get_char();
void token_clear();
bool Is_Letter();
bool Is_Digit();
bool Is_Semi();
token_types Is_Key();
token_types lex();
void grammar();

#endif
