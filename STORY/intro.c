//Intro Script
//after dink walking and credits have already 
//been done

void main(void)
{
 sp_nohit(&current_sprite, 1);
 if (&player_map == 1)
 {
  if (&story == 0)
  {
  //Give the mouse back
   sp_nodraw(1, 1);
   sp_seq(1, 0);
   sp_brain(1, 13);
   sp_pseq(1,10);
   sp_pframe(1,8);
   sp_que(1,20000);
   sp_noclip(1, 1);
   sp_base_idle(1, -1);
   sp_base_walk(1, -1);

  //create bottom black backdrop
   int &backd = create_sprite(406, 389, 0, 99, 5);
   sp_pseq(&backd, 99);
   sp_pframe(&backd, 5);
   sp_que(&backd, -550);
   wait(1000);
   int &myx = 0;

  //Create the first text
   int &txt = create_sprite(410, 389, 0, 160, 1);
   sp_size(&txt, 1);
   sp_pseq(&txt, 160);
   sp_pframe(&txt, 1);
  
 //make it start small and grow 
  loop:
   wait(2);
   &myx += 2;
   sp_size(&txt, &myx);
   &myx = sp_size(&txt, -1);
   if (&myx < 100) goto loop;
   wait(4000); 
  
  //change screens
   script_attach(1000);
   fade_down();
   wait(400);
   &player_map = 2;
   load_screen(2);
   draw_screen();
   fade_up();
   kill_this_task();
  }
 }
 if (&player_map == 2)
 {
  if (&story == 0)
  {
  //Create bottom black backdrop
   int &backd = create_sprite(406, 389, 0, 99, 5);
   sp_pseq(&backd, 99);
   sp_pframe(&backd, 5);
   sp_que(&backd, -550);
   wait(1000);
   int &myx = 0;

  //create first text
   int &txt = create_sprite(410, 389, 0, 160, 2);
   sp_size(&txt, 1);
   sp_pseq(&txt, 160);
   sp_pframe(&txt, 2);

 //make it start small and grow
  loop2:
   wait(2);
   &myx += 2;
   sp_size(&txt, &myx);
   &myx = sp_size(&txt, -1);
   if (&myx < 100) goto loop2;
   wait(4000);   

  //move the text off screen and kill it
   sp_speed(&txt, 3);
   move_stop(&txt, 6, 800, 1);
   sp_active(&txt, 0);

  //create split screen effect
   sp_x(&current_sprite, 128);
   int &scn = create_sprite(538, 220, 0, 99, 1);
   sp_pseq(&scn, 99);
   sp_pframe(&scn, 1);
   sp_que(&scn, -500);
   Playsound(20,22050,0,0,0);
   wait(700);
   
  //speech 1
   &txt = create_sprite(403, 124, 0, 150, 1);
   sp_pseq(&txt, 150);
   sp_pframe(&txt, 1);
   Playsound(61,22050,0,0,0); 
   wait(200);
   wait_for_button();  

  //speech 2
   sp_pframe(&txt, 2);
   sp_x(430);
   sp_y(166);
   Playsound(61,22050,0,0,0); 
   wait(200);
   wait_for_button();

  //speech 3
   sp_pframe(&txt, 3);
   sp_x(395);
   sp_y(140);
   Playsound(61,22050,0,0,0); 
   wait(200);
   wait_for_button(); 

  //speech 4 
   sp_pframe(&txt, 4);
   sp_x(412);
   sp_y(151);
   Playsound(61,22050,0,0,0); 
   wait(200);
   wait_for_button(); 

  //speech 5
   sp_pframe(&txt, 5);
   sp_x(388);
   sp_y(127);
   Playsound(61,22050,0,0,0); 
   wait(200);
   wait_for_button(); 

  //speech 6
   sp_pframe(&txt, 6);
   sp_x(424);
   sp_y(133);
   Playsound(61,22050,0,0,0); 
   wait(200);
   wait_for_button(); 

  //speech 7
   sp_pframe(&txt, 7);
   sp_x(399);
   sp_y(125);
   Playsound(61,22050,0,0,0); 
   wait(200);
   wait_for_button(); 

  //kill speech 
   sp_nodraw(&txt, 1);
   sp_active(&txt, 0);

  //change screens
   script_attach(1000);
   fade_down();
   wait(400);
   &player_map = 3;
   load_screen(3);
   draw_screen();
   fade_up();
   kill_this_task();
  }
 }
}
   
  
   