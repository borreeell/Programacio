#include <iostream>
#include <ctime>

using namespace std;

time_t t = time(nullptr);
tm tm_struct;

int now = localtime_s(&tm_struct, &t);
int anyActual = tm_struct.tm_year + 1900;

static void exercici1()
{
	int edat;
	int edatMinima = 14;
	 
	cout << "Entra la teva edat: ";
	cin >> edat;

	if (edat >= edatMinima) {
		cout << "Pots accedir a instagram";
	}
	else {
		int anysRestants = edatMinima - edat;
		int anyEntrada = anyActual + anysRestants;
		cout << "Podras entrar a: " << anyEntrada << endl;
	}
}

static void exercici2()
{
	int anyNaixement;

	cout << "Entra l'any de naixement: " << endl;
	cin >> anyNaixement;

	int edat = anyActual - anyNaixement;

	cout << "L'edat actual es: " << edat << endl;
}

static void exercici3()
{
	int vidaActual, dany;

	cout << "Entra la vida del jugador: ";
	cin >> vidaActual;

	cout << "Introdueix el dany rebut: ";
	cin >> dany;

	vidaActual -= dany;

	if (vidaActual <= 0) {
		cout << "Game Over" << endl;
	}
	else {
		cout << "Encara tens: " << vidaActual << "punts de vida" << endl;
	}
}

int main()
{
	exercici1();

	return 0;
}