
#Requires AutoHotkey v2.0
#SingleInstance Force

CoordMode "Mouse", "Client"

; N.I.N.A. manual control coordinates
northX := 2060, northY := 1193
southX := 2060, southY := 1509
westX  := 1901, westY  := 1351
eastX  := 2217, eastY  := 1351

stopX  := 2060, stopY  := 1351
homeX  := 2788, homeY  := 1351
parkX  := 2788, parkY  := 1508

slewEnabled := true
slewHeld := ""
slewWindow := 0

; F8 toggles keyboard controls
F8:: {
    global slewEnabled

    ReleaseSlew()
    slewEnabled := !slewEnabled

    ToolTip "N.I.N.A. Keyboard Control: "
        . (slewEnabled ? "ON" : "OFF")

    SetTimer () => ToolTip(), -1200
}

; Keyboard controls only active in N.I.N.A.
#HotIf WinActive("ahk_exe NINA.exe") && slewEnabled

; Directional slewing
*Up::StartSlew("Up", northX, northY)
*Down::StartSlew("Down", southX, southY)
*Left::StartSlew("Left", westX, westY)
*Right::StartSlew("Right", eastX, eastY)

; Mount commands
^h::ClickControl(homeX, homeY)
^p::ClickControl(parkX, parkY)
Space::ClickControl(stopX, stopY)

#HotIf

; Key releases remain active even if focus changes
~*Up up::StopSlew("Up")
~*Down up::StopSlew("Down")
~*Left up::StopSlew("Left")
~*Right up::StopSlew("Right")

; Monitor focus while slewing
SetTimer CheckSlewFocus, 50

StartSlew(key, x, y) {
    global slewHeld, slewWindow

    if (slewHeld != "")
        return

    slewHeld := key
    slewWindow := WinGetID("A")

    MouseMove x, y, 0
    SendEvent "{LButton down}"
}

StopSlew(key) {
    global slewHeld

    if (slewHeld = key)
        ReleaseSlew()
}

ReleaseSlew() {
    global slewHeld, slewWindow

    if (slewHeld = "")
        return

    SendEvent "{LButton up}"
    slewHeld := ""
    slewWindow := 0
}

ClickControl(x, y) {
    ReleaseSlew()

    ; Save current cursor position
    MouseGetPos &oldX, &oldY

    MouseMove x, y, 0
    Click

    ; Restore cursor position
    MouseMove oldX, oldY, 0
}

CheckSlewFocus() {
    global slewHeld, slewWindow

    if (slewHeld != ""
        && !WinActive("ahk_id " slewWindow))
        ReleaseSlew()
}
