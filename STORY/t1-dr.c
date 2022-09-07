void main(void)
{
 editor_type(1, 0);

 &save_x = editor_frame(1, -1);
 if (&save_x == 0)
 {
  sp_touch_damage(&current_sprite, -1);
 }
}

void touch(void)
{
 sp_touch_damage(&current_sprite, 0);
 say("Hmmm... I can't enter.", 1);
 wait(2000);
 editor_type(1, 0);
 editor_frame(1, 1);
}