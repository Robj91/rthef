//Numpad 'delete' key (DinkHD)

void main(void)
{
 &save_x = get_client_version();
 if (&save_x >= 199)
 {
  &keypressed = 46;
  
  //poke the puzzle control script
  &save_x = editor_seq(3, -1);
  &save_x = is_script_attached(&save_x);
  run_script_by_number(&save_x, "keys_extra");
 }

 kill_this_task();
}