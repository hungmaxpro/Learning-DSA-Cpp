/*
1. Cấu trúc Node (Skill Slot)
Mỗi Node sẽ lưu:
string skillName: Tên kỹ năng (ví dụ: "Q - Phi Thạch", "W - Địa Chấn").
int manaCost: Năng lượng tiêu tốn.
Node* next: Chiêu thức tiếp theo trong chuỗi combo.
2.
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
};
struct Node{
    Skill data;
    Node* next;
};
typedef struct Node* node;
node Newnode(string b, int c){
    node newnode = new Node();
    newnode->data.skillName=b;
    newnode->data.manaCost=c;
    newnode->next=NULL;
    return newnode;
}

void addToCombo(node &a, string b, int c){
    node p=a;
    if(a==NULL){
        a=Newnode(b,c);
    }
    else{
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=Newnode(b,c);
    }
}

void showcombo(node a){
    while (a!= NULL){
        cout<<"\n"<<a->data.skillName;
        cout<<"-"<<a->data.manaCost;
        a=a->next;
    }
    
        cout<<"\n-------Ket thuc combo------";

}

int totalmana(node a){
    int tongmana=0;
     while (a!= NULL){
        tongmana+=a->data.manaCost;
        a=a->next;
    }
    return tongmana;
}


void removeLastSkill(node &a){
    node p=a;
    if (a==NULL){
        cout<<"khong co skill nao de xoa";
    }
    else if(a->next==NULL){
        delete a;
        a=NULL;
    }
    else{
        while (p->next->next != NULL){
            p=p->next;
        }
        delete p->next;
        p->next=NULL;
    } 
}

void excuteCombo(node &a){
    node p;
    node tmp;
    if(a==NULL){
        cout<<"khong co combo";
        return;
    }
    else if(a->next==NULL){
        delete a;
        a=NULL;
        return;
    }
    else{
    while (a!= NULL){
        tmp=a->next;
        delete a;
        a=tmp;
    }
}
}
int main(){
    int i=0;
    node head=NULL;
    string name;
    int mana;
    while(i!=6){
        cout<<"---MENU---";
        cout<<"\n1. addcombo";
        cout<<"\n2. showcombo";
        cout<<"\n3. total mana";
        cout<<"\n4. removelastskill";
        cout<<"\n5. excutecombo";
        cout<<"\n6. END";
        cout<<"\n chon:";
        cin>>i;
        cin.ignore();
    switch (i)
    {
    case 1:
        cout << "Nhap ten skill: ";

        getline(cin, name);
        cout << "Nhap mana tieu ton: ";
        cin >> mana;
        addToCombo(head, name, mana);
        break;
    case 2:
        showcombo(head);
        break;
    case 3:
        mana = totalmana(head);
        cout << "Tong mana: " << mana << endl;
        if (mana > 500) cout << "(!) Canh bao: Khong du mana!" << endl;
        break;
    case 4:
        removeLastSkill(head);
        cout << "Da xoa chieu cuoi." << endl;
        break;
    case 5:
        excuteCombo(head);
        break;
    case 6:
        excuteCombo(head); // Giai phong truoc khi thoat
        cout << "Tam biet!" << endl;
        break;
    default:
            cout << "Lua chon khong hop le!" << endl;
        }
    }
    
    
	return 0;
}
