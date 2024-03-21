#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(int argc, char *argv[])
{
    // v² = v0² + 2a * (delta S)
    // 1    2     3        4
    setlocale(LC_ALL, "Portuguese_Brazil.UTF8");
    //Checa a quantidade de argumentos (o comando de execucao do programa conta)
    if(argc != 5)
    {
        printf("Quantidade de argumentos inválida\n");
        printf("Insira respectivamente: velocidade final, velocidade inicial, aceleração e variação de distância. (Valores no SI)\n");
        system("pause");
        return 1;
    }
    float vfquad, viquad, acel, deltaS;
    //Checa se o número inserido em alguma das posições é zero
    if(argv[1][0] == '0' && argv[1][1] == '\0')
    {
        vfquad = 0;
    }
    else
    {
        vfquad = pow(atof(argv[1]), 2);
    }
    if(argv[2][0] == '0' && argv[2][1] == '\0')
    {
        viquad = 0;
    }
    else
    {
        viquad = pow(atof(argv[2]), 2);
    }
    if(argv[3][0] == '0' && argv[3][1] == '\0')
    {
        acel = 0;
    }
    else
    {
        acel = 2 * atof(argv[3]);
    }
    if(argv[4][0] == '0' && argv[4][1] == '\0')
    {
        deltaS = 0;
    }
    else
    {
        deltaS = atof(argv[4]);
    }
    //Checa se uma letra foi inserida ao invés de um número, podendo executar as operações de acordo com a variavel que nao temos
    if(isalpha(argv[1][0]) != 0)
    {
        vfquad = sqrt(viquad + (acel * deltaS));
        printf("Argv[1] inválido\n Velocidade Final: %.2f\n", vfquad);
        system("pause");
        return 2;
    }
    if(isalpha(argv[2][0]) != 0)
    {
        viquad = sqrt(vfquad - (acel * deltaS));
        printf("Argv[2] inválido\n V0²: %.2f\n", viquad);
        system("pause");
        return 3;
    }
    if(isalpha(argv[3][0]) != 0)
    {
        acel = (vfquad - viquad) / (2 * deltaS);
        printf("Argv[3] inválido\n Aceleração: %.2f\n", acel);
        system("pause");
        return 4;
    }
    if(isalpha(argv[4][0]) != 0)
    {
        //v² = v0² + 2a * delta(S)
        deltaS = (vfquad - viquad) / (acel);
        printf("Argv[4] inválido\n Delta S: %.2f\n", deltaS);
        system("pause");
        return 5;
    }
    /*printf("Velocidade ao quadrado: %.2f\n", vfquad);
    printf("Velocidade inicial ao quadrado: %.2f\n", viquad);
    printf("Aceleração: %.2f\n", acel);
    printf("Variação da distância: %.2f\n", deltaS); */
}