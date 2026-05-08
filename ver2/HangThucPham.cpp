#include "HangThucPham.h"
#include <iostream>
using namespace std;

HangThucPham::HangThucPham()
    : SanPham(), nhietDoLuuTru(0.0) {}

HangThucPham::HangThucPham(string ten, int ma, double g, int sl, string loaiSP,
                            string thuong, string nuoc, NhaCungCap ncc,
                            string hanSD, string loai, double nhiet)
    : SanPham(ten, ma, g, sl, loaiSP, thuong, nuoc, ncc),
      hanSuDung(hanSD), loaiThucPham(loai), nhietDoLuuTru(nhiet) {}

void HangThucPham::nhapThongTin() {
    SanPham::nhapThongTin();
    cout << "  Han su dung (YYYY-MM-DD): "; getline(cin, hanSuDung);
    cout << "  Loai thuc pham          : "; getline(cin, loaiThucPham);
    cout << "  Nhiet do luu tru (do C) : "; cin >> nhietDoLuuTru;
}

void HangThucPham::xuatThongTin() const {
    cout << "--- [HANG THUC PHAM] ---\n";
    SanPham::xuatThongTin();
    cout << "  Han su dung : " << hanSuDung     << "\n";
    cout << "  Loai        : " << loaiThucPham   << "\n";
    cout << "  Nhiet do    : " << nhietDoLuuTru  << " do C\n";
}

bool HangThucPham::conHan(string ngayHienTai) const {
    return hanSuDung >= ngayHienTai;
}

void soSanhHanSD(const HangThucPham& a, const HangThucPham& b) {
    cout << "\n[SO SANH HAN SD]\n";
    cout << "  " << a.tenSanPham << ": " << a.hanSuDung << "\n";
    cout << "  " << b.tenSanPham << ": " << b.hanSuDung << "\n";
    if (a.hanSuDung < b.hanSuDung)
        cout << "  => '" << a.tenSanPham << "' het han truoc!\n";
    else
        cout << "  => '" << b.tenSanPham << "' het han truoc!\n";
}
