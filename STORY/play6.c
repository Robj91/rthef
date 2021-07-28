//Script for screen 131

void main(void)
{
 //make the current sprite invisible
 sp_nodraw(&current_sprite, 1); 
 
 int &numfive;

  //move hatch
  int &hatch = sp(57);
  sp_speed(&hatch, 2);
  sp_timing(&hatch, 20);
  playsound(75, 22052, 0, 0, 0);
  move(&hatch, 6, 532, 1);
  
  wait(700);
 
 //create transport
  int &elev = create_sprite(383, -100, 0, 855, 1);
  sp_pseq(&elev, 855);
  sp_pframe(&elev, 1);
  sp_speed(&elev, 10);
  sp_timing(&elev, 0);

 //make transport flash
  sp_frame_delay(&elev, 150);
  sp_brain(&elev, 6);
  sp_seq(&elev, 855);
  sp_sound(&elev, 68); 

  move_stop(&elev, 2, 500, 1);
  sp_x(&elev, 383);
  sp_y(&elev, 337);
  
  sp_brain(&elev, 0);
  sp_sound(&elev, 0);
  wait(1);
  sp_seq(&elev, 0);
  sp_pframe(&elev, 1);
  
  //change screens
  script_attach(1000);
  &player_map = 163;
  load_screen(163);
  draw_screen();
  kill_this_task();  
}    