void main(void)
{
 //this is a status bar button
 sp_custom("stat_but", &current_sprite, 1);
}

void click(void)
{
 //stop mouse from interferring with choice menu
 sp_brain(1, 0);
 
 //cancel wait_for_button, so it doesn't interfere with choice menu
 &save_x = editor_seq(3, -1);
 &save_x = sp_custom("but-script", &save_x, -1);
 run_script_by_number(&save_x, "pause");
 
 if (&player_map == 163)
 {
  choice_start();
  set_title_color 15
  set_y 240
  title_start();
  Locate the clues found in both this puzzle, and Dinks world, and then enter the correct words.
  You can switch between Dinks World and Inside the System in the menu, accessed by clicking the
  Help/info button.
  title_end();
  "Return to game"
  choice_end();
 }

 //re-enable  wait_for_button
 &save_x = editor_seq(3, -1);
 &save_x = sp_custom("but-script", &save_x, -1);
 run_script_by_number(&save_x, "main");

 //re-enable normal mouse movement
 sp_brain(1, 13);
}