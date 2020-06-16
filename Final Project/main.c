#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* infixPrep(char* fileName)
    {
        char character, rightHandSide[20]/*, varArray[20]*/;
        char* infix = NULL;
        int i = 0, j = 0, k = 0;
        //float varValue;
        FILE* filePointer;

        filePointer = fopen(fileName, "r");

        if(filePointer == NULL) //file not found
        {
            printf("Error opening file.");
            exit(-1);
        }

        do
        {
            character = fgetc(filePointer);

            if((character == '\n') || (character != '=')
                || ((character < 65 && character > 90)
                   && (character < 97 && character > 122))
                || (character == ' '))
            {
                printf("Syntax error.");
                exit(-1);
            }

            if((character >= 65 && character <= 90)
                || (character >= 97 && character <= 122))
            {
                if(k > 0)
                {
                    if(rightHandSide[k - 1] == ' ')
                    {
                        printf("Syntax error.");
                        exit(-1);
                    }
                }
            }
            rightHandSide[k] = character;
            k++;
        }
        while(character != '='); //traverses through line till rhs

        do
        {
            character = fgetc(filePointer);

            if((character >= 65 && character <= 90)
               || (character >= 97 && character <= 122))
            {
                if(j > 0)
                {
                    if(infix[j - 1] != ' ')
                    {
                        infix[j] = ' ';
                        j++;
                    }
                }
                //varArray[i] = character;
                /*invoke search by key function in bst and put value in varValue
                convert value from float to string
                add string to infix
                add space after string in infix
                reset varArray to NULL
                let i = 0*/
                i++;
            }
            else if(character == '+' || character == '-'
                    || character == '/' || character == '*'
                    || character == '(' || character == ')')
            {
                if(j > 0)
                {
                    if(infix[j - 1] != ' ')
                    {
                        infix[j] = ' ';
                        j++;
                    }
                }

                infix[j] = character;
                infix[++j] = ' ';
                j++;
            }
            else if((character >= 48 && character <= 57)
                    || character == '.')
            {
                if(character == '.')
                {
                    if(infix[j - 1] == '.')
                    {
                        printf("Syntax error.");
                        exit(-1);
                    }
                }
                infix[j] = character;
                j++;
            }
            else
            {
                printf("Syntax error.");
                exit(-1);
            }
        }
        while(character != '\0');

        return infix;
    }
    return 0;
}
