void main(void)
{
 sp_hard(&current_sprite, 0);
 sp_nodraw(&current_sprite, 1);
 sp_nohit(&current_sprite, 1);
 sp_touch_damage(&current_sprite, -1);
 draw_hard_map();
}

void touch(void)
{
 sp_touch_damage(&current_sprite, 0);
 say("There's just invisible blockades everywhere.. this is a mess!", 1);
 wait(2000);
 editor_frame(3, 1);
 sp_active(&current_sprite, 0);
 kill_this_task();
}