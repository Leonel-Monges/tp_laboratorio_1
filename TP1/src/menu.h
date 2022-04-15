/*
 * menu.h
 *
 *  Created on: Apr 14, 2022
 *      Author: Sistemas4
 */

#ifndef MENU_H_
#define MENU_H_

#define ERROR_REINTENTOS "\n [!] Lo sentimos! Intentelo mas tarde...\n <<< Redireccionando al menu principal...\n"
#define KMS_FORZADO 7090
#define PRECIO_FORZADO_AEROLINEAS 162965
#define PRECIO_FORZADO_LATAM 159339
#define ERROR_OPCIONES "\n [!] No se puede realizar los costos si no se ingresan \n     los KMS o PRECIOS!\n"
#define VALOR_INICIAL 0
#define PRECIO_MINIMO 10000
#define KMS_MINIMO 300

int menu_principal();
void menu_mostrarDescripcion(int kms, float precioAerolineas, float precioLatam);
int menu_ingresarKms(int* pKms);
int menu_ingresarPrecio(float* pPrecio, char* mensaje);
int menu_calcularCostos(float precioVuelo, int kms, float* pPrecioDebito, float* pPrecioCredito, float* pPrecioBitcoin, float* pPrecioUnitario);
void menu_informarResultados(char* mensajeAerolinea, float precioVuelo, float precioDebito, float precioCredito, float precioBitcoin, float precioUnitario);
int menu_mostrarDiferenciaDePrecios(float precioLatam, float precioAerolineas);

#endif /* MENU_H_ */
