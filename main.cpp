//Project: Phan mem quan ly khach san don gian (dung cho le tan) (console app)
#include <conio.h>
#include <sstream>
#include "Quan_ly_nhan_vien.cpp"
#include "Quan_ly_bao_cao.cpp"

//ham nguyen mau
void Dang_nhap();
void So_luong_khach(Khach_hang *&Khach, int &n);
string ma_kh(Khach_hang *&Khach, int &n);
bool Kiem_tra_ttkh(Khach_hang *&Khach, int &n); 
void Nhap_du_lieu(Khach_hang *&Khach, int &n); //1
void Xuat_du_lieu(Khach_hang *&Khach, int &n); //2
void Sua_thong_tin_khach_hang(Khach_hang *&Khach, int &n); //3
void Khach_doi_phong(Khach_hang *&Khach, int &n); //4
void Them_dich_vu(Khach_hang *&Khach, int &n); //5
void Khach_thanh_toan(Khach_hang *&Khach, int &n); //6
void Tim_kiem_khach_hang(Khach_hang *&Khach, int &n); //7
void Xoa_thong_tin_khach_hang(Khach_hang *&Khach, int &n); //8
void Thong_tin_tinh_trang_phong(); //9
void Bao_cao(); //10
void Menu(Khach_hang *&Khach, int &n);

int main()
{
	Dang_nhap();
	int n = 1;
	
	Khach_hang *Khach = new Khach_hang[n];
	
	Menu(Khach, n);
	getch();
	
	delete Khach;
	return 0;
}

//doc du lieu tu file .txt neu dung thi cho truy cap
void Dang_nhap()
{

}

//tang so luong phan tu cho mang dong
void So_luong_khach(Khach_hang *&Khach, int &n) 
{
    Khach_hang* new_Khach = new Khach_hang[n+1];

    for (int i = 0; i < n; i++) 
	{
        new_Khach[i] = Khach[i];
    }
    delete[] Khach;
    Khach = new_Khach;
    n++;
}

//tao ra ma khach hang tu ngay, thang, nam va so thu tu trong ngay 
string ma_kh(Khach_hang *&Khach, int &n) {
	ostringstream _ngay;
	for (int i = 0; i < n; ++i) {
		if(Khach[i].get_Ngay_dat_phong() < 10)
		{
			_ngay << "0" << Khach[i].get_Ngay_dat_phong();
		}
		else
		{
			_ngay << Khach[i].get_Ngay_dat_phong();
		}
    }
    
	ostringstream _thang;
	for (int i = 0; i < n; ++i) 
	{
		if(Khach[i].get_Thang_dat_phong() < 10)
		{
			_thang << "0" << Khach[i].get_Thang_dat_phong();
		}
		else
		{
			_thang << Khach[i].get_Thang_dat_phong();
		}
    }
    
	ostringstream _nam;
	for (int i = 0; i < n; ++i) 
	{
        _nam << (Khach[i].get_Nam_dat_phong() - 2000);
    }
	
	ostringstream _stt;
	for (int i = 0; i < n; ++i) 
	{
        if(i<10)
		{
        	_stt << "00" << i;
		}
		else if(i<100 && i>=10)
		{
			_stt << "0" << i;
		}
    }
	
    ostringstream oss;
    for (int i = 0; i < n; ++i) {
        oss << _ngay << _thang << _nam << _stt;
    }
    
    return oss.str();
}

//Kiem tra thong tin cho cac ham ben duoi su dung lai
bool Kiem_tra_ttkh(Khach_hang *&Khach, int &n)
{
	string Kiem_tra;
	int dem = 0;
	
	cout << "\nNhap ma khach hang hoac cccd khach hang can tim: ";
	getline(cin, Kiem_tra);
	cout << "----------------------------------------------------\n";
	
	for(int i=0; i<n; i++)
	{
		if(Khach[i].get_Cccd() == Kiem_tra || ma_kh(Khach, n) == Kiem_tra)
		{
			return true;
			dem++;
		}
	}
	
	if(dem == 0)
	{
		return false;
	}
}

bool trung_thong_tin(Khach_hang *&Khach, int &n)
{
	for(int i=n; i>0; i--)
	{
		for(int j=0; j<n; j++)
		{
			if(Khach[i].get_Cccd() == Khach[i].get_Cccd())
			{
				return true;	
			}
		}	
	}
	return false;
}

//check xem co trung dat phong (so phong, ngay/thang/nam) hay khong
bool trung_dat_phong(Khach_hang *&Khach, int &n)
{
	for(int i=0; i<n; i++)
	{
		if(Khach[n - 1].get_Phong_da_dat() == Khach[i].get_Phong_da_dat() && Khach[n - 1].get_Ngay_dat_phong() == Khach[i].get_Ngay_dat_phong() && Khach[n - 1].get_Thang_dat_phong() == Khach[i].get_Thang_dat_phong() && Khach[n - 1].get_Nam_dat_phong() == Khach[i].get_Nam_dat_phong())
		{
			return true;
		}
	}
	return false;
}

//01. Nhap du lieu khach hang + dat phong
//nhap du lieu vao mang, neu mang da co du lieu thi dung ham tang so luong mang dong. 
//khach sau se duoc check xem co trung thong tin cac khach truoc khong, neu co nhap lai
void Nhap_du_lieu(Khach_hang *&Khach, int &n) {
    cout << "\n\nNHAP THONG TIN KHACH HANG" << "\n----------------------------------------------------\n\n";

    if (n == 0 || Khach[n - 1].get_Phong_da_dat() != 0) 
	{
        So_luong_khach(Khach, n);
        cout << "Khach hang: " << n << "\n---------------------\n";
        nhaplai:
        Khach[n - 1].Nhap_khach_hang();
        
        for(int i; i<n; i++)
		{
        	if(trung_dat_phong(Khach, n) == true)
        	{
				cout << "Phong da duoc dat, vui long cho phong khac!\n---------------------\n";
				goto nhaplai;
			}
		}
    }
    else
    {
    	for(int i=0; i<n; i++)
    	{
    		cout << "Khach hang: " << n << "\n---------------------\n";
        	Khach[i].Nhap_khach_hang();
		}
	}
}

//02. Xuat du lieu khach hang
//xuat toan bo du lieu ve cac khach hang
void Xuat_du_lieu(Khach_hang *&Khach, int &n)
{	
    int dem = 0;
    cout << "\n\nDANH SACH, THONG TIN KHACH HANG" << "\n----------------------------------------------------\n\n";
    for(int i = 0; i < n; i++)
    {
    	if(Khach[i].get_Phong_da_dat() != 0)
    	{
    		cout << "Khach hang: " << i + 1 << "\n---------------------\n";
		    Khach[i].Xuat_khach_hang();
		    
		    if(Khach[i].get_Ngay_ra() == 0)
			{
				cout << "\nKhach chua tra phong\n";
				cout << "------------------------------\n\n\n";
			}
			dem++;
		}
    }

    if(dem == 0)
    {
        cout << "\nDANH SACH TRONG, VUI LONG NHAP DANH SACH!" << "\n----------------------------------------------------\n";
    }
    else
    {
        cout << "HET DANH SACH" << "\n----------------------------------------------------\n";
    }
}


//03. Sua thong tin khach hang
//chon khach hang, sau do chinh sua cac thong tin cua ho
void Sua_thong_tin_khach_hang(Khach_hang *&Khach, int &n)
{
	if(Kiem_tra_ttkh(Khach, n) == true)
	{
		for(int i=0; i<n; i++)
		{
			cout << "\n----------------------------------------------------";
			cout << "\nXac nhan lai thong tin cua khach hang" << endl;
			cout << "Khach hang: " << i+1 << "\n---------------------\n";
			Khach[i].Xuat_khach_hang();
			Khach[i].Sua_thong_tin(n);
		}
	}
	else
	{
		cout << "\nKhong tim thay thong tin hop le!\n";
		cout << "\n----------------------------------------------------\n";
	}		
}

//04. Khach muon doi phong
//doi phong cho khach hang
void Khach_doi_phong(Khach_hang *&Khach, int &n)
{
	if(Kiem_tra_ttkh(Khach, n) == true)
	{
		for(int i=0; i<n; i++)
		{
			cout << "Khach hang: " << Khach->get_Ho_ten() << "\n---------------------\n";
			Khach[i].Xuat_khach_hang();
			Khach[i].Nhap_doi_phong();
			
			Khach[i].Xuat_doi_phong();
			cout << "----------------------------------------------------\n";
			break;
		}
	}
	else
	{
		cout << "\nKhong tim thay thong tin hop le!\n";
		cout << "----------------------------------------------------\n";
	}
}
      
//05. Khach dung them dich vu
//khach dung them cac loai hinh dich vu
void Them_dich_vu(Khach_hang *&Khach, int &n)
{
	if(Kiem_tra_ttkh(Khach, n) == true)
	{
		for(int i=0; i<n; i++)
		{
			cout << "\nTHONG TIN KHACH HANG" << endl;
			cout << "---------------------\n";
			Khach[i].Xuat_khach_hang();
			
			Khach[i].Khach_them_dv();
			break;
		}
	}
	else
	{
		cout << "\nKhong tim thay khach hang!\n";
		cout << "----------------------------------------------------\n";
	}
}

//06. Khach hang thanh toan
//tinh toan sau do thanh toan cho khach hang, xuat bill theo dinh dang file: ma_khach_hang.txt
void Khach_thanh_toan(Khach_hang *&Khach, int &n)
{
	if(Kiem_tra_ttkh(Khach, n) == true)
	{
		for(int i=0; i<n; i++)
		{
			cout << "\nTHONG TIN KHACH HANG" << endl;
			cout << "---------------------\n";
			Khach[i].Xuat_khach_hang();
			Khach[i].Khach_N_co();
			
			cout << "\nXAC NHAN LAI\n";
			Khach[i].Xuat_dat_phong();
			cout << "Gio check-in: " << Khach[i].get_Gio_vao() << endl;
			Khach[i].Khach_X_co();
			
			Khach[i].Khach_tra_phong();
			
			break;
		}
	}
	else
	{
		cout << "\nKhong tim thay khach hang!\n";
		cout << "----------------------------------------------------\n";
	}
}

//7. Tim kiem khach hang
//tim kiem khach hang theo ma khach hang hoac cac thong tin da nhap truoc do
void Tim_kiem_khach_hang(Khach_hang *&Khach, int &n)
{
	string Tim_kiem;
	int dem = 0;
	
    int luachon;
    cout << "TIM KIEM THEO:\n";
    cout << "---------------------\n";
    cout << "01. Ma khach hang\n";
    cout << "02. CCCD\n";
    cout << "03. SDT\n";
    cout << "---------------------\n";
    chonlai:
	cout << "Lua chon: ";
    cin >> luachon;
    
    if(luachon == 1)
	{
    	cout << "\nNhap ma khach hang can tim: ";
		cin.ignore();
		getline(cin, Tim_kiem);
		cout << "----------------------------------------------------\n";
		
		for(int i=0; i<n; i++)
		{
			if(ma_kh(Khach, n) == Tim_kiem)
			{
				cout << "Thong tin khach hang\n";
				Khach[i].Xuat_khach_hang();
				dem++;
			}
		}
	}
	else if(luachon == 2)
	{
		cout << "\nNhap cccd khach hang can tim: ";
		cin.ignore();
		getline(cin, Tim_kiem);
		cout << "----------------------------------------------------\n";
		
		for(int i=0; i<n; i++)
		{
			if(Khach[i].get_Cccd() == Tim_kiem)
			{
				cout << "Thong tin khach hang\n";
				Khach[i].Xuat_khach_hang();
				dem++;
			}
		}
	}
	else if(luachon == 3)
	{
		cout << "\nNhap sdt khach hang can tim: ";
		cin.ignore();
		getline(cin, Tim_kiem);
		cout << "----------------------------------------------------\n";
		
		for(int i=0; i<n; i++)
		{
			if(Khach[i].get_So_dien_thoai() == Tim_kiem)
			{
				cout << "Thong tin khach hang\n";
				Khach[i].Xuat_khach_hang();
				dem++;
			}
		}
	}
	else
	{
		cout << "Loi nhap, vui long thu lai!";
		goto chonlai;
	}
	
	if(dem == 0)
	{
		cout << "\nKhong tim thay khach hang, vui long kiem tra thong tin va thu lai sau!";
		cout << "\n----------------------------------------------------\n";
	}
}

//08. Xoa thong tin khach hang
//chon khach hang va xoa toan bo thong tin
void Xoa_thong_tin_khach_hang(Khach_hang *&Khach, int &n)
{
	if(Kiem_tra_ttkh(Khach, n) == true)
	{
		for(int i=0; i<n; i++)
		{
			cout << "\n----------------------------------------------------\n";
			cout << "Xac nhan lai thong tin cua khach hang" << endl;
			cout << "---------------------\n";
			Khach[i].Xuat_khach_hang();
			Khach[i].Xoa_thong_tin();
			break;
		}
	}
	else
	{
		cout << "\nKhong tim thay khach hang!\n";
		cout << "----------------------------------------------------\n";
	}
}

//09. Danh sach + trang thai phong
//lua chon hien thi thong tin, danh sach va trang thai cua cac phong
void Thong_tin_tinh_trang_phong()
{
	Danh_sach_phong dsp;
	int x;
	cout << "\n----------------------------------------------------\n";
	cout << "01. Cap nhat thong tin tinh trang phong" << endl;
	cout << "02. Hien thi thong tin tinh trang phong" << endl;
	cout << "---------------------\n";
	cout << "Nhap lua chon: ";
	cin >> x;
	
	switch(x)
	{ 
		case 1:
			cout << "\n---------------------";
			dsp.Nhap_thong_tin_ds();
			cout << "----------------------------------------------------\n";
			break;
			
		case 2:
			cout << "\n---------------------";
			dsp.Hien_thong_tin_ds();
			cout << "----------------------------------------------------\n";
			break;
	}
}

//10. Bao_cao
//xuat bao cao theo ngay vao cac file .txt
void Bao_cao()
{
	
} 

//MENU
//lua chon cac chuc nang duoc hien thi
void Menu(Khach_hang *&Khach, int &n)
{
	int Lua_chon;
	
	do
	{
		system("cls");
		cout << "\t  Chuong trinh quan ly khach san" << endl;
		cout << " =======================<MENU>=======================\n";
		cout << " ==                                                ==\n";
		cout << " ==       01. Nhap thong tin ve khach hang         ==\n";
		cout << " ==       02. Danh sach thong tin khach hang       ==\n";
		cout << " ==       03. Sua thong tin khach hang             ==\n";
		cout << " ==       04. Khach hang muon doi phong            ==\n";
		cout << " ==       05. Khach dung them dich vu              ==\n";
		cout << " ==       06. Khach hang thanh toan                ==\n";
		cout << " ==       07. Tim kiem khach hang                  ==\n";
		cout << " ==       08. Xoa thong tin khach hang             ==\n";
		cout << " ==       ----------------------------------       ==\n";
		cout << " ==       09. Danh sach, thong tin phong           ==\n";
		cout << " ==       10. Xuat bao cao                         ==\n";
		cout << " ==       ----------------------------------       ==\n";
		cout << " ==       00. Thoat chuong trinh quan ly           ==\n";
		cout << " ==                                                ==\n";
		cout << " ====================================================\n";
		cout << "\t  Nhap lua chon cua ban: ";
		cin >> Lua_chon;
		cin.ignore(); 
		
		switch(Lua_chon)
		{ 
			case 1:
				Nhap_du_lieu(Khach, n);
				cout << "\n==\tDAT PHONG THANH CONG\t==\n\n";
				system("\nPAUSE");
				break;
				
			case 2:
				Xuat_du_lieu(Khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 3:
				Sua_thong_tin_khach_hang(Khach, n);
				cout << endl; 
				system("\nPAUSE");
				break;                                                      
				
			case 4:
				Khach_doi_phong(Khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 5:
				Them_dich_vu(Khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 6:
				Khach_thanh_toan(Khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 7:
				Tim_kiem_khach_hang(Khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 8:
				Xoa_thong_tin_khach_hang(Khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
			
			case 9:
				Thong_tin_tinh_trang_phong();
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 10:
				Bao_cao();
				cout << endl;
				system("\nPAUSE");
				break;
			
			case 0:
				exit(0);
				break;
		}
	}
	while(Lua_chon != 0);
}
