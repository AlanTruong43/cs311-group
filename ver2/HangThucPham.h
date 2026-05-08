#pragma once
#include "SanPham.h"

class HangThucPham : public SanPham {
private:
    string hanSuDung;
    string loaiThucPham;
    double nhietDoLuuTru;

    friend void soSanhHanSD(const HangThucPham& a, const HangThucPham& b);

public:
    HangThucPham();
    HangThucPham(string ten, int ma, double g, int sl, string loaiSP,
                 string thuong, string nuoc, NhaCungCap ncc,
                 string hanSD, string loai, double nhiet);

    string getHanSuDung()     const { return hanSuDung; }
    string getLoaiThucPham()  const { return loaiThucPham; }
    double getNhietDoLuuTru() const { return nhietDoLuuTru; }

    void setHanSuDung(string h)     { hanSuDung = h; }
    void setLoaiThucPham(string l)  { loaiThucPham = l; }
    void setNhietDoLuuTru(double n) { nhietDoLuuTru = n; }

    void nhapThongTin() override;
    void xuatThongTin() const override;
    bool conHan(string ngayHienTai) const;
};

void soSanhHanSD(const HangThucPham& a, const HangThucPham& b);
