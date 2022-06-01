/**
* author: Josué - Aluno 19553
* email: a19553@alunos.ipca.pt
* date: 31-05-2022
* desc: Modulo de Testes Unitários
*/

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
    int min;
    bool pass = false;
    

    Process* grid = NULL;
    grid = Load_Grid();

    min = min_operation(grid, "PF1.1", 1);
    if (min == 4) pass = true;

    return pass;
}
/***********************************************************************************************************************************************************************/
bool test_valormax()
{
    int max;
    bool pass = false;
    
    Process* grid = NULL;
    grid = Load_Grid();

    max = max_operation(grid, "PF1.1", 1);
    if (max == 5) pass = true;

    return pass;
}
/***********************************************************************************************************************************************************************/
bool test_valormedio()
{
    float avg;
    bool pass = false;
    
    Process* grid = NULL;
    grid = Load_Grid();

    avg = avg_operation(grid, "PF1.1", 1);
    if (avg == 4,97)pass = true;

    return pass;
}
/***********************************************************************************************************************************************************************/
int UnitTests()
{
    bool pass = false;
    /********************************************************************************************/
    pass = test_add_list();
    if (pass == true) { printf("OK - Teste adiciona item lista\n"); }
    else { printf("KO - Teste adiciona item lista\n"); }
    /********************************************************************************************/
    pass = test_add_list_middle();
    if (pass == true) { printf("OK - Teste adiciona item no meio da lista\n"); }
    else { printf("KO - Teste adiciona item no meio da lista\n"); }
    /********************************************************************************************/
    pass = test_alt_list();
    if (pass == true) { printf("OK - Teste altera item na lista\n"); }
    else { printf("KO - Teste altera item na lista\n"); }
    /********************************************************************************************/
    pass = test_delete_list_middle();
    if (pass == true) { printf("OK - Teste remove item no meio da lista\n"); }
    else { printf("KO - Teste remove item no meio da lista\n"); }
    /********************************************************************************************/
    pass = test_delete_list();
    if (pass == true) { printf("OK - Teste remove item na lista\n"); }
    else { printf("KO - Teste remove item na lista\n"); }
    /********************************************************************************************/
    pass = test_valormin();
    if (pass == true) { printf("OK - Teste valor min\n"); }
    else { printf("KO - Teste valor min\n"); }
    /********************************************************************************************/
    pass = test_valormax();
    if (pass == true) { printf("OK - Teste valor max\n"); }
    else { printf("KO - Teste valor max\n"); }
    /********************************************************************************************/
    pass = test_valormedio();
    if (pass == true) { printf("OK - Teste valor medio\n"); }
    else { printf("KO - Teste valor medio\n"); }
    /********************************************************************************************/

    printf("\n");
    printf("\n");
    printf("\n");

    return 1;
}

#pragma endregion