                
//This code only will work with ARDUINO LEONARDO

// Good info about the keyboard codes: https://www.arduino.cc/en/Reference/KeyboardModifiers 

//Keep a copy of the last communicated state, to reduce overhead only call the keyboard functions if there's a change.
byte switches0_7 = 0;
byte switches8_13 = 0;

//1 means the key press has been sent, 0 means the key release has been sent
#define SWITCH_STATE_COMMUNICATED_0 (switches0_7 & 0x01)
#define SWITCH_STATE_COMMUNICATED_1 (switches0_7 & 0x02)
#define SWITCH_STATE_COMMUNICATED_2 (switches0_7 & 0x04)
#define SWITCH_STATE_COMMUNICATED_3 (switches0_7 & 0x08)
#define SWITCH_STATE_COMMUNICATED_4 (switches0_7 & 0x10)
#define SWITCH_STATE_COMMUNICATED_5 (switches0_7 & 0x20)
#define SWITCH_STATE_COMMUNICATED_6 (switches0_7 & 0x40)
#define SWITCH_STATE_COMMUNICATED_7 (switches0_7 & 0x80)
#define SWITCH_STATE_COMMUNICATED_8 (switches8_13 & 0x01)
#define SWITCH_STATE_COMMUNICATED_9 (switches8_13 & 0x02)
#define SWITCH_STATE_COMMUNICATED_10 (switches8_13 & 0x04)
#define SWITCH_STATE_COMMUNICATED_11 (switches8_13 & 0x08)
#define SWITCH_STATE_COMMUNICATED_12 (switches8_13 & 0x10)
#define SWITCH_STATE_COMMUNICATED_13 (switches8_13 & 0x20)


#define SET_SWITCH_STATE_COMMUNICATED_0(c) (c ? (switches0_7 |= 0x01) : (switches0_7 &= ~0x01))
#define SET_SWITCH_STATE_COMMUNICATED_1(c) (c ? (switches0_7 |= 0x02) : (switches0_7 &= ~0x02))
#define SET_SWITCH_STATE_COMMUNICATED_2(c) (c ? (switches0_7 |= 0x04) : (switches0_7 &= ~0x04))
#define SET_SWITCH_STATE_COMMUNICATED_3(c) (c ? (switches0_7 |= 0x08) : (switches0_7 &= ~0x08))
#define SET_SWITCH_STATE_COMMUNICATED_4(c) (c ? (switches0_7 |= 0x10) : (switches0_7 &= ~0x10))
#define SET_SWITCH_STATE_COMMUNICATED_5(c) (c ? (switches0_7 |= 0x20) : (switches0_7 &= ~0x20))
#define SET_SWITCH_STATE_COMMUNICATED_6(c) (c ? (switches0_7 |= 0x40) : (switches0_7 &= ~0x40))
#define SET_SWITCH_STATE_COMMUNICATED_7(c) (c ? (switches0_7 |= 0x80) : (switches0_7 &= ~0x80))

#define SET_SWITCH_STATE_COMMUNICATED_8(c) (c ? (switches8_13 |= 0x01) : (switches8_13 &= ~0x01))
#define SET_SWITCH_STATE_COMMUNICATED_9(c) (c ? (switches8_13 |= 0x02) : (switches8_13 &= ~0x02))
#define SET_SWITCH_STATE_COMMUNICATED_10(c) (c ? (switches8_13 |= 0x04) : (switches8_13 &= ~0x04))
#define SET_SWITCH_STATE_COMMUNICATED_11(c) (c ? (switches8_13 |= 0x08) : (switches8_13 &= ~0x08))
#define SET_SWITCH_STATE_COMMUNICATED_12(c) (c ? (switches8_13 |= 0x10) : (switches8_13 &= ~0x10))
#define SET_SWITCH_STATE_COMMUNICATED_13(c) (c ? (switches8_13 |= 0x20) : (switches8_13 &= ~0x20))


//debounce by insisting the state is consistent this many reads in a row
#define MAX_DEBOUNCE_COUNT 12

byte switch0_count = 0;
byte switch1_count = 0;
byte switch2_count = 0;
byte switch3_count = 0;
byte switch4_count = 0;
byte switch5_count = 0;
byte switch6_count = 0;
byte switch7_count = 0;
byte switch8_count = 0;
byte switch9_count = 0;
byte switch10_count = 0;
byte switch11_count = 0;
byte switch12_count = 0;
byte switch13_count = 0;

#if 1
//normal key config
#define UP_KEYBOARD_CODE            218   /* UP_ARROW */
#define DOWN_KEYBOARD_CODE          217   /* DOWN_ARROW*/
#define LEFT_KEYBOARD_CODE          216   /* RIGHT_ARROW */
#define RIGHT_KEYBOARD_CODE         215   /* LEFT_ARROW */
#define TAB_KEYBOARD_CODE           179   /* TAB */
#define ESC_KEYBOARD_CODE           177   /* ESC */
#define BUTTON1_KEYBOARD_CODE       128   /* LEFT_CTRL */
#define BUTTON2_KEYBOARD_CODE       130   /* LEFT_ALT */
#define BUTTON3_KEYBOARD_CODE       32    /* SPACE */
#define BUTTON4_KEYBOARD_CODE       129   /* LEFT_SHIFT */
#define BUTTON5_KEYBOARD_CODE       122   /* z */
#define BUTTON6_KEYBOARD_CODE       120   /* x */ 
#define START1_KEYBOARD_CODE        49    /* 1 */
#define COIN1_KEYBOARD_CODE         53    /* 5 */
#else 
//test key configs for easy testing
#define UP_KEYBOARD_CODE            85    /* U */
#define DOWN_KEYBOARD_CODE          68    /* D*/
#define LEFT_KEYBOARD_CODE          82    /* R */
#define RIGHT_KEYBOARD_CODE         76    /* L */
#define TAB_KEYBOARD_CODE           84    /* T */
#define ESC_KEYBOARD_CODE           69    /* E */
#define BUTTON1_KEYBOARD_CODE       97    /* a */
#define BUTTON2_KEYBOARD_CODE       98    /* b */
#define BUTTON3_KEYBOARD_CODE       99    /* c */
#define BUTTON4_KEYBOARD_CODE       100   /* d */
#define BUTTON5_KEYBOARD_CODE       101   /* e */
#define BUTTON6_KEYBOARD_CODE       102   /* f */ 
#define START1_KEYBOARD_CODE        49    /* 1 */
#define COIN1_KEYBOARD_CODE         53    /* 5 */
#endif


void setup() {

  Keyboard.begin();

  pinMode(13, INPUT_PULLUP); //5
  pinMode(12, INPUT_PULLUP); //1

  //Joystick and button connections
  pinMode(11, INPUT_PULLUP); //Joystick R Switch
  pinMode(10, INPUT_PULLUP); //Joystick L Switch
  pinMode(9, INPUT_PULLUP); //Joystick U Switch
  pinMode(8, INPUT_PULLUP); //Joystick D Switch
  pinMode(7, INPUT_PULLUP); //Joystick Button 1   L Ctl
  pinMode(6, INPUT_PULLUP); //Joystick Button 2   L Alt
  pinMode(5, INPUT_PULLUP); //Joystick Button 3   space
  pinMode(4, INPUT_PULLUP); //Joystick Button 4   L shift
  pinMode(3, INPUT_PULLUP); //Joystick Button 5  Z
  pinMode(2, INPUT_PULLUP); //Joystick Button 6  X
  pinMode(1, INPUT_PULLUP); //Joystick Button 7  Tab
  pinMode(0, INPUT_PULLUP); //Joystick Button 8  Esc
}


void loop() {

  // Check the switches:
  //int buttonState0 = digitalRead(0);
  byte inputB = PINB;
  byte inputC = PINC;
  byte inputD = PIND;
  byte inputE = PINE;
  
  int buttonState0 = inputD & 0x04;
  int buttonState1 = inputD & 0x08;
  int buttonState2 = inputD & 0x02;
  int buttonState3 = inputD & 0x01;
  int buttonState4 = inputD & 0x10;
  int buttonState5 = inputC & 0x40;
  int buttonState6 = inputD & 0x80;
  int buttonState7 = inputE & 0x40;;
  int buttonState8 = inputB & 0x10;
  int buttonState9 = inputB & 0x20;
  int buttonState10 = inputB & 0x40;
  int buttonState11 = inputB & 0x80;
  int buttonState12 = inputD & 0x40;
  int buttonState13 = inputC & 0x80;

  // ESC
  if (!buttonState0) {
    if (switch0_count < MAX_DEBOUNCE_COUNT)  switch0_count++;
    
    if ((switch0_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_0)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_0(1);
      Keyboard.press(ESC_KEYBOARD_CODE);
    }
  } else {
    if (switch0_count > 0)  switch0_count--;
    
    if ((switch0_count==0) && (SWITCH_STATE_COMMUNICATED_0)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_0(0);      
      Keyboard.release(ESC_KEYBOARD_CODE);
    }
  }


  // TAB
  if (!buttonState1) {
    if (switch1_count < MAX_DEBOUNCE_COUNT)  switch1_count++;
    
    if ((switch1_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_1)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_1(1);
      Keyboard.press(TAB_KEYBOARD_CODE);
    }
  } else {
    if (switch1_count > 0)  switch1_count--;
        
    if ((switch1_count==0) && (SWITCH_STATE_COMMUNICATED_1)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_1(0);      
      Keyboard.release(TAB_KEYBOARD_CODE);
    }
  }

  //Button 6 (typically x)
  if (!buttonState2) {
    if (switch2_count < MAX_DEBOUNCE_COUNT)  switch2_count++;
    
    if ((switch2_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_2)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_2(1);
      Keyboard.press(BUTTON6_KEYBOARD_CODE);
    }
  } else {
    if (switch2_count > 0)  switch2_count--;
        
    if ((switch2_count==0) && (SWITCH_STATE_COMMUNICATED_2)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_2(0);      
      Keyboard.release(BUTTON6_KEYBOARD_CODE);
    }
  }


  //Button 5 (typically z)
  if (!buttonState3) {
    if (switch3_count < MAX_DEBOUNCE_COUNT)  switch3_count++;
    
    if ((switch3_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_3)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_3(1);
      Keyboard.press(BUTTON5_KEYBOARD_CODE);
    }
  } else {
    if (switch3_count > 0)  switch3_count--;
        
    if ((switch3_count==0) && (SWITCH_STATE_COMMUNICATED_3)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_3(0);      
      Keyboard.release(BUTTON5_KEYBOARD_CODE);
    }
  }

  
  //BUTTON 4 (typically lshift)
  if (!buttonState4) {
    if (switch4_count < MAX_DEBOUNCE_COUNT)  switch4_count++;
        
    if ((switch4_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_4)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_4(1);
      Keyboard.press(BUTTON4_KEYBOARD_CODE);
    }
  } else {
    if (switch4_count > 0)  switch4_count--;
        
    if ((switch4_count==0) && (SWITCH_STATE_COMMUNICATED_4)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_4(0);      
      Keyboard.release(BUTTON4_KEYBOARD_CODE);
    }
  }


  //Button 3 (typically space)
  if (!buttonState5) {
    if (switch5_count < MAX_DEBOUNCE_COUNT)  switch5_count++;
    
    if ((switch5_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_5)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_5(1);
      Keyboard.press(BUTTON3_KEYBOARD_CODE);
    }
  } else {
    if (switch5_count > 0)  switch5_count--;    
    
    if ((switch5_count==0) && (SWITCH_STATE_COMMUNICATED_5)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_5(0);      
      Keyboard.release(BUTTON3_KEYBOARD_CODE);
    }
  }



  //Button 2 (typically L Alt)
  if (!buttonState6) {
    if (switch6_count < MAX_DEBOUNCE_COUNT)  switch6_count++;
        
    if ((switch6_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_6)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_6(1);
      Keyboard.press(BUTTON2_KEYBOARD_CODE);
    }
  } else {
    if (switch6_count > 0)  switch6_count--;
        
    if (((switch6_count==0) && SWITCH_STATE_COMMUNICATED_6)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_6(0);      
      Keyboard.release(BUTTON2_KEYBOARD_CODE);
    }
  }


  // Button 1 (typically L CTL)
  if (!buttonState7) {
    if (switch7_count < MAX_DEBOUNCE_COUNT)  switch7_count++;
        
    if ((switch7_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_7)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_7(1);
      Keyboard.press(BUTTON1_KEYBOARD_CODE);
    }
  } else {
    if (switch7_count > 0)  switch7_count--;
        
    if ((switch7_count==0) && (SWITCH_STATE_COMMUNICATED_7)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_7(0);      
      Keyboard.release(BUTTON1_KEYBOARD_CODE);
    }
  }


  // Joystick Down
  if (!buttonState8) {
    if (switch8_count < MAX_DEBOUNCE_COUNT)  switch8_count++;
        
    if ((switch8_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_8)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_8(1);
      Keyboard.press(DOWN_KEYBOARD_CODE);
    }
  } else {
    if (switch8_count > 0)  switch8_count--;    
    
    if ((switch8_count==0) && (SWITCH_STATE_COMMUNICATED_8)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_8(0);      
      Keyboard.release(DOWN_KEYBOARD_CODE);
    }
  }


  // Joystick Up
  if (!buttonState9) {
    if (switch9_count < MAX_DEBOUNCE_COUNT)  switch9_count++;
        
    if ((switch9_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_9)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_9(1);
      Keyboard.press(UP_KEYBOARD_CODE);
    }
  } else {
    if (switch9_count > 0)  switch9_count--;
        
    if ((switch9_count==0) && (SWITCH_STATE_COMMUNICATED_9)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_9(0);      
      Keyboard.release(UP_KEYBOARD_CODE);
    }
  }


  // Joystick Left
  if (!buttonState10) {
    if (switch10_count < MAX_DEBOUNCE_COUNT)  switch10_count++;
        
    if ((switch10_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_10)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_10(1);
      Keyboard.press(LEFT_KEYBOARD_CODE);
    }
  } else {
    if (switch10_count > 0)  switch10_count--;    
    
    if ((switch10_count==0) && (SWITCH_STATE_COMMUNICATED_10)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_10(0);      
      Keyboard.release(LEFT_KEYBOARD_CODE);
    }
  }


  // Joystick Right
  if (!buttonState11) {
    if (switch11_count < MAX_DEBOUNCE_COUNT)  switch11_count++;
        
    if ((switch11_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_11)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_11(1);
      Keyboard.press(RIGHT_KEYBOARD_CODE);
    }
  } else {
    if (switch11_count > 0)  switch11_count--;
        
    if ((switch11_count==0) && (SWITCH_STATE_COMMUNICATED_11)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_11(0);      
      Keyboard.release(RIGHT_KEYBOARD_CODE);
    }
  }


  //Player 1 Start (typically 1)
  if (!buttonState12) {
    if (switch12_count < MAX_DEBOUNCE_COUNT)  switch12_count++;
        
    if ((switch12_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_12)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_12(1);
      Keyboard.press(START1_KEYBOARD_CODE);
    }
  } else {
    if (switch12_count > 0)  switch12_count--;    
    
    if ((switch12_count==0) && (SWITCH_STATE_COMMUNICATED_12)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_12(0);      
      Keyboard.release(START1_KEYBOARD_CODE);
    }
  }


  // //Player 1 Coin (typically 5)
  if (!buttonState13){
    if (switch13_count < MAX_DEBOUNCE_COUNT)  switch13_count++;
        
    if ((switch13_count==MAX_DEBOUNCE_COUNT) && (!SWITCH_STATE_COMMUNICATED_13)){
      //if the key press hasn't been sent yet, send it 
      SET_SWITCH_STATE_COMMUNICATED_13(1);
      Keyboard.press(COIN1_KEYBOARD_CODE);
    }
  } else {
    if (switch13_count > 0)  switch13_count--;
        
    if ((switch13_count==0) && (SWITCH_STATE_COMMUNICATED_13)) { 
      //if the key release hasn't been sent yet, send it
      SET_SWITCH_STATE_COMMUNICATED_13(0);      
      Keyboard.release(COIN1_KEYBOARD_CODE);
    }
  }


}

 
  
  

