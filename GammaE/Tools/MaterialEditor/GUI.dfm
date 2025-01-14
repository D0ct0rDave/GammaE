object Form1: TForm1
  Left = 341
  Top = 143
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 355
  ClientWidth = 456
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 224
    Top = 20
    Width = 42
    Height = 13
    Caption = 'Shaders:'
  end
  object Label2: TLabel
    Left = 224
    Top = 184
    Width = 82
    Height = 13
    Caption = 'Shader definition:'
  end
  object GroupBox1: TGroupBox
    Left = 12
    Top = 16
    Width = 201
    Height = 329
    Caption = 'Properties:'
    TabOrder = 0
    object RadioGroup1: TRadioGroup
      Left = 12
      Top = 20
      Width = 173
      Height = 117
      Caption = 'Type'
      ItemIndex = 0
      Items.Strings = (
        'Normal'
        'Particle System'
        'Flare'
        'Volumetric Light'
        'Volumetric Fog')
      TabOrder = 0
    end
  end
  object Memo1: TMemo
    Left = 224
    Top = 200
    Width = 221
    Height = 145
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object ListBox1: TListBox
    Left = 224
    Top = 36
    Width = 221
    Height = 141
    ItemHeight = 13
    TabOrder = 2
  end
  object MainMenu1: TMainMenu
    Left = 428
    object Files1: TMenuItem
      Caption = '&Files'
      object LoadMaterials1: TMenuItem
        Caption = 'Load Materials'
      end
      object SaveMaterials1: TMenuItem
        Caption = 'Save Materials'
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Addshaders1: TMenuItem
        Caption = 'Add shaders'
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Quit1: TMenuItem
        Caption = 'Quit'
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object About1: TMenuItem
        Caption = 'About'
      end
    end
  end
end
