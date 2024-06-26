#include <iostream>

using namespace std;

class thoiGian{
	public:
		struct gioPhut{
				int gio, phut;
				
				gioPhut() {}
				
				gioPhut(int _gio, int _phut)
				: gio(_gio), phut (_phut) {}
		} gp;
		
		struct ngayThangNam{
				int ngay, thang, nam;
				
				ngayThangNam() {}
				
				ngayThangNam(int _ngay, int _thang, int _nam)
				: ngay(_ngay), thang (_thang), nam (_nam) {}
		} ntn;
};

