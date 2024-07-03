#include "checkOut.h"

string checkOut::dinhDangThoiGian(int value) {
	if (value < 10) {
        return "0" + to_string(value);
    } else {
        return to_string(value);
    }
}

void checkOut::nhap_checkOut() {
	if (checkIn::get_ngayVao() == 0) {
		cout << "\nKhach chua check-in, vui long nhap check-in truoc!/n";
	} else {
		int luaChon;
		time_t now = time(0);
		tm *ltm = localtime(&now);
		
	    do {
	    	cout << "\n\nKHACH HANG CHECK-OUT";
	        cout << "\n---------------------";
	        cout << "\nThoi gian: " << ltm->tm_hour << ":" << ltm->tm_min << " " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year;
	        cout << "\n---------------------";
	        cout << "\n01. Dong y";
	        cout << "\n02. Huy bo";
	        cout << "\n---------------------";
	        cout << "\nNhap lua chon: ";
	        cin >> luaChon;
		    
		    switch (luaChon) {
		    	case 1:
				    dmy.ngay = ltm->tm_mday;
				    dmy.thang = 1 + ltm->tm_mon;
				    dmy.nam = 1900 + ltm->tm_year;
				    co.ngayRa = dmy;
				    
				    hms.gio = ltm->tm_hour;
				    hms.phut = ltm->tm_min;
				    co.gioRa = hms;
				    break;
				    
				case 2:
					cout << "DA HUY YEU CAU\n---------------------\n";
					break;
			}
		} while (luaChon <= 0 && luaChon > 2);
	}
    
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
	
	switch (luaChon) {
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
	    	
	    default:
	    	cout << "\nLoi nhap lua chon, vui long thu lai!\n";
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
	
    cout << "Ngay check-out: " << dinhDangNgay << "/" << dinhDangThang << "/" << dinhDangNam << endl;
    cout << "Gio check-out: " << dinhDangGio << ":" << dinhDangPhut << endl;
}

