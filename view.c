/**
* author: Josué - Aluno 19553
* email: a19553@alunos.ipca.pt
* date: 31-05-2022
* desc: Views
*/

#pragma warning( disable : 4996 )
//Evita a utilização do _CRT_SECURE_NO_WARNINGS, desactiva avisos de segurança na compilação

#pragma region Includes
#include "Definitions.h"
#pragma endregion


#pragma region Funções_View_Jobs_(OLD)
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
	/*int valor = 0;
	int min = 0;

	Process* jb_temp = grid;
	while (jb_temp != NULL) 
	{
		if (strcmp(jb_temp->codigo,job)==0)
		{

			Operation* op_temp = jb_temp->operacao;
			while (op_temp != NULL) 
			{
				Bin_Machine* ma_temp = op_temp->machine;
				min = 0;
				while (ma_temp != NULL)
				{
					if (ma_temp->tempo < min)
					{
						min = ma_temp->tempo;
						
					}

					ma_temp = ma_temp->next_machine;
				}
				valor = valor + min;
				op_temp = op_temp->next_operation;
			}
		}
		jb_temp = jb_temp->next_job;
	}*/

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

	/*int valor = 0;
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
	}*/



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

	/*char res_fun[50];
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
	}*/

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
	
	return NULL;
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

	return NULL;
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
	return NULL;
}

#pragma endregion

#pragma region Funções_View_Jobs_(NEW)_Binary_Tree

/**
* @brief Função Devolve o tempo minimo numa operação percorrendo a arvore Binária 
* @param [Struct] Processo grid
* @param [char] Processo
* @param [int] Opertação
* @return [int] Valor Minimo
*/
int min_operation(Process* grid, char* job, int operation)
{

	int min = 0;

	Process* aux_jb = grid;
	while (strcmp(aux_jb->codigo, job) != 0)
	{
		aux_jb = aux_jb->next_job;
	}
	Operation* aux_op = aux_jb->operacao;
	while (aux_op->codigo != operation)
	{
		aux_op = aux_op->next_operation;
	}

	min = getlessmachinetime(aux_op->machine, min);

	
	return min;
}
/**
* @brief Função Devolve o tempo maximo numa operação percorrendo a arvore Binária
* @param [Struct] Processo grid
* @param [char] Processo
* @param [int] Opertação
* @return [int] Valor Maximo
*/
int max_operation(Process* grid, char* job, int operation)
{

	int max = 0;

	Process* aux_jb = grid;
	while (strcmp(aux_jb->codigo, job) != 0)
	{
		aux_jb = aux_jb->next_job;
	}
	Operation* aux_op = aux_jb->operacao;
	while (aux_op->codigo != operation)
	{
		aux_op = aux_op->next_operation;
	}

	max = getmoremachinetime(aux_op->machine, max);


	return max;
}
/**
* @brief Função recursiva para percorrer a arvore binaria ( menor )
* @param [Struct] Bin_Machine
* @param [int]
* @return Valor minimo de cada nó que encontra na arvore binaria
*/
int getlessmachinetime(Bin_Machine* machine, int min)
{

	int time = machine->tempo;

	if (machine->binmachine_less != NULL)
	{
		time = getlessmachinetime(machine->binmachine_less,time);
	}

	if (machine->binmachine_less != NULL)
	{
		time = getlessmachinetime(machine->binmachine_more, time);
	}

	if (min > time || min == 0 )
	{
		min = time;
	}

	return min;

}
/**
* @brief Função recursiva para percorrer a arvore binaria ( maior )
* @param [Struct] Bin_Machine
* @param [int]
* @return Valor maximo de cada nó que encontra na arvore binaria
*/
int getmoremachinetime(Bin_Machine* machine, int max)
{

	int time = machine->tempo;

	if (machine->binmachine_less != NULL)
	{
		time = getmoremachinetime(machine->binmachine_less, time);
	}

	if (machine->binmachine_less != NULL)
	{
		time = getmoremachinetime(machine->binmachine_more, time);
	}

	if (max < time || max == 0)
	{
		max = time;
	}

	return max;

}
/**
* @brief Função Devolve o tempo medio numa operação percorrendo a arvore Binária
* @param [Struct] Processo grid
* @param [char] Processo
* @param [int] Opertação
* @return [int] Valor Medio
*/
float avg_operation(Process* grid, char* job, int operation)
{

	float avg = 0;

	Process* aux_jb = grid;
	while (strcmp(aux_jb->codigo, job) != 0)
	{
		aux_jb = aux_jb->next_job;
	}
	Operation* aux_op = aux_jb->operacao;
	while (aux_op->codigo != operation)
	{
		aux_op = aux_op->next_operation;
	}

 	Bin_Machine* tree = aux_op->machine;
	avg = (float)tree->tempo;
	avg = getavgmachinetime(aux_op->machine, avg);

	return avg;
}

/**
* @brief Função recursiva para percorrer a arvore binaria ( media )
* @param [Struct] Bin_Machine
* @param [int]
* @return Valor medio de cada nó que encontra na arvore binaria
*/
float getavgmachinetime(Bin_Machine* machine, float avg)
{

	float time = (float)machine->tempo;

	if (machine->binmachine_less != NULL)
	{
		time = getavgmachinetime(machine->binmachine_less, time);
	}

	if (machine->binmachine_less != NULL)
	{
		time = getavgmachinetime(machine->binmachine_more, time);
	}

	avg = (avg + time) / 2;

	return avg;

}

#pragma endregion
