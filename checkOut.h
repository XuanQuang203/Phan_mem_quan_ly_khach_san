#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <iostream>
using namespace std;

class checkOut {
protected:
    struct ngayThangNam {
        int ngay, thang, nam;

        ngayThangNam() {}
        ngayThangNam(int _ngay, int _thang, int _nam) : ngay(_ngay), thang(_thang), nam(_nam) {}
    } ntn;

    struct thoiGianCO {
        ngayThangNam ngayRa;
        int gioRa;

        thoiGianCO() {}
        thoiGianCO(ngayThangNam _ngayRa, int _gioRa) : ngayRa(_ngayRa), gioRa(_gioRa) {}
    } co;

public:
    bool kt_yy(int yy);
    bool yy_nhuan(int yy);
    int kt_mm(int mm, int yy);
    bool kt_dd(int dd, int mm, int yy);
    void nhap_checkOut();
    int get_ngayRa();
    void set_ngayRa(int _ngayRa);
    int get_gioRa();
    void set_gioRa(int _gioRa);
    void xoa_checkOut();
    void xuat_checkOut();

    friend class thanhToan;
};

#endif // CHECKOUT_H

