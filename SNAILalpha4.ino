/*SNAIL MAZE by Keyboard_Camper
I built a dirty port of the SEGA MASTERSYSTEM BIOS EASTER EGG made from examples and comments from members at community.arduboy.com
Shouts to crait and MLXXXp without your contributions to the community I wouldnt have even got past the boot screen
Shouts to the Arduboy Team and everyone else that contributes
A BIG Thank You to Pharap for some optimization 
shouts to those who I failed to mention
And apologies for the mess in here its built from snippets and trial and error
To Do:
Figure our collision with background
Fix timer
Put everything where it really should be
sprite animation
clean up sprites
Move to Arduboy2 -- Done
Fully understand the code xD


            ymmmmmmmmmmmmmmmmmmmmmmmm-                  
            hMMMMMMMMMMMMMMMMMMMMMMMM:                  
            hMMMMMMMMMMMMMMMMMMMMMMMM:                  
      ddddddNMMMMMy------------MMMMMMmddddd/            
      MMMMMMMMMMMMo            MMMMMMMMMMMMo            
      MMMMMMMMMMMMo            MMMMMMMMMMMMo            
      MMMMMMo/////oyyyyyyyyyyyy//////mMMMMMo     .yyyyyy
      MMMMMM:     oMMMMMMMMMMMM      hMMMMMo     :MMMMMM
      MMMMMM:     oMMMMMMMMMMMM      hMMMMMo     :MMMMMM
      MMMMMM:     oMMMMMm++++++ssssssmMMMMMo     .++++++
      MMMMMM:     oMMMMMh      MMMMMMMMMMMMo            
      MMMMMM:     oMMMMMh      MMMMMMMMMMMMo            
      MMMMMMs+++++osssss+      ssssssmMMMMMh++++++++++++
      MMMMMMMMMMMMo                  hMMMMMMMMMMMMMMMMMM
     MMMMMMMMMMMMo                  hMMMMMMMMMMMMMMMMMM
      yyyyyyNMMMMMy//////////////////mMMMMMMMMMMMMMMMMMM
            hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
           hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
      ------dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdddddd
      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      
      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      
     mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmy  
*/

#include <Arduboy2.h>
#include <ArduboyPlaytune.h>
#include "bitmaps.h"
#include "BGM.h"
#include "pause.h"
Arduboy2 arduboy;
ArduboyPlaytune tunes(arduboy.audio.enabled);
int counter;
//int snail_bx = 1;
//int snail_by = 54;
int snailx = 1;
int snaily = 54;
int goalx = 121;
int goaly = 54;
int gamestate = 0;
bool hit = false;

bool invertScreen = false;

#define MIRROR_SCREEN
bool isPaused = false;

void setup() {
    arduboy.setFrameRate(60);
    arduboy.begin();
    arduboy.clear();
    arduboy.setCursor(0, 0);
    arduboy.print("A DIRTY PORT OF THE\n\nSEGA MASTERSYSTEM\n\nBIOS EASTER EGG\n\nBy @Keyboard_Camper");
    arduboy.display();
    // audio setup
    tunes.initChannel(PIN_SPEAKER_1);
    #ifndef AB_DEVKIT
    // if not a DevKit
    tunes.initChannel(PIN_SPEAKER_2);
    #else
    // if it's a DevKit
    tunes.initChannel(PIN_SPEAKER_1); // use the same pin for both channels
    tunes.toneMutesScore(true);       // mute the score when a tone is sounding
    #endif
    if (!tunes.playing())
    tunes.playScore(bootsound);
    arduboy.delayShort(2500);
    arduboy.clear();
    arduboy.drawBitmap( 68, 1, AB, 39, 57, WHITE );
    arduboy.setCursor(0, 10);
    arduboy.print(" FOR THE\n ARDUBOY\n MAY 2017\n GAME JAM!");
    arduboy.display();
    arduboy.delayShort(3500);
    #ifdef MIRROR_SCREEN
    Serial.begin(9600);
    #endif
}


void loop() {
  if(!arduboy.nextFrame()) {
    return;
  }
  arduboy.pollButtons();
  arduboy.clear();
  //Game code here
  switch( gamestate ) {
   case 0:
      //Intro screen
      arduboy.drawBitmap(0, 0, title, 128, 64, WHITE);
      arduboy.setCursor(50, 56);
      arduboy.setTextSize(1);
      arduboy.print("PRESS A");
      if(arduboy.everyXFrames(60))
      {
        invertScreen = !invertScreen;
        arduboy.invert(invertScreen);
      }
      if(arduboy.justPressed(A_BUTTON)) {
        gamestate = 1;
        invertScreen = false;
        arduboy.invert(false);
      }
      break;
      case 1:
      //Intro screen
      //arduboy.clear();
      arduboy.setCursor(0, 0);
      arduboy.setTextSize(1);
      arduboy.print("WELCOME TO ARDUBOY\nSYSTEM TO PLAY:\n\n1. PRESS A TO START \n\n2. PRESS B TO PAUSE \n\nAND....  ENJOY!!!");
      //Change the gamestate    
      if(arduboy.justPressed(A_BUTTON)) {
        gamestate = 2;
        counter = 31;
      }
      break;
   case 2:
    //arduboy.clear();
    arduboy.drawBitmap( 0, 0, background, 128, 64, WHITE );
    arduboy.drawBitmap(goalx, goaly, goal, 6, 6, WHITE);
    arduboy.drawBitmap(snailx, snaily, snail, 7, 6, WHITE);
      
     if (arduboy.everyXFrames(60)){      
      counter = counter - 1;}
      
     arduboy.setCursor(116, 0);
     arduboy.print(counter);
      
     if (counter == 0){
       gamestate = 4;
      }
        
     if (!tunes.playing())
       tunes.playScore(bgm);     

      hit = (snailx == goalx && snaily == goaly);
      if(hit) {
        digitalWrite(GREEN_LED, LOW); // turn on green LED
        digitalWrite(RED_LED, HIGH);  // turn off red LED
        digitalWrite(BLUE_LED, HIGH);  // turn off blue LED
        arduboy.delayShort(500);
        digitalWrite(GREEN_LED, HIGH); // turn off green LED
        digitalWrite(RED_LED, LOW);  // turn on red LED
        digitalWrite(BLUE_LED, HIGH);  // turn off blue LED
        arduboy.delayShort(500);
        digitalWrite(GREEN_LED, HIGH); // turn off green LED
        digitalWrite(RED_LED, HIGH);  // turn off red LED
        digitalWrite(BLUE_LED, LOW);  // turn on blue LED
        arduboy.delayShort(500);
        digitalWrite(BLUE_LED, HIGH);  // turn off blue LED       
        arduboy.clear();
        gamestate = 3;
      }
      break;
   case 3:
      //arduboy.clear();
      arduboy.setCursor(14, 14);
      arduboy.print("CONGRATULATIONS\n\n       PRESS A\n\n     TO CONTINUE");
           
      if(arduboy.justPressed(A_BUTTON)) {
        gamestate = 1;
        snailx = 1;
        snaily = 54;
        hit = false;
      }
      break;   
   case 4:
      //arduboy.clear();                
      arduboy.setCursor(20,8);
      arduboy.setTextSize(3);
      arduboy.print("TIME! \nPress A");
         
      if(arduboy.justPressed(A_BUTTON)) {
        gamestate = 1;
        counter = 31;
      }
      break; 
    }
 //pausing this is broken I think I killed it but props to gnargle for the example       
     if (isPaused){
    arduboy.setCursor(50,30);
    arduboy.setTextSize(1);
    arduboy.print("PAUSE ");
   }
   
  isPaused = check_pause(arduboy, isPaused);

  if(arduboy.pressed(LEFT_BUTTON)) {
       snailx = snailx - 1;
      }
      if(arduboy.pressed(RIGHT_BUTTON)) {
        snailx = snailx + 1;
      }
      if(arduboy.pressed(UP_BUTTON)) {
        snaily = snaily - 1;
        }   
      if(arduboy.pressed(DOWN_BUTTON)) {
        snaily = snaily + 1;
      }
#ifdef MIRROR_SCREEN
Serial.write(arduboy.getBuffer(), 128 * 64 / 8);
#endif
  arduboy.display();
 }
