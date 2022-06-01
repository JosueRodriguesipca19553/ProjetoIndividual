/**
* author: Josué - Aluno 19553
* email: a19553@alunos.ipca.pt
* date: 31-05-2022
* desc: Projecto Individual EDA - IPCA LESI 1ºANO - PL
*/

#pragma warning( disable : 4996 )
//Evita a utilização do _CRT_SECURE_NO_WARNINGS, desactiva avisos de segurança na compilação

#include "Definitions.h"

 int main()
{
    setlocale(LC_ALL, "Portuguese");

    initvar();

    //UnitTests();

    Process* grid= NULL;
    grid = Load_Grid();

    schedule_job_operation(grid, "PF1.1", 1);
    schedule_job_operation(grid, "PF1.1", 2);
    schedule_job_operation(grid, "PF1.1", 3);
    schedule_job_operation(grid, "PF1.1", 4);

    schedule_job_operation(grid, "PF2.2", 1);
    schedule_job_operation(grid, "PF2.2", 2);
    schedule_job_operation(grid, "PF2.2", 3);
    schedule_job_operation(grid, "PF2.2", 4);


    listagens(grid);

    create_process_plan();

    free(grid);

    return 1;
}



