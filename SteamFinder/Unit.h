//---------------------------------------------------------------------------

#ifndef UnitH
#define UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TMain_Form : public TForm
{
__published:	// IDE-managed Components
        TButton *Start_Game;
        TImage *Main_Image;
        TImage *Item1;
        TImage *Item2;
        TImage *Item3;
        TImage *Item4;
        TImage *Item5;
        TImageList *Set_of_Items;
        TLabel *Label1;
        void __fastcall Start_GameClick(TObject *Sender);
        void __fastcall Item1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMain_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
