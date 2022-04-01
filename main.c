/*
* author: Josu� - Aluno 19553
* email: a19553@alunos.ipca.pt
* date: 31-03-2022
* desc: Main
*/

#pragma warning( disable : 4996 )
//Evita a utiliza��o do _CRT_SECURE_NO_WARNINGS, desactiva avisos de seguran�a na compila��o

#pragma region Includes
#include "model.c"
#include "view.c"
#include "controller.c"
#include "DataStructure.h"
#include <locale.h>
#pragma endregion

#pragma region Assinaturas
int listagens();
#pragma endregion

int main()
{
    setlocale(LC_ALL, "Portuguese");

/**
* Na Ponto 3,4 e 5 do enunciado pede para  :
* 3. Inser��o de uma nova opera��o;
* 4. Remo��o de uma determinada opera��o;
* 5. Altera��o de uma determinada opera��o;
* 
* Na tabela de opera��es vamos :
* 3. Inserir uma opera��o nova no fim da lista com o codigo 99 e descri��o TESTE
*    Inserir uma opera��o nova ordenada ( anterior ao codigo 99 ) com o codigo 98 e descri��o TESTE
* 5. Alterar o nome da descri��o da opera��o 99 para ALTERADO
* 4. Remover a opera��o a opera��o 98 ( no meio da lista )
*    Remover a opera��o a opera��o 99 ( no fim da lista )
* 
**/

    //
    // Inserir nova opera��o no fim da lista e outra imediatamente antes
    // Altera a ultima descri��o
    // Remove os itens criados, primeiro uma opera��o no meio da lista e depois a ultima
    //

    Operations_Table* table_operations_table = NULL;
    table_operations_table = loadOperation_table(table_operations_table);

    table_operations_table = newoperation(table_operations_table, 99, "TESTE", 0);
    table_operations_table = newoperation(table_operations_table, 98, "TESTE", 1);
    table_operations_table = changeoperation(table_operations_table, 99, "ALTERADO");
    table_operations_table = removeoperation(table_operations_table, 98);
    table_operations_table = removeoperation(table_operations_table, 99);

/**
* Carregamento da grelha para responder ao ponto 1 e 2 do enunciado:
* 1. Defini��o de uma estrutura de dados din�mica para a representa��o de um job com um conjunto finito de n opera��es;
* 2. Armazenamento/leitura de ficheiro de texto com representa��o de um job;
* 
* 
*/

    Process* grid= NULL;
    grid = Load_Grid();

/**
* Listagens para para responder ao ponto 6,7 e 8 do enunciado:
* 6. Determina��o da quantidade m�nima de unidades de tempo necess�rias para completar o job e listagem das respetivas opera��es;
* 7. Determina��o da quantidade m�xima de unidades de tempo necess�rias para completar o job e listagem das respetivas opera��es;
* 8. Determina��o da quantidade m�dia de unidades de tempo necess�rias para completar uma opera��o, considerando todas as alternativas poss�veis;*
*
*/

    listagens(grid);

/**
* Libertar memoria
*
*/
    free(table_operations_table);
    free(grid);

    return 1;
}
/**
* @brief Listagem das opera��es do enunciado
* @return [String] Resultado
*/
int listagens(Process* grid)
{
    
    char resultado[1000];

    //
    // Determinar quantidade minima para completar um job (2 exemplos)
    // a fun��o vai mostrar o job, as opera��es escolhidas e as maquinas com o valor minimo
    //

    strcpy(resultado, "");
    strcpy(resultado, view_min_job(grid,"PF1.1",resultado));
    printf("%s\n\n", resultado);

    strcpy(resultado, "");
    strcpy(resultado, view_min_job(grid, "PF2.2", resultado));
    printf("%s\n\n", resultado);

    //
    // Determinar quantidade maxima para completar um job (2 exemplos)
    // a fun��o vai mostrar o job, as opera��es escolhidas e as maquinas com o valor maxima
    //

    strcpy(resultado, "");
    strcpy(resultado, view_max_job(grid, "PF6.3", resultado));
    printf("%s\n\n", resultado);

    strcpy(resultado, "");
    strcpy(resultado, view_max_job(grid, "PF3.3", resultado));
    printf("%s\n\n", resultado);

    //
    // Determinar quantidade minima para completar um job (2 exemplos)
    // a fun��o vai mostrar o job, as opera��es escolhidas e a media de tempos de todas as maquinas
    //

    strcpy(resultado, "");
    strcpy(resultado, view_avg_job(grid, "PF7.2", resultado));
    printf("%s\n\n", resultado);

    strcpy(resultado, "");
    strcpy(resultado, view_avg_job(grid, "PF8.1", resultado));
    printf("%s\n\n", resultado);

    return 1;
}

