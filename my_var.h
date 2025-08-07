#ifndef my_var
#define my_var
unsigned long DnOnTime;
unsigned long endTime, startTime;

unsigned long loopDuration, PauseMove = 500000;

#define FPSTR(pstr) (const __FlashStringHelper *)(pstr)

// Устанавливаем номера пинов
const int pin8 = 8;
const int pin9 = 9;
const int ledPin = 13; // Встроенный светодиод на плате

#define SEMICOLON ':'
#define cmdDnOn "DnOn"
#define cmdDnOff "DnOff"
#define cmdUpOn "UpOn"
#define cmdUpOff "UpOff"
#define SetALLOWANCE "allowance"
#define SetPause "SetPause"
#define cmdStart "Start"

#define CmdResultOK " OK"

String CmdStr;
const PROGMEM char DebugON[] = "DebugON";
long CmdParam;
String CmdResult;
int lenStrRead, OldlenStrRead;
int ALLOWANCE, CurCountStep;
bool Start, OutUp, OutDn;

#endif
