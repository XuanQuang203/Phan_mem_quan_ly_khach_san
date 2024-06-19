#include <fstream>
#include "Quan_ly_nhan_vien.cpp"
#include "Quan_ly_khach_hang.cpp"
#pragma once

using namespace std;

class Bao_cao
{
	public:		
		void Nhap_bc()
		{
			fstream fs;
			
			fs.open("text.txt", ios::out | ios::app);
			
			if(!fs.is_open())
			{
				cout << "Khong mo duoc file";
			}
			
			fs << "Heloo";
			fs.close();
		}
		
		void Xuat_bc()
		{
			
		}
		
};
