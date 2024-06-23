//#include <limits>
#pragma once
#include "Quan_ly_giao_dich.cpp"

class Khach_hang : public Dat_phong, public Check_out
{ 
	private:
		struct Ngay_thang_nam
		{
			int Ngay, Thang, Nam;
			
			Ngay_thang_nam() {}
			
			Ngay_thang_nam(int _Ngay, int _Thang, int _Nam)
			: Ngay(_Ngay), Thang (_Thang), Nam (_Nam) {}
		} NTN;
		
		struct Thong_tin_kh
		{
			string Cccd, So_dien_thoai, Ho_ten;
			Ngay_thang_nam Ngay_sinh;
			
			Thong_tin_kh() {}
			
			Thong_tin_kh(string _Quay_tiep_khach, string _Cccd, string _So_dien_thoai, string _Ho_ten, Ngay_thang_nam _Ngay_sinh)
			: Ho_ten(_Ho_ten), Cccd(_Cccd), Ngay_sinh(_Ngay_sinh), So_dien_thoai(_So_dien_thoai) {}
		} KH;
		
	public:
		Khach_hang() {}

    	~Khach_hang() {}

		
		void chuan_hoa_so()
		{
			
		}
		
		bool kt_yy(int yy) {
		    return yy >= 1900 && yy <= 2024;
		}
		
		bool yy_nhuan(int yy) {
		    return (yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0);
		}
		
		int kt_mm(int mm, int yy) {
		    switch (mm) {
		        case 1: return 31;
		        case 2: return yy_nhuan(yy) ? 29 : 28;
		        case 3: return 31;
		        case 4: return 30;
		        case 5: return 31;
		        case 6: return 30;
		        case 7: return 31;
		        case 8: return 31;
		        case 9: return 30;
		        case 10: return 31;
		        case 11: return 30;
		        case 12: return 31;
		        default: return 0;
		    }
		}
		
		bool kt_dd(int dd, int mm, int yy) {
		    int maxDay = kt_mm(mm, yy);
		    return dd >= 1 && dd <= maxDay;
		}
		
		void Nhap_khach_hang() {
	        cout << "Nhap ho ten khach hang: "; 
	        cin.ignore(); 
	        getline(cin, KH.Ho_ten);
	
	        cout << "Nhap cccd: "; 
	        getline(cin, KH.Cccd);
	
	        cout << "Nhap so dien thoai: "; 
	        getline(cin, KH.So_dien_thoai);
	
			do 
			{
				cout << "Nhap ngay sinh (dd mm yyyy): "; 
	        	cin >> NTN.Ngay >> NTN.Thang >> NTN.Nam;
	        	
	            if (!kt_yy(NTN.Nam) || !kt_mm(NTN.Thang, NTN.Nam) || !kt_dd(NTN.Ngay, NTN.Thang, NTN.Nam)) 
				{
					cout << "\n---------------------\n";
	                cout << "Khong hop le, vui long nhap lai!\n";
	                cout << "---------------------\n\n";
	            }
	        } 
			while (!kt_yy(NTN.Nam) || !kt_mm(NTN.Thang, NTN.Nam) || !kt_dd(NTN.Ngay, NTN.Thang, NTN.Nam));
	        KH.Ngay_sinh = NTN;
			
	        Dat_phong::Nhap_dat_phong();
	        Check_in::Nhap_thoi_gian_vao();
	    }
		
		void chuan_hoa_chu()
		{
			//xoa khoang trang o dau
			while(KH.Ho_ten[0] == ' ')
			{
				KH.Ho_ten.erase(0, 1);
			}
			
			//xoa khoang trang o giua
			for(int i=0; i<KH.Ho_ten.size(); i++)
			{
				if(KH.Ho_ten[i] == ' ' && KH.Ho_ten[i+1] == ' ')
				{
					KH.Ho_ten.erase(i+1, 1);
				}
			}
			
			for(int i=KH.Ho_ten.size(); i>0; i--)
			{
				if(KH.Ho_ten[i] == ' ' && KH.Ho_ten[i-1] == ' ')
				{
					KH.Ho_ten.erase(i-1, 1);
				}
			}
			
			//xoa khoang trang o cuoi
			while(KH.Ho_ten[KH.Ho_ten.size()-1] == ' ')
			{
				KH.Ho_ten.erase(KH.Ho_ten.size()-1, 1);
			}
			
			for(int i=0; i<KH.Ho_ten.size(); i++)
			{
				if((int)KH.Ho_ten[i] >= 65 && (int)KH.Ho_ten[i] <= 90)
				{
					KH.Ho_ten[i] = KH.Ho_ten[i] + 32;
				}
			}
			
			//viet hoa chu cai dau
			if(KH.Ho_ten[0] >= 97 && KH.Ho_ten[0] <=122 )
			{
				KH.Ho_ten[0] = KH.Ho_ten[0] - 32;
			}
			
			for(int i=0; i<KH.Ho_ten.size(); i++)
			{
				if(KH.Ho_ten[i] == ' ')
				{
					if(KH.Ho_ten[i+1] != ' ')
					{
						KH.Ho_ten[i+1] = KH.Ho_ten[i+1] - 32;
					}
				}
			}
		}
		
		string get_Ho_ten()
		{
			chuan_hoa_chu();
			return this->KH.Ho_ten;
		}
		
		void set_Ho_ten(string Ho_ten)
		{
			KH.Ho_ten = Ho_ten;
		}
		
		string get_Cccd()
		{
			return this->KH.Cccd;
		}
		
		void set_Cccd(int Cccd)
		{
			KH.Cccd = Cccd;
		}
		
		string get_So_dien_thoai()
		{
			return this->KH.So_dien_thoai;
		}
		
		void set_So_dien_thoai(int So_dien_thoai)
		{
			KH.So_dien_thoai = So_dien_thoai;
		}
		
		void Xuat_khach_hang()
		{
			chuan_hoa_chu();
			cout << "Ho ten khach hang: " << KH.Ho_ten << endl;
			cout << "Cccd: " << KH.Cccd << endl;
			cout << "Ngay sinh (dd mm yyyy): " << KH.Ngay_sinh.Ngay << "/" << KH.Ngay_sinh.Thang << "/" << KH.Ngay_sinh.Nam << endl;
			cout << "So dien thoai: " << KH.So_dien_thoai << endl;
			
			Dat_phong::Xuat_dat_phong();
			Check_in::Xuat_thoi_gian_vao();
			
			if(Check_out::get_Ngay_ra() != 0)
			{
				Check_out::Xuat_thoi_gian_ra();
				cout << "\n---------------------\n";
				cout << "\nKhach da thanh toan\n";
			}
		}
		
		void Sua_thong_tin(int &n)
		{
	        int Lua_chon;
	   		do{
	   			cout << "\n\nSUA THONG TIN KHACH HANG";
	   			cout << "\n---------------------";
			    cout << "\n01. Sua ho va ten khach hang";
			    cout << "\n02. Sua cccd khach hang";
			    cout << "\n03. Sua ngay sinh khach hang";
			    cout << "\n04. Sua SDT khach hang";
			    cout << "\n05. Sua toan bo thong tin khach hang";
			    cout << "\n---------------------";
			    cout << "\n00. Thoat chinh sua\n";
			    cout << "\n---------------------";
			    cout << "\nNhap lua chon: ";
		    	cin >> Lua_chon;
		    	
			    switch(Lua_chon){
			    	cout << "\n---------------------";
				    case 1:
						cout << "\nNhap ho ten khach hang: ";
						fflush(stdin);
						getline(cin, KH.Ho_ten);
						break;
						
				    case 2:
						cout << "\nNhap cccd khach hang: ";
						fflush(stdin);
						getline(cin, KH.Cccd);
						break;
						
				    case 3:
						do 
						{
							cout << "Nhap ngay sinh (dd mm yyyy): "; 
							fflush(stdin);
				        	cin >> NTN.Ngay >> NTN.Thang >> NTN.Nam;
				        	
				            if (!kt_yy(NTN.Nam) || !kt_mm(NTN.Thang, NTN.Nam) || !kt_dd(NTN.Ngay, NTN.Thang, NTN.Nam)) 
							{
				                cout << "Khong hop le, vui long nhap lai!\n";
				                cout << "---------------------\n";
				            }
				        } 
						while (!kt_yy(NTN.Nam) || !kt_mm(NTN.Thang, NTN.Nam) || !kt_dd(NTN.Ngay, NTN.Thang, NTN.Nam));
						break;
						
				    case 4:
						cout << "\nNhap SDT khach hang: ";
						fflush(stdin);
						getline(cin, KH.So_dien_thoai);
						break;
						
					case 5:
						cin.ignore();
						cout << "\nNhap ho ten khach hang: ";
						fflush(stdin);
						getline(cin, KH.Ho_ten);
						
						cout << "Nhap cccd khach hang: ";
						fflush(stdin);
						getline(cin, KH.Cccd);
						
						do 
						{
							cout << "Nhap ngay sinh (dd mm yyyy): "; 
							fflush(stdin);
				        	cin >> NTN.Ngay >> NTN.Thang >> NTN.Nam;
				        	
				            if (!kt_yy(NTN.Nam) || !kt_mm(NTN.Thang, NTN.Nam) || !kt_dd(NTN.Ngay, NTN.Thang, NTN.Nam)) 
							{
				                cout << "Khong hop le, vui long nhap lai!\n";
				                cout << "---------------------\n";
				            }
				        } 
						while (!kt_yy(NTN.Nam) || !kt_mm(NTN.Thang, NTN.Nam) || !kt_dd(NTN.Ngay, NTN.Thang, NTN.Nam));
						
						cout << "Nhap SDT khach hang: ";
						fflush(stdin);
						getline(cin, KH.So_dien_thoai);
						break;
					
					default:
						break;
				}	
				cout << "---------------------\n";
				cout << "DA SUA THONG TIN KHACH HANG!\n";
				cout << "----------------------------------------------------\n";
	    	}
			while(Lua_chon <= 0 && Lua_chon > 5);
        }
        
        void Xoa_thong_tin()
        {
        	int Lua_chon;
        	
   			cout << "\n\nXAC NHAN XOA?";
   			cout << "\n---------------------";
		    cout << "\n01. Xac nhan";
		    cout << "\n02. Huy";
		    cout << "\n---------------------";
		    cout << "\nNhap lua chon: ";
		   	cin >> Lua_chon;
		    
			if(Lua_chon = 1)
			{
				KH.Ho_ten = "0";
		        KH.Cccd = "0";
		        KH.So_dien_thoai = "0";
				NTN.Ngay = 0;
				NTN.Thang = 0; 
				NTN.Nam = 0;
		        KH.Ngay_sinh = NTN;
				
		        Dat_phong::Xoa_dat_phong();
		        Check_in::Xoa_ci();
		        Check_out::Xoa_co();
		        
		        cout << "\nDA XOA THONG TIN KHACH HANG!\n";
				cout << "----------------------------------------------------\n";
			}
        	else if(Lua_chon = 2)
        	{
        		cout << "\nDA HUY YEU CAU XOA THONG TIN\n";
				cout << "----------------------------------------------------\n";
			}
		}
        
        void Khach_doi_phong_N()
        {
        	Dat_phong::Nhap_doi_phong();
			cout << "\n----------------------------------------------------\n";
			cout << "Xac nhan lai thong tin cua khach hang:" << endl;
			cout << "---------------------\n";
        	Dat_phong::Xac_nhan_lai();
		}
		
		void Khach_doi_phong_X()
        {
        	Dat_phong::Xuat_doi_phong();
		}
		
		void Khach_N_co()
		{
			Check_out::Nhap_thoi_gian_ra();
		}
		
		void Khach_X_co()
		{
			Check_out::Xuat_thoi_gian_ra();
			cout << "---------------------\n";
		}
		
		void Khach_them_dv()
		{
			int luachon;
	        	cout << "\nTHEM DICH VU\n"
		        cout << "---------------------\n";
		        cout << "01. Do an\n";
		        cout << "02. Do uong\n";
		        cout << "03. Khac\n";
		        cout << "---------------------\n";
		    do
	        {    
				cout << "Khach chon: ";
		        cin >> luachon;
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
			}
			while(luachon<=0 || luachon >3);
		}
		
		void Khach_tra_phong()
		{
			int x, y, So_ngay_thue, So_gio_thue, Thanh_tien, Gia_ngay = 2500000, Gia_gio = 150000;
			
	        x = Check_out::get_Ngay_ra() - Dat_phong::get_Ngay_dat_phong();
	        if(x == 0)
			{
	        	y = (Check_out::get_Gio_ra() - Check_in::get_Gio_vao());
			}
			else if(x > 0)
			{
				y = (Check_out::get_Ngay_ra() - Dat_phong::get_Ngay_dat_phong()) * 24 + (Check_out::get_Gio_ra() - Check_in::get_Gio_vao());
			}
			else
			{
				cout << "Loi tinh toan, vui long kiem tra lai thong tin da nhap!\n";
			}
			
			if(y == 0)
			{
	        	cout << "Loi tinh toan, vui long kiem tra lai thong tin da nhap!\n";
			}
			
			Thanh_tien = x * Gia_ngay + y * Gia_gio;

	        cout << "\nHOA DON\n";
	        cout << "---------------------\n";
	        cout << "Thong tin thanh toan: \n";
	        if(x == 0)
			{
				cout << "Tong so gio thue: " << y << endl;
			}
			else if(x > 0)
			{
				cout << "So ngay thue: " << y << endl;
				cout << "Tong so gio thue: " << y << endl;
			}
	        
	        
	        cout << "\nThanh tien: " << Thanh_tien << " vnd" << endl;
	        
	        int luachon;
	        cout << "---------------------\n";
	        cout << "Phuong thuc thanh toan:\n";
	        cout << "01. Tien mat\n";
	        cout << "02. Chuyen khoan\n";
	        cout << "---------------------\n";
	        chonlai:
			cout << "Khach chon: ";
	        cin >> luachon;
	        
	        if(luachon == 1)
			{
	        	cout << "\nXAC NHAN PHUONG THUC: Tien mat\n";
			}
			else if(luachon == 2)
			{
				cout << "\nXAC NHAN PHUONG THUC: Chuyen khoan\n";
			}
			else
			{
				cout << "Loi nhap, vui long thu lai!";
				goto chonlai;
			}
			cout << "---------------------\n\n";
			cout << "Cam on quy khach da su dung dich vu! \n----------------------------------------------------\n";
		}
};
