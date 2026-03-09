#include<iostream>
#include<limits>
#include<cmath>
using namespace std;
int UCLN(int a, int b) {
	a = abs(a);
	b = abs(b);
	if (b == 0) return a;
	return UCLN(b ,a%b);
}
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
}
void Xuat(Phanso& ps) {
	int c = UCLN(ps.tu, ps.mau);
	
	ps.tu /= c;
	ps.mau /= c;
	if (ps.mau < 0) {
		ps.tu *= -1;
		ps.mau *= -1;
	}
	if (ps.mau == 1) {
		cout << ps.tu;
	}
	else if (ps.tu == 0) {
		cout << "0";
	}
	else cout << ps.tu << "/" << ps.mau;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Phanso ps;
	Nhap(ps);
	Xuat(ps);
}


