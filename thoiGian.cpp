#include <iostream>
#include <string>
#include <ctime>

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
		
	    string dinhDangThoiGian(int value) {
			if (value < 10) {
		        return "0" + to_string(value);
		    } else {
		        return to_string(value);
		    }
		}
		
		bool kt_yy(int yy) {
		    time_t now = time(0);
		    tm *ltm = localtime(&now);
		    
		    int _yy = 1900 + ltm->tm_year;
		    return yy >= _yy;
		}
		
		bool kt_mm(int yy, int mm) {
		    time_t now = time(0);
		    tm *ltm = localtime(&now);
		    
		    int _yy = 1900 + ltm->tm_year;
		    int _mm =  1+ ltm->tm_mon;
		    
		    if (yy == _yy) {
		        return mm >= _mm;
		    } else if (yy > _yy) {
		        return true;
		    }
		    return false;
		}
		
		bool kt_dd(int yy, int mm, int dd) {
		    time_t now = time(0);
		    tm *ltm = localtime(&now);
		    
		    int _yy = 1900 + ltm->tm_year;
		    int _mm = 1 + ltm->tm_mon;
		    int _dd = ltm->tm_mday;
		    
		    if (yy == _yy && mm == _mm) {
		        return dd >= _dd;
		    } else if (yy > _yy || (yy == _yy && mm > _mm)) {
		        return true;
		    }
		    return false;
		}
		
		bool kt_h(int yy, int mm, int dd, int h) {
		    time_t now = time(0);
		    tm *ltm = localtime(&now);
		    
		    int _yy = 1900 + ltm->tm_year;
		    int _mm = 1 + ltm->tm_mon ;
		    int _dd = ltm->tm_mday;
		    int _h = ltm->tm_hour;
		    
		    if (yy == _yy && mm == _mm && dd == _dd) {
		        return h >= _h;
		    } else if (yy > _yy || (yy == _yy && mm > _mm) || (yy == _yy && mm == _mm && dd > _dd)) {
		        return true;
		    }
		    return false;
		}
		
		bool kt_min(int yy, int mm, int dd, int h, int min) {
		    time_t now = time(0);
		    tm *ltm = localtime(&now);
		    
		    int _yy = 1900 + ltm->tm_year;
		    int _mm = 1 + ltm->tm_mon ;
		    int _dd = ltm->tm_mday;
		    int _h = ltm->tm_hour;
		    int _min = ltm->tm_min;
		    
		    if (yy == _yy && mm == _mm && dd == _dd && h == _h) {
		        return min >= _min;
		    } else if (yy > _yy || (yy == _yy && mm > _mm) || (yy == _yy && mm == _mm && dd > _dd) || (yy == _yy && mm == _mm && dd == _dd && h > _h)) {
		        return true;
		    }
		    return false;
		}
};

