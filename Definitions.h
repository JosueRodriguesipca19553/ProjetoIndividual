/*
* author: Josué - Aluno 19553
* email: a19553@alunos.ipca.pt
* date: 21-05-2022
* desc: Assinaturas das Funções
*/

#pragma once

#ifndef ASSINATURAS

#include "DataStructure.h"
#include <stdbool.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Process* Load_Grid();

Operations_Table* newoperation(Operations_Table* table, int codigo, char* descricao, int tipoadd);
Operations_Table* changeoperation(Operations_Table* table, int codigo, char* descricao);
Operations_Table* removeoperation(Operations_Table* table, int codigo);

Bin_Machine* add_machine_tree(Bin_Machine* tree, Bin_Machine* machine);
Process* add_job(Process* grid, Process* record);
Process* add_process(Process* grid, char* job, Operation* op_record);
Process* add_machine(Process* grid, char* job, int operation, Bin_Machine* machine_record);
Process* add_record_processplan(Process* grid, char* job, int operation, int machine, int time);

Machine_Type* load_record_machine_type_table(int codigo, char* descricao);
bool exist_machine_type_table(Machine_Type* table, int codigo);
Machine_Type* add_record_machine_type_table(Machine_Type* table, Machine_Type* record);
Machine_Type* load_record_machine_type_table(int codigo, char* descricao);
Machine_Type* loadMachine_type_table(Machine_Type* table_machine_type);
Operations_Table* loadOperation_table(Operations_Table* table_operations_table);

Operations_Table* load_record_operation_table(int codigo, char* descricao);
Operations_Table* loadOperation_table(Operations_Table* table_operations_table);
Operations_Table* add_record_operation_table(Operations_Table* table, Operations_Table* record);
ProcessPlan_Table* loadProcessPlan_table(ProcessPlan_Table* table_processplan_table);
Machine_Table* loadMachine_table(Machine_Table* table_machine);
bool exist_operation_table(Operations_Table* table, int codigo);

char* get_desc_processplan(char* job);
char* get_desc_operation(int codigo);
char* get_desc_machine(int codigo);

bool test_add_list();
bool test_add_list_middle();
bool test_alt_list();
bool test_delete_list_middle();
bool test_delete_list();
bool test_valormin();
bool test_valormax();
bool test_valormedio();
int UnitTests();

char* view_min_job(Process* grid, char* job, char* resultado);
char* view_max_job(Process* grid, char* job, char* resultado);
char* view_avg_job(Process* grid, char* job, char* resultado);
char* get_desc_processplan(char* job);
char* get_desc_operation(int codigo);
char* get_desc_machine(int codigo);

#define ASSINATURAS 1
#endif 