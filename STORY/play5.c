//Script for screen 99

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
  
  move_stop(&elev, 2, 500, 1);
  
  wait(2000);
 
  //change screens
  wait(1500);
  script_attach(1000);
  fade_down();
  &player_map = 131;
  load_screen(131);
  draw_screen();
  fade_up();
  kill_this_task();  
}