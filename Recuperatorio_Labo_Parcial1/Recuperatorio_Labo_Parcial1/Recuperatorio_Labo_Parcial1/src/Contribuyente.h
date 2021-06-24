/*
 * Contribuyente.h
 *
 *  Created on: 21 jun. 2021
 *      Author: mkale
 */

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_
#define N_LEN 25
#define CUIL_LEN 12
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Recaudacion.h"
#include "utn1.h"


typedef struct
{
	int id;
	char nombre[N_LEN];
	char apellido[N_LEN];
	char cuil[CUIL_LEN];
	int isEmpty;

}eContribuyente;

/**
 * @fn int inicializarContribuyentes(eContribuyente*, int)
 * @brief
 * inicializa el campo isEmpty de cada posicion del array de contribuyentes en 0
 * @param list array de contribuyentes
 * @param len tamaño del array
 * @return 0 si tiene exito, -1 si no
 */
int inicializarContribuyentes(eContribuyente *list, int len);

/**
 * @fn eContribuyente PedirDatosContribuyente()
 * @brief
 * pide los datos a completar por el usuario sobre el contribuyente
 * @return los datos del contribuyente
 */
eContribuyente PedirDatosContribuyente();

/**
 * @fn int BuscarLibreC(eContribuyente*, int)
 * @brief
 * busca una posicion libre en el array de contribuyentes
 * @param lista array de contribuyentes
 * @param tam tamaño del array
 * @return -1 si no hay lugar, la posicion vacia si encuentra alguna
 */
int BuscarLibreC(eContribuyente *lista, int tam);

/**
 * @fn int IncrementarIdC(int*)
 * @brief
 * incrementa el campo id del contribuyente en 1
 * @param proximoId id a incrementar
 * @return id incrementado
 */
int IncrementarIdC (int *proximoId);

/**
 * @fn int agregarContribuyente(eContribuyente*, int, int)
 * @brief
 * agrega un contribuyente y sus datos a la lista
 * @param lista array de contribuyentes
 * @param len tamaño del array
 * @param id id asignado al nuevo contribuyente
 * @return 0 si agregó, -1 si no
 */
int agregarContribuyente(eContribuyente *lista, int len,int id);

/**
 * @fn int ModificarDatosContribuyente(eContribuyente*, int)
 * @brief
 * modifica el dato seleccionado por el usuario en el contribuyente
 * @param lista array de contribuyentes
 * @param tam tamaño del array
 * @return 0 si modificó, -1 si no
 */
int ModificarDatosContribuyente(eContribuyente *lista, int tam);

/**
 * @fn int EncontrarContribuyentePorId(eContribuyente*, int, int*)
 * @brief
 * encuentra los datos de un contribuyente buscandolo por su ig asignado
 * @param lista aray de contribuytentes
 * @param len tamaño del array
 * @param id id buscado
 * @return devuelve la posicion del id ingresado si lo encuentra, -1 si no
 */
int EncontrarContribuyentePorId(eContribuyente *lista, int len, int *id);

/**
 * @fn int BajaContribuyente(eContribuyente*, int, int, eRecaudacion*, int, eTipo*, int)
 * @brief
 * da de baja y elimina los datos de un contribuyente
 * @param lista array de contribuyentes
 * @param len tamaño del array
 * @param id id del contribuyente a eliminar
 * @param listaRecaudaciones lista de recaudaciones del contribuyente a eliminar
 * @param tamRec tamaño de la lista de recaudaciones
 * @param listaTipos lista de tipos de recaudaciones
 * @param tamTipos tamaño de la lista de tipos
 * @return 0 si dio de baja, -1 si no
 */
int BajaContribuyente(eContribuyente *lista, int len,int id,eRecaudacion *listaRecaudaciones, int tamRec, eTipo *listaTipos, int tamTipos);



#endif /* CONTRIBUYENTE_H_ */
