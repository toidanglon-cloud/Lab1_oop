#include<iostream>
#include<string>
#include<limits>
#include<iomanip>
using namespace std;

struct Thongtin{
	string Ho_ten;
	double Diem_toan;
	double Diem_van;
	double Diem_TB;

};
double Kiemtra() {
	double a;
	while (true) {
		if (!(cin >> a)) {
			cout << "Phai nhap so tu nhien! ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (a < 0 || a>10) {
			cout << "So diem khong hop le! ";
			continue;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return a;
	}

}

void DTB(Thongtin& Hocsinh) {
	cout << "Diem trung binh cua hoc sinh la: ";
	Hocsinh.Diem_TB= (Hocsinh.Diem_toan + Hocsinh.Diem_van) / 2.0;
	cout << fixed << setprecision(2)<< Hocsinh.Diem_TB;
}
void Nhap(Thongtin& Hocsinh) {
	while (true) {
		getline(cin, Hocsinh.Ho_ten);

		if (Hocsinh.Ho_ten.empty()) {
			cout << "Ten khong duoc de trong! Vui long nhap lai: ";
		}
		else {
			break;
		}
	}
	 Hocsinh.Diem_toan= Kiemtra();
	 Hocsinh.Diem_van= Kiemtra();
}
void Xuat(Thongtin& Hocsinh) {
	DTB(Hocsinh);
}

int main() {
	Thongtin Hocsinh;
	Nhap(Hocsinh);
	Xuat(Hocsinh);
}
