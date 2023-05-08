create database Quanliluong3
go
use quanliluong3
go
create table Donvi(
	Madonvi nvarchar(50) ,
	Tendonvi nvarchar(255),
	Diachi nvarchar(255),
	Dienthoai nvarchar(50),
	Website nvarchar(255),
	Email nvarchar(50),
	constraint PK_Donvi1 primary key (
		madonvi 
	) 
)
go
create table DanhMucBacLuong(
	BacLuong int ,
	TienLuong money
	constraint PK_Danhmucbacluong primary key(
		Bacluong
	) 
)
go
create table NhanVien(
	Manhanvien nvarchar(50) ,
	Ho nvarchar(100),
	Ten nvarchar(50),
	Gioitinh bit,
	Ngaysinh date,
	NgayVaoLamViec date,
	BacLuong int,
	MaDonVi nvarchar(50)
	constraint PK_Nhanvien primary key (
		manhanvien 
	) 
)
go

create table BangLuong(
	Mabangluong int ,
	Thang int,
	Nam int,
	NgayLapBangLuong date
	constraint PK_BangLuong primary key  (
		mabangluong 
	)
)
go
create table BangLuongNhanVien(
	MaBangluong int,
	MaNhanVien nvarchar(50) ,
	Bacluong int,
	Tienluong money,
	Tienthuong money,
	TienPhucap money,
	Tientamung money,
	ThucNhan money
	CONSTRAINT PK_BangLuongNhanVien primary key  (
		MaBangluong 
	) 
	
)
go
alter table nhanvien
add constraint fk_madonvi foreign key (madonvi) references  donvi(madonvi)

alter table nhanvien
add constraint fk_bacluong foreign key(bacluong) references danhmucbacluong(bacluong)

alter table bangluongnhanvien
add constraint fk_manhanvien foreign key(manhanvien) references nhanvien(manhanvien)

alter table bangluongnhanvien
add constraint fk_mabangluong foreign key(mabangluong) references bangluong(mabangluong)

alter table nhanvien
add danghiviec bit not null
