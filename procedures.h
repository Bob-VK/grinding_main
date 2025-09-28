#ifndef procedures
#define procedures
#include <TimerOne.h>
inline void StartMoveTimer1(int ALLOWANCE);
inline void StartMove (int ALLOWANCE){
/*               Start = true;
              CurCountStep = ALLOWANCE;  */
                StartMoveTimer1(ALLOWANCE);
}
inline void StepUpISR();
inline void StepDnISR();
inline void StepUp();
inline void StepDn();
inline void StartMoveTimer1(int ALLOWANCE){
    Timer1.initialize(400);
    CurCountStep = ALLOWANCE; 
    if (CurCountStep>0){
      Timer1.attachInterrupt(StepUpISR);
    }else if (CurCountStep<0){
      Timer1.attachInterrupt(StepDnISR);
    }
}
inline void StepUpISR(){
          if (CurCountStep>0) {
        StepUp();
      }else{
        // отключаем прерывания по таймеру 1
        Timer1.detachInterrupt();
      }
}
inline void StepDnISR(){
if (CurCountStep<0){
        StepDn();
      }else{
        // отключаем прерывания по таймеру 1
        Timer1.detachInterrupt();
      }
}
bool NeedPrintSteps;
inline void StepUp(){
        CurCountStep--;
        OutDn = !OutDn;
        digitalWrite(pin8, OutDn);
        //  встроенный светодиод
        digitalWrite(ledPin, OutDn);
        NeedPrintSteps = true;   
}

inline void StepDn(){
        CurCountStep++;
        OutUp = !OutUp;
        digitalWrite(pin9, OutUp);
        //  встроенный светодиод
        digitalWrite(ledPin, OutUp);
        NeedPrintSteps = true; 
}

#endif