//Numpad 'delete' key (DinkHD)

void main(void)
{
 &save_x = get_client_version();
 if (&save_x >= 199)
 {
  //give a chance for wait_for_button to tell us ctrl is being pressed instead of delete
    //CTRL and DEL use the same keycode.. what the hell.
  wait(0);
  
  &save_x = sp_custom("cancel-del", 1, -1);
  if (&save_x == 1)
  {
   sp_custom("cancel-del", 1, 0);
   kill_this_task();
  }
  &keypressed = 46;
  
  //poke the puzzle control script
  &save_x = editor_seq(3, -1);
  &save_x = is_script_attached(&save_x);
  run_script_by_number(&save_x, "keys_extra");
 }

 kill_this_task();
}