/*
* author: Josué - Aluno 19553
* email: a19553@alunos.ipca.pt
* date: 31-03-2022
* desc: Estrutura de Dados
*/

#pragma once

#pragma region Data_Models_(Structs)

typedef struct process {
	char codigo[10];
	struct operation* operacao;
	struct process* next_job;
}Process;

typedef struct operation {
	int codigo;
	struct machine* machine;
	struct operation* next_operation;
}Operation;

typedef struct machine {
	int codigo;
	int tempo;
	struct machine* next_machine;
}Machine;

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
	char descricao[50];
	struct machine_type* next_type;
}Machine_Type;

typedef struct machine_table {
	int codigo;
	char descricao[50];
	int machinetype;
	struct machine_table* next_machine;
}Machine_Table;

typedef struct operations_table {
	int codigo;
	char descricao[50];
	struct operations_table* next_operation;
}Operations_Table;

typedef struct processplan_table {
	char codigo[10];
	char descricao[50];
	struct processplan_table* next_process;
}ProcessPlan_Table;

#pragma endregion