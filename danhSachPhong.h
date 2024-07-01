#ifndef DANHSACHPHONG_H
#define DANHSACHPHONG_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class danhSachPhong {
    protected:
        struct dacDiemPhong {
            string giuong, noiThat, wc, view;

            dacDiemPhong() {}

            dacDiemPhong(string _giuong, string _noiThat, string _wc, string _view)
                : giuong(_giuong), noiThat(_noiThat), wc(_wc), view(_view) {}
        };

        struct maPhong {
            int phong, tang;

            maPhong() {}

            maPhong(int _tang, int _phong)
                : tang(_tang), phong(_phong) {}
        };

        struct thongTinPhong {
            maPhong soPhong;
            dacDiemPhong dacDiem;
            string tinhTrang;

            thongTinPhong() {}

            thongTinPhong(maPhong _soPhong, dacDiemPhong _dacDiem, string _tinhTrang)
                : soPhong(_soPhong), dacDiem(_dacDiem), tinhTrang(_tinhTrang) {}
        } dsp[3];

    public:
        danhSachPhong() {
            dsp[0] = thongTinPhong(maPhong(1, 1), dacDiemPhong("Don", "Co ban", "1", "Vuon"), "Trong");
            dsp[1] = thongTinPhong(maPhong(1, 2), dacDiemPhong("Doi", "Full", "2", "Bien"), "Trong");
            dsp[2] = thongTinPhong(maPhong(2, 1), dacDiemPhong("Doi", "Full", "3", "Bien"), "Trong");
        }

        int get_soPhong(int i) {
            if (i < 0 || i >= 3) {
                return -1;
            }
            return dsp[i].soPhong.tang * 100 + dsp[i].soPhong.phong;
        }

        void nhap_danhSachPhong() {
            int i;
            cout << "\nNhap ma phong can sua (1, 2, 3): ";
            cin >> i;

            if (i <= 0 || i > 3) {
                cout << "Khong ton tai ma phong, vui long thu lai!\n";
                return;
            }

            cout << "---------------------\n";
            cout << "Tang thu: ";
            cin >> dsp[i - 1].soPhong.tang;

            cout << "Phong so: ";
            cin >> dsp[i - 1].soPhong.phong;

            cout << "Nhap thong tin giuong: ";
            cin.ignore();
            getline(cin, dsp[i - 1].dacDiem.giuong);

            cout << "Nhap thong tin noi that: ";
            getline(cin, dsp[i - 1].dacDiem.noiThat);

            cout << "Nhap thong tin WC: ";
            getline(cin, dsp[i - 1].dacDiem.wc);

            cout << "Nhap thong tin View: ";
            getline(cin, dsp[i - 1].dacDiem.view);
        }

        void xuat_danhSachPhong() {
            for (int i = 0; i < 3; i++) {
                cout << "\nThong tin phong " << i + 1 << endl;
                cout << "---------------------\n";
                cout << "So phong: " << dsp[i].soPhong.tang * 100 + dsp[i].soPhong.phong << endl;
                cout << "Giuong: " << dsp[i].dacDiem.giuong << endl;
                cout << "Noi that: " << dsp[i].dacDiem.noiThat << endl;
                cout << "So WC: " << dsp[i].dacDiem.wc << endl;
                cout << "View: " << dsp[i].dacDiem.view << endl;
                cout << "Tinh trang: " << dsp[i].tinhTrang << endl;
            }
        }
};

#endif //DANHSACHPHONG_H

