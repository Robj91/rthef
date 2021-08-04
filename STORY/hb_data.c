//SCRIPT CURRENTLY NOT IN USE

//hardbox information for sprites needed for other scripts
//hardbox info taken directly from dink.ini.

//sprite that will have custom keys attached will be &arg1, or &current_sprite if no sprite passed(0).
//pass sequence and frame of sprite as &arg2 and &arg3.
//pass x position of sprite in &arg4
//pass y position of sprite in &arg5

//current position of left, top, right and bottom hardbox edges will be returned in custom keys
//"hb_left" = left
//"hb_top" = top
//"hb_right" = right
//"hb_bottom" = bottom

void get_hb_val(void)
{
 if (&arg1 <= 0)
 {
  &save_x = &current_sprite;
 }
 else
 {
  &save_x = &arg1;
 }

 int &val1;
 int &val2;
 int &val3;
 int &val4;

 //////////////////////////////////////
 //save hardbox values in custom keys//
 //////////////////////////////////////
 if (&arg2 == 98)
 { 
  if (&arg3 == 5)
  {
   sp_custom("hb_l", &save_x, -85);
   sp_custom("hb_t", &save_x, -20);
   sp_custom("hb_r", &save_x, 89);
   sp_custom("hb_b", &save_x, 24);
  }
  if (&arg3 == 6)
  {
   sp_custom("hb_l", &save_x, -64);
   sp_custom("hb_t", &save_x, -20);
   sp_custom("hb_r", &save_x, 67);
   sp_custom("hb_b", &save_x, 20);
  }
 }
 if (&arg2 == 35)
 {
  if (&arg3 == 1)
  {
   sp_custom("hb_l", &save_x, -26);
   sp_custom("hb_t", &save_x, -35);
   sp_custom("hb_r", &save_x, 8);
   sp_custom("hb_b", &save_x, 7);
  }
  if (&arg3 == 2)
  {
   sp_custom("hb_l", &save_x, -17);
   sp_custom("hb_t", &save_x, -25);
   sp_custom("hb_r", &save_x, 5);
   sp_custom("hb_b", &save_x, 4);
  }
 }
 if (&arg2 == 36)
 {
  if (&arg3 == 1)
  {
   sp_custom("hb_l", &save_x, -71);
   sp_custom("hb_t", &save_x, -21);
   sp_custom("hb_r", &save_x, 74);
   sp_custom("hb_b", &save_x, 22);
  }
 }
 
 //store hardbox values in variables
 &val1 = sp_custom("hb_l", &save_x, -1);
 &val2 = sp_custom("hb_t", &save_x, -1);
 &val3 = sp_custom("hb_r", &save_x, -1);
 &val4 = sp_custom("hb_b", &save_x, -1);
 
 //current position of left boundary
 &save_y = sp_custom("hb_l", &current_sprite, -1);
 &save_y += &arg4; 
 sp_custom("hb_left", &current_sprite, &save_y);
 
 //current position of top boundary
 &save_y = sp_custom("hb_t", &current_sprite, -1);
 &save_y += &arg5; 
 sp_custom("hb_top", &current_sprite, &save_y);
 
 //current position of right boundary
  //(taking into account the -1 discrepency for right hardbox edge in the Dink Engine)
 &save_y = sp_custom("hb_r", &current_sprite, -1);
 &save_y += &arg4; 
 &save_y -= 1;
 sp_custom("hb_tight", &current_sprite, &save_y);
 
 //current position of bottom boundary
  //(taking into account the -1 discrepency for bottom hardbox edge in the Dink Engine)
 &save_y = sp_custom("hb_b", &current_sprite, -1);
 &save_y += &arg5; 
 &save_y -= 1;
 sp_custom("hb_bottom", &current_sprite, &save_y);
 
 kill_this_task();
}