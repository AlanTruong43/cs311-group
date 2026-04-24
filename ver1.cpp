#include <iostream>
#include <string>
using namespace std;

// ===================== STRUCT =====================
struct NhaCungCap {
    string ten;
    string diaChi;
    string soDienThoai;
};

// ===================== BASE CLASS: SANPHAM =====================
class SanPham {
protected:
    string     tenSanPham;
    int        maSanPham;
    double     gia;
    int        soLuong;
    string     thuongHieu;
    string     nuocSanXuat;
    NhaCungCap nhaCungCap;

public:
    // ---------- Constructors ----------
    SanPham()
        : maSanPham(0), gia(0.0), soLuong(0) {}

    SanPham(string ten, int ma, double g, int sl,
            string thuong, string nuoc, NhaCungCap ncc)
        : tenSanPham(ten), maSanPham(ma), gia(g), soLuong(sl),
          thuongHieu(thuong), nuocSanXuat(nuoc), nhaCungCap(ncc) {}

    virtual ~SanPham() {}

    // ---------- Getters ----------
    string     getTenSanPham()  const { return tenSanPham; }
    int        getMaSanPham()   const { return maSanPham; }
    double     getGia()         const { return gia; }
    int        getSoLuong()     const { return soLuong; }
    string     getThuongHieu()  const { return thuongHieu; }
    string     getNuocSanXuat() const { return nuocSanXuat; }
    NhaCungCap getNhaCungCap()  const { return nhaCungCap; }

    // ---------- Setters ----------
    void setTenSanPham(string ten)    { tenSanPham = ten; }
    void setMaSanPham(int ma)         { maSanPham = ma; }
    void setGia(double g)             { if (g >= 0) gia = g; }
    void setSoLuong(int sl)           { if (sl >= 0) soLuong = sl; }
    void setThuongHieu(string t)      { thuongHieu = t; }
    void setNuocSanXuat(string n)     { nuocSanXuat = n; }
    void setNhaCungCap(NhaCungCap n)  { nhaCungCap = n; }

    // ---------- 4 Phuong Thuc ----------
    // 1. Nhap thong tin
    virtual void nhapThongTin() {
        cin.ignore();
        cout << "  Ten san pham : "; getline(cin, tenSanPham);
        cout << "  Ma san pham  : "; cin >> maSanPham;
        cout << "  Gia          : "; cin >> gia;
        cout << "  So luong     : "; cin >> soLuong;
        cin.ignore();
        cout << "  Thuong hieu  : "; getline(cin, thuongHieu);
        cout << "  Nuoc san xuat: "; getline(cin, nuocSanXuat);
        cout << "  Ten NCC      : "; getline(cin, nhaCungCap.ten);
    }

    // 2. Xuat thong tin
    virtual void xuatThongTin() const {
        cout << "  Ma SP        : " << maSanPham        << "\n";
        cout << "  Ten SP       : " << tenSanPham        << "\n";
        cout << "  Gia          : " << gia               << " VND\n";
        cout << "  So luong     : " << soLuong           << "\n";
        cout << "  Thuong hieu  : " << thuongHieu        << "\n";
        cout << "  Nuoc SX      : " << nuocSanXuat       << "\n";
        cout << "  Nha CC       : " << nhaCungCap.ten    << "\n";
    }

    // 3. Cap nhat gia
    void capNhatGia(double giaMoi) {
        if (giaMoi >= 0) gia = giaMoi;
    }

    // 4. Cap nhat so luong
    void capNhatSoLuong(int slMoi) {
        if (slMoi >= 0) soLuong = slMoi;
    }
};

// ===================== DERIVED CLASS: HANGTHUCPHAM =====================
class HangThucPham : public SanPham {
private:
    string hanSuDung;
    string loaiThucPham;
    double nhietDoLuuTru;

    friend void soSanhHanSD(const HangThucPham& a, const HangThucPham& b);

public:
    // ---------- Constructors ----------
    HangThucPham()
        : SanPham(), nhietDoLuuTru(0.0) {}

    HangThucPham(string ten, int ma, double g, int sl,
                 string thuong, string nuoc, NhaCungCap ncc,
                 string hanSD, string loai, double nhiet)
        : SanPham(ten, ma, g, sl, thuong, nuoc, ncc),
          hanSuDung(hanSD), loaiThucPham(loai), nhietDoLuuTru(nhiet) {}

    // ---------- 5 Chuc Nang ----------
    // 1. Nhap thong tin (override)
    void nhapThongTin() override {
        SanPham::nhapThongTin();
        cout << "  Han su dung (YYYY-MM-DD): "; getline(cin, hanSuDung);
        cout << "  Loai thuc pham          : "; getline(cin, loaiThucPham);
        cout << "  Nhiet do luu tru (do C) : "; cin >> nhietDoLuuTru;
    }

    // 2. Xuat thong tin (override)
    void xuatThongTin() const override {
        cout << "--- [HANG THUC PHAM] ---\n";
        SanPham::xuatThongTin();
        cout << "  Han su dung  : " << hanSuDung     << "\n";
        cout << "  Loai         : " << loaiThucPham  << "\n";
        cout << "  Nhiet do     : " << nhietDoLuuTru << " do C\n";
    }

    // 3. Getter han su dung
    string getHanSuDung() const { return hanSuDung; }

    // 4. Setter han su dung
    void setHanSuDung(string h) { hanSuDung = h; }

    // 5. Kiem tra con han
    bool conHan(string ngayHienTai) const {
        return hanSuDung >= ngayHienTai;
    }
};

// ===================== DERIVED CLASS: HANGDIENTU =====================
class HangDienTu : public SanPham {
private:
    int    baoHanh;
    double congSuat;
    string phienBan;
    string mauSac;

    friend void soSanhBaoHanh(const HangDienTu& a, const HangDienTu& b);

public:
    // ---------- Constructors ----------
    HangDienTu()
        : SanPham(), baoHanh(0), congSuat(0.0) {}

    HangDienTu(string ten, int ma, double g, int sl,
               string thuong, string nuoc, NhaCungCap ncc,
               int bh, double cs, string pv, string ms)
        : SanPham(ten, ma, g, sl, thuong, nuoc, ncc),
          baoHanh(bh), congSuat(cs), phienBan(pv), mauSac(ms) {}

    // ---------- 5 Chuc Nang ----------
    // 1. Nhap thong tin (override)
    void nhapThongTin() override {
        SanPham::nhapThongTin();
        cout << "  Bao hanh (thang): "; cin >> baoHanh;
        cout << "  Cong suat (W)   : "; cin >> congSuat;
        cin.ignore();
        cout << "  Phien ban       : "; getline(cin, phienBan);
        cout << "  Mau sac         : "; getline(cin, mauSac);
    }

    // 2. Xuat thong tin (override)
    void xuatThongTin() const override {
        cout << "--- [HANG DIEN TU] ---\n";
        SanPham::xuatThongTin();
        cout << "  Bao hanh     : " << baoHanh  << " thang\n";
        cout << "  Cong suat    : " << congSuat << " W\n";
        cout << "  Phien ban    : " << phienBan  << "\n";
        cout << "  Mau sac      : " << mauSac    << "\n";
    }

    // 3. Getter bao hanh
    int getBaoHanh() const { return baoHanh; }

    // 4. Setter bao hanh
    void setBaoHanh(int b) { if (b >= 0) baoHanh = b; }

    // 5. Getter cong suat
    double getCongSuat() const { return congSuat; }
};

// ===================== FRIEND FUNCTIONS =====================
void soSanhHanSD(const HangThucPham& a, const HangThucPham& b) {
    cout << "\n[SO SANH HAN SD]\n";
    cout << "  " << a.tenSanPham << ": " << a.hanSuDung << "\n";
    cout << "  " << b.tenSanPham << ": " << b.hanSuDung << "\n";
    if (a.hanSuDung < b.hanSuDung)
        cout << "  => '" << a.tenSanPham << "' het han truoc!\n";
    else
        cout << "  => '" << b.tenSanPham << "' het han truoc!\n";
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

// ===================== MAIN =====================
int main() {
    NhaCungCap ncc1 = {"Cong ty Thuc Pham Sach", "Ha Noi",    "0901234567"};
    NhaCungCap ncc2 = {"Cong ty Samsung VN",     "Binh Duong","0912345678"};

    HangThucPham tp1("Sua TH True Milk", 201, 35000, 100,
                     "TH", "Viet Nam", ncc1,
                     "2025-12-01", "Dong lanh", 4.0);

    HangThucPham tp2("Banh Oreo", 202, 25000, 200,
                     "Oreo", "USA", ncc1,
                     "2025-08-15", "Kho", 25.0);

    HangDienTu dt1("Samsung Galaxy S24", 301, 22000000, 10,
                   "Samsung", "Han Quoc", ncc2,
                   24, 25.0, "S24-5G", "Den");

    HangDienTu dt2("Laptop Asus Zenbook", 302, 18500000, 5,
                   "Asus", "Dai Loan", ncc2,
                   12, 65.0, "2024-i7", "Xam");

    // Xuat thong tin
    cout << "========== DANH SACH ==========\n\n";
    tp1.xuatThongTin(); cout << "\n";
    tp2.xuatThongTin(); cout << "\n";
    dt1.xuatThongTin(); cout << "\n";
    dt2.xuatThongTin(); cout << "\n";

    // capNhatGia / capNhatSoLuong (phuong thuc 3,4 cua SanPham)
    cout << "========== CAP NHAT ==========\n";
    tp1.capNhatGia(38000);
    tp1.capNhatSoLuong(120);
    cout << "[SanPham] Gia moi Sua TH   : " << tp1.getGia()      << " VND\n";
    cout << "[SanPham] SL moi Sua TH    : " << tp1.getSoLuong()  << "\n";

    // get/set han su dung (chuc nang 3,4 cua HangThucPham)
    cout << "\n[HangThucPham] Han cu Oreo : " << tp2.getHanSuDung() << "\n";
    tp2.setHanSuDung("2026-01-01");
    cout << "[HangThucPham] Han moi Oreo: " << tp2.getHanSuDung() << "\n";

    // conHan (chuc nang 5 cua HangThucPham)
    string homNay = "2025-07-01";
    cout << "\n[HangThucPham] Sua TH con han? " << (tp1.conHan(homNay) ? "Co" : "Khong") << "\n";
    cout << "[HangThucPham] Oreo   con han? " << (tp2.conHan(homNay) ? "Co" : "Khong") << "\n";

    // get/set bao hanh, getCongSuat (chuc nang 3,4,5 cua HangDienTu)
    cout << "\n[HangDienTu] Bao hanh S24 cu : " << dt1.getBaoHanh()  << " thang\n";
    dt1.setBaoHanh(36);
    cout << "[HangDienTu] Bao hanh S24 moi: " << dt1.getBaoHanh()  << " thang\n";
    cout << "[HangDienTu] Cong suat S24   : " << dt1.getCongSuat() << " W\n";

    // Friend functions
    soSanhHanSD(tp1, tp2);
    soSanhBaoHanh(dt1, dt2);

    return 0;
}
