//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <conio.h>
#include <iostream.h>
#include <fstream.h>
#include <cstring>
#include <stdio.h>
#include "Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain_Form *Main_Form;
//Here you can declare custom functions (global)
int counter=0;
//---------------------------------------------------------------------------
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
        : TForm(Owner)
{
 //here shove the code that runs before the program starts
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Start_GameClick(TObject *Sender)
{
 Start_Game->Visible = false;
 Start_Game->Caption ="Next level";
 Randomize();
 ofstream out_f;
 ifstream in_f,in_Lor_Text;
 int Item1_x, Item1_y,
     Item2_x, Item2_y,
     Item3_x, Item3_y,
     Item4_x, Item4_y,
     Item5_x, Item5_y,
     Timer;
 string Pict_1, Pict_2, Pict_3, Pict_4, Pict_5,Main_Picture,Texts,Lor;
 char File_path[16];

 //The task of random coordinates
 /*Item1_x=random(900); Item1_y=random(600);
 Item2_x=random(900); Item2_y=random(600);
 Item3_x=random(900); Item3_y=random(600);
 Item4_x=random(900); Item4_y=random(600);
 Item5_x=random(900); Item5_y=random(600);
 Pict_1=0; Pict_2=1; Pict_3=2; Pict_4=3; Pict_5=4;
 out_f.open("1.txt");

 //Uploading coordinates to a file
 out_f<<Item1_x<<" "<< Item1_y<<" "<<
        Item2_x<<" "<< Item2_y<<" "<<
        Item3_x<<" "<< Item3_y<<" "<<
        Item4_x<<" "<< Item4_y<<" "<<
        Item5_x<<" "<< Item5_y<<" "<<
        Pict_1<<" "<< Pict_2<<" "<< Pict_3<<" "<< Pict_4<<" "<< Pict_5;
 out_f.close();      */
 counter++;
 sprintf(File_path,"%s%d%s",".\\levels\\",counter,".txt");
 in_f.open(File_path);
 if(!in_f)
 {
  ShowMessage("There are no more levels\nEnter your name for the leaderboard and click End game");
  Main_Lor_Text->Caption = "Enter your name";
  Personal_Name->Visible = true;
 }
 else
 {
  //Add a job with a tag when finding an item
  //change the name of a file with a level to +1 to open the next level

  /*if (in_f.open(".\\levels\\1.txt").isOpen())
  ShowMessage("Everything is bad, nothing has opened!"); */

  //Loading coordinates from a file
  in_f>>Item1_x>> Item1_y>>
         Item2_x>> Item2_y>>
         Item3_x>> Item3_y>>
         Item4_x>> Item4_y>>
         Item5_x>> Item5_y>>
         Timer>>
         Pict_1>> Pict_2>> Pict_3>> Pict_4>> Pict_5>>Main_Picture>>Texts;

  //The assignment of coordinates to the pictures
  Item1->Left = Item1_x; Item1->Top = Item1_y;
  Item2->Left = Item2_x; Item2->Top = Item2_y;
  Item3->Left = Item3_x; Item3->Top = Item3_y;
  Item4->Left = Item4_x; Item4->Top = Item4_y;
  Item5->Left = Item5_x; Item5->Top = Item5_y;

  Timer_Sizer->Caption = Timer;
  Timer_of_time->Enabled = true;

  //Assigning images to images
  Item1->Picture->LoadFromFile(Pict_1.c_str());
  Item2->Picture->LoadFromFile(Pict_2.c_str());
  Item3->Picture->LoadFromFile(Pict_3.c_str());
  Item4->Picture->LoadFromFile(Pict_4.c_str());
  Item5->Picture->LoadFromFile(Pict_5.c_str());
  Main_Image->Picture->LoadFromFile(Main_Picture.c_str());
  in_f.close();

  //Attempts to insert text from a file into a label
  in_Lor_Text.open(Texts.c_str());
  if(!in_Lor_Text)
  {
   Main_Lor_Text->Caption = "There might have been a wall of text with lore if they hadn't forgotten to write it";
  }
  else
  {
   getline(in_Lor_Text,Lor,';');
   Main_Lor_Text->Caption = Lor.c_str();
  }
  in_Lor_Text.close();
 }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::NoTrue()
{
 ShowMessage("This is not what you are looking for!");
 Score_Sizer->Caption = IntToStr(StrToInt(Score_Sizer->Caption)-1);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Item1Click(TObject *Sender)
{
 ShowMessage("You found what you were looking for!");
 Start_Game->Visible = true;
 Timer_of_time->Enabled = false;
 Score_Sizer->Caption = IntToStr(StrToInt(Score_Sizer->Caption)+1);
 Main_Lor_Text->Caption = " ";
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


void __fastcall TMain_Form::End_GameClick(TObject *Sender)
{
 if(Personal_Name->Visible == true)
  {
   ofstream outf_Leaderboard;
   outf_Leaderboard.open("Leaderboard.txt",ios_base::app);
   outf_Leaderboard<<"Name: "<<Personal_Name->Text.c_str()<<"  Score: "<<StrToInt(Score_Sizer->Caption)<<"\n";
   outf_Leaderboard.close();

   ifstream inf_Leaderboard;
   string Liders;
   inf_Leaderboard.open("Leaderboard.txt");
   getline(inf_Leaderboard,Liders,';');
   ShowMessage (Liders.c_str());
   inf_Leaderboard.close();
  }
 exit(0);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Timer_of_timeTimer(TObject *Sender)
{
 Timer_Sizer->Caption = IntToStr(StrToInt(Timer_Sizer->Caption)-1);
 if(StrToInt(Timer_Sizer->Caption)<11)
 {
  Timer->Font->Color = clRed;
  Timer_Sizer->Font->Color = clRed;
 }
 else
 {
  Timer->Font->Color = clBlack;
  Timer_Sizer->Font->Color = clBlack;
 }
 
 if(StrToInt(Timer_Sizer->Caption) <1)
 {
  Timer_of_time->Enabled=false;
  ShowMessage("You did not succeed,\n click on the Next Level to continue...");
  Start_Game->Visible = true;
  Score_Sizer->Caption = IntToStr(StrToInt(Score_Sizer->Caption)-1);
 }

}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::PauseClick(TObject *Sender)
{
 if(Timer_of_time->Enabled == true) Timer_of_time->Enabled=false;
 else Timer_of_time->Enabled=true;
}
//---------------------------------------------------------------------------

