#include "checkOut.h"

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
    cout << "Gio check-out: ";
    cin >> co.gioRa;

    do {
        cout << "Ngay check-out (dd mm yyyy): ";
        cin >> ntn.ngay >> ntn.thang >> ntn.nam;

        if (!kt_yy(ntn.nam) || !kt_mm(ntn.thang, ntn.nam) || !kt_dd(ntn.ngay, ntn.thang, ntn.nam)) {
            cout << "Khong hop le, vui long nhap lai!\n";
            cout << "---------------------\n";
        }
    } while (!kt_yy(ntn.nam) || !kt_mm(ntn.thang, ntn.nam) || !kt_dd(ntn.ngay, ntn.thang, ntn.nam));
    co.ngayRa = ntn;
}

int checkOut::get_ngayRa() {
    return ntn.ngay;
}

void checkOut::set_ngayRa(int _ngayRa) {
    ntn.ngay = _ngayRa;
}

int checkOut::get_gioRa() {
    return co.gioRa;
}

void checkOut::set_gioRa(int _gioRa) {
    co.gioRa = _gioRa;
}

void checkOut::xoa_checkOut() {
    co.gioRa = 0;
    ntn.ngay = 0;
    ntn.thang = 0;
    ntn.nam = 0;
    co.ngayRa = ntn;
}

void checkOut::xuat_checkOut() {
    cout << "Ngay check-out: " << co.ngayRa.ngay << "/" << co.ngayRa.thang << "/" << co.ngayRa.nam << endl;
    cout << "Gio check-out: " << co.gioRa << endl;
    cout << "---------------------\n";
}

