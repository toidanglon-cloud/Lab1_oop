#include<iostream>
#include<limits>
#include<cmath>
using namespace std;

int UCLN(int a, int b) {
	a = abs(a);
	b = abs(b);

	if (b == 0) return a;
	return UCLN(b, a % b);
}


struct Phanso {
	int tu;
	int mau;
};
void Rutgon(Phanso& ps) {
	if (ps.tu == 0) {
		ps.mau = 1;
		return;
	}
	int ucln = UCLN(ps.tu, ps.mau);
	ps.tu /= ucln;
	ps.mau /= ucln;
	
}
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
void InPhanso(Phanso& ps) {
	Rutgon(ps);
	if (ps.mau == 1) {
		cout << ps.tu;
	}
	else cout << ps.tu << "/" << ps.mau;
}

void Xuat(Phanso& ps1, Phanso& ps2) {
	Phanso tong, hieu, tich, thuong;
	tong.tu = ps1.tu * ps2.mau + ps1.mau * ps2.tu;
	tong.mau = ps1.mau * ps2.mau;
	cout << "Tong cua hai phan so la: "; InPhanso(tong); cout << '\n';
	
	hieu.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
	hieu.mau = ps1.mau * ps2.mau;
	cout << "Hieu cua hai phan so la: "; InPhanso(hieu); cout << '\n';

	tich.tu = ps1.tu * ps2.tu;
	tich.mau = ps1.mau * ps2.mau;
	cout << "Tich cua hai phan so la: "; InPhanso(tich);cout << '\n';

	if (ps2.tu == 0) {
		cout << "Khong the thuc hien phep chia!";
	}
	else {
		thuong.tu = ps1.tu * ps2.mau;
		thuong.mau = ps1.mau * ps2.tu;
		cout << "Thuong cua hai phan so la: "; InPhanso(thuong);
	}
	
	

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
