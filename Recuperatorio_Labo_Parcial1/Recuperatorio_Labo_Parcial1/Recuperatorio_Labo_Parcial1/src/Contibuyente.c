/*
 * Contibuyente.c
 *
 *  Created on: 21 jun. 2021
 *      Author: mkale
 */


#include "utn1.h"
#include "Contribuyente.h"
#define FALSE 1
#define TRUE 0

int inicializarContribuyentes(eContribuyente *list, int len)
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


eContribuyente PedirDatosContribuyente()
{
    eContribuyente miContribuyente;

    utn_getPalabra(miContribuyente.nombre,sizeof(miContribuyente.nombre),"Ingrese el nombre del contribuyente", "Error. Nombre invalido\n", 5);
    utn_getPalabra(miContribuyente.apellido,sizeof(miContribuyente.apellido),"Ingrese el apellido del contribuyente", "Error. Apellido invalido\n", 5);
    //utn_getNumero(&miContribuyente.cuil,"Ingrese el cuil del contribuyente","Error, cuil invalido", 11111111111,99999999999,5);
    utn_getString(miContribuyente.cuil,sizeof(miContribuyente.cuil),"Ingrese el cuil del contribuyente", "Error. Cuil invalido\n", 5);


    return miContribuyente;

}

int BuscarLibreC(eContribuyente *lista, int tam)
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

int IncrementarIdC (int *proximoId)
{
	 int auxId= *proximoId;
	 int nuevoId = auxId+1;
	*proximoId = nuevoId;
	return nuevoId;
}

int agregarContribuyente(eContribuyente *lista, int len,int id)
{

	int i;
	int retorno = -1;

	if(lista != NULL && len > 0)
	{
		i = BuscarLibreC(lista, len);
		if (i != -1)
		{
			lista[i] = PedirDatosContribuyente();
			lista[i].id = id;
			lista[i].isEmpty = FALSE;

			retorno = 0;
		}

	}
	return retorno;
}


int ModificarDatosContribuyente(eContribuyente *lista, int tam)
{

	int idIngresado;
	int i;
	int opcionMod;
	char seguir;
	int retorno = -1;


	printf("Ingrese el ID del Contribuyente a modificar: ");
	scanf("%d", &idIngresado);


	if(lista != NULL && tam >0)
	{
		for(i=0; i<tam; i++)
		{
			if(idIngresado == lista[i].id)
			{

				do
				{
					utn_getNumero(&opcionMod, "Ingrese el numero que corresponda a lo que quiera modificar:\n"
							"1. Nombre del contribuyente\n2.Apellido del contribuyente\n3.C.U.I.L. del contribuyente,",
							"Error, elija una opcion valida", 1,3,2);

					switch(opcionMod)
					{
					case 1:
						utn_getPalabra(lista[i].nombre,strlen(lista->nombre),"Ingrese nuevo nombre\n",
								"Error al ingresar nuevo nombre\n", 3);
						break;
					case 2:
						utn_getPalabra(lista[i].apellido,strlen(lista->apellido),"Ingrese nuevo apellido\n",
														"Error al ingresar nuevo apellido\n", 3);
						break;
					case 3:
						utn_getString(lista[i].cuil,strlen(lista->cuil),"Ingrese nuevo apellido\n",
														"Error al ingresar nuevo apellido\n", 3);
					}

					retorno = 0;

					printf("Modificacion realizada con exito!.\nDesea realizar alguna otra modificacion? (S/N).");
					scanf("%c", &seguir);

				}while(seguir == 's');

			}

		}
	}


	return retorno;
}


int EncontrarContribuyentePorId(eContribuyente *lista, int len, int *id)
{
	int retorno = -1;
	int i;
	if(lista != NULL && len > 0 && id >=0)
	{

		for(i=0; i< len;i++)
		{
			if(lista[i].id == *id)
			{
				retorno = i;
				break;
			}
		}
	}


	return retorno;
}

int BajaContribuyente(eContribuyente *lista, int len,int id,eRecaudacion *listaRecaudaciones, int tamRec, eTipo *listaTipos, int tamTipos)
{
	int retorno = -1;
	char opcion;

	if(lista != NULL && len > 0 )
	{
		printf("¿Seguro desea eliminar al contribuyente de id %d  nombre %s %s.? Se eliminaran tambien sus recaudaciones (S/N)",
				lista[id].id, lista[id].nombre,lista[id].apellido);
		scanf("%c", &opcion);
		if(opcion == 's')
		{
			lista[id].isEmpty = TRUE;
			if(lista[id].id == listaRecaudaciones->idContribuyente)
			{
				listaRecaudaciones->isEmpty = TRUE;
			}
			retorno = 0;
		}
		else
		{
			retorno = -1;

		}
	}
	return retorno;
}

