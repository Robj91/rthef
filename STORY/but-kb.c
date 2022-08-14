void click(void)
{
  //disable numbers for now
  sp_custom("disable_num", &current_sprite, 1);
  
  //disable touch damage on keyboard icon and handle that with position of cursor, with on-screen keyboard
  sp_touch_damage(&current_sprite, 0);
  
  &save_x = create_sprite(308, 407, 0, 98, 7);
  sp_noclip(&save_x, 1);
  sp_que(&save_x, 1001);
  sp_custom("keyboard", &current_sprite, &save_x);  
  sp_custom("but-kb", &save_x, &current_sprite);
  sp_touch_damage(&save_x, -1);
  sp_script(&save_x, "keyboard");
}