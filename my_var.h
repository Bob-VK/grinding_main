#ifndef my_var
#define my_var
unsigned long DnOnTime;
unsigned long EarlyTimeMove, CurTime;
unsigned int  CountStableRead = 0;
#define       CountStableReadOk 20
unsigned long DurationMove, PauseMove               = 500000;

#define FPSTR(pstr) (const __FlashStringHelper *)(pstr)

// Устанавливаем номера пинов
const int pin8 = 8;
const int pin9 = 9;
const int pin10 = 10;
const int ledPin = 13; // Встроенный светодиод на плате

#define SEMICOLON ':'
#define cmdDnOn "DnOn"
#define cmdDnOff "DnOff"
#define cmdUpOn "UpOn"
#define cmdUpOff "UpOff"
#define SetALLOWANCE "allowance"
#define SetPause "SetPause"
#define cmdStart "Start"
// #define HBT "HBT"
#define HBT "~"


#define CmdResultOK " OK"

String CmdStr;
const PROGMEM char DebugON[] = "DebugON";
long CmdParam;
String CmdResult;
int lenStrRead, OldlenStrRead;
int ALLOWANCE, CurCountStep;
bool Start, OutUp, OutDn;

#endif
