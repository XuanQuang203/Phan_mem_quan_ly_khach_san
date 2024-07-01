#ifndef DATPHONG_H
#define DATPHONG_H

#include "danhSachPhong.h"

class datPhong : public danhSachPhong {
    private:
        struct ngayThangNam {
            int ngay, thang, nam;

            ngayThangNam() {}

            ngayThangNam(int _ngay, int _thang, int _nam)
                : ngay(_ngay), thang(_thang), nam(_nam) {}
        } ntn;

        struct thongTinDatPhong {
            int phongDaDat;
            ngayThangNam ngayDatPhong;
            int phongMoi;
            string lyDoDoi;

            thongTinDatPhong() {}

            thongTinDatPhong(int _phongDaDat, ngayThangNam _ngayDatPhong, int _phongMoi, string _lyDoDoi)
                : phongDaDat(_phongDaDat), ngayDatPhong(_ngayDatPhong), phongMoi(_phongMoi), lyDoDoi(_lyDoDoi) {}
        } dp;

    public:
        // dat phong
        bool kt_yy(int yy) {
            return yy >= 2024;
        }

        bool yy_nhuan(int yy) {
            return (yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0);
        }

        int kt_mm(int mm, int yy) {
            switch (mm) {
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

        bool kt_dd(int dd, int mm, int yy) {
            int maxDay = kt_mm(mm, yy);
            return dd >= 1 && dd <= maxDay;
        }

        bool kt_datPhong(int i) {
            return (i >= 0 && i < 3 && dp.phongDaDat == get_soPhong(i));
        }

        bool kt_doiPhong(int i) {
            return (i >= 0 && i < 3 && dp.phongMoi == get_soPhong(i));
        }

        void nhap_datPhong() {
            while (true) {
                cout << "---------------------\n";
                cout << "Phong khach muon dat: ";
                cin >> dp.phongDaDat;

                bool valid = false;
                for (int i = 0; i < 3; ++i) {
                    if (kt_datPhong(i)) {
                        valid = true;
                        break;
                    }
                }

                if (valid) {
                    do {
                        cout << "Ngay dat phong (dd mm yyyy): ";
                        cin >> ntn.ngay >> ntn.thang >> ntn.nam;

                        if (!kt_yy(ntn.nam) || !kt_mm(ntn.thang, ntn.nam) || !kt_dd(ntn.ngay, ntn.thang, ntn.nam)) {
                            cout << "Khong hop le, vui long nhap lai!\n";
                            cout << "---------------------\n";
                        }
                    } while (!kt_yy(ntn.nam) || !kt_mm(ntn.thang, ntn.nam) || !kt_dd(ntn.ngay, ntn.thang, ntn.nam));
                    dp.ngayDatPhong = ntn;
                    cout << "---------------------\n";
                    break;
                } else {
                    cout << "Phong khong dung, vui long nhap lai!\n";
                }
            }
        }

        int get_phongDaDat() {
            return dp.phongDaDat;
        }

        void set_phongDaDat(int _phongDaDat) {
            dp.phongDaDat = _phongDaDat;
        }

        int get_ngayDatPhong() {
            return dp.ngayDatPhong.ngay;
        }

        int get_thangDatPhong() {
            return dp.ngayDatPhong.thang;
        }

        int get_namDatPhong() {
            return dp.ngayDatPhong.nam;
        }

        void sua_datPhong() {
            // Thêm logic s?a d?i phòng ? dây
        }

        void xoa_datPhong() {
            dp.phongDaDat = 0;
            dp.ngayDatPhong.ngay = 0;
            dp.ngayDatPhong.thang = 0;
            dp.ngayDatPhong.nam = 0;
        }

        void xuat_datPhong() {
            cout << "---------------------\n";
            cout << "Phong duoc dat: " << dp.phongDaDat << endl;
            cout << "Ngay dat phong (dd mm yyyy): " << dp.ngayDatPhong.ngay << "/" << dp.ngayDatPhong.thang << "/" << dp.ngayDatPhong.nam << endl;
            cout << "---------------------\n";
        }

        // doi phong
        void nhap_doiPhong() {
            while (true) {
                cout << "Khach muon chon phong: ";
                cin >> dp.phongMoi;

                bool valid = false;
                for (int i = 0; i < 3; ++i) {
                    if (kt_doiPhong(i)) {
                        valid = true;
                        break;
                    }
                }

                if (valid) {
                    if (dp.phongMoi == dp.phongDaDat) {
                        cout << "Phong moi trung voi phong cu, vui long nhap lai!\n";
                    } else {
                        cout << "Ly do doi phong cua khach: ";
                        cin.ignore();
                        getline(cin, dp.lyDoDoi);
                        cout << endl;
                        break;
                    }
                } else {
                    cout << "Phong khong hop le, vui long chon lai!\n";
                }
            }
        }

        void xacNhanLai() {
            cout << "Khach muon chon phong: " << dp.phongMoi << endl;
            cout << "Ly do doi phong cua khach: " << dp.lyDoDoi << endl;
        }

        void xuat_doiPhong() {
            cout << "\nTHONG BAO";
            cout << "\n---------------------\n";
            cout << "Xac nhan doi phong\n";
            cout << "01. Xac nhan\n";
            cout << "02. Huy bo\n";
            cout << "---------------------\n";

            int luaChon;
            cout << "Lua chon: ";
            cin >> luaChon;

            if (luaChon == 1) {
                int x = dp.phongDaDat;
                dp.phongDaDat = dp.phongMoi;
                dp.phongMoi = x;

                cout << "\nDa doi phong thanh cong!\n";
                cout << "---------------------\n";
                cout << "Phong truoc khi doi: " << dp.phongMoi << endl;
                cout << "Phong sau khi doi: " << dp.phongDaDat << endl;
            } else if (luaChon == 2) {
                cout << "\n\nHuy qua trinh doi phong!\n";
            }
        }
};

#endif // DATPHONG_H

