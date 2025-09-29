
#include <iostream>

using namespace std;

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

int main()
{
	int opcio, files;

	do {
		cout << "\n===== MENU DIBUIXOS =====" << endl;
		cout << "1. Triangle ple" << endl;
		cout << "2. Escala" << endl;
		cout << "3. Triangle buit" << endl;
		cout << "4. Triangle sencer" << endl;
		cout << "5. Diamant" << endl;
		cout << "Entra una opcio (1-5): ";
		cin >> opcio;

		if (opcio != 0) {
			cout << "Entra el nombre de files: ";
			cin >> files;
		}

		switch (opcio) {
		case 1: dibuixBucles1(files); break;
		case 2: dibuixBucles2(files); break;
		case 3: dibuixBucles3(files); break;
		case 4: dibuixBucles4(files); break;
		case 5: dibuixBucles5(files); break;
		default: cout << "Opcio invalida" << endl; break;
		}
	} while (opcio != 0);
}