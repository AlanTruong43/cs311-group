#pragma once
#include "SanPham.h"

class HangDienTu : public SanPham {
private:
    int    baoHanh;
    double congSuat;
    string phienBan;
    string mauSac;

    friend void soSanhBaoHanh(const HangDienTu& a, const HangDienTu& b);

public:
    HangDienTu();
    HangDienTu(string ten, int ma, double g, int sl, string loaiSP,
               string thuong, string nuoc, NhaCungCap ncc,
               int bh, double cs, string pv, string ms);

    int    getBaoHanh()  const { return baoHanh; }
    double getCongSuat() const { return congSuat; }
    string getPhienBan() const { return phienBan; }
    string getMauSac()   const { return mauSac; }

    void setBaoHanh(int b)     { if (b >= 0) baoHanh = b; }
    void setCongSuat(double c) { if (c >= 0) congSuat = c; }
    void setPhienBan(string p) { phienBan = p; }
    void setMauSac(string m)   { mauSac = m; }

    void nhapThongTin() override;
    void xuatThongTin() const override;
};

void soSanhBaoHanh(const HangDienTu& a, const HangDienTu& b);
