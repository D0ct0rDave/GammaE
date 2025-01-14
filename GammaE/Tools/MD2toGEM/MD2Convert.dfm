object Form2: TForm2
  Left = 198
  Top = 202
  Width = 520
  Height = 476
  Caption = 'Form2'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object pb_Dsp: TPaintBox
    Left = 0
    Top = 0
    Width = 512
    Height = 430
    Align = alClient
    OnMouseDown = FormMouseDown
    OnMouseMove = FormMouseMove
    OnMouseUp = FormMouseUp
    OnPaint = pb_DspPaint
  end
  object MainMenu1: TMainMenu
    Left = 4
    Top = 4
    object File1: TMenuItem
      Caption = '&File'
      object LoadMD2Player1: TMenuItem
        Caption = 'Load MD2 Player'
        ShortCut = 16460
        OnClick = LoadMD2Player1Click
      end
      object LoadMD2model1: TMenuItem
        Caption = 'Load &MD2 model'
        ShortCut = 16461
        OnClick = LoadMD2model1Click
      end
      object Loadtexture1: TMenuItem
        Caption = 'Load skin &Texture'
        ShortCut = 16468
        OnClick = Loadtexture1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object SaveGEMmodel1: TMenuItem
        Caption = '&Save GEM model'
        ShortCut = 16467
        OnClick = SaveGEMmodel1Click
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Quit1: TMenuItem
        Caption = '&Quit'
        ShortCut = 16465
      end
    end
  end
  object RTimer: TTimer
    Enabled = False
    Interval = 10
    OnTimer = pb_DspPaint
    Left = 32
    Top = 4
  end
  object dlg_Save: TSaveDialog
    DefaultExt = 'gem'
    Filter = 'GammaE Model file (*.gem)|*.gem|All the files|*.*'
    Left = 88
    Top = 4
  end
  object dlg_Load: TOpenDialog
    DefaultExt = 'gts'
    Filter = 'Quake2 MD2 model files|*.md2|All the files (*.*)|*.*'
    InitialDir = '.'
    Title = 'Load MD2 Model file:'
    Left = 60
    Top = 4
  end
  object dlg_LoadTex: TOpenDialog
    DefaultExt = 'gts'
    Filter = 
      'TGA Textures|*.tga|JPEG Textures|*.jpg|PCX Textures|*.pcx|WAL Te' +
      'xtures|*.wal|All the files (*.*)|*.*'
    InitialDir = '.'
    Title = 'Load Textures:'
    Left = 116
    Top = 4
  end
end
