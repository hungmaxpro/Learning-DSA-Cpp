/*🎮 Đề bài: "Hệ thống Quản lý Chiêu thức (Combo System)"
Hãy tưởng tượng ông đang xây dựng một vị tướng có khả năng tung chuỗi Combo liên hoàn. Mỗi kỹ năng (Skill) là một Node trong danh sách liên kết.

1. Cấu trúc Node (Skill Slot)
Mỗi Node sẽ lưu:
string skillName: Tên kỹ năng (ví dụ: "Q - Phi Thạch", "W - Địa Chấn").
int manaCost: Năng lượng tiêu tốn.
Node* next: Chiêu thức tiếp theo trong chuỗi combo.
2. Thử thách Code "Vui" (5 Hàm thực chiến):
Hàm addToCombo (Thêm chiêu): Cho phép người chơi nạp thêm một chiêu vào cuối chuỗi Combo hiện tại (Dùng push_back).
Hàm showCombo (Duyệt chuỗi): In ra màn hình chuỗi combo rực rỡ dạng:
[Q] -> [E] -> [R] -> HẾT NĂNG LƯỢNG!
Hàm totalMana (Tính toán): Duyệt qua danh sách và tính tổng lượng Mana cần thiết để thi triển toàn bộ chuỗi Combo này.
Logic: Nếu tổng Mana vượt quá 500, hãy in ra cảnh báo "Hụt Mana rồi đại ca!".
Hàm removeLastSkill (Xóa chiêu): Người chơi bấm nhầm, hãy xóa kỹ năng cuối cùng vừa thêm vào (Đây là bài test tư duy xóa Node ở cuối - khó hơn xóa ở đầu một chút).
Hàm executeCombo (Giải phóng): "Xả" hết bộ nhớ sau khi dùng xong Combo (Dọn dẹp RAM bằng delete).
*/

#include <iostream>
using namespace std;
struct Skill{
    string skillName;
    int manaCost;
}
struct Node{
    Skill data;
    Node* next;
}
type struct Node* node;
node Newnode(string b, int c){
    node newnode = new Node();
    newnode->data.skillName=b;
    newnode->data.manaCost=c;
    newnode->next=NULL;
    return *newnode;
}

void addToCombo(node &a, string b, int c){
    node p=a;
    while(p!=NULL){
        p=p->next;
    }
    Newnode(b,c);
    p->next=Newnode;
}



void removeLastSkill(node &a){
    node truoc=NULL, sau=a;
    if (a->next==NULL){
        cout<<"Combo chi co 1 phan tu khong the xoa."
    }
    while (sau != NULL){
        truoc->next=sau;
        sau=sau->next;
    }
    truoc->next=NULL;
}

int main(){

	return 0;
}
