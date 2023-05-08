#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <iomanip>
#define MAX 500 
using namespace std;

struct NgayThang{
	int Ngay;
	int Thang;
	int Nam;
};

struct sinhvien{
	string HoTen;
	NgayThang NS;
	int GT;
	float Diem;
	sinhvien *Next;
};
sinhvien *Head=NULL;
sinhvien *Last=NULL;

sinhvien * TaoPhanTu(int i)
{
	sinhvien * p = new sinhvien;
	cout<<"Nhap thong tin cho sinh vien thu "<<i+1<<":\n";
	fflush(stdin);
	cout<<"Ho ten sinh vien: ";
	getline(cin,p->HoTen);
	cout<<"Ngay sinh (dd mm yyyy):";
	cin>>p->NS.Ngay>>p->NS.Thang>>p->NS.Nam;
	cout<<"Gioi tinh (nhap 1: nam, 0: nu): ";
	cin>>p->GT;
	cout<<"Diem: ";cin>>p->Diem;
	cin.ignore();
	p->Next=NULL;
	return p;
}

sinhvien * taoptu()
{
	sinhvien * p = new sinhvien;
	cout<<"Nhap thong tin cho sinh vien :\n";
	fflush(stdin);
	cout<<"Ho ten sinh vien: ";
	getline(cin,p->HoTen);
	cout<<"Ngay sinh (dd mm yyyy):";
	cin>>p->NS.Ngay>>p->NS.Thang>>p->NS.Nam;
	cout<<"Gioi tinh (nhap 1: nam, 0: nu): ";
	cin>>p->GT;
	cout<<"Diem: ";cin>>p->Diem;
	cin.ignore();
	p->Next=NULL;
	return p;
}

void ThemDau(sinhvien *&Head, sinhvien *&Last, sinhvien *p)
{
	if (Head==NULL)
	{
		Head=p;
		Last=p;
	}
	else{
		p->Next = Head;
		Head=p;
	}
}
void ThemCuoi(sinhvien *&Head, sinhvien *&Last, sinhvien *p)
{
	if (Head==NULL)
	{
		Head=p;
		Last=p;
	}
	else{
		Last->Next=p;
		Last=p;
	}
}
void Themgiua(sinhvien *&Head, sinhvien *&Last, sinhvien *p, int vt)
{
	if(Head == NULL){
		Head = p;
		return;
	}
	sinhvien *chay = Head;
	int dem = 0;
	while(chay != NULL){
		dem++;
		chay = chay->Next;	
	}
	if(dem >= vt){
		if(vt == 1){
			ThemDau(Head, Last, p);
			return;
		}
		sinhvien *tam = Head;
		for(int i = 2; i < vt; i++){
			tam = tam->Next;
		}
		p->Next = tam->Next;
		tam->Next = p;
		return;
	}ThemCuoi(Head, Last, p);
	
}

void xoadau(sinhvien *&Head){
//	if(Head == NULL){
//	
//		return;
//	}
	sinhvien *tam = Head;
	Head = Head->Next;
	delete tam;
	//return;
}

void xoacuoi(sinhvien *&Head, sinhvien *&Last){
	if(Head == NULL){
		Last == NULL;
		return;
	}
	sinhvien *tam = Head;
	if(tam->Next == NULL){
		Head = NULL;
		delete tam;
	}
	while(tam->Next->Next != NULL){
		tam = tam->Next;
	}
	sinhvien *ok = tam->Next;
	tam->Next = NULL;
	Last = tam;
	delete ok;
}

void xoavt(sinhvien *&Head, int vt){
	if(Head == NULL){
		return;
	}
	
	
	sinhvien *chay = Head;
	int dem = 0;
	while(chay != NULL){
		dem++;
		chay = chay->Next;
	}
	if(vt <= dem){
		sinhvien *ok = Head;
		if(vt == 1){
			Head = Head->Next;
			delete ok;
			return;
		} else{
			
	//	sinhvien *tam = Head;
		for(int i = 2; i < vt; i++){
			ok = ok->Next;
		}
		sinhvien *moi = ok->Next;
		ok->Next = moi->Next;
		delete moi;
	//	return;
		}
	}
	
}
ofstream file;


void xuat(){
	file.open("D://output.txt");
			file << setw(10) << left << "STT" << setw(20) << left << "Ho va Ten";
			file << setw(10) << right << " ";
			file << setfill('0');
			file << setw(5) << right << "Ngay/Thang/Nam sinh";
			file << setfill(' ');
			file << setw(20) << right << "Gioi tinh" << setw(20) << right << "Diem" << endl;
}

void XuatPhanTu(sinhvien *p, int i)
{
	string gt = (p->GT==1)?"Nam":"Nu";
		file << setw(10) << left << i+1 << setw(20) << left << p->HoTen;
		file << setw(10) << right << " ";
		file << setfill('0');
		file << setw(2) << right << p->NS.Ngay << "/" << p->NS.Thang << "/" << p->NS.Nam;
		file << setfill(' ');
		file << setw(25) << right << gt << setw(23) << right << p->Diem << endl;
}

void DuyetDSLK(sinhvien *Head)
{
	sinhvien* p = Head;
	//p=Head;
	int i=0;
	while(p!=NULL)
	{
		XuatPhanTu(p,i);
		p=p->Next;
		i++;
	}
	
}
void timmax(sinhvien* head){
	int max=-1;
	sinhvien* t;
	while(head!=NULL){
		if(max< head->Diem) {
			max=head->Diem;
			t=head;
		}
		head=head->Next;
	}
	file<<"SINH VIEN CO DIEM LON NHAT: "<<endl;
	XuatPhanTu(t,0);
	//return 1;
}
void timmin(sinhvien* head){
	int min=head->Diem;
	sinhvien* t;
	while(head!=NULL){
		if(min> head->Diem) {
			min=head->Diem;
			t=head;
		}
		head=head->Next;
	}
	
	file<<"SINH VIEN CO DIEM NHO NHAT: "<<endl;
	XuatPhanTu(t,0);

}
int main(){
	int n, so;
	sinhvien *p=NULL;
	cout<<"Nhap so sinh vien: "	;
	cin>>n;
	int max=0, min=0;
	
//	KhoiTao(Head, Last);
	for (int i = 0; i < n; i++){
		p = TaoPhanTu(i);
		ThemCuoi(Head, Last, p);
	}
	cout << "-----------------------------QUAN LI SINH VIEN BANG DSLK DON-----------------------------\n";
	cout << "1.----------------------------------XUAT DU LIEU-----------------------------------------\n";
	cout << "2.-------------------------------CHEN VAO 1 VI TRI---------------------------------------\n";
	cout << "3.---------------------------------XOA 1 VI TRI------------------------------------------\n";
	cout << "4.-------------------------Tim SINH VIEN CO DIEM LON NHAT--------------------------------\n";
	cout << "5.-------------------------Tim SINH VIEN CO DIEM NHO NHAT--------------------------------\n";
	while(1){
		do{
			cout << "Moi ban nhap tuy chon: ";
			cin >> so;
			if(so > 5){
				cout << "Tuy chon sai, vui long nhap lai!!!!";
			}
		}while(so > 5);
		switch(so){
			case 1:
				cout<< "---------------------DANH SACH SINH VIEN DA NHAP------------------" << endl;
				xuat();
				DuyetDSLK(Head);
				file.close();
			break;
			case 2:{
			
				cout << "-------------------------------CHEN VAO 1 VI TRI---------------------------------------" << endl;
				int vt;
				cout << "Nhap vi tri muon chen: ";
				cin >> vt;
				sinhvien *p = taoptu();
				Themgiua(Head, Last, p, vt);
				xuat();
				DuyetDSLK(Head);
				file.close();
			break;}
			case 3:
				cout << "----------------------------------------XOA 1 VI TRI------------------------------------"<< endl;
				int x;
				cout << "Nhap vi tri muon xoa: ";
				cin >> x;
				xoavt(Head, x);
			//	xoadau(Head);
				xuat();
				DuyetDSLK(Head);
//				cout<<Head->HoTen<<endl;
				file.close();
			break;
			case 4:
				cout<<"------------------------tim diem lon nhat----------------------------------------"<<endl;
				xuat();
				DuyetDSLK(Head);
				if(min==1) timmin(Head);
				timmax(Head);
				max=1;
				file.close();
				break;
			case 5:
				cout<<"------------------------tim diem nho nhat----------------------------------------"<<endl;
				xuat();
				DuyetDSLK(Head);
				if(max==1) timmax(Head);
				timmin(Head);
				min=1;
				file.close();
				break;
		}
	
	
		
	
	}
	return 0;
}