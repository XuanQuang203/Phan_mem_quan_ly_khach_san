#ifndef CHECKIN_H
#define CHECKIN_H

#include <iostream>
using namespace std;

class checkIn {
protected:
    int gioVao;

public:
    void nhap_checkIn();
    int get_gioVao();
    void set_gioVao(int _gioVao);
    void sua_checkIn(int gioVao);
    void xoa_checkIn();
    void xuat_checkIn();
    
    friend class thanhToan;
};

#endif // CHECKIN_H

