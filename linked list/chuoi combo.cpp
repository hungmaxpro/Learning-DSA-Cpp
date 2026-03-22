/*
1. C?u trúc Node (Skill Slot)
M?i Node s? luu:
string skillName: Tên k? nang (ví d?: "Q - Phi Th?ch", "W - Ð?a Ch?n").
int manaCost: Nang lu?ng tiêu t?n.
Node* next: Chiêu th?c ti?p theo trong chu?i combo.
2.
Hàm addToCombo (Thêm chiêu): Cho phép ngu?i choi n?p thêm m?t chiêu vào cu?i chu?i Combo hi?n t?i (Dùng push_back).
Hàm showCombo (Duy?t chu?i): In ra màn hình chu?i combo r?c r? d?ng:
[Q] -> [E] -> [R] -> H?T NANG LU?NG!
Hàm totalMana (Tính toán): Duy?t qua danh sách và tính t?ng lu?ng Mana c?n thi?t d? thi tri?n toàn b? chu?i Combo này.
Logic: N?u t?ng Mana vu?t quá 500, hãy in ra c?nh báo "H?t Mana r?i d?i ca!".
Hàm removeLastSkill (Xóa chiêu): Ngu?i choi b?m nh?m, hãy xóa k? nang cu?i cùng v?a thêm vào (Ðây là bài test tu duy xóa Node ? cu?i - khó hon xóa ? d?u m?t chút).
Hàm executeCombo (Gi?i phóng): "X?" h?t b? nh? sau khi dùng xong Combo (D?n d?p RAM b?ng delete).
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
    else{
        while (p->next != NULL){
            p=p->next;
        }
        delete p;
    } 
}

void excuteCombo(node &a){
    node p=a;
    if(a==NULL){
        cout<<"khong co combo";
        return;
    }
    while (a!= NULL){
        while (p!=NULL){
        p=p->next; 
        } 
        delete p;
        p=a;}

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
    switch (i)
    {
    case 1:
        cout << "Nhap ten skill: ";
        cin.ignore(); 
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
