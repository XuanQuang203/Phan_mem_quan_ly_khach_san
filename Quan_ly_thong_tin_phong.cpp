#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#pragma once
using namespace std;

class Danh_sach_phong 
{
    protected:
        struct Dac_diem_phong 
		{
	        string Giuong, Noi_that, Wc, View;
	        
	        Dac_diem_phong() {}
	        
	        Dac_diem_phong(string _Giuong, string _Noi_that, string _Wc, string _View)
        	: Giuong(_Giuong), Noi_that(_Noi_that), Wc(_Wc), View(_View) {}
    	};
        
        struct Ma_phong 
		{
	        int Phong, Tang;
	        
	        Ma_phong() {}
	        
	        Ma_phong(int _Tang, int _Phong)
	        : Tang(_Tang), Phong(_Phong) {}
		};
        
        struct Thong_tin_phong 
		{
	        Ma_phong So_phong;
	        Dac_diem_phong Dac_diem;
	        string Tinh_trang = "Trong";
	        
	        Thong_tin_phong() {}
	        
	        Thong_tin_phong(Ma_phong _So_phong, Dac_diem_phong _Dac_diem, string _Tinh_trang)
        	: So_phong(_So_phong), Dac_diem(_Dac_diem), Tinh_trang (_Tinh_trang) {}
		} Ds_p[3];
        
    public:
        Danh_sach_phong() 
	    {
	        Ds_p[0] = Thong_tin_phong(Ma_phong(1, 1), Dac_diem_phong("Don", "Co ban", "1", "Vuon"), "Trong");
	        Ds_p[1] = Thong_tin_phong(Ma_phong(1, 2), Dac_diem_phong("Doi", "Full", "2", "Bien"), "Trong");
	        Ds_p[2] = Thong_tin_phong(Ma_phong(2, 1), Dac_diem_phong("Doi", "Full", "3", "Bien"), "Trong");
	    }
    	
    	int get_So_phong(int i) 
		{
	        if(i < 0 || i >= 3) 
	        {
	        	return -1;
			}
	        return Ds_p[i].So_phong.Tang * 100 + Ds_p[i].So_phong.Phong;
		}
    	
        void Nhap_thong_tin_ds()
		{

        	int i;
        	cout << "\nNhap ma phong can sua (1, 2, 3): ";
        	cin >> i;
        	
        	if(i <= 0 || i > 3)
            {
                cout << "Khong ton tai ma phong, vui long thu lai!\n";
                return;
            }
            
			cout << "---------------------\n";
    		cout << "Tang thu: " ;
            cin >> Ds_p[i-1].So_phong.Tang;
            
            cout << "Phong so: " ;
            cin >> Ds_p[i-1].So_phong.Phong;
            
            cout << "So phong: ";
            Danh_sach_phong::get_So_phong(i-1);
            
            cout << "Nhap thong tin giuong: " ;
            cin.ignore();
            getline(cin, Ds_p[i-1].Dac_diem.Giuong);
            
            cout << "Nhap thong tin noi that: " ;
            getline(cin, Ds_p[i-1].Dac_diem.Noi_that);
            
            cout << "Nhap thong tin WC: " ;
            getline(cin, Ds_p[i-1].Dac_diem.Wc);
            
            cout << "Nhap thong tin View:" ;
            getline(cin, Ds_p[i-1].Dac_diem.View);
        }
        
        void Hien_thong_tin_ds()
		{
            for(int i=0; i<3; i++)
			{
                cout << "\nThong tin phong " << endl;
                cout << "---------------------\n";
                
                cout << "Ma phong: " << setw(5) << i+1 
				<< setw(9) << i+2 
				<< setw(9) << i+3 << endl;
				
                cout << "So phong: " << setw(6) << Ds_p[i].So_phong.Tang * 100 + Ds_p[i].So_phong.Phong 
				<< setw(9) << Ds_p[i+1].So_phong.Tang * 100 + Ds_p[i+1].So_phong.Phong 
				<< setw(9) << Ds_p[i+2].So_phong.Tang * 100 + Ds_p[i+2].So_phong.Phong << endl;
				
				cout << "Giuong: " << setw(8) << Ds_p[i].Dac_diem.Giuong 
				<< setw(9) << Ds_p[i+1].Dac_diem.Giuong 
				<< setw(9) << Ds_p[i+2].Dac_diem.Giuong << endl;
				
                cout << "Noi that: " << setw(9) << Ds_p[i].Dac_diem.Noi_that 
				<< setw(7) << Ds_p[i+1].Dac_diem.Noi_that 
				<< setw(9) << Ds_p[i+2].Dac_diem.Noi_that << endl;
				
                cout << "So WC: " << setw(8) << Ds_p[i].Dac_diem.Wc 
				<< setw(9) << Ds_p[i+1].Dac_diem.Wc 
				<< setw(9) << Ds_p[i+2].Dac_diem.Wc << endl;
				
                cout << "View: " << setw(11) << Ds_p[i].Dac_diem.View 
				<< setw(9) << Ds_p[i+1].Dac_diem.View
				<< setw(9) << Ds_p[i+2].Dac_diem.View << endl;
				
                cout << endl;
                cout << "Tinh trang: " << setw(6) << Ds_p[i].Tinh_trang 
				<< setw(9) << Ds_p[i+1].Tinh_trang 
				<< setw(9) << Ds_p[i+2].Tinh_trang << endl;
				
                break;
            }
        }
        
        friend class Dat_phong;
};

class Dat_phong : public Danh_sach_phong 
{
	private:
	    struct Ngay_thang_nam 
		{
	        int Ngay, Thang, Nam;
	
	        Ngay_thang_nam() {}
	
	        Ngay_thang_nam(int _Ngay, int _Thang, int _Nam)
	            : Ngay(_Ngay), Thang(_Thang), Nam(_Nam) {}
	    };
	
	    struct Thong_tin_dat_phong 
		{
	        int Phong_da_dat;
	        Ngay_thang_nam Ngay_dat_phong;
	        int Phong_moi;
	        string Ly_do_doi;
	
	        Thong_tin_dat_phong() {}
	
	        Thong_tin_dat_phong(int _Phong_da_dat, Ngay_thang_nam _Ngay_dat_phong, int _Phong_moi, string _Ly_do_doi)
	            : Phong_da_dat(_Phong_da_dat), Ngay_dat_phong(_Ngay_dat_phong), Phong_moi(_Phong_moi), Ly_do_doi(_Ly_do_doi) {}
	    } DatP;
	
	public:
	    bool Kiem_tra_datp(int i) 
		{
	        return (i >= 0 && i < 3 && DatP.Phong_da_dat == get_So_phong(i));
	    }
	
	    bool Kiem_tra_doip(int i) 
		{
	        return (i >= 0 && i < 3 && DatP.Phong_moi == get_So_phong(i));
	    }
	
	    void Nhap_dat_phong() 
		{
	        while (true) 
			{
	            cout << "---------------------\n";
	            cout << "Phong khach muon dat: ";
	            cin >> DatP.Phong_da_dat;
	
	            bool valid = false;
	            for (int i = 0; i < 3; ++i) 
				{
	                if (Kiem_tra_datp(i)) 
					{
	                    valid = true;
	                    break;
	                }
	            }
	
	            if (valid) 
				{
	                cout << "Ngay dat phong (yyyy mm dd): ";
	                cin >> DatP.Ngay_dat_phong.Nam >> DatP.Ngay_dat_phong.Thang >> DatP.Ngay_dat_phong.Ngay;
	                cout << "---------------------\n\n";
	                break;
	            } 
				else 
				{
	                cout << "Phong khong dung, vui long nhap lai!\n";
	            }
	        }
	    }
	
	    int get_Phong_da_dat() 
		{
	        return DatP.Phong_da_dat;
	    }
	
	    void set_Phong_da_dat(int Phong_da_dat) 
		{
	        DatP.Phong_da_dat = Phong_da_dat;
	    }
	
	    void Xuat_dat_phong() 
		{
	        cout << "---------------------\n";
	        cout << "Phong duoc dat: " << DatP.Phong_da_dat << endl;
	        cout << "Ngay dat phong (dd mm yyyy): " << DatP.Ngay_dat_phong.Ngay << "/" << DatP.Ngay_dat_phong.Thang << "/" << DatP.Ngay_dat_phong.Nam << endl;
	        cout << "---------------------\n";
	    }
	
	    void Nhap_doi_phong() 
		{
	        while (true) 
			{
	            cout << "Khach muon chon phong: ";
	            cin >> DatP.Phong_moi;
	
	            bool valid = false;
	            for (int i = 0; i < 3; ++i) 
				{
	                if (Kiem_tra_doip(i)) 
					{
	                    valid = true;
	                    break;
	                }
	            }
	
	            if (valid) 
				{
	                if (DatP.Phong_moi == DatP.Phong_da_dat) 
					{
	                    cout << "Phong moi trung voi phong cu, vui long nhap lai!\n";
	                } 
					else 
					{
	                    cout << "Ly do doi phong cua khach: ";
	                    cin.ignore();
	                    getline(cin, DatP.Ly_do_doi);
	                    cout << endl;
	                    break;
	                }
	            } 
				else 
				{
	                cout << "Phong khong hop le, vui long chon lai!\n";
	            }
	        }
	    }
	
	    void Xac_nhan_lai() 
		{
	        cout << "Khach muon chon phong: " << DatP.Phong_moi << endl;
	        cout << "Ly do doi phong cua khach: " << DatP.Ly_do_doi << endl;
	    }
	
	    void Xuat_doi_phong() 
		{
	        cout << "\nTHONG BAO";
	        cout << "\n---------------------\n";
	        cout << "Xac nhan doi phong\n";
	        cout << "01. Xac nhan\n";
	        cout << "02. Huy bo\n";
	        cout << "---------------------\n";
	
	        int Lua_chon;
	        cout << "Lua chon: ";
	        cin >> Lua_chon;
	
	        if (Lua_chon == 1) 
			{
	            int x = DatP.Phong_da_dat;
	            DatP.Phong_da_dat = DatP.Phong_moi;
	            DatP.Phong_moi = x;
	
	            cout << "\nDa doi phong thanh cong!\n";
	            cout << "---------------------\n";
	            cout << "Phong truoc khi doi: " << DatP.Phong_moi << endl;
	            cout << "Phong sau khi doi: " << DatP.Phong_da_dat << endl;
	        } 
			else if (Lua_chon == 2) 
			{
	            cout << "\n\nHuy qua trinh doi phong!\n";
	        }
	    }
	
	    void Xoa_giao_dich() 
		{
	        // Function implementation
	    }
};
