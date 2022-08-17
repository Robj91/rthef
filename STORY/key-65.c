//A

void main(void)
{
 &letter = 1;

 //poke the puzzle control script
 &save_x = editor_seq(3, -1);
 &save_x = is_script_attached(&save_x);
 run_script_by_number(&save_x, "keys_letters");
 kill_this_task();
}