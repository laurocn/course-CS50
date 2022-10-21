#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //  Pega o valor de n com o usuário (p/ altura)
    int altura;
    // Se altura maior que 1 e menor que 8, é armazenado
    do
    {
        altura = get_int("Altura da pirâmide: ");
    }
    while (altura < 1 || altura > 8);
    // Aqui, vai imprimir uma "linha" para o valor da altura.
    for (int linha = 0; linha < altura; linha++)
    {
        // Na linha, ela vai ter, primeiro o espaço e, em seguida a hash, de acordo com a altura
        //for (inicialização; condição; o que faz)
        for (int espaço = 0; espaço < altura - linha - 1; espaço++)
        {
            printf(" ");
        }
        for (int hash = 0; hash <= linha; hash++)
        {
            printf("#");
        }
        for (int space = 0; space < 1; space++)
        {
            printf("  ");
        }
        for (int hash = 0; hash <= linha; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}