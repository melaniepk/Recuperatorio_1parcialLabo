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

//a) Contribuyentes con más recaudaciones en estado “refinanciar”.
/*
int contribuyentesConMasRecRefinanciar(eContribuyente *listaCont, int tamCont, eRecaudacion *listaRecaudaciones, int tamRec)
{
	int retorno = -1;
	int i;
	int j;
	//int mayorRefinnaciar;

	if(listaCont!= NULL && listaRecaudaciones != NULL && tamCont >=0 && tamRec >=0)
	{
		for(i=0;i<tamCont;i++)
		{

			for(j=0;j<tamRec;j++)
			{
				if((*(listaCont+i)).isEmpty != TRUE  && (*(listaRecaudaciones+j)).isEmpty != TRUE && (*(listaRecaudaciones+j)).estado == ESTADO_REFINANCIAR)
				{
					if((*)
				}

			}

		}

	}
	return retorno;
}
*/
// Cantidad de recaudaciones saldadas de importe mayor a 1000: Se imprimirá
//la cantidad de recaudaciones en estado “saldado” con ese importe o mayor.

int cantidadDeRecaudacionesImporteMayorMil(eContribuyente *listaCont, int tamCont, eRecaudacion *listaRecaudaciones, int tamRec)
{
	int retorno = -1;
	int i;
	int cantidad = 0;

	if(listaCont!= NULL && listaRecaudaciones != NULL && tamCont >=0 && tamRec >=0)
	{
		for(i=0;i<tamRec;i++)
		{
			if((*(listaRecaudaciones+i)).isEmpty != TRUE && (*(listaRecaudaciones+i)).importe >1000 && (*(listaRecaudaciones+i)).estado != ESTADO_REFINANCIAR)
			{
				cantidad++;
				retorno = 0;
			}
		}
		printf("La cantidad de recaudaciones saldads con importe mayor a mil es de : %d", cantidad);
	}

	return retorno;
}


//c) Informar todos los datos de los contribuyentes de un tipo de recaudación
//ingresada por el usuario (ARBA, IIBB, GANANCIAS)


int datosContribuyentesSegunTipo(int tipoIngresado, eContribuyente *listaCont, int tamCont, eRecaudacion *listaRecaudaciones, int tamRec, eTipo *listaTipos, int tamTipo)
{
	int retorno = -1;

	int i;
	int j;
	int k;

	if(listaCont!= NULL && listaRecaudaciones != NULL && tamCont >=0 && tamRec >=0&& listaTipos!= NULL && tamTipo >=0 && tipoIngresado >0)
	{
		for(i=0;i<tamTipo;i++)
		{
			for(j=0;j<tamCont;j++)
			{
				for(k=0;k<tamRec;k++)
				{
					if((*(listaCont+j)).isEmpty != TRUE && (*(listaRecaudaciones+k)).isEmpty != TRUE
							&& tipoIngresado == (*(listaRecaudaciones+k)).tipo.id && (*(listaRecaudaciones+k)).tipo.id ==(*(listaTipos+i)).id)
					{
						printf("DATOS DE CONTRIBUYENTES SEGUN EL TIPO %s", (*(listaTipos+i)).descripcion);
						ImprimirUnContribuyente((*(listaCont+j)));
						retorno = 0;
					}

				}

			}
		}
	}


	return retorno;

}

//Nombre y c.u.i.l. de los Contribuyentes que pagaron impuestos en el mes de
//FEBRERO.

int datosContribuyentesFebrero( eContribuyente *listaCont, int tamCont, eRecaudacion *listaRecaudaciones, int tamRec)
{
	int retorno = -1;
	int i;
	int j;

	if(listaCont!= NULL && listaRecaudaciones != NULL && tamCont >=0 && tamRec >=0)
	{
		for(i=0;i<tamCont;i++)
		{
			for(j=0;j<tamRec;j++)
			{
				if((*(listaCont+i)).isEmpty != TRUE && (*(listaRecaudaciones+j)).isEmpty != TRUE &&
						(*(listaCont+i)).id == (*(listaRecaudaciones+j)).idContribuyente && (*(listaRecaudaciones+j)).mes == 2)
				{
					printf("Contribuyentes que pagaron impuestos en el mes de ferbero:\n");
					printf("Nombre: %s %s, cuil : %s", (*(listaCont+i)).nombre,(*(listaCont+i)).apellido, (*(listaCont+i)).cuil);
				}
			}
		}
	}


	return retorno;
}
