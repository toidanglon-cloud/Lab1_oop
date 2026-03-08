#include<iostream>
#include<limits>
using namespace std;

struct Phanso {
	int tu;
	int mau;
};
void Nhap(Phanso& ps) {
	while (!(cin >> ps.tu >> ps.mau)) {
		cout << "Chi nhap so tu nhien! ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while (ps.mau == 0) {
		cout << "gia tri b: ";
		cin >> ps.mau;
	}
	if (ps.mau < 0) {
		ps.mau *= -1;
		ps.tu *= -1;
	}
}
void Xuat(Phanso& ps1, Phanso& ps2) {
	if (ps1.tu * ps2.mau == ps2.tu * ps1.mau) {

	}
	if (ps1.tu * ps2.mau < ps2.tu * ps1.mau) {
		cout << ps2.tu << "/" << ps2.mau;
	}else if (ps1.tu * ps2.mau == ps2.tu * ps1.mau) {
		cout << "Hai so bang nhau!";
	}
	else cout << ps1.tu << "/" << ps1.mau;
	
	

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Phanso ps1;
	Phanso ps2;
	Nhap(ps1);
	Nhap(ps2);
	Xuat(ps1, ps2 );

}






