#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2 || argc == 1) //se não começar com essa linha, o programa dá erro se preencher o comando sem o array[1]
    {
        printf("Uso: ./ chave de substituição\n");
        return 1;
    }
    int i = 0;
    string key = argv[1];
    int codigo = strlen(argv[1]);
    bool rules = true;
    if (codigo != 26)
    {
        printf("Please, input 26 character key\n");
        return 1;
    }
    for (i = 0; i < 26; i++) //aqui tem um loop duplo, coisa mais louca. roda o i
    {
        for (int j = i; j < 26; j++) //depois cria o j = o i, e roda todos os j's da key
        {
            if (!isalpha(key[i]))//comparando se esse i é diferente de alpha
            {
                printf("Please, use only letters\n");
                return 1;
            }
            if (toupper(key[i]) == toupper(key[j + 1])) //e se esse j é = a algum i. Também não faz diferença se é upper ou lower case, por isso mais fácil já jogar os dois pra upper.
            {
                printf("Please, doesn't use duplicate letters\n");
                return 1;
            }
        }
    }
    string plain = get_string("plaintext: ");//input plaintext
    int leng = strlen(plain);
    for (i = 0; i < leng; i++)
    {
        if (!isalpha(plain[i]))
        {
            continue;
        }
        if (isupper(plain[i]))
        {
            plain[i] = toupper(key[plain[i] - 65]);
        }
        else
        {
            plain[i] = tolower(key[plain[i] - 97]);
        }
    }
    printf("ciphertext: %s\n", plain);
    return 0;
}