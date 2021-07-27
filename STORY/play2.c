//Script for WITHIN THE SYSTEM scene

void main(void)
{
//make the current sprite invisible
 sp_nodraw(&current_sprite, 1);
 if (&story == 0)
 {
 //create text
  wait(500);
  int &spch = create_sprite(479, 45, 0, 160, 7);
  sp_pseq(&spch, 160);
  sp_pframe(&spch, 7);
  sp_speed(&spch, 7);
  Playsound(63,44100,0,0,0);
  wait(700);
  wait_for_button();

 //move text off screen
  Playsound(61,35000,0,0,0); 
  move_stop(&spch, 6, 900, 1);

 //create transport
  int &elev = create_sprite(-70, 273, 6, 852, 1);
  sp_seq(&elev, 852);
  sp_brain(&elev, 6);
  sp_speed(&elev, 1);
  sp_sound(&elev, 68);
  sp_timing(&elev, 33);

 //move transport on screen
  move_stop(&elev, 6, 93, 1);
  
 //create hole that number 5 will fall out of
  int &hole = create_sprite(447, 22, 0, 158, 2);
  sp_pseq(&hole, 158);
  sp_pframe(&hole, 2);
  sp_que(&hole, -700);
  playsound(24, 22052, 0, 0, 0);
  
 //make transport keep moving 
 //while the next stuff happens
  move(&elev, 6, 355, 1);

 //create number 5
  int &five = create_sprite(447, 22, 0, 853, 5);
  sp_pseq(&five, 853);
  sp_pframe(&five, 5);
  sp_speed(&five, 5);
  playsound(61, 22052, 0, 0, 0);

 //make it fall and bounce
  move_stop(&five, 2, 179, 1);
  playsound(51, 44100, 0, 0, 0); 
  sp_speed(&five, 3); 
  move_stop(&five, 8, 158, 1);
  sp_speed(&five, 4);
  move_stop(&five, 2, 196, 1);
  playsound(51, 44100, 0, 0, 0); 
  sp_speed(&five, 4);
  move_stop(&five, 8, 164, 1);
  sp_speed(&five, 5);
  move(&five, 2, 247, 1);

 //make transport fast and flash like crazy
  sp_speed(&elev, 16);
  sp_timing(&elev, 0);
  playsound(67, 16000, 0, 0, 0);
  sp_frame_delay(&elev, 20);
  playsound(69, 44100, 0, 0, 0);
  sp_sound(&elev, 0);

 //make it move to catch the number 5
  move_stop(&elev, 6, 446, 1);
  sp_x(&elev, 450);
  move_stop(&five, 2, 247, 1);
  playsound(51, 44100, 0, 0, 0); 
  move_stop(&five, 8, 215, 1);
  move_stop(&five, 2, 247, 1);
  sp_y(&five, 247);
  wait(700);

 //change sequence 
 //so the 5 sitting on transport is only 1 sprite
  sp_seq(&elev, 855);
  sp_frame(&elev, 1);
  sp_nodraw(&five, 1);
  sp_brain(&elev, 0);
  wait(1);
  wait(1000);

 //speech bubble
  sp_nodraw(&spch, 1);
  sp_x(&spch, 384);
  sp_y(&spch, 205);
  sp_pseq(&spch, 150);
  sp_pframe(&spch, 9);
  sp_que(&spch, -500);
  sp_nodraw(&spch, 0);
  Playsound(61,22050,0,0,0);
  wait(200); 
  wait_for_button();

 //speech bubble
  sp_pframe(&spch, 10);
  Playsound(61,22050,0,0,0);
  wait(200);
  wait_for_button();

 //speech bubble
  sp_pframe(&spch, 11);
  Playsound(61,22050,0,0,0);
  sp_x(&spch, 384);
  sp_y(&spch, 218);
  wait(200);
  wait_for_button();

 //speech bubble
  sp_pframe(&spch, 12);
  Playsound(61,22050,0,0,0); 
  wait(200);
  wait_for_button(); 

 //speech bubble 
  sp_pframe(&spch, 13);
  Playsound(61,22050,0,0,0);    
  wait(200);
  wait_for_button();  
  wait(600);

 //make transport flash
  sp_frame_delay(&elev, 150);
  sp_brain(&elev, 6);
  sp_seq(&elev, 855);
  sp_sound(&elev, 68);
  wait(1000);
  sp_brain(&elev, 0);
  sp_sound(&elev, 0);
  wait(1);
  sp_pframe(&elev, 1);
  sp_frame(&elev, 1);

 //speech bubble
  sp_x(&spch, 399);
  sp_y(&spch, 269);
  sp_pframe(&spch, 18);
  sp_que(&spch, 500);
  Playsound(61,22050,0,0,0);
  wait(200);
  wait_for_button(); 
  wait(500);

 //make transport flash again
  sp_frame_delay(&elev, 150);
  sp_brain(&elev, 6);
  sp_seq(&elev, 855);
  sp_sound(&elev, 68);
  wait(1000);
  sp_brain(&elev, 0);
  sp_sound(&elev, 0);
  wait(1);
  sp_pframe(&elev, 1);
  sp_frame(&elev, 1); 

 //speech bubble
  sp_pframe(&spch, 19);
  Playsound(61,22050,0,0,0);
  wait(200);
  wait_for_button(); 

 //speech bubble
  sp_pframe(&spch, 20);
  Playsound(61,22050,0,0,0);
  wait(200);  
  wait_for_button();

 //get rid of speech bubble
 //and make transport move off screen
  sp_nodraw(&spch, 1);
  sp_speed(&elev, 3);
  sp_brain(&elev, 6);
  sp_seq(&elev, 855);
  sp_sound(&elev, 68);
  move_stop(&elev, 4, 413, 1);
  sp_speed(&elev, 9);
  playsound(69, 44100, 0, 0, 0);
  move_stop(&elev, 6, 700, 1);
  sp_sound(&elev, 0);
  wait(1000);

 //change screens
  script_attach(1000);
  fade_down();
  wait(400);
  &player_map = 35;
  load_screen(35);
  draw_screen();
  fade_up();
  kill_this_task();  
 }
}
 
 