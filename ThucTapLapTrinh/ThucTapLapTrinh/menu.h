#pragma once
#include "struct.h"
void Main_ThongKe(HoSo *Array, char* FileName, int n);
void MainSapxep();
void Menu();
int TongSoSV();
void input(char *NameFile, HoSo *Array, int  *j);
void  ThemMoi_Hs(HoSo *Array);
void OutPut(HoSo *Array,int n);
void Ong_DaiDuoi(int ChieuDai_duoi_min);
void Ong_ChieuRong(int Ong_RongMin);
void Khung_IN();
void Save();
void Menu_batPhim(int Toado);
void MainTimKiem(HoSo  *Array, int n);
void checkExit(int *Err1);
void XoaCheckExit();
void InFile(HoSo *Array);
void Khung_PrintfTK_class();
void END();
//////////
void ThongKe_MaLop(HoSo *Array);
void DeleteSV(HoSo *Array, int ToaDo, int *n);
void ChuyenContro(HoSo *Array, int *ToaDo, int Trang);
void Khung_BieuDo(HoSo *Array,int n);