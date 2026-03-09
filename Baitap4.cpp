#include<iostream>
#include<limits>
using namespace std;

struct Ngaytotinhem {
	int Ngay;
	int Thang;
	int Nam;
};
bool Namnhuan(int a) {
	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {
		return true;
	}
	else return false;
}
int Songaytrongthang(int Nam, int Thang) {
	if (Thang == 4 || Thang == 6 || Thang == 9 || Thang == 11) {
		return 30;
	}
	else if (Thang == 2) {
		return Namnhuan(Nam) ? 29 : 28;
	} 
	return 31;
}



bool Kiemtra(Ngaytotinhem& conguoiiu){
	if (conguoiiu.Nam < 0 || conguoiiu.Thang < 1 || conguoiiu.Thang>12 || conguoiiu.Ngay < 1 || Songaytrongthang(conguoiiu.Nam, conguoiiu.Thang) < conguoiiu.Ngay) {
		return false;
	} 
	return true;
}
void Nhap(Ngaytotinhem& conguoiiu) {
	while (true) {
		if (!(cin >> conguoiiu.Ngay >> conguoiiu.Thang >> conguoiiu.Nam)) {
			cout << "Chi nhap so tu nhien! (nhap lai ngay, thang, nam!)";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (Kiemtra(conguoiiu)) {
			break;
		}
		else cout << "Nhap lai ngay thang nam! ";
		
	}
}
void Xuat(Ngaytotinhem& conguoiiu) {
	conguoiiu.Ngay++;

	if (conguoiiu.Ngay > Songaytrongthang( conguoiiu.Nam, conguoiiu.Thang)) {
		conguoiiu.Ngay = 1;
		conguoiiu.Thang++;
		if (conguoiiu.Thang > 12) {
			conguoiiu.Thang = 1;
			conguoiiu.Nam++;
		}
	}
	cout << conguoiiu.Ngay << "/" << conguoiiu.Thang << "/" << conguoiiu.Nam;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Ngaytotinhem conguoiiu;
	Nhap(conguoiiu);
	Xuat(conguoiiu);

}
