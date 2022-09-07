void main(void)
{
 sp_nodraw(&current_sprite, 1);
 sp_nohit(&current_sprite, 1);
 sp_touch_damage(&current_sprite, -1);
}

void touch(void)
{
 sp_touch_damage(&current_sprite, 0);
 say("I can't walk any further.. but it appears nothing is blocking my way.. what the hell?", 1);
 wait(2000);
 int &hold = sp_editor_num(&current_sprite);
 editor_type(&hold, 1);
 sp_active(&current_sprite, 0);
 kill_this_task();
}