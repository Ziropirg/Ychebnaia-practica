object MainForm: TMainForm
  Left = 206
  Top = 126
  BorderStyle = bsDialog
  Caption = 'MainForm'
  ClientHeight = 427
  ClientWidth = 912
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabelInput: TLabel
    Left = 8
    Top = 72
    Width = 35
    Height = 13
    Caption = #1063#1080#1089#1083#1086':'
  end
  object LabelHead: TLabel
    Left = 8
    Top = 16
    Width = 105
    Height = 13
    Caption = 'LabelHead'
  end
  object ButtonAccepted: TButton
    Left = 48
    Top = 88
    Width = 121
    Height = 25
    Caption = #1042#1074#1086#1076
    TabOrder = 0
    OnClick = ButtonAcceptedClick
  end
  object TextInput: TEdit
    Left = 48
    Top = 64
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object MemoOutput: TMemo
    Left = 224
    Top = 32
    Width = 185
    Height = 105
    TabOrder = 2
  end
  object RadioScale: TRadioGroup
    Left = 168
    Top = 32
    Width = 57
    Height = 105
    Caption = 'RadioScale'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Serif'
    Font.Style = []
    Items.Strings = (
      'x1'
      'x2'
      'x3'
      'x4'
      'x5'
      'x10')
    ParentFont = False
    TabOrder = 3
  end
end
