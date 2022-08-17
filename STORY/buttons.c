//wait for buttons

void main(void)
{
loop:
 wait_for_button();
 &keypressed = &result;
 
 if (&result == 5)
 {
  //ESCAPE key
  //de-select text box
  &save_x = editor_seq(2, -1);  
  sp_pframe(&save_x, 2);
  editor_seq(2, 0);
 
  if (&keyboard == 1)
  {
   //re-enter mouse mode
   sp_brain(1, 13);
   sp_nodraw(1, 0);
  }
 }
 if (&result == 6)
 {
  if (&keyboard == 1)
  {
   //LETTER 'M'
   &letter = 13;
  
   //poke the puzzle control script
   &save_x = editor_seq(3, -1);
   &save_x = is_script_attached(&save_x);
   run_script_by_number(&save_x, "keys_letters");
  }
 }
 if (&result == 12)
 {
  //DOWN ARROW
  //poke the puzzle control script
  &save_x = editor_seq(3, -1);
  &save_x = is_script_attached(&save_x);
  run_script_by_number(&save_x, "keys_extra");
 }
 if (&result == 14)
 {
  //LEFT ARROW
  //poke the puzzle control script
  &save_x = editor_seq(3, -1);
  &save_x = is_script_attached(&save_x);
  run_script_by_number(&save_x, "keys_extra");
 }
 if (&result == 16)
 {
  //RIGHT ARROW
  //poke the puzzle control script
  &save_x = editor_seq(3, -1);
  &save_x = is_script_attached(&save_x);
  run_script_by_number(&save_x, "keys_extra");
 }
 if (&result == 18)
 {
  //UP ARROW
  //poke the puzzle control script
  &save_x = editor_seq(3, -1);
  &save_x = is_script_attached(&save_x);
  run_script_by_number(&save_x, "keys_extra");
 }
 
 &keypressed = 0;
 goto loop;
}