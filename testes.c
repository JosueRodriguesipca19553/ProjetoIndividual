/**
* author: Josué - Aluno 19553
* email: a19553@alunos.ipca.pt
* date: 31-03-2022
* desc: Main
*/

#pragma once

#pragma warning( disable : 4996 )
//Evita a utilização do _CRT_SECURE_NO_WARNINGS, desactiva avisos de segurança na compilação

#pragma region Includes
#include "Definitions.h"
#pragma endregion


#pragma region Testes
/***********************************************************************************************************************************************************************/
bool test_add_list()
{
    // Teste adiciona item na lista 

    bool pass = false;

    Operations_Table* table_operations_table = NULL;
    table_operations_table = loadOperation_table(table_operations_table);

    table_operations_table = newoperation(table_operations_table, 99, "TESTE", 0);

    while (table_operations_table != NULL)
    {
        if (table_operations_table->codigo == 99)
        {
            pass = true;
        }
        table_operations_table = table_operations_table->next_operation;
    }
    free(table_operations_table);
    return pass;

}
/***********************************************************************************************************************************************************************/
bool test_add_list_middle()
{
    // Teste adiciona item a meio da lista 

    bool pass = false;

    Operations_Table* table_operations_table = NULL;
    table_operations_table = loadOperation_table(table_operations_table);

    table_operations_table = newoperation(table_operations_table, 99, "TESTE", 0);
    table_operations_table = newoperation(table_operations_table, 98, "TESTE", 1);

    while (table_operations_table != NULL)
    {
        if (table_operations_table->codigo == 98)
        {
            pass = true;
        }
        table_operations_table = table_operations_table->next_operation;
    }
    free(table_operations_table);
    return pass;

}
/***********************************************************************************************************************************************************************/
bool test_alt_list()
{
    // Teste adiciona item na lista 

    bool pass = false;

    Operations_Table* table_operations_table = NULL;
    table_operations_table = loadOperation_table(table_operations_table);

    table_operations_table = newoperation(table_operations_table, 99, "TESTE", 0);
    table_operations_table = newoperation(table_operations_table, 98, "TESTE", 1);
    table_operations_table = changeoperation(table_operations_table, 99, "ALTERADO");

    while (table_operations_table != NULL) {
        if (table_operations_table->codigo == 99)
        {
            if (strcmp(table_operations_table->descricao, "ALTERADO") == 0)
            {
                pass = true;
            }
        }
        table_operations_table = table_operations_table->next_operation;
    }
    free(table_operations_table);
    return pass;

}
/***********************************************************************************************************************************************************************/
bool test_delete_list_middle()
{
    // Teste adiciona item na lista 

    bool pass = true;

    Operations_Table* table_operations_table = NULL;
    table_operations_table = loadOperation_table(table_operations_table);

    table_operations_table = newoperation(table_operations_table, 99, "TESTE", 0);
    table_operations_table = newoperation(table_operations_table, 98, "TESTE", 1);
    table_operations_table = removeoperation(table_operations_table, 98);

    while (table_operations_table != NULL) {
        if (table_operations_table->codigo == 98)
        {
            pass = false;
        }
        table_operations_table = table_operations_table->next_operation;
    }
    free(table_operations_table);
    return pass;

}
/***********************************************************************************************************************************************************************/
bool test_delete_list()
{
    // Teste adiciona item na lista 

    bool pass = true;

    Operations_Table* table_operations_table = NULL;
    table_operations_table = loadOperation_table(table_operations_table);

    table_operations_table = newoperation(table_operations_table, 99, "TESTE", 0);
    table_operations_table = removeoperation(table_operations_table, 99);

    while (table_operations_table != NULL) {
        if (table_operations_table->codigo == 99)
        {
            pass = false;
        }
        table_operations_table = table_operations_table->next_operation;
    }
    free(table_operations_table);
    return pass;

}
/***********************************************************************************************************************************************************************/
bool test_valormin()
{
    char* cptr;
    bool pass = false;
    char resultado[10000];

    Process* grid = NULL;
    grid = Load_Grid();

    strcpy(resultado, view_min_job(grid, "PF1.1", resultado));
    cptr = strstr(resultado, "Tempo Total:");

    if (strcmp(cptr, "Tempo Total:17\n") == 0)
    {
        pass = true;
    }

    return pass;
}
/***********************************************************************************************************************************************************************/
bool test_valormax()
{
    char* cptr;
    bool pass = false;
    char resultado[10000];

    Process* grid = NULL;
    grid = Load_Grid();

    strcpy(resultado, view_max_job(grid, "PF6.3", resultado));
    cptr = strstr(resultado, "Tempo Total:");

    if (strcmp(cptr, "Tempo Total:23\n") == 0)
    {
        pass = true;
    }

    return pass;
}
/***********************************************************************************************************************************************************************/
bool test_valormedio()
{
    char* cptr;
    bool pass = false;
    char resultado[10000];

    Process* grid = NULL;
    grid = Load_Grid();

    strcpy(resultado, view_avg_job(grid, "PF7.2", resultado));
    cptr = strstr(resultado, "Total Average :");

    if (strcmp(cptr, "Total Average :4,2\n") == 0)
    {
        pass = true;
    }

    return pass;
}
/***********************************************************************************************************************************************************************/
int UnitTests()
{
    bool pass = false;
    /********************************************************************************************/
    pass = test_add_list();
    if (pass == true) { printf("Teste adiciona item lista - PASS\n"); }
    else { printf("Teste adiciona item lista - NOT PASS\n"); }
    /********************************************************************************************/
    pass = test_add_list_middle();
    if (pass == true) { printf("Teste adiciona item no meio da lista - PASS\n"); }
    else { printf("Teste adiciona item no meio da lista - NOT PASS\n"); }
    /********************************************************************************************/
    pass = test_alt_list();
    if (pass == true) { printf("Teste altera item na lista - PASS\n"); }
    else { printf("Teste altera item na lista - NOT PASS\n"); }
    /********************************************************************************************/
    pass = test_delete_list_middle();
    if (pass == true) { printf("Teste remove item no meio da lista - PASS\n"); }
    else { printf("Teste remove item no meio da lista - NOT PASS\n"); }
    /********************************************************************************************/
    pass = test_delete_list();
    if (pass == true) { printf("Teste remove item na lista - PASS\n"); }
    else { printf("Teste remove item na lista - NOT PASS\n"); }
    /********************************************************************************************/
    pass = test_valormin();
    if (pass == true) { printf("Teste valor min- PASS\n"); }
    else { printf("Teste valor min - NOT PASS\n"); }
    /********************************************************************************************/
    pass = test_valormax();
    if (pass == true) { printf("Teste valor max - PASS\n"); }
    else { printf("Teste valor max - NOT PASS\n"); }
    /********************************************************************************************/
    pass = test_valormedio();
    if (pass == true) { printf("Teste valor medio - PASS\n"); }
    else { printf("Teste valor medio - NOT PASS\n"); }
    /********************************************************************************************/

    printf("\n");
    printf("\n");
    printf("\n");

    return 1;
}

#pragma endregion