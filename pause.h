#include <Arduboy2.h>

byte pause_countdown = 0;
byte pause_countdown_set_val = 30; //default half a second 

void setup_pause(byte countdown_var){
  //you only need call this function if you wish to change the default time between which 
  //the game can be paused and unpaused. 30 is a good value because it leaves plenty of time
  //for the player to remove their thumb at 60fps. 
  //You will want to change this if you're using any other framerate probably.
  pause_countdown_set_val = countdown_var;
}

bool check_pause(Arduboy& arduboy, bool isPaused){
   if(arduboy.pressed(B_BUTTON)){
    if (pause_countdown <= 0){
      if (isPaused == false){
        isPaused = true;
        pause_countdown = pause_countdown_set_val;
      }
      else{
        isPaused = false;
        pause_countdown = pause_countdown_set_val;
      }
    }
  }
  if (pause_countdown > 0)  pause_countdown--;
  return isPaused;
}
