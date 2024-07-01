#include "checkIn.h"

void checkIn::nhap_checkIn() {
    cout << "Gio check-in: ";
    cin >> gioVao;
}

int checkIn::get_gioVao() {
    return gioVao;
}

void checkIn::set_gioVao(int _gioVao) {
    gioVao = _gioVao;
}

void checkIn::sua_checkIn(int gioVao) {
    cout << "Sua thoi gian check in: ";
    set_gioVao(gioVao);
}

void checkIn::xoa_checkIn() {
    gioVao = 0;
}

void checkIn::xuat_checkIn() {
    cout << "Gio check-in: " << gioVao << endl;
}

