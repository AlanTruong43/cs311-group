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
    string tenSanPham;
    int    maSanPham;
    double gia;
    int    soLuong;
    string thuongHieu;
    string nuocSanXuat;
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
    void setTenSanPham(string ten)   { tenSanPham = ten; }
    void setMaSanPham(int ma)        { maSanPham = ma; }
    void setGia(double g)            { if (g >= 0) gia = g; }
    void setSoLuong(int sl)          { if (sl >= 0) soLuong = sl; }
    void setThuongHieu(string t)     { thuongHieu = t; }
    void setNuocSanXuat(string n)    { nuocSanXuat = n; }
    void setNhaCungCap(NhaCungCap n) { nhaCungCap = n; }

    // ---------- Methods ----------
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

    virtual void xuatThongTin() const {
        cout << "  Ma SP       : " << maSanPham   << "\n";
        cout << "  Ten SP      : " << tenSanPham  << "\n";
        cout << "  Gia         : " << gia          << " VND\n";
        cout << "  So luong    : " << soLuong      << "\n";
        cout << "  Thuong hieu : " << thuongHieu   << "\n";
        cout << "  Nuoc SX     : " << nuocSanXuat  << "\n";
        cout << "  Nha CC      : " << nhaCungCap.ten << "\n";
    }

    void capNhatGia(double giaMoi)   { if (giaMoi >= 0) gia = giaMoi; }
    void capNhatSoLuong(int slMoi)   { if (slMoi >= 0) soLuong = slMoi; }
    double tinhTongTien() const      { return gia * soLuong; }
};

// ===================== DERIVED CLASS: HANGTHUCPHAM =====================
class HangThucPham : public SanPham {
private:
    string hanSuDung;
    string loaiThucPham;    // tuoi song / dong lanh / kho
    double nhietDoLuuTru;   // do C

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

    // ---------- Getters ----------
    string getHanSuDung()      const { return hanSuDung; }
    string getLoaiThucPham()   const { return loaiThucPham; }
    double getNhietDoLuuTru()  const { return nhietDoLuuTru; }

    // ---------- Setters ----------
    void setHanSuDung(string h)     { hanSuDung = h; }
    void setLoaiThucPham(string l)  { loaiThucPham = l; }
    void setNhietDoLuuTru(double n) { nhietDoLuuTru = n; }

    // ---------- Override Methods ----------
    void nhapThongTin() override {
        SanPham::nhapThongTin();
        cout << "  Han su dung (YYYY-MM-DD): "; getline(cin, hanSuDung);
        cout << "  Loai thuc pham          : "; getline(cin, loaiThucPham);
        cout << "  Nhiet do luu tru (do C) : "; cin >> nhietDoLuuTru;
    }

    void xuatThongTin() const override {
        cout << "--- [HANG THUC PHAM] ---\n";
        SanPham::xuatThongTin();
        cout << "  Han su dung : " << hanSuDung      << "\n";
        cout << "  Loai        : " << loaiThucPham    << "\n";
        cout << "  Nhiet do    : " << nhietDoLuuTru   << " do C\n";
    }

    bool conHan(string ngayHienTai) const {
        return hanSuDung >= ngayHienTai;
    }
};

// ===================== DERIVED CLASS: HANGDIENTU =====================
class HangDienTu : public SanPham {
private:
    int    baoHanh;     // thang
    double congSuat;    // Watt
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

    // ---------- Getters ----------
    int    getBaoHanh()  const { return baoHanh; }
    double getCongSuat() const { return congSuat; }
    string getPhienBan() const { return phienBan; }
    string getMauSac()   const { return mauSac; }

    // ---------- Setters ----------
    void setBaoHanh(int b)      { if (b >= 0) baoHanh = b; }
    void setCongSuat(double c)  { if (c >= 0) congSuat = c; }
    void setPhienBan(string p)  { phienBan = p; }
    void setMauSac(string m)    { mauSac = m; }

    // ---------- Override Methods ----------
    void nhapThongTin() override {
        SanPham::nhapThongTin();
        cout << "  Bao hanh (thang): "; cin >> baoHanh;
        cout << "  Cong suat (W)   : "; cin >> congSuat;
        cin.ignore();
        cout << "  Phien ban       : "; getline(cin, phienBan);
        cout << "  Mau sac         : "; getline(cin, mauSac);
    }

    void xuatThongTin() const override {
        cout << "--- [HANG DIEN TU] ---\n";
        SanPham::xuatThongTin();
        cout << "  Bao hanh : " << baoHanh  << " thang\n";
        cout << "  Cong suat: " << congSuat << " W\n";
        cout << "  Phien ban: " << phienBan  << "\n";
        cout << "  Mau sac  : " << mauSac    << "\n";
    }
};

// ===================== FRIEND FUNCTIONS =====================
void soSanhHanSD(const HangThucPham& a, const HangThucPham& b) {
    // Truy cap private truc tiep nho friend
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
