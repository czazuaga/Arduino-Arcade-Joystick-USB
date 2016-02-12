
//This code only will work with ARDUINO LEONARDO

//we will send keyboard messages to the PC  (each key has a ASCII code)
//You can find the ascii table to customize the keyboard messages sent by each button

void setup() {
  
Keyboard.begin();
 
//Joystick and button connections
pinMode(2, INPUT_PULLUP); //Joystick Left Switch  
pinMode(3, INPUT_PULLUP); //Joystick Right Switch 
pinMode(4, INPUT_PULLUP); //Joystick Up Switch 
pinMode(5, INPUT_PULLUP); //Joystick Down Switch 
//Poner Botones Aqui
pinMode(6, INPUT_PULLUP); //Joystick Button 1 
pinMode(7, INPUT_PULLUP); //Joystick Button 2 
pinMode(8, INPUT_PULLUP); //Joystick Button 3 
pinMode(9, INPUT_PULLUP); //Joystick Button 4 
pinMode(10, INPUT_PULLUP); //Joystick Button 5 
pinMode(11, INPUT_PULLUP); //Joystick Button 6 
pinMode(12, INPUT_PULLUP); //Joystick Button 7 (Service 1)
pinMode(13, INPUT_PULLUP); //Joystick Button 8 (Service 2)


}
 
 void loop() {

//I preferred not to do this with a for loop, becouse that is more understandable for other users
  
// Check the switches:
int buttonState2 = digitalRead(2);
int buttonState3 = digitalRead(3);
int buttonState4 = digitalRead(4);
int buttonState5 = digitalRead(5);


//Check Buttons

 int buttonState6 = digitalRead(6);
int buttonState7 = digitalRead(7);
int buttonState8 = digitalRead(8);
int buttonState9 = digitalRead(9);
int buttonState10 = digitalRead(10);
 int buttonState11 = digitalRead(11);
int buttonState12 = digitalRead(12);
int buttonState13 = digitalRead(13);

//Directions checkers
// Joystick Left = a Key
if (buttonState2 == LOW) {
Keyboard.press(97);
}
else {
Keyboard.release(97);
}
 
// Joystick Right = d Key
if (buttonState3 == LOW) {
Keyboard.press(100);
}
else{
Keyboard.release(100);
}
 
// Joystick Up = w key
if(buttonState4 == LOW) {
Keyboard.press(119);
}
else{
Keyboard.release(119);
}

// Joystick Down = s Key
if(buttonState5 == LOW) {
Keyboard.press(115);
}
else{
Keyboard.release(115);
}

//Button checkers
//1
if(buttonState6 == LOW) {
Keyboard.press(101);
}
else{
Keyboard.release(101);
}

//2
if(buttonState7 == LOW) {
Keyboard.press(114);
}
else{
Keyboard.release(114);
}

//3
if(buttonState8 == LOW) {
Keyboard.press(116);
}
else{
Keyboard.release(116);
}

//4
if(buttonState9 == LOW) {
Keyboard.press(121);
}
else{
Keyboard.release(121);
}

//5
if(buttonState10 == LOW) {
Keyboard.press(117);
}
else{
Keyboard.release(117);
}

//6
if(buttonState11 == LOW) {
Keyboard.press(105);
}
else{
Keyboard.release(105);
}

//7 (Service1)
if(buttonState12 == LOW) {
Keyboard.press(111);
}
else{
Keyboard.release(111);
}

//8 (Service2)
if(buttonState13 == LOW) {
Keyboard.press(112);
}
else{
Keyboard.release(112);
}


}
