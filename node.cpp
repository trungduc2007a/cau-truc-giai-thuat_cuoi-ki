#include "node.h"
#include <vector>
  

// Hàm đúc ra một Node mới
Node* taoNode(int id, string hoTen, int namSinh, int namMat, string voChong) {
    // 1. Cấp phát động một vùng nhớ mới cho Node
    Node* p = new Node;
    
    // 2. Gán dữ liệu cá nhân vào phần "ruột"
    p->id = id;
    p->hoTen = hoTen;
    p->namSinh = namSinh;
    p->namMat = namMat;
    p->voChong = voChong;
    
    // 3. Khởi tạo các con trỏ
    // Người mới sinh ra/mới nhập vào chưa nối với ai cả, nên các sợi dây phải ngắt đi (gán nullptr)
    p->cha = nullptr;
    p->me = nullptr;
    p->next = nullptr;
    // Cẳm Đào
     // Luu Node vao danh sach
    danhSachNode.push_back(p);
    //
    
    // Trả về địa chỉ của Node vừa tạo
    return p;
}
// Cẩm Đào
// 1. Tim Cu to trong gia pha
Node* timCuTo() {
    for (Node* p : danhSachNode) {
        if (p->cha == nullptr && p->me == nullptr) {
            return p;
        }
    }

    return nullptr;
}

// 2. Tim anh, chi, em
void timAnhChiEm(Node* node) {
    if (node == nullptr) return;

    cout << "\nAnh, chi, em cua " << node->hoTen << ":\n";

    bool found = false;

    for (Node* p : danhSachNode) {
        if (p != node &&
            (node->cha != nullptr || node->me != nullptr) &&
            p->cha == node->cha &&
            p->me == node->me) {

            cout << "- " << p->hoTen << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Khong co anh, chi, em.\n";
    }
}

// 3. Tim con cai
void timConCai(Node* node) {
    if (node == nullptr) return;

    cout << "\nCon cai cua " << node->hoTen << ":\n";

    bool found = false;

    for (Node* p : danhSachNode) {
        if (p->cha == node || p->me == node) {
            cout << "- " << p->hoTen << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Khong co con cai.\n";
    }
}

// 4. Hien thi danh sach thanh vien
void hienThiDanhSach() {
    cout << "\n===== DANH SACH THANH VIEN =====\n";

    for (Node* p : danhSachNode) {
        cout << "ID: " << p->id
             << " | Ho ten: " << p->hoTen << endl;
    }
}

// 5. Tim Node theo ID
Node* timNodeTheoID(int id) {
    for (Node* p : danhSachNode) {
        if (p->id == id) {
            return p;
        }
    }

    return nullptr;
}

// 6. Giao dien Console Menu
void menuConsole() {
    int chon;

    do {
        cout << "\n========== MENU GIA PHA ==========\n";
        cout << "1. Tim Cu to\n";
        cout << "2. Tim anh, chi, em\n";
        cout << "3. Tim con cai\n";
        cout << "4. Hien thi danh sach thanh vien\n";
        cout << "0. Thoat\n";
        cout << "=================================\n";
        cout << "Nhap lua chon: ";

        cin >> chon;

        switch (chon) {
            case 1: {
                Node* cuTo = timCuTo();

                if (cuTo != nullptr) {
                    cout << "\nCu to la: "
                         << cuTo->hoTen << endl;
                } else {
                    cout << "\nKhong tim thay Cu to.\n";
                }

                break;
            }

            case 2: {
                int id;

                hienThiDanhSach();

                cout << "Nhap ID thanh vien: ";
                cin >> id;

                Node* p = timNodeTheoID(id);

                if (p != nullptr) {
                    timAnhChiEm(p);
                } else {
                    cout << "Khong tim thay thanh vien.\n";
                }

                break;
            }

            case 3: {
                int id;

                hienThiDanhSach();

                cout << "Nhap ID thanh vien: ";
                cin >> id;

                Node* p = timNodeTheoID(id);

                if (p != nullptr) {
                    timConCai(p);
                } else {
                    cout << "Khong tim thay thanh vien.\n";
                }

                break;
            }

            case 4:
                hienThiDanhSach();
                break;

            case 0:
                cout << "Da thoat chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);
}
//
