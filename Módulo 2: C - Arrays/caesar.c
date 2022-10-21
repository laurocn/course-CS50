#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]) //arg count the number of command arguments
{
    if (argc != 2) // se o input é diferente de 2 arrays, pede input correto
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int ruler = atoi(argv[1]); // que seja 1 número o array 1!
    for (int i = 0, n = strlen(argv[1]); i < n; i++) //
    {
        if (ruler <= 0 || (!isdigit(argv[1][i])))  //se não for positivo
        {
            printf("Use:./ceasar key\n");
            return 1;
        }
    }
    string plain = get_string("plaintext: "); //Pede o texto a ser criptografado
    printf("ciphertext: "); //Prepara para apresentar o texto cipher
    int n = strlen(plain); //qual tamanho da string?
    for (int i = 0; i <= n; i++)
        //caracter vai ser caracter de plain + ruler %26
        if (isalpha(plain[i])) //se i faz parte do alfabeto
        {
            if (isupper(plain[i])) //se i é letra maíscula
            {
                plain[i] = (((plain[i] - 65) + ruler) % 26) + 65;
                printf("%c", plain[i]);
            }
            if (islower(plain[i])) // se i é letra mínuscula
            {
                plain[i] = (((plain[i] - 97) + ruler) % 26) + 97;
                printf("%c", plain[i]);
            }
        }
        else // se não for alfa
        {
            printf("%c", plain[i]);
        }
        // se colocar o printf("\n"); aqui, o teste A>B dá certo e os outros errado
    printf("\n"); //o dito que dá problema no check50, mesmo estando visualmente correto todos os testes
    return 0;
}