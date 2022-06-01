/*
* author: Josué - Aluno 19553
* email: a19553@alunos.ipca.pt
* date: 31-05-2022
* desc: Estrutura de Dados
*/

#pragma once

#ifndef ESTRUTURAS

#pragma region Data_Models_(Structs)

#define SIZE 100
#define HASHMAX 31
#define CODIGO 10
#define DESCRICAO 50
#define MAQUINAS 8
#define TIMESLOTS 24
#define MAXOP 10
#define MAXLINE 100
#define MAXFILE 30000
#define STRSTD 15

typedef struct process {
	char codigo[CODIGO];
	struct operation* operacao;
	struct process* next_job;
}Process;

typedef struct operation {
	int codigo;
	struct binmachine* machine;
	struct operation* next_operation;
}Operation;


typedef struct binmachine
{
	int codigo;
	int tempo;
	struct binmachine* binmachine_more;
	struct binmachine* binmachine_less;

}Bin_Machine;

/*
Estas tabelas são tabelas de suporte para carregamento de dados informativos sobre:

Tipos de Maquinas - Codigo e descrição
	eg. M1, Motor
Maquinas - Codigo, Nome e tipo de Maquina
	eg. 01, RX20, M1
Operações - Codigo e descrição das Operações
	eg. 01, Montar o Motor
Process Plan- Codigo e descrição do Process Plan ( Job )
	eg. JOB1, Montar Automovel

São de preenchimento facultativo ( não estavam incluidas no projeto) mas fornecem um contexto aos dados apresentados nas listagens.

*/

typedef struct machine_type {
	int codigo;
	char descricao[DESCRICAO];
	struct machine_type* next_type;
}Machine_Type;

typedef struct machine_table {
	int codigo;
	char descricao[DESCRICAO];
	int machinetype;
	struct machine_table* next_machine;
}Machine_Table;

typedef struct operations_table {
	int codigo;
	char descricao[DESCRICAO];
	struct operations_table* next_operation;
}Operations_Table;

typedef struct processplan_table {
	char codigo[CODIGO];
	char descricao[DESCRICAO];
	struct processplan_table* next_process;
}ProcessPlan_Table;

typedef struct HashTable {
	int key;
	Process* job;
}HashTable;

struct HashTable HashTableJob[HASHMAX];

typedef struct Cell {
	char process[CODIGO];
	int operation;
}cell;

cell escalation[MAQUINAS][TIMESLOTS];

int seq[MAXOP][2];

#pragma endregion

#define ESTRUTURAS 1
#endif 