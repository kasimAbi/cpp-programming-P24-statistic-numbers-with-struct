#pragma once
// unbekannter Datentyp die ermittelt wird wenn was übergeben wird
template <class T>
void get_statistikwerte(T *werte, int anzahl, struct Statistikwerte &statistikwerte)
{
	// initialisierungen/ deklarationen
	int index = 0, index2 = 0;
	// Minimum berechnen
	// erste wert speichern
	statistikwerte.mimumumwert = werte[0];
	// alle werte durchgehen. wenn eins kleiner ist dann 0 setzen
	for (int index = 1; index < anzahl; index++)
	{
		if (statistikwerte.mimumumwert > werte[index])
		{
			statistikwerte.mimumumwert = werte[index];
		}
	}

	// Maximum berechnen
	// das gleiche nur andersrum.
	statistikwerte.maximumwert = werte[0];
	for (int index = 1; index < anzahl; index++)
	{
		if (statistikwerte.maximumwert < werte[index])
		{
			statistikwerte.maximumwert = werte[index];
		}
	}

	// Mittelwert berechnen
	statistikwerte.mittelwert = 0.0;
	// alle werte zsm addieren und dann durch die anzahl teilen
	for (int index = 0; index < anzahl; index++)
	{
		statistikwerte.mittelwert += werte[index];
	}

	statistikwerte.mittelwert /= (float)anzahl;
	// Streuung berechen
	statistikwerte.streuung = 0.0;
	for (int index = 0; index < anzahl; index++)
	{
		// wurde vorgegeben also diese formel. s = (E(wert - mittelwert)²) / anzahl - 1.
		statistikwerte.streuung += pow(werte[index] - statistikwerte.mittelwert, 2);
	}
	statistikwerte.streuung /= (float)anzahl - 1.0;

	// Standardabweichung berechnen
	// wurzel aus streuung. wurde vorgegeben.
	statistikwerte.standartabweichung = sqrt(statistikwerte.streuung);

	//-------------------------------------------------------------------------------------------------------------------------//
	// Häufigkeiten ermitteln
	int *schon_gehabt;
	int ueberspringe = 0;

	// schon_gehabt array größe wie die werte größe stellen also anzahl
	schon_gehabt = (int*)malloc(anzahl * sizeof(int));
	for (index = 0; index < anzahl; index++)
	{
		ueberspringe = 0;
		if (index != 0)
		{
			for (index2 = 0; index2 < anzahl; index2++)
			{
				// wenn die zahl schonmal vorkam
				if (werte[index] == schon_gehabt[index2])
				{
					ueberspringe = 1;
				}
			}
		}
		if (ueberspringe != 1)
		{
			// wenn die zahl nicht vorkam
			for (index2 = 0; index2 < anzahl; index2++)
			{
				if (werte[index] == werte[index2])
				{
					// zählt die werte hoch also die anzahl wie oft die zahl vorkam und setzt schon_gehabt für diese zahl damit sie nciht
					// erneut untersucht wird.
					schon_gehabt[index] = werte[index];
					statistikwerte.modalwerte[index]++;
				}
			}
		}
	}
	// größte zahl für die anzahl der meist vorkommenden zahlen speichern. wie bei maximumwert ausrechnen
	statistikwerte.groesste_zahl = statistikwerte.modalwerte[0];
	for (index = 0; index < anzahl; index++)
	{
		if (statistikwerte.groesste_zahl < statistikwerte.modalwerte[index])
		{
			statistikwerte.groesste_zahl = statistikwerte.modalwerte[index];
		}
	}
	// spannweite: max.wert - min.wert. wurde vorgegeben
	statistikwerte.spannweite = fabs(statistikwerte.maximumwert - statistikwerte.mimumumwert);
}