// HolaMon.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <locale.h> // setLocale
#include <string.h> // strcmp
#include <stdlib.h> // atoi

using namespace std;

// -------------------------------------
// Constants
// -------------------------------------

// Constants funcioClasse1
const int INFANTIL = 12;
const int JOVE = 17;
const int ADULT = 64;

static void gameStats()
{
	int score;
	double distance;
	char playAgain;
	bool shieldsUp;
	short lives, aliensKilled;
	double engineTemp = 6572.89;

	score = 0;
	distance = 12000.76;
	playAgain = 'y';
	shieldsUp = true;
	lives = 3;
	aliensKilled = 10;

	cout << "\nscore: " << score << endl;
	cout << "distance: " << distance << endl;
	cout << "playAgain: " << playAgain << endl;
	cout << "lives: " << lives << endl;
	cout << "aliensKilled: " << aliensKilled << endl;
	cout << "engineTemp: " << engineTemp << endl;
}

static void sortNumbers()
{
	cout << "Enter two numbers: ";
	int value1;
	int value2;
	cin >> value1 >> value2;

	if (value1 > value2) {
		int rememberValue1 = value1;
		value1 = value2;
		value2 = rememberValue1;
	}

	cout << "The input in sorted order: " << value1 << " " << value2 << endl;
}

static void computeAverage()
{
	int listSize;
	int numberProcessed = 0;
	double sum = 0;

	cout << "Enter the numbers to sum: ";
	cin >> listSize;

	while (numberProcessed < listSize) {
		double value;
		cout << "Enter value: ";
		cin >> value;
		sum += value;
		++numberProcessed;
	}
	double average = sum / numberProcessed;
	cout << "Average: " << average << endl;
}

static void variables1()
{
	int peus = 0;

	int polzades;
	polzades = 0;

	cout << "Peus: " << peus << endl;
	cout << "Polzades: " << polzades << endl;
}

static void variables2()
{
	int v1, v2, v3, v4, v5;

	v1 = rand();
	v2 = rand();
	v3 = rand();
	v4 = rand();
	v5 = rand();

	cout << "v1 " << v1 << endl;
	cout << "v2 " << v2 << endl;
	cout << "v3 " << v3 << endl;
	cout << "v4 " << v4 << endl;
	cout << "v5 " << v5 << endl;
}

static void variables3()
{
	double ftemp, ctemp;

	cout << "Enter fahrenheit temperature:";
	cin >> ftemp;

	ctemp = (ftemp - 32) / 1.8;

	cout << "Celsius temperature: " << ctemp << endl;
}

static void programacioEstructurada1()
{
	int edat;
	int anyActual = 2025;
	int edatMinima = 13;

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

static void programacioEstructurada2()
{
	// Obtenim el temps actual
	time_t t = time(nullptr);
	tm tm_struct;

	// Convertim a estructura tm local
	int now = localtime_s(&tm_struct, &t);

	// Guardem l'any actual en una variable
	int anyActual = tm_struct.tm_year + 1900;

	int anyNaixement;

	cout << "Entra l'any de naixement: " << endl;
	cin >> anyNaixement;

	int edat = anyActual - anyNaixement;

	cout << "L'edat actual es: " << edat << endl;
}

static void programacioEstructurada3()
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
		cout << "Encara tens: " << vidaActual << " punts de vida" << endl;
	}
}

static void bucles1()
{
	char continuar = 's'; // Variable per controlar si l'usuari vol continuar jugant (per defecte es Si)

	while (continuar == 's' || continuar == 'S') {
		// Generem dos numeros d'1 a 99
		int num1 = rand() % 99 + 1;
		int num2 = rand() % 99 + 1;

		// Calculem la resposta correcta
		int correcte = num1 + num2;

		int resposta;
		cout << "Quant fa " << num1 << " + " << num2 << "?";
		cin >> resposta;

		if (resposta == correcte) {
			cout << "Correcte" << endl;
		}
		else {
			cout << "Incorrecte. El resultat es: " << correcte << endl;
		}

		cout << "Vols tornar a jugar? (s/n)";
		cin >> continuar;
		cout << endl;
	}

	cout << "Fi." << endl;
}

static void bucles2()
{
	char continuar = 's'; // Variable per controlar si l'usuari vol continuar jugant (per defecte es Si)

	while (continuar == 's' || continuar == 'S') {
		// Generem dos numeros d'1 a 99
		int num1 = rand() % 99 + 1;
		int num2 = rand() % 99 + 1;

		// Calculem la resposta correcta
		int correcte = num1 + num2;

		// Genera aleatoriament dues possibles respostes mes
		int opcio1 = rand() % 99 + 1;
		int opcio2 = rand() % 99 + 1;

		// Barrejar l'ordre de les opcions
		int posCorrecte = rand() % 3 + 1;

		cout << "Quin es el resultat de: " << num1 << "+" << num2 << "?" << endl;

		switch (posCorrecte) {
		case 1:
			cout << "a) " << correcte << endl;
			cout << "b) " << opcio1 << endl;
			cout << "c) " << opcio2 << endl;
			break;
		case 2:
			cout << "a) " << opcio1 << endl;
			cout << "b) " << correcte << endl;
			cout << "c) " << opcio2 << endl;
			break;
		case 3:
			cout << "a) " << opcio1 << endl;
			cout << "b) " << opcio2 << endl;
			cout << "c) " << correcte << endl;
			break;
		}

		char resposta;
		cout << "Tria una opcio (a-c): " << endl;
		cin >> resposta;

		bool encert = false;

		switch (posCorrecte) {
			case 1: encert = (resposta == 1); break;
			case 2: encert = (resposta == 2); break;
			case 3: encert = (resposta == 3); break;
		}

		if (encert) {
			cout << "Correcte" << endl;
		}
		else {
			cout << "Incorrecte. La resposta correcta era: " << correcte << endl;
		}

		cout << "Vols tornar a jugar? (s/n)";
		cin >> continuar;
		cout << endl;
	}

	cout << "Fi." << endl;
}

static void bucles3()
{
	// Contar endevant
	cout << "Contar endavant: " << endl;
	for (int i = 0; i <= 9; i++) {
		cout << i << " ";
	}

	cout << endl << endl;

	// Contar endarrere
	cout << "Contar endarrere: " << endl;
	for (int i = 9; i >= 0; i--) {
		cout << i << " ";
	}

	cout << endl << endl;

	// Contar de cinc en cinc
	cout << "Contar de cinc en cinc: " << endl;
	for (int i = 0; i <= 50; i += 5) {
		cout << i << " ";
	}

	cout << endl << endl;

	// Contar amb declaracions nules
	cout << "Contar amb declaracions nules: " << endl;
	int j = 0;
	while (true) {
		cout << j << " ";
		j++;
		if (j > 9) break;
	}

	cout << endl << endl;

	// Contar amb bucles anidats
	cout << "Contar amb bucles anidats: " << endl;
	for (int x = 0; x <= 4; x++) {
		for (int y = 0; y <= 2; y++) {
			cout << x << "." << y << " ";
		}
		cout << endl;
	}
}

static void dibuixBucles1(int n)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cout << "*";
		cout << endl;
	}

	cout << endl;
}

static void dibuixBucles2(int n)
{
	for (int i = 1; i <= n; i++) {
		for (int espais = 1; espais <= n - i; espais++) cout << " ";
		for (int j = 1; j <= n; j++) cout << "*";
		cout << endl;
	}

	cout << endl;
}

static void dibuixBucles3(int n)
{
	for (int i = 1; i <= n; i++) {
		if (i == 1) cout << "*" << endl;
		else if (i == n) {
			for (int j = 1; j <= n; j++) cout << "*";
			cout << endl;
		}
		else {
			cout << "*";
			for (int j = 1; j <= i - 2; j++) cout << " ";
			cout << "*" << endl;
		}
	}

	cout << endl;
}

static void dibuixBucles4(int n)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cout << "*";
		cout << endl;
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) cout << "*";
		cout << endl;
	}

	cout << endl;
}

static void dibuixBucles5(int n)
{
	if (n % 2 == 0) n++;

	for (int i = 1; i <= n; i += 2) {
		int espais = (n - i) / 2;
		for (int j = 0; j < espais; j++) cout << " ";
		for (int j = 0; j < i; j++) cout << "*";
		cout << endl;
	}

	for (int i = n - 2; i >= 1; i -= 2) {
		int espais = (n - i) / 2;
		for (int j = 0; j < espais; j++) cout << " ";
		for (int j = 0; j < i; j++) cout << "*";
		cout << endl;
	}

	cout << endl;
}

static void stringsClasse1()
{
	char line[80];
	int count = 0;

	cout << "Enter a sentence of more than 79 characters:\n";
	cin.getline(line, 80);

	cout << "The sentence you entered is:\n";
	while (line[count] != '\0') {
		cout << line[count];
		count++;
	}
}

static void stringsClasse2()
{
	char input[20];
	int total = 0, count = 0;
	float average;

	cout << "This program will average a series of numbers:\n";
	cout << "Enter the first number or Q to quit: ";
	cin.getline(input, 20);

	while ((strcmp(input, "Q") != 0) && (strcmp(input, "q") != 0)) {
		total += atoi(input);
		count++;
		cout << "Enter the next number or Q to quit: ";
		cin.getline(input, 20);
	}

	if (count != 0) {
		average = total / count;
		cout << "Average: " << average << endl;
	}
}

string obtenirGrup(int edat) 
{
	if (edat <= INFANTIL) {
		return "Infantil";
	}
	else if (edat <= JOVE) {
		return "Jove";
	}
	else if (edat <= ADULT) {
		return "Adult";
	}
	else {
		return "Senior";
	}
}



int main()
{
	int opcio, files;

	srand(time(0)); // Inicialitzem srand per assegurar que les operacions de bucles1 i bucles2 no siguin repetitives

	setlocale(LC_CTYPE, "spanish"); // Posem el locale a spanish per poder imprimir accents per consola 

	//gameStats();
	//sortNumbers();
	//computeAverage();

	//variables1();
	//variables2();
	//variables3();

	//programacioEstructurada1();
	//programacioEstructurada2();
	//programacioEstructurada3();

	//bucles1();
	//bucles2();
	//bucles3();

	//do {
	//	cout << "\n===== MENU DIBUIXOS =====" << endl;
	//	cout << "1. Triangle ple" << endl;
	//	cout << "2. Escala" << endl;
	//	cout << "3. Triangle buit" << endl;
	//	cout << "4. Triangle sencer" << endl;
	//	cout << "5. Diamant" << endl;
	//	cout << "Entra una opcio (1-5): ";
	//	cin >> opcio;

	//	if (opcio != 0) {
	//		cout << "Entra el nombre de files: ";
	//		cin >> files;
	//	}

	//	switch (opcio) {
	//		case 1: dibuixBucles1(files); break;
	//		case 2: dibuixBucles2(files); break;
	//		case 3: dibuixBucles3(files); break;
	//		case 4: dibuixBucles4(files); break;
	//		case 5: dibuixBucles5(files); break;
	//		default: cout << "Opcio invalida" << endl; break;
	//	}
	//} while (opcio != 0);

	//stringsClasse1();
	//stringsClasse2();


}
