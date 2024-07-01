#include "checkOut.h"

string checkOut::dinhDangThoiGian(int value) {
	if (value < 10) {
        return "0" + to_string(value);
    } else {
        return to_string(value);
    }
}

bool checkOut::kt_gio(int _gio) {
        return _gio >= 0 && _gio <= 23;
    }

bool checkOut::kt_phut(int _phut) {
    return _phut >= 0 && _phut <= 59;
}

bool checkOut::kt_yy(int yy) {
    return yy >= 2024;
}

bool checkOut::yy_nhuan(int yy) {
    return (yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0);
}

int checkOut::kt_mm(int mm, int yy) {
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

bool checkOut::kt_dd(int dd, int mm, int yy) {
    int maxDay = kt_mm(mm, yy);
    return dd >= 1 && dd <= maxDay;
}

void checkOut::nhap_checkOut() {
    do {
        cout << "Ngay check-in (dd mm yyyy): ";
        cin >> dmy.ngay >> dmy.thang >> dmy.nam;

        if (!kt_yy(dmy.nam) || !kt_mm(dmy.thang, dmy.nam) || !kt_dd(dmy.ngay, dmy.thang, dmy.nam)) {
            cout << "Khong hop le, vui long nhap lai!\n";
            cout << "---------------------\n";
        }
    } while (!kt_yy(dmy.nam) || !kt_mm(dmy.thang, dmy.nam) || !kt_dd(dmy.ngay, dmy.thang, dmy.nam));
    co.ngayRa = dmy;
    
    do {
        cout << "Gio check-in (h:min): ";
        cin >> hms.gio >> hms.phut;

        if (!kt_gio(hms.gio) || !kt_phut(hms.phut)) {
            cout << "Khong hop le, vui long nhap lai!\n";
            cout << "---------------------\n";
        }
    } while (!kt_gio(hms.gio) || !kt_phut(hms.phut));
    co.gioRa = hms;
}

int checkOut::get_gioRa() {
    return co.gioRa.gio;
}

void checkOut::set_gioRa(int _gioRa) {
	co.gioRa.gio = _gioRa;
}

int checkOut::get_phutRa() {
    return co.gioRa.phut;
}

void checkOut::set_phutRa(int _phutRa) {
    co.gioRa.phut = _phutRa;
}

int checkOut::get_ngayRa() {
	return co.ngayRa.ngay;
}

void checkOut::set_ngayRa(int _ngayRa) {
	co.ngayRa.ngay = _ngayRa;
}

int checkOut::get_thangRa() {
	return co.ngayRa.thang;
}

void checkOut::set_thangRa(int _thangRa){
	co.ngayRa.thang = _thangRa;
}

int checkOut::get_namRa() {
	return co.ngayRa.nam;
}

void checkOut::set_namRa(int _namRa){
	co.ngayRa.nam = _namRa;
}

void checkOut::sua_checkOut() {
	int luaChon, sua[5];
	cout << "\nSUA THOI GIAN CHECK-OUT\n";
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
	        set_gioRa(sua[0]);
	        set_phutRa(sua[1]);
	    	break;
	        
	    case 2:
	        cout << "Nhap ngay/thang/nam: ";
	    	cin >> sua[0] >> sua[1] >> sua[2];
	        set_ngayRa(sua[0]);
	        set_thangRa(sua[1]);
	        set_namRa(sua[2]);
	    	break;
	    
		case 3:	
		    cout << "Nhap gio:phut: ";
	    	cin >> sua[0] >> sua[1];
	        set_gioRa(sua[0]);
	        set_phutRa(sua[1]);
	        
	        cout << "Nhap ngay/thang/nam: ";
	    	cin >> sua[2] >> sua[3] >> sua[4];
	        set_ngayRa(sua[2]);
	        set_thangRa(sua[3]);
	        set_namRa(sua[4]);
	    	break;
	    	
	    case 0:
	    	break;
	}
}

void checkOut::xoa_checkOut() {
    co.gioRa.gio = 0;
    co.gioRa.phut = 0;
    co.ngayRa.ngay = 0;
    co.ngayRa.thang = 0;
    co.ngayRa.nam = 0;
}

void checkOut::xuat_checkOut() {
	string dinhDangGio = dinhDangThoiGian(co.gioRa.gio);
	string dinhDangPhut = dinhDangThoiGian(co.gioRa.phut);
	
	string dinhDangNgay = dinhDangThoiGian(co.ngayRa.ngay);
	string dinhDangThang = dinhDangThoiGian(co.ngayRa.thang);
	string dinhDangNam = to_string(co.ngayRa.nam);
	
    cout << "Gio check-out: " << dinhDangGio << ":" << dinhDangPhut << endl;
    cout << "Ngay check-out: " << dinhDangNgay << "/" << dinhDangThang << "/" << dinhDangNam << endl;
}

