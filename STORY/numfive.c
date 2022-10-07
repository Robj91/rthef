void click(void)
{
 //stop mouse from interferring with choice menu
 sp_brain(1, 0);

 //cancel wait_for_button, so it doesn't interfere
 &save_x = editor_seq(3, -1);
 &save_x = sp_custom("but-script", &save_x, -1);
 run_script_by_number(&save_x, "pause");
 
 //create the speech bubble
 
}