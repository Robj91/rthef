void main(void)
{
 int &val1;
}

void click(void)
{
 //undo mouse mode and enable keystrokes
 sp_brain(1, 1);
 
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