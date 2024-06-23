#include "Quan_ly_thong_tin_phong.cpp"

class Check_in 
{
	public:
		int Gio_vao;
		
		void Nhap_thoi_gian_vao() 
		{   
	        cout << "Gio check-in: ";
	        cin >> Gio_vao;
	    }
	
	    int get_Gio_vao()
		{
	        return Gio_vao;
	    }
	
	    void set_Gio_vao(int _Gio_vao) 
		{
	        Gio_vao = _Gio_vao;
	    }
	    
	    void Xoa_ci()
	    {
	    	Gio_vao = 0;
		}
	
	    void Xuat_thoi_gian_vao()
		{
	        cout << "Gio check-in: " << Gio_vao << endl;
	    }
	    
	    friend class Check_out;
};

class Check_out : public Check_in
{
	protected:
		struct Ngay_thang_nam 
		{
	        int Ngay, Thang, Nam;
	
	        Ngay_thang_nam() {}
	
	        Ngay_thang_nam(int _Ngay, int _Thang, int _Nam)
	            : Ngay(_Ngay), Thang(_Thang), Nam(_Nam) {}
	    } NTN;
		
		struct Thoi_gian
		{
			Ngay_thang_nam Ngay_ra;
			int Gio_ra;
			
			Thoi_gian() {}
			
			Thoi_gian(Ngay_thang_nam _Ngay_ra, int _Gio_ra)
			: Ngay_ra(_Ngay_ra), Gio_ra(_Gio_ra) {}
		} tg_co;
		
	public:
		bool kt_yy(int yy) {
		    return yy >= 2024;
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
		
		void Nhap_thoi_gian_ra() 
		{
			cout << "Gio check-out: ";
	        cin >> tg_co.Gio_ra;
	        
	        do 
				{
					cout << "Ngay check-out (dd mm yyyy): "; 
		        	cin >> NTN.Ngay >> NTN.Thang >> NTN.Nam;
		        	
		            if (!kt_yy(NTN.Nam) || !kt_mm(NTN.Thang, NTN.Nam) || !kt_dd(NTN.Ngay, NTN.Thang, NTN.Nam)) 
					{
		                cout << "Khong hop le, vui long nhap lai!\n";
		                cout << "---------------------\n";
		            }
		        } 
				while (!kt_yy(NTN.Nam) || !kt_mm(NTN.Thang, NTN.Nam) || !kt_dd(NTN.Ngay, NTN.Thang, NTN.Nam));
		        tg_co.Ngay_ra = NTN;
	    }
		
	    int get_Ngay_ra() 
		{
	        return NTN.Ngay;
	    }
	
	    void set_Ngay_ra(int Ngay_ra) 
		{
	        NTN.Ngay = Ngay_ra;
	    }
	
	    int get_Gio_ra() 
		{
	        return tg_co.Gio_ra;
	    }
	
	    void set_Gio_ra(int Gio_ra) 
		{
	        tg_co.Gio_ra = Gio_ra;
	    }
	    
	    void Xoa_co()
	    {
	    	tg_co.Gio_ra = 0;
	    	NTN.Ngay = 0;
	    	NTN.Thang = 0;
	    	NTN.Nam = 0;
	    	tg_co.Ngay_ra = NTN;
		}
	
	    void Xuat_thoi_gian_ra()
		{
	        cout << "Ngay check-out: " << tg_co.Ngay_ra.Ngay << "/" << tg_co.Ngay_ra.Thang << "/" << tg_co.Ngay_ra.Nam << endl;
	        cout << "Gio check-out: " << tg_co.Gio_ra << endl;
	    }
};

