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
//---------------------------------------------------------------------------
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Start_GameClick(TObject *Sender)
{
 ofstream out_f;
 ifstream in_f;
 in_f.open("1.txt");
 int Item1_x, Item1_y,
     Item2_x, Item2_y,
     Item3_x, Item3_y,
     Item4_x, Item4_y,
     Item5_x, Item5_y,
     Pict_1, Pict_2, Pict_3, Pict_4, Pict_5;
 string Find;
 //Выгрузка координат из файла
 in_f>>Item1_x>> Item1_y>>
        Item2_x>> Item2_y>>
        Item3_x>> Item3_y>>
        Item4_x>> Item4_y>>
        Item5_x>> Item5_y>>
        Pict_1>> Pict_2>> Pict_3>> Pict_4>> Pict_5
        >>Find;
 //Присваивание координат картинкам
 Item1->Left = Item1_x; Item1->Top = Item1_y;
 Item2->Left = Item2_x; Item2->Top = Item2_y;
 Item3->Left = Item3_x; Item3->Top = Item3_y;
 Item4->Left = Item4_x; Item4->Top = Item4_y;
 Item5->Left = Item5_x; Item5->Top = Item5_y;

 //Присваивание изображений картинкам
 Set_of_Items->GetBitmap(Pict_1,Item1->Picture->Bitmap);
 Set_of_Items->GetBitmap(Pict_2,Item2->Picture->Bitmap);
 Set_of_Items->GetBitmap(Pict_3,Item3->Picture->Bitmap);
 Set_of_Items->GetBitmap(Pict_4,Item4->Picture->Bitmap);
 Set_of_Items->GetBitmap(Pict_5,Item5->Picture->Bitmap);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Item1Click(TObject *Sender)
{
 ShowMessage("Вы нашли то, что искали!");
}
//---------------------------------------------------------------------------

