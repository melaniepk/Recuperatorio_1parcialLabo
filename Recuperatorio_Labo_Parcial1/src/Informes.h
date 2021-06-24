/*
 * Informes.h
 *
 *  Created on: 21 jun. 2021
 *      Author: mkale
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include <stdio.h>
#include <stdlib.h>
#include "Contribuyente.h"
#include "Recaudacion.h"
#include "utn1.h"
#define TRUE 0
#define FALSE 1

/**
 * @fn int ImprimirUnContribuyente(eContribuyente)
 * @brief
 * Imprime los datos de un contribuyente
 * @param unContribuyente contribuyente a imprimir
 * @return 0
 */
int ImprimirUnContribuyente(eContribuyente unContribuyente);

/**
 * @fn int ImprimirContribuyentes(eContribuyente[], int)
 * @brief
 * imprime los datos de todo el array de contribuyentes
 * @param lista array de contribuyentes
 * @param len tamaño del array
 * @return 0 si imprimió, -1 i no
 */
int ImprimirContribuyentes(eContribuyente lista[], int len);

/**
 * @fn int ImprimirRecaudaciones(eContribuyente*, int, eRecaudacion*, int, eTipo*, int)
 * @brief
 * imprime las recaudaciones hechas
 * @param contribuyentes lista de contribuyentes
 * @param tamCont tamaño de la lista de contribuyentes
 * @param lista lista de recaudaciones
 * @param len tamaño de la lista de recaudaciones
 * @param arrayTipos lista de tipos
 * @param tamTipo tamaño de la lista de tipos
 * @return devuelve 0 si imprime, -1 si no
 */
int ImprimirRecaudaciones(eContribuyente *contribuyentes,int tamCont,eRecaudacion *lista, int len,eTipo *arrayTipos,int tamTipo);

/**
 * @fn int ImprimirContribuyentesConRecaudaciones(eContribuyente[], eRecaudacion[], int, int, eTipo[], int)
 * @brief
 * impime los datos de cada contribuytente y sus recaudaciones si tienen
 * @param arrayContribuyentes lista de contribuyentes
 * @param arrayRecaudaciones lista de recaudaciones
 * @param tamCont tamaño de la lista de contribiuyentes
 * @param tamRec tamaño de la lista de recaudaciones
 * @param arrayTipos lista de tipos
 * @param tamTipos tamaño de la lsta de tipos
 * @return 0 si imprime, -1 si no
 */
int ImprimirContribuyentesConRecaudaciones(eContribuyente arrayContribuyentes[],eRecaudacion arrayRecaudaciones[],int tamCont,int tamRec, eTipo arrayTipos[],int tamTipos);

/**
 * @fn int ImprimirRecaudacionesSaldadas(eContribuyente[], eRecaudacion[], int, int, eTipo[], int)
 * @brief
 * imorime las recaudaciones que tienen  como estado saldada
 * @param arrayContribuyentes lista de contribuyentes
 * @param arrayRecaudaciones lista de recaudaciones
 * @param tamCont tamaño de lista de contribuyentes
 * @param tamRec tamaño de lista de recaudaciones
 * @param arrayTipos lista de tipos
 * @param tamTipo tamalño de la lista de tipos
 * @return 0 si imprime, -1 si no
 */
int ImprimirRecaudacionesSaldadas(eContribuyente arrayContribuyentes[],eRecaudacion arrayRecaudaciones[],int tamCont,int tamRec,eTipo arrayTipos[],int tamTipo);

/**
 * @fn int refinanciarRecaudacion(int, eContribuyente*, int, eRecaudacion*, int)
 * @brief
 * cambia el estado de una recaudacion de saldada a refinanciar
 * @param idIngresado id de la recaudacion a cambiar
 * @param listaCont lista de contribiuyentes
 * @param tamCont tamaño de la lista de contribuyentes
 * @param listaRec lista de recaudaciones
 * @param tamRec tamaño de la lista de recaudaciones
 * @return 0 si cambbió el estado, -1 si no
 */
int refinanciarRecaudacion(int idIngresado,eContribuyente *listaCont, int tamCont,eRecaudacion *listaRec, int tamRec);

/**
 * @fn int saldarRecaudacion(eContribuyente*, int, eRecaudacion*, int, eTipo[], int)
 * @brief
 * cambia el estado de una recaudacion de reninanciar a saldada
 *
 * @param listaCont lista de contribuyentes
 * @param tamCont tamaño de la lista de contribuyentes
 * @param listaRec lista de recaudaciones
 * @param tamRec tamaño de la lista de recaudaciones
 * @param arrayTipos lista de tipos
 * @param tamTipo tamaño de la lista de tipos
 * @return
 */
int saldarRecaudacion(eContribuyente *listaCont, int tamCont,eRecaudacion *listaRec, int tamRec, eTipo arrayTipos[], int tamTipo);

//int ImprimirunaRecaudacion(eRecaudacion unaRecaudacion, eContribuyente contribuyente);


#endif /* INFORMES_H_ */
