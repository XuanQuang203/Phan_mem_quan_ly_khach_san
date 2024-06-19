#include "Quan_ly_thong_tin_phong.cpp"
#pragma once

class Check_in 
{
	protected:
		struct Thoi_gian
		{
			int Ngay_vao, Gio_vao;
			
			Thoi_gian() {}
			
			Thoi_gian(int _Ngay_vao, int _Gio_vao)
			: Ngay_vao(_Ngay_vao), Gio_vao(_Gio_vao) {}
		} tg_ci;
	    
	public:
		void Nhap_thoi_gian_vao() 
		{
	        cout << "Nhap ngay check-in: ";
	        cin >> tg_ci.Ngay_vao;
	        
	        cout << "Nhap gio check-in: ";
	        cin >> tg_ci.Gio_vao;
	    }
	    
	    int get_Ngay_vao()
		{
	        return tg_ci.Ngay_vao;
	    }
	
	    void set_Ngay_vao(int Ngay_vao) 
		{
	        Ngay_vao = Ngay_vao;
	    }
	
	    int get_Gio_vao() 
		{
	        return tg_ci.Gio_vao;
	    }
	
	    void set_Gio_vao(int Gio_vao) 
		{
	        Gio_vao = Gio_vao;
	    }
	
	    void Xuat_thoi_gian_vao() 
		{
	        cout << "Ngay check-in: " << tg_ci.Ngay_vao << endl;
	        cout << "Gio check-in: " << tg_ci.Gio_vao << endl;
	    }
	    
	    friend class Check_out;
	    friend class Thanh_toan;
};

class Check_out : public Check_in 
{
	protected:
		struct Thoi_gian
		{
			int Ngay_ra, Gio_ra;
			
			Thoi_gian() {}
			
			Thoi_gian(int _Ngay_ra, int _Gio_ra)
			: Ngay_ra(_Ngay_ra), Gio_ra(_Gio_ra) {}
		} tg_co;
		
	public:
		void Nhap_thoi_gian_ra() 
		{
	        cout << "Nhap ngay check-out: ";
	        cin >> tg_co.Ngay_ra;
	        cout << "Nhap gio check-out: ";
	        cin >> tg_co.Gio_ra;
	    }
		
	    int get_Ngay_ra() 
		{
	        return tg_co.Ngay_ra;
	    }
	
	    void set_Ngay_ra(int Ngay_ra) 
		{
	        tg_co.Ngay_ra = Ngay_ra;
	    }
	
	    int get_Gio_ra() 
		{
	        return tg_co.Gio_ra;
	    }
	
	    void set_Gio_ra(int Gio_ra) 
		{
	        tg_co.Gio_ra = Gio_ra;
	    }
	
	    void Xuat_thoi_gian_ra()
		{
	        cout << "Ngay check-out: " << tg_co.Ngay_ra << endl;
	        cout << "Gio check-out: " << tg_co.Gio_ra << endl;
	    }
	    
	    friend class Thanh_toan;
};

class Thanh_toan : public Check_out
{
	private:
	    int Thanh_tien, Gia_ngay = 2500000, Gia_gio = 150000;
	    int So_ngay_thue, So_gio_thue;
	    
	public:
		int Lap_hoa_don() 
		{
			int tien, x, y;
	        x = Check_out::get_Ngay_ra() - Check_in::get_Ngay_vao();
	        if(x == 0)
			{
	        	y = (Check_out::get_Gio_ra() - Check_in::get_Gio_vao());
			}
			else if(x > 0)
			{
				y = (Check_out::get_Ngay_ra() - Check_in::get_Ngay_vao()) * 24 + (Check_out::get_Gio_ra() - Check_in::get_Gio_vao());
			}
			else
			{
				cout << "Loi tinh toan, vui long kiem tra lai thong tin da nhap!\n";
			}
			
			if(y == 0)
			{
	        	cout << "Loi tinh toan, vui long kiem tra lai thong tin da nhap!\n";
			}
			return y;
			
			tien = x * Gia_ngay + y * Gia_gio;

	        cout << "HOA DON\n";
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
	        cout << "Khach chon: ";
	        chonlai:
	        cin >> luachon;
	        
	        if(luachon == 1)
			{
	        	cout << "XAC NHAN PHUONG THUC: Tien mat";
			}
			else if(luachon == 2)
			{
				cout << "XAC NHAN PHUONG THUC: Chuyen khoan";
			}
			else
			{
				cout << "Loi nhap, vui long thu lai!";
				goto chonlai;
			}
			cout << "---------------------\n";
			cout << "Cam on quy khach da su dung dich vu!";
	    }
};

