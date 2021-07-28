//Script for screen with symbols on them, script number

void main(void)
{
 //make the current sprite invisible
 sp_nodraw(&current_sprite, 1); 
 
 //create transport
  int &elev = create_sprite(383, -100, 0, 855, 1);
  sp_pseq(&elev, 855);
  sp_pframe(&elev, 1);
  sp_speed(&elev, 10);
  sp_timing(&elev, 0);
  
  move(&elev, 2, 500, 1);
  
  wait(500);
  
  //create ? symbol
  int &qmark = create_sprite(780, 60, 0, 857, 5);
  sp_pseq(&qmark, 857);
  sp_pframe(&qmark, 5);
  sp_speed(&qmark, 11);
  sp_timing(&qmark, 0);
  
  //create ! symbol
  int &emark = create_sprite(-100, 168, 0, 856, 3);
  sp_pseq(&emark, 856);
  sp_pframe(&emark, 3);
  sp_speed(&emark, 11);
  sp_timing(&emark, 0);
  
  //create @ symbol
  int &amark = create_sprite(780, 272, 0, 856, 9);
  sp_pseq(&amark, 856);
  sp_pframe(&amark, 9); 
  sp_speed(&amark, 11);
  sp_timing(&amark, 0); 

  //create # symbol
  int &nmark = create_sprite(-100, 378, 0, 856, 5);
  sp_pseq(&nmark, 856);
  sp_pframe(&nmark, 5);
  sp_speed(&nmark, 11);
  sp_timing(&nmark, 0);
 
  //move them
  move(&qmark, 4, 455, 1);
  wait(100);
  move(&nmark, 6, 335, 1);
  wait(100);
  move(&emark, 6, 335, 1);
  wait(80);
  move_stop(&amark, 4, 455, 1);
  sp_speed(&emark, 11);
  sp_timing(&emark, 0);
  
  //speech bubbles
  &save_x = create_sprite(388, 106, 0, 150, 27);
  sp_pseq(&save_x, 150);
  sp_pframe(&save_x, 27);
  sp_que(&save_x, -500);
  Playsound(61,22050,0,0,0);
  
  wait(200);  

  &save_x = create_sprite(500, 206, 0, 150, 28);
  sp_pseq(&save_x, 150);
  sp_pframe(&save_x, 28);
  sp_que(&save_x, -500);
  Playsound(61,22050,0,0,0);  
 
  wait(600);
 
  //change screens
  script_attach(1000);
  &player_map = 99;
  load_screen(99);
  draw_screen();  
  kill_this_task();  
}