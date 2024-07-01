#include "checkIn.h"

string checkIn::dinhDangThoiGian(int value) {
	if (value < 10) {
        return "0" + to_string(value);
    } else {
        return to_string(value);
    }
}

bool checkIn::kt_gio(int _gio) {
        return _gio >= 0 && _gio <= 23;
    }

bool checkIn::kt_phut(int _phut) {
    return _phut >= 0 && _phut <= 59;
}

bool checkIn::kt_yy(int yy) {
    return yy >= 2024;
}

bool checkIn::yy_nhuan(int yy) {
    return (yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0);
}

int checkIn::kt_mm(int mm, int yy) {
    switch(mm) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return yy_nhuan(yy) ? 29 : 28;
        default:
            return 0;
    }
}

bool checkIn::kt_dd(int dd, int mm, int yy) {
    int maxDay = kt_mm(mm, yy);
    return dd >= 1 && dd <= maxDay;
}

void checkIn::nhap_checkIn() {
    do {
        cout << "Ngay check-in (dd mm yyyy): ";
        cin >> dmy.ngay >> dmy.thang >> dmy.nam;

        if (!kt_yy(dmy.nam) || !kt_mm(dmy.thang, dmy.nam) || !kt_dd(dmy.ngay, dmy.thang, dmy.nam)) {
            cout << "Khong hop le, vui long nhap lai!\n";
            cout << "---------------------\n";
        }
    } while (!kt_yy(dmy.nam) || !kt_mm(dmy.thang, dmy.nam) || !kt_dd(dmy.ngay, dmy.thang, dmy.nam));
    ci.ngayVao = dmy;
    
    do {
        cout << "Gio check-in (h:min): ";
        cin >> hms.gio >> hms.phut;

        if (!kt_gio(hms.gio) || !kt_phut(hms.phut)) {
            cout << "Khong hop le, vui long nhap lai!\n";
            cout << "---------------------\n";
        }
    } while (!kt_gio(hms.gio) || !kt_phut(hms.phut));
    ci.gioVao = hms;
}

int checkIn::get_gioVao() {
    return ci.gioVao.gio;
}

void checkIn::set_gioVao(int _gioVao) {
	ci.gioVao.gio = _gioVao;
}

int checkIn::get_phutVao() {
    return ci.gioVao.phut;
}

void checkIn::set_phutVao(int _phutVao) {
    ci.gioVao.phut = _phutVao;
}

int checkIn::get_ngayVao() {
	return ci.ngayVao.ngay;
}

void checkIn::set_ngayVao(int _ngayVao) {
	ci.ngayVao.ngay = _ngayVao;
}

int checkIn::get_thangVao() {
	return ci.ngayVao.thang;
}

void checkIn::set_thangVao(int _thangVao){
	ci.ngayVao.thang = _thangVao;
}

int checkIn::get_namVao() {
	return ci.ngayVao.nam;
}

void checkIn::set_namVao(int _namVao){
	ci.ngayVao.nam = _namVao;
}

void checkIn::sua_checkIn() {
	int luaChon, sua[5];
	cout << "\nSUA THOI GIAN CHECK-IN\n";
	cout << "01. Sua gio phut (h:min): \n";
	cout << "02. Sua ngay thang nam (dd/mm/yyyy): \n";
	cout << "03. Ca hai (h:min) (dd/mm/yyyy): \n";
	cout << "00. Thoat chinh sua\n";
	cout << "Nhap lua chon: ";
	cin >> luaChon;
	
	switch(luaChon) {
	    case 1:
	    	cout << "Nhap gio:phut: ";
	    	cin >> sua[0] >> sua[1];
	        set_gioVao(sua[0]);
	        set_phutVao(sua[1]);
	    	break;
	        
	    case 2:
	        cout << "Nhap ngay/thang/nam: ";
	    	cin >> sua[0] >> sua[1] >> sua[2];
	        set_ngayVao(sua[0]);
	        set_thangVao(sua[1]);
	        set_namVao(sua[2]);
	    	break;
	    
		case 3:	
		    cout << "Nhap gio:phut: ";
	    	cin >> sua[0] >> sua[1];
	        set_gioVao(sua[0]);
	        set_phutVao(sua[1]);
	        
	        cout << "Nhap ngay/thang/nam: ";
	    	cin >> sua[2] >> sua[3] >> sua[4];
	        set_ngayVao(sua[2]);
	        set_thangVao(sua[3]);
	        set_namVao(sua[4]);
	    	break;
	    	
	    case 0:
	    	break;
	}
}

void checkIn::xoa_checkIn() {
    ci.gioVao.gio = 0;
    ci.gioVao.phut = 0;
    ci.ngayVao.ngay = 0;
    ci.ngayVao.thang = 0;
    ci.ngayVao.nam = 0;
}

void checkIn::xuat_checkIn() {
	string dinhDangGio = dinhDangThoiGian(ci.gioVao.gio);
	string dinhDangPhut = dinhDangThoiGian(ci.gioVao.phut);
	
	string dinhDangNgay = dinhDangThoiGian(ci.ngayVao.ngay);
	string dinhDangThang = dinhDangThoiGian(ci.ngayVao.thang);
	string dinhDangNam = to_string(ci.ngayVao.nam);
	
    cout << "Gio check-in: " << dinhDangGio << ":" << dinhDangPhut << endl;
    cout << "Ngay check-in: " << dinhDangNgay << "/" << dinhDangThang << "/" << dinhDangNam << endl;
}

