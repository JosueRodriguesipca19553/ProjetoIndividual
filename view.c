/*
* author: Josué - Aluno 19553
* email: a19553@alunos.ipca.pt
* date: 31-03-2022
* desc: Views
*/

#pragma once

#pragma region Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "DataStructure.h"
#pragma endregion

#pragma region Assinaturas
char* get_desc_processplan(char* job);
char* get_desc_operation(int codigo);
char* get_desc_machine(int codigo);
#pragma endregion

#pragma region Funções_View_Jobs
/**
* @brief Determinar quantidade minima de tempo para completar um job 
*        a função vai mostrar o job, as operações escolhidas e as maquinas com o valor minimo
* @param [St]   Grid      : Grelha de processos
* @param [Char] Processo  : Processo a listar
* @param [Char] Resultado : Variavel do tipo String para receber o texto formatado
* @return String com o resultado já formatado
*/
char* view_min_job(Process* grid, char* job, char* resultado)
{

	int valor = 0;
	int min = 99;
	char res_fun[50];
	char res_tmp_pln[50];
	char res_tmp_opr[50];
	char res_tmp_mch[50];
	char cod[10];
	char tmp_resultado[1000];
	strcpy(res_fun, "");
	strcpy(cod, "");
	strcpy(resultado, "Quantidade minima para completar um job.\n");
	strcpy(res_tmp_pln, "ProcessPlan :");
	strcpy(res_tmp_opr, "  Operation :");
	strcpy(res_tmp_mch, "    Machine :");
	Process* jb_temp = grid;
	while (jb_temp != NULL) 
	{
		if (strcmp(jb_temp->codigo,job)==0)
		{
			strcpy(cod, "");
			strcat(cod, job);
			strcat(cod, " - ");
			strcat(res_tmp_pln, cod);
			strcpy(res_fun , get_desc_processplan(job));
			strcat(res_tmp_pln, res_fun);
			strcat(resultado, res_tmp_pln);
			strcat(resultado, "\n");
			Operation* op_temp = jb_temp->operacao;
			while (op_temp != NULL) 
			{
				strcpy(res_tmp_opr, "  Operation :");
				strcpy(cod, "");
				strcpy(res_fun, "");
				strcpy(res_fun, get_desc_operation(op_temp->codigo));
				itoa(op_temp->codigo, cod, 10);
				strcat(cod, " - ");
				strcat(res_tmp_opr, cod);
				strcat(res_tmp_opr, res_fun);
				strcat(resultado, res_tmp_opr);
				strcat(resultado, "\n");
				Machine* ma_temp = op_temp->machine;
				min = 99;
				while (ma_temp != NULL)
				{
					if (ma_temp->tempo < min)
					{
						min = ma_temp->tempo;
						strcpy(tmp_resultado, "");
						strcpy(res_tmp_mch, "    Machine :");
						strcpy(cod, "");
						strcpy(res_fun, "");
						strcpy(res_fun, get_desc_machine(ma_temp->codigo));
						itoa(ma_temp->codigo, cod, 10);
						strcat(cod, " - ");
						strcat(res_tmp_mch, cod);
						strcat(res_tmp_mch, res_fun);
						strcpy(cod, "");
						itoa( ma_temp->tempo, cod, 10);
						strcat(cod, " ) ");
						strcat(res_tmp_mch, " ( ");
						strcat(res_tmp_mch, cod);
						strcat(tmp_resultado, res_tmp_mch);
						strcat(tmp_resultado, "\n");
					}
					ma_temp = ma_temp->next_machine;
				}
				strcat(resultado, tmp_resultado);
				valor = valor + min;
				op_temp = op_temp->next_operation;
			}
			itoa(valor, cod, 10);
			strcat(resultado, "\nTempo Total:");
			strcat(resultado, cod);
			strcat(resultado, "\n");
		}
		jb_temp = jb_temp->next_job;
	}

	return resultado;
}

/**
* @brief Determinar quantidade maxima de tempo para completar um job
*        a função vai mostrar o job, as operações escolhidas e as maquinas com o valor minimo
* @param [St]   Grid      : Grelha de processos
* @param [Char] Processo  : Processo a listar
* @param [Char] Resultado : Variavel do tipo String para receber o texto formatado
* @return String com o resultado já formatado
*/
char* view_max_job(Process* grid, char* job, char* resultado)
{

	int valor = 0;
	int max = 0;
	char res_fun[50];
	char res_tmp_pln[50];
	char res_tmp_opr[50];
	char res_tmp_mch[50];
	char cod[10];
	char tmp_resultado[1000];
	strcpy(res_fun, "");
	strcpy(cod, "");
	strcpy(resultado, "Quantidade maxima para completar um job.\n");
	strcpy(res_tmp_pln, "ProcessPlan :");
	strcpy(res_tmp_opr, "  Operation :");
	strcpy(res_tmp_mch, "    Machine :");
	Process* jb_temp = grid;
	while (jb_temp != NULL)
	{
		if (strcmp(jb_temp->codigo, job) == 0)
		{
			strcpy(cod, "");
			strcat(cod, job);
			strcat(cod, " - ");
			strcat(res_tmp_pln, cod);
			strcpy(res_fun, get_desc_processplan(job));
			strcat(res_tmp_pln, res_fun);
			strcat(resultado, res_tmp_pln);
			strcat(resultado, "\n");
			Operation* op_temp = jb_temp->operacao;
			while (op_temp != NULL)
			{
				strcpy(res_tmp_opr, "  Operation :");
				strcpy(cod, "");
				strcpy(res_fun, "");
				strcpy(res_fun, get_desc_operation(op_temp->codigo));
				itoa(op_temp->codigo, cod, 10);
				strcat(cod, " - ");
				strcat(res_tmp_opr, cod);
				strcat(res_tmp_opr, res_fun);
				strcat(resultado, res_tmp_opr);
				strcat(resultado, "\n");
				Machine* ma_temp = op_temp->machine;
				max = 0;
				while (ma_temp != NULL)
				{
					if (ma_temp->tempo > max)
					{
						max = ma_temp->tempo;
						strcpy(tmp_resultado, "");
						strcpy(res_tmp_mch, "    Machine :");
						strcpy(cod, "");
						strcpy(res_fun, "");
						strcpy(res_fun, get_desc_machine(ma_temp->codigo));
						itoa(ma_temp->codigo, cod, 10);
						strcat(cod, " - ");
						strcat(res_tmp_mch, cod);
						strcat(res_tmp_mch, res_fun);
						strcpy(cod, "");
						itoa(ma_temp->tempo, cod, 10);
						strcat(cod, " ) ");
						strcat(res_tmp_mch, " ( ");
						strcat(res_tmp_mch, cod);
						strcat(tmp_resultado, res_tmp_mch);
						strcat(tmp_resultado, "\n");
					}
					ma_temp = ma_temp->next_machine;
				}
				strcat(resultado, tmp_resultado);
				valor = valor + max;
				op_temp = op_temp->next_operation;
			}
			itoa(valor, cod, 10);
			strcat(resultado, "\nTempo Total:");
			strcat(resultado, cod);
			strcat(resultado, "\n");
		}
		

		jb_temp = jb_temp->next_job;
	}



	return resultado;
}

/**
* @brief Determinar quantidade media de tempo para completar um job
*        a função vai mostrar o job, as operações escolhidas e as maquinas com o valor minimo
* @param [St]   Grid      : Grelha de processos
* @param [Char] Processo  : Processo a listar
* @param [Char] Resultado : Variavel do tipo String para receber o texto formatado
* @return String com o resultado já formatado
*/
char* view_avg_job(Process* grid, char* job, char* resultado)
{

	char res_fun[50];
	char res_tmp_pln[90];
	char res_tmp_opr[90];
	char res_tmp_mch[90];
	char cod[10];
	float num=0;
	float valor = 0;
	float num_total = 0;
	float valor_total = 0;
	strcpy(res_fun, "");
	strcpy(cod, "");
	strcpy(resultado, "Quantidade media para completar um job.\n");
	strcpy(res_tmp_pln, "ProcessPlan :");
	strcpy(res_tmp_opr, "  Operation :");
	strcpy(res_tmp_mch, "    Machine :");
	Process* jb_temp = grid;
	while (jb_temp != NULL)
	{
		if (strcmp(jb_temp->codigo, job) == 0)
		{
			strcpy(cod, "");
			strcat(cod, job);
			strcat(cod, " - ");
			strcat(res_tmp_pln, cod);
			strcpy(res_fun, get_desc_processplan(job));
			strcat(res_tmp_pln, res_fun);
			strcat(resultado, res_tmp_pln);
			strcat(resultado, "\n");
			Operation* op_temp = jb_temp->operacao;
			while (op_temp != NULL)
			{
				strcpy(res_tmp_opr, "  Operation :");
				strcpy(cod, "");
				strcpy(res_fun, "");
				strcpy(res_fun, get_desc_operation(op_temp->codigo));
				itoa(op_temp->codigo, cod, 10);
				strcat(cod, " - ");
				strcat(res_tmp_opr, cod);
				strcat(res_tmp_opr, res_fun);
				strcat(resultado, res_tmp_opr);
				strcat(resultado, "\n");
				Machine* ma_temp = op_temp->machine;
				valor = 0;
				num = 0;
				while (ma_temp != NULL)
				{
					num++;
					num_total++;
					valor = valor + ma_temp->tempo;
					valor_total = valor_total + ma_temp->tempo;
					ma_temp = ma_temp->next_machine;
				}
				strcpy(res_tmp_mch, "    Machines:");
				gcvt(num, 3,cod);
				strcat(res_tmp_mch, cod);
				strcat(res_tmp_mch, "\n");
				strcat(res_tmp_mch, "    Average :");
				gcvt((valor/num),3 ,cod);
				strcat(res_tmp_mch, cod);
				strcat(res_tmp_mch, "\n");
				strcat(resultado, res_tmp_mch);
				op_temp = op_temp->next_operation;
			}
			strcat(res_tmp_mch, "\n");
			strcat(res_tmp_mch, "Total Machines:");
			gcvt(num_total, 3, cod);
			strcat(res_tmp_mch, cod);
			strcat(res_tmp_mch, "\n");
			strcat(res_tmp_mch, "Total Average :");
			gcvt((valor_total / num_total), 3, cod);
			strcat(res_tmp_mch, cod);
			strcat(res_tmp_mch, "\n");
			strcat(resultado, res_tmp_mch);

		}
		jb_temp = jb_temp->next_job;
	}

	return resultado;
}

/**
* @brief Função que devolve a descricao de um determinado Processo
* @param [Char] Codigo : Codigo do processo a pesquisar
* @return Descrição do processo
*/
char* get_desc_processplan(char* job)
{
	ProcessPlan_Table* table_process_plan_table = NULL;
	table_process_plan_table = loadProcessPlan_table(table_process_plan_table);

	while (table_process_plan_table != NULL)
	{
		if (strcmp(table_process_plan_table->codigo, job) == 0)
		{
			return table_process_plan_table->descricao;
		}
		table_process_plan_table = table_process_plan_table->next_process;
	}
	
	return"N/A";
}
/**
* @brief Função que devolve a descricao de um determinada operação
* @param [Char] Codigo : Codigo da operação a pesquisar
* @return Descrição da operação
*/
char* get_desc_operation(int codigo)
{ 
	Operations_Table* table_operations_table = NULL;
	table_operations_table = loadOperation_table(table_operations_table);

	while (table_operations_table != NULL)
	{
		if (table_operations_table->codigo==codigo)
		{
			return table_operations_table->descricao;
		}
		table_operations_table = table_operations_table->next_operation;
	}

	return""; 
}
/**
* @brief Função que devolve a descricao de uma determinada maquina
* @param [Char] Codigo : Codigo da maquina a pesquisar
* @return Descrição da maquina
*/
char* get_desc_machine(int codigo)
{ 
	char typem[50];
	strcpy(typem,"(");
	Machine_Table* table_machine = NULL;
	table_machine = loadMachine_table(table_machine);

	while (table_machine != NULL)
	{
		if (table_machine->codigo == codigo)
		{
			Machine_Type* table_machine_type = NULL;
			table_machine_type = loadMachine_type_table(table_machine_type);

			while (table_machine_type != NULL)
			{
				if (table_machine_type->codigo == table_machine->machinetype)
				{
					strcat(typem, strcat(table_machine_type->descricao,")"));
				}
				table_machine_type = table_machine_type->next_type;
			}
			return strcat(table_machine->descricao, typem);
		}
		table_machine = table_machine->next_machine;
	}
	return""; 
}

#pragma endregion