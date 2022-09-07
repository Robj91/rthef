void main(void)
{
 sp_nodraw(&current_sprite, 1);
 sp_nohit(&current_sprite, 1);
 sp_touch_damage(&current_sprite, -1);
}

void touch(void)
{
 sp_touch_damage(&current_sprite, 0);
 say("What's with these walls.. URGH!", 1);
 wait(2000);
 &save_x = sp_x(&current_sprite, -1);
 if (&save_x < 314)
 {
  editor_frame(1, 1);
 }
 else
 {
  editor_frame(2, 1);  
 }
 sp_active(&current_sprite, 0);
 kill_this_task();
}