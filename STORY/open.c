//Script for Dmod opening
//After you start the game

void main(void)
{
 if (&player_map == 738)
 {
 //freeze dink and create variables
  freeze(1);

  ////////////////////////
  //temporary intro skip//
  ////////////////////////
   sp_nodraw(1, 1);
   sp_seq(1, 0);
   sp_brain(1, 13);
   sp_pseq(1,10);
   sp_pframe(1,8);
   sp_que(1,20000);
   sp_noclip(1, 1);
   sp_base_idle(1, -1);
   sp_base_walk(1, -1);
   
   script_attach(1000);
   &player_map = 67;
   load_screen(67);
   draw_screen();
   //sp_nodraw(1, 0);

   kill_this_task();
  ////////////////////////
  ////////////////////////

  int &sttext;
  int &sttext2;
  int &sttext3;
  int &sttext4;
  int &sttext5; 
  int &sttext6; 
  int &sttext7; 
  int &sttext8; 
  wait(2000);

 //scrolling text
  &sttext = say_xy("`%It is well known these days, that new adventures are a rare occurance", 0, 500);
  sp_kill(&sttext, 0);
  sp_speed(&sttext, 1);
  move(&sttext, 8, -20, 1);
  wait(2000);

 //scrolling text
  &sttext3 = say_xy("`%Motivation is lost so easily, but treasured when found..", 30, 480);
  sp_kill(&sttext3, 0);
  sp_speed(&sttext3, 1);
  move(&sttext3, 8, -20, 1);
  wait(3000);

 //scrolling text
  &sttext4 = say_xy("`%Sometimes bad luck strikes, and an adventure is no more...", 0, 500);
  sp_kill(&sttext4, 0);
  sp_speed(&sttext4, 1);
  move(&sttext4, 8, -20, 1);
  wait(3000);

 //scrolling text
  &sttext5 = say_xy("`%But sometimes, once in a life time, something very unlcuky happens..", 0, 500);
  sp_kill(&sttext5, 0);
  sp_speed(&sttext5, 1);
  move(&sttext5, 8, -20, 1);
  wait(4000);

 //scrolling text
  &sttext6 = say_xy("`%Something odd..", 0, 500);
  sp_kill(&sttext6, 0);
  sp_speed(&sttext6, 1);
  move(&sttext6, 8, -20, 1);
  wait(4000);

 //scrolling text
  &sttext7 = say_xy("`%Something strange...", 0, 500);
  sp_kill(&sttext7, 0);
  sp_speed(&sttext7, 1);
  move(&sttext7, 8, -20, 1);
  wait(4000);

 //scrolling text
  &sttext8 = say_xy("`%And something even Dink could not possibly expect to happen...", 0, 500);
  sp_kill(&sttext8, 0);
  sp_speed(&sttext8, 1);
  move_stop(&sttext8, 8, -60, 1);

 //Kill text sprites
  sp_active(&sttext, 0);
  sp_active(&sttext3, 0);
  sp_active(&sttext4, 0);
  sp_active(&sttext5, 0);
  sp_active(&sttext6, 0);
  sp_active(&sttext7, 0);
  sp_active(&sttext8, 0);

 
 //Change screens
  script_attach(1000);
  fade_down();
  wait(400);
  &player_map = 737;
  load_screen(737);
  draw_screen();
  fade_up();
  kill_this_task();
 }

 if (&player_map == 737)
 {
 //freeze dink
  freeze(1);

 //create text at bottom of screen
  say_xy("`%Graphics - ", 20, 350);
  wait(800);

 //make dink walk up screen
  move(1, 8, -60, 1);
  wait(3500);

 //change screens
  script_attach(1000);
  fade_down();
  wait(400);
  &player_map = 705;
  load_screen(705);
  draw_screen();
  fade_up();
  kill_this_task();
 }
 if (&player_map == 705)
 {
 //freeze dink
  freeze(1);
  sp_y(1, 490);

 //create text at bottom of screen
  say_xy("`%Sounds and Midis - various places on the internet.", 20, 350);
  wait(800);

 //make dink move up screen
  move(1, 8, -60, 1);
  wait(3500);

 //change screens
  script_attach(1000);
  fade_down();
  wait(400);
  &player_map = 673;
  load_screen(673);
  draw_screen();
  fade_up();
  kill_this_task();
 }
 if (&player_map == 673)
 {
 //freeze dink
  freeze(1);
  sp_y(1, 490);
  sp_x(1, 377);

 //create text at bottom of screen
  say_xy("`%Mapping, scripting and overall design by Robj", 20, 350);
  wait(800);

 //make dink walk up and across screen
  move_stop(1, 8, 265, 1);
  move(1, 6, 660, 1);
  wait(3500);

 //change screens
  script_attach(1000);
  fade_down();
  wait(400);
  &player_map = 674;
  load_screen(674);
  draw_screen();
  fade_up();
  kill_this_task();
 }
 if (&player_map == 674)
 {
 //freeze dink
  freeze(1);
  sp_x(1, -5); 
  sp_y(1, 307);

 //create text at bottom of screen
  say_xy("`%Thanks to the Dink Network, and its many users for inspiration.", 20, 350);
  wait(800);

 //make dink move halfway across screen
  move_stop(1, 6, 245, 1);
  wait(500);

 //make dink stop and have a quick look
  sp_dir(1, 8);
  wait(500);
  sp_dir(1, 2);
  wait(450);

 //make dink move across and up screen
  move_stop(1, 6, 462, 1);
  move(1, 8, 96, 1);
  wait(200);

 //change screens
  script_attach(1000);
  fade_down();
  wait(400);
  &player_map = 706;
  load_screen(706);
  draw_screen();
  fade_up();
  kill_this_task();  
 }
 if (&player_map == 706)
 {
 //freeze dink
  freeze(1);
  sp_x(1, 354);
  sp_y(1, -20);

 //create text at bottom of screen
  say_xy("`%Special Thanks to RTsoft for the creation of Dink Smallwood.", 20, 350);
  wait(800);

 //make dink move down screens
  move(1, 2, 490, 1);
  wait(3500);

 //change screens
  script_attach(1000);
  fade_down();
  wait(400);
  &player_map = 1;
  sp_x(1, 282);
  sp_y(1, 228);
  dink_can_walk_off_screen(0);
  load_screen(1);
  draw_screen();
  fade_up();
  kill_this_task();  
 }
 