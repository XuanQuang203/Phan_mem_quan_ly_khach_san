#include "dichVu.h"

void dichVu::themDichVu () {
	string matHang[9] = {
        "Mi", "Com rang", "Hoa qua",
        "Nuoc cam", "Coca", "Bia",
        "Ban chai", "Khan tam", "Dau goi"
    };

    int gia[9] = {
        10, 50, 100,
        20, 20, 30,
        30, 50, 20
    };
    
    int luaChon, soLuong, tien;
    
    cout << "\nTHEM DICH VU\n";
    cout << "---------------------------------------------------------\n";
    cout << "Do an:\t  01. " << matHang[0] << "\t  02. " << matHang[1] << "\t  03. " << matHang[2] << endl;
    cout << "\t  " << gia[0] << ".000 vnd\t  " << gia[1] << ".000 nvd\t  " << gia[2] << ".000 vnd\n\n";
    cout << "Do uong:  04. " << matHang[3] << "\t  05. " << matHang[4] << "\t  06. " << matHang[5] << endl;
    cout << "\t  " << gia[3] << ".000 vnd\t  " << gia[4] << ".000 vnd\t  " << gia[5] << ".000 vnd\n\n";
    cout << "Khac:\t  07. " << matHang[6] << "\t  08. " << matHang[7] << "\t  09. " << matHang[8] << endl;
    cout << "\t  " << gia[6] << ".000 vnd\t  " << gia[7] << ".000 vnd\t  " << gia[8] << ".000 vnd\n";
    cout << "---------------------------------------------------------\n";
    cout << "00. Hoan tat lua chon.\n";
    cout << "---------------------\n";
    
    do {
        cout << "Khach chon: ";
        cin.ignore();
        cin >> luaChon;
        
        switch (luaChon) {
            case 1:
                cout << "Nhap so luong: ";
                cin >> soLuong;
                tien = soLuong * 10;
                
                cout << "So tien " << tien << ".000 vnd da duoc them vao hoa don.\n";
                break;
                
            case 2:
                
                break;
                
            case 3:
                
                break;
                
            case 0:
            	break;
            	
            default:
                cout << "Lua chon khong hop le, vui long chon lai.\n";
                break;
        }
    } while (luaChon <= 0 || luaChon > 9);
}

