
#include "my_var.h"

void setup() {

 Serial.begin(9600);
 Serial.setTimeout(0);
 Serial.println(FPSTR(DebugON));
   /*/ Настраиваем 8-й пин как выход */
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  /*  Настраиваем пин светодиода как выход */
  pinMode(ledPin, OUTPUT);
  pinMode(pin10,  INPUT);
}

void loop() {
// ---- прием команд -----
static bool CmdNotCopmlit =true;

{
        //CmdStr = Serial.readString();
if(CmdNotCopmlit)

  while((lenStrRead = Serial.available())>0){
    char ReadChar = Serial.read();
     if (ReadChar!= 10 ){
      if (ReadChar!= 13){
             CmdStr += ReadChar; 
      }else{
        CmdNotCopmlit = false;
        break;
      }

     }

  }else //обработка
  {
           if (CmdStr.equals(HBT)){
            Serial.write('~');
        }else{
          
        
          int PosSeparate  = CmdStr.indexOf(SEMICOLON);
          if (PosSeparate != -1){
              CmdParam = CmdStr.substring(PosSeparate+1,CmdStr.length()).toInt();
              CmdStr=CmdStr.substring(0,PosSeparate);
            } else{
              CmdParam =0;
              int LastChar =CmdStr.length() - 1;
              if (CmdStr.charAt(LastChar)==10){//очистка на всякий сл
                  CmdStr=CmdStr.substring(0,LastChar);
                }
              }//if (PosSeparate != -1)
          OldlenStrRead = 0;
            CmdResult =  "Not Command";
            
          if  (CmdStr.equals(cmdDnOn)){ 
              CmdResult =  CmdResultOK;
              // Устанавливаем высокий уровень на 8-й пин
              digitalWrite(pin8, HIGH);
            
              // Включаем встроенный светодиод
              digitalWrite(ledPin, HIGH);          
          }//if  (CmdStr.equals(cmdDnOn))
          
          else if  (CmdStr.equals(cmdDnOff)){ 
              CmdResult =  CmdResultOK;
              // Устанавливаем низкий уровень на 8-й пин
              digitalWrite(pin8, LOW);
            
              // Выключаем встроенный светодиод
              digitalWrite(ledPin, LOW);
          }//if (CmdStr.equals(cmdDnOff)) 
          else if  (CmdStr.equals(cmdUpOn)){ 
              CmdResult =  CmdResultOK;
              // Устанавливаем высокий уровень на 8-й пин
              digitalWrite(pin9, HIGH);
            
              // Включаем встроенный светодиод
              digitalWrite(ledPin, HIGH);          
          }//if  (CmdStr.equals(cmdUpOn))
          
          else if  (CmdStr.equals(cmdUpOff)){ 
              CmdResult =  CmdResultOK;
              // Устанавливаем низкий уровень на 8-й пин
              digitalWrite(pin9, LOW);
            
              // Выключаем встроенный светодиод
              digitalWrite(ledPin, LOW);
          }//if (CmdStr.equals(cmdUpOff))  
          else  if  (CmdStr.equals(SetALLOWANCE)){ 
              ALLOWANCE = CmdParam;
              CmdResult =  CmdResultOK;

          }//if (CmdStr.equals(SetALLOWANCE)) 
          else  if  (CmdStr.equals(SetPause)){
              PauseMove = CmdParam;
              CmdResult = CmdResultOK;
          }// else  if  (CmdStr.equals(SetPause)) 
          else  if  (CmdStr.equals(cmdStart)){
              Start = true;
              CurCountStep = ALLOWANCE;
              CmdResult = CmdResultOK;
          }//else  if  (CmdStr.equals(Start))
                    
              Serial.print(CmdStr);
              Serial.print(":");
              Serial.print(CmdParam,DEC);  
              Serial.println(CmdResult);
        }//if (CmdStr.equals(HBT)) else 
        CmdStr = ""; //обнулить если обработка закончена
        CmdNotCopmlit = true;
  }//if(CmdNotComplit) else


        
      


}// end ---прием команд  -----  
  CurTime = micros(); // Сохраняем время окончания цикла
  if ((DurationMove = CurTime - EarlyTimeMove)>PauseMove)
  { 
    if (Start){
      if (CurCountStep>0) {
        CurCountStep--;
        OutDn = !OutDn;
        digitalWrite(pin8, OutDn);
        //  встроенный светодиод
        digitalWrite(ledPin, OutDn);        
        Serial.print(" left  - ");
        Serial.println(CurCountStep,DEC);

      }
      else if (CurCountStep<0){
        CurCountStep++;
        OutUp = !OutUp;
        digitalWrite(pin9, OutUp);
        //  встроенный светодиод
        digitalWrite(ledPin, OutUp);
        Serial.print(" left  - ");
        Serial.println(CurCountStep,DEC);        
      }
      else{
        Start=false;
      }

    }  
    {// печать продолжительности цикла
    // Выводим результат в последовательный монитор
    Serial.print("CyD: ");
    Serial.print(DurationMove);
    Serial.print(" -- ");
    Serial.print(PauseMove);   
    Serial.println(" ms");
    EarlyTimeMove =  CurTime;
    }
  }//if ((DurationMove = CurTime - EarlyTimeMove)>PauseMove)

  if ((DurationdigitalRead = CurTime - EarlyTimeRead)>PausedigitalRead){
      EarlyTimeRead =  CurTime;

  }
}
