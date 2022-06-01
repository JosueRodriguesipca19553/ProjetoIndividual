/**
* author: Josué - Aluno 19553
* email : a19553@alunos.ipca.pt
* date: 31-05-2022
* desc : Modelo de listagens
*/

#pragma once

#pragma warning( disable : 4996 )
//Evita a utilização do _CRT_SECURE_NO_WARNINGS, desactiva avisos de segurança na compilação

#pragma region Includes
#include "Definitions.h"
#pragma endregion

#pragma region Funções_de_listagens_e_ficheiros

/**
* @brief Listagem das operações do enunciado
* @param [Struct]  Processo: Grelha geral de processos.
* @return [int] 
*/
int listagens(Process* grid)
{

    //
    // Determinar quantidade minima para completar um job (2 exemplos)
    // a função vai mostrar o job, as operações escolhidas e as maquinas com o valor minimo
    //

    int min = 0;
    int max = 0;
    float avg = 0;

    min = min_operation(grid, "PF1.1", 1);
    printf("PF1.1 - OP1 - MIN");
    printf("\n%i\n", min);

    min = min_operation(grid, "PF2.2", 1);
    printf("PF2.2 - OP1 - MIN");
    printf("\n%i\n", min);

    min = min_operation(grid, "PF3.3", 3);
    printf("PF3.3 - OP5 - MIN");
    printf("\n%i\n", min);


    max = max_operation(grid, "PF1.1", 1);
    printf("PF1.1 - OP1 - MAX");
    printf("\n%i\n", max);

    max = max_operation(grid, "PF2.2", 1);
    printf("PF2.2 - OP1 - MAX");
    printf("\n%i\n", max);

    max = max_operation(grid, "PF3.3", 3);
    printf("PF3.3 - OP3 - MAX");
    printf("\n%i\n", max);


    avg = avg_operation(grid, "PF1.1", 1);
    printf("PF1.1 - OP1 - AVG");
    printf("\n%3.2f\n", avg);

    avg = avg_operation(grid, "PF2.2", 1);
    printf("PF2.2 - OP1 - AVG");
    printf("\n%3.2f\n", avg);

    avg = avg_operation(grid, "PF3.3", 3);
    printf("PF3.3 - OP3 - AVG");
    printf("\n%3.2f\n", avg);

    return 1;
}


/**
* @brief Função que cria o Process plan em HTML ( ficheiro criado : TESTE.HTML )
* @return VOID
*/
void create_process_plan()
{

    int i;
    int i2;
    char sea[15];
    FILE* fp;
    char htmlline[MAXLINE];
    char htmlfile[MAXFILE];
    char rep[MAXLINE];
    char st1[15];
    char st2[15];
    char st3[15];
    int a;
    int position;
    char* ptr;

    strcpy(htmlline,"");
    strcpy(htmlfile, "");
    strcpy(sea, "");
    strcpy(rep, "");

        fp = fopen("template.html", "rt");
        while (!feof(fp))
        {
            fgets(htmlline, sizeof htmlline, fp);
            strcat(htmlfile, htmlline);
        }
        fclose(fp);
    
        for (i = 0; i < MAQUINAS; i++)
        {
            for (i2 = 0; i2 < TIMESLOTS; i2++)
            {
                if (escalation[i][i2].operation != 0)
                {
                    strcpy(sea, "");
                    strcat(sea, "#");
                    itoa((i + 1),st1,10);
                    strcat(sea, st1);
                    strcat(sea, ".");
                    if(i2<10) strcat(sea, "0");
                    itoa((i2),st2, 10);
                    strcat(sea, st2);
                    strcat(sea, "<br>OPX");
                    //pos = strstr(htmlfile, sea);
                    strcpy(rep, "");
                    strcat(rep, escalation[i][i2].process);
                    strcat(rep, "<br>  ");
                    itoa(escalation[i][i2].operation, st3, 10);
                    strcat(rep, st3);

                    ptr = strstr(htmlfile, sea);
                    position = (int)(htmlfile - ptr)*-1;
                    if (ptr)
                    {
                        for (a = position; a < position + 12; a++)
                        {
                            htmlfile[a] = rep[a - position];
                        }
                    }
                }
            }
        }

        for (i = 0; i < MAQUINAS; i++)
        {
            for (i2 = 0; i2 < TIMESLOTS; i2++)
            {
                if (escalation[i][i2].operation == 0)
                {
                    strcpy(sea, "");
                    strcat(sea, "#");
                    itoa((i + 1), st1, 10);
                    strcat(sea, st1);
                    strcat(sea, ".");
                    if (i2 < 10) strcat(sea, "0");
                    itoa((i2), st2, 10);
                    strcat(sea, st2);
                    strcat(sea, "<br>OPX");
                    ptr = strstr(htmlfile, sea);
                    position = (int)(htmlfile - ptr) * -1;
                    if (ptr)
                    {
                        for (a = position; a < position + 4; a++)
                        {
                            htmlfile[a] = 32;
                        }
                        htmlfile[a + 0] = 60;
                        htmlfile[a + 1] = 98;
                        htmlfile[a + 2] = 114;
                        htmlfile[a + 3] = 62;
                        htmlfile[a + 4] = 60;
                        htmlfile[a + 5] = 98;
                        htmlfile[a + 6] = 114;
                        htmlfile[a + 7] = 62;
                    }
                }

            }
        }

        FILE* fhtml;

        fhtml = fopen("teste.html", "wt");
        fprintf(fhtml, "%s\n", htmlfile);
        fclose(fhtml);

}

#pragma endregion
