#include "datPhong.h"
#include "thanhToan.h"

class khachHang : public virtual datPhong, public virtual checkIn, public virtual checkOut, public virtual dichVu, public virtual thanhToan {
	private:
	    struct ngayThangNam {
	        int ngay, thang, nam;
	
	        ngayThangNam() {}
	
	        ngayThangNam(int _ngay, int _thang, int _nam):
				ngay(_ngay), thang(_thang), nam(_nam) {}
	    } dmy;
	
	    struct thongTinkhach {
	        string cccd, soDienThoai, hoTen;
	        ngayThangNam ngaySinh;
	
	        thongTinkhach() {}
	
	        thongTinkhach(string _cccd, string _soDienThoai, string _hoTen, ngayThangNam _ngaySinh):
				hoTen(_hoTen), cccd(_cccd), ngaySinh(_ngaySinh), soDienThoai(_soDienThoai) {}
	    } kh;

	public:
		khachHang() {}
		
		~khachHang() {}
		
		string dinhDangThoiGian(int value) {
			if (value < 10) {
		        return "0" + to_string(value);
		    } else {
		        return to_string(value);
		    }
		}
		
		bool kt_yy(int yy) {
		    return yy >= 1900 && yy <= 2024;
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
		
		void nhap_khachHang() {
		    cout << "Nhap ho ten khach hang: ";
		    cin.ignore();
		    getline(cin, kh.hoTen);
		
		    cout << "Nhap cccd: ";
		    getline(cin, kh.cccd);
		
		    cout << "Nhap so dien thoai: ";
		    getline(cin, kh.soDienThoai);
		
		    do {
		        cout << "Nhap ngay sinh (dd mm yyyy): ";
		        cin >> dmy.ngay >> dmy.thang >> dmy.nam;
		
		        if (!kt_yy(dmy.nam) || !kt_mm(dmy.thang, dmy.nam) || !kt_dd(dmy.ngay, dmy.thang, dmy.nam)) {
		            cout << "\n---------------------\n";
		            cout << "khong hop le, vui long nhap lai!\n";
		            cout << "---------------------\n\n";
		        }
		    } 
			while (!kt_yy(dmy.nam) || !kt_mm(dmy.thang, dmy.nam) || !kt_dd(dmy.ngay, dmy.thang, dmy.nam));
		    kh.ngaySinh = dmy;
		
		    datPhong::nhap_datPhong();
		}
		
		void chuanHoaChu() {
		    while (kh.hoTen[0] == ' ') {
		        kh.hoTen.erase(0, 1);
		    }
		
		    for (int i = 0; i < kh.hoTen.size(); i++) {
		        if (kh.hoTen[i] == ' ' && kh.hoTen[i + 1] == ' ') {
		            kh.hoTen.erase(i + 1, 1);
		        }
		    }
		
		    for (int i = kh.hoTen.size(); i > 0; i--) {
		        if (kh.hoTen[i] == ' ' && kh.hoTen[i - 1] == ' ') {
		            kh.hoTen.erase(i - 1, 1);
		        }
		    }
		    
		    while (kh.hoTen[kh.hoTen.size() - 1] == ' ') {
		        kh.hoTen.erase(kh.hoTen.size() - 1, 1);
		    }
		
		    for (int i = 0; i < kh.hoTen.size(); i++) {
		        if ((int)kh.hoTen[i] >= 65 && (int)kh.hoTen[i] <= 90) {
		            kh.hoTen[i] = kh.hoTen[i] + 32;
		        }
		    }
		
		    if (kh.hoTen[0] >= 97 && kh.hoTen[0] <= 122) {
		        kh.hoTen[0] = kh.hoTen[0] - 32;
		    }
		
		    for (int i = 0; i < kh.hoTen.size(); i++) {
		        if (kh.hoTen[i] == ' ') {
		            if (kh.hoTen[i + 1] != ' ') {
		                kh.hoTen[i + 1] = kh.hoTen[i + 1] - 32;
		            }
		        }
		    }
		}
		
		string get_hoTen() {
		    chuanHoaChu();
		    return kh.hoTen;
		}
		
		void set_hoTen(string _hoTen) {
		    kh.hoTen = _hoTen;
		}
		
		string get_cccd() {
		    return kh.cccd;
		}
		
		void set_cccd(int _cccd) {
		    kh.cccd = _cccd;
		}
		
		string get_soDienThoai() {
		    return kh.soDienThoai;
		}
		
		void set_soDienThoai(int _soDienThoai) {
		    kh.soDienThoai = _soDienThoai;
		}
		
		string maKhachHang() {		
			return dinhDangThoiGian(datPhong::get_ngayDatPhong()) + dinhDangThoiGian(datPhong::get_thangDatPhong()) + dinhDangThoiGian(datPhong::get_namDatPhong() - 2000) + get_cccd();
		}
		
		void xuat_khachHang() {
		    chuanHoaChu();
		    string dinhDangNgay = dinhDangThoiGian(kh.ngaySinh.ngay);
		    string dinhDangThang = dinhDangThoiGian(kh.ngaySinh.thang);
		    string dinhDangNam = to_string(kh.ngaySinh.nam);
		    
		    cout << "\nHo ten khach hang: " << kh.hoTen << endl;
		    cout << "Cccd: " << kh.cccd << endl;
		    cout << "Ngay sinh (dd mm yyyy): " << dinhDangNgay << "/" << dinhDangThang << "/" << dinhDangNam << endl;
		    cout << "So dien thoai: " << kh.soDienThoai << endl;
		
		    datPhong::xuat_datPhong();
		}
		
		void sua_khachHang(int &n) {
		    int luaChon;
		    
		    do {
		        cout << "\n\nSUA THONG TIN KHACH HANG";
		        cout << "\n---------------------";
		        cout << "\n01. Sua ho va ten khach hang";
		        cout << "\n02. Sua cccd";
		        cout << "\n03. Sua ngay thang nam sinh";
		        cout << "\n04. Sua so dien thoai";
		        cout << "\n05. Sua tat ca thong tin";
		        cout << "\n06. Tro ve";
		        cout << "\n---------------------";
		        cout << "\nNhap lua chon: ";
		        cin >> luaChon;
		        
		        switch (luaChon) {
		            case 1:
		                cout << "\nNhap ho ten khach hang: ";
		                cin.ignore();
		                getline(cin, kh.hoTen);
		                break;
		                
		            case 2:
		                cout << "\nNhap cccd khach hang: ";
		                cin.ignore();
		                getline(cin, kh.cccd);
		                break;
		                
		            case 3:
		                do {
		                    cout << "Nhap ngay sinh (dd mm yyyy): ";
		                    cin.ignore();
		                    cin >> dmy.ngay >> dmy.thang >> dmy.nam;
		
		                    if (!kt_yy(dmy.nam) || !kt_mm(dmy.thang, dmy.nam) || !kt_dd(dmy.ngay, dmy.thang, dmy.nam)) {
		                        cout << "khong hop le, vui long nhap lai!\n";
		                        cout << "---------------------\n";
		                    }
		                } 
						while (!kt_yy(dmy.nam) || !kt_mm(dmy.thang, dmy.nam) || !kt_dd(dmy.ngay, dmy.thang, dmy.nam));
		                break;
		                
		            case 4:
		                cout << "\nNhap SDT khach hang: ";
		                cin.ignore();
		                getline(cin, kh.soDienThoai);
		                break;
		                
		            case 5:
		                cout << "\nNhap ho ten khach hang: ";
		                cin.ignore();
		                getline(cin, kh.hoTen);
		
		                cout << "Nhap cccd khach hang: ";
		                cin.ignore();
		                getline(cin, kh.cccd);
		
		                do {
		                    cout << "Nhap ngay sinh (dd mm yyyy): ";
		                    cin.ignore();
		                    cin >> dmy.ngay >> dmy.thang >> dmy.nam;
		
		                    if (!kt_yy(dmy.nam) || !kt_mm(dmy.thang, dmy.nam) || !kt_dd(dmy.ngay, dmy.thang, dmy.nam)) {
		                        cout << "khong hop le, vui long nhap lai!\n";
		                        cout << "---------------------\n";
		                    }
		                } 
						while (!kt_yy(dmy.nam) || !kt_mm(dmy.thang, dmy.nam) || !kt_dd(dmy.ngay, dmy.thang, dmy.nam));
		
		                cout << "Nhap SDT khach hang: ";
		                cin.ignore();
		                getline(cin, kh.soDienThoai);
		                break;
		                
		            default:
		            	cout << "Lua chon khong hop le, vui long nhap lai!\n";
		                break;
		        }
		        cout << "---------------------\n";
		        cout << "HOAN TAT SUA THONG TIN KHACH HANG!\n";
		        cout << "----------------------------------------------------\n";
		    } 
			while (luaChon <= 0 && luaChon > 5);
		}
		
		void xoa_khachHang() {
		    int luaChon;
		
		    do {
		        cout << "\n\nXAC NHAN XOA?";
		        cout << "\n---------------------";
		        cout << "\n01. Xac nhan";
		        cout << "\n02. Huy";
		        cout << "\n---------------------";
		        cout << "\nNhap lua chon: ";
		        cin >> luaChon;
		
		        switch (luaChon) {
		            case 1:
		                kh.hoTen = "0";
		                kh.cccd = "0";
		                kh.soDienThoai = "0";
		                dmy.ngay = 0;
		                dmy.thang = 0;
		                dmy.nam = 0;
		                kh.ngaySinh = dmy;
		
		                datPhong::xoa_datPhong();
		                checkIn::xoa_checkIn();
		                checkOut::xoa_checkOut();
		
		                cout << "\nDA XOA THONG TIN KHACH HANG!\n";
		                cout << "----------------------------------------------------\n";
		                break;
		            
		            case 2:
		                cout << "\nDA HUY YEU CAU XOA THONG TIN\n";
		                cout << "----------------------------------------------------\n";
		                break;
		            
		            default: 
		                cout << "Vui long chon lai!\n";
		                break;
		            
		        }
		    } 
			while (luaChon != 1 && luaChon != 2);
		}
		
		void kt_tinhTrangPhong() {
			if (checkIn::get_ngayVao() == 0 && checkOut::get_ngayRa() == 0) {
		    	cout << "\nKhach da dat phong\n";
				cout << "------------------------------\n\n";
			}
			
		    if (checkIn::get_ngayVao() != 0 && checkOut::get_ngayRa() == 0) {
		        checkIn::xuat_checkIn();
		        cout << "\nKhach chua tra phong\n";
				cout << "------------------------------\n\n";
		    }
		
		    if (checkOut::get_ngayRa() != 0) {
		    	checkIn::xuat_checkIn();
		        checkOut::xuat_checkOut();
		        cout << "\nKhach da thanh toan\n";
				cout << "------------------------------\n\n";
		    }
		}
};

