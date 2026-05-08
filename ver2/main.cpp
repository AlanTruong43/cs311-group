#include <iostream>
#include "HangThucPham.h"
#include "HangDienTu.h"
using namespace std;

int main() {
    const int MAX = 100;
    SanPham* danhSach[MAX];
    int soLuongSP = 0;
    int luaChon;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Them Hang Thuc Pham\n";
        cout << "2. Them Hang Dien Tu\n";
        cout << "3. Xuat danh sach\n";
        cout << "4. Tinh tong tien toan kho\n";
        cout << "0. Thoat\n";
        cout << "Chon: "; cin >> luaChon;

        if (luaChon == 1) {
            if (soLuongSP >= MAX) { cout << "[!] Danh sach day!\n"; continue; }
            HangThucPham* sp = new HangThucPham();
            cout << "\n-- Nhap thong tin Hang Thuc Pham --\n";
            sp->nhapThongTin();
            danhSach[soLuongSP++] = sp;
            cout << "[+] Da them san pham!\n";

        } else if (luaChon == 2) {
            if (soLuongSP >= MAX) { cout << "[!] Danh sach day!\n"; continue; }
            HangDienTu* sp = new HangDienTu();
            cout << "\n-- Nhap thong tin Hang Dien Tu --\n";
            sp->nhapThongTin();
            danhSach[soLuongSP++] = sp;
            cout << "[+] Da them san pham!\n";

        } else if (luaChon == 3) {
            if (soLuongSP == 0) { cout << "(Chua co san pham)\n"; continue; }
            cout << "\n========== DANH SACH ==========\n";
            for (int i = 0; i < soLuongSP; i++) {
                danhSach[i]->xuatThongTin();
                cout << "  Tong tien: " << danhSach[i]->tinhTongTien() << " VND\n\n";
            }

        } else if (luaChon == 4) {
            double tong = 0;
            for (int i = 0; i < soLuongSP; i++) tong += danhSach[i]->tinhTongTien();
            cout << "\nTong tien toan kho: " << tong << " VND\n";
        }

    } while (luaChon != 0);

    for (int i = 0; i < soLuongSP; i++) delete danhSach[i];
    return 0;
}
