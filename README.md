# ClipboardLib
Clipboard.SetText in VBA/VBS (x86 and x64)

VBS:
```vb
Set Clipboard = CreateObject("ClipboardLib.Clipboard")
Clipboard.SetText "123あり有り☑"
```

Excel VBA Macro:
```vb
Public Sub CopyText(Text As String)
    Dim Clipboard
    Set Clipboard = CreateObject("ClipboardLib.Clipboard")
    Clipboard.SetText Text
End Sub
```

Excel VBA Macro:
```vb
Public Sub PasteTextHere()
    Dim Clipboard
    Set Clipboard = CreateObject("ClipboardLib.Clipboard")
    ActiveCell.Value = Clipboard.GetText
End Sub
```
