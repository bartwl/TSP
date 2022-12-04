#include<iostream>
#include<climits>
using namespace std;

int Graf[40][40], UkonczoneMiasta[40], LiczbaMiast;
long Trasa = 0;

unsigned long Silnia(unsigned int n)
{
	if (n > 1)
		return n * Silnia(n - 1);
	else
		return 1;
}

void GrafFunc()
{
	cout << "Podaj liczbe miast: ";
	cin >> LiczbaMiast;
	cout << "\nPodaj odleglosc/koszt/czas podrozy pomiedzy miastami\n";
	for (int i = 0; i < LiczbaMiast; i++)
	{
		for (int j = 0; j < LiczbaMiast; j++)
		{
			cout << "\nPodaj odleglosc pomiedzy miastem " << i + 1 << " a miastem " << j + 1 << "\n";
			cin >> Graf[i][j];
			if (i == j)
				Graf[i][j] = 0;
		}
		UkonczoneMiasta[i] = 0;
	}
	cout << "\n\nTablica odleglosci pomiedzy miastami:\n";
	for (int i = 0; i < LiczbaMiast; i++)
		cout << "\tM" << i;
	for (int i = 0; i < LiczbaMiast; i++)
	{
		cout << "\nM" << i;
		for (int j = 0; j < LiczbaMiast; j++)
			cout << "\t" << Graf[i][j];
	}
}

long CyklHamiltona(int cykl)
{
	long NM = Silnia(LiczbaMiast);
	int ObecnaTrasa;
	int NajkrotszaTrasa = INT16_MAX;
	for (int KolejneMiasto = 0; KolejneMiasto < LiczbaMiast; KolejneMiasto++)
	{
		if ((Graf[cykl][KolejneMiasto] != 0) && (UkonczoneMiasta[KolejneMiasto] == 0))
		{
			if (Graf[cykl][KolejneMiasto] < NajkrotszaTrasa && Graf[KolejneMiasto][cykl] < NajkrotszaTrasa)
			{
				NajkrotszaTrasa = Graf[cykl][KolejneMiasto];
				ObecnaTrasa = Graf[cykl][KolejneMiasto];
				NM = KolejneMiasto;
			}
		}
	}
	if (NajkrotszaTrasa != INT16_MAX)
		Trasa += ObecnaTrasa;
	return NM;
}

int TSP(int Miasto)
{
	long NastepneMiasto;
	UkonczoneMiasta[Miasto] = 1;
	cout << Miasto << "--->";
	NastepneMiasto = CyklHamiltona(Miasto);
	if (NastepneMiasto == Silnia(LiczbaMiast))
	{
		NastepneMiasto = 0;
		cout << NastepneMiasto;
		Trasa += Graf[Miasto][NastepneMiasto];
		return 0;
	}
	TSP(NastepneMiasto);
}

int main()
{
	GrafFunc();
	cout << "\n\nSciezka:\n";
	TSP(0);
	cout << "\nNajkrotsza trasa: " << Trasa;
	return 0;
}