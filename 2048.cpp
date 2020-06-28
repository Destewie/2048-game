#include <iostream>
#include <Windows.h>
#include <cstdlib>			//serve per la funzione del numero random
#include <ctime>			//serve per generare un numero usando il tempo del computer. numero che dopo andrà passato alla funzione srand, che a sua volta comunicherà con il rand per dare un numero casuale
using namespace std;

enum colors {def = 15, due = 714, quattro = 618, otto = 945, unosei = 636, tredue = 987, seiquattro = 956, unodueotto = 752, duecinquesei =626 , cinqueunodue = 859, unozeroduequattro = 1020, duezeroquattrootto = 1005};

void Color(colors color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

const int DIM = 6;		//sono 4x4 per il campo + una cornice di 0;
int SCORE = 0;

int main();

void Inizializza(int M[DIM][DIM]);
void Visualizza(int M[DIM][DIM]);
void CopiaMatrix(int M[DIM][DIM], int M1[DIM][DIM]);
bool MatrixDiverse(int M[DIM][DIM], int M1[DIM][DIM]);
bool Movimento(int M[DIM][DIM], int M1[DIM][DIM]);
void Inserimento(int M[DIM][DIM]);
bool Fine(int M[DIM][DIM]);

int main()
{

			int Campo[DIM][DIM], CampoTemp[DIM][DIM];
			bool mosso = false, morto;

			Color(def);

			Inizializza(Campo);
			Inizializza(CampoTemp);
			Inserimento(Campo);
			CopiaMatrix(Campo, CampoTemp);
			Visualizza(Campo);
			cout << endl << "Per giocare usa le frecette!\n";

			do
			{
				do
				{
					mosso = Movimento(Campo, CampoTemp);
				} while (mosso == false);

				Visualizza(Campo);
				Inserimento(Campo);
				CopiaMatrix(Campo, CampoTemp);
				Sleep(230);
				Visualizza(Campo);
				
				morto = Fine(Campo);
				
			} while (morto == false);

			cout << "Mi Dispiace, sei morto.\nIn compenso hai totalizzato un punteggio da capogiro, ben " << SCORE << " punti!";
			system("pause>nul");
			return 0;

}

//----------------------------------------------------------------------------------------------------------- Inizializza

void Inizializza(int M[DIM][DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			M[i][j] = 0;
		}
	}
}

//----------------------------------------------------------------------------------------------------------- Visualizza


void Visualizza(int M[DIM][DIM])
{
	system("cls");
	cout << "     	   2048\n\n\n";
	for (int i = 1; i<DIM-1; i++)
	{
		for (int j = 1; j<DIM-1; j++)
		{
			if (M[i][j] == 0)			//se 0 vuol dire che è una casella ignuda
			{
				cout << "_\t";
			}
			else
			{
				if (M[i][j] == 2)			
				{
					Color(due);
					cout << M[i][j];
					Color(def);
					cout << "\t";
				}
				if (M[i][j] == 4)
				{
					Color(quattro);
					cout << M[i][j];
					Color(def);
					cout << "\t";
				}
				if (M[i][j] == 8)
				{
					Color(otto);
					cout << M[i][j];
					Color(def);
					cout << "\t";
				}
				if (M[i][j] == 16)
				{
					Color(unosei);
					cout << M[i][j];
					Color(def);
					cout << "\t";
				}
				if (M[i][j] == 32)
				{
					Color(tredue);
					cout << M[i][j];
					Color(def);
					cout << "\t";
				}
				if (M[i][j] == 64)
				{
					Color(seiquattro);
					cout << M[i][j];
					Color(def);
					cout << "\t";
				}
				if (M[i][j] == 128)
				{
					Color(unodueotto);
					cout << M[i][j];
					Color(def);
					cout << "\t";
				}
				if (M[i][j] == 256)
				{
					Color(duecinquesei);
					cout << M[i][j];
					Color(def);
					cout << "\t";
				}
				if (M[i][j] == 512)
				{
					Color(cinqueunodue);
					cout << M[i][j];
					Color(def);
					cout << "\t";
				}
				if (M[i][j] == 1024)
				{
					Color(unozeroduequattro);
					cout << M[i][j];
					Color(def);
					cout << "\t";
				}
				if (M[i][j] == 2048)
				{
					Color(duezeroquattrootto);
					cout << M[i][j];
					Color(def);
					cout << "\t";
				}
				if(M[i][j] != 0 && M[i][j] != 2 && M[i][j] != 4 && M[i][j] != 8 && M[i][j] != 16 && M[i][j] != 32 && M[i][j] != 64 && M[i][j] != 128 && M[i][j] != 256 && M[i][j] != 512 && M[i][j] != 1024 && M[i][j] != 2048)
				{
					cout << M[i][j] << "\t";
				}
				
			}

			

		}
		if(i==1)	cout << "\tScore: " << SCORE;
		cout << endl<<endl<<endl;
	}

	cout << endl << "   ";

}

//--------------------------------------------------------------------------------------------------------------------------- Copia le matrici

void CopiaMatrix(int M[DIM][DIM], int M1[DIM][DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			M1[i][j] = M[i][j];
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------------- Confronta Matrici

bool MatrixDiverse(int M[DIM][DIM], int M1[DIM][DIM])
{
	for (int i = 1; i < DIM - 1; i++)
	{
		for (int j = 1; j < DIM - 1; j++)
		{
			if (M1[i][j] != M[i][j])
			{
				return true;
			}
		}
	}
	return false;
}

//--------------------------------------------------------------------------------------------------------------------------- Movimento

bool Movimento(int M[DIM][DIM], int M1[DIM][DIM])
{
	bool spostato;

	spostato = false;

	if (GetAsyncKeyState(VK_UP))
	{

		for (int x = 0; x < 3; x++)				//lo fai TOT volte per avere tutto a posto ordinato prima di sommare le caselle
		{
			for (int j = 1; j < DIM - 1; j++)
			{
				for (int i = DIM -1; i > 1; i--)
				{
					if (i != 1)
					{
						if (M[i - 1][j] == 0)
						{
							M[i - 1][j] = M[i][j];
							M[i][j] = 0;
						}
					}
				}
			}
		}

		for (int i = 1; i < DIM - 1; i++)					//dopo che hai ordinato, unisci le caselle
		{
			for (int j = 1; j < DIM - 1; j++)
			{
				if (M[i][j] != 0)
				{
					if (M[i][j] == M[i + 1][j])
					{
						M[i + 1][j] = 0;
						M[i][j] *= 2;
						SCORE += M[i][j];
					}
				}
			}
		}

		for (int x = 0; x < 2; x++)				//lo fai TOT volte per avere tutto a posto ordinato dopo aver sommato le caselle 
		{
			for (int j = 1; j < DIM - 1; j++)
			{
				for (int i = DIM - 1; i > 1; i--)
				{
					if (i != 1)
					{
						if (M[i - 1][j] == 0)
						{
							M[i - 1][j] = M[i][j];
							M[i][j] = 0;
						}
					}
				}
			}
		}

		spostato = MatrixDiverse(M, M1);   //per fare le cose fatte bene bisognerebbe fare una seconda matrice e dire che si è mosso quando la matrice secondaria (che è ferma all'istante prima) è diversa da quella attuale
		return spostato;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{

		for (int x = 0; x < 3; x++)				//lo fai TOT volte per avere tutto a posto ordinato prima di sommare le caselle
		{
			for (int i = 1; i < DIM - 1; i++)
			{
				for (int j = 1; j < DIM - 1; j++)
				{
					if (j != 4)
					{
						if (M[i][j + 1] == 0)
						{
							M[i][j + 1] = M[i][j];
							M[i][j] = 0;
						}
					}
				}
			}
		}

		for (int j = DIM - 1; j > 1; j--)
		{
			for (int i = 1; i < DIM - 1; i++)
			{
				if (M[i][j] != 0)
				{
					if (M[i][j] == M[i][j - 1])
					{
						M[i][j - 1] = 0;
						M[i][j] *= 2;
						SCORE += M[i][j];
					}
				}
			}
		}

		for (int x = 0; x < 2; x++)				//lo fai TOT volte per avere tutto a posto ordinato dopo aver sommato le caselle 
		{
			for (int i = 1; i < DIM - 1; i++)
			{
				for (int j = 1; j < DIM - 1; j++)
				{
					if (j != 4)
					{
						if (M[i][j + 1] == 0)
						{
							M[i][j + 1] = M[i][j];
							M[i][j] = 0;
						}
					}
				}
			}
		}

		spostato = MatrixDiverse(M, M1);
		return spostato;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{

		for (int x = 0; x < 3; x++)				//lo fai TOT volte per avere tutto a posto ordinato prima di sommare le caselle
		{
			for (int j = 1; j < DIM - 1; j++)
			{
				for (int i = 1; i < DIM - 1; i++)
				{
					if (i != 4)
					{
						if (M[i + 1][j] == 0)
						{
							M[i + 1][j] = M[i][j];
							M[i][j] = 0;
						}
					}
				}
			}
		}

		for (int i = DIM-1; i >1; i--)					//dopo che hai ordinato, unisci le caselle
		{
			for (int j = 1; j < DIM - 1; j++)
			{
				if (M[i][j] != 0)
				{
					if (M[i][j] == M[i - 1][j])
					{
						M[i - 1][j] = 0;
						M[i][j] *= 2;
						SCORE += M[i][j];
					}
				}
			}
		}

		for (int x = 0; x < 2; x++)				///lo fai TOT volte per avere tutto a posto ordinato dopo aver sommato le caselle 
		{
			for (int j = 1; j < DIM - 1; j++)
			{
				for (int i = 1; i < DIM - 1; i++)
				{
					if (i != 4)
					{
						if (M[i + 1][j] == 0)
						{
							M[i + 1][j] = M[i][j];
							M[i][j] = 0;
						}
					}
				}
			}
		}

		spostato = MatrixDiverse(M, M1);
		return spostato;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{

		for (int x = 0; x < 3; x++)				//lo fai TOT volte per avere tutto a posto ordinato prima di sommare le caselle
		{
			for (int i = 1; i < DIM - 1; i++)
			{
				for (int j = DIM - 1; j > 1; j--)
				{
					if (j != 1)
					{
						if (M[i][j - 1] == 0)
						{
							M[i][j - 1] = M[i][j];
							M[i][j] = 0;
						}
					}
				}
			}
		}

		for (int j = 1; j < DIM; j++)
		{
			for (int i = 1; i < DIM - 1; i++)
			{
				if (M[i][j] != 0)
				{
					if (M[i][j] == M[i][j + 1])
					{
						M[i][j + 1] = 0;
						M[i][j] *= 2;
						SCORE += M[i][j];
					}
				}
			}
		}

		for (int x = 0; x < 2; x++)				//lo fai TOT volte per avere tutto a posto ordinato dopo aver sommato le caselle 
		{
			for (int i = 1; i < DIM - 1; i++)
			{
				for (int j = DIM - 1; j > 1; j--)
				{
					if (j != 1)
					{
						if (M[i][j - 1] == 0)
						{
							M[i][j - 1] = M[i][j];
							M[i][j] = 0;
						}
					}
				}
			}
		}

		spostato = MatrixDiverse(M, M1);
		return spostato;
	}
	
	return false;
}


	//--------------------------------------------------------------------------------------------------------------------------- Inserimento
void Inserimento(int M[DIM][DIM])
{
	int col, rig;
	srand(time(0));		
	
	do
	{									// da un numero basandosi sull'ora del pc
		col = 1 + (rand() % 4);
		rig = 1 + (rand() % 4);

	} while (M[rig][col] != 0);

	M[rig][col] = 2;
}

//---------------------------------------------------------------------------------------------------------------------------- Morto

bool Fine(int M[DIM][DIM])
{
	for (int i = 1; i < DIM - 1; i++)
	{
		for (int j = 1; j < DIM - 1; j++)
		{
			if (M[i][j] != 0)
			{
				if (M[i - 1][j] == M[i][j])
				{
					return false;
				}
				if (M[i][j + 1] == M[i][j])
				{
					return false;
				}
				if (M[i + 1][j] == M[i][j])
				{
					return false;
				}
				if (M[i][j - 1] == M[i][j])
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}
