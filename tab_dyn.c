/* tab_dyn.c -- dynamiczne konstruowanie tablic */
#include <stdio.h>
#include <stdlib.h>		// potrzebne dla wykorzystania funkcji malloc() i free()

int main(void)
{
	double* wsk;
	int max = 0;
	int liczba;
	int i = 0;

	puts("Podaj maksymalna liczbe elementow (typu double)");
	if (scanf_s("%d", &max) != 1)
	{
		puts("Niepoprawna liczba, do widzenia");
		exit(EXIT_FAILURE);
	}

	wsk = (double*) malloc(max * sizeof(double));
	if (wsk == NULL)
	{
		puts("Przydzial pamieci nie powidl sie");
		exit(EXIT_FAILURE);
	}

	/* wsk wskazuje na tablice o liczbie elementow rownej max */
	puts("Podaj elementy (k to koniec)");
	while (i < max && scanf_s("%lf", &wsk[i]) == 1)
		i++;
	printf("Oto %d wprowadzonych elemtow:\n", liczba = i);
	for (i = 0; i < liczba; i++)
	{
		printf("%7.2f ", *(wsk + i));
		if (i % 7 == 6)
			putchar('\n');
	}
	if (i % 7 != 0)
		putchar('\n');
	puts("Koniec");
	free(wsk);		// zwolnienie pamiêci

	return 0;
}