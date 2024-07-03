#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

struct ngayThangNam {
    int nam, thang, ngay, gio, phut, giay;
};

time_t chuyenDoiThoiGian(ngayThangNam dmy) {
    tm a = {};
    a.tm_year = dmy.nam - 1900;
    a.tm_mon = dmy.thang - 1;
    a.tm_mday = dmy.ngay;
    a.tm_hour = dmy.gio;
    a.tm_min = dmy.phut;
    a.tm_sec = dmy.giay;
    
    return mktime(&a);
}

int main() {
    ngayThangNam dmy1, dmy2;

    cout << "Nhap ngay gio dau tien (nam thang ngay gio phut): ";
    cin >> dmy1.nam >> dmy1.thang >> dmy1.ngay >> dmy1.gio >> dmy1.phut;

    cout << "Nhap ngay gio thu hai (nam thang ngay gio phut): ";
    cin >> dmy2.nam >> dmy2.thang >> dmy2.ngay >> dmy2.gio >> dmy2.phut;

    time_t time1 = chuyenDoiThoiGian(dmy1);
    time_t time2 = chuyenDoiThoiGian(dmy2);

    double thoiGian = difftime(time2, time1);
    double soPhut = thoiGian / 60;
    double soGio = thoiGian / 3600;
    double soNgay = thoiGian / (3600 * 24);

	
	int ngay = static_cast<int>(soNgay);
    int gio = static_cast<int>(soGio) - static_cast<int>(soNgay) * 24;
    int phut = static_cast<int>(soPhut) - static_cast<int>(soGio) * 60;
    
    if (soGio >= 24) {
        cout << "Khoang thoi gian: " << ngay << " ngay, " << gio << " gio, " << phut << "phut." << endl;
    } else {
        cout << "Khoang thoi gian: " << gio << " gio, " << phut << "phut." << endl;
    }

    return 0;
}

