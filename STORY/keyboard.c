//sscript for on screen keyboard in status area
//one big button, with inside box checks for the individual keys

void main(void)
{
 int &val1;
 int &val2;
 int &val3;
 int &val4;
 
 int &letter;
 
 &save_x = sp_custom("disable_num", &current_sprite, -1);
 if (&save_x > 0)
 {
  //this puzzle doesn't need numbers - cover them up with black
  
 }
}

void click(void)
{
 //get the cursor location
 &save_x = sp_x(1, -1);
 &save_y = sp_y(1, -1);

 //first check if they clicked on the keyboard icon
 //get keyboard icon location
 &val1 = sp_custom("but-kb", &current_sprite, -1);
 &gjug1 = sp_x(&val1, -1);
 &gjug2 = sp_y(&val1, -1);
 &val1 = &gjug1;
 &val1 -= 13;
 &val2 = &gjug2;
 &val2 -= 32;
 &val3 = &gjug1;
 &val3 += 8;
 &val4 = &gjug2;
 &val4 += 10;
 &save_x = inside_box(&save_x, &save_y, &val1, &val2, &val3, &val4);
 if (&save_x > 0)
 {
  &val1 = sp_custom("but-kb", &current_sprite, -1);
  sp_touch_damage(&val1, -1);
  sp_active(&current_sprite, 0);
  kill_this_task();
 }

 //let's try to automate the inside_box thingy with the letters, rather than checking each letter manually

 &save_x = editor_seq(2, -1);
 if (&save_x <= 0)
 {
  //no textbox selected
  say_xy("`%No space selected - click on the box you want to type in!", 10, 0);
  goto stopex;
 }

 //get on-screen keyboard sprite position
 &gjug1 = sp_x(&current_sprite, -1);
 &gjug2 = sp_y(&current_sprite, -1);

 //check backspace first
 //define inside box for backspace
 &val1 = &gjug1;
 &val1 += 120;
 
 //top
 &val2 = &gjug2;
 &val2 -= 3;
 
 //right
 &val3 = &gjug1;
 &val3 += 153;
 
 //bottom
 &val4 = &gjug2;
 &val4 += 17; 

 //check if the cursor is on the backspace key
 &save_x = sp_x(1, -1);
 &save_y = sp_y(1, -1);
 &save_x = inside_box(&save_x, &save_y, &val1, &val2, &val3, &val4); 
 if (&save_x > 0)
 {
  //select the previous text box, and de-select the current oneone.
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
     
     //now kill off the text in the newly selected box
     &save_x = editor_seq(2, -1);  
     &save_y = sp_custom("text_input", &save_x, -1);
     if (&save_y > 0)
     {
      sp_active(&save_y, 0);
      sp_custom("text_input", &save_x, 0);
     }   
     goto stopex;
    }
   }
   &gjug1 += 1;
   goto get_prior_box;
  }  
  
  //no previous box found - do nothing
  goto stopex;
 }
 
 //start at letter 1 (which is Q - top left letter on keyboard)
 &letter = 1;
 
 //define inside box for first letter[Q] (left, top, right, bottom)
 //left
 &val1 = &gjug1;
 &val1 -= 300;
 
 //top
 &val2 = &gjug2;
 &val2 -= 3;
 
 //right
 &val3 = &gjug1;
 &val3 -= 267;
 
 //bottom
 &val4 = &gjug2;
 &val4 += 17;

check_letter: 
 &save_x = sp_x(1, -1);
 &save_y = sp_y(1, -1);
 &save_x = inside_box(&save_x, &save_y, &val1, &val2, &val3, &val4);
 if (&save_x > 0)
 {
  //convert &letter to 1=A, 2=B, 3=C, etc.
  external("keyboard", "convert", &letter);
  &save_x = &return;

  //save which letter has been chosen, with the text box
  sp_custom("letter", &save_y, &save_x);
  
  //make the chosen letter at the location
  &save_y = editor_seq(2, -1);
  &gjug1 = sp_x(&save_y, -1);
  &gjug2 = sp_y(&save_y, -1);
  &gjug1 -= 7;
  &gjug2 -= 20;
  external("keyboard", "make_letter", &save_x, &gjug1, &gjug2);
  &save_x = &return;
  
  //save the active sprite of the letter with the text box
  sp_custom("text_input", &save_y, &save_x);
  sp_kill(&save_x, 0);
  
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
     goto stopex;
    }
   }
   &gjug1 += 1;
   goto get_next_box;
  }
  
  //next box wasn't foud - that means this is the last box, just de-select it
  sp_pframe(&save_x, 2);  
  editor_seq(2, 0);  
  
  goto stopex;
 }
 else
 {
  //increment to check next letter
  if (&letter == 10)
  {
   &val1 = &gjug1;
   &val1 -= 280;
   &val2 += 26;
   &val3 = &gjug1;
   &val3 -= 247;
   &val4 += 26;
   &letter += 1;
   goto check_letter;
  }
  if (&letter == 19)
  {
   &val1 = &gjug1;
   &val1 -= 247;
   &val2 += 26;
   &val3 = &gjug1;
   &val3 -= 214;
   &val4 += 26;
   &letter += 1;
   goto check_letter;
  }
  
  if (&letter < 26)
  {
   &val1 += 42;
   &val3 += 42;
   
   &letter += 1; 
   goto check_letter;
  }
 }
 
 goto stopex;
}

void convert(void)
{
 //convert qwerty to normal based on &arg1
 if (&arg1 == 1) return(17);
 if (&arg1 == 2) return(23);
 if (&arg1 == 3) return(5);
 if (&arg1 == 4) return(18);
 if (&arg1 == 5) return(20);
 if (&arg1 == 6) return(25);
 if (&arg1 == 7) return(21);
 if (&arg1 == 8) return(9);
 if (&arg1 == 9) return(15);
 if (&arg1 == 10) return(16);
 if (&arg1 == 11) return(1);
 if (&arg1 == 12) return(19);
 if (&arg1 == 13) return(4);
 if (&arg1 == 14) return(6);
 if (&arg1 == 15) return(7);
 if (&arg1 == 16) return(8);
 if (&arg1 == 17) return(10);
 if (&arg1 == 18) return(11);
 if (&arg1 == 19) return(12);
 if (&arg1 == 20) return(26);
 if (&arg1 == 21) return(24);
 if (&arg1 == 22) return(3);
 if (&arg1 == 23) return(22);
 if (&arg1 == 24) return(2);
 if (&arg1 == 25) return(14);
 if (&arg1 == 26) return(13);
}

void make_letter(void)
{
 //create a letter using say_xy, based on &arg1, at x=&arg2, y=&arg3, in colour &arg4, or white if no value passed to &arg2
 //pass 10 to arg2 for bold green(it's usually 0)
 //the 309 x difference for say_xy is factored in here, so pass ACTUAL position for the text to be at
 
 int &txtclr;
 int &x = &arg2;
 &x -= 309;
 
 if (&arg2 > 0)
 {
  &txtclr = &arg4;
 }
 else
 {
  &txtclr = 0;
 }
 
 if (&txtclr == 0)
 {
  //WHITE
  if (&arg1 == 1) say_xy("`%A", &x, &arg3);
  if (&arg1 == 2) say_xy("`%B", &x, &arg3);
  if (&arg1 == 3) say_xy("`%C", &x, &arg3);
  if (&arg1 == 4) say_xy("`%D", &x, &arg3);
  if (&arg1 == 5) say_xy("`%E", &x, &arg3);
  if (&arg1 == 6) say_xy("`%F", &x, &arg3);
  if (&arg1 == 7) say_xy("`%G", &x, &arg3);
  if (&arg1 == 8) say_xy("`%H", &x, &arg3);
  if (&arg1 == 9) say_xy("`%I", &x, &arg3);
  if (&arg1 == 10) say_xy("`%J", &x, &arg3);
  if (&arg1 == 11) say_xy("`%K", &x, &arg3);
  if (&arg1 == 12) say_xy("`%L", &x, &arg3);
  if (&arg1 == 13) say_xy("`%M", &x, &arg3);
  if (&arg1 == 14) say_xy("`%N", &x, &arg3);
  if (&arg1 == 15) say_xy("`%O", &x, &arg3);
  if (&arg1 == 16) say_xy("`%P", &x, &arg3);
  if (&arg1 == 17) say_xy("`%Q", &x, &arg3);
  if (&arg1 == 18) say_xy("`%R", &x, &arg3);
  if (&arg1 == 19) say_xy("`%S", &x, &arg3);
  if (&arg1 == 20) say_xy("`%T", &x, &arg3);
  if (&arg1 == 21) say_xy("`%U", &x, &arg3);
  if (&arg1 == 22) say_xy("`%V", &x, &arg3);
  if (&arg1 == 23) say_xy("`%W", &x, &arg3);
  if (&arg1 == 24) say_xy("`%X", &x, &arg3);
  if (&arg1 == 25) say_xy("`%Y", &x, &arg3);
  if (&arg1 == 26) say_xy("`%Z", &x, &arg3);
 }
 else
 {
  //CUSTOM COLOUR (using (&arg4)
  if (&arg1 == 1) say_xy("`&txtclrA", &x, &arg3);
  if (&arg1 == 2) say_xy("`&txtclrB", &x, &arg3);
  if (&arg1 == 3) say_xy("`&txtclrC", &x, &arg3);
  if (&arg1 == 4) say_xy("`&txtclrD", &x, &arg3);
  if (&arg1 == 5) say_xy("`&txtclrE", &x, &arg3);
  if (&arg1 == 6) say_xy("`&txtclrF", &x, &arg3);
  if (&arg1 == 7) say_xy("`&txtclrG", &x, &arg3);
  if (&arg1 == 8) say_xy("`&txtclrH", &x, &arg3);
  if (&arg1 == 9) say_xy("`&txtclrI", &x, &arg3);
  if (&arg1 == 10) say_xy("`&txtclrJ", &x, &arg3);
  if (&arg1 == 11) say_xy("`&txtclrK", &x, &arg3);
  if (&arg1 == 12) say_xy("`&txtclrL", &x, &arg3);
  if (&arg1 == 13) say_xy("`&txtclrM", &x, &arg3);
  if (&arg1 == 14) say_xy("`&txtclrN", &x, &arg3);
  if (&arg1 == 15) say_xy("`&txtclrO", &x, &arg3);
  if (&arg1 == 16) say_xy("`&txtclrP", &x, &arg3);
  if (&arg1 == 17) say_xy("`&txtclrQ", &x, &arg3);
  if (&arg1 == 18) say_xy("`&txtclrR", &x, &arg3);
  if (&arg1 == 19) say_xy("`&txtclrS", &x, &arg3);
  if (&arg1 == 20) say_xy("`&txtclrT", &x, &arg3);
  if (&arg1 == 21) say_xy("`&txtclrU", &x, &arg3);
  if (&arg1 == 22) say_xy("`&txtclrV", &x, &arg3);
  if (&arg1 == 23) say_xy("`&txtclrW", &x, &arg3);
  if (&arg1 == 24) say_xy("`&txtclrX", &x, &arg3);
  if (&arg1 == 25) say_xy("`&txtclrY", &x, &arg3);
  if (&arg1 == 26) say_xy("`&txtclrZ", &x, &arg3); 
 }
 
 return(&last_text);
}

void stopex(void)
{
stopex:
 return;
}