#include "SanPham.h"
#include <iostream>
using namespace std;

SanPham::SanPham()
    : maSanPham(0), gia(0.0), soLuong(0) {}

SanPham::SanPham(string ten, int ma, double g, int sl, string loai,
                 string thuong, string nuoc, NhaCungCap ncc)
    : tenSanPham(ten), maSanPham(ma), gia(g), soLuong(sl), loaiSP(loai),
      thuongHieu(thuong), nuocSanXuat(nuoc), nhaCungCap(ncc) {}

void SanPham::nhapThongTin() {
    cin.ignore();
    cout << "  Ten san pham : "; getline(cin, tenSanPham);
    cout << "  Ma san pham  : "; cin >> maSanPham;
    cout << "  Gia          : "; cin >> gia;
    cout << "  So luong     : "; cin >> soLuong;
    cin.ignore();
    cout << "  Loai SP      : "; getline(cin, loaiSP);
    cout << "  Thuong hieu  : "; getline(cin, thuongHieu);
    cout << "  Nuoc san xuat: "; getline(cin, nuocSanXuat);
    cout << "  Ten NCC      : "; getline(cin, nhaCungCap.ten);
}

void SanPham::xuatThongTin() const {
    cout << "  Ma SP       : " << maSanPham        << "\n";
    cout << "  Ten SP      : " << tenSanPham        << "\n";
    cout << "  Gia         : " << gia               << " VND\n";
    cout << "  So luong    : " << soLuong           << "\n";
    cout << "  Loai SP     : " << loaiSP            << "\n";
    cout << "  Thuong hieu : " << thuongHieu        << "\n";
    cout << "  Nuoc SX     : " << nuocSanXuat       << "\n";
    cout << "  Nha CC      : " << nhaCungCap.ten    << "\n";
}

void SanPham::capNhatGia(double giaMoi)   { if (giaMoi >= 0) gia = giaMoi; }
void SanPham::capNhatSoLuong(int slMoi)   { if (slMoi >= 0) soLuong = slMoi; }
double SanPham::tinhTongTien() const      { return gia * soLuong; }
