#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <iostream>
using namespace std;

class checkOut {
protected:
	struct gioPhutGiay {
        int gio, phut, giay;

        gioPhutGiay() {}

        gioPhutGiay(int _gio, int _phut, int _giay)
            : gio(_gio), phut(_phut), giay(_giay) {}
    } hms;
	
    struct ngayThangNam {
        int ngay, thang, nam;

        ngayThangNam() {}
        ngayThangNam(int _ngay, int _thang, int _nam) : ngay(_ngay), thang(_thang), nam(_nam) {}
    } dmy;

    struct thoiGianCO {
        ngayThangNam ngayRa;
        gioPhutGiay gioRa;

        thoiGianCO() {}
        thoiGianCO(ngayThangNam _ngayRa, gioPhutGiay _gioRa) : ngayRa(_ngayRa), gioRa(_gioRa) {}
    } co;

public:
	string dinhDangThoiGian(int value);
	
	bool kt_gio(int _gio);
    bool kt_phut(int _phut);
    
    bool kt_yy(int yy);
    bool yy_nhuan(int yy);
    int kt_mm(int mm, int yy);
    bool kt_dd(int dd, int mm, int yy);
    
    void nhap_checkOut();
    
    int get_gioRa();
	void set_gioRa(int _gioRa);
	int get_phutRa();
	void set_phutRa(int _phutRa);
	
	int get_ngayRa();
	void set_ngayRa(int _ngayRa);
	int get_thangRa();
	void set_thangRa(int _thangRa);
	int get_namRa();
	void set_namRa(int _namRa);
    
    void sua_checkOut();
    void xoa_checkOut();
    void xuat_checkOut();

    friend class thanhToan;
};

#endif //CHECKOUT_H

