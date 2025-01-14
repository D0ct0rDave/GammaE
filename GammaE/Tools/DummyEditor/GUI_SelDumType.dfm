object GUI_SelDType: TGUI_SelDType
  Left = 319
  Top = 253
  BorderStyle = bsToolWindow
  Caption = 'Select dummy model:'
  ClientHeight = 256
  ClientWidth = 292
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 95
    Height = 13
    Caption = 'Enter dummy model:'
  end
  object SpeedButton1: TSpeedButton
    Left = 244
    Top = 36
    Width = 23
    Height = 22
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      0400000000000001000000000000000000001000000010000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00303333333333
      333337F3333333333333303333333333333337F33FFFFF3FF3FF303300000300
      300337FF77777F77377330000BBB0333333337777F337F33333330330BB00333
      333337F373F773333333303330033333333337F3377333333333303333333333
      333337F33FFFFF3FF3FF303300000300300337FF77777F77377330000BBB0333
      333337777F337F33333330330BB00333333337F373F773333333303330033333
      333337F3377333333333303333333333333337FFFF3FF3FFF333000003003000
      333377777F77377733330BBB0333333333337F337F33333333330BB003333333
      333373F773333333333330033333333333333773333333333333}
    NumGlyphs = 2
    OnClick = SpeedButton1Click
  end
  object Label2: TLabel
    Left = 225
    Top = 88
    Width = 48
    Height = 13
    Caption = 'Probability'
  end
  object lb_DProb: TLabel
    Left = 248
    Top = 188
    Width = 12
    Height = 13
    Caption = '----'
  end
  object Label4: TLabel
    Left = 176
    Top = 88
    Width = 25
    Height = 13
    Caption = 'scale'
  end
  object lb_DScale: TLabel
    Left = 184
    Top = 188
    Width = 12
    Height = 13
    Caption = '----'
  end
  object Label6: TLabel
    Left = 16
    Top = 88
    Width = 78
    Height = 13
    Caption = 'Select algorithm:'
  end
  object Label3: TLabel
    Left = 112
    Top = 88
    Width = 42
    Height = 13
    Caption = 'iterations'
  end
  object lb_DIters: TLabel
    Left = 124
    Top = 188
    Width = 12
    Height = 13
    Caption = '----'
  end
  object ed_DummyModel: TEdit
    Left = 24
    Top = 36
    Width = 209
    Height = 21
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 44
    Top = 216
    Width = 100
    Height = 25
    TabOrder = 1
    Kind = bkOK
  end
  object BitBtn2: TBitBtn
    Left = 144
    Top = 216
    Width = 100
    Height = 25
    TabOrder = 2
    Kind = bkCancel
  end
  object tb_DProb: TTrackBar
    Left = 236
    Top = 104
    Width = 37
    Height = 81
    Max = 100
    Orientation = trVertical
    Frequency = 10
    Position = 1
    SelEnd = 0
    SelStart = 0
    TabOrder = 3
    ThumbLength = 16
    TickMarks = tmBoth
    TickStyle = tsAuto
    OnChange = tb_DProbChange
  end
  object tb_DScale: TTrackBar
    Left = 172
    Top = 104
    Width = 37
    Height = 81
    Max = 4
    Orientation = trVertical
    Frequency = 1
    Position = 1
    SelEnd = 0
    SelStart = 0
    TabOrder = 4
    ThumbLength = 16
    TickMarks = tmBoth
    TickStyle = tsAuto
    OnChange = tb_DScaleChange
  end
  object lb_DAlg: TListBox
    Left = 16
    Top = 108
    Width = 81
    Height = 85
    ItemHeight = 13
    Items.Strings = (
      'Random'
      'Perlin')
    TabOrder = 5
  end
  object tb_DIters: TTrackBar
    Left = 112
    Top = 104
    Width = 37
    Height = 81
    Max = 5000
    Min = 1
    Orientation = trVertical
    Frequency = 250
    Position = 1
    SelEnd = 0
    SelStart = 0
    TabOrder = 6
    ThumbLength = 16
    TickMarks = tmBoth
    TickStyle = tsAuto
    OnChange = tb_DItersChange
  end
  object dlg_SelDModel: TOpenDialog
    DefaultExt = 'gem'
    Filter = 
      'GammaE Model files (*.gem)|*.gem|3DStudio files (*.3ds)|*.3ds|Al' +
      'l the files (*.*)|*.*'
    InitialDir = '.'
    Title = 'Select dummy model from file:'
    Left = 260
  end
end
