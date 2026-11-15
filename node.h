#pragma once
#include <iostream>
#include <string>

using namespace std;

// Cấu trúc lưu trữ thông tin 1 thành viên trong gia phả
struct Node {
    int id;
    string hoTen;
    int namSinh;
    int namMat;
    string voChong;
    
    // Các con trỏ liên kết
    Node* cha;   // Trỏ lên node của cha 
    Node* me;    // Trỏ lên node của mẹ  
    Node* next;  // Trỏ sang người tiếp theo
};
// Cẩm Đào
Node* taoNode(int id, string hoTen, int namSinh, int namMat, string voChong);

Node* timCuTo();

void timAnhChiEm(Node* node);

void timConCai(Node* node);

void hienThiDanhSach();

Node* timNodeTheoID(int id);

// Giao dien Console Menu
void menuConsole();
 //
