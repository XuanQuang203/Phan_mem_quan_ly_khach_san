#include "Quan_ly_thong_tin_phong.cpp"

class checkIn{
	protected:
		int gioVao;
	
	public:
		void nhap_checkIn();
	
	    int get_gioVao();
	    void set_gioVao(int _gioVao);
	    
	    void sua_checkIn(int gioVao);
	    void xoa_checkIn();
	    void xuat_checkIn();
	    
	    friend class checkOut;
//	    friend class thanhToan;
};

class checkOut{
	protected:
	    struct ngayThangNam{
	        int ngay, thang, nam;
	
	        ngayThangNam() {}
	
	        ngayThangNam(int _ngay, int _thang, int _nam)
	            : ngay(_ngay), thang(_thang), nam(_nam) {}
	    } ntn;
		
		struct thoiGianCO{
			ngayThangNam ngayRa;
			int gioRa;
			
			thoiGianCO() {}
			
			thoiGianCO(ngayThangNam _ngayRa, int _gioRa)
			: ngayRa(_ngayRa), gioRa(_gioRa) {}
		} co;
		
	public:
		bool kt_yy(int yy);
		bool yy_nhuan(int yy);
		int kt_mm(int mm, int yy);
		bool kt_dd(int dd, int mm, int yy);
		
		void nhap_checkOut();
		
	    int get_ngayRa();
	    void set_ngayRa(int _ngayRa);
	    int get_gioRa();
	    void set_gioRa(int _gioRa);
	    
	    void xoa_checkOut();
	    void xuat_checkOut();
//	    friend class thanhToan;
};

class dichVu{
	public:
		void them_dichVu();
		
//		friend class thanhToan;
};

//class thanhToan : public datPhong, public checkIn, public checkOut, public dichVu {
//	private:
//		int soNgayThue, soGioThue, thanhTien;
//		int giaNgay = 2500, giaGio = 150;
//			
//	public:
//		thanhToan();
//		
//		void khachThanhToan();
//		
////		friend class khachHang;
//};

//void thanhToan::khachThanhToan(){
//	int x, y;
//    
//	x = checkOut::get_ngayRa() - datPhong::get_ngayDatPhong();
//    if(x == 0){
//    	y = checkOut::get_gioRa() - checkIn::get_gioVao();
//	}
//	else if(x > 0){
//		y = (checkOut::get_ngayRa() - datPhong::get_ngayDatPhong()) * 24 + checkOut::get_gioRa() - checkIn::get_gioVao();
//	}
//	else{
//		cout << "Loi tinh toan, vui long kiem tra lai thong tin da nhap!\n";
//	}
//	
//	if(y == 0){
//    	cout << "Loi tinh toan, vui long kiem tra lai thong tin da nhap!\n";
//	}
//	
//	thanhTien = x * giaNgay + y * giaGio;
//
//    cout << "\nHOA DON\n";
//    cout << "---------------------\n";
//    cout << "Thong tin thanh toan: \n";
//    if(x == 0){
//		cout << "Tong so gio thue: " << y << endl;
//	}
//	else if(x > 0){
//		cout << "So ngay thue: " << y << endl;
//		cout << "Tong so gio thue: " << y << endl;
//	}
//    
//    
//    cout << "\nThanh tien: " << thanhTien << " nghin vnd" << endl;
//    
//    int luaChon;
//    cout << "---------------------\n";
//    cout << "Phuong thuc thanh toan:\n";
//    cout << "01. Tien mat\n";
//    cout << "02. Chuyen khoan\n";
//    cout << "---------------------\n";
//    chonLai:
//	cout << "khach chon: ";
//    cin >> luaChon;
//    
//    if(luaChon == 1){
//    	cout << "\nXAC NHAN PHUONG THUC: Tien mat\n";
//	}
//	else if(luaChon == 2){
//		cout << "\nXAC NHAN PHUONG THUC: Chuyen khoan\n";
//	}
//	else{
//		cout << "Loi nhap, vui long thu lai!";
//		goto chonLai;
//	}
//	cout << "---------------------\n\n";
//	cout << "Cam on quy khach da su dung dich vu! \n----------------------------------------------------\n";
//}

//check in
void checkIn::nhap_checkIn(){   
    cout << "Gio check-in: ";
    cin >> gioVao;
}

int checkIn::get_gioVao(){
    return this->gioVao;
}

void checkIn::set_gioVao(int _gioVao){
    this->gioVao = _gioVao;
}

void checkIn::sua_checkIn(int gioVao){
	cout << "Sua thoi gian check in: ";
	set_gioVao(gioVao);
}

void checkIn::xoa_checkIn(){
	gioVao = 0;
}

void checkIn::xuat_checkIn(){
    cout << "Gio check-in: " << gioVao << endl;
}

//check out
bool checkOut::kt_yy(int yy){
    return yy >= 2024;
}

bool checkOut::yy_nhuan(int yy){
    return (yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0);
}

int checkOut::kt_mm(int mm, int yy){
    switch(mm){
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

bool checkOut::kt_dd(int dd, int mm, int yy){
    int maxDay = kt_mm(mm, yy);
    return dd >= 1 && dd <= maxDay;
}

void checkOut::nhap_checkOut(){
	cout << "Gio check-out: ";
    cin >> co.gioRa;
    
    do{
		cout << "Ngay check-out (dd mm yyyy): "; 
    	cin >> ntn.ngay >> ntn.thang >> ntn.nam;
    	
        if(!kt_yy(ntn.nam) || !kt_mm(ntn.thang, ntn.nam) || !kt_dd(ntn.ngay, ntn.thang, ntn.nam)){
            cout << "Khong hop le, vui long nhap lai!\n";
            cout << "---------------------\n";
        }
	} 
	while(!kt_yy(ntn.nam) || !kt_mm(ntn.thang, ntn.nam) || !kt_dd(ntn.ngay, ntn.thang, ntn.nam));
    co.ngayRa = ntn;
}

int checkOut::get_ngayRa(){
    return this->ntn.ngay;
}

void checkOut::set_ngayRa(int _ngayRa){
    this->ntn.ngay = _ngayRa;
}

int checkOut::get_gioRa(){
    return this->co.gioRa;
}

void checkOut::set_gioRa(int _gioRa){
    this->co.gioRa = _gioRa;
}

void checkOut::xoa_checkOut(){
	co.gioRa = 0;
	ntn.ngay = 0;
	ntn.thang = 0;
	ntn.nam = 0;
	co.ngayRa = ntn;
}

void checkOut::xuat_checkOut(){
    cout << "Ngay check-out: " << co.ngayRa.ngay << "/" << co.ngayRa.thang << "/" << co.ngayRa.nam << endl;
    cout << "Gio check-out: " << co.gioRa << endl;
    cout << "---------------------\n";
}

//dich vu
void dichVu::them_dichVu(){
	int luaChon;
	cout << "\nTHEM DICH VU\n";
    cout << "---------------------\n";
    cout << "01. Do an\n";
    cout << "02. Do uong\n";
    cout << "03. khac\n";
    cout << "---------------------\n";
	do{    
		cout << "khach chon: ";
        cin >> luaChon;
    	switch(luaChon){ 
			case 1:
				
				break;
				
			case 2:
				
				break;
				
			case 3:
				
				break;
		}
	}
	while(luaChon<=0 || luaChon >3);
}

//thanh toan
