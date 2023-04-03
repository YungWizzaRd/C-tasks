/*
Aleksejs Gerasimovs St.apl.kods:ag21275

B8.Doti trīs naturāli skaitļi.Noteikt, vai starp dotajiem skaitļiem ir tāds,
kura ciparu summa ir vienāda ar pārējo divu skaitļu starpību.
Ja ir, izdrukāt šo skaitli.Skaitļu dalīšana ciparos jāveic skaitliski.
Risinājumā izmantot funkciju, kas aprēķina skaitļa ciparu summu.
*/
#include <iostream>
using namespace std;

int sum(int x)
{
	int summa = 0;
	while (x != 0) {
		summa += x % 10;
		x /= 10;
	}
	return summa;
}
int main() {
	int x, y, z, ok = 0;
	do {
		cin >> x >> y >> z;
		if (x >= 0 && y >= 0 && z >= 0) {
			if (sum(x) == y - z || sum(x) == z - y) {
				cout << "Number which u find is " << x << endl;
			}
			else if (sum(y) == x - z || sum(y) == z - x) {
				cout << "Number which u find is " << y << endl;
			}
			else if (sum(z) == y - x || sum(z) == x - y) {
				cout << "Number which u find is " << z << endl;
			}
			else {
				cout << "Here is no number what you're searching" << endl;
			}

		}
		else {
			cout << "All numbers should be neutral" << endl;
		}
		cout << "Type (0) to finish or (1) to continue!" << endl;
		cin >> ok;
	} while (ok == 1);
	return 0;
}
/*

Input			Expectation										Result
123; 121; 127		123												+			*Šeit ir 2 pareizi skaitļi, gan 123, gan, bet balstoties uz uzdevuma definīciju
-15; 215; 13   All numbers should be neutral						+			vajag izfrukāt vismāz vienu. Citāts: "vai starp dotajiem skaitļiem ir tāds".
25; -7; 39		All numbers should be neutral						+
315 219 303			219												+
27; 14; 3     Here is no number what you are searching				+
*/