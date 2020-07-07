//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <conio.h>
#include <iostream.h>
#include <fstream.h>
#include "Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain_Form *Main_Form;
//Тут объявлять пользовательские функции (глобальные)
//---------------------------------------------------------------------------
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
        : TForm(Owner)
{
 //сюда пихать код, который выполниться до запуска программы
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Start_GameClick(TObject *Sender)
{
 Start_Game->Visible = false;
 Start_Game->Caption ="Следующий уровень";
 Randomize();
 ofstream out_f;
 ifstream in_f;
 int Item1_x, Item1_y,
     Item2_x, Item2_y,
     Item3_x, Item3_y,
     Item4_x, Item4_y,
     Item5_x, Item5_y;
 string Pict_1, Pict_2, Pict_3, Pict_4, Pict_5;
 //Папка с уровнем и путями к картинкам в файле и уровни
 //Задание случайных координат
 /*Item1_x=random(900); Item1_y=random(600);
 Item2_x=random(900); Item2_y=random(600);
 Item3_x=random(900); Item3_y=random(600);
 Item4_x=random(900); Item4_y=random(600);
 Item5_x=random(900); Item5_y=random(600);
 Pict_1=0; Pict_2=1; Pict_3=2; Pict_4=3; Pict_5=4;
 out_f.open("1.txt");

 //Загрузка координат в файл
 out_f<<Item1_x<<" "<< Item1_y<<" "<<
        Item2_x<<" "<< Item2_y<<" "<<
        Item3_x<<" "<< Item3_y<<" "<<
        Item4_x<<" "<< Item4_y<<" "<<
        Item5_x<<" "<< Item5_y<<" "<<
        Pict_1<<" "<< Pict_2<<" "<< Pict_3<<" "<< Pict_4<<" "<< Pict_5;

 out_f.close();      */
 in_f.open("1.txt");

 //Выгрузка координат из файла
 in_f>>Item1_x>> Item1_y>>
        Item2_x>> Item2_y>>
        Item3_x>> Item3_y>>
        Item4_x>> Item4_y>>
        Item5_x>> Item5_y>>
        Pict_1>> Pict_2>> Pict_3>> Pict_4>> Pict_5;

 //Присваивание координат картинкам
 Item1->Left = Item1_x; Item1->Top = Item1_y;
 Item2->Left = Item2_x; Item2->Top = Item2_y;
 Item3->Left = Item3_x; Item3->Top = Item3_y;
 Item4->Left = Item4_x; Item4->Top = Item4_y;
 Item5->Left = Item5_x; Item5->Top = Item5_y;

 Label1->Caption = Pict_1.c_str();
 //Присваивание изображений картинкам
/* Item1->Picture->LoadFromFile(Pict_1.c_str());
 Item2->Picture->LoadFromFile(Pict_2.c_str());
 Item3->Picture->LoadFromFile(Pict_3.c_str());
 Item4->Picture->LoadFromFile(Pict_4.c_str());
 Item5->Picture->LoadFromFile(Pict_5.c_str());   */
 in_f.close();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::NoTrue()
{
 ShowMessage("Это не то, что вы ищете!");
 Score_Sizer->Caption = IntToStr(StrToInt(Score_Sizer->Caption)-1);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Item1Click(TObject *Sender)
{
 ShowMessage("Вы нашли то, что искали!");
 Start_Game->Visible = true;
 Score_Sizer->Caption = IntToStr(StrToInt(Score_Sizer->Caption)+1);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Item2Click(TObject *Sender)
{
 NoTrue();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Item3Click(TObject *Sender)
{
 NoTrue();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Item4Click(TObject *Sender)
{
 NoTrue();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Item5Click(TObject *Sender)
{
 NoTrue();
}
//---------------------------------------------------------------------------


