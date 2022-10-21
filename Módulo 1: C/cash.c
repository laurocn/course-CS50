#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float valor;
    do
    {
        //Coletar valor do usuário, sem R$
        valor = get_float ("Inserir valor (p.ex 7.55):");
    }
    //Garantir que o valor é maior que zero
    while (valor <= 0);
    //Transformar o valor em centavos
    int total = round(valor * 100);
    //Quantas moedas de 25 centavos
    int quarter = total/25;
    //Tirando as moedas de 25 centavos, quantas de 10 centavos (e assim sucessivamente)
    int dimes = (total - quarter*25)/10;
    int nickles = (total - quarter*25 - dimes*10)/5;
    int pennys = (total - quarter*25 - dimes*10 - nickles*5)/1;
    int change = quarter + dimes + nickles + pennys;
    {
    printf("%i\n", change);
    }
}