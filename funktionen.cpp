#include"header.h"
#include"fehler_abfangen.h"
#include<iostream>
// zum eingeben von den werten
void eingeben(struct Statistikwerte &meine_werte, int *int_float, int anzahl)
{
	char eingabe[GROESSE];
	int index = 0, ok = 0;
	while (ok == 0)
	{
		cout << "geben sie ihre erste zahl ein. \nSie bestimmen mit der Zahl ob sie mit \nInteger oder Float werten arbeiten moechten!\n\ngeben sie ihre 1.te zahl ein:  ";
		cin >> eingabe;
		ok = pruefen_gueltig_float(eingabe);
		if (ok == 2 || ok == -2)
		{
			// setzt es dementsprechend groß
			meine_werte.integer_werte = new int[anzahl];
			if (meine_werte.integer_werte == NULL)
			{
				// fehlermeldung
				cout << "speicher konnte nciht gesetzt werden.\n" << endl;
				return;
			}
			*int_float = 1;
			// wandelt zahl in int wert um
			meine_werte.integer_werte[0] = wandeln_integer(eingabe);
		}
		if (ok == 1 || ok == -1)
		{
			// float werte
			meine_werte.float_werte = (float*)malloc(anzahl * sizeof(float));
			if (meine_werte.float_werte == NULL)
			{
				// fehlermeldung
				cout << "speicher konnte nciht gesetzt werden.\n" << endl;
				return;
			}
			*int_float = 2;
			// wandelt zahl in float wert um
			meine_werte.float_werte[0] = wandeln_float(eingabe);
		}
	}

	// solange was eingeben bis man halt die anzahl- variable erreicht hat
	for (index = 1; index < anzahl; index++)
	{
		cout << "geben sie ihre " << index + 1 << ".te zahl ein:  ";
		// wahl ist: entweder integer oder float
		if (*int_float == 1)
		{
			cin >> eingabe;
			// löscht kommandozeile
			// prüft ob der wert ein integer ist
			ok = pruefen_gueltig_integer(eingabe);
			// -1 ist minuszahl und 1 ist pluszahl darum != 0.
			if (ok != 0)
			{
				// wenn ja wandelt zahl in integer wert um
				meine_werte.integer_werte[index] = wandeln_integer(eingabe);
			}
			else
			{
				// fehlermeldung
				system("cls");
				index--;
				cout << "wiederholen sie ihre eingabe." << endl;
			}
		}
		else
		{
			cin >> eingabe;
			// prüft ob float
			ok = pruefen_gueltig_float(eingabe);
			// 1 ist pluswert und 2 ist minuswert
			if (ok == 1 || ok == -1)
			{
				// wandelt zahl in float wert um
				meine_werte.float_werte[index] = wandeln_float(eingabe);
			}
			else
			{
				// fehlermeldung
				system("cls");
				index--;
				cout << "wiederholen sie ihre eingabe.\n\n" << endl;
			}
		}
	}
}

void ausgeben(Statistikwerte &statistikwerte, int* integer_werte, float* float_werte, int wahl, int anzahl)
{
	// initialisierungen für modalwert.
	int index = 0;
	// alles ausgeben
	cout << endl << "Minimalwert: " << statistikwerte.mimumumwert << endl;
	cout << "Maximalwert: " << statistikwerte.maximumwert << endl;
	cout << "Mittelwert:  " << statistikwerte.mittelwert << endl;
	if (anzahl > 1)
	{
		cout << "Streuung:    " << statistikwerte.streuung << endl;
		cout << "Standardabweichung:   " << statistikwerte.standartabweichung << endl;
	}
	if (statistikwerte.modalwerte == NULL)
	{
		// wenn modalwert nciht vorhanden ist.
		cout << "Modalwert:   Nicht vorhanden" << endl;
	}
	else
	{
		// ansonsten geht er alle zahlen durch bis ein modalwert gefunden wurde
		for (index = 0; index < anzahl; index++)
		{
			// in modalwerte_float sind keine werte drin gespeichert sondern die anzahl der werte wie oft sie vorkamen.
			if (statistikwerte.modalwerte[index] == statistikwerte.groesste_zahl)
			{
				// für integer.
				if (wahl == 1)
				{
					cout << "ihr Modalwert lautet: " << integer_werte[index] << endl;
					// index = anzahl setzen damit er nur ein modalwert ausgibt.
					index = anzahl;
				}
				// für float.
				if (wahl == 2)
				{
					cout << "ihr Modalwert lautet: " << float_werte[index] << endl;
					// index = anzahl setzen damit er nur ein modalwert ausgibt.
					index = anzahl;
				}
			}
		}
	}
	// gibt spannweite aus.
	cout << "Spannweite:  " << statistikwerte.spannweite << endl << endl;
}