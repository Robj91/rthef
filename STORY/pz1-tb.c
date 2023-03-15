//text boxes on screen 163

//CUSTOM KEYS:
//km_mode_text: stores the text sprite tip for entering keyboard mode

void main(void)
{
 //check if a letter should be placed in this box on creation
 &gjug5 = sp_custom("textbox", &current_sprite, -1);
 &gjug5 /= 3;
 &gjug5 += 4;
 &gjug5 = editor_seq(&gjug5, -1);
 if (&gjug5 > 0)
 {
  wait(0);
  //there is a value stored in the editor_sprite mapped to this text box for storing the letter value
  //run the svar_extract to see if a letter sohuld be created
  external("pz1-sh", "lett_get_edin", &current_sprite);
  &gjug5 = &return;
  
  //now make the letter
  &gjug3 = sp_x(&current_sprite, -1);
  &gjug4 = sp_y(&current_sprite, -1);
  external("keyboard", "make_letter", &gjug5, &gjug3, &gjug4);
  &gjug5 = &return;

  sp_size(&gjug5, 65);
  &gjug3 = sp_x(&gjug5, -1);
  sp_x(&gjug5, &gjug3);  

  //save the active sprite of the letter with the text box
  sp_custom("text_input", &current_sprite, &gjug5);
 }
 goto stopex;
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
   &gjug5 = sp_custom("text_active", &save_x, -1);
   if (&gjug5 > 0)
   {
    sp_active(&save_y, 0);  
   }
   &gjug5 = say_xy("`%Keyboard mode active. Press `ESC` to go back to mouse mode.", 12, 360);
   &save_x = editor_seq(3, -1);
   sp_custom("km_mode_text", &save_x, &gjug5);
   sp_custom("text_active", &gjug5, 1);
  }
 }

 //get any currently selected text box sprite
 &save_x = editor_seq(2, -1);
 if (&save_x == &current_sprite)
 {
  //don't do anything - player clicked on already selected box
  return;
 }
 
 //revert the previously selected box
 sp_pframe(&save_x, 2);
 
 //select the new one
 sp_pframe(&current_sprite, 3);
 editor_seq(2, &current_sprite);
}

void stopex(void)
{
 stopex:
  return;
}