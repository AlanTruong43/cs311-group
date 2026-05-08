#pragma once
#include <string>
#include "NhaCungCap.h"
using namespace std;

class SanPham {
protected:
    string     tenSanPham;
    int        maSanPham;
    double     gia;
    int        soLuong;
    string     loaiSP;
    string     thuongHieu;
    string     nuocSanXuat;
    NhaCungCap nhaCungCap;

public:
    SanPham();
    SanPham(string ten, int ma, double g, int sl, string loai,
            string thuong, string nuoc, NhaCungCap ncc);
    virtual ~SanPham() {}

    string     getTenSanPham()  const { return tenSanPham; }
    int        getMaSanPham()   const { return maSanPham; }
    double     getGia()         const { return gia; }
    int        getSoLuong()     const { return soLuong; }
    string     getLoaiSP()      const { return loaiSP; }
    string     getThuongHieu()  const { return thuongHieu; }
    string     getNuocSanXuat() const { return nuocSanXuat; }
    NhaCungCap getNhaCungCap()  const { return nhaCungCap; }

    void setTenSanPham(string ten)   { tenSanPham = ten; }
    void setMaSanPham(int ma)        { maSanPham = ma; }
    void setGia(double g)            { if (g >= 0) gia = g; }
    void setSoLuong(int sl)          { if (sl >= 0) soLuong = sl; }
    void setLoaiSP(string loai)      { loaiSP = loai; }
    void setThuongHieu(string t)     { thuongHieu = t; }
    void setNuocSanXuat(string n)    { nuocSanXuat = n; }
    void setNhaCungCap(NhaCungCap n) { nhaCungCap = n; }

    virtual void nhapThongTin();
    virtual void xuatThongTin() const;
    void   capNhatGia(double giaMoi);
    void   capNhatSoLuong(int slMoi);
    double tinhTongTien() const;
};
