//screen sprite for puzzle 1 - screen 163

//editor sprite number variables for this screen:
//#1 - <=0 = intro has not finished playing
//       1 = intro has finished, puzzle unsolved
//       2 = puzzle solved
//
//#2 =       Text box sprite currently selected

//CUSTOM KEYS:
//tiptext - stores the tip text that appears when player clicks stuff wrong
//textbox - stores the textbox sprite (attached to editor_sprite 2)
//text_input - stores the typed letters
//letter - stores the letter number currently typed in a textbox
//delete - stores whether delete is toggled on or off

void main(void)
{
 editor_seq(3, &current_sprite);
 sp_nodraw(&current_sprite, 1);
}

void keys_letters(void)
{
 &save_x = editor_frame(3, -1);
 if (&save_x <= 0)
 {
  goto stopex;
 } 

 //make the chosen letter at the location
 //first check if no box selected
 &save_x = editor_seq(2, -1);
 if (&save_x <= 0)
 {
  //no textbox selected kill old text if still active and show new text
  &save_x = sp_custom("tip_text", &current_sprite, -1);
  &save_y = sp_custom("text_active", &save_x, -1);
  if (&save_y > 0)
  {
   sp_active(&save_x, 0);
  }
  say_xy("`%No space selected - click on the box you want to type in!", 10, 0);
  &save_x = &return;
  sp_custom("tip_text", &current_sprite, &save_x);
  sp_custom("text_active", &save_x, 1);
  goto stopex;
 } 
 
 //get the text box
 &save_y = editor_seq(2, -1);
 
 //check if it currently has text in it
 &save_x = sp_custom("text_input", &save_y, -1);
 if (&save_x > 0)
 {
  //kill old text before putting new text in
  sp_active(&save_x, 0);
  sp_custom("text-input", &save_y, 0);
 }
 
 //save &letter with the text box (in a custom key)
 sp_custom("letter", &save_y, &letter);
 
 &gjug1 = sp_x(&save_y, -1);
 &gjug2 = sp_y(&save_y, -1);
 &gjug1 -= 7;
 &gjug2 -= 20;
 external("keyboard", "make_letter", &letter, &gjug1, &gjug2);
 &save_x = &return;
 
 //save the active sprite of the letter with the text box
 sp_custom("text_input", &save_y, &save_x);
 sp_kill(&save_x, 0);
 
 //select the next text box and de-select the current one.
 next_box();
 &save_y = &return;
 if (&save_y == 0)
 {
  //next box wasn't foud - that means this is the last box, just de-select it
  sp_pframe(&save_x, 2);  
  editor_seq(2, 0); 
  
  if (&keyboard == 1)
  {
   //re-enable mouse mode
   sp_brain(1, 13);
   sp_nodraw(1, 0);
  }   
 }
}

void keys_extra(void)
{
 &save_x = editor_frame(3, -1);
 if (&save_x <= 0)
 {
  goto stopex;
 } 

 //first check if they pressed the backspace key
 if (&keypressed == 14)
 {
  //Left arrow was pressed
  &save_x = editor_seq(2, -1);
  if (&save_x <= 0)
  {
   //no textbox selected kill old text if still active and show new text
   &save_x = sp_custom("tip_text", &current_sprite, -1);
   &save_y = sp_custom("text_active", &save_x, -1);
   if (&save_y > 0)
   {
    sp_active(&save_x, 0);
   }
   say_xy("`%No space selected - click a box to select it", 10, 0);
   &save_x = &return;
   sp_custom("tip_text", &current_sprite, &save_x);
   sp_custom("text_active", &save_x, 1);
  } 
  else
  {
   //select the previous text box, and de-select the current one.
   prior_box();
   &save_x = &return;
   
   //check if delete is active and if so, delete the text
   if (&save_x > 0)
   {
    &save_y = sp_custom("delete", &current_sprite, -1);
    if (&save_y == 1)
    {
     &save_y = sp_custom("text_input", &save_x, -1);
     if (&save_y > 0)
     {
      sp_active(&save_y, 0);
      sp_custom("text_input", &save_x, 0);
     }
    }
   }
  }
 }
 if (&keypressed == 16)
 {
  //right arrow was pressed
  &save_x = editor_seq(2, -1);
  if (&save_x <= 0)
  {
   //no textbox selected kill old text if still active and show new text
   &save_x = sp_custom("tip_text", &current_sprite, -1);
   &save_y = sp_custom("text_active", &save_x, -1);
   if (&save_y > 0)
   {
    sp_active(&save_x, 0);
   }
   say_xy("`%No space selected - click a box to select it", 10, 0);
   &save_x = &return;
   sp_custom("tip_text", &current_sprite, &save_x);
   sp_custom("text_active", &save_x, 1);
  } 
  else
  {
   //select the next text box and de-select the current one.
   next_box();
   &save_x = &return;
   
   //check if delete is active and if so, delete the text
   if (&save_x > 0)
   {
    &save_y = sp_custom("delete", &current_sprite, -1);
    if (&save_y == 1)
    {
     &save_y = sp_custom("text_input", &save_x, -1);
     if (&save_y > 0)
     {
      sp_active(&save_y, 0);
      sp_custom("text_input", &save_x, 0);
     }
    }
   }
  }
 }
 if (&keypressed == 46)
 {
  //'delete' key was pressed - toggle deleting when moving text boxes
  //delete old 'tip text' if it's active
  &save_x = sp_custom("tip_text", &current_sprite, -1);
  &save_y = sp_custom("text_active", &save_x, -1);
  if (&save_y > 0)
  {
   sp_active(&save_x, 0);
  }

  //toggle delete
  &save_x = sp_custom("delete", &current_sprite, -1);
  if (&save_x <= 0)
  {
   say_xy("`%Delete is now turned ON. Left or Right arrow will delete text.", 10, 0);
   &save_x = &return;
   sp_custom("tip_text", &current_sprite, &save_x);
   sp_custom("text_active", &save_x, 1);
   sp_custom("delete", &current_sprite, 1);
  }
  else
  {
   say_xy("`%Delete is now turned OFF. Left or Right arrow will not delete text.", 10, 0);
   &save_x = &return;
   sp_custom("tip_text", &current_sprite, &save_x);
   sp_custom("text_active", &save_x, 1);
   sp_custom("delete", &current_sprite, 0);
  }
 }
 
 goto stopex;
}

void prior_box(void)
{
 //select the previous text box, and de-select the current one.
 &save_x = editor_seq(2, -1);
 &save_y = sp_custom("textbox", &save_x, -1);
 &save_y -= 1;
 &gjug1 = 0;
get_prior_box:
 &gjug1 = get_next_sprite_with_this_brain(0, 0, &gjug1);
 if (&gjug1 > 0)
 {
  &gjug2 = sp_custom("textbox", &gjug1, -1);
  if (&gjug2 == &save_y)
  {
   &gjug2 = is_script_attached(&gjug1);
   if (&gjug2 > 0)
   {
    run_script_by_number(&gjug2, "click"); 
    return(&gjug1); 
    goto stopex;
   }
  }
  &gjug1 += 1;
  goto get_prior_box;
 } 
 
 return(0);
}

void next_box(void)
{
  //select the next text box and de-select the current one.
  &save_x = editor_seq(2, -1);
  &save_y = sp_custom("textbox", &save_x, -1);
  &save_y += 1;
  &gjug1 = 0;
 get_next_box:
  &gjug1 = get_next_sprite_with_this_brain(0, 0, &gjug1);
  if (&gjug1 > 0)
  {
   &gjug2 = sp_custom("textbox", &gjug1, -1);
   if (&gjug2 == &save_y)
   {
    &gjug2 = is_script_attached(&gjug1);
    if (&gjug2 > 0)
    {
     run_script_by_number(&gjug2, "click");
     return(&gjug1);
     goto stopex;
    }
   }
   &gjug1 += 1;
   goto get_next_box;
  }
 
 return(0);
}

void stopex(void)
{
stopex:
 return;
}