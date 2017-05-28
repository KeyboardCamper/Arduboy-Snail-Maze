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

enum class GameState
: unsigned char
{
	Intro,
	Title,
	Description,
	Gameplay,
	Success,
	Failure,
	Paused,
};

int counter;
//int snail_bx = 1;
//int snail_by = 54;
int snailx = 1;
int snaily = 54;
int goalx = 121;
int goaly = 54;

bool invertScreen = false;

GameState gameState;
GameState priorState;

void changeState(GameState newState)
{
	priorState = gameState;
	gameState = newState;
}

void restoreState(void)
{
	gameState = priorState;
}

#define MIRROR_SCREEN

void setup()
{	
    #ifdef MIRROR_SCREEN
    Serial.begin(9600);
    #endif
	
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
    changeState(GameState::Title);
}


void loop()
{
	if(!arduboy.nextFrame())
		return;

	arduboy.pollButtons();
  
	arduboy.clear();
	
	//Game code here
	switch(gameState)
	{
		case GameState::Title: updateTitle(); break;
		case GameState::Description: updateDescription(); break;
		case GameState::Gameplay: updateGameplay(); break;
		case GameState::Success: updateSuccess(); break;
		case GameState::Failure: updateFailure(); break;
		case GameState::Paused: updatePaused(); break;
	}
		
#ifdef MIRROR_SCREEN
Serial.write(arduboy.getBuffer(), (arduboy.width() * arduboy.height()) / sizeof(unsigned char));
#endif

	arduboy.display();
}

void updateTitle(void)
{
	arduboy.drawBitmap(0, 0, title, arduboy.width(), arduboy.height());
	arduboy.setCursor(50, 56);
	arduboy.setTextSize(1);
	arduboy.print(F("PRESS A"));
	
	if(arduboy.everyXFrames(60))
	{
		invertScreen = !invertScreen;
		arduboy.invert(invertScreen);
	}
	
	if(arduboy.justPressed(A_BUTTON))
	{
		changeState(GameState::Description);
    invertScreen = false;
    arduboy.invert(false);
	}
}
 
void updateDescription(void)
{
	arduboy.setCursor(0, 0);
	arduboy.setTextSize(1);
	arduboy.print(F("WELCOME TO ARDUBOY\nSYSTEM TO PLAY:\n\n1. PRESS A TO START \n\n2. PRESS B TO PAUSE \n\nAND....  ENJOY!!!"));
	
	if(arduboy.justPressed(A_BUTTON))
	{
    snailx = 1;
    snaily = 54;
    counter = 31;
		changeState(GameState::Gameplay);
	}
}

void updateGameplay(void)
{
  if(arduboy.pressed(LEFT_BUTTON)) --snailx;
  if(arduboy.pressed(RIGHT_BUTTON)) ++snailx;
  if(arduboy.pressed(UP_BUTTON)) --snaily;
  if(arduboy.pressed(DOWN_BUTTON)) ++snaily;
  
  if(arduboy.justPressed(B_BUTTON))
    changeState(GameState::Paused);
  
  arduboy.drawBitmap( 0, 0, background, arduboy.width(), arduboy.height());
  arduboy.drawBitmap(goalx, goaly, goal, 6, 6, WHITE);
  arduboy.drawBitmap(snailx, snaily, snail, 7, 6, WHITE);
      
  if (arduboy.everyXFrames(60))
    --counter;
      
  arduboy.setCursor(116, 0);
  arduboy.print(counter);
      
  if (counter == 0)
  {
    changeState(GameState::Failure);
  }
     
  if (!tunes.playing())
    tunes.playScore(bgm);

	if(snailx == goalx && snaily == goaly)
	{
    lightSequence();   
		changeState(GameState::Success);
	}
}

void updateSuccess(void)
{
	arduboy.setCursor(14, 14);
	arduboy.print(F("CONGRATULATIONS\n\n       PRESS A\n\n     TO CONTINUE"));
         
  if(arduboy.justPressed(A_BUTTON))
    changeState(GameState::Title);
}

void updateFailure(void)
{          
	arduboy.setCursor(20,8);
	arduboy.setTextSize(3);
	arduboy.print(F("TIME! \nPress A"));
         
	if(arduboy.justPressed(A_BUTTON))
    changeState(GameState::Title);
}

void updatePaused(void)
{
    arduboy.setCursor(50,30);
    arduboy.setTextSize(1);
    arduboy.print(F("PAUSE"));
	
    if(arduboy.justPressed(B_BUTTON))
      restoreState();
}


void lightSequence(void)
{
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
}

