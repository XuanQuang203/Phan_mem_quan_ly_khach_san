#include "Quan_ly_giao_dich.cpp"
#pragma once

class Khach_hang : public Dat_phong, public Thanh_toan
{ 
	private:
		struct Ngay_thang_nam
		{
			int Ngay, Thang, Nam;
			
			Ngay_thang_nam() {}
			
			Ngay_thang_nam(int _Ngay, int _Thang, int _Nam)
			: Ngay(_Ngay), Thang (_Thang), Nam (_Nam) {}
		};
		
		struct Thong_tin_kh
		{
			string Cccd, So_dien_thoai, Ho_ten;
			Ngay_thang_nam Ngay_sinh;
			
			Thong_tin_kh() {}
			
			Thong_tin_kh(string _Quay_tiep_khach, string _Cccd, string _So_dien_thoai, string _Ho_ten, Ngay_thang_nam _Ngay_sinh)
			: Ho_ten(_Ho_ten), Cccd(_Cccd), Ngay_sinh(_Ngay_sinh), So_dien_thoai(_So_dien_thoai) {}
		} KH;
		
	public:
		void chuan_hoa_so(){
		}
		
		bool kt_yy(int yy)
		{
//			if(yy<1900 || y>2024){
//				return false;
//			}
//			return (yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0);
//		}
//		
//		bool kt_mm(int mm, int yy) 
//		{
//	  		switch (mm) 
//			{
//		        case 1:
//					return 31;
//		        case 2:
//					return yy_nhuan(yy) ? 29 : 28;
//		        case 3:
//					return 31;
//		        case 4:
//					return 30;
//		        case 5:
//					return 31;
//		        case 6:
//					return 30;
//		        case 7:
//					return 31;
//		        case 8:
//					return 31;
//		        case 9:
//					return 30;
//		        case 10:
//					return 31;
//		        case 11:
//					return 30;
//		        case 12:
//					return 31;
//		        default:
//					return 0;
//		    }
//		}
//		
//		bool _dd()
//		{
//			
		}
		
		void Nhap_khach_hang()
		{
			cout << "Nhap ho ten khach hang: "; 
			getline(cin, KH.Ho_ten);
			
			cout << "Nhap cccd: "; 
			getline(cin, KH.Cccd);
			
			cout << "Nhap so dien thoai: "; 
			getline(cin, KH.So_dien_thoai);
			
			cout << "Nhap ngay sinh (yyyy mm dd): "; 
			cin >> KH.Ngay_sinh.Nam >> KH.Ngay_sinh.Thang >> KH.Ngay_sinh.Ngay;
//			if(kt_yy(KH.Ngay_sinh.Nam) == false){
//				goto nhap_lai_yy;
//			}
			
			Dat_phong::Nhap_dat_phong();
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
			return this->KH.Ho_ten;
		}
		
		void set_Ho_ten(string Ho_ten)
		{
			chuan_hoa_chu();
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
			cout << "Ngay sinh (dd mm yy): " << KH.Ngay_sinh.Ngay << "/" << KH.Ngay_sinh.Thang << "/" << KH.Ngay_sinh.Nam << endl;
			cout << "So dien thoai: " << KH.So_dien_thoai << endl;
			
			Dat_phong::Xuat_dat_phong();
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
						cout << "\nNhap ngay sinh khach hang (dd mm yy): ";
						fflush(stdin);
						cin >> KH.Ngay_sinh.Ngay;
						cin >> KH.Ngay_sinh.Thang;
						cin >> KH.Ngay_sinh.Nam;
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
						
						cout << "Nhap ngay sinh khach hang (dd mm yy): ";
						fflush(stdin);
						cin >> KH.Ngay_sinh.Ngay;
						cin >> KH.Ngay_sinh.Thang;
						cin >> KH.Ngay_sinh.Nam;
						
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
		
		void Khach_N_ci()
		{
			Check_in::Nhap_thoi_gian_vao();
		}
		
		void Khach_X_ci()
		{
			cout << "---------------------\n";
			cout << "\nXAC NHAN LAI\n";
			cout << "---------------------\n";
			Check_in::Xuat_thoi_gian_vao();
			cout << "----------------------------------------------------\n";
		}
		
		void Khach_N_co()
		{
			Check_out::Nhap_thoi_gian_ra();
		}
		
		void Khach_X_co()
		{
			cout << "---------------------\n";
			cout << "\nXAC NHAN LAI\n";
			cout << "---------------------\n";
			Check_out::Xuat_thoi_gian_ra();
			cout << "----------------------------------------------------\n";
		}
		
		void Khach_tra_phong()
		{
			Thanh_toan::Lap_hoa_don();
		}
};
