/*
 ============================================================================
 Name        : TP1.c
 Author      : Leonel Monges
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(void)
{
	setbuf(stdout, NULL);

	menu_principal();

	return EXIT_SUCCESS;
}
