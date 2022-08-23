//text boxes on screen 163

//CUSTOM KEYS:
//km_mode_text: stores the text sprite tip for entering keyboard mode

void main(void)
{
 int &val1;
}

void click(void)
{
 if (&keyboard == 1)
 {
  //exit mouse mode if keyboard is in use
  &save_x = sp_brain(1, -1);
  if (&save_x > 1)
  {
   set_dink_speed(-1);
   sp_brain(1, 1);
   sp_nodraw(1, 1);
   
   //kill any old text and create new stuff
   &save_x = editor_seq(3, -1);
   &save_y = sp_custom("km_mode_text", &save_x, -1);
   &val1 = sp_custom("text_active", &save_x, -1);
   if (&val1 > 0)
   {
    sp_active(&save_y, 0);  
   }
   &val1 = say_xy("`%Keyboard mode active. Press `ESC` to go back to mouse mode.", 12, 360);
   &save_x = editor_seq(3, -1);
   sp_custom("km_mode_text", &save_x, &val1);
   sp_custom("text_active", &val1, 1);
  }
 }

 //get any currently selected text box sprite
 &save_x = editor_seq(2, -1);
 if (&save_x == &current_sprite)
 {
  say("ok", 1);
  //don't do anything - player clicked on already selected box
  return;
 }
 
 //revert the previously selected box
 sp_pframe(&save_x, 2);
 
 //select the new one
 sp_pframe(&current_sprite, 3);
 editor_seq(2, &current_sprite);
}