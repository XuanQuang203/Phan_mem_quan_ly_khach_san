#ifndef THANHTOAN_H
#define THANHTOAN_H

#include "datPhong.h"
#include "checkIn.h"
#include "checkOut.h"
#include "dichVu.h"

class thanhToan : public virtual datPhong, public virtual checkIn, public virtual checkOut, public virtual dichVu {
private:
    int soNgayThue, soGioThue, thanhTien;
    int giaNgay = 2500, giaGio = 150;

public:
    thanhToan();
    void khachThanhToan();
};

#endif // THANHTOAN_H

