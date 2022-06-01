/**
* author: Josué - Aluno 19553
* email: a19553@alunos.ipca.pt
* date: 31-05-2022
* desc: Escalation
*/

#pragma warning( disable : 4996 )
//Evita a utilização do _CRT_SECURE_NO_WARNINGS, desactiva avisos de segurança na compilação

#pragma region Includes
#include "Definitions.h"
#pragma endregion

#pragma region Funções Escalonamento
/**
* @brief Calendariza uma operação no mapa de escalonamento
* @param [Struct] Processo grid
* @param [char] Processo
* @param [int] Opertação 
* @return VOID
*/
void schedule_job_operation(Process* grid, char* job, int operation)
{

	int mak = 0;
	int tim = 0;
	int i = 0;
	int i2 = 0;

	Bin_Machine* machine = get_machine_job_op(grid, job,operation);
	Bin_Machine* temp = machine;

	for (i = 0; i < MAXOP; i++)
	{
		seq[i][0] = 0;
		seq[i][1] = 0;
	}

	get_machine_job(temp);


	for (i = 0; i < MAXOP; i++)
	{
		for (i2 = i + 1; i2 < MAXOP; i2++)
		{
			if (seq[i][1] > seq[i2][1] && seq[i2][1]>0)
			{
				mak = seq[i][0];
				tim = seq[i][1];
				seq[i][1] = seq[i2][1];
				seq[i][0] = seq[i2][0];
				seq[i2][0] = mak;
				seq[i2][1] = tim;
			}
		}
	}

	int pos = 0;
	for (i = 0; i < MAQUINAS; i++)
	{
		for (i2 = 0 ; i2 < TIMESLOTS; i2++)
		{
			if (strcmp(escalation[i][i2].process, job) == 0 )
			{
				pos = i2+1;
			}
		}
	}

	int p;
	int aux;
	aux = pos;
	for (i = 0; i < MAXOP; i++)
	{
		for (p = pos; p < TIMESLOTS; p++)
		{
			if (escalation[seq[i][0] - 1][(pos + p) - 1].operation != 0)
			{
				aux = p;
			}
		}
		pos = aux;
		if (((TIMESLOTS - (TIMESLOTS -pos)) + seq[i][1])+1<= TIMESLOTS)
		{
			for (i2 = 1; i2 <= seq[i][1]; i2++)
			{
				escalation[seq[i][0]-1][(pos+i2)-1].operation = operation;
				strcpy(escalation[seq[i][0]-1][(pos + i2)-1].process,job);
			}
			i = MAXOP;
		}
		
	}

}
/**
* @brief Devolve as maquinas de uma operação em arvore binaria
* @param [Struct] Processo grid
* @param [char] Processo
* @param [int] Opertação
* @return [Struct] Bi_Machibe Arvore Binaria
*/
Bin_Machine* get_machine_job_op(Process* grid, char* job, int operation)
{
	Bin_Machine * machine = (Bin_Machine*)malloc(sizeof(Bin_Machine));

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

	machine = aux_op->machine;

	return machine;

}
/**
* @brief Percorre a arvore Binaria de Maquinas e preenche um array bidimencional para com o codigo e o tempo para utilização no escalonamento
* @param [Strunt] Bin_Machine 
* @return VOID
*/
void get_machine_job(Bin_Machine* temp)
{
	int i;

	if (temp->binmachine_less != NULL)
	{
		get_machine_job(temp->binmachine_less);
	}
	
	if (temp->binmachine_more != NULL)
	{
		get_machine_job(temp->binmachine_more);
	}
	
	
	i = 0;
	while (seq[i][0] != 0)
	{
		i++;
	}
	seq[i][0] = temp->codigo;
	seq[i][1] = temp->tempo;
	
}



#pragma endregion
