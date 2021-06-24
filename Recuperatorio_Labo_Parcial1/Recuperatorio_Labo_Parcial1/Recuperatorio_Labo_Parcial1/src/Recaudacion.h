/*
 * Recaudacion.h
 *
 *  Created on: 21 jun. 2021
 *      Author: mkale
 */

#ifndef RECAUDACION_H_
#define RECAUDACION_H_
#include <stdio.h>
#include <stdlib.h>
#include"utn1.h"

#define TRUE 0
#define FALSE 1
#define ESTADO_SALDADO 1
#define ESTADO_REFINANCIAR 0

typedef struct
{
	int id;
	char descripcion[10];
}eTipo;


typedef struct
{
	int idContribuyente;
	int id;
	int mes;
	eTipo tipo; //IIBB,GANANCIAS,ARBA
	float importe;
	int estado;
	int isEmpty;
}eRecaudacion;

/**
 * @fn int agregarTipo(eTipo*, int, int, int, char*)
 * @brief
 * hardcodea un tipo de recaudacion
 * @param lista lista de tipos
 * @param tam tamaño de la lista de tipos
 * @param indice indice en el cual se hardcodea en la lista
 * @param id id del nuevo tipo
 * @param descripcion descripcion del nuevo tipo
 * @return devuelve 0 si hardcodeó, -1 si no
 */
int agregarTipo(eTipo *lista, int tam,int indice, int id,char *descripcion);

/**
 * @fn int listarTipos(eTipo[], int)
 * @brief
 * lista los tipos de recaudaciones
 * @param arrayTipos lista de tipos
 * @param tam tamaño de la lista
 * @return 0 si listó, -1 si no
 */
int listarTipos(eTipo arrayTipos[],int tam);

/**
 * @fn int inicializarRecaudaciones(eRecaudacion*, int)
 * @brief
 * inicializa el campo isEmpty de las recaudaciones en 0
 * @param list lista de recaudaciones
 * @param len tamaño de la lista
 * @return 0 si inicializó, -1 si no
 */
int inicializarRecaudaciones(eRecaudacion *list, int len);

/**
 * @fn eRecaudacion PedirDatosRecaudaciones(eTipo*, int)
 * @brief
 * pide los datos al usuario para una nueva recaudacion
 * @param arrayTipos lista de tipos
 * @param tam tamaño de la lista de tipos
 * @return devuelve la recaudacion cargada
 */
eRecaudacion PedirDatosRecaudaciones(eTipo *arrayTipos,int tam);

/**
 * @fn int BuscarLibreR(eRecaudacion*, int)
 * @brief
 * busca un espacio libre en el array de recaudaciones
 * @param lista lista de recaudaciones
 * @param tam tamaño de la lista
 * @return devuelve la posicion si encuentra libre, -1 si no
 */
int BuscarLibreR(eRecaudacion *lista, int tam);

/**
 * @fn int IncrementarIdR(int*)
 * @brief
 * incrementa en 1 el id de la recaudacion
 * @param proximoId id a incrementar
 * @return id incrementado
 */
int IncrementarIdR (int *proximoId);

/**
 * @fn int agregarRecaudacion(eRecaudacion*, int, int, eTipo*, int)
 * @brief
 * agrega una recaudacion a la lista
 * @param lista lista de recaudaciones
 * @param len tamaño de la lista
 * @param id id asignado a la recaudacion
 * @param arrayTipos lista de tipos
 * @param tamTipo tamaño de la lista de tipos
 * @return devuelve 0 si agregó, -1 si no
 */
int agregarRecaudacion(eRecaudacion *lista, int len,int id,eTipo *arrayTipos,int tamTipo);

//int refinanciarRecaudacion(eContribuyente *listaCont, int tamCont,eRecaudacion *listaRec, int tamRec);
//int saldarRecaudacion(eContribuyente *listaCont, int tamCont,eRecaudacion *listaRec, int tamRec);



#endif /* RECAUDACION_H_ */
