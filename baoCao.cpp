#include "khachHang.cpp"

class baoCao : public khachHang{
	private:
		struct gioPhutGiay {
			int gio, phut, giay;
			
			gioPhutGiay() {}
			
			gioPhutGiay(int _gio, int _phut, int _giay) : gio(_gio), phut(_phut), giay(_giay) {}
		} gpg;
		
		struct ngayThangNam {
			int ngay, thang, nam;
			
			ngayThangNam() {}
			
			ngayThangNam(int _ngay, int _thang, int _nam) : ngay(_ngay), thang(_thang), nam(_nam) {}
		} ntn;
		
	public:
		string tenBaoCao() {
	        return "baoCao" + string("/") + to_string(datPhong::get_ngayDatPhong()) + "_" + to_string(datPhong::get_thangDatPhong()) + "_" + to_string(datPhong::get_namDatPhong()) + ".txt";
	    }
		
		void baoCaoNgay() {
			ofstream fs;
	        fs.open(tenBaoCao(), ios::out | ios::app);
	        
	        fs << "----------------------------------------------------\nBAO CAO NGAY\n---------------------\n";
	        if (fs.is_open()) {
	            fs << "Ma khach hang: " << maKhachHang() << endl;
	            xuat_khachHang(fs);
	            xuat_datPhong(fs);
	            xuat_checkIn(fs);
	            xuat_checkOut(fs);
	            xuat_dichVu(fs);
	            xuat_thanhToan(fs);
	            fs << "---------------------\n";
	            fs << "Thoi gian: " << "fix";
	            fs << "\n----------------------------------------------------\n";
	            fs.close();
	            cout << "Bao cao ngay da duoc ghi vao file " << tenBaoCao() << "\n";
	        } else {
	            cerr << "Khong the mo file de ghi thong tin hoa don.\n";
	        }
		}
};
