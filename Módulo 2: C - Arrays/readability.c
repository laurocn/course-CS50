#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//índice Coleman-Liau

int main(void)
{
    string text = get_string("What do you want to know? ");
    int letras = 0, palavras = 1, sentencas = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letras++;
        }
        else if (text[i] == ' ' && text[i + 1] != ' ')
        {
            palavras++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentencas++;
        }
    }
    //índice Coleman-Liau = 0,0588 * L (número médio de letras por 100 palavras) - 0,296 * S (número médio de sentenças por 100 palavras) - 15,8
    float letrasm = (letras * 100 / (float)palavras);
    float sentencasm = (sentencas * 100 / (float)palavras);
    float grade = (0.0588 * letrasm) - (0.296 * sentencasm) - 15.8;
    //resultado do índice
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", grade);
    }
    return 0;
}
