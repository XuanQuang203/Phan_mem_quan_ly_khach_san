#include <iostream>

using namespace std;

class thoiGian{
	public:
		struct gioPhutGiay{
				int gio, phut, giay;
				
				gioPhutGiay() {}
				
				gioPhutGiay(int _gio, int _phut, int _giay)
				: gio(_gio), phut (_phut), giay(_giay) {}
		} hms;
		
		struct ngayThangNam{
				int ngay, thang, nam;
				
				ngayThangNam() {}
				
				ngayThangNam(int _ngay, int _thang, int _nam)
				: ngay(_ngay), thang (_thang), nam (_nam) {}
		} dmy;
		
		bool kt_gio(int _gio) {
        	return _gio >= 0 || _gio <= 23;
		}
		
		bool kt_phut(int _phut) {
			return _phut >= 0 || _phut <= 59;
		}
        
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
};

