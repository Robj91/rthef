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
  
  move_stop(&elev, 2, 500, 1);
 
  //change screens
  script_attach(1000);
  &player_map = 131;
  load_screen(131);
  draw_screen();
  kill_this_task();  
}