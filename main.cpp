//Project: Phan mem quan ly khach san don gian (dung cho le tan) (console app)
#include <conio.h>
#include <sstream>

#include "khachHang.cpp"
//#include "Quan_ly_bao_cao.cpp"
//#include "Thoi_gian.cpp"

//void makhachHang(khachHang *&khach, int &n);
void themKhachHang(khachHang *&khach, int &n);
bool kiemTraThongTin(khachHang *&khach, int &n); 
void nhap_duLieu(khachHang *&khach, int &n); //1
void xuat_duLieu(khachHang *&khach, int &n); //2
void sua_duLieu(khachHang *&khach, int &n); //3
void khachDoiPhong(khachHang *&khach, int &n); //4
void themDichVu(khachHang *&khach, int &n); //5
void khachThanhToan(khachHang *&khach, int &n); //6
void timKiem_duLieu(khachHang *&khach, int &n); //7
void xoa_duLieu(khachHang *&khach, int &n); //8
void thongTinDanhSachPhong(); //9
void baoCao(); //10
void menu(khachHang *& khach, int & n);

int main(){
	int n = 1;
	
	khachHang *khach = new khachHang[n];
	
	menu(khach, n);
	getch();
	
	delete[] khach;
	return 0;
}

//tao ra ma khach hang tu ngay, thang, nam va so thu tu trong ngay 
//void makhachHang(khachHang *&khach, int &n){
//	ostringstream _ngay;
//	for(int i = 0; i < n; ++i){
//		if(khach[i].get_ngayDatPhong() < 10){
//			_ngay << "0" << khach[i].get_ngayDatPhong();
//		}
//		else{
//			_ngay << khach[i].get_ngayDatPhong();
//		}
//    }
//    
//	ostringstream _thang;
//	for (int i = 0; i < n; ++i){
//		if(khach[i].get_thangDatPhong() < 10){
//			_thang << "0" << khach[i].get_thangDatPhong();
//		}
//		else{
//			_thang << khach[i].get_thangDatPhong();
//		}
//    }
//    
//	ostringstream _nam;
//	for(int i = 0; i < n; ++i){
//        _nam << (khach[i].get_namDatPhong() - 2000);
//    }
//	
//	ostringstream _stt;
//	for(int i = 0; i < n; ++i){
//        if(i<10){
//        	_stt << "00" << i;
//		}
//		else if(i<100 && i>=10){
//			_stt << "0" << i;
//		}
//    }
//	
//    ostringstream oss;
//    for(int i = 0; i < n; ++i){
//        oss << _ngay << _thang << _nam << _stt;
//    }
//    
//    string str;
//    return oss.str();
//}

//tang so luong phan tu cho mang dong
void themKhachHang(khachHang *&khach, int &n){
    khachHang *new_khach = new khachHang[n+1];
    for (int i = 0; i < n; i++){
        new_khach[i] = khach[i];
    }
    delete[] khach;
    khach = new_khach;
    n++;
}

//Kiem tra thong tin cho cac ham ben duoi su dung lai
bool kiemTraThongTin(khachHang *&khach, int &n){
	string kiemTra;
	int dem = 0;
	
	cout << "\nNhap ma khach hang hoac cccd khach hang can tim: ";
	getline(cin, kiemTra);
	cout << "----------------------------------------------------\n";
	
	for(int i=0; i<n; i++){
		if(khach[i].get_cccd() == kiemTra /*|| makhachHang(khach, n) == kiemTra*/){
			return true;
			dem++;
		}
	}
	
	if(dem == 0){
		return false;
	}
}

bool trungThongTin(khachHang *&khach, int &n){
//	for(int i=n; i>0; i--)
//	{
//		for(int j=0; j<n; j++)
//		{
//			if(khach[i].get_cccd() == khach[i].get_cccd())
//			{
//				return true;	
//			}
//		}	
//	}
//	return false;
}

//check xem co trung dat phong (so phong, ngay/thang/nam) hay khong
bool trungDatPhong(khachHang *&khach, int &n){
	for(int i=0; i<n; i++){
		if(khach[n - 1].get_phongDaDat() == khach[i].get_phongDaDat() && khach[n - 1].get_ngayDatPhong() == khach[i].get_ngayDatPhong() && khach[n - 1].get_thangDatPhong() == khach[i].get_thangDatPhong() && khach[n - 1].get_namDatPhong() == khach[i].get_namDatPhong()){
			return true;
		}
	}
	return false;
}

//01. Nhap du lieu khach hang + dat phong
//nhap du lieu vao mang, neu mang da co du lieu thi dung ham tang so luong mang dong. 
//khach sau se duoc check xem co trung thong tin cac khach truoc khong, neu co nhap lai
void nhap_duLieu(khachHang *&khach, int &n){
    cout << "\n\nNHAP THONG TIN KHACH HANG" << "\n----------------------------------------------------\n\n";

    if (n == 0 || khach[n - 1].get_phongDaDat() != 0){
        themKhachHang(khach, n);
        cout << "khach hang: " << n << "\n---------------------\n";
        nhapLai:
        khach[n - 1].nhap_khachHang();
        
        for(int i; i<n; i++){
        	if(trungDatPhong(khach, n) == true){
				cout << "Phong da duoc dat, vui long cho phong khac!\n---------------------\n";
				goto nhapLai;
			}
		}
    }
    else{
    	for(int i=0; i<n; i++){
    		cout << "khach hang: " << n << "\n---------------------\n";
        	khach[i].nhap_khachHang();
		}
	}
}

//02. Xuat du lieu khach hang
//xuat toan bo du lieu ve cac khach hang
void xuat_duLieu(khachHang *&khach, int &n){	
    int dem = 0;
    cout << "\n\nDANH SACH, THONG TIN KHACH HANG" << "\n----------------------------------------------------\n\n";
    for(int i = 0; i < n; i++){
    	if(khach[i].get_phongDaDat() != 0){
    		cout << "khach hang: " << i + 1 << "\n---------------------\n";
		    khach[i].xuat_khachHang();
		    
//		    if(khach[i].get_ngayRa() == 0){
//				cout << "\nkhach chua tra phong\n";
//				cout << "------------------------------\n\n\n";
//			}
			dem++;
		}
    }

    if(dem == 0){
        cout << "\nDANH SACH TRONG, VUI LONG NHAP DANH SACH!" << "\n----------------------------------------------------\n";
    }
    else{
        cout << "HET DANH SACH" << "\n----------------------------------------------------\n";
    }
}


//03. Sua THONG TIN KHACH HANG
//chon khach hang, sau do chinh sua cac thong tin cua ho
void sua_duLieu(khachHang *&khach, int &n){
	if(kiemTraThongTin(khach, n) == true){
		for(int i=0; i<n; i++){
			cout << "\n----------------------------------------------------";
			cout << "\nXac nhan lai thong tin cua khach hang" << endl;
			cout << "khach hang: " << i+1 << "\n---------------------\n";
			khach[i].xuat_khachHang();
			khach[i].sua_khachHang(n);
		}
	}
	else{
		cout << "\nKhong tim thay thong tin hop le!\n";
		cout << "\n----------------------------------------------------\n";
	}		
}

//04. khach muon doi phong
//doi phong cho khach hang
void khachDoiPhong(khachHang *&khach, int &n){
	if(kiemTraThongTin(khach, n) == true){
		for(int i=0; i<n; i++){
			cout << "khach hang: " << khach->get_hoTen() << "\n---------------------\n";
			khach[i].xuat_khachHang();
			khach[i].nhap_doiPhong();
			
			khach[i].xuat_doiPhong();
			cout << "----------------------------------------------------\n";
			break;
		}
	}
	else{
		cout << "\nKhong tim thay thong tin hop le!\n";
		cout << "----------------------------------------------------\n";
	}
}
      
//05. khach dung them dich vu
//khach dung them cac loai hinh dich vu
void themDichVu(khachHang *&khach, int &n){
	if(kiemTraThongTin(khach, n) == true){
		for(int i=0; i<n; i++){
			cout << "\nTHONG TIN KHACH HANG" << endl;
			cout << "---------------------\n";
			khach[i].xuat_khachHang();
			
			khach[i].themDichVu();
			break;
		}
	}
	else{
		cout << "\nKhong tim thay khach hang!\n";
		cout << "----------------------------------------------------\n";
	}
}

//06. khach hang thanh toan
//tinh toan sau do thanh toan cho khach hang, xuat bill theo dinh dang file: makhachHangach_hang.txt
void khachThanhToan(khachHang *&khach, int &n){
	if(kiemTraThongTin(khach, n) == true){
		for(int i=0; i<n; i++){
			cout << "\nTHONG TIN KHACH HANG" << endl;
			cout << "---------------------\n";
			khach[i].xuat_khachHang();
			khach[i].nhap_co();
			
			cout << "\nXAC NHAN LAI\n";
			khach[i].xuat_datPhong();
//			cout << "Gio check-in: " << khach[i].get_gioVao() << endl;
			khach[i].xuat_co();
			
			khach[i].khachTraPhong();
			
			break;
		}
	}
	else{
		cout << "\nKhong tim thay khach hang!\n";
		cout << "----------------------------------------------------\n";
	}
}

//7. Tim kiem khach hang
//tim kiem khach hang theo ma khach hang hoac cac thong tin da nhap truoc do
void timKiem_duLieu(khachHang *&khach, int &n){
	string timKiem;
	int dem = 0;
	
    int luaChon;
    cout << "TIM KIEM THEO:\n";
    cout << "---------------------\n";
    cout << "01. Ma khach hang\n";
    cout << "02. CCCD\n";
    cout << "03. SDT\n";
    cout << "---------------------\n";
    chonLai:
	cout << "Lua chon: ";
    cin >> luaChon;
    
    if(luaChon == 1){
    	cout << "\nNhap ma khach hang can tim: ";
		cin.ignore();
		getline(cin, timKiem);
		cout << "----------------------------------------------------\n";
		
		for(int i=0; i<n; i++){
			if(/*makhachHang(khach, n) == */timKiem == "0"){
				cout << "THONG TIN KHACH HANG\n";
				khach[i].xuat_khachHang();
				dem++;
			}
		}
	}
	else if(luaChon == 2){
		cout << "\nNhap cccd khach hang can tim: ";
		cin.ignore();
		getline(cin, timKiem);
		cout << "----------------------------------------------------\n";
		
		for(int i=0; i<n; i++){
			if(khach[i].get_cccd() == timKiem)
			{
				cout << "THONG TIN KHACH HANG\n";
				khach[i].xuat_khachHang();
				dem++;
			}
		}
	}
	else if(luaChon == 3)
	{
		cout << "\nNhap sdt khach hang can tim: ";
		cin.ignore();
		getline(cin, timKiem);
		cout << "----------------------------------------------------\n";
		
		for(int i=0; i<n; i++)
		{
			if(khach[i].get_soDienThoai() == timKiem)
			{
				cout << "THONG TIN KHACH HANG\n";
				khach[i].xuat_khachHang();
				dem++;
			}
		}
	}
	else
	{
		cout << "Loi nhap, vui long thu lai!";
		goto chonLai;
	}
	
	if(dem == 0)
	{
		cout << "\nKhong tim thay khach hang, vui long kiem tra thong tin va thu lai sau!";
		cout << "\n----------------------------------------------------\n";
	}
}

//08. Xoa THONG TIN KHACH HANG
//chon khach hang va xoa toan bo thong tin
void xoa_duLieu(khachHang *&khach, int &n){
	if(kiemTraThongTin(khach, n) == true){
		for(int i=0; i<n; i++){
			cout << "\n----------------------------------------------------\n";
			cout << "Xac nhan lai thong tin cua khach hang" << endl;
			cout << "---------------------\n";
			khach[i].xuat_khachHang();
			khach[i].xoa_khachHang();
			break;
		}
	}else{
		cout << "\nKhong tim thay khach hang!\n";
		cout << "----------------------------------------------------\n";
	}
}

//09. Danh sach + trang thai phong
//lua chon hien thi thong tin, danh sach va trang thai cua cac phong
void thongTinDanhSachPhong(){
	danhSachPhong _dsp;
	int x;
	cout << "\n----------------------------------------------------\n";
	cout << "01. Cap nhat thong tin tinh trang phong" << endl;
	cout << "02. Hien thi thong tin tinh trang phong" << endl;
	cout << "---------------------\n";
	cout << "Nhap lua chon: ";
	cin >> x;
	
	switch(x){ 
		case 1:
			cout << "\n---------------------";
			_dsp.nhap_danhSachPhong();
			cout << "----------------------------------------------------\n";
			break;
			
		case 2:
			cout << "\n---------------------";
			_dsp.xuat_danhSachPhong();
			cout << "----------------------------------------------------\n";
			break;
	}
}

//10. baoCao
//xuat bao cao theo ngay vao cac file .txt
void baoCao(){
	
} 

//menu
//lua chon cac chuc nang duoc hien thi
void menu(khachHang *&khach, int &n){
	int luaChon;
	
	do{
		system("cls");
		cout << "=======================<MENU>=====================\n";
		cout << "==\t  Chuong trinh quan ly khach san  \t==\n";
		cout << "==\t  ------------------------------  \t==\n";
		cout << "==\t                                  \t==\n";
		cout << "==\t01. Nhap thong tin ve khach hang  \t==\n";
		cout << "==\t02. Danh sach thong tin khach hang\t==\n";
		cout << "==\t03. Sua thong tin khach hang      \t==\n";
		cout << "==\t04. khach hang muon doi phong     \t==\n";
		cout << "==\t05. khach dung them dich vu       \t==\n";
		cout << "==\t06. khach hang thanh toan         \t==\n";
		cout << "==\t07. Tim kiem khach hang           \t==\n";
		cout << "==\t08. Xoa thong tin khach hang      \t==\n";
		cout << "==\t----------------------------------\t==\n";
		cout << "==\t09. Danh sach, thong tin phong    \t==\n";
		cout << "==\t10. Xuat bao cao                  \t==\n";
		cout << "==\t----------------------------------\t==\n";
		cout << "==\t00. Thoat chuong trinh quan ly    \t==\n";
		cout << "==\t                                  \t==\n";
		cout << "==================================================\n";
		cout << "\t    Nhap lua chon cua ban: ";
		cin >> luaChon;
		cin.ignore(); 
		
		switch(luaChon){ 
			case 1:
				nhap_duLieu(khach, n);
				cout << "\n==\tDAT PHONG THANH CONG\t==\n\n";
				system("\nPAUSE");
				break;
				
			case 2:
				xuat_duLieu(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 3:
				sua_duLieu(khach, n);
				cout << endl; 
				system("\nPAUSE");
				break;                                                      
				
			case 4:
				khachDoiPhong(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 5:
				themDichVu(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 6:
				khachThanhToan(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 7:
				timKiem_duLieu(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 8:
				xoa_duLieu(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
			
			case 9:
				thongTinDanhSachPhong();
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 10:
				baoCao();
				cout << endl;
				system("\nPAUSE");
				break;
			
			case 0:
				exit(0);
				break;
		}
	}
	while(luaChon != 0);
}
