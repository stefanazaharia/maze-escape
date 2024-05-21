#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define Latime 8
#define Inaltime 8

int tablaJoc[Latime][Inaltime] =
{
		{ -2, -2, -2, -2, -2, -3, -2, -2 },
		{ -2, -1, -1, -1, -1, -1, -1, -2 },
		{ -2, -1, -2, -2, -2, -2, -1, -2 },
		{ -2, -1, -2, 0, -2, -1, -1, -2 },
		{ -2, -1, -2, -1, -2, -2, -1, -2 },
		{ -2, -1, -2, -1, -2, -1, -1, -2 },
		{ -2, -1, -1, -1, -1, -1, -1, -2 },
		{ -2, -2, -2, -2, -2, -2, -2, -2 }
	  };
void desenTabla()
{
    for (int x = 0; x < Latime; x++)
    {
        for (int y = 0; y < Inaltime; y++)
        {
            string carAfisat;

            if (tablaJoc[x][y] == 0)
                carAfisat = "S";
            else if (tablaJoc[x][y] == -3)
                carAfisat = "D";
            else if (tablaJoc[x][y] == -2)
                carAfisat = "#";
            else if (tablaJoc[x][y] == -1)
                carAfisat = " ";
            else
                carAfisat = to_string(tablaJoc[x][y]);

            cout <<setw(3) << carAfisat << "  ";
        }
     cout << endl << endl ;
    }
}

int determinCale()
{
    bool gasitFinal = false;
    int pas = 0;

    while (!gasitFinal)
    {
        bool gasitLiber = false;
        for (int x = 0; x < Latime && !gasitFinal; ++x)
        {
            for (int y = 0; y < Inaltime; ++y)
            {
                if (tablaJoc[x][y] == pas)
                {
                    // Dreapta
                    if (x < Latime - 1)
                    {
                        int &dreapta = tablaJoc[x + 1][y];
                        if (dreapta == -3)
                        {
                            gasitFinal = true;
                            x=Latime;
                        }
                        else if (dreapta == -1)
                        {
                            dreapta = pas + 1;
                            gasitLiber = true;
                        }
                    }

                    // Stanga
                    if (x > 0)
                    {
                        int &stanga = tablaJoc[x - 1][y];
                        if (stanga == -3)
                        {
                            gasitFinal = true;
                            x=Latime;
                        }
                        else if (stanga == -1)
                        {
                            stanga = pas + 1;
                            gasitLiber = true;
                        }
                    }
                    // Sus
                    if (y > 0)
                    {
                        int &sus = tablaJoc[x][y - 1];
                        if (sus == -3)
                        {
                            gasitFinal = true;
                            x=Latime;
                        }
                        else if (sus == -1)
                        {
                            sus = pas + 1;
                            gasitLiber = true;
                        }
                    }
                    // Jos
                    if (y < Inaltime - 1)
                    {
                        int &jos = tablaJoc[x][y + 1];
                        if (jos == -3)
                        {
                            gasitFinal = true;
                            x = Latime;
                        }
                        else if (jos == -1)
                        {
                            jos = pas + 1;
                            gasitLiber = true;
                        }
                    }

                }
            }
        }

        if (!gasitFinal && !gasitLiber)
            return -1;

        pas++;
    }
 return pas;
}

int main()
{
    int pasi=-1;
    desenTabla();
    cout << endl << endl;
    pasi = determinCale();

    system("pause");

    if(pasi!=-1)
    {

       cout << endl<< "calea minima de iesire din labirint este:" << pasi << endl;
       cout << endl << endl;
       desenTabla();
    }
    else
        cout << "Nu exista solutie!"<< endl;


    system("pause");
    return 0;
}
