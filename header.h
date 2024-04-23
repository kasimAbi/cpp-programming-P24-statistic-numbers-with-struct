#pragma once
#pragma comment(lib, "FehlerAbfangen")
#include "fehler_abfangen.h"
#define GROESSE 20
struct Statistikwerte	// struktur
{
	// Definitionen
	float mimumumwert;
	float maximumwert;
	float mittelwert;
	float streuung;
	// damit die entsprechenden stellen auch gezählt werden
	int modalwerte[GROESSE] = { 0 };
	float spannweite;
	float standartabweichung;
	int groesste_zahl;		// für modalwert
	int *integer_werte;
	float *float_werte;
};
void eingeben(struct Statistikwerte &meine_werte, int*, int);
void ausgeben(struct Statistikwerte &statistikwerte, int*, float*, int, int);