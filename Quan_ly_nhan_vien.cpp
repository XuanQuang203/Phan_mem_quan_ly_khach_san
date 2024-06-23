#include <iostream>
#include <string>

using namespace std;

class Nhan_vien
{
	private:
		struct Ngay_thang_nam
		{
			int Ngay, Thang, Nam;
			
			Ngay_thang_nam() {}
			
			Ngay_thang_nam(int _Ngay, int _Thang, int _Nam)
			: Ngay(_Ngay), Thang (_Thang), Nam (_Nam) {}
		} NTN;
		
		struct Thong_tin_nv
		{
			string Cccd, So_dien_thoai, Ho_ten;
			Ngay_thang_nam Ngay_sinh;
			
			Thong_tin_nv() {}
			
			Thong_tin_nv(string _Quay_tiep_khach, string _Cccd, string _So_dien_thoai, string _Ho_ten, Ngay_thang_nam _Ngay_sinh)
			: Ho_ten(_Ho_ten), Cccd(_Cccd), Ngay_sinh(_Ngay_sinh), So_dien_thoai(_So_dien_thoai) {}
		} NV;
};
