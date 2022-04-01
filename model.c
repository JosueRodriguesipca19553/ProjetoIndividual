/*
* author: Josué - Aluno 19553
* email: a19553@alunos.ipca.pt
* date: 31-03-2022
* desc: Modelo de Dados
*/

#pragma once

#pragma region Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "DataStructure.h"
#pragma endregion

#pragma region Funções_LOAD_Machine_Type_(Table)
/**
* @brief Função que verifica se determinado tipo de maquina já existe na lista se existir devolve TRUE se for o primeiro elemento da lista ou não existir devolve FALSE
* @param [St]   Table  : Apontador para a struct de Tipos de Maquina
* @param [Int]  Codigo : Codigo da maquina a verificar se existe
* @return (true) se existir, (false) se não existir
*/
bool exist_machine_type_table(Machine_Type* table, int codigo)
{
	if (table == NULL) return false;
	Machine_Type* aux = table;
	while (aux != NULL) 
	{
		if (aux->codigo== codigo) return true;
		aux = aux->next_type;
	}
	return false; 
}

/**
* @brief Função adiciona um novo tipo de maquina na lista ligada
* @param [St]   Table   : Grid que está a ser preenchida
* @param [St]   Registo : Registo com a nova tipo de maquina 
* @return Grid com o novo registo
*/
Machine_Type* add_record_machine_type_table(Machine_Type* table, Machine_Type* record)
{
	if (exist_machine_type_table(table, record->codigo)) return table;
	if (table == NULL) 
	{
		table = record;
	}
	else
	{
		Machine_Type* aux = table;
		while (aux->next_type != NULL) 
		{
			aux = aux->next_type;
		}
		aux->next_type = record;
	}
	return table;
}

/**
* @brief Função preenche o novo registo com o tipo de maquina 
* @param [Int]   Codigo    : Codigo do tipo de maquina
* @param [Char]  Descricao : Descrição do tipo de maquina
* @return Registo com o novo registo
*/
Machine_Type* load_record_machine_type_table(int codigo, char* descricao)
{
	Machine_Type* record = (Machine_Type*)malloc(sizeof(Machine_Type));

	if (record == NULL) return NULL;

	record->codigo = codigo;
	strcpy(record->descricao, descricao);
	record->next_type = NULL;

	return record;
}

/**
* @brief Função que carrega do ficheiro de texto a lista de tipos de maquinas
* @param [St]   Lista : Lista a ser preenchida com a informação do ficheiro
* @return Lista preenchida
*/
Machine_Type* loadMachine_type_table(Machine_Type* table_machine_type)
{

	char line[100];
	char* readline[2];
	const char separador[2] = ";";
	int i = 0;
	Machine_Type* record;

	FILE* fp;
	fp = fopen("machinetype.table", "rt");
	while (!feof(fp))
	{
		fgets(line, sizeof line, fp);
		readline[0] = strtok(line, separador); // Função para separar a string pelos pontos e virgulas
		readline[1] = strtok(NULL, separador);
		record = load_record_machine_type_table(atoi(readline[0]), readline[1]); // gera o registo
		table_machine_type= add_record_machine_type_table(table_machine_type,record); // adiciona o registo á lista
	}
	fclose(fp);

	return table_machine_type;

}
#pragma endregion

#pragma region Funções_LOAD_Machine_(Table)
/**
* @brief Função que verifica se determinada maquina já existe na lista se existir devolve TRUE se for o primeiro elemento da lista ou não existir devolve FALSE
* @param [St]   Table  : Apontador para a struct das Maquina
* @param [Int]  Codigo : Codigo da maquina a verificar se existe
* @return (true) se existir, (false) se não existir
*/
bool exist_machine_table(Machine_Table* table, int codigo)
{
	if (table == NULL) return false;
	Machine_Table* aux = table;
	while (aux != NULL)
	{
		if (aux->codigo == codigo) return true;
		aux = aux->next_machine;
	}
	return false;
}

/**
* @brief Função adiciona uma nova maquina na lista ligada
* @param [St]   Table   : Grid que está a ser preenchida
* @param [St]   Registo : Registo com a nova maquina
* @return Grid com o novo registo
*/
Machine_Table* add_record_machine_table(Machine_Table* table, Machine_Table* record)
{
	if (exist_machine_table(table, record->codigo)) return table;
	if (table == NULL)
	{
		table = record;
	}
	else
	{
		Machine_Table* aux = table;
		while (aux->next_machine != NULL)
		{
			aux = aux->next_machine;
		}
		aux->next_machine = record;
	}
	return table;
}

/**
* @brief Função preenche o novo registo com a informação da maquina
* @param [Int]   Codigo    : Codigo da maquina
* @param [Char]  Descricao : Descrição da maquina
* @return Registo com o novo registo
*/
Machine_Table* load_record_machine_table(int codigo, char* descricao, int type)
{
	Machine_Table* record = (Machine_Table*)malloc(sizeof(Machine_Table));

	if (record == NULL) return NULL;

	record->codigo = codigo;
	strcpy(record->descricao, descricao);
	record->machinetype = type;
	record->next_machine = NULL;

	return record;
}

/**
* @brief Função que carrega do ficheiro de texto a lista de maquinas
* @param [St]   Lista : Lista a ser preenchida com a informação do ficheiro
* @return Lista preenchida
*/
Machine_Table* loadMachine_table(Machine_Table* table_machine)
{

	char line[100];
	char* readline[3];
	const char separador[2] = ";";
	int i = 0;
	Machine_Table* record;

	FILE* fp;
	fp = fopen("machine.table", "rt");
	while (!feof(fp))
	{
		fgets(line, sizeof line, fp);
		readline[0] = strtok(line, separador); // Função para separar a string pelos pontos e virgulas
		readline[1] = strtok(NULL, separador);
		readline[2] = strtok(NULL, separador);
		record = load_record_machine_table(atoi(readline[0]), readline[1], atoi(readline[2])); // gera o registo
		table_machine = add_record_machine_table(table_machine, record); // adiciona o registo á lista
	}
	fclose(fp);

	return table_machine;

}


#pragma endregion

#pragma region Funções_LOAD_Operations_(Table)
/**
* @brief Função que verifica se determinado Operação já existe na lista se existir devolve TRUE se for o primeiro elemento da lista ou não existir devolve FALSE
* @param [St]   Table  : Apontador para a struct de Operações
* @param [Int]  Codigo : Codigo da operação a verificar se existe
* @return (true) se existir, (false) se não existir
*/
bool exist_operation_table(Operations_Table* table, int codigo)
{
	if (table == NULL) return false;
	Operations_Table* aux = table;
	while (aux != NULL)
	{
		if (aux->codigo == codigo) return true;
		aux = aux->next_operation;
	}
	return false;
}

/**
* @brief Função adiciona uma nova operação na lista ligada
* @param [St]   Table   : Grid que está a ser preenchida
* @param [St]   Registo : Registo com a nova operação
* @return Grid com o novo registo
*/
Operations_Table* add_record_operation_table(Operations_Table* table, Operations_Table* record)
{
	if (exist_operation_table(table, record->codigo)) return table;
	if (table == NULL)
	{
		table = record;
	}
	else
	{
		Operations_Table* aux = table;
		while (aux->next_operation != NULL)
		{
			aux = aux->next_operation;
		}
		aux->next_operation = record;
	}
	return table;
}

/**
* @brief Função preenche o novo registo com a informação da operação
* @param [Int]   Codigo    : Codigo da operação
* @param [Char]  Descricao : Descrição da operação
* @return Registo com o novo registo
*/
Operations_Table* load_record_operation_table(int codigo, char* descricao)
{
	Operations_Table* record = (Operations_Table*)malloc(sizeof(Operations_Table));

	if (record == NULL) return NULL;

	record->codigo = codigo;
	strcpy(record->descricao, descricao);
	record->next_operation = NULL;

	return record;
}
/**
* @brief Função que carrega do ficheiro de texto a lista de operaçoes
* @param [St]   Lista : Lista a ser preenchida com a informação do ficheiro
* @return Lista preenchida
*/
Operations_Table* loadOperation_table(Operations_Table* table_operations_table)
{

	char line[100];
	char* readline[2];
	const char separador[2] = ";";
	int i = 0;
	Operations_Table* record;

	FILE* fp;
	fp = fopen("operations.table", "rt");
	while (!feof(fp))
	{
		fgets(line, sizeof line, fp);
		readline[0] = strtok(line, separador); // Função para separar a string pelos pontos e virgulas
		readline[1] = strtok(NULL, separador);
		record = load_record_operation_table(atoi(readline[0]), readline[1]); // gera o registo
		table_operations_table = add_record_operation_table(table_operations_table, record); // adiciona o registo á lista
	}
	fclose(fp);

	return table_operations_table;

}
#pragma endregion

#pragma region Funções_LOAD_ProcessPlan_(Table)
/**
* @brief Função que verifica se determinado processo já existe na lista se existir devolve TRUE se for o primeiro elemento da lista ou não existir devolve FALSE
* @param [St]   Table  : Apontador para a struct de processos
* @param [Int]  Codigo : Codigo da processo a verificar se existe
* @return (true) se existir, (false) se não existir
*/
bool exist_processplan_table(ProcessPlan_Table* table, char* codigo)
{
	if (table == NULL) return false;
	ProcessPlan_Table* aux = table;
	while (aux != NULL)
	{
		if (strcmp(aux->codigo,codigo)==0 ) return true;
		aux = aux->next_process;
	}
	return false;
}

/**
* @brief Função adiciona um novo processo na lista ligada
* @param [St]   Table   : Grid que está a ser preenchida
* @param [St]   Registo : Registo com o novo processo
* @return Grid com o novo registo
*/
ProcessPlan_Table* add_record_processplan_table(ProcessPlan_Table* table, ProcessPlan_Table* record)
{
	if (exist_processplan_table(table, record->codigo)) return table;
	if (table == NULL)
	{
		table = record;
	}
	else
	{
		ProcessPlan_Table* aux = table;
		while (aux->next_process != NULL)
		{
			aux = aux->next_process;
		}
		aux->next_process = record;
	}
	return table;
}

/**
* @brief Função preenche o novo registo com a informação do processo
* @param [Int]   Codigo    : Codigo do processo
* @param [Char]  Descricao : Descrição do processo
* @return Registo com o novo registo
*/
ProcessPlan_Table* load_record_processplan_table(char* codigo, char* descricao)
{
	ProcessPlan_Table* record = (ProcessPlan_Table*)malloc(sizeof(ProcessPlan_Table));

	if (record == NULL) return NULL;

	strcpy(record->codigo, codigo);
	strcpy(record->descricao, descricao);
	record->next_process = NULL;

	return record;
}

/**
* @brief Função que carrega do ficheiro de texto a lista de processos (jobs)
* @param [St]   Lista : Lista a ser preenchida com a informação do ficheiro
* @return Lista preenchida
*/
ProcessPlan_Table* loadProcessPlan_table(ProcessPlan_Table* table_processplan_table)
{

	char line[100];
	char* readline[2];
	const char separador[2] = ";";
	int i = 0;
	ProcessPlan_Table* record;

	FILE* fp;
	fp = fopen("processplan.table", "rt");
	while (!feof(fp))
	{
		fgets(line, sizeof line, fp);
		readline[0] = strtok(line, separador); // Função para separar a string pelos pontos e virgulas
		readline[1] = strtok(NULL, separador);
		record = load_record_processplan_table(readline[0], readline[1]); // gera o registo
		table_processplan_table = add_record_processplan_table(table_processplan_table, record); // adiciona o registo á lista
	}
	fclose(fp);

	return table_processplan_table;

}
#pragma endregion

#pragma region Funções_Get_Data
/**
* @brief Função que carrega do ficheiro do processo (Job)
* @param [Char]   Codigo : Codigo do Processo
* @return Lista preenchida com informação do processo (Job)
*/
ProcessPlan_Table* GetDataProcess(char* cod)
{
	
	ProcessPlan_Table* table_process_plan_table = NULL;
	table_process_plan_table = loadProcessPlan_table(table_process_plan_table);

	while (table_process_plan_table != NULL)
	{
		if (strcmp(table_process_plan_table->codigo, cod) == 0)
		{
			return table_process_plan_table;
		}
		table_process_plan_table = table_process_plan_table->next_process;
	}
	
	return table_process_plan_table;

}

#pragma endregion

#pragma region Funções_LOAD_ProcessPlan_(Grid)
/**
* @brief Função que verifica se determinado process plan já existe na grid de processos se existir devolve TRUE se for o primeiro elemento da lista ou não existir devolve FALSE
* @param [St]   Table  : Grid que está a ser preenchida
* @param [Char] Codigo : Codigo do processo a verificar se existe
* @return (true) se existir, (false) se não existir
*/
bool exist_processplan(Process* grid, char* codigo)
{
	if (grid == NULL) return false;
	Process* aux = grid;
	while (aux != NULL)
	{
		if (strcmp(aux->codigo, codigo) == 0) return true;
		aux = aux->next_job;
	}
	return false;
}
/**
* @brief Função que verifica se determinada operação já existe na grid de processos se existir devolve TRUE se for o primeiro elemento da lista ou não existir devolve FALSE
* @param [St]   Table  : Grid que está a ser preenchida ( processo )
* @param [Char] Codigo : Codigo da operação a verificar se existe
* @return (true) se existir, (false) se não existir
*/
bool exist_operation(Operation* grid, int codigo)
{
	if (grid == NULL) return false;
	Operation* aux = grid;
	while (aux != NULL)
	{
		if (aux->codigo==codigo) return true;
		aux = aux->next_operation;
	}
	return false;
}
/**
* @brief Função que carrega a informação de uma operação para um registo
* @param [Int]   Codigo : Codigo da operação a carregar 
* @return Registo preenchido
*/
Operation* load_record_operation(int codigo)
{
	Operation* record = (Operation*)malloc(sizeof(Operation));

	if (record == NULL) return NULL;

	record->codigo=codigo;
	record->machine = NULL;
	record->next_operation= NULL;

	return record;
}
/**
* @brief Função que carrega a informação de uma maquina para um registo
* @param [Int]   Codigo : Codigo da maquina a carregar
* @return Registo preenchido
*/

Machine* load_record_machine(int codigo, int time)
{
	Machine* record = (Machine*)malloc(sizeof(Machine));

	if (record == NULL) return NULL;

	record->codigo = codigo;
	record->tempo= time;
	record->next_machine= NULL;

	return record;
}

/**
* @brief Função que preenche a grelha com base numa linha do ficheiro de texto
* @param [St]   Grid     : Grelha que esta a ser preenchida 
* @param [St]   Processo : Registo do processo que queremos adicionar
* @param [Int]  Operação : Codigo da operação
* @param [Int]  Maquina  : Codigo da maquina
* @param [Int]  Tempo    : Tempo da maquina
* @return Grelha Preenchida
*/

Process* add_record_processplan(Process* grid, Process* record, int operation, int machine, int time)
{
	
	Operation* op_record = NULL;
	op_record = load_record_operation(operation); // gera o registo para as linhas das dimensões

	Machine* machine_record = NULL;
	machine_record = load_record_machine(machine, time); // gera o registo para as linhas maquina ( 3 dimenção da grelha )

	if (exist_processplan(grid, record->codigo)==false)
	{
		if (grid == NULL)
		{
			grid = record;
			grid->operacao = op_record;
			grid->operacao->machine = machine_record;
		}
		else
		{
			Process* aux = grid;
			while (aux->next_job!= NULL)
			{
				aux = aux->next_job;
			}
			aux->next_job = record;
			aux->next_job->operacao= op_record;
			aux->next_job->operacao->machine = machine_record;
		}
	}
	else
	{
		Process* aux_op = grid;
		while (strcmp(aux_op->codigo,record->codigo)!=0)
		{
			aux_op = aux_op->next_job;
		}
		if (exist_operation(aux_op->operacao, operation) == false)
		{
			Operation* aux = aux_op->operacao;
			while (aux->next_operation!= NULL)
			{
				aux = aux->next_operation;
			}
			aux->next_operation = op_record;
			aux->next_operation->machine = machine_record;
		}
		else
		{
			Process* aux_op = grid;
			while (strcmp(aux_op->codigo, record->codigo) != 0)
			{
				aux_op = aux_op->next_job;
			}
			Operation* aux = aux_op ->operacao;
			while (aux->next_operation != NULL)
			{
				aux = aux->next_operation;
			}
			Machine* aux_m = aux->machine;
			while (aux_m->next_machine != NULL)
			{
				aux_m = aux_m->next_machine;
			}
			aux_m->next_machine= machine_record;

		}
	}

	return grid;
}

/**
* @brief Função que carrega a informação de um processo para um registo
* @param [Int]   Codigo : Codigo do processo a carregar
* @return Registo preenchido
*/
Process* load_record_processplan(char* codigo)
{
	Process* record = (Process*)malloc(sizeof(Process));

	if (record == NULL) return NULL;

	strcpy(record->codigo, codigo);
	record->operacao = NULL;
	record->next_job = NULL;

	return record;
}

/**
* @brief Função que lê registos dos process plan do ficheiro de texto e preenche a grelha 
* @param ( Sem parametros )
* @return Registo preenchido
*/
Process* Load_Grid()
{

	char line[100];
	char* readline[4];
	const char separador[2] = ";";
	int i = 0;
	Process* grid = NULL;
	Process* record = NULL;

	FILE* fp;
	fp = fopen("griddata.dat", "rt");
	while (!feof(fp))
	{
		fgets(line, sizeof line, fp);
		readline[0] = strtok(line, separador); // Função para separar a string pelos pontos e virgulas
		readline[1] = strtok(NULL, separador);
		readline[2] = strtok(NULL, separador);
		readline[3] = strtok(NULL, separador);

		record = load_record_processplan(readline[0]); // gera o registo para a primeira coluna da grelha
		grid = add_record_processplan(grid, record, atoi(readline[1]), atoi(readline[2]), atoi(readline[3])); // popula a grelha
		
	}
	fclose(fp);

	return grid;

}

#pragma endregion

