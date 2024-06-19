//Bai tap lon
//Phan mem quan ly khach san don gian (dung cho le tan)
#include <conio.h>
#include "Quan_ly_bao_cao.cpp"

//void Dang_nhap();
//void Nhap_so_luong();
bool Kiem_tra_ttkh(Khach_hang Khach[], int &n); //check
void Nhap_du_lieu(Khach_hang Khach[], int &n); //1
void Xuat_du_lieu(Khach_hang Khach[], int &n); //2
void Sua_thong_tin_khach_hang(Khach_hang Khach[], int &n); //3
void Khach_doi_phong(Khach_hang Khach[], int &n); //4
void Khach_check_in(Khach_hang Khach[], int &n); //5
void Khach_check_out(Khach_hang Khach[], int &n); //6
void Tim_kiem_khach(Khach_hang Khach[], int &n); //7
void Xoa_thong_tin_khach_hang(Khach_hang Khach[], int &n); //8
void Thong_tin_tinh_trang_phong(); //9
void Bao_cao(); //10
void Menu(Khach_hang Khach[], int &n);

int main()
{
	//Dang_nhap();
	int n=1;
	//Nhap_so_luong();
	
	Khach_hang *Khach = new Khach_hang[n];
	Danh_sach_phong *room = new Danh_sach_phong;
	
	Menu(Khach, n);
	getch();
	return 0;
}

//void Dang_nhap(){
//
//}

//void Nhap_so_luong(){
//	do{
//		cout << "Nhap so luong khach hang thue phong: ";
//		cin >> n;
//	}
//	while(n<1 || n>5);
//}

//Kiem tra
bool Kiem_tra_ttkh(Khach_hang Khach[], int &n)
{
	string Kiem_tra;
	int dem=0;
	
	cout << "\nNhap cccd khach hang can tim: ";
	getline(cin, Kiem_tra);
	cout << "----------------------------------------------------\n";
	
	for(int i=0; i<n; i++)
	{
		if(Khach[i].get_Cccd() == Kiem_tra)
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

//01. Nhap du lieu khach hang + dat phong
void Nhap_du_lieu(Khach_hang Khach[], int &n)
{
	cout << "\n\nNHAP THONG TIN KHACH HANG";
	cout << "\n----------------------------------------------------\n";
	for(int i=0; i<n; i++)
	{
		cout << "Khach hang: " << i+1 << "\n---------------------\n";
		Khach[i].Nhap_khach_hang();
	}
}

//02. Xuat du lieu khach hang 
void Xuat_du_lieu(Khach_hang Khach[], int &n)
{
	cout << "\n\nDANH SACH, THONG TIN KHACH HANG";
	cout << "\n----------------------------------------------------\n";
	for(int i=0; i<n; i++)
	{
		cout << "Khach hang: " << i+1 << "\n---------------------\n";
		Khach[i].Xuat_khach_hang();
	}
}

//03. Sua thong tin khach hang
void Sua_thong_tin_khach_hang(Khach_hang Khach[], int &n)
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
		cout << "Khong tim thay thong tin hop le!\n";
		cout << "\n----------------------------------------------------\n";
	}		
}

//04. Doi phong
void Khach_doi_phong(Khach_hang Khach[], int &n)
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
		cout << "Khong tim thay thong tin hop le!\n";
		cout << "----------------------------------------------------\n";
	}
}
      
//05. Check-in
void Khach_check_in(Khach_hang Khach[], int &n)
{
	if(Kiem_tra_ttkh(Khach, n) == true)
	{
		for(int i=0; i<n; i++)
		{
			cout << "\nTHONG TIN KHACH HANG" << endl;
			cout << "---------------------\n";
			Khach[i].Xuat_khach_hang();
			Khach[i].Khach_N_ci();
			Khach[i].Khach_X_ci();
			break;
		}
	}
	else
	{
		cout << "Khong tim thay khach hang!\n";
		cout << "----------------------------------------------------\n";
	}
}

//06. Check-out
void Khach_check_out(Khach_hang Khach[], int &n)
{
	if(Kiem_tra_ttkh(Khach, n) == true)
	{
		for(int i=0; i<n; i++)
		{
			cout << "\nTHONG TIN KHACH HANG" << endl;
			cout << "---------------------\n";
			Khach[i].Xuat_khach_hang();
			Khach[i].Khach_N_co();
			Khach[i].Khach_X_co();
			break;
		}
	}
	else
	{
		cout << "Khong tim thay khach hang!\n";
		cout << "----------------------------------------------------\n";
	}
}

//07. Thanh toan
//void Khach_thanh_toan(Khach_hang Khach[], int &n)
//{
//	for(int i=0; i<n; i++)
//	{
//		if(Kiem_tra_ttkh(Khach, n) == true)
//		{
//			cout << "\nTHONG TIN KHACH HANG" << endl;
//			cout << "---------------------\n";
//			
//			Khach[i].Xuat_khach_hang();
//			Khach[i].Khach_tra_phong();
//			cout << "----------------------------------------------------\n";
//			break;
//		}
//		else
//		{
//			cout << "Khong tim thay khach hang!\n";
//			cout << "----------------------------------------------------\n";
//			break;
//		}
//	}
//}

//7. Tim kiem bang ma khach hang
void Tim_kiem_khach(Khach_hang Khach[], int &n)
{
	string Tim_kiem;
	int dem=0;
	
	cout << "\nNhap cccd khach hang can tim: ";
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
	
	if(dem == 0)
	{
		cout << "\nKhong tim thay khach hang, vui long thu lai!";
		cout << "\n----------------------------------------------------\n";
	}
}

//08. Xoa thong tin khach hang
void Xoa_thong_tin_khach_hang(Khach_hang Khach[], int &n)
{
//	int Ma_kh;
//    cout << "Nhap can cuoc cong dan khach hang muon huy phong: ";
//    cin >> Ma_kh;
//    cout << "\n";
//    
//    int index = -1;
//    for (int i = 0; i < n; i++)
//	{
//        if (Khach[i].get_Ma_khach_hang() == Ma_kh)
//		{
//            index = i;
//            Khach[i].Xoa_khach_hang();
//            break;
//        }
//    }
//    
//    if (index == -1)
//	{
//        cout << "Ma khach hang: " << Ma_kh << " khong ton tai khach hang" << endl;
//        return;
//    }
}

//09. Danh sach + trang thai phong
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
	
	switch(x){ 
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
void Bao_cao()
{
	
} 

//MENU
void Menu(Khach_hang Khach[], int &n)
{
	int Lua_chon;
	
	do{
		system("cls");
		cout << "\t  Chuong trinh quan ly khach san" << endl;
		cout << " =======================<MENU>=======================\n";
		cout << " ==                                                ==\n";
		cout << " ==       01. Nhap thong tin ve khach hang         ==\n";
		cout << " ==       02. Danh sach thong tin khach hang       ==\n";
		cout << " ==       03. Sua thong tin khach hang             ==\n";
		cout << " ==       04. Khach hang muon doi phong            ==\n";
		cout << " ==       05. Ngay/gio khach check-in              ==\n";
		cout << " ==       06. Ngay/gio khach check-out             ==\n";
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
		
		switch(Lua_chon){ 
			case 1:
				Nhap_du_lieu(Khach, n);
				cout << "==\tDAT PHONG THANH CONG\t==\n";
				cout << endl;
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
				Khach_check_in(Khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 6:
				Khach_check_out(Khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 7:
				Tim_kiem_khach(Khach, n);
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
