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
 //out_f<<"123 "<<12;
 int Item1_x, Item1_y,
     Item2_x, Item2_y,
     Item3_x, Item3_y,
     Item4_x, Item4_y,
     Item5_x, Item5_y;
 in_f>>Item1_x>> Item1_y>>
        Item2_x>> Item2_y>>
        Item3_x>> Item3_y>>
        Item4_x>> Item4_y>>
        Item5_x>> Item5_y;
 Item1->Left = Item1_x; Item1->Top = Item1_y;
 Item2->Left = Item2_x; Item2->Top = Item2_y;
 Item3->Left = Item3_x; Item3->Top = Item3_y;
 Item4->Left = Item4_x; Item4->Top = Item4_y;
 Item5->Left = Item5_x; Item5->Top = Item5_y;

 //Item1->Picture =  ;
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Item1Click(TObject *Sender)
{
 ShowMessage("Вы нашли то, что искали!!");
}
//---------------------------------------------------------------------------

