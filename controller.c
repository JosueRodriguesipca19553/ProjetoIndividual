/**
* author: Josu� - Aluno 19553
* email: a19553@alunos.ipca.pt
* date: 31-03-2022
* desc: Controller
*/

#pragma once

#pragma warning( disable : 4996 )
//Evita a utiliza��o do _CRT_SECURE_NO_WARNINGS, desactiva avisos de seguran�a na compila��o

#pragma region Includes
#include "Definitions.h"
#pragma endregion

#pragma region Fun��es_Opera��es

/**
* @brief Insere Opera��o na Tabela de Opera��es
* @param [St]   Table  : apontador para a struct de Opera��es
* @param [Int]  Codigo : Codigo da nova opera��o a inserir
* @param [Char] Descricao : Descri��o da opera��o a inserir
* @param [Int]  Int TipoAdd : Tipo de Inser��o ( 0-No fim da Lista; 1-Ordenado )
* @return Struct Alterada
*/
Operations_Table* newoperation(Operations_Table* table, int codigo, char* descricao, int tipoadd)
{
	Operations_Table* record;
	record = load_record_operation_table(codigo, descricao);

	if (tipoadd == 0)
	{ 
		//
		// Estando j� criada a fun��o de adi��o para o carregamento (model.c) , foi reutilizada essa
		//
		table = add_record_operation_table(table, record);
	}
	if (tipoadd == 1)
	{
		if (exist_operation_table(table, record->codigo)) return table;
		if (table == NULL)
		{
			table = record;
		}
		else
		{
			Operations_Table* t_aux = table;
			Operations_Table* temp = NULL;
			while (t_aux && t_aux->codigo < record->codigo)
			{
				temp = t_aux;
				t_aux = t_aux->next_operation;
			}
			if (temp == NULL)
			{	
				record->next_operation = table;
				table = record;
			}
			else
			{
				temp->next_operation = record;
				record->next_operation = t_aux;
			}
		}

	}
	return table;
}

/**
* @brief Altera Opera��o na Tabela de Opera��es
* @param [St]   Table  : Apontador para a struct de Opera��es
* @param [Int]  Codigo : Codigo da nova opera��o a alterar
* @param [Char] Descricao : Nova descri��o
* @return Struct Alterada
*/
Operations_Table* changeoperation(Operations_Table* table, int codigo, char* descricao)
{
	Operations_Table* temp = NULL;
	if (table == NULL)
	{
		return NULL;
	}
	else
	{
		Operations_Table* temp = table;
		while (temp != NULL) {
			if (temp->codigo == codigo) 
			{
				strcpy(temp->descricao, descricao);
			}
			temp = temp->next_operation;
		}
	}
	return table;
}

/**
* @brief Remove Opera��o na Tabela de Opera��es
* @param [St]   Table  : Apontador para a struct de Opera��es
* @param [Int]  Codigo : Codigo da nova opera��o a remover
* @return Struct Alterada
*/
Operations_Table* removeoperation(Operations_Table* table, int codigo)
{
	if (table == NULL) return NULL;
	if (exist_operation_table(table, codigo))
	{
		if (table->codigo== codigo) 
		{
			Operations_Table* temp = table;
			table = table->next_operation;
			free(temp);
		}
		else
		{
			Operations_Table* temp = table;
			Operations_Table* temp2 = temp;
			while (temp && temp->codigo != codigo) 
			{	
				temp2 = temp;
				temp = temp->next_operation;
			}
			if (temp != NULL) 
			{
				temp2->next_operation = temp->next_operation;
				free(temp);
			}
		}
	}

	return table;
}



#pragma endregion
