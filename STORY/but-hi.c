//this is run when the escape key is pressed

void click(void)
{
 //stop mouse from interferring with choice menu
 sp_brain(1, 0);

 //cancel wait_for_button, so it doesn't interfere with choice menu
 &save_x = editor_seq(3, -1);
 &save_x = sp_custom("but-script", &save_x, -1);
 run_script_by_number(&save_x, "pause");

 int &old_result;
 Playsound(18, 22050, 0,0,0);

 help:

  choice_start();
  set_title_color 15
  title_start();
   Choose an option
  title_end();
  "Help/info"
  "Save/Load"
  "Switch to Dinks World"
  "Resume game"
  "Restart game"
  "Quit Game"
  choice_end();


 if (&result == 1)
 {
  helpinfo:
   choice_start();
   "What are the current puzzle controls?"
   "What does the System Access button do?"
   "Done"
   choice_end();
   
  if (&result == 1)
  {
   puz_tut();
   goto helpinfo;
  }
  if (&result == 2)
  {
   choice_start();
   set_title_color 15
   set_y 240
   title_start();
   Use the System Access button to move between currently available screens/scenes 'Inside the System'
   More screen will unlock as you progress
   title_end();
   "Ok, got it"
   choice_end();
   
   goto helpinfo;
  }
  
  goto help;
 }

 if (&result == 2)
 {
  saveload:
   choice_start();
   "Save game"
   "Load game"
   "Done"
   choice_end();
   
   if (&result == 1)
   {
    choice_start();
    "&savegameinfo"
    "&savegameinfo"
    "&savegameinfo"
    "&savegameinfo" 
    "&savegameinfo" 
    "&savegameinfo" 
    "&savegameinfo" 
    "&savegameinfo" 
    "&savegameinfo" 
    "&savegameinfo" 
    "Nevermind"
    choice_end();
    
    save_game(&result);
    goto saveload;
  }
  
  if (&result == 2)
  {
   choice_start();
   "&savegameinfo"
   "&savegameinfo"
   "&savegameinfo"
   "&savegameinfo" 
   "&savegameinfo" 
   "&savegameinfo" 
   "&savegameinfo" 
   "&savegameinfo" 
   "&savegameinfo" 
   "&savegameinfo" 
   "Nevermind"
   choice_end();
   
   if (&result == 11) goto help;

   if (game_exist(&result) == 0)
   {
    unfreeze(1);
    wait(2000);  
    say("Wow, this loaded game looks so familiar.", 1);
    goto stopex;
   }

   init("load_sequence_now graphics\dink\walk\ds-w1- 71 43 38 72 -14 -9 14 9");
   init("load_sequence_now graphics\dink\walk\ds-w2- 72 43 37 69 -13 -9 13 9");
   init("load_sequence_now graphics\dink\walk\ds-w3- 73 43 38 72 -14 -9 14 9");
   init("load_sequence_now graphics\dink\walk\ds-w4- 74 43 38 72 -12 -9 12 9");
   
   init("load_sequence_now graphics\dink\walk\ds-w6- 76 43 38 72 -13 -9 13 9");
   init("load_sequence_now graphics\dink\walk\ds-w7- 77 43 38 72 -12 -10 12 10");
   init("load_sequence_now graphics\dink\walk\ds-w8- 78 43 37 69 -13 -9 13 9");
   init("load_sequence_now graphics\dink\walk\ds-w9- 79 43 38 72 -14 -9 14 9");
   
   init("load_sequence_now graphics\dink\idle\ds-i2- 12 250 33 70 -12 -9 12 9");
   init("load_sequence_now graphics\dink\idle\ds-i4- 14 250 30 71 -11 -9 11 9");
   init("load_sequence_now graphics\dink\idle\ds-i6- 16 250 36 70 -11 -9 11 9");
   init("load_sequence_now graphics\dink\idle\ds-i8- 18 250 32 68 -12 -9 12 9");
   
   init("load_sequence_now graphics\dink\hit\normal\ds-h2- 102 75 60 72 -19 -9 19 9");
   init("load_sequence_now graphics\dink\hit\normal\ds-h4- 104 75 61 73 -19 -10 19 10");
   init("load_sequence_now graphics\dink\hit\normal\ds-h6- 106 75 58 71 -18 -10 18 10");
   init("load_sequence_now graphics\dink\hit\normal\ds-h8- 108 75 61 71 -19 -10 19 10");


   unfreeze(1);
   load_game(&result);
   &update_status = 1;
   draw_status();
   kill_this_task();   
  }
  
  goto help;
 }

 if (&result == 3)
 {
  int &val1;
  int &val2;
 
  script_attach(1000);
  fade_down();
  fill_screen(0);

  //Store current 'inside the system` location
  external("dc-f", "remoteseq", 65, 99, &player_map);  
  
  //Retrieve Dinks map location
  external("dc-f", "remoteseq", 65, 1, -1);
  int &val1 = &return;
  &player_map = &val1;

  //Retrieve Dinks x location
  external("dc-f", "remoteseq", 65, 2, -1);
  int &val1 = &return;
  
  //Retrieve Dinks y location
  external("dc-f", "remoteseq", 65, 3, -1);   
  int &val2 = &return;  
  sp_x(1, &val1);
  sp_y(1, &val2);
  
  //Retrieve Dinks direction
  external("dc-f", "remoteframe", 65, 1, -1);
  int &val1 = &return;
  sp_dir(1, &val1);
  
  sp_base_idle(1, 10);
  sp_base_walk(1, 70);
  sp_base_attack(1, 100);
  sp_brain(1, 1);
  sp_que(1, 0);
  sp_noclip(1, 0);
  set_dink_speed(3);
  
  load_screen();
  draw_screen();
  draw_hard_map();
  draw_status();
  draw_background();
  fade_up();
  kill_this_task();
 }

 if (&result == 4)
 {
  resumegame:
   //re-enable  wait_for_button
   &save_x = editor_seq(3, -1);
   &save_x = sp_custom("but-script", &save_x, -1);
   run_script_by_number(&save_x, "main");
   
   //re-enable normal mouse movement
   sp_brain(1, 13);
   
   unfreeze(1);
   goto stopex;
 }

 if (&result == 5)
 {
  choice_start();
  "Yes, I really want to restart from scratch"
  "No, go back!"
  choice_end();
  if (&result == 2)
  {
  goto help;
  }
  if (&result == 1)
  {
  unfreeze(1);
  restart_game();
  kill_this_task();
  }
  
  unfreeze(1);
  goto stopex;
 }

 if (&result == 6)
 {
  choice_start();
  "Yes, I really want to quit the game"
  "I was just kidding, back to the action, please"
  choice_end();
  if (&result == 1)
  {
   kill_game();
  }
  if (&result == 2)
  {
   goto resumegame;
  }
  unfreeze(1);
  goto stopex;
 }

 unfreeze(1);
 goto stopex;
}

void puz_tut(void)
{
 int &word;

 if (&player_map == 163)
 {
  //initiate text box with paper background and black borders
  external("robj-dctb", "text_box_start", 320, 65, 0, 0, 0, 0, 0, 0);
  if (&save_x == 0) return;
    &word = &save_x;
  
  //text display
  say_xy("`%~Controls and Info~", 1, &word);

  if (&keyboard == 1)
  {
   say_xy("`%Clicking a text box will select it and activate keyboard mode.", 3, &word);
   say_xy("`%In keyboard mode you can type, and select other text boxes using the arrows", 3, &word);
   
   if (&vcheck >= 111)
    say_xy("`%Pressing the 'DELETE' key will toggle delete mode.", 4, &word);
   else
    say_xy("`%Pressing the 'Backspace' key will toggle delete mode.", 4, &word); 
    
   say_xy("`%When delete is turned on, arrow keys will also delete text.", 5, &word);
   say_xy("`%Delete mode is optional though. You can also just type over", 6, &word);
   say_xy("`%the top of old text and it will be replaced.", 7, &word);
   say_xy("`%To exit keyboard mode and bring back the mouse, press the `ESC` key.", 8, &word);

   say_xy("`3~PRESS SPACEBAR TO CONTINUE~", 10, &word); 
  }
  else
  {
   say_xy("`%Click a text box to select it and activate keyboard mode.", 3, &word);
   say_xy("`%In keyboard mode you can type, using the on-screen keyboard.", 3, &word);
   say_xy("`%Click the keyboard icon in the bottom left to toggle the on-screen keyboard", 4, &word);
   say_xy("`%While in keyboard mode, use the arrow keys to select other text boxes", 5, &word);
  
   say_xy("`%Clicking the 'Delete' key on the on-screen keyboard will toggle delete mode.", 6, &word);  
    
   say_xy("`%When delete is turned on, arrow keys will also delete text.", 7, &word);
   say_xy("`%Delete mode is optional though. You can also just type over", 8, &word);
   say_xy("`%the top of old text and it will be replaced.", 9, &word);
   say_xy("`%If you want to de-select a text box you can press the `ESC` key.", 10, &word);
 
    say_xy("`3~PRESS SPACEBAR TO CONTINUE~", 12, &word); 
  }
   
   //arrange text, wait for space, and clear the text
   external("robj-dctb", "text_box_arrange", &word, 0, 635, 1, 0, 0, 0, 1); 
   
   //change the position of the text box
   external("robj-dctb", "text_box_xy", &word, 320, 120);
   
   say_xy("`%Don't worry about remembering everything - reminders will display on screen", 1, &word);
   say_xy("`%Also, you can click 'Help/Info' for information on various things.", 2, &word);
   say_xy("`%Also clicking other stuff will help you figure out what to do - try everything.", 3, &word);
   say_xy("`%Good luck!", 5, &word);
   say_xy("`3~PRESS SPACEBAR TO CONTINUE~", 6, &word);    
  
  //arrange text, wait for space, and clear the text
  external("robj-dctb", "text_box_arrange", &word, 0, 635, 1, 0, 0, 0, 2);  
 }
}

void stopex(void)
{
stopex:
 return;
}