#include <iostream>
#include <string>
#pragma once

using namespace std;

class nhanVien{
	private:
		struct ngayThangNam{
			int Ngay, Thang, Nam;
			
			ngayThangNam() {}
			
			ngayThangNam(int _Ngay, int _Thang, int _Nam)
			: Ngay(_Ngay), Thang (_Thang), Nam (_Nam) {}
		} ntn;
		
		struct Thong_tin_nv{
			string Cccd, So_dien_thoai, Ho_ten;
			ngayThangNam ngaySinh;
			
			Thong_tin_nv() {}
			
			Thong_tin_nv(string _Quay_tiep_khach, string _Cccd, string _So_dien_thoai, string _Ho_ten, ngayThangNam _ngaySinh)
			: Ho_ten(_Ho_ten), Cccd(_Cccd), ngaySinh(_ngaySinh), So_dien_thoai(_So_dien_thoai) {}
		} nv;
};
