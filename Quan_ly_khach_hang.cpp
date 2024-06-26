#include <limits>
#include "Quan_ly_giao_dich.cpp"

class khachHang : public datPhong, public checkIn, public checkOut/*, public dichVu, public thanhToan*/{ 
	private:
		struct ngayThangNam{
			int ngay, thang, nam;
			
			ngayThangNam() {}
			
			ngayThangNam(int _ngay, int _thang, int _nam)
			: ngay(_ngay), thang (_thang), nam (_nam) {}
		} ntn;
		
		struct thongTinkhach{
			string cccd, soDienThoai, hoTen;
			ngayThangNam ngaySinh;
			
			thongTinkhach() {}
			
			thongTinkhach(string _cccd, string _soDienThoai, string _hoTen, ngayThangNam _ngaySinh)
			: hoTen(_hoTen), cccd(_cccd), ngaySinh(_ngaySinh), soDienThoai(_soDienThoai) {}
		} kh;
		
	public:
		khachHang();
		
		bool kt_yy(int yy);
		bool yy_nhuan(int yy);
		int kt_mm(int mm, int yy);
		bool kt_dd(int dd, int mm, int yy);
		
		void nhap_khachHang();
		
		void chuanHoaChu();
		string get_hoTen();
		void set_hoTen(string _hoTen);
		string get_cccd();
		void set_cccd(int _cccd);
		string get_soDienThoai();
		void set_soDienThoai(int _soDienThoai);
		
		void xuat_khachHang();
		void sua_khachHang(int &n);
        void xoa_khachHang();
        
        void nhap_dp_doiPhong();
		void xuat_dp_doiPhong();
		
		void nhap_co();
		void xuat_co();
		
		void themDichVu();
		void khachTraPhong();
		
		~khachHang();
};

//khach hang
khachHang::khachHang(){
}

bool khachHang::kt_yy(int yy){
    return yy >= 1900 && yy <= 2024;
}

bool khachHang::yy_nhuan(int yy){
    return (yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0);
}

int khachHang::kt_mm(int mm, int yy){
    switch (mm){
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

bool khachHang::kt_dd(int dd, int mm, int yy){
    int maxDay = kt_mm(mm, yy);
    return dd >= 1 && dd <= maxDay;
}

void khachHang::nhap_khachHang(){
    cout << "Nhap ho ten khach hang: "; 
    cin.ignore(); 
    getline(cin, kh.hoTen);

    cout << "Nhap cccd: "; 
    getline(cin, kh.cccd);

    cout << "Nhap so dien thoai: "; 
    getline(cin, kh.soDienThoai);

	do{
		cout << "Nhap ngay sinh (dd mm yyyy): "; 
    	cin >> ntn.ngay >> ntn.thang >> ntn.nam;
    	
        if (!kt_yy(ntn.nam) || !kt_mm(ntn.thang, ntn.nam) || !kt_dd(ntn.ngay, ntn.thang, ntn.nam)){
			cout << "\n---------------------\n";
            cout << "khong hop le, vui long nhap lai!\n";
            cout << "---------------------\n\n";
        }
    } 
	while(!kt_yy(ntn.nam) || !kt_mm(ntn.thang, ntn.nam) || !kt_dd(ntn.ngay, ntn.thang, ntn.nam));
    kh.ngaySinh = ntn;
	
    datPhong::nhap_datPhong();
    checkIn::nhap_checkIn();
}

void khachHang::chuanHoaChu(){
	//xoa khoang trang o dau
	while(kh.hoTen[0] == ' '){
		kh.hoTen.erase(0, 1);
	}
	
	//xoa khoang trang o giua
	for(int i=0; i<kh.hoTen.size(); i++){
		if(kh.hoTen[i] == ' ' && kh.hoTen[i+1] == ' '){
			kh.hoTen.erase(i+1, 1);
		}
	}
	
	for(int i=kh.hoTen.size(); i>0; i--){
		if(kh.hoTen[i] == ' ' && kh.hoTen[i-1] == ' '){
			kh.hoTen.erase(i-1, 1);
		}
	}
	
	//xoa khoang trang o cuoi
	while(kh.hoTen[kh.hoTen.size()-1] == ' '){
		kh.hoTen.erase(kh.hoTen.size()-1, 1);
	}
	
	for(int i=0; i<kh.hoTen.size(); i++){
		if((int)kh.hoTen[i] >= 65 && (int)kh.hoTen[i] <= 90){
			kh.hoTen[i] = kh.hoTen[i] + 32;
		}
	}
	
	//viet hoa chu cai dau
	if(kh.hoTen[0] >= 97 && kh.hoTen[0] <=122 ){
		kh.hoTen[0] = kh.hoTen[0] - 32;
	}
	
	for(int i=0; i<kh.hoTen.size(); i++){
		if(kh.hoTen[i] == ' '){
			if(kh.hoTen[i+1] != ' '){
				kh.hoTen[i+1] = kh.hoTen[i+1] - 32;
			}
		}
	}
}

string khachHang::get_hoTen(){
	chuanHoaChu();
	return this->kh.hoTen;
}

void khachHang::set_hoTen(string _hoTen){
	kh.hoTen = _hoTen;
}

string khachHang::get_cccd(){
	return this->kh.cccd;
}

void khachHang::set_cccd(int _cccd){
	kh.cccd = _cccd;
}

string khachHang::get_soDienThoai(){
	return this->kh.soDienThoai;
}

void khachHang::set_soDienThoai(int _soDienThoai){
	kh.soDienThoai = _soDienThoai;
}

void khachHang::xuat_khachHang(){
	chuanHoaChu();
	cout << "Ho ten khach hang: " << kh.hoTen << endl;
	cout << "Cccd: " << kh.cccd << endl;
	cout << "Ngay sinh (dd mm yyyy): " << kh.ngaySinh.ngay << "/" << kh.ngaySinh.thang << "/" << kh.ngaySinh.nam << endl;
	cout << "So dien thoai: " << kh.soDienThoai << endl;
	
	datPhong::xuat_datPhong();
	checkIn::xuat_checkIn();
	
	if(checkOut::get_ngayRa() != 0){
		checkOut::xuat_checkOut();
		cout << "\n---------------------\n";
		cout << "\nkhach da thanh toan\n";
	}
}

void khachHang::sua_khachHang(int &n){
    int luaChon;
	do{
		cout << "\n\nSUA THONG TIN KHACH HANG";
		cout << "\n---------------------";
	    cout << "\n01. Sua ho va ten khach hang";
	    cout << "\n02. Sua cccd khach hang";
	    cout << "\n03. Sua ngay sinh khach hang";
	    cout << "\n04. Sua SDT khach hang";
	    cout << "\n05. Sua toan bo THONG TIN KHACH HANG";
	    cout << "\n---------------------";
	    cout << "\n00. Thoat chinh sua\n";
	    cout << "\n---------------------";
	    cout << "\nNhap lua chon: ";
    	cin >> luaChon;
    	
	    switch(luaChon){
	    	cout << "\n---------------------";
		    case 1:
				cout << "\nNhap ho ten khach hang: ";
				fflush(stdin);
				getline(cin, kh.hoTen);
				break;
				
		    case 2:
				cout << "\nNhap cccd khach hang: ";
				fflush(stdin);
				getline(cin, kh.cccd);
				break;
				
		    case 3:
				do{
					cout << "Nhap ngay sinh (dd mm yyyy): "; 
					fflush(stdin);
		        	cin >> ntn.ngay >> ntn.thang >> ntn.nam;
		        	
		            if (!kt_yy(ntn.nam) || !kt_mm(ntn.thang, ntn.nam) || !kt_dd(ntn.ngay, ntn.thang, ntn.nam)){
		                cout << "khong hop le, vui long nhap lai!\n";
		                cout << "---------------------\n";
		            }
		        } 
				while(!kt_yy(ntn.nam) || !kt_mm(ntn.thang, ntn.nam) || !kt_dd(ntn.ngay, ntn.thang, ntn.nam));
				break;
				
		    case 4:
				cout << "\nNhap SDT khach hang: ";
				fflush(stdin);
				getline(cin, kh.soDienThoai);
				break;
				
			case 5:
				cin.ignore();
				cout << "\nNhap ho ten khach hang: ";
				fflush(stdin);
				getline(cin, kh.hoTen);
				
				cout << "Nhap cccd khach hang: ";
				fflush(stdin);
				getline(cin, kh.cccd);
				
				do{
					cout << "Nhap ngay sinh (dd mm yyyy): "; 
					fflush(stdin);
		        	cin >> ntn.ngay >> ntn.thang >> ntn.nam;
		        	
		            if (!kt_yy(ntn.nam) || !kt_mm(ntn.thang, ntn.nam) || !kt_dd(ntn.ngay, ntn.thang, ntn.nam)){
		                cout << "khong hop le, vui long nhap lai!\n";
		                cout << "---------------------\n";
		            }
		        } 
				while (!kt_yy(ntn.nam) || !kt_mm(ntn.thang, ntn.nam) || !kt_dd(ntn.ngay, ntn.thang, ntn.nam));
				
				cout << "Nhap SDT khach hang: ";
				fflush(stdin);
				getline(cin, kh.soDienThoai);
				break;
			
			default:
				break;
		}	
		cout << "---------------------\n";
		cout << "DA SUA THONG TIN KHACH HANG!\n";
		cout << "----------------------------------------------------\n";
	}
	while(luaChon <= 0 && luaChon > 5);
}

void khachHang::xoa_khachHang(){
	int luaChon;
	
	cout << "\n\nXAC NHAN XOA?";
	cout << "\n---------------------";
    cout << "\n01. Xac nhan";
    cout << "\n02. Huy";
    cout << "\n---------------------";
    nhapLai:
    cout << "\nNhap lua chon: ";
   	cin >> luaChon;
    
	if(luaChon = 1){
		kh.hoTen = "0";
        kh.cccd = "0";
        kh.soDienThoai = "0";
		ntn.ngay = 0;
		ntn.thang = 0; 
		ntn.nam = 0;
        kh.ngaySinh = ntn;
		
        datPhong::xoa_datPhong();
        checkIn::xoa_checkIn();
        checkOut::xoa_checkOut();
        
        cout << "\nDA XOA THONG TIN KHACH HANG!\n";
		cout << "----------------------------------------------------\n";
	}
	else if(luaChon = 2){
		cout << "\nDA HUY YEU CAU XOA THONG TIN\n";
		cout << "----------------------------------------------------\n";
	}
	else{
		cout << "VUi LONG CHON LAI!";
		goto nhapLai;
	}
}

void khachHang::nhap_dp_doiPhong(){
	datPhong::nhap_doiPhong();
	cout << "\n----------------------------------------------------\n";
	cout << "Xac nhan lai thong tin cua khach hang:" << endl;
	cout << "---------------------\n";
	datPhong::xacNhanLai();
}

void khachHang::xuat_dp_doiPhong(){
	datPhong::xuat_doiPhong();
}

void khachHang::nhap_co(){
	checkOut::nhap_checkOut();
}

void khachHang::xuat_co(){
	checkOut::xuat_checkOut();
}

void khachHang::themDichVu(){
//			dichVu::them_dichVu();
}

void khachHang::khachTraPhong(){
//			thanhToan::khachThanhToan();
}

khachHang::~khachHang(){
}
