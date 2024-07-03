#ifndef THANHTOAN_H
#define THANHTOAN_H

#include "datPhong.h"
#include "checkIn.h"
#include "checkOut.h"
#include "dichVu.h"

#pragma once

class thanhToan : public virtual datPhong, public virtual checkIn, public virtual checkOut, public virtual dichVu {
    private:
        double thanhTien;
        double giaNgay = 2500, giaGio = 150;

        double chuyenDoiThoiGian();

    public:
        thanhToan();
        void khachThanhToan();
};

#endif // THANHTOAN_H

