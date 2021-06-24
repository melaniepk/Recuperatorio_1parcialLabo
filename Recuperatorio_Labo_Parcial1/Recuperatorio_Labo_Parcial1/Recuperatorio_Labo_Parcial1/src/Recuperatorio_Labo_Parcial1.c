/*
 ============================================================================
 Name        : Recuperatorio_Labo_Parcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include"utn1.h"
#include "Contribuyente.h"
#include "Recaudacion.h"
#include "Informes.h"
#define TAM_CONT 50
#define TAM_REC 50
#define TAM_TIPO 3
int main(void) {

		setbuf(stdout, NULL);
	    int option = 0;
	    int carga = 0;
	    int id = 999;
	    int idR = 99;
		int IdIncremental;
		int IdIncrementalR;
		int NuevoContribuyente;
		int NuevaRecaudacion;
		int Modificacion;
		int idContribuyente;
		int bajaCont;
		int idIngresado;
		int tipoIngresado;

	    eContribuyente arrayContribuyentes[TAM_CONT];
	    eRecaudacion arrayRecaudaciones[TAM_REC];
	    eTipo arrayTipos[TAM_TIPO];


	    inicializarContribuyentes(arrayContribuyentes,TAM_CONT);
	    inicializarRecaudaciones(arrayRecaudaciones,TAM_REC);

	    agregarTipo(arrayTipos,TAM_TIPO,0,1,"ARBA");
	    agregarTipo(arrayTipos,TAM_TIPO,1,2,"IIBB");
	    agregarTipo(arrayTipos,TAM_TIPO,2,3,"GANANCIAS");

	    do{

	    	if(utn_getNumero(&option,
	    			 " \n---Menu---\n"
	    			 "1. Dar de alta un contribuyente.\n"
	    			 "2. Modificar datos de un contribuyente\n"
					 "3. Dar de baja un contribuyente\n"
					 "4. Crear una nueva recaudación\n"
					 "5. Refinanciar una recaudacion\n"
					 "6. Saldar una recaudacion\n"
					 "7. Imprimir contribuyentes\n"
					 "8. Imprimir recaudación\n"
				     "9. Contribuyentes con más recaudaciones en estado “refinanciar\n"
					 "10. Cantidad de recaudaciones saldadas de importe mayor a 1000\n"
	    			 "11. Informar todos los datos de los contribuyentes de un tipo de recaudación"
                     "ingresada por el usuario (ARBA, IIBB, GANANCIAS)\n"
	    			 "12.Nombre y c.u.i.l. de los Contribuyentes que pagaron impuestos en el mes de FEBRERO\n"
					 "13. Salir\n",
	    		"Error, Ingrese una de las opciones validas\n",1,13,10)==0)
	    	{

	    		switch(option) {
	            case 1:
					IdIncremental = IncrementarIdC(&id);
						NuevoContribuyente = agregarContribuyente(arrayContribuyentes, TAM_CONT, IdIncremental);
						if(NuevoContribuyente == 0)
						{
							ImprimirContribuyentes(arrayContribuyentes,TAM_CONT);
						}
	                    carga = 1;
	                break;
	            case 2:
	            	if(carga == 1)
	            	{
						printf("Contribuyentes que puede modificar:\n");
						ImprimirContribuyentes(arrayContribuyentes,TAM_CONT);
						Modificacion = ModificarDatosContribuyente(arrayContribuyentes, TAM_CONT);
						if(Modificacion == -1)
						{
							printf("No se pudo modificar al contribuyente o el ID no existe\n");
						}
						else
						{
							printf("Contribuyente modificado\n");
						}
	            	}
	            	else
	            	{
						printf("Error! primero debe cargar contribuyentes");

	            	}
	            	break;
	            case 3:
	            	if(carga == 1)
	            	{
	            		printf("Contribuyentes que puede dar de baja:\n");
						ImprimirContribuyentesConRecaudaciones(arrayContribuyentes,arrayRecaudaciones,TAM_CONT,TAM_REC,arrayTipos,TAM_TIPO);
						utn_getNumero(&idContribuyente,"Ingrese el id del contribuyente a dar de baja", "ERROR, id inexistente", 1,1000,2);
						idContribuyente = EncontrarContribuyentePorId(arrayContribuyentes,TAM_CONT,&idContribuyente);
						if(idContribuyente == -1)
						{
							printf("No se pudo encontrar a un contribuyente con ese ID\n");
						}
						else
						{
							bajaCont = BajaContribuyente(arrayContribuyentes, TAM_CONT,idContribuyente,arrayRecaudaciones,TAM_REC, arrayTipos, TAM_TIPO);
							if(bajaCont != -1)
							{
								printf("Baja completada!\n");
							}
							else
							{
								printf("No se completó la baja del contribuyente");
							}
						}
	            	}
	            	else
	            	{
						printf("Error! primero debe cargar contribuyentes");

	            	}
	            	break;
	            case 4:
	            	if(carga ==1)
	            	{
						ImprimirContribuyentes(arrayContribuyentes,TAM_CONT);
						IdIncrementalR = IncrementarIdR(&idR);
						NuevaRecaudacion = agregarRecaudacion(arrayRecaudaciones,TAM_REC,IdIncrementalR,arrayTipos,TAM_TIPO);
						if(NuevaRecaudacion == 0)
						{
							ImprimirRecaudaciones(arrayContribuyentes, TAM_CONT,arrayRecaudaciones,TAM_REC,arrayTipos,TAM_TIPO);
						}
	            	}
	            	else
	            	{
						printf("Error! primero debe cargar contribuyentes");

	            	}
	            	break;
	            case 5:
	            	if(carga ==1)
	            	{
						ImprimirRecaudaciones(arrayContribuyentes,TAM_CONT,arrayRecaudaciones,TAM_REC,arrayTipos,TAM_TIPO);
						utn_getNumero(&idIngresado,"Ingrese el ID de la recaudacion a refinanciar: ","ERROR, numero invalido",100,150,5);
	            		refinanciarRecaudacion(idIngresado,arrayContribuyentes,TAM_CONT,arrayRecaudaciones,TAM_REC);
	            	}
	            	else
	            	{
						printf("Error! primero debe cargar contribuyentes");

	            	}
	            	break;
	            case 6:
	            	if(carga ==1)
	            	{
						ImprimirRecaudaciones(arrayContribuyentes, TAM_CONT,arrayRecaudaciones,TAM_REC,arrayTipos,TAM_TIPO);
	            		saldarRecaudacion(arrayContribuyentes,TAM_CONT,arrayRecaudaciones,TAM_REC,arrayTipos, TAM_TIPO);
	            	}
	            	else
	            	{
						printf("Error! primero debe cargar contribuyentes");

	            	}
	            	break;
	            case 7:
	            	if(carga ==1)
	            	{
	            		ImprimirContribuyentesConRecaudaciones(arrayContribuyentes,arrayRecaudaciones,TAM_CONT,TAM_REC,arrayTipos,TAM_TIPO);
	            	}
	            	else
	            	{
						printf("Error! primero debe cargar contribuyentes");

	            	}
	            	break;
	            case 8:
	            	if(carga ==1)
	            	{
						ImprimirRecaudacionesSaldadas(arrayContribuyentes,arrayRecaudaciones,TAM_CONT,TAM_REC,arrayTipos,TAM_TIPO);
					}
					else
					{
						printf("Error! primero debe cargar contribuyentes");

					}
	            	break;
	            case 9:
	            	break;
	            case 10:
	            	cantidadDeRecaudacionesImporteMayorMil(arrayContribuyentes,TAM_CONT,arrayRecaudaciones,TAM_REC);

	            	break;
	            case 11:
	            	listarTipos(arrayTipos, TAM_TIPO);
					utn_getNumero(&tipoIngresado,"Ingrese el numero del tipo de recaudacion: ","ERROR, numero invalido",1,3,5);
					datosContribuyentesSegunTipo(tipoIngresado,arrayContribuyentes,TAM_CONT,arrayRecaudaciones,TAM_REC,arrayTipos,TAM_TIPO);


	            	break;
	            case 12:
	            	datosContribuyentesFebrero(arrayContribuyentes, TAM_CONT, arrayRecaudaciones, TAM_REC);
	            	break;
	            case 13:
	            	printf("Cerrando el programa");

	            	break;

	    		}
	    	}

	    }while(option != 13);

	    return 0;
}
