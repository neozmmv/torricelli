#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil.UTF8");
    printf("*****************************\n");
    printf("* Calculadora de Torricelli *\n");
    printf("*****************************\n\n");
    printf("Insira um \"x\" na variável que quiser descobrir.\n\n");
    
    char *vf = malloc(10);
    char *vi = malloc(10);
    char *acel = malloc(10);
    char *deltaS = malloc(10);

    float vinicial, vfinal, acc, dS;

    printf("Insira a velocidade final: ");
    scanf("%s", vf);

    printf("Insira a velocidade inicial: ");
    scanf("%s", vi);

    printf("Insira a aceleração: ");
    scanf("%s", acel);

    printf("Insira a variação de distância: ");
    scanf("%s", deltaS);

    if(vf[0] == '0' && vf[1] == '\0')
    {
        vfinal = 0;
    }
    else
    {
        vfinal = pow(atof(vf), 2);
    }
    if(vi[0] == '0' && vi[1] == '\0')
    {
        vinicial = 0;
    }
    else
    {
        vinicial = pow(atof(vi), 2);
    }
    if(acel[0] == '0' && acel[1] == '\0')
    {
        acc = 0;
    }
    else
    {
        acc = 2 * atof(acel);
    }
    if(deltaS[0] == '0' && deltaS[1] == '\0')
    {
        dS = 0;
    }
    else
    {
        dS = atof(deltaS);
    }
    // vi vf acel deltaS
    if(vi[0] == 'x' && vf[0] == 'x')
    {
        printf("Erro: mais de uma variável desconhecida.\n");
        free(vi);
        free(vf);
        free(acel);
        free(deltaS);
        return 1;
    }
    if(vi[0] == 'x' && acel[0] == 'x')
    {
        printf("Erro: mais de uma variável desconhecida.\n");
        free(vi);
        free(vf);
        free(acel);
        free(deltaS);
        return 2;
    }
    if(vi[0] == 'x' && deltaS[0] == 'x')
    {
        printf("Erro: mais de uma variável desconhecida.\n");
        free(vi);
        free(vf);
        free(acel);
        free(deltaS);
        return 3;
    }
    if(vf[0] == 'x' && acel[0] == 'x')
    {
        printf("Erro: mais de uma variável desconhecida.\n");
        free(vi);
        free(vf);
        free(acel);
        free(deltaS);
        return 4;
    }
    if(vf[0] == 'x' && deltaS[0] == 'x')
    {
        printf("Erro: mais de uma variável desconhecida.\n");
        free(vi);
        free(vf);
        free(acel);
        free(deltaS);
        return 5;
    }
    if(acel[0] == 'x' && deltaS[0] == 'x')
    {
        printf("Erro: mais de uma variável desconhecida.\n");
        free(vi);
        free(vf);
        free(acel);
        free(deltaS);
        return 6;
    }
    if(isalpha(vf[0]) != 0)
    {
        vfinal = sqrt(vinicial + (acc * dS));
        printf("Velocidade final: %.2f\n", vfinal);
        system("pause");
    }
    if(isalpha(vi[0]) != 0)
    {
        vinicial = sqrt(vfinal - (acc * dS));
        printf("Velocide inicial: %.2f\n", vinicial);
        system("pause");
    }
    if(isalpha(acel[0]) != 0)
    {
        acc = (vfinal - vinicial) / (2 * dS);
        printf("Aceleração: %.2f\n", acc);
        system("pause");
    }
    if(isalpha(deltaS[0]) != 0)
    {
        dS = (vfinal - vinicial) / (acc);
        printf("Variação da distância: %.2f\n", dS);
        system("pause");
    }

    free(vi);
    free(vf);
    free(acel);
    free(deltaS);
}
