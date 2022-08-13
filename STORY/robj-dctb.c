//ROBJ'S Attempt at a somewhat automated text box//
//Specifically for custom text box layouts using say_xy.
//how to use:
// >> https://docs.google.com/document/d/1HnBFtS5ztK5KK3PRUXGLIKKqsRNqr7nxuC16HVbS7xk/edit?usp=sharing

//Obviously some stuff still has to be passed to the procedure - there's no way in DinkC to retrieve the width of text.
//So text box width must be specified. Height is handled automatically.
//For say_xy and say_stop_xy, it takes the y position of the bottom and top line and finds the midpoint (

//I created a pixel counter for Dink text, it will be accurate most of the time if the font is not changed in game with initfont()
//It takes the individual pixel measurement of every character of size 12 Liberations Sans Regular, which is the default FreeDink font,
//and adds them together. The reason it might be off by a few pixels sometimes is because it does not take into account kerning
//(variance in letter spacing for specific letters used in pairs).

//If it ends up ever messing up because of being slightly off, you can just do a slight manual adjustement when you see that when you test your dmod.
//Here's the URL:
// >> https://docs.google.com/spreadsheets/d/192OoGll9GiUeYm4wG95mlTcFZ4wP93fyfn9XiYotToE/edit?usp=sharing

void text_box_start(void)
{
  //text box initialisation
  //&arg1 = X position of first text sprite (this will be the top most text in the textbox)
  //&arg2 = Y position of first text sprite (this will be the top most text in the textbox)
  //&arg3 = Custom sequence for text box background
  //&arg4 = Custom frame for text box background
  //&arg5 = custom text box border sequence
  //&arg6 = custom text box border start frame (input frame of BOTTOM border sprite, will use next frame for Right, then next for top, then next for left)
  //&arg7 = borderless
  //&arg8 = Allow multiple text boxes to exist for active sprites (if &current_sprite > 0 old text box will not be killed off before creating another one)
  
  //local var needed
  int &val2;
  
  //check if text box already exists
  if (&arg8 <= 0)
  {
    &save_x = sp_custom("TB_make_limit", &current_sprite, -1);
    if (&save_x > 0)
    {
      //make sure it's not just another sprite that took that sprite number
      &save_y = sp_custom("TB_make_limit", &save_x, -1);
      if (&save_y == &current_sprite)
      {
        //confirmed - first check if it's running a halt proc already
        &save_y = sp_custom("tb_halt_snum", &save_x, -1);
        if (&save_y > 0)
        {
          //it is - check if it spawned a script
          &val2 = sp_custom("TB_halt_spawned", &save_x, -1);
          if (&val2 > 0)
          {
            //it has - kill that off
            run_script_by_number(&val2, "killscript");
          }
          
          //kill off halt script instance
          run_script_by_number(&save_y, "killscript");
        }
        
        //kill off the old text box
        &save_x = sp_custom("TB_make_limit", &current_sprite, -1);
        &save_x *= 1000;
        external("robj-dctb", "text_box_end", &save_x);
      }
    }
  }
  
  //set the default normal space between lines of text
  &save_x = 23;
  
  //set the default large space between lines of text
  &save_y = 33;
  
  //get x position of first line of text, don't worry about y position here
  &val2 = &arg1;
  &val2 -= 309;
  
  text_box_blank(&arg1, 0, 600, 400, &val2, &arg2, &save_x, &save_y, 1);
  &save_x = &return;
  
  //save the current player map in a custom key attached to the text box
  &save_y = &player_map;
  sp_custom("TB_pmap", &save_x, &save_y);
  
  //If this script is attached to a sprite, we should limit text boxes to 1 at a time
  //unless the author has chosen not to, we check &arg8 for that.
  if (&arg8 <= 0)
  {
    if (&current_sprite > 0)
    {
      //limit to one text box.
      sp_custom("TB_make_limit", &current_sprite, &save_x);
      sp_custom("TB_make_limit", &save_x, &current_sprite);
    }
  }
  
  //now that the textbox is created we can set a couple of additional custom keys on it
  if (&arg4 <= 0)
  {
    sp_custom("tb_do_char_length", &save_x, &arg3);
  }
  else
  {
    sp_custom("tb_do_pixel_length", &save_x, &arg4);
  }
  
  //save textbox x position
  if (&arg1 == -1)
  {
    sp_custom("textbox_pos_x", &save_x, 0);
  }
  else
  {
    sp_custom("textbox_pos_x", &save_x, &arg1);
  }
  
  //custom seq and frame of textbox background
  if (&arg3 > 0)
  {
    sp_custom("tb_bg_seq", &save_x, &arg3);
    sp_pseq(&save_x, &arg3);
  }
  if (&arg4 > 0)
  {
    sp_custom("tb_bg_frame", &save_x, &arg4);
    sp_pframe(&save_x, &arg4);
  }
  
  //borderless
  if (&arg7 > 0)
  {
    &save_y = sp_custom("tb_border-bottom", &save_x, -1);
    sp_active(&save_y, 0);
    &save_y = sp_custom("tb_border-right", &save_x, -1);
    sp_active(&save_y, 0);
    &save_y = sp_custom("tb_border-top", &save_x, -1);
    sp_active(&save_y, 0);
    &save_y = sp_custom("tb_border-left", &save_x, -1);
    sp_active(&save_y, 0);
    
    sp_custom("tb_border-bottom", &save_x, 0);
    sp_custom("tb_border-right", &save_x, 0);
    sp_custom("tb_border-top", &save_x, 0);
    sp_custom("tb_border-left", &save_x, 0);
    
    //save borderless specification in custom key
    sp_custom("tb_nobd", &save_x, 1);
  }
  
  //custom seq and frame of textbox border
  if (&arg5 > 0)
  {
    if (&arg6 > 0)
    {
      &save_y = sp_custom("tb_nobd", &save_x, -1);
      if (&save_y <= 0)
      {
        &val2 = &arg6;
        &save_y = sp_custom("tb_border-bottom", &save_x, -1);
        sp_pseq(&save_y, &arg5);
        sp_pframe(&save_y, &val2);
        &val2 += 1;
        &save_y = sp_custom("tb_border-right", &save_x, -1);
        sp_pseq(&save_y, &arg5);
        sp_pframe(&save_y, &val2);
        &val2 += 1;
        &save_y = sp_custom("tb_border-top", &save_x, -1);
        sp_pseq(&save_y, &arg5);
        sp_pframe(&save_y, &val2);
        &val2 += 1;
        &save_y = sp_custom("tb_border-left", &save_x, -1);
        sp_pseq(&save_y, &arg5);
        sp_pframe(&save_y, &val2);
      }
    }
  }
  
  &save_x *= 1000;
  return(&save_x);
}

void text_box_hide(void)
{
  //&arg1 = active sprite number of text box(x1000)
  
  &save_x = &arg1;
  &save_x /= 1000;
  
  &save_y = sp_custom("tb_nobd", &save_x, -1);
  if (&save_y <= 0)
  {
    &save_y = sp_custom("tb_border-bottom", &save_x, -1);
    sp_nodraw(&save_y, 1);
    &save_y = sp_custom("tb_border-right", &save_x, -1);
    sp_nodraw(&save_y, 1);
    &save_y = sp_custom("tb_border-top", &save_x, -1);
    sp_nodraw(&save_y, 1);
    &save_y = sp_custom("tb_border-left", &save_x, -1);
    sp_nodraw(&save_y, 1);
  }
  
  sp_nodraw(&save_x, 1);
  
  sp_custom("tb_hidden", &save_x, 1);
  
  &save_x *= 1000;
  return(&save_x);
}

void text_box_show(void)
{
  //&arg1 = active sprite number of text box(x1000)
  
  &save_x = &arg1;
  &save_x /= 1000;
  
  &save_y = sp_custom("tb_nobd", &save_x, -1);
  if (&save_y <= 0)
  {
    &save_y = sp_custom("tb_border-bottom", &save_x, -1);
    sp_nodraw(&save_y, 0);
    &save_y = sp_custom("tb_border-right", &save_x, -1);
    sp_nodraw(&save_y, 0);
    &save_y = sp_custom("tb_border-top", &save_x, -1);
    sp_nodraw(&save_y, 0);
    &save_y = sp_custom("tb_border-left", &save_x, -1);
    sp_nodraw(&save_y, 0);
  }
  
  sp_nodraw(&save_x, 0);
  
  sp_custom("tb_hidden", &save_x, 0);
  
  &save_x *= 1000;
  return(&save_x);
}

void text_box_halt(void)
{
  //&arg1 = active sprite number of text box(x1000)
  //&arg2 = If set, text box is timed instead of space.
  //        Will wait &arg2 and then continue the calling script
  //
  //&arg3 = if set to 1, text box is timed and space skip-able
  //        will wait &arg2 and then continue calling script or wait for press of spacebar.
  //
  //&arg4 = this is like a protection for accidentally skipping the next dialogue
  //        when the player presses space at the same time it times out..
  //        useful for textboxes that time out, or maybe even for any textbox
  //        basically, if this is set the player won't be able to skip it
  //       until &arg4 milliseconds after it appears
  
  //This prcoedure will return 1 if manually skipped with spacebar
  //Otherwise, will return 0. Could be helpful for something.
  
  //little trick to mimck the spacebar, but also skippable behaviour of text
  //we can run a wait in a spawned script, and wait_for_button in the current script,
  //then if spawned script wait expires, we set custom key "timeout" to 1, poke this procedure
  //with run_script_by_number, to make it cancel it's wait_for_button and restart the proc.
  //and it will then detect "timeout" is set to 1, and end this procedure.
  
  //local var
  int &val1;
  
  //save text box active sprite number in &arg2
  int &val2 = &arg1;
  &val2 /= 1000;
  
  //save current script instance number
  sp_custom("tb_halt_snum", &val2, &current_script);
  
  &save_x = sp_custom("tb_timeout", &val2, -1);
  if (&save_x > 0)
  {
    sp_custom("tb_timeout", &val2, 0);
    sp_custom("tb_halt_snum", &val2, 0);
    return(0);
    kill_this_task();
  }
  
  if (&arg2 > 0)
  {
    if (&arg3 == 1)
    {
      //pass text box sprite and the script number of this proc
      //(custom procedures are their own script number)
      sp_custom("tb_halt_proc", &val2, &current_script);
      sp_custom("tb_halt_time", &val2, &arg2);
      &save_x = &val2;
      spawn("dctb-ht");
      goto text_box_halt;
    }
    
    &val1 = &arg2;
   halt_wait_loop:
    wait(50);
    &val1 -= 50;
    &save_x = sp_custom("TB_pmap", &val2, -1);
    if (&save_x != &player_map)
    {
      return(3);
    }
    if (&val1 > 0)
    {
     goto halt_wait_loop;
    }
    sp_custom("tb_halt_snum", &val2, 0);
    return(0);
    kill_this_task();
  }
  
text_box_halt:
  if (&arg4 > 0)
  {
    wait(&arg4);
    &save_x = sp_custom("TB_pmap", &val2, -1);
    if (&save_x != &player_map)
    {
      sp_custom("TB_halt_spawned", &val2, 0);
      sp_custom("tb_halt_proc", &val2, 0);
      sp_custom("tb_halt_snum", &val2, 0);
      return(3);
      kill_this_task();
    }
  }
 
 halt_space_skip:
  wait_for_button();
  &save_x = sp_custom("TB_pmap", &val2, -1);
  if (&save_x != &player_map)
  {
    &save_x = sp_custom("TB_halt_spawned", &val2, -1); 
    if (&save_x > 0)
    {
     run_script_by_number(&save_x, "killscript");
     sp_custom("TB_halt_spawned", &val2, 0);
     sp_custom("tb_halt_proc", &val2, 0);
     sp_custom("tb_halt_snum", &val2, 0);
    }
    return(3);
    kill_this_task();
  }
  if (&result != 2)
  {
    goto halt_space_skip;
  }

  &save_x = sp_custom("TB_halt_spawned", &val2, -1); 
  if (&save_x > 0)
  {
    //player pressed space, kill the previously spawned script instance of "robj-dctb.c"
    run_script_by_number(&save_x, "killscript");
    sp_custom("tb_halt_proc", &val2, 0);
    sp_custom("TB_halt_spawned", &val2, 0);
  }
  
  sp_custom("tb_halt_snum", &val2, 0);
  return(1);
  kill_this_task();
}

void text_box_end(void)
{
  //&arg1 = active sprite number of text box(x1000)
  
  //clears all text, text box and borders attached to box &arg1
  
  text_box_clear(&arg1);
  
  &save_y = &arg1;
  &save_y /= 1000;
  
  
  &save_x = sp_custom("tb_border-bottom", &save_y, -1);
  if (&save_x > 0)
  {
    sp_active(&save_x, 0);
  }
  &save_x = sp_custom("tb_border-left", &save_y, -1);
  if (&save_x > 0)
  {
    sp_active(&save_x, 0);
  }
  &save_x = sp_custom("tb_border-top", &save_y, -1);
  if (&save_x > 0)
  {
    sp_active(&save_x, 0);
  }
  &save_x = sp_custom("tb_border-right", &save_y, -1);
  if (&save_x > 0)
  {
    sp_active(&save_x, 0);
  }
  
  sp_active(&save_y, 0);
  
  return;
}

void text_box_clear(void)
{
  //&arg1 = active sprite number of text box(x1000)
  
  int &val1 = &arg1;
  &val1 /= 1000;
  
  &save_x = 0;
kill_tb_text:
  &save_x = get_next_sprite_with_this_brain(8, 0, &save_x);
  if (&save_x > 0)
  {
    &save_y = sp_custom("tb_text_box_parent", &save_x, -1);
    if (&save_y == &val1)
    {
      sp_active(&save_x, 0);
    }
    
    &save_x += 1;
    goto kill_tb_text;
  }
  
  return;
}

void text_box_xy(void)
{
  //adjusts the position of where the top line of text will be
  //Everything else will also adjust automatically and move the same amount
  //used to re-adjust the position of the text box without killing it off and making a new one
  
  //&arg1 = active sprite number of textbox(x1000)
  //&arg2 = new x position of top line of text
  //&arg3 = new y position of top line of text
  
  //get the textbox active sprite number
  int &val2 = &arg1;
  &val2 /= 1000;
  
  //get x position of first line of text, don't worry about y position here
  int &val1 = &arg2;
  &val1 -= 309;
  if (&val1 == -1)
  {
    &val1 = 0;
  }
  sp_custom("tb_textpos-x", &val2, &val1);
  
  if (&arg3 == -1)
  {
    sp_custom("tb_textpos-y", &val2, 0);
  }
  else
  {
    sp_custom("tb_textpos-y", &val2, &arg3);
  }
  
  if (&arg2 == -1)
  {
    sp_custom("textbox_pos_x", &val2, 0);
  }
  else
  {
    sp_custom("textbox_pos_x", &val2, &arg2);
  }
  
  return;
}

void tbb_fix_nix(void)
{
 //linux fix to revert &ar9 back to 0
 text_box_blank(&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, 0);
 kill_this_task(); 
}

void text_box_blank(void)
{
  //text box create called from this script (text_box_start), or can be called directly to create an empty box
  //and then do whatever you want with it
  //for ane empty box you will only need to specify values for &arg1 - &arg4.
  //the other values are used by the automatic text box system when text is involved.
  
  //NOTE: you'll notice below that &arg5-8 have different possible purposes.
  //If you're creating an empty box, ignore all the "extra automatic text box stuff"
  //follow what the &arg#'s say for "empty box creation"
  
  ////////////////////////////////////////
  //Empty box creation - required values//
  ////////////////////////////////////////
  //&arg1 = x position of text box
  //&arg2 = y position of text box
  //&arg3 = length of box
  //&arg4 = height of box
  //&arg5 = custom text box background sequence
  //&arg6 = custom text box background frame
  //&arg7 = custom text box border sequence
  //&arg8 = custom text box border start frame (input frame of BOTTOM border sprite, will use next frame for Right, then next for top, then next for left)
  
  //if &arg7 and/or &arg8 is set to -2, the text box will be borderless
  
  
  //////////////////////////////////
  //Extra automatic text box stuff//
  //////////////////////////////////
  //These will be used instead if &arg9 is equal to 1.
  //&arg5 = first line of text X position
  //&arg6 = First line of text Y position
  //&arg7 = body text spacing
  //&arg8 = title and footer spacing
  
  //local vars
  int &val1;
  int &val2;
  
  //create the text box
  &save_x = create_sprite(&arg1, &arg2, 0, 30, 5);
  sp_nodraw(&save_x, 1);
  sp_nohit(&save_x, 1);
  sp_que(&save_x, 10000);
  sp_noclip(&save_x, 1);
  
  //initiliase sprite size for clipping
  sp_clip_right(&save_x, 600);
  sp_clip_bottom(&save_x, 400);
  
  //save some of the information provided so we don't lose it
  if (&arg5 == -1)
  {
    sp_custom("tb_textpos-x", &save_x, 0);
  }
  else
  {
    if (&arg9 == 1)
    {
      sp_custom("tb_textpos-x", &save_x, &arg5);
    }
    else
    {
      //&arg5 is custom seq, not textpox x position
      if (&arg5 > 0)
      {
        sp_custom("tb_bg_seq", &save_x, &arg5);
        sp_pseq(&save_x, &arg5);
      }
    }
  }
  if (&arg6 == -1)
  {
    sp_custom("tb_textpos-y", &save_x, 0);
  }
  else
  {
    if (&arg9 == 1)
    {
      sp_custom("tb_textpos-y", &save_x, &arg6);
    }
    else
    {
      if (&arg6 > 0)
      {
        sp_custom("tb_bg_frame", &save_x, &arg6);
        sp_pframe(&save_x, &arg6);
      }
    }
  }
  
  sp_custom("tb_normal_space", &save_x, &arg7);
  sp_custom("tb_extra_space", &save_x, &arg8);
  
  //create the borders
  //bottom
  &save_y = create_sprite(&arg1, &arg2, 0, 30, 6);
  sp_nodraw(&save_y, 1);
  sp_nohit(&save_y, 1);
  sp_que(&save_y, 10000);
  sp_noclip(&save_y, 1);
  sp_custom("tb_border-bottom", &save_x, &save_y);
  
  //initiliase sprite size for clipping
  sp_clip_right(&save_y, 604);
  sp_clip_bottom(&save_y, 400);
  
  //right
  &save_y = create_sprite(&arg1, &arg2, 0, 30, 7);
  sp_nodraw(&save_y, 1);
  sp_nohit(&save_y, 1);
  sp_que(&save_y, 10000);
  sp_noclip(&save_y, 1);
  sp_custom("tb_border-right", &save_x, &save_y);
  
  sp_clip_right(&save_y, 600);
  sp_clip_bottom(&save_y, 400);
  
  //top
  &save_y = create_sprite(&arg1, &arg2, 0, 30, 8);
  sp_nodraw(&save_y, 1);
  sp_nohit(&save_y, 1);
  sp_que(&save_y, 10000);
  sp_noclip(&save_y, 1);
  sp_custom("tb_border-top", &save_x, &save_y);
  sp_clip_right(&save_y, 604);
  sp_clip_bottom(&save_y, 400);
  
  //left
  &save_y = create_sprite(&arg1, &arg2, 0, 30, 9);
  sp_nodraw(&save_y, 1);
  sp_nohit(&save_y, 1);
  sp_que(&save_y, 10000);
  sp_noclip(&save_y, 1);
  sp_custom("tb_border-left", &save_x, &save_y);
  sp_clip_right(&save_y, 600);
  sp_clip_bottom(&save_y, 400);
  
  &val2 = &arg3;
  if (&val2 < 600)
  {
    if (&val2 > 0)
    {
tb_blank_length:
      &save_y = sp_custom("tb_border-top", &save_x, -1);
      sp_x(&save_y, &arg1);
      &save_y = sp_custom("tb_border-bottom", &save_x, -1);
      sp_x(&save_y, &arg1);
      &save_y = sp_custom("tb_border-left", &save_x, -1);
      sp_x(&save_y, &arg1);
      &save_y = sp_custom("tb_border-right", &save_x, -1);
      sp_x(&save_y, &arg1);
      
      //simply use sp_clip_right to display the amount of pixels we want
      sp_clip_right(&save_x, &val2);
      
      //do the bottom and top borders as well
      &save_y = sp_custom("tb_border-bottom", &save_x, -1);
      &val1 = &val2;
      &val1 += 4;
      sp_clip_right(&save_y, &val1);
      &save_y = sp_custom("tb_border-top", &save_x, -1);
      &val1 = &val2;
      &val1 += 4;
      sp_clip_right(&save_y, &val1);
      
      //centre the text box//
      //get the different between the right border edge before and after clipping
      //(on the x axis)
      &save_y = 600;
      &save_y -= &val2;
      sp_custom("tb_clip_diff_x", &save_x, &save_y);
      
      //move it so the center of the textbox will be at the chosen x/y position
      &val1 = math_mod(&save_y, 2);
      &save_y /= 2;
      &save_y += &val1;
      sp_custom("tb_offset_x", &save_x, &save_y);
      &save_y += sp_x(&save_x, -1);
      if (&save_y == -1)
      {
tb_blank_length_bugfix:
        //move the main text box left one and adjust clip size to show 1 more pixel on the right as well
        &save_y = &arg1;
        &save_y -= 1;
        sp_x(&save_x, &save_y);
        &val2 = sp_clip_right(&save_x, -1);
        &val2 += 1;
        goto tb_blank_length;
      }
      sp_x(&save_x, &save_y);
      
      //centre the borders on the x axis - top first
      &save_y = sp_custom("tb_border-top", &save_x, -1);
      &val1 = sp_x(&save_y, -1);
      &val1 += sp_custom("tb_offset_x", &save_x, -1);
      if (&val1 == -1)
      {
        goto tb_blank_length_bugfix;
      }
      &save_y = sp_x(&save_y, &val1);
      
      //save where the box centre is(on the x axis) in a custom key
      &save_y -= sp_custom("tb_offset_x", &save_x, -1);
      sp_custom("tb_x_centre", &save_x, &save_y);
      
      //now - x axis  bottom
      &save_y = sp_custom("tb_border-bottom", &save_x, -1);
      &val1 = sp_x(&save_y, -1);
      &val1 += sp_custom("tb_offset_x", &save_x, -1);
      if (&val1 == -1)
      {
        goto tb_blank_length_bugfix;
      }
      sp_x(&save_y, &val1);
      
      //now - x axis right
      &save_y = sp_custom("tb_border-right", &save_x, -1);
      &val1 = sp_x(&save_y, -1);
      &val1 -= sp_custom("tb_clip_diff_x", &save_x, -1);
      &val1 += sp_custom("tb_offset_x", &save_x, -1);
      if (&val1 == -1)
      {
        goto tb_blank_length_bugfix;
      }
      sp_x(&save_y, &val1);
      
      //now - x axis left
      &save_y = sp_custom("tb_border-left", &save_x, -1);
      &val1 = sp_x(&save_y, -1);
      &val1 += sp_custom("tb_offset_x", &save_x, -1);
      if (&val1 == -1)
      {
        goto tb_blank_length_bugfix;
      }
      sp_x(&save_y, &val1);
    }
  }
  
  &val2 = &arg4;
  if (&val2 < 400)
  {
    if (&val2 > 0)
    {
tb_blank_height:
      &save_y = sp_custom("tb_border-top", &save_x, -1);
      sp_y(&save_y, &arg2);
      &save_y = sp_custom("tb_border-bottom", &save_x, -1);
      sp_y(&save_y, &arg2);
      &save_y = sp_custom("tb_border-left", &save_x, -1);
      sp_y(&save_y, &arg2);
      &save_y = sp_custom("tb_border-right", &save_x, -1);
      sp_y(&save_y, &arg2);
      
      //simply use sp_clip_bottom to display the amount of pixles we want
      sp_clip_bottom(&save_x, &val2);
      
      //do the bottom and top borders as well
      &save_y = sp_custom("tb_border-right", &save_x, -1);
      sp_clip_bottom(&save_y, &val2);
      &save_y = sp_custom("tb_border-left", &save_x, -1);
      sp_clip_bottom(&save_y, &val2);
      
      //centre the text box//
      //get the different between the bottom border edge before and after clipping
      //(on the x axis)
      &save_y = 400;
      &save_y -= &val2;
      sp_custom("tb_clip_diff_y", &save_x, &save_y);
      
      //move it so the center of the textbox will be at the chosen x/y position
      &val1 = math_mod(&save_y, 2);
      &save_y /= 2;
      &save_y += &val1;
      sp_custom("tb_offset_y", &save_x, &save_y);
      &save_y += sp_y(&save_x, -1);
      if (&save_y == -1)
      {
tb_blank_height_bugfix:
        //move the main text box left one and adjust clip size to show 1 more pixel on the bottom as well
        &save_y = &arg2;
        &save_y -= 1;
        sp_y(&save_x, &save_y);
        &val2 = sp_clip_bottom(&save_x, -1);
        &val2 += 1;
        goto tb_blank_height;
      }
      &save_y = sp_y(&save_x, &save_y);
      
      //save where the box centre is(on the y axis) in a custom key
      &save_y -= sp_custom("tb_offset_y", &save_x, -1);
      sp_custom("tb_y_centre", &save_x, &save_y);
      
      //centre the borders on the y axis - top first
      &save_y = sp_custom("tb_border-left", &save_x, -1);
      &val1 = sp_y(&save_y, -1);
      &val1 += sp_custom("tb_offset_y", &save_x, -1);
      if (&val1 == -1)
      {
        goto tb_blank_height_bugfix;
      }
      sp_y(&save_y, &val1);
      
      //now - y axis  bottom
      &save_y = sp_custom("tb_border-right", &save_x, -1);
      &val1 = sp_y(&save_y, -1);
      &val1 += sp_custom("tb_offset_y", &save_x, -1);
      if (&val1 == -1)
      {
        goto tb_blank_height_bugfix;
      }
      sp_y(&save_y, &val1);
      
      //now - y axis bottom
      &save_y = sp_custom("tb_border-bottom", &save_x, -1);
      &val1 = sp_y(&save_y, -1);
      &val1 -= sp_custom("tb_clip_diff_y", &save_x, -1);
      &val1 += sp_custom("tb_offset_y", &save_x, -1);
      if (&val1 == -1)
      {
        goto tb_blank_height_bugfix;
      }
      sp_y(&save_y, &val1);
      
      //now - y axis top
      &save_y = sp_custom("tb_border-top", &save_x, -1);
      &val1 = sp_y(&save_y, -1);
      &val1 += sp_custom("tb_offset_y", &save_x, -1);
      if (&val1 == -1)
      {
        goto tb_blank_height_bugfix;
      }
      sp_y(&save_y, &val1);
    }
  }
  
  if (&arg9 <= 0)
  {
    //an empty box - make it visible immediately
    &save_y = sp_custom("tb_border-top", &save_x, -1);
    sp_nodraw(&save_y, 0);
    &save_y = sp_custom("tb_border-right", &save_x, -1);
    sp_nodraw(&save_y, 0);
    &save_y = sp_custom("tb_border-bottom", &save_x, -1);
    sp_nodraw(&save_y, 0);
    &save_y = sp_custom("tb_border-left", &save_x, -1);
    sp_nodraw(&save_y, 0);
    sp_nodraw(&save_x, 0);
  }
  
  //check for borderless specification
  &save_y = 0;
  if (&arg7 == -2)
  {
    &save_y = 1;
  }
  if (&arg8 == -2)
  {
    &save_y = 1;
  }
  
  if (&save_y == 1)
  {
    //borderless
    &save_y = sp_custom("tb_border-bottom", &save_x, -1);
    sp_active(&save_y, 0);
    &save_y = sp_custom("tb_border-right", &save_x, -1);
    sp_active(&save_y, 0);
    &save_y = sp_custom("tb_border-top", &save_x, -1);
    sp_active(&save_y, 0);
    &save_y = sp_custom("tb_border-left", &save_x, -1);
    sp_active(&save_y, 0);
    
    sp_custom("tb_border-bottom", &save_x, 0);
    sp_custom("tb_border-right", &save_x, 0);
    sp_custom("tb_border-top", &save_x, 0);
    sp_custom("tb_border-left", &save_x, 0);
    
    //save borderless specification in custom key
    sp_custom("tb_nobd", &save_x, 1);
  }
  
  //check for custom seq/frame for borders
  if (&arg9 <= 0)
  {
    if (&arg7 > 0)
    {
      if (&arg8 > 0)
      {
        &save_y = sp_custom("tb_nobd", &save_x, -1);
        if (&save_y <= 0)
        {
          &val1 = &arg8;
          &save_y = sp_custom("tb_border-bottom", &save_x, -1);
          sp_pseq(&save_y, &arg7);
          sp_pframe(&save_y, &val1);
          &val1 += 1;
          &save_y = sp_custom("tb_border-right", &save_x, -1);
          sp_pseq(&save_y, &arg7);
          sp_pframe(&save_y, &val1);
          &val1 += 1;
          &save_y = sp_custom("tb_border-top", &save_x, -1);
          sp_pseq(&save_y, &arg7);
          sp_pframe(&save_y, &val1);
          &val1 += 1;
          &save_y = sp_custom("tb_border-left", &save_x, -1);
          sp_pseq(&save_y, &arg7);
          sp_pframe(&save_y, &val1);
        }
      }
    }
  }

  return(&save_x);
  kill_this_task();
}

void text_box_arrange(void)
{
  //detects all text sprites that belong in &arg1(/1000) text box and places them in correct position.
  //according to arrangement as set by x/y values of say_xy lines.
  
  //&arg1 = textbox active sprite number(x1000)
  
  //&arg2 = Max characters used in the longest say line. Estimates required textbox size from character count
  //        It isn't alweays entirely accurate becasue every character is a different number of picels in length!
  //        If this fails, and your text is out of bounds, use Custom Textbox length instead.
  
  //&arg3 = Custom textbox length
  //        Used to set a custom textbox width in sutations where &arg2 fails.
  
  /////////////////////////////////////////////////////////////////////////////////
  //&arg values used to automatically progress to and configure "text_box_halt()"//
  /////////////////////////////////////////////////////////////////////////////////
  //&arg4 = if this is set to 1, will automatically run the "text_box_halt()" procedure after this is done.
  //        used to keep scripts even cleaner by having less external lines!
  
  //&arg5 = If set > 1, text box is timed, rather than space-skip-able
  //        Will wait &arg5 and then continue the calling script
  
  // &arg6 = If set to 1, text box is time AND space-skip-able
  //         will wait &arg5 and then continue calling script or wait for press of spacebar.
  
  //&arg7 = this is like a protection for accidentally skipping the next dialogue
  //        when the player presses space at the same time it times out..
  //        useful for textboxes that time out, or maybe even for any textbox
  //        basically, if this is set the player won't be able to skip it
  //       until &arg7 milliseconds after it appears
  
  //&arg8 = If set to 1 will automatically call "text_box_clear();" after "text_box_halt();"
  //        If set to 2 will automatically call "text_box_end();" after "text_box_halt();"
  
  
  //&val1 will track the next expected text order number
  int &val1 = 1;
  
  //for various uses
  int &val2;
  
  //to store textbox sprite number
  int &val3 = &arg1;
  &val3 /= 1000;
  
  //initialise custom keys
  sp_custom("tb_text_hold", &val3, 0);
  sp_custom("tb_first_text", &val3, 0);
  sp_custom("tb_last_text", &val3, 0);
  sp_custom("tb_header_space", &val3, 0);
  
  //copy custom key to store next y and not lose original value
  &save_x = sp_custom("tb_textpos-y", &val3, -1);
  sp_custom("tb_textpos-nexty", &val3, &save_x);
  
  //Retrieve and arrange the text
  &save_x = 0;
arrange_all_text:
  &save_x = get_next_sprite_with_this_brain(8, 0, &save_x);
  if (&save_x > 0)
  {
    &save_y = sp_y(&save_x, -1);
    &save_y /= 1000;
    if (&save_y == &val3)
    {
      //this is a text sprite meant for this text box
      //make it survive till killed by other means
      sp_kill(&save_x, 0);
      
      //make it so the text is immune to spacebar skip in all situations
      //we don't want the text to die until we manually kill it off ourself
      sp_script(&save_x, "dctb-tl");
      
      //make it retrievable after position changes
      sp_custom("tb_text_box_parent", &save_x, &val3);
      
      //check if we are checking for skipped text sprites
      &save_y = sp_custom("tb_text_hold", &val3, -1);
      if (&save_y > 0)
      {
        //the only bug I can fore-see occuring, and it would be *very unlikely* is that another text sprite
        //already exists when text box say lines are being created. IF the existing text sprite vanishes
        //and one of the text box say lines takes it's active sprite number, this means they won't
        //be in ascending order of active sprite number (as they are usually). This will fix that.
        
        //SO, what have we done here?//
        //We have detected a higher numerical order then expected, we shelved it temporarily
        //and we are now checking every other text sprite to see if there's any with a lower active sprite number
        //if there is, it will then have it's numerical order compared, and if it's as expected, we switch to it
        //if it's not, we obviously have the correct text sprite, so "un-shelf" the shelfed text sprite and continue.
        if (&save_x >= &save_y)
        {
          &save_x += 1;
          goto arrange_all_text;
        }
      }
      
      //check the order and check if it's meant for next in line
      &save_y = sp_x(&save_x, -1);
      if (&save_y > &val1)
      {
        //somehow skipped a line, or extra space is wanted.
        //save text sprite in a custom key, and search through remaining text sprites to make sure
        sp_custom("tb_text_hold", &val3, &save_x);
        &save_x += 1;
        goto arrange_all_text;
      }
      
arrange_skip_accept:
      //store the text order number (old x pos) in a custom key attached to the text sprite
      &save_y = sp_x(&save_x, -1);
      sp_custom("tb_text_order_num", &save_x, &save_y);
      
      //set text to chosen x position
      &save_y = sp_custom("tb_textpos-x", &val3, -1);
      sp_x(&save_x, &save_y);
      
      //check if we need to factor in extra space for this line
      &save_y = sp_custom("tb_text_hold", &val3, -1);
      if (&save_y == &save_x)
      {
        //extra space was specified in x position of this text
        &save_y = sp_custom("tb_text_order_num", &save_x, -1);
        &val2 = &val1;
        &val2 *= 100;
        if (&save_y >= &val2)
        {
          //100 or more difference between previous line and last line x position
          //get how many increments * 100 were done and get "extra space" value
          &save_y /= 100;
          &save_y += 1;
          &save_y -= &val1;
          &val2 = sp_custom("tb_extra_space", &val3, -1);
        }
        else
        {
          &save_y -= &val1;
          &save_y += 1;
          //get normal space value
          &val2 = sp_custom("tb_normal_space", &val3, -1);
          
          if (&val1 == 1)
          {
            //we want 1 less space multiplied by missed number here.
            //there is no default space before first line
            //so we need to drop the result down by 1.
            &save_y -= 1;
          }
        }
        
        //increase &val2 to the amount of space specified inf say_xy order number (x pos value)
        &val2 *= &save_y;
        
        //if this is space wanted before the first line of text, save it in a custom key
        //so when we extend the text box to fit the text, we take that into account
        if (&val1 == 1)
        {
          sp_custom("tb_header_space", &val3, &val2);
        }
        
        //reset "texthold" custom key.
        sp_custom("tb_text_hold", &val3, 0);
      }
      else
      {
        //default no space before the first line of text unless specified.
        if (&val1 > 1)
        {
          &val2 = sp_custom("tb_normal_space", &val3, -1);
        }
      }
      
      //////////////
      //do spacing//
      //////////////
      &save_y = sp_custom("tb_textpos-nexty", &val3, -1);
      
      //increment y value
      &save_y += &val2;
      
      //don't allow a -1 value
      if (&save_y == -1)
      {
        &save_y += 1;
      }
      
      //set text sprite y position
      sp_custom("tb_space_x", &save_x, &save_y);
      sp_y(&save_x, &save_y);
      
      //check for spaces via custom keys
      &val2 = 0;
      &save_y = sp_custom("default_space", &save_x, -1);
      if (&save_y > 0)
      {
        &val2 = sp_custom("tb_normal_space", &val3, -1);
        &val2 *= &save_y;
      }
      &save_y = sp_custom("big_space", &save_x, -1);
      if (&save_y > 0)
      {
        &val2 = sp_custom("tb_extra_space", &val3, -1);
        &val2 *= &save_y;
      }
      &save_y = sp_custom("custom_space", &save_x, -1);
      if (&save_y > 0)
      {
        &val2 = &save_y;
      }
      
      if (&val2 > 0)
      {
        //we have custom key spacing to apply after the text as well
        &val2 += sp_y(&save_x, -1);
        &save_y = &val2;
      }
      else
      {
        //there is no custom key spacing specified, restore the value form before
        &save_y = sp_custom("tb_space_x", &save_x, -1);
      }
      
      //set the Y position designated for the next text sprite
      sp_custom("tb_textpos-nexty", &val3, &save_y);
      
      //if this is the first text sprite, save it in a custom key
      if (&val1 == 1)
      {
        sp_custom("tb_first_text", &val3, &save_x);
      }
      
      //set next expected text sprite order number (x pos)
      //commented out the following to make it so it expects the next number
      //to fall back to it's expected order, disregarding an increase of a particular line
      //so don't have to modify every single line if you choose to add a space
      //&val1 = sp_custom("tb_text_order_num", &save_x, -1);
      &val1 += 1;
      
      //save the last retrieved active text sprite in a custom key
      sp_custom("tb_last_text", &val3, &save_x);
    }
    
    &save_x += 1;
    goto arrange_all_text;
  }
  
  &save_y = sp_custom("tb_text_hold", &val3, -1);
  if (&save_y > 0)
  {
    //all text sprites were searched due to number skip
    //no lower text sprite found - continue and add desired space
    &save_x = sp_custom("tb_text_hold", &val3, -1);
    goto arrange_skip_accept;
  }
  
  ///////////////////////////////
  //X AXIS AND BOX LENGTH STUFF//
  ///////////////////////////////
  //check if pixel or char length is provided and which one to use
  if (&arg2 <= 0)
  {
    if (&arg3 <= 0)
    {
      //no value passed to "text_box_arrange()", assuming values were set at "text_box_start()"
      &val2 = sp_custom("tb_do_pixel_length", &val3, -1);
      if (&val2 <= 0)
      {
        //it's not so store the char length instead.
        &val2 = sp_custom("tb_do_char_length", &val3, -1);
        
        //Estimate the size of the text box from the character length input
        &val2 *= 10;
      }
    }
    else
    {
      &val2 = &arg3;
      sp_custom("tb_do_pixel_length", &val3, &val2);
      goto tb_arr_xset_cont;
    }
  }
  else
  {
    &val2 = &arg2;
    sp_custom("tb_do_char_length", &val3, &arg2);
    //Estimate the size of the text box from the character length input
    &val2 *= 10;
  }
  
tb_arr_xset_cont:
  //set x position of text box
  &save_y = sp_custom("textbox_pos_x", &val3, -1);
  sp_x(&val3, &save_y);
  
  &save_x = sp_custom("tb_nobd", &val3, -1);
  if (&save_x <= 0)
  {
    //borders
    &save_x = sp_custom("tb_border-right", &val3, -1);
    sp_x(&save_x, &save_y);
    &save_x = sp_custom("tb_border-top", &val3, -1);
    sp_x(&save_x, &save_y);
    &save_x = sp_custom("tb_border-left", &val3, -1);
    sp_x(&save_x, &save_y);
    &save_x = sp_custom("tb_border-bottom", &val3, -1);
    sp_x(&save_x, &save_y);
  }
  
  if (&val2 < 600)
  {
    if (&val2 > 0)
    {
      &save_x = sp_custom("tb_nobd", &val3, -1);
      if (&save_x <= 0)
      {
        &save_x = sp_custom("tb_border-top", &val3, -1);
        sp_x(&save_x, &save_y);
        &save_x = sp_custom("tb_border-bottom", &val3, -1);
        sp_x(&save_x, &save_y);
        &save_x = sp_custom("tb_border-left", &val3, -1);
        sp_x(&save_x, &save_y);
        &save_x = sp_custom("tb_border-right", &val3, -1);
        sp_x(&save_x, &save_y);
      }
      
      //simply use sp_clip_right to display the amount of pixels we want
      sp_clip_right(&val3, &val2);
      
      &save_x = sp_custom("tb_nobd", &val3, -1);
      if (&save_x <= 0)
      {
        //do the bottom and top borders as well
        &save_y = sp_custom("tb_border-bottom", &val3, -1);
        &val1 = &val2;
        &val1 += 4;
        sp_clip_right(&save_y, &val1);
        &save_y = sp_custom("tb_border-top", &val3, -1);
        &val1 = &val2;
        &val1 += 4;
        sp_clip_right(&save_y, &val1);
      }
      
      //centre the text box//
      //get the different between the right border edge before and after clipping
      //(on the x axis)
      &save_y = 600;
      &save_y -= &val2;
      sp_custom("tb_clip_diff_x", &val3, &save_y);
      
      //move it so the center of the textbox will be at the chosen x/y position
      &val1 = math_mod(&save_y, 2);
      &save_y /= 2;
      &save_y += &val1;
      sp_custom("tb_offset_x", &val3, &save_y);
      &save_y += sp_x(&val3, -1);
      if (&save_y == -1)
      {
tb_arr_length_bugfix:
        //move the main text box left one and adjust clip size to show 1 more pixel on the right as well
        &save_y = sp_custom("textbox_pos_x", &val3, -1);
        &save_y -= 1;
        sp_x(&val3, &save_y);
        &val2 = sp_clip_right(&val3, -1);
        &val2 += 1;
        sp_custom("textbox_pos_x", &val3, &save_y);
        goto tb_arr_xset_cont;
      }
      &save_y = sp_x(&val3, &save_y);
      
      //save where the box centre is(on the x axis) in a custom key
      &save_y -= sp_custom("tb_offset_x", &val3, -1);
      sp_custom("tb_x_centre", &val3, &save_y);
      
      &save_x = sp_custom("tb_nobd", &val3, -1);
      if (&save_x <= 0)
      {
        //centre the borders on the x axis - top first
        &save_y = sp_custom("tb_border-top", &val3, -1);
        &val1 = sp_x(&save_y, -1);
        &val1 += sp_custom("tb_offset_x", &val3, -1);
        if (&val1 == -1)
        {
          goto tb_arr_length_bugfix;
        }
        sp_x(&save_y, &val1);
        
        //now - x axis  bottom
        &save_y = sp_custom("tb_border-bottom", &val3, -1);
        &val1 = sp_x(&save_y, -1);
        &val1 += sp_custom("tb_offset_x", &val3, -1);
        if (&val1 == -1)
        {
          goto tb_arr_length_bugfix;
        }
        sp_x(&save_y, &val1);
        
        //now - x axis right
        &save_y = sp_custom("tb_border-right", &val3, -1);
        &val1 = sp_x(&save_y, -1);
        &val1 -= sp_custom("tb_clip_diff_x", &val3, -1);
        &val1 += sp_custom("tb_offset_x", &val3, -1);
        if (&val1 == -1)
        {
          goto tb_arr_length_bugfix;
        }
        sp_x(&save_y, &val1);
        
        //now - x axis left
        &save_y = sp_custom("tb_border-left", &val3, -1);
        &val1 = sp_x(&save_y, -1);
        &val1 += sp_custom("tb_offset_x", &val3, -1);
        if (&val1 == -1)
        {
          goto tb_arr_length_bugfix;
        }
        sp_x(&save_y, &val1);
      }
    }
  }
  
  ///////////////////////////////
  //Y AXIS AND BOX HEIGHT STUFF//
  ///////////////////////////////
  
  //now use the y position of the first and last text sprite to set the box height
  &save_x = sp_custom("tb_first_text", &val3, -1);
  &save_y = sp_custom("tb_last_text", &val3, -1);
  
  //compare y positions
  &val1 = sp_y(&save_y, -1);
  sp_custom("tb_text_floor", &val3, &val1);
  &val2 = sp_y(&save_x, -1);
  sp_custom("tb_text_ceiling", &val3, &val2);
  &val1 -= &val2;
  
  //factor in extra space before first line of text
  &val1 += sp_custom("tb_header_space", &val3, -1);
  
  //add some extra room top and bottom of box
  &val1 += 35;
  
  //find midpoint of text block on the y axis
  &val2 = &val1;
  &val2 /= 2;
  &val2 += math_mod(&val1, 2);
  &save_x = sp_custom("tb_text_ceiling", &val3, -1);
  &save_x -= 8;
  &val2 += &save_x;
  if (&val2 == -1)
  {
    &val2 += 1;
  }
  sp_custom("tb_text_midpoint_y", &val3, &val2);
  &save_y = &val2;
  
  //set initial y position
arrange_tb_set_pos:
  sp_y(&val3, &save_y);
  
  &save_x = sp_custom("tb_nobd", &val3, -1);
  if (&save_x <= 0)
  {
    //borders
    &save_x = sp_custom("tb_border-right", &val3, -1);
    sp_y(&save_x, &save_y);
    &save_x = sp_custom("tb_border-top", &val3, -1);
    sp_y(&save_x, &save_y);
    &save_x = sp_custom("tb_border-left", &val3, -1);
    sp_y(&save_x, &save_y);
    &save_x = sp_custom("tb_border-bottom", &val3, -1);
    sp_y(&save_x, &save_y);
  }
  
  //now adjust the box height and make the textbox and borders visible
  if (&val1 < 400)
  {
    if (&val1 > 0)
    {
      &save_x = sp_custom("tb_nobd", &val3, -1);
      if (&save_x <= 0)
      {
        &save_x = sp_custom("tb_border-top", &val3, -1);
        sp_y(&save_x, &save_y);
        &save_x = sp_custom("tb_border-bottom", &val3, -1);
        sp_y(&save_x, &save_y);
        &save_x = sp_custom("tb_border-left", &val3, -1);
        sp_y(&save_x, &save_y);
        &save_x = sp_custom("tb_border-right", &val3, -1);
        sp_y(&save_x, &save_y);
      }
      
      //simply use sp_clip_bottom to display the amount of pixles we want
      sp_clip_bottom(&val3, &val1);
      
      &save_x = sp_custom("tb_nobd", &val3, -1);
      if (&save_x <= 0)
      {
        //do the bottom and top borders as well
        &save_y = sp_custom("tb_border-right", &val3, -1);
        sp_clip_bottom(&save_y, &val1);
        &save_y = sp_custom("tb_border-left", &val3, -1);
        sp_clip_bottom(&save_y, &val1);
      }
      
      //centre the text box//
      //get the different between the right border edge before and after clipping
      //(on the x axis)
      &save_y = 400;
      &save_y -= &val1;
      sp_custom("tb_clip_diff_y", &val3, &save_y);
      
      //move it so the center of the textbox will be at the centre
      &val1 = math_mod(&save_y, 2);
      &save_y /= 2;
      &save_y += &val1;
      
      //take into account header space
      &save_y -= sp_custom("tb_header_space", &val3, -1);
      
      //add clip different *minus* header space to current y position
      //and move it to centre it around text.
      sp_custom("tb_offset_y", &val3, &save_y);
      &save_y += sp_y(&val3, -1);
      if (&save_y == -1)
      {
tb_arr_height_bugfix:
        //move the main text box up one and adjust clip size to show 1 more pixel on the bottom as well
        //to fix result of -1 (can't set that).
        &save_y = sp_custom("tb_text_midpoint_y", &val3, -1);
        &save_y -= 1;
        &val1 = sp_clip_bottom(&val3, -1);
        &val1 += 1;
        sp_custom("tb_text_midpoint_y", &val3, &save_y);
        goto arrange_tb_set_pos;
      }
      &save_y = sp_y(&val3, &save_y);
      
      //save where the box centre is(on the y axis) in a custom key
      &save_y -= sp_custom("tb_offset_y", &val3, -1);
      sp_custom("tb_y_centre", &val3, &save_y);
      
      &save_x = sp_custom("tb_nobd", &val3, -1);
      if (&save_x <= 0)
      {
        //centre the borders on the y axis - top first
        &save_y = sp_custom("tb_border-left", &val3, -1);
        &val1 = sp_y(&save_y, -1);
        &val1 += sp_custom("tb_offset_y", &val3, -1);
        if (&val1 == -1)
        {
          goto tb_arr_height_bugfix;
        }
        sp_y(&save_y, &val1);
        
        //now - y axis  bottom
        &save_y = sp_custom("tb_border-right", &val3, -1);
        &val1 = sp_y(&save_y, -1);
        &val1 += sp_custom("tb_offset_y", &val3, -1);
        if (&val1 == -1)
        {
          goto tb_arr_height_bugfix;
        }
        sp_y(&save_y, &val1);
        
        //now - y axis bottom
        &save_y = sp_custom("tb_border-bottom", &val3, -1);
        &val1 = sp_y(&save_y, -1);
        &val1 -= sp_custom("tb_clip_diff_y", &val3, -1);
        &val1 += sp_custom("tb_offset_y", &val3, -1);
        if (&val1 == -1)
        {
          goto tb_arr_height_bugfix;
        }
        sp_y(&save_y, &val1);
        
        //now - y axis top
        &save_y = sp_custom("tb_border-top", &val3, -1);
        &val1 = sp_y(&save_y, -1);
        &val1 += sp_custom("tb_offset_y", &val3, -1);
        if (&val1 == -1)
        {
          goto tb_arr_height_bugfix;
        }
        sp_y(&save_y, &val1);
      }
    }
  }
  
  //make all components of the text box visible - as long as text_box_hide isn't active
  &save_x = sp_custom("tb_hidden", &val3, -1);
  if (&save_x <= 0)
  {
    sp_nodraw(&val3, 0);
    &save_x = sp_custom("tb_nobd", &val3, -1);
    if (&save_x <= 0)
    {
      &save_x = sp_custom("tb_border-bottom", &val3, -1);
      sp_nodraw(&save_x, 0);
      &save_x = sp_custom("tb_border-left", &val3, -1);
      sp_nodraw(&save_x, 0);
      &save_x = sp_custom("tb_border-top", &val3, -1);
      sp_nodraw(&save_x, 0);
      &save_x = sp_custom("tb_border-right", &val3, -1);
      sp_nodraw(&save_x, 0);
    }
  }
  
  if (&arg4 > 0)
  {
    external("robj-dctb", "text_box_halt", &arg1, &arg5, &arg6, &arg7, 0, 0, 0, 0);
    &save_x = &return;
    if (&save_x == 3)
    {
      kill_this_task();
    }
  }
  if (&arg8 == 1)
  {
    external("robj-dctb", "text_box_clear", &arg1);
    &save_x = &return;
    if (&save_x == 3)
    {
      kill_this_task();
    }
  }
  if (&arg8 == 2)
  {
    external("robj-dctb", "text_box_end", &arg1);
    &save_x = &return;
    if (&save_x == 3)
    {
      kill_this_task();
    }
  }

  return(&val3);
  kill_this_task();
}

void killscript(void)
{
  //used to kill any proc calls, or a spawned instance of this script
  &save_x = 0;
  kill_this_task();
}
