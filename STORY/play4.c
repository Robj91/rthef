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
  sp_sound(&elev, 68);
  
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
 
  //change screens
  wait(1500);
  script_attach(1000);
  fade_down();
  &player_map = 99;
  load_screen(99);
  draw_screen();
  fade_up();
  kill_this_task();  
}