void main(void)
{
 sp_nodraw(&current_sprite, 1);
 sp_nohit(&current_sprite, 1);
 sp_touch_damage(&current_sprite, -1);
}

void touch(void)
{
 sp_touch_damage(&current_sprite, 0);
 say("Why can't I walk through here? ... There's nothing in my way!", 1);
 wait(2000);
 int &hold = sp_editor_num(&current_sprite);
 editor_type(&hold, 1);
 sp_active(&current_sprite, 0);
 kill_this_task();
}