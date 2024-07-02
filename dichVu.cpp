#include "dichVu.h"

void dichVu::them_dichVu() {
    int luaChon, soLuong;
    cout << "\nTHEM DICH VU\n";
    cout << "---------------------------------------------------------\n";
    cout << "Do an:" << "      01. Mi           02. Com rang     03. Hoa qua\n";
    cout << "            10.000 vnd       ";
    cout << "Do uong:    04. Nuoc cam     05. Coca         06. Bia\n";
    cout << "Khac:       07. Ban chai     08. Khan tam     09. Dau goi";
    cout << "---------------------------------------------------------\n";
    
    do {
        cout << "Khach chon: ";
        cin >> luaChon;
        switch(luaChon) {
            case 1:
                // Logic cho Do an
                break;
            case 2:
                // Logic cho Do uong
                break;
            case 3:
                // Logic cho Khac
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai.\n";
                break;
        }
    } while(luaChon <= 0 || luaChon > 3);
}

