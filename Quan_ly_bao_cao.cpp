#include <fstream>
#include "Quan_ly_khach_hang.cpp"

class baoCao : public khachHang{
	private:
		int maBaoCao;
		
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
		
	public:		
		void Nhap_bc()
		{
			fstream fs;
			
			fs.open("text.txt", ios::out | ios::app);
			
			if(!fs.is_open())
			{
				cout << "Khong mo duoc file";
			}
			
			fs << "Heloo";
			fs.close();
		}
		
		void Xuat_bc()
		{
			
		}
		
};
