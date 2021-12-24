#include "parser.h"

FILE *input_script;

int line_index;                     //The current processed position in a line
int line_lenth;                     //The length of a line
int line;                           //The index number of the line
long int_temp = 0;                  //Temporary variable to hold a int value or a char
char line_proc[LINE_MAX_LENGTH];    //The line of code that is being processed
char char_temp;                     //The character that got input
char token[TOKEN_MAX_LENGTH];       //The processing token

//Get the next character, automatically advances the line
int get_char()
{
    if (line_index == line_lenth)//End of the line
    {
        line++;//Add one to the record
        if (fgets(line_proc, LINE_MAX_LENGTH, input_script) != NULL)//End of file
        {
            line_lenth = strlen(line_proc);
            line_index = 0;
            return ('\n');
        }
        else
            return (EOF);
    }
    else
    {
        
        char_temp = (line_proc[line_index]);//Get the char
        line_index += 1;//Add next

        return char_temp;
    }
}

//Clear the token string
void token_clear()
{
    int i;
    printf("Clearing token: %s\n", token);//Print what's in the token for debugging
    for (i = 0; i < TOKEN_MAX_LENGTH; i++)
        token[i] = '\0';
    return;
}

//Determine if it's a letter or '_'
bool Is_Button()
{
    return ((33 <= char_temp) && (char_temp <= 127));
}

//Determine if it's a digit
bool Is_Digit()
{
    return (('0' <= char_temp) && (char_temp <= '9'));
}

//Determine if it's a ';'
bool Is_Semi()
{
    return (char_temp == ';');
}

//Determine if it's a keyword
token_types Is_Key()
{
    if (strcmp(token, "HOLD") == 0)
        return HOLD;
    else if (strcmp(token, "RELEASE") == 0)
        return RELEASE;
    else if (strcmp(token, "ALL") == 0)
        return ALL;
    else if (strcmp(token, "STRING") == 0)
        return STRING;
    else if (strcmp(token, "FN") == 0)
        return FN;
    else if (strcmp(token, "ESC") == 0)
        return ESC;
    else if (strcmp(token, "DELETE") == 0)
        return DELETE;
    else if (strcmp(token, "F1") == 0)
        return F1;
    else if (strcmp(token, "F2") == 0)
        return F2;
    else if (strcmp(token, "F3") == 0)
        return F3;
    else if (strcmp(token, "F4") == 0)
        return F4;
    else if (strcmp(token, "F5") == 0)
        return F5;
    else if (strcmp(token, "F6") == 0)
        return F6;
    else if (strcmp(token, "F7") == 0)
        return F7;
    else if (strcmp(token, "F8") == 0)
        return F8;
    else if (strcmp(token, "F9") == 0)
        return F9;
    else if (strcmp(token, "F10") == 0)
        return F10;
    else if (strcmp(token, "F11") == 0)
        return F11;
    else if (strcmp(token, "F12") == 0)
        return F12;
    else if (strcmp(token, "PRTSCR") == 0)
        return PRTSCR;
    else if (strcmp(token, "INSERT") == 0)
        return INSERT;
    else if (strcmp(token, "BACKSPACE") == 0)
        return BACKSPACE;
    else if (strcmp(token, "ENTER") == 0)
        return ENTER;
    else if (strcmp(token, "SHIFT") == 0)
        return SHIFT;
    else if (strcmp(token, "CAPSLOCK") == 0)
        return CAPSLOCK;
    else if (strcmp(token, "CTRL") == 0)
        return CTRL;
    else if (strcmp(token, "ALT") == 0)
        return ALT;
    else if (strcmp(token, "PGUP") == 0)
        return PGUP;
    else if (strcmp(token, "PGDN") == 0)
        return PGDN;
    else if (strcmp(token, "HOME") == 0)
        return HOME;
    else if (strcmp(token, "END") == 0)
        return END;
    else if (strcmp(token, "NUMLOCK") == 0)
        return NUMLOCK;
    else if (strcmp(token, "UP") == 0)
        return UP;
    else if (strcmp(token, "DOWN") == 0)
        return DOWN;
    else if (strcmp(token, "LEFT") == 0)
        return LEFT;
    else if (strcmp(token, "RIGHT") == 0)
        return RIGHT;
    else if (strlen(token) == 1)
        return KEY;
    else
        return CONTENT;
}

//Lexical analysis function
token_types lex()
{
    int k = 0;                      //The index of the processing character in a token
    token_types symbol = NONE;      //The type of the processing token

    token_clear();

    while ((char_temp == ' ') || (char_temp == '\t') || (char_temp == '\n'))
        get_char();                 //Skip the divisor

    if (Is_Letter(char_temp))
    {
        token_clear();

        do
        {
            if (k < TOKEN_MAX_LENGTH)
            {
                token[k] = char_temp;
                k++;
            }
            else
            {
                fprintf(stderr, "Error: content exceeds the maximum length.");
                exit(-1);
            }
            get_char();
        } while (Is_Letter(char_temp) || Is_Digit(char_temp));

        symbol = Is_Key();          //Try to determine if it's a keyword
    }
    else if (Is_Digit(char_temp))
    {
        if (char_temp == '0')       //Starting with 0
        {
            int_temp = 0;
            symbol = INT;
            get_char();
            if (Is_Digit(char_temp))
            {
                fprintf(stderr, "Error: Int number can't start with 0.\n");
                exit(-1);
            }
        }
        else
        {
            int_temp = 0;
            symbol = INT;
            for (; Is_Digit(char_temp); k++)
            {
                int_temp = int_temp * 10 + char_temp - '0';
                get_char();
            }
        }
        if (int_temp < 0)           //Can't be less than 0, indicating it's overflown
        {
            fprintf(stderr, "Error: Int number overflown.\n");
            exit(-1);
        }
    }
    else
    {
        fprintf(stderr, "Something is wrong.\n");//Unsupported input, handle later
        exit(-1);
    }

    return symbol;
}

void grammar()
{
    
}
