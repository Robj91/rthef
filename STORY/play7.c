//script for screen 163

void main(void)
{
 //make the current sprite invisible
 sp_nodraw(&current_sprite, 1); 
 
 int &numfive;
 int &tbox;
 int &counter;
 int &let_num;
 int &word;
 int &elev;
 
 &save_x = editor_seq(1, -1);
 if (&save_x <= 0)
 {
  //create transport
  &elev = create_sprite(383, -100, 0, 855, 1);
  sp_pseq(&elev, 855);
  sp_pframe(&elev, 1);
  sp_speed(&elev, 10);
  sp_timing(&elev, 0);
  sp_sound(&elev, 68);
  
  move_stop(&elev, 2, 355, 1);
  sp_x(&elev, 383);
  sp_y(&elev, 355);
  
  //separate the transport and 5 sprite
  &save_x = &elev;
  
  //create stand alone transport
  &elev = create_sprite(383, 355, 0, 852, 1);
  sp_pseq(&elev, 852);
  sp_pframe(&elev, 1);
  
  //create standalone five sprite
  &numfive = sp_x(&elev, -1);
  &save_y = sp_y(&elev, -1);
  &numfive -= 3;
  &save_y -= 26;
  &numfive = create_sprite(&numfive, &save_y, 0, 853, 5);
  sp_pseq(&numfive, 853);
  sp_pframe(&numfive, 5);
  
  //kill the old combined 5 and transport
  sp_active(&save_x, 0);
  
  //make it bounce
  playsound(51, 44100, 0, 0, 0); 
  sp_speed(&elev, 10);
  sp_timing(&elev, 0);
  sp_speed(&numfive, 10);
  sp_timing(&numfive, 0);
  move(&numfive, 8, 295, 1);
  move_stop(&elev, 8, 322, 1);
  sp_speed(&elev, 9);
  sp_speed(&numfive, 9);
  move(&elev, 2, 355, 1);
  move_stop(&numfive, 8, 322, 1);
  move(&numfive, 2, 329, 1);
  move_stop(&elev, 2, 355, 1);
  move_stop(&numfive, 2, 329, 1);
  sp_y(&elev, 355);
  sp_y(&numfive, 329);
  
  //create explosion on the transport
  playsound(6, 22050, 0,0,0);
  &save_x = create_sprite(385, 373, 7, 70, 1);
  sp_seq(&save_x, 70);
  sp_que(&save_x, 500);
  sp_size(&save_x, 75);
  sp_frame_delay(&save_x, 25);
  
  //jump up from explosion
  move(&numfive, 8, 250, 1);
  move_stop(&elev, 8, 322, 1);
  move(&elev, 2, 355, 1);
  move_stop(&numfive, 8, 250, 1);
  move_stop(&elev, 2, 355, 1);
  sp_y(&elev, 355);
  move(&numfive, 2, 366, 1);
  
  //transport flash
  sp_frame_delay(&elev, 150);
  sp_brain(&elev, 6);
  sp_seq(&elev, 852);
  sp_sound(&elev, 68);
  sp_speed(&elev, 15);
  move(&elev, 4, 116, 1);
  move_stop(&numfive, 2, 366, 1);
  sp_y(&numfive, 366);
  
  sp_sound(&elev, 68);
  //make it flash red
  init("load_sequence_now graphics\trans\transr- 852 150 32 22 -21 -14 21 10");
  
  sp_speed(&elev, 13);
  sp_frame_delay(&elev, 180);  
  
  move_stop(&elev, 6, 300, 1);
  sp_speed(&elev, 11);
  sp_frame_delay(&elev, 210);
  move_stop(&elev, 4, 150, 1);
  sp_sound(&elev, 58);
  sp_speed(&elev, 8);
  sp_frame_delay(&elev, 240);
  move_stop(&elev, 6, 280, 1);
  sp_speed(&elev, 5);
  sp_frame_delay(&elev, 270);
  move_stop(&elev, 4, 100, 1);

  playsound(77, 65000, 0, 0, 0);

  sp_sound(&elev, 57);
  sp_speed(&elev, 3);
  move_stop(&elev, 6, 180, 1);
  sp_sound(&elev, 0);
  sp_frame_delay(&elev, 310);
  sp_speed(&elev, 1);
  move_stop(&elev, 4, 80, 1);

  //speech bubble
  int &spch = create_sprite(185, 305, 0, 150, 24);
  sp_pseq(&spch, 150);
  sp_pframe(&spch, 24);
  sp_que(&spch, -500);
  Playsound(61,22050,0,0,0);

  sp_frame_delay(&elev, 310);  
  wait(2500);
  
  //speech bubble
  sp_pframe(&spch, 25);
  sp_x(&spch, 195);
  sp_y(&spch, 330);
  Playsound(61,22050,0,0,0);

  sp_frame_delay(&elev, 350);    
  wait(2500);

  //speech bubble
  sp_pframe(&spch, 26);
  sp_y(&spch, 300);
  sp_x(&spch, 200);
  Playsound(61,22050,0,0,0);

  Playsound(59,22050,0,0,0);
  sp_frame_delay(&elev, 400);
  wait(1500);  
  
  Playsound(57,22050,0,0,0);  
  
  wait(2000);
  
  sp_brain(&elev, 0);
  sp_sound(&elev, 0);
  wait(1);
  sp_seq(&elev, 0);
  sp_pframe(&elev, 1);  
  wait(300);
  sp_active(&spch, 0);

  playsound(71, 22050, 0, 0, 0);

  //ask for keyboard
  stop_entire_game(1);
  choice_start();
  set_title_color 3
  title_start();
  Are you using a keyboard?
  (If you are playing on phone or tablet and do not kave a keyboard, select NO)
  title_end();
  "I am using a keyboard"
  "NO, I do not have a keyboard"
  choice_end();
  
  if (&result == 1)
  {
   &keyboard = 1;
  }
  else
  {
   &keyboard = 0;
  }

  //set initial Dink Smallwood stats using screen 65 editor_seqs
  //Dinks map location
  external("dc-f", "remoteseq", 65, 1, 731);
  
  //Dinks x location
  external("dc-f", "remoteseq", 65, 2, 314);
  
  //Dinks y location
  external("dc-f", "remoteseq", 65, 3, 202);  
  
  //Dinks direction
  external("dc-f", "remoteframe", 65, 1, 6);    

  //increment editor_seq on editor_sprite 1, so we know this intro has played already
  editor_seq(1, 1);
 }
 else
 {
  //create the number 5 in position
  &numfive = create_sprite(383, 366, 0, 853, 5);
  sp_pseq(&numfive, 853);
  sp_pframe(&numfive, 5);  

  //create transport in position
  &elev = create_sprite(80, 355, 0, 852, 1);
  sp_pseq(&elev, 852);
  sp_pframe(&elev, 1);
  sp_speed(&elev, 10);
  sp_timing(&elev, 0);
  sp_brain(&elev, 0);
  sp_sound(&elev, 0);
 }

  //make sure mouse mode will be disabled and dink can't move
  set_dink_speed(-1);
  sp_brain(1, 1);
  dink_can_walk_off_screen();
  sp_x(1, 1);
  sp_y(1, 1);
  sp_nodraw(1, 1);
  
  //stat bar
  &save_x = create_sprite(308, 407, 0, 98, 4);
  sp_noclip(&save_x, 1);
  sp_que(&save_x, 1000);
  sp_custom("puzzle_pframe", &save_x, 1);
  sp_script(&save_x, "stat2");
  
  //draw the text boxes
  //order: rof, ffd, fcc, ntf.
   &save_x = 181;
   &save_y = 62;
   &counter = 1;
   &let_num = 1;
   &word = 1;
  create_tboxes:
   &tbox = create_sprite(&save_x, &save_y, 0, 35, 2);
   sp_touch_damage(&tbox, -1);
   sp_custom("textbox", &tbox, &counter);
   sp_custom("word_num", &tbox, &word);
   sp_custom("letter_num", &tbox, &let_num);
   sp_script(&tbox, "pz1-tb");
   &counter += 1;
   if (&counter < 52)
   { 
    &gjug1 = &word;
    //next box increment
    &save_x += 24;

    //word spaces
    if (&counter == 5)
    {
     &word = 2;
     &save_x += 20;
    }
    if (&counter == 7)
    {
     &word = 3;
     &save_x += 20;
    }
    if (&counter == 15)
    {
     &word = 4;
     &save_x += 20;
    }
    if (&counter == 21)
    {
     &word = 5;
     &save_x += 20;
    }
    if (&counter == 33)
    {
     &word = 6;
     &save_x += 20;
    }
    if (&counter == 37)
    {
     &word = 7;
     &save_x += 20;
    }
    if (&counter == 46)
    {
     &word = 8;
     &save_x += 20;
    }
    if (&counter == 48)
    {
     &word = 9;
     &save_x += 20;
    }    
    
    //next line of text boxes
    if (&counter == 11)
    {
     &word = 10;
     &save_x = 97;
     &save_y += 85;
    }
    if (&counter == 29)
    {
     &word = 11;
     &save_x = 134;
     &save_y += 85;
    }
    if (&counter == 42)
    {
     &word = 12;
     &save_x = 218;
     &save_y += 85;
    }
    
    if (&word != &gjug1)
    {
     &let_num = 1;
    }
    
    goto create_tboxes;
   }
 
 &save_x = editor_seq(1, -1);
 if (&save_x == 1)
 {
  editor_seq(1, 2);
  
  //initiate text box with paper background and black borders
  external("robj-dctb", "text_box_start", 320, 65, 0, 0, 0, 0, 0, 0);
  if (&save_x == 0) return;
    &word = &save_x;
  
  //text display
  say_xy("`%~Controls and Info~", 1, &word);

  if (&keyboard == 1)
  {
   say_xy("`%Click a text box to select it.", 3, &word);
   say_xy("`%Use the arrow keys to go to the next or previous text box", 3, &word);
   
   say_xy("`%Pressing the 'DELETE' key on the NUMPAD will delete text from a text box", 4, &word); 
    
   say_xy("`%OR, you can also just type over the top of old text to replace it.", 5, &word);
   say_xy("`%To de-select the text box and bring back the mouse cursor, press the `ESC` key.", 6, &word);

   say_xy("`3~PRESS SPACEBAR TO CONTINUE~", 8, &word); 
  }
  else
  {
   say_xy("`%Click a text box to select it.", 3, &word);
   say_xy("`%You can then type using the on-screen keyboard.", 3, &word);
   say_xy("`%Click the keyboard icon in the bottom left to toggle the on-screen keyboard", 4, &word);
  
   say_xy("`%Clicking the 'Delete' key on the on-screen keyboard will clear a box", 5, &word);  
    
   say_xy("`%OR, you can also just type over the top of old text to replace it.", 6, &word);
   say_xy("`%If you want to de-select a text box you can press the `ESC` key.", 7, &word);
 
    say_xy("`3~PRESS SPACEBAR TO CONTINUE~", 9, &word); 
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

 //spawn the script to wait for buttons
 wait(0);
 &counter = spawn("buttons");
 &save_x = editor_seq(3, -1);
 sp_custom("but-script", &save_x, &counter);

 //mouse mode
 sp_brain(1, 13);
 sp_nodraw(1, 0);
 sp_noclip(1, 1);
 sp_que(1, 20000);
 
 //make the numfive a button
 sp_touch_damage(&numfive, -1);
 sp_script(&numfive, "numfive");
 
 //set puzzle active
 editor_frame(3, 1);
}