#include <iostream>
#include <string>
using namespace std;

struct NgaySinh {
    int Ngay;
    int Thang;
    int Nam;
};

struct SinhVien {
    string MaSinhVien;
    string HoTen;
    NgaySinh NgaySinh;
};

struct DanhSachSinhVien {
    SinhVien A[100];
    int ts ;
};

void themSinhVien(DanhSachSinhVien &ds, const SinhVien &sv) {
    if (ds.ts >= 100) {
        cout << "Danh sach da day, khong the them sinh vien." << endl;
        return;
    }
    for (int i = ds.ts; i > 0; --i) {
        ds.A[i] = ds.A[i - 1];
    }
    ds.A[0] = sv;
    ds.ts++;
}

bool soSanhNgaySinh(const SinhVien &sv1, const SinhVien &sv2) {
    if (sv1.NgaySinh.Nam != sv2.NgaySinh.Nam)
        return sv1.NgaySinh.Nam < sv2.NgaySinh.Nam;
    if (sv1.NgaySinh.Thang != sv2.NgaySinh.Thang)
        return sv1.NgaySinh.Thang < sv2.NgaySinh.Thang;
    return sv1.NgaySinh.Ngay < sv2.NgaySinh.Ngay;
}


void sapXepDanhSach(DanhSachSinhVien &ds) {
    for (int i = 0; i < ds.ts - 1; ++i) {
        for (int j = i + 1; j < ds.ts; ++j) {
            if (!soSanhNgaySinh(ds.A[i], ds.A[j])) {
                SinhVien temp = ds.A[i];
                ds.A[i] = ds.A[j];
                ds.A[j] = temp;
            }
        }
    }
}

void suaSinhVien(DanhSachSinhVien &ds, const string &HoTen) {
    for (int i = 0; i < ds.ts; ++i) {
        if (ds.A[i].HoTen == HoTen) {
            cout << "Nhap ma sinh vien moi: ";
            cin >> ds.A[i].MaSinhVien;
            cout << "Nhap ngay sinh moi (ngay thang nam): ";
            cin >> ds.A[i].NgaySinh.Ngay >> ds.A[i].NgaySinh.Thang >> ds.A[i].NgaySinh.Nam;
            return;
        }
    }
    cout << "Khong tim thay sinh vien voi ho ten " << HoTen << endl;
}

void inDanhSach(const DanhSachSinhVien &ds) {
    for (int i = 0; i < ds.ts; ++i) {
        cout << ds.A[i].MaSinhVien << " " << ds.A[i].HoTen << " "
             << ds.A[i].NgaySinh.Ngay << " " << ds.A[i].NgaySinh.Thang << " " << ds.A[i].NgaySinh.Nam << endl;
    }
}

int main() {
    DanhSachSinhVien ds;
    int choice;
    ds.ts=0;

    while (true) {
        cout << "Nhap lua chon (1: Them,2: Sua, 3: Sap xep va In): ";
        cin >> choice;

        if (choice == 1) {
            int soSinhVien;
            cout << "Nhap so sinh vien can them: ";
            cin >> soSinhVien;

            for (int i = 0; i < soSinhVien; ++i) {
                SinhVien sv;
                cout << "Nhap ma sinh vien: ";
                cin >> sv.MaSinhVien;
                cout << "Nhap ho ten: ";
                cin.ignore();
                getline(cin, sv.HoTen);
                cout << "Nhap ngay sinh (dd mm yyyy): ";
                cin >> sv.NgaySinh.Ngay >> sv.NgaySinh.Thang >> sv.NgaySinh.Nam;

                themSinhVien(ds, sv);
            }

            cout << "Da them " << soSinhVien << " sinh vien." << endl;
        } else if(choice == 2){
    		string hoTen;
        	cin.ignore(); 
        	cout << "Nhap ho ten sinh vien can sua: ";
        	getline(cin, hoTen);
        	suaSinhVien(ds, hoTen);
        cout << "Da sua thong tin sinh vien " << hoTen << "." << endl;
		} else if (choice == 3) {
            sapXepDanhSach(ds);
            inDanhSach(ds);
           break; 
        } else {
            cout << "Lua chon khong hop le." << endl;
        }
    }

    return 0;
}
