//Script for Dmod opening
//After you start the game

void main(void)
{
 if (&player_map == 738)
 {
 //freeze dink and create variables
  freeze(1);

  choice_start();
  "skip intro"
  "skip half of intro"
  "don't skip any"
  choice_end();
  
  if (&result == 1)
  {
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
    &player_map = 163;
    load_screen(163);
    draw_screen();
    //sp_nodraw(1, 0);
   
    kill_this_task();
   ////////////////////////
   ////////////////////////
  }
  if (&result == 2)
  {
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
  }

  int &sttext;
  wait(2000);

 //scrolling text
  &sttext = say_xy("`%It is well known these days, that new adventures are a rare occurance", 0, 500);
  sp_kill(&sttext, 0);
  sp_speed(&sttext, 2);
  move(&sttext, 8, -20, 1);
  wait(1500);

 //scrolling text
  &sttext = say_xy("`%Motivation is lost so easily, but treasured when found..", 0, 480);
  sp_kill(&sttext, 0);
  sp_speed(&sttext, 2);
  move(&sttext, 8, -20, 1);
  wait(1500);

 //scrolling text
  &sttext = say_xy("`%Sometimes bad luck strikes, and an adventure is no more...", 0, 500);
  sp_kill(&sttext, 0);
  sp_speed(&sttext, 2);
  move(&sttext, 8, -20, 1);
  wait(1500);

 //scrolling text
  &sttext = say_xy("`%But sometimes, once in a life time, something very unlucky happens..", 0, 500);
  sp_kill(&sttext, 0);
  sp_speed(&sttext, 2);
  move(&sttext, 8, -20, 1);
  wait(2000);

 //scrolling text
  &sttext = say_xy("`%Something odd..", 0, 500);
  sp_kill(&sttext, 0);
  sp_speed(&sttext, 2);
  move(&sttext, 8, -20, 1);
  wait(2000);

 //scrolling text
  &sttext = say_xy("`%Something strange...", 0, 500);
  sp_kill(&sttext, 0);
  sp_speed(&sttext, 2);
  move(&sttext, 8, -20, 1);
  wait(2000);

 //scrolling text
  &sttext = say_xy("`%And something even Dink could not possibly expect to happen...", 0, 500);
  sp_kill(&sttext, 0);
  sp_speed(&sttext, 2);
  move_stop(&sttext, 8, 225, 1);
  
  //move it all off faster once the last line has reached the middle
  &save_x = 0;
 text_speedup:
  &save_x = get_next_sprite_with_this_brain(8, 0, &save_x);
  if (&save_x > 0)
  {
   sp_speed(&save_x, 6);
   &save_x += 1;
   goto text_speedup;
  }

 move_stop(&sttext, 8, -60, 1);

 //Kill all text sprites
 external("dc-f", "kill_texts");
 
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
  say_xy("`%Robj and Skurn present..", 20, 350);
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
  say_xy("`%A new Dink Smallwood adventure..", 20, 350);
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
  say_xy("`%Thanks to the Dink Network, and its many users for inspiration", 20, 350);
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
  say_xy("`%Parts of this dmod inspired by (and particular parts a homage to) '3 in Three'", 20, 350);
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
  say_xy("`%See credits.txt for credits", 20, 350);
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
 