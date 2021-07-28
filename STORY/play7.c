//script for screen 163

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
  
  move_stop