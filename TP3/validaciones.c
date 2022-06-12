#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static void capitalizarNombre(char* nombre, int len);

static void capitalizarNombre(char* nombre, int len)
{
	if(nombre != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(i == 0)
			{
				nombre[0] = toupper(nombre[0]);
				break;
			}
		}
	}
}


/**
 * @fn int esNumerica(char*)
 * @brief Recibe una cadena de caracteres y devuelve 1
 * 		  en el caso de que el texto este compuesto solo por números.
 *
 * @param cadena: Cadena de caracteres a ser analizada.
 * @param limite: Limite de la cadena a ser analizada.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
int esNumerica(char* cadena, int limite)
{
	int retorno = 1; // Valor en OK!

	if(cadena != NULL && limite > 0 && strlen(cadena) > 0)
	{
		for(int i = 0; i < limite && cadena[i] != '\0' ; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0; // Valor en ERROR!
				break;
			}
		}
	}

	return retorno;
}

/**
 * @fn int esLetra(char*)
 * @brief Verifica si la variable es una letra.
 *
 * @param caracter: Variable char a verificar.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
int esLetra(char* caracter)
{
	int respuesta = 1; // Valor en OK!

	if(caracter != NULL)
	{
		if(	(*caracter < 'a' || *caracter > 'z') &&
			(*caracter < 'A' || *caracter > 'Z'))
		{
			respuesta = 0; // Valor en ERROR!
		}
	}

	return respuesta;
}

/**
 * @fn int esAlfaNumerico(char*, int)
 * @brief Verifica si la cadena/buffer son solo letras y numeros
 * 		  (incluye tambien los espacios  y guiones).
 * @param cadena: Cadena a analizar.
 * @param limite: Indica la cantidad de caracteres maxima de la cadena.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
int esAlfaNumerico(char* cadena, int limite)
{
	int respuesta = 1; // Valor en OK!

	if(cadena != NULL && limite > 0 && strlen(cadena) > 0)
	{
		for(int i = 0; i <= limite && cadena[i] != '\0'; i++)
		{
			if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] < 'a' || cadena[i] > 'z') &&
				(cadena[i] < '0' || cadena[i] > '9'))
			{
				respuesta = 0; // Valor en ERROR!
				break;
			}
		}
	}

	return respuesta;
}

/**
 * @fn int esNombreValido(char*, int)
 * @brief Verifica si la cadena esta compuesto por letras y espacios
 * 		  para nombres.
 *
 * @param cadena: Cadena a analizar.
 * @param limite: Indica la cantidad de caracteres maxima de la cadena.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
int esNombreValido(char* cadena, int limite)
{
	int respuesta = 1; // Valor en OK!

	if(cadena != NULL && limite > 0)
	{
		for(int i = 0; i <= limite && cadena[i] != '\0'; i++)
		{
			if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] < 'a' || cadena[i] > 'z') &&
				 cadena[i] != ' ')
			{
				capitalizarNombre(cadena, limite);
				respuesta = 0; // Valor en ERROR!
				break;
			}
		}
	}

	return respuesta;
}

/**
 * @fn int esFlotante(char*)
 * @brief Verifica si la cadena/buffer son solo numeros flotantes
 *        (Se incluyen ejemplos como: 3.14 +3.14 -3.14 .314 +.314 -.314 314. +314. -314.)
 * @param cadena: Cadena de caracteres a ser analizada.
 * @param limite: Limite de la cadena a ser analizada.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
int esFlotante(char* cadena, int limite)
{
	int retorno = 1; // Valor en OK!
	int i = 0;
	int contadorPuntos = 0; // No tiene que haber mas de 2 puntos.

	if(cadena != NULL && limite > 0 && strlen(cadena) > 0)
	{
		for(i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0; // Valor en ERROR!
					break;
				}
			}
		}
	}

	return retorno;
}
