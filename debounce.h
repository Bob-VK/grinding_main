#ifndef debounce
#define debounce
#define EnoughRepeatNewStat  4
#include "procedures.h"

inline void Debounce(){
    unsigned long DurationdigitalRead;
    static unsigned long EarlyTimeRead = 0,PausedigitalRead = 50;
    static bool EarlyState;
     
    static int RepeatNewState = 0;
      if ((DurationdigitalRead =  CurTime - EarlyTimeRead)>PausedigitalRead){//антидребезг
      EarlyTimeRead =  CurTime;
      bool CurState;
      if ((CurState=digitalRead(pin10))!=EarlyState){
          RepeatNewState++;
          if(RepeatNewState>EnoughRepeatNewStat){
            RepeatNewState=0;
            EarlyState=CurState;//!!!
            if (!CurState){
              StartMove (ALLOWANCE);
            }
          }//if(RepeatNewState>EnoughRepeatNewStat){
      }else{//if ((bool CurState=digitalRead(pin10))!=EarlyState){
        RepeatNewState=0;
      }
      
  }//if ((DurationdigitalRead =  CurTime - EarlyTimeRead)>PausedigitalRead)
}
#endif