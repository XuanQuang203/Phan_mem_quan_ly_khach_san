#include "checkIn.h"

string checkIn::dinhDangThoiGian(int value) {
	if (value < 10) {
        return "0" + to_string (value);
    } else {
        return to_string (value);
    }
}

void checkIn::nhap_checkIn() { 
	int luaChon;
	time_t now = time (0);
	tm *ltm = localtime (&now);
	
    do {
    	cout << "\n\nKHACH HANG CHECK-IN";
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
			    ci.ngayVao = dmy;
			    
			    hms.gio = ltm->tm_hour;
			    hms.phut = ltm->tm_min;
			    ci.gioVao = hms;
			    break;
			    
			case 2:
				break;
		}
	} while (luaChon <= 0 && luaChon > 2);
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

void checkIn::set_thangVao(int _thangVao) {
	ci.ngayVao.thang = _thangVao;
}

int checkIn::get_namVao() {
	return ci.ngayVao.nam;
}

void checkIn::set_namVao(int _namVao) {
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
	
	switch (luaChon) {
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
	    	
	    default:
	    	cout << "\nLoi nhap lua chon, vui long thu lai!\n";
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
	
    cout << "Ngay check-in: " << dinhDangNgay << "/" << dinhDangThang << "/" << dinhDangNam << endl;
	cout << "Gio check-in: " << dinhDangGio << ":" << dinhDangPhut << endl;
}

