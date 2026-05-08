#include "HangDienTu.h"
#include <iostream>
using namespace std;

HangDienTu::HangDienTu()
    : SanPham(), baoHanh(0), congSuat(0.0) {}

HangDienTu::HangDienTu(string ten, int ma, double g, int sl, string loaiSP,
                        string thuong, string nuoc, NhaCungCap ncc,
                        int bh, double cs, string pv, string ms)
    : SanPham(ten, ma, g, sl, loaiSP, thuong, nuoc, ncc),
      baoHanh(bh), congSuat(cs), phienBan(pv), mauSac(ms) {}

void HangDienTu::nhapThongTin() {
    SanPham::nhapThongTin();
    cout << "  Bao hanh (thang): "; cin >> baoHanh;
    cout << "  Cong suat (W)   : "; cin >> congSuat;
    cin.ignore();
    cout << "  Phien ban       : "; getline(cin, phienBan);
    cout << "  Mau sac         : "; getline(cin, mauSac);
}

void HangDienTu::xuatThongTin() const {
    cout << "--- [HANG DIEN TU] ---\n";
    SanPham::xuatThongTin();
    cout << "  Bao hanh : " << baoHanh  << " thang\n";
    cout << "  Cong suat: " << congSuat << " W\n";
    cout << "  Phien ban: " << phienBan  << "\n";
    cout << "  Mau sac  : " << mauSac    << "\n";
}

void soSanhBaoHanh(const HangDienTu& a, const HangDienTu& b) {
    cout << "\n[SO SANH BAO HANH]\n";
    cout << "  " << a.tenSanPham << ": " << a.baoHanh << " thang\n";
    cout << "  " << b.tenSanPham << ": " << b.baoHanh << " thang\n";
    if (a.baoHanh > b.baoHanh)
        cout << "  => '" << a.tenSanPham << "' bao hanh lau hon!\n";
    else
        cout << "  => '" << b.tenSanPham << "' bao hanh lau hon!\n";
}
