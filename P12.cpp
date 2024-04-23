#include"header.h"
#include"templates.h"
// main
int main()
{
	// initialisierungen/ Deklarationen
	int wahl = 0, anzahl = 0, index = 0;
	int int_float;
	char eingabe[GROESSE];
	Statistikwerte meine_werte;

	// wählen
	while (wahl != 2)
	{
		// alles auf 0 setzen
		wahl = 0;
		anzahl = 0;
		index = 0;
		cout << "Was moechten sie tun?\n (1) Zahlen eingeben.\n (2) Programm beenden.\nihre wahl:	";
		cin >> eingabe;
		// prüft ob zahl integer ist.
		wahl = pruefen_gueltig_integer(eingabe);
		// wenn wahl 1
		if (wahl == 1)
		{
			// wandelt in zahl um.
			wahl = wandeln_integer(eingabe);
		}
		else
		{
			wahl = 0;
		}
		// 1 ist für pluszahl und 2 für minuszahl. das sind die werte die von prüefen_ob_zahl zurück gegeben werden.
		switch (wahl)
		{
		case 1:
			while (anzahl == 0)
			{
				system("cls");
				cout << "mit wie vielen werten moechten sie arbeiten:   ";
				cin >> eingabe;
				// löscht kommandozeile.
				system("cls");
				anzahl = pruefen_gueltig_integer(eingabe);
				// weil prüfen_gültig_integer nur eine 1 für positive werte gibt muss geprüft werden ob die zahl eine 1 ist.
				if (anzahl == 1)
				{
					// wandelt zahl um.
					anzahl = wandeln_integer(eingabe);
					// funktionsaufrufe.
					eingeben(meine_werte, &int_float, anzahl);
					if (int_float == 1)
					{
						get_statistikwerte(meine_werte.integer_werte, anzahl, meine_werte);
					}
					else
					{
						get_statistikwerte(meine_werte.float_werte, anzahl, meine_werte);
					}
					ausgeben(meine_werte, meine_werte.integer_werte, meine_werte.float_werte, int_float, anzahl);
					system("pause");
					system("cls");
				}
			}
			break;
		case 2:
			system("cls");
			cout << "programm wird beendet.\n" << endl;
			system("pause");
			break;
		default:
			system("cls");
			cout << "Sie haben etwas falsch eingegeben.\n" << endl;
		}
	}
	return 0;
}