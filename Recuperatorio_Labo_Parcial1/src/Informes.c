/*
 * Informes.c
 *
 *  Created on: 21 jun. 2021
 *      Author: mkale
 */
#include "Informes.h"

int ImprimirUnContribuyente(eContribuyente unContribuyente)
{
	int retorno = 0;

	printf("\n %-5d    %s    %s     %s",unContribuyente.id,unContribuyente.nombre,unContribuyente.apellido,unContribuyente.cuil);

	return retorno;
}

int ImprimirContribuyentes(eContribuyente lista[], int len)
{
	int retorno = -1;
	int i;
	if(lista != NULL && len >=0)
	{
		printf("\nId     Nombre     Apellido     Cuil");
		for(i= 0; i< len; i++)
		{
			if(lista[i].isEmpty == TRUE)
				break;
			else
			{
				ImprimirUnContribuyente(lista[i]);
			}
		}
		retorno = 0;
	}
	return retorno;
}


int ImprimirRecaudaciones(eContribuyente *contribuyentes,int tamCont,eRecaudacion *lista, int len,eTipo *arrayTipos,int tamTipo)
{
	int retorno = -1;
	int i;
	int j;
	int k;
	if(lista != NULL && len > 0 && contribuyentes!= NULL && arrayTipos != NULL && tamCont >=0 && tamTipo >=0)
	{
			   printf("  ID --- Mes --- Importe --- Tipo --- c.u.i.l del contribuyente ---- Nombre y  Apellido del Contribuyente \n ");

		for(i=0;i<len;i++)
		{
			for(j=0;j<tamTipo;j++)
			{
				for(k=0;k<tamCont;k++)
				{
					if(lista[i].isEmpty != TRUE && lista[i].tipo.id == arrayTipos[j].id && contribuyentes[k].isEmpty != TRUE && contribuyentes[k].id == lista[i].idContribuyente)
					{
						retorno = 0;

						printf(" %d      %d     %.2f    %s    %s      %s %s \n ",  lista[i].id,
														lista[i].mes,
														lista[i].importe,
														arrayTipos[j].descripcion,
														contribuyentes[k].cuil,
														contribuyentes[k].nombre,
														contribuyentes[k].apellido);
					}
				}

			}


		}
	}

	return retorno;
}

int ImprimirContribuyentesConRecaudaciones(eContribuyente arrayContribuyentes[],eRecaudacion arrayRecaudaciones[],int tamCont,int tamRec, eTipo arrayTipos[],int tamTipos)
{
	int i;
	int j;
	int retorno = -1;

	if(arrayContribuyentes!= NULL && arrayRecaudaciones != NULL && arrayTipos != NULL && tamCont >=0 && tamRec >=0 && tamTipos >=0)
	{

		printf("\nId     nombre     apellido     cuil\n");
		for(i= 0; i< tamCont; i++)
		{
			if(arrayContribuyentes[i].isEmpty == TRUE)
			break;
			else
			{
				ImprimirUnContribuyente(arrayContribuyentes[i]);
				for(j=0;i<tamRec;j++)
				{

					if(arrayContribuyentes[i].id == arrayRecaudaciones[j].idContribuyente && arrayRecaudaciones[j].isEmpty == FALSE)
					{
						printf("\n----RECAUDACIONES----\n");
						ImprimirRecaudaciones(arrayContribuyentes,tamCont,arrayRecaudaciones,tamRec,arrayTipos,tamTipos);
						break;
						retorno = 0;
					}
					else
					{
						printf("\nNo hay recaudaciones correspondientes a este contribuyente\n");
						break;
					}

				}
			}
		}
	}
	return retorno;
}

int ImprimirRecaudacionesSaldadas(eContribuyente arrayContribuyentes[],eRecaudacion arrayRecaudaciones[],int tamCont,int tamRec,eTipo arrayTipos[],int tamTipo)
{

	int retorno = -1;
		int i;
		int j;
		int k;
		if(arrayRecaudaciones != NULL && tamRec > 0 && arrayContribuyentes!= NULL && arrayTipos != NULL && tamCont >=0 && tamTipo >=0)
		{
				   printf("  ID --- Mes --- Importe --- Tipo --- Nombre y  Apellido del Contribuyente\n ");

			for(i=0;i<tamRec;i++)
			{
				for(j=0;j<tamTipo;j++)
				{
					for(k=0;k<tamCont;k++)
					{
						if(arrayRecaudaciones[i].isEmpty != TRUE  && arrayContribuyentes[k].isEmpty != TRUE && arrayRecaudaciones[i].estado != ESTADO_REFINANCIAR &&arrayRecaudaciones[i].idContribuyente == arrayContribuyentes[k].id && arrayRecaudaciones[i].tipo.id == arrayTipos[j].id )
						{
							retorno = 0;

							printf(" %d      %d     %.2f    %s     %s %s \n ",  arrayRecaudaciones[i].id,
															arrayRecaudaciones[i].mes,
															arrayRecaudaciones[i].importe,
															arrayTipos[j].descripcion,
															arrayContribuyentes[k].nombre,
															arrayContribuyentes[k].apellido);
						}
					}

				}


			}
		}

	return retorno;
}


int refinanciarRecaudacion(int idIngresado, eContribuyente *listaCont, int tamCont,eRecaudacion *listaRec, int tamRec)
{

	int i;
	char seguir;
	int retorno = -1;

	if(idIngresado >= 0 && listaCont != NULL && listaRec != NULL && tamCont >=0 && tamRec >=0)
	{
		for(i=0;i<tamCont;i++)
		{
			if(idIngresado == listaRec->id)
			{
				printf("El contribuyente es %s %s, ID: %d, c.u.i.l : %s", listaCont->nombre,listaCont->apellido,listaCont->id,listaCont->cuil);
				if(listaRec->estado == ESTADO_SALDADO)
				{
					printf("\nDesea cambiar el estado a 'refinanciar'? (s/n)");
					scanf("%c",&seguir);
					if(seguir == 's')
					{
						listaRec->estado = ESTADO_REFINANCIAR;
						printf("El estado de la recaudacion ahora es 'refinanciar'\n'");
						retorno = 0;
					}
				}
			}

		}
	}

	return retorno;
}


int saldarRecaudacion(eContribuyente *listaCont, int tamCont,eRecaudacion *listaRec, int tamRec, eTipo arrayTipos[], int tamTipo)
{

		int idIngresado;
		int i;
		char seguir;
		int retorno = -1;


		printf("Ingrese el ID de la recaudacion a refinanciar: ");
		scanf("%d", &idIngresado);
		//ImprimirUnContribuyente(listaCont[idIngresado]);

		for(i=0;i<tamCont;i++)
		{
			if(idIngresado == listaRec->id)
			{
				if(listaRec->estado == ESTADO_REFINANCIAR)
				{
					printf("Desea cambiar el estado a 'saldado'? (s/n)");
					scanf("%c",&seguir);
					if(seguir == 's')
					{
						listaRec->estado = ESTADO_SALDADO;
						retorno = 0;
					}
				}
				else
				{
					if(listaRec->estado == ESTADO_SALDADO)
					{
						printf("El estado actual de la Recaudacion es Saldado\n");
						break;
					}
				}
			}
		}

	return retorno;
}
