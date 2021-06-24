/*
 * Recaudacion.c
 *
 *  Created on: 21 jun. 2021
 *      Author: mkale
 */

#include "Recaudacion.h"


int agregarTipo(eTipo *lista, int tam,int indice, int id,char *descripcion)
{

	int retorno = -1;
	eTipo bufferTipo;

	if(lista != NULL && tam > 0 && indice >=0  && descripcion != NULL)
	{

		strncpy(bufferTipo.descripcion, descripcion, sizeof(bufferTipo.descripcion));
		bufferTipo.id = id;
		lista[indice] = bufferTipo;

			retorno = 0;
	}
	return retorno;
}
int inicializarRecaudaciones(eRecaudacion *list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = TRUE;
			retorno = 0;
		}
	}

	return retorno;
}

int listarTipos(eTipo arrayTipos[],int tam)
{
	int i;
	int retorno = -1;
	if(arrayTipos!= NULL)
	{
		for(i=0;i<tam;i++)
		{
			printf("%d--- %s\n",(*(arrayTipos+i)).id, (*(arrayTipos+i)).descripcion);
			retorno = 0;
		}
	}
	return retorno;
}
eRecaudacion PedirDatosRecaudaciones(eTipo *arrayTipos,int tam)
{
    eRecaudacion unaRecaudacion;

    utn_getNumero(&unaRecaudacion.idContribuyente,"\nIngrese el numero de ID del contribuyente\n","Error, mes invalido", 1000,1050,5);

    utn_getNumero(&unaRecaudacion.mes,"Ingrese el numero del mes en el cual se efectua la recaudación\n","Error, mes invalido", 1,12,5);
    listarTipos(arrayTipos,tam);
    utn_getNumero(&unaRecaudacion.tipo.id,"Ingrese el numero del tipo de la recaudacion\n","Error, tipo invalido", 1,3,5);
    utn_getNumeroFlotante(&unaRecaudacion.importe,"Ingrese el importe\n","Error, imporrte invalido", 1,9999999,5);

    return unaRecaudacion;

}

int BuscarLibreR(eRecaudacion *lista, int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == TRUE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int IncrementarIdR (int *proximoId)
{
	 int auxId= *proximoId;
	 int nuevoId = auxId+1;
	*proximoId = nuevoId;
	return nuevoId;
}

int agregarRecaudacion(eRecaudacion *lista, int len,int id,eTipo *arrayTipos,int tamTipo)
{

	int i;
	int retorno = -1;

	if(lista != NULL && len > 0)
	{
		i = BuscarLibreR(lista, len);
		if (i != -1)
		{
			lista[i] = PedirDatosRecaudaciones(arrayTipos,tamTipo);
			lista[i].id = id;
			lista[i].isEmpty = FALSE;
			lista[i].estado = ESTADO_SALDADO;

			retorno = 0;
		}

	}
	return retorno;
}

