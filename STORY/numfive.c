void main(void)
{
 int &spch;
}

void click(void)
{
 //stop mouse from interferring with choice menu
 sp_brain(1, 0);

 //cancel wait_for_button, so it doesn't interfere
 &save_x = editor_seq(3, -1);
 &save_x = sp_custom("but-script", &save_x, -1);
 run_script_by_number(&save_x, "pause");
 
 //create the speech bubble
 &save_x = sp_x(&current_sprite, -1);
 &save_y = sp_y(&current_sprite, -1);
 &save_x += 111;
 &save_y -= 65;
 &spch = create_sprite(&save_x, &save_y, 0, 150, 29);
 sp_pseq(&spch, 150);
 sp_pframe(&spch, 29);
 sp_que(&spch, 1000);
 Playsound(61,22050,0,0,0);
 wait(200);
 wait_for_button(); 
 
 sp_active(&spch, 0);

 //re-enable  wait_for_button
 &save_x = editor_seq(3, -1);
 &save_x = sp_custom("but-script", &save_x, -1);
 run_script_by_number(&save_x, "main");
   
 //re-enable normal mouse movement
 sp_brain(1, 13);
}