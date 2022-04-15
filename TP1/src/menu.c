#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "menu.h"

/**
 * @fn int menu_principal()
 * @brief Funcion encargada de mostrar/ingresar
 * 		  la seleccion de opciones que el usuario requiera (Opciones del 1-6)
 *
 * @return 0 == OK
 */
int menu_principal()
{
	int opcion;
	int kms = VALOR_INICIAL;
	float precioAerolineas = VALOR_INICIAL;
	float precioLatam = VALOR_INICIAL;

	float precioDebitoAero;
	float precioCreditoAero;
	float precioBitcoinAero;
	float precioUnitarioAero;

	float precioDebitoLat;
	float precioCreditoLat;
	float precioBitcoinLat;
	float precioUnitarioLat;

	int flagKm = -1; // Valdra 0 cuando que ingrese KMS
	int flagPrecios = -1; // Valdra 0 cuando que ingrese los PRECIOS

	do
	{
		menu_mostrarDescripcion(kms, precioAerolineas, precioLatam);
		if(!(utn_getInt(&opcion, "\n\n > Ingrese una opcion (1-6): ", ERROR_MSJ, 1, 6, REINTENTOS)))
			{
				switch(opcion)
				{
					case 1:
						if(!(menu_ingresarKms(&kms)))
						{
							printf("\n ~ Ingresaste %d kms\n", kms);
							flagKm = 0;
						}
						else
						{
							printf(ERROR_REINTENTOS);
						}
						break;
					case 2:
						if(!(menu_ingresarPrecio(&precioAerolineas,
							"\n > Ingrese precio del vuelos Aerolineas (min. $10.000): $ ")))
							{
								if(!(menu_ingresarPrecio(&precioLatam,
									"\n > Ingrese precio del vuelos Latam (min. $10.000): $ ")))
								{
									printf("\n ~ Ha ingresado los siguientes precios:");
									printf("\n   - Precio Vuelos Aerolineas: $ %.2f", precioAerolineas);
									printf("\n   - Precio Vuelos Latam: $ %.2f\n\n", precioLatam);
									flagPrecios = 0;
								}
								else
								{
									printf(ERROR_REINTENTOS);
								}
							}
						else
						{
							printf(ERROR_REINTENTOS);
						}
						break;
					case 3:
						if(flagKm == 0 && flagPrecios == 0)
						{
							if(menu_calcularCostos(
									precioAerolineas,
									kms,
									&precioDebitoAero,
									&precioCreditoAero,
									&precioBitcoinAero,
									&precioUnitarioAero) == 0 &&
								menu_calcularCostos(
									precioLatam,
									kms,
									&precioDebitoLat,
									&precioCreditoLat,
									&precioBitcoinLat,
									&precioUnitarioLat) == 0)
									{
										printf("\n ~ Calculo realizado con exito!\n");
									}
						}
						else
						{
							printf(ERROR_OPCIONES);
						}
						break;
					case 4:
						if(flagKm == 0 && flagPrecios == 0)
						{
							menu_informarResultados("Aerolineas",precioAerolineas,
									precioDebitoAero,
									precioCreditoAero,
									precioBitcoinAero,
									precioUnitarioAero);

							menu_informarResultados(
									"Latam",precioLatam,
									precioDebitoLat,
									precioCreditoLat,
									precioBitcoinLat,
									precioUnitarioLat);

							menu_mostrarDiferenciaDePrecios(precioLatam, precioAerolineas);
						}
						else
						{
							printf(ERROR_OPCIONES);
						}
						break;
					case 5:
						if(menu_calcularCostos(PRECIO_FORZADO_AEROLINEAS, KMS_FORZADO,
								&precioDebitoAero, &precioCreditoAero, &precioBitcoinAero, &precioUnitarioAero) == 0 &&
							menu_calcularCostos(PRECIO_FORZADO_LATAM, KMS_FORZADO,
								&precioDebitoLat, &precioCreditoLat, &precioBitcoinLat, &precioUnitarioLat) == 0)
						{
							printf("\n KMS Ingresados: %d km \n", KMS_FORZADO);
							menu_informarResultados("Aerolineas", PRECIO_FORZADO_AEROLINEAS,
									precioDebitoAero, precioCreditoAero, precioBitcoinAero, precioUnitarioAero);
							menu_informarResultados("Latam", PRECIO_FORZADO_LATAM,
									precioDebitoLat, precioCreditoLat, precioBitcoinLat, precioUnitarioLat);
							menu_mostrarDiferenciaDePrecios(PRECIO_FORZADO_AEROLINEAS, PRECIO_FORZADO_LATAM);
						}
						break;
					case 6:
						printf("\n ~ Gracias! Vuelva prontos! \n");
						break;
				}
			}
	}while(opcion != 6);

	return 0;
}

/**
 * @fn void menu_mostrarDescripcion(int, float, float)
 * @brief Funcion encargada de mostrar una descripcion de las opciones a elegir,
 * 		  como tambien mostrarle los valores ingresados por el usuario.
 *
 * @param kms: Parametro encargado de copiar el valor de los kms,
 * 			   con el fin de mostrarle al usuario dicho valor ingresado.
 * @param precioAerolineas: Parametro encargado de copiar el valor del vuelo por Aerolineas,
 * 							con el fin de mostrarle al usuario dicho valor ingresado.
 * @param precioLatam: Parametro encargado de copiar el valor del vuelo por Latam,
 * 					   con el fin de mostrarle al usuario dicho valor ingresado.
 */
void menu_mostrarDescripcion(int kms, float precioAerolineas, float precioLatam)
{
	printf("\n TP1 - Agencia de Viajes (Leonel Monges - 1E)\n");
	printf("\n 1. Ingresar Kilometros (kms = %d).", kms);
	printf("\n 2. Ingresar Precio de Vuelos (Aerolíneas = $ %.2f, Latam = $ %.2f).", precioAerolineas, precioLatam);
	printf("\n 3. Calcular todos los costos.");
	printf("\n 4. Informar resultados.");
	printf("\n 5. Carga forzada de datos.");
	printf("\n 6. Salir.");
}

/**
 * @fn int menu_ingresarKms(int*)
 * @brief Funcion encargada de pedir los kms que el usuario estipule,
 * 		  incluyendo la validacion de dicho dato (>= 300 kms)
 *
 * @param pKms: Puntero a entero a retornar, con el valor validado de Kms.
 * @return 0 == OK || -1 == ERROR!
 */
int menu_ingresarKms(int* pKms)
{
	int retorno = -1;
	int bufferKms;

	if(pKms != NULL)
	{
		if(!(utn_getInt(&bufferKms,
				"\n > Ingrese Kms (min.300): ",
				" [!] Error! ", KMS_MINIMO, 99999, 2)))
		{
			*pKms = bufferKms;
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * @fn int menu_ingresarPrecio(float*, char*)
 * @brief Funcion encargada de pedir el precio del vuelo que el usuario estipule,
 *		  incluyendo la validacion de dicho dato (precios >= $10000)
 * @param pPrecio: Puntero a entero a setear, con el valor validado de precio.
 * @param mensaje: Mensaje de ingreso generico a mostrar.
 * @return 0 == OK || -1 == ERROR!
 */
int menu_ingresarPrecio(float* pPrecio, char* mensaje)
{
	int retorno = -1;
	float bufferPrecio;

	if(pPrecio != NULL && mensaje != NULL)
	{
		if(!(utn_getFloat(&bufferPrecio, mensaje, ERROR_MSJ, PRECIO_MINIMO, 9999999.99, REINTENTOS)))
			{
				*pPrecio = bufferPrecio;
				retorno = 0;
			}
	}

	return retorno;
}

/**
 * @fn int menu_calcularCostos(float, int, float*, float*, float*, float*)
 * @brief Funcion encargada de realizar todas las operaciones de pago
 * 		  bajo el precio de un vuelo estipulado.
 *
 * @param precioVuelo: Valor del precio a tener a cuenta para operar en dicho valor.
 * @param kms: Valor de Kms a tener a cuenta para operar en dicho valor.
 * @param pPrecioDebito: Puntero a flotante a setear, con el valor validado de precio por debito.
 * @param pPrecioCredito: Puntero a flotante a setear, con el valor validado de precio por credito.
 * @param pPrecioBitcoin: Puntero a flotante a setear, con el valor validado de precio por bitcoin.
 * @param pPrecioUnitario: Puntero a flotante a setear, con el valor validado de precio unitario.
 * @return 0 == OK || -1 == ERROR!
 */
int menu_calcularCostos(float precioVuelo, int kms, float* pPrecioDebito, float* pPrecioCredito, float* pPrecioBitcoin, float* pPrecioUnitario)
{
	int retorno = -1;
	float bufferDebito;
	float bufferCredito;
	float bufferBitcoin;
	float bufferUnitario;

	if(utn_getPorcentaje(&bufferDebito, precioVuelo, 0.10, 1) == 0 &&
	   utn_getPorcentaje(&bufferCredito, precioVuelo, 0.25, 0) == 0 &&
	   utn_calcularOperacion(&bufferBitcoin, precioVuelo, 4606954.55, 4) == 0 &&
	   utn_calcularOperacion(&bufferUnitario, precioVuelo, kms, 4) == 0
	   )
	{
		*pPrecioDebito = bufferDebito;
		*pPrecioCredito = bufferCredito;
		*pPrecioBitcoin = bufferBitcoin;
		*pPrecioUnitario = bufferUnitario;
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn void menu_informarResultados(char*, float, float, float, float, float)
 * @brief Funcion encargada de mostrar todos los medios de pagos de un vuelo,
 * 		  ya implementados y validados, correspodientes a dicho precio del vuelo y kms ingresados.
 *
 * @param mensajeAerolinea: Estipula por mensaje la compañia seleccionada.
 * @param precioVuelo: Valor a copiar con el fin de mostrar el precio del vuelo.
 * @param precioDebito: Valor a copiar con el fin de mostrar el precio por debito.
 * @param precioCredito: Valor a copiar con el fin de mostrar el precio del credito.
 * @param precioBitcoin: Valor a copiar con el fin de mostrar el precio por bitcoin.
 * @param precioUnitario: Valor a copiar con el fin de mostrar el precio unitario.
 */
void menu_informarResultados(char* mensajeAerolinea, float precioVuelo,
		float precioDebito, float precioCredito, float precioBitcoin,
		float precioUnitario)
{
	printf("\n Precio %s: $ %.2f", mensajeAerolinea, precioVuelo);
	printf("\n a) Precio con tarjeta de débito: $ %.2f", precioDebito);
	printf("\n b) Precio con tarjeta de crédito: $ %.2f", precioCredito);
	printf("\n c) Precio pagando con bitcoin: BTC %.8f", precioBitcoin);
	printf("\n d) Precio unitario: $ %.2f\n", precioUnitario);
}

/**
 * @fn int menu_mostrarDiferenciaDePrecios(float, float)
 * @brief Funcion encargada de realizar y mostrar la diferencia de precios
 * 		  entre los vuelos de Aerolineas y Latam.
 *
 * @param precioLatam: Valor del precio por Latam para operar en dicho valor.
 * @param precioAerolineas: Valor del precio por Aerolineas para operar en dicho valor.
 * @return 0 == OK || -1 == ERROR!
 */
int menu_mostrarDiferenciaDePrecios(float precioLatam, float precioAerolineas)
{
	int retorno = -1;
	float precioDiferencia;

	if(utn_calcularOperacion(&precioDiferencia, precioLatam, precioAerolineas, 2) == 0)
	{
		printf("\n ~ La diferencia de precio es: $ %.2f \n", precioDiferencia);
		retorno = 0;
	}

	return retorno;
}
