#include "dichVu.h"

void dichVu::them_dichVu() {
    int luaChon;
    cout << "\nTHEM DICH VU\n";
    cout << "---------------------\n";
    cout << "01. Do an\n";
    cout << "02. Do uong\n";
    cout << "03. Khac\n";
    cout << "---------------------\n";
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

