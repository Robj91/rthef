//script for screen 163

  //text position for small text box
  //is text box X-301
  //            Y-29

void main(void)
{
 //make the current sprite invisible
 sp_nodraw(&current_sprite, 1); 
 
 //hide all text boxes
 &save_x = 0;
hide_tbox:
 &save_x = get_next_sprite_with_this_brain(0, 0, &save_x);
 if (&save_x > 0)
 {
  &save_y = sp_pseq(&save_x, -1);
  if (&save_y == 35)
  {
   sp_nodraw(&save_x, 1);
  }
  
  &save_x += 1;
  goto hide_tbox;
 }
 
 int &numfive;
 
 //create transport
  int &elev = create_sprite(383, -100, 0, 855, 1);
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

  //un-hide all text boxes
  playsound(71, 22050, 0, 0, 0);
  &save_x = 0;
 unhide_tbox:
  &save_x = get_next_sprite_with_this_brain(0, 0, &save_x);
  if (&save_x > 0)
  {
   &save_y = sp_pseq(&save_x, -1);
   if (&save_y == 35)
   {
    sp_nodraw(&save_x, 0);
   }
   
   &save_x += 1;
   goto unhide_tbox;
  }

  sp_nodraw(1, 0);
  &save_x = create_sprite(308, 410, 0, 98, 3);
  sp_noclip(&save_x, 1);
  sp_que(&save_x, 1000);
  sp_pseq(&save_x, 98);
  sp_pframe(&save_x, 4);
  
  &save_x = create_sprite(
  set_mode(1);
 }