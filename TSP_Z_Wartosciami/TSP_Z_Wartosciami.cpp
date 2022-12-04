#include<iostream>
#include<climits>
using namespace std;

int Graf[4][4]
{
	{0,13,40,35},
	{13,0,15,7},
	{40,15,0,25},
	{35,7,25,0}
};

void WyswietlanieTablicy()
{
	cout << "\n\nTablica odleglosci pomiedzy miastami:\n";
	for (int i = 0; i < 4; i++)
		cout << "\tM" << i;
	for (int i = 0; i < 4; i++)
	{
		cout << "\n\nM" << i;
		for (int j = 0; j < 4; j++)
			cout << "\t" << Graf[i][j];
	}
}

int UkonczoneMiasta[4];
int Trasa = 0;

int CyklHamiltona(int cykl)
{
	int NM = 24;
	int ObecnaTrasa;
	int NajkrotszaTrasa = INT16_MAX;
	for (int KolejneMiasto = 0; KolejneMiasto < 4; KolejneMiasto++)
	{
		cout << "\n Wartosc KolejneMiasto w petli = " << KolejneMiasto;
		if ((Graf[cykl][KolejneMiasto] != 0) && (UkonczoneMiasta[KolejneMiasto] == 0))
		{
			cout << "\nPierwszy Warunek cyklu spelniny";
			if (Graf[cykl][KolejneMiasto] < NajkrotszaTrasa && Graf[KolejneMiasto][cykl] < NajkrotszaTrasa)
			{
				cout << "\nDrugi Warunek cyklu spelniony";
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
	int NastepneMiasto;
	UkonczoneMiasta[Miasto] = 1;
	cout << "\nUkonczoneMiasta[" << Miasto << "] = " << UkonczoneMiasta[Miasto];
	cout << "\n\n" << Miasto << "--->";
	NastepneMiasto = CyklHamiltona(Miasto);
	cout << "\nNastepneMiasto = " << NastepneMiasto;
	if (NastepneMiasto == 24)
	{
		cout << "\nPowrot do poczatku\n";
		NastepneMiasto = 0;
		cout << NastepneMiasto;
		Trasa += Graf[Miasto][NastepneMiasto];
		return 0;
	}
	TSP(NastepneMiasto);
}

int main()
{
	WyswietlanieTablicy();
	cout << "\n\nSciezka:\n"; TSP(0);
	cout << "\nNajkrotsza trasa: " << Trasa;
	return 0;
}