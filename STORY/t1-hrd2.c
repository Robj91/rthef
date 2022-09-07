void main(void)
{
 sp_nodraw(&current_sprite, 1);
 sp_nohit(&current_sprite, 1);
 sp_touch_damage(&current_sprite, -1);
}

void touch(void)
{
 sp_touch_damage(&current_sprite, 0);
 say("Why can't I walk any further? Nothing in my way..", 1);
 wait(2000);
 &save_x = sp_pframe(&current_sprite, -1);
 if (&save_x == 7)
 {
  editor_frame(4, 1);
 }
 if (&save_x == 8)
 {
  &save_x = sp_x(&current_sprite, -1);
  if (&save_x < 309)
  {
   editor_frame(5, 1);
  }
  else
  {
   editor_frame(6, 1);
  }
 }
 sp_active(&current_sprite, 0);
 kill_this_task();
}