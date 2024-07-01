#include "thanhToan.h"

thanhToan::thanhToan() : soNgayThue(0), soGioThue(0), thanhTien(0) {}

void thanhToan::khachThanhToan() {
    int x, y;

    x = checkOut::get_ngayRa() - checkIn::get_ngayVao();
    if (x == 0) {
        y = checkOut::get_gioRa() - checkIn::get_gioVao();
    } else if (x > 0) {
        y = (x * 24) + (checkOut::get_gioRa() - checkIn::get_gioVao());
    } else {
        cout << "Loi tinh toan, vui long kiem tra lai thong tin da nhap!\n";
        return;
    }

    if (y == 0) {
        cout << "Loi tinh toan, vui long kiem tra lai thong tin da nhap!\n";
        return;
    }

    thanhTien = x * giaNgay + y * giaGio;

    cout << "\nHOA DON\n";
    cout << "---------------------\n";
    cout << "Thong tin thanh toan: \n";
    if (x == 0) {
        cout << "Tong so gio thue: " << y << endl;
    } else if (x > 0) {
        cout << "So ngay thue: " << x << endl;
        cout << "Tong so gio thue: " << y << endl;
    }
    cout << "\nThanh tien: " << thanhTien << " nghin vnd" << endl;

    int luaChon;
    cout << "---------------------\n";
    cout << "Phuong thuc thanh toan:\n";
    cout << "01. Tien mat\n";
    cout << "02. Chuyen khoan\n";
    cout << "---------------------\n";

    while (true) {
        cout << "Khach chon: ";
        cin >> luaChon;

        if (luaChon == 1) {
            cout << "\nXAC NHAN PHUONG THUC: Tien mat\n";
            break;
        } else if (luaChon == 2) {
            cout << "\nXAC NHAN PHUONG THUC: Chuyen khoan\n";
            break;
        } else {
            cout << "Loi nhap, vui long thu lai!\n";
        }
    }

    cout << "---------------------\n\n";
    cout << "Cam on quy khach da su dung dich vu! \n----------------------------------------------------\n";
}

