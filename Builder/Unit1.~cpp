//---------------------------------------------------------------------------

#include <vcl.h>
#include <conio.h>
#include <stdlib.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
 int Random;
 randomize();
 Random=random(25)+ 10;
 LabelHead->Caption="ƒостигните максимально быстро числа: ";
 LabelHead->Caption=LabelHead->Caption+Random;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButtonAcceptedClick(TObject *Sender)
{
 int tmp,number;
 if(RadioScale->ItemIndex==5)tmp=10;
    else tmp=RadioScale->ItemIndex+1;
 MemoOutput->Lines->Add(TextInput->Text*(tmp));
}
//---------------------------------------------------------------------------





