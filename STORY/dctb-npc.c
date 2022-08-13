//ROBJ'S Attempt and somewhat automated NPC conversation text boxes//
//Specifically for when sprites are talking using say or say_stop.
//how to use:
// >> https://docs.google.com/document/d/1FfkpIUnUdwnH4xievT5jN25oCUZRijqH8R2zTO8SLQU/edit?usp=sharing

//Obviously some stuff still has to be passed to the procedure - there's no way in DinkC to retrieve the width of text.
//So text box width must be specified. Height is handled automatically.
//For say and say_stop it works off the max text width that can be disaplyed on 1 line, which is 150 pixels wide.
//If you specifiy a length value more than 150, the text box will limit it's length to 150.
//Unless you force a custom length and height using the extra arguments when calling "text_box_npc_size()".
//Also, it'll automatically make the text box the correct height for the amount of lines ([string / 150] + 1 if math_mod(string, 150) > 0)

//I created a pixel counter for Dink text, it will be accurate most of the time if the font is not changed in game with initfont()
//It takes the individual pixel measurement of every character of size 12 Liberations Sans Regular, which is the default FreeDink font,
//and adds them together. The reason it might be off by a few pixels sometimes is because it does not take into account kerning
//(variance in letter spacing for specific letters used in pairs).

//If it ends up ever messing up because of being slightly off, you can just do a slight manual adjustement when you see it in testing your dmod.
//Here's the URL:
// >> https://docs.google.com/spreadsheets/d/192OoGll9GiUeYm4wG95mlTcFZ4wP93fyfn9XiYotToE/edit?usp=sharing

void text_box_npc_hide(void)
{
  //&arg1 = Text sprite parent (active sprite number), default &current_sprite if no value passed.
  
  //store the parent sprite in &save_y for now
  &save_y = &arg1;
  if (&save_y <= 0)
  {
    &save_y = &current_sprite;
  }

  //player map check
  &save_x = sp_custom("tb_pmap", &save_y, -1);
  if (&save_x != &player_map)
  {
   kill_this_task();
  }
  
  //make sure text box exists, and if so, retrieve it.
  &save_x = sp_custom("npc_tb_make_limit", &save_y, -1);
  if (&save_x > 0)
  {
    &save_x = sp_custom("npc_tb_make_limit", &save_x, -1);
    if (&save_x == &save_y)
    {
      &save_x = sp_custom("npc_tb_make_limit", &save_y, -1);
      sp_nodraw(&save_x, 1);
    }
  }
  
  return;
}

void text_box_npc_show(void)
{
  //&arg1 = Text sprite parent (active sprite number), default &current_sprite if no value passed.
  
  //store the parent sprite in &save_y for now
  &save_y = &arg1;
  if (&save_y <= 0)
  {
    &save_y = &current_sprite;
  }

  //player map check
  &save_x = sp_custom("tb_pmap", &save_y, -1);
  if (&save_x != &player_map)
  {
   kill_this_task();
  }
  
  //make sure text box exists, and if so, retrieve it.
  &save_x = sp_custom("npc_tb_make_limit", &save_y, -1);
  if (&save_x > 0)
  {
    &save_x = sp_custom("npc_tb_make_limit", &save_x, -1);
    if (&save_x == &save_y)
    {
      &save_x = sp_custom("npc_tb_make_limit", &save_y, -1);
      sp_nodraw(&save_x, 0);
    }
  }
  
  return;
}

void text_box_npc_size(void)
{
  //&arg1 = Text sprite parent (active sprite number), default &current_sprite if no value passed.
  //&arg2 = text pixel length
  //&arg3 = length override (disable pixel count calculation)
  //&arg4 = height override (disable pixel count calculation)
  //&arg5 = height override based on number of lines in say/say_stop line (disable pixel count calculation and &arg4 height override)
  
  //store the parent sprite in &save_y for now
  &save_y = &arg1;
  if (&save_y <= 0)
  {
    &save_y = &current_sprite;
  }

  //player map check
  &save_x = sp_custom("tb_pmap", &save_y, -1);
  if (&save_x != &player_map)
  {
   kill_this_task();
  }
  
  //cancel any previous bulk length settings
  sp_custom("tb_bulk_length1", &save_y, 0);
  sp_custom("tb_bulk_length2", &save_y, 0);
  sp_custom("tb_bulk_length3", &save_y, 0);
  sp_custom("tb_bulk_length4", &save_y, 0);
  sp_custom("tb_bulk_length5", &save_y, 0);
  sp_custom("tb_bulk_length6", &save_y, 0);
  sp_custom("tb_bulk_length7", &save_y, 0);
  sp_custom("tb_bulk_count", &save_y, 0);
  
  //set custom keys for box_length
  sp_custom("tb_text_length", &save_y, &arg2);
  sp_custom("tb_box_length", &save_y, &arg3);
  sp_custom("tb_box_height", &save_y, &arg4);
  sp_custom("tb_box_lines", &save_y, &arg5);
  return;
}

void text_bulk_npc_length(void)
{
  //&arg1 = Text sprite parent (active sprite number), default &current_sprite if no value passed.
  //&arg2 - &arg7 = lengths that will be used for the next 7 say/say_stop lines created by sprite &arg1.
  
  //store the parent sprite in &save_y for now
  &save_y = &arg1;
  if (&save_y <= 0)
  {
    &save_y = &current_sprite;
  }

  //player map check
  &save_x = sp_custom("tb_pmap", &save_y, -1);
  if (&save_x != &player_map)
  {
   kill_this_task();
  }
  
  //cancel any individual box length setting
  sp_custom("tb_text_length", &save_y, 0);
  sp_custom("tb_box_length", &save_y, 0);
  sp_custom("tb_box_height", &save_y, 0);
  sp_custom("tb_box_lines", &save_y, 0);
  
  //set all lengths in custom keys
  sp_custom("tb_bulk_length1", &save_y, &arg2);
  sp_custom("tb_bulk_length2", &save_y, &arg3);
  sp_custom("tb_bulk_length3", &save_y, &arg4);
  sp_custom("tb_bulk_length4", &save_y, &arg5);
  sp_custom("tb_bulk_length5", &save_y, &arg6);
  sp_custom("tb_bulk_length6", &save_y, &arg7);
  sp_custom("tb_bulk_length7", &save_y, &arg8);
  
  //reset counter
  sp_custom("tb_bulk_count", &save_y, 0);
  return;
}

void text_box_npc_shadow(void)
{
  //&arg1 = Text sprite parent (active sprite number), default &current_sprite if no value passed.
  
  //store the parent sprite in &save_y for now
  &save_y = &arg1;
  if (&save_y <= 0)
  {
    &save_y = &current_sprite;
  }

  //player map check
  &save_x = sp_custom("tb_pmap", &save_y, -1);
  if (&save_x != &player_map)
  {
   kill_this_task();
  }
  
  &save_x = sp_custom("npc_tb_make_limit", &save_y, -1);
  &save_x = sp_custom("TB_npc_spawned5", &save_x, -1);
  if (&save_x > 0)
  {
    kill_this_task();
  }
  
  &save_x = sp_custom("npc_tb_make_limit", &save_y, -1);
  sp_custom("tb_npc_proc5", &save_x, &current_script);
  spawn("dctb-spn");
  kill_this_task();
}

void tb_npc_getxy(void)
{
  //&arg1 = Text sprite parent (active sprite number)
  //&arg2 = Active sprite number of text sprite.
  //&arg3 = text box active sprite number
  
  int &val1;

  //player map check
  &val1 = sp_custom("tb_pmap", &arg1, -1);
  if (&val1 != &player_map)
  {
   kill_this_task();
  }
  
  //get x position of text and factor in offset
  &save_x = sp_x(&arg1, -1);
  &save_x += 75;
  &save_x -= 1;
  &save_x -= sp_custom("tb_default_text_x_offset", &arg1, -1);
  &save_y = &save_x;
  &save_y -= 75;
  &save_y += 1;
  if (&save_y < 1)
  {
    &save_x = 1;
    &save_x += 75;
    &save_x -= 1;
  }
  if (&save_y > 470)
  {
    &save_x = 470;
    &save_x += 75;
    &save_x -= 1;
  }
  
  //get y position of text and factor in offset
  &save_y = sp_y(&arg1, -1);
  &save_y -= sp_custom("tb_default_text_y_offset", &arg1, -1);
  if (&save_y < 1)
  {
    &save_y = 1;
  }
  &val1 = sp_custom("tb_box_lines", &arg1, -1);
  if (&val1 > 0)
  {
    goto tb_npc_start_ypos;
  }
  &vision = sp_custom("tb_textbox_length", &arg1, -1);
  if (&vision > 150)
  {
    //get the amount of lines of text there will be.
    &val1 = &vision;
    &vision = math_mod(&val1, 150);
    &val1 /= 150;
    if (&vision > 0)
    {
      &val1 += 1;
    }
    
tb_npc_start_ypos:
    //get y position of bottom line of text
    &vision = &val1;
    &vision -= 1;
    &vision *= 19;
    &val1 = &save_y;
    &val1 += &vision;
    
    //find midpoint
    &val1 += &save_y;
    &vision = math_mod(&val1, 2);
    &val1 /= 2;
    if (&vision > 0)
    {
      &val1 += 1;
    }
    &save_y = &val1;
  }
  &save_y += 9;
  
  //save in custom keys, since we can't return 2 values
  sp_custom("tb_npc_getxy-x", &arg1, &save_x);
  sp_custom("tb_npc_getxy-y", &arg1, &save_y);
  
  return(&arg1);
}

void tb_npc_getwh(void)
{
  //&arg1 = Text sprite parent (active sprite number), default &current_sprite if no value passed.
  //&arg2 = Text pixel length
  
  int &val1;

  //player map check
  &val1 = sp_custom("tb_pmap", &arg1, -1);
  if (&val1 != &player_map)
  {
   kill_this_task();
  }
  
  //get the text box height
  &vision = sp_custom("tb_box_lines", &arg1, -1);
  if (&vision <= 0)
  {
    &vision = sp_custom("tb_box_height", &arg1, -1);
  }
  else
  {
    &vision = sp_custom("tb_textbox_height", &arg1, -1);
  }
  if (&vision > 0)
  {
    &val1 = &vision;
  }
  else
  {
    //If above condition checking clarification: This will only run if 'box_lines,' or 'box_height' ISN'T set.
    &vision = sp_custom("tb_textbox_length", &arg1, -1);
    &val1 = &vision;
    if (&val1 > 150)
    {
      &vision = math_mod(&val1, 150);
      &val1 /= 150;
      if (&vision > 0)
      {
        &val1 += 1;
      }
      &val1 *= 19;
    }
    else
    {
      &val1 = 19;
    }
    &val1 += 4;
  }
  
  //get the text box width.
  &vision = sp_custom("tb_box_length", &arg1, -1);
  if (&vision <= 0)
  {
    &vision = sp_custom("tb_textbox_length", &arg1, -1);
    if (&vision > 150)
    {
      &vision = 150;
    }
    &vision += 4;
  }
  
  //save in custom keys, since we can't return 2 values
  sp_custom("tb_npc_getwh-w", &arg1, &vision);
  sp_custom("tb_npc_getwh-h", &arg1, &val1);
  
  return;
}

void text_box_npc_end(void)
{
  //&arg1 = Text sprite parent (active sprite number), default &current_sprite if no value passed.
  //&arg2 = if '1', will end the text box immediately, and will not wait for text.
  
  //kill all text boxes and spawned scripts
  int &val1 = &arg1;
  if (&val1 <= 0)
  {
    &val1 = &current_sprite;
  }
  
  //player map check
  &save_x = sp_custom("tb_pmap", &val1, -1);
  if (&save_x != &player_map)
  {
   kill_this_task();
  }
  
  if (&arg2 > 0)
  {
    //get the text box if it exists
    &save_x = sp_custom("npc_tb_make_limit", &val1, -1);
    if (&save_x > 0)
    {
      &save_y = sp_custom("npc_tb_make_limit", &save_x, -1);
      if (&save_y == &val1)
      {
        //kill off spawned scripts if they exist
        &save_y = sp_custom("TB_npc_spawned", &save_x, -1);
        if (&save_y > 0)
        {
          run_script_by_number(&save_y, "killscript");
        }
        &save_y = sp_custom("TB_npc_spawned2", &save_x, -1);
        if (&save_y > 0)
        {
          run_script_by_number(&save_y, "killscript");
        }
        &save_y = sp_custom("TB_npc_spawned3", &save_x, -1);
        if (&save_y > 0)
        {
          run_script_by_number(&save_y, "killscript");
        }
        
        //don't kill 'spawned4' - that's this script!
        
        &save_y = sp_custom("TB_npc_spawned5", &save_x, -1);
        if (&save_y > 0)
        {
          run_script_by_number(&save_y, "killscript");
        }
        
        //kill off previous text box for this sprite
        &save_x = sp_custom("npc_tb_make_limit", &val1, -1);
        sp_custom("TB_npc_spawned", &save_x, 0);
        sp_custom("TB_npc_spawned2", &save_x, 0);
        sp_custom("TB_npc_spawned3", &save_x, 0);
        sp_custom("TB_npc_spawned4", &save_x, 0);
        sp_custom("TB_npc_spawned5", &save_x, 0);
        sp_custom("tb_npc_proc", &save_x, 0);
        sp_custom("tb_npc_proc2", &save_x, 0);
        sp_custom("tb_npc_proc3", &save_x, 0);
        sp_custom("tb_npc_proc4", &save_x, 0);
        sp_custom("tb_npc_proc5", &save_x, 0);
        
        &save_y = sp_custom("tb_npc_nobd", &val1, -1);
        if (&save_y <= 0)
        {
          &save_y = sp_custom("tb_border-bottom", &save_x, -1);
          if (&save_y > 0)
            sp_active(&save_y, 0);
          &save_y = sp_custom("tb_border-top", &save_x, -1);
          if (&save_y > 0)
            sp_active(&save_y, 0);
          &save_y = sp_custom("tb_border-right", &save_x, -1);
          if (&save_y > 0)
            sp_active(&save_y, 0);
          &save_y = sp_custom("tb_border-left", &save_x, -1);
          if (&save_y > 0)
            sp_active(&save_y, 0);
        }
        &save_y = sp_custom("tb_npc_text_parent", &save_x, -1);
        sp_custom("npc_tb_make_limit", &save_y, 0);
        sp_custom("tb_npc_text_parent", &save_x, 0);
        sp_active(&save_x, 0);
      }
    }
  }
  
  //we don't wanna run waits in our externals or it can cause issues - so we spawn another script instance.
  //and then kill this external instance.
  &save_x = sp_custom("npc_tb_make_limit", &val1, -1);
  sp_custom("tb_npc_proc1", &save_x, 0);
  sp_custom("tb_npc_proc4", &save_x, &current_script);
  spawn("dctb-spn");
  kill_this_task();
}

void text_box_npc_start(void)
{
  //this is used when using a "say" line on a sprite
  //&arg1 = Text sprite parent (active sprite number), default &current_sprite if no value passed.
  //&arg2 = Text pixel length
  //&arg3 = custom text box background sequence
  //&arg4 = custom text box background frame
  //&arg5 = custom text box border sequence
  //&arg6 = custom text box border start frame (frame of BOTTOM border sprite, will use next frame for Right, then next for top, then next for left)
  //&arg7 = borderless
  //&arg8 = persist (text box stays between text lines)
  
  //local vars
  int &val1;
  int &val2;
  
  //store the parent sprite in &val1 for now
  &val1 = &arg1;
  if (&val1 <= 0)
  {
    &val1 = &current_sprite;
  }
  
  //store the current player_map with the parent sprite
  sp_custom("tb_pmap", &val1, &player_map);
  
  if (&arg8 != -99)
  {
    //this is being called by authors script.. initialise the text box..
    
    //store all passed arguments in custom keys
    if (&arg1 > 0)
      sp_custom("tb_txtspr_parent", &val1, &arg1);
    if (&arg2 > 0)
      sp_custom("tb_npc_plength", &val1, &arg2);
    if (&arg3 > 0)
      sp_custom("tb_npc_bs", &val1, &arg3);
    if (&arg4 > 0)
      sp_custom("tb_npc_bf", &val1, &arg4);
    if (&arg5 > 0)
      sp_custom("tb_npc_bors", &val1, &arg5);
    if (&arg6 > 0)
      sp_custom("tb_npc_borf", &val1, &arg6);
    if (&arg7 > 0)
      sp_custom("tb_npc_nobd", &val1, &arg7);
    if (&arg8 > 0)
      sp_custom("tb_npc_persist", &val1, &arg8);
    
    //reset text box length custom key
    sp_custom("tb_text_length", &val1, 0);
    
    //check if text box already exists
    &save_x = sp_custom("npc_tb_make_limit", &val1, -1);
    if (&save_x > 0)
    {
      &save_y = sp_custom("npc_tb_make_limit", &save_x, -1);
      if (&save_y == &val1)
      {
        //kill off spawned scripts if they exist
        &save_y = sp_custom("TB_npc_spawned", &save_x, -1);
        if (&save_y > 0)
        {
          run_script_by_number(&save_y, "killscript");
        }
        &save_y = sp_custom("TB_npc_spawned2", &save_x, -1);
        if (&save_y > 0)
        {
          run_script_by_number(&save_y, "killscript");
        }
        &save_y = sp_custom("TB_npc_spawned3", &save_x, -1);
        if (&save_y > 0)
        {
          run_script_by_number(&save_y, "killscript");
        }
        &save_y = sp_custom("TB_npc_spawned4", &save_x, -1);
        if (&save_y > 0)
        {
          run_script_by_number(&save_y, "killscript");
        }
        &save_y = sp_custom("TB_npc_spawned5", &save_x, -1);
        if (&save_y > 0)
        {
          run_script_by_number(&save_y, "killscript");
        }
        
        sp_custom("TB_npc_spawned", &save_x, 0);
        sp_custom("TB_npc_spawned2", &save_x, 0);
        sp_custom("TB_npc_spawned3", &save_x, 0);
        sp_custom("TB_npc_spawned4", &save_x, 0);
        sp_custom("tb_npc_proc", &save_x, 0);
        sp_custom("tb_npc_proc2", &save_x, 0);
        sp_custom("tb_npc_proc3", &save_x, 0);
        sp_custom("tb_npc_proc4", &save_x, 0);
        sp_custom("tb_npc_proc5", &save_x, 0);
        
        //kill off previous text box for this sprite
        &save_x = sp_custom("npc_tb_make_limit", &val1, -1);
        &save_y = sp_custom("tb_npc_nobd", &val1, -1);
        if (&save_y <= 0)
        {
          &save_y = sp_custom("tb_border-bottom", &save_x, -1);
          if (&save_y > 0)
            sp_active(&save_y, 0);
          &save_y = sp_custom("tb_border-top", &save_x, -1);
          if (&save_y > 0)
            sp_active(&save_y, 0);
          &save_y = sp_custom("tb_border-right", &save_x, -1);
          if (&save_y > 0)
            sp_active(&save_y, 0);
          &save_y = sp_custom("tb_border-left", &save_x, -1);
          if (&save_y > 0)
            sp_active(&save_y, 0);
        }
        &save_y = sp_custom("tb_npc_text_parent", &save_x, -1);
        sp_custom("npc_tb_make_limit", &save_y, 0);
        sp_active(&save_x, 0);
      }
    }
    
    //check the default text x and y offset value for this sprite
    //we do this by creating a blank say line, checking it's defense value, storing it and then killing off the text.
    &save_x = say("", &val1);
    &save_y = sp_defense(&save_x, -1);
    sp_custom("tb_default_text_y_offset", &val1, &save_y);
    &save_y = sp_strength(&save_x, -1);
    sp_custom("tb_default_text_x_offset", &val1, &save_y);
    sp_active(&save_x, 0);
    
    //create a placeholder text box in preperation for future text
    text_box_blank(10, 10, 10, 10, &arg3, &arg4, &arg5, &arg6, &arg7);
    &save_x = &return;
    sp_custom("npc_tb_make_limit", &val1, &save_x);
    sp_custom("npc_tb_make_limit", &save_x, &val1);
    sp_custom("tb_npc_text_num", &save_x, &val1);
    
    //make invisible
    &save_y = sp_custom("tb_npc_nobd", &val1, -1);
    if (&save_y <= 0)
    {
      &save_y = sp_custom("tb_border-bottom", &save_x, -1);
      if (&save_y > 0)
        sp_nodraw(&save_y, 1);
      &save_y = sp_custom("tb_border-top", &save_x, -1);
      if (&save_y > 0)
        sp_nodraw(&save_y, 1);
      &save_y = sp_custom("tb_border-right", &save_x, -1);
      if (&save_y > 0)
        sp_nodraw(&save_y, 1);
      &save_y = sp_custom("tb_border-left", &save_x, -1);
      if (&save_y > 0)
        sp_nodraw(&save_y, 1);
    }
    sp_nodraw(&save_x, 1);
    
    //sprite is not currently talking - spawn the script instance that will wait for the text
    sp_custom("tb_npc_proc1", &save_x, &current_script);
    spawn("dctb-spn");
    &save_x = sp_custom("npc_tb_make_limit", &val1, -1);
    return(&save_x);
  }
  else
  {
    //script is called by spawned dctb script instance

    //player map check
    &save_x = sp_custom("tb_pmap", &val1, -1);
    if (&save_x != &player_map)
    {
     kill_this_task();
    }
    
    //double check text box is still active
    &save_x = sp_custom("npc_tb_make_limit", &val1, -1);
    if (&save_x > 0)
    {
      &val2 = busy(&val1);
      sp_custom("tb_text_sprite", &val1, &val2);
      
      if (&val2 <= 0)
      {
        //somehow text vanished during execution of this procedure
        //I don't actually think this should be possible, but I'll account for this just in case
        //The Dink Engine can be weird sometimes.
        
        //reset text sprite store custom key.
        sp_custom("tb_npc_text_num", &val1, 0);
        
        //return to spawned dctt instance and make it keep waiting for a text sprite.
        return(1);
      }
      
      //kill off any currently active spawned instance of "TB_npc_spawned"
      &save_y = sp_custom("TB_npc_spawned", &save_x, -1);
      if (&save_y > 0)
      {
        run_script_by_number(&save_y, "killscript");
      }
      
      //kill off any currently active spawned instance of "TB_npc_spawned2" and "TB_npc_spawned3"
      &save_y = sp_custom("TB_npc_spawned2", &save_x, -1);
      if (&save_y > 0)
      {
        run_script_by_number(&save_y, "killscript");
      }
      &save_y = sp_custom("TB_npc_spawned3", &save_x, -1);
      if (&save_y > 0)
      {
        run_script_by_number(&save_y, "killscript");
      }
    }
    
    //get the correct text_box length, based on whichever was last set and priority
    &save_x = sp_custom("tb_text_length", &val1, -1);
    if (&save_x <= 0)
    {
      &save_y = sp_custom("tb_bulk_count", &val1, -1);
      &save_y += 1;
      sp_custom("tb_bulk_count", &val1, &save_y);
      if (&save_y == 1)
      {
        &save_x = sp_custom("tb_bulk_length1", &val1, -1);
      }
      if (&save_y == 2)
      {
        &save_x = sp_custom("tb_bulk_length2", &val1, -1);
      }
      if (&save_y == 3)
      {
        &save_x = sp_custom("tb_bulk_length3", &val1, -1);
      }
      if (&save_y == 4)
      {
        &save_x = sp_custom("tb_bulk_length4", &val1, -1);
      }
      if (&save_y == 5)
      {
        &save_x = sp_custom("tb_bulk_length5", &val1, -1);
      }
      if (&save_y == 6)
      {
        &save_x = sp_custom("tb_bulk_length6", &val1, -1);
      }
      if (&save_y == 7)
      {
        &save_x = sp_custom("tb_bulk_length7", &val1, -1);
      }
    }
    if (&save_x <= 0)
    {
      &save_x = &arg2;
    }
    sp_custom("tb_textbox_length", &val1, &save_x);
    
    //initialise the correct text_box height setting to run calculations from, based on whichever was last set and the priority
    &save_x = sp_custom("tb_box_lines", &val1, -1);
    if (&save_x <= 0)
    {
      &save_x = sp_custom("tb_box_height", &val1, -1);
    }
    else
    {
      &save_x *= 19;
      &save_x += 4;
    }
    if (&save_x <= 0)
    {
      &save_x = &arg2;
    }
    sp_custom("tb_textbox_height", &val1, &save_x);
    
    //get position of text box placement
    &save_x = sp_custom("npc_tb_make_limit", &val1, -1);
    tb_npc_getxy(&val1, &val2, &save_x);
    &save_x = sp_custom("tb_npc_getxy-x", &val1, -1);
    &save_y = sp_custom("tb_npc_getxy-y", &val1, -1);
    
    //get actual width and height of text box
    tb_npc_getwh(&val1, &arg2);
    &val2 = sp_custom("tb_npc_getwh-h", &val1, -1);
    &val1 = sp_custom("tb_npc_getwh-w", &val1, -1);
    
    text_box_adjust(&save_x, &save_y, &val1, &val2, &arg1);
    &save_x = &return;
    
    //make visible
    &save_y = sp_custom("tb_border-bottom", &save_x, -1);
    if (&save_y > 0)
      sp_nodraw(&save_y, 0);
    &save_y = sp_custom("tb_border-top", &save_x, -1);
    if (&save_y > 0)
      sp_nodraw(&save_y, 0);
    &save_y = sp_custom("tb_border-right", &save_x, -1);
    if (&save_y > 0)
      sp_nodraw(&save_y, 0);
    &save_y = sp_custom("tb_border-left", &save_x, -1);
    if (&save_y > 0)
      sp_nodraw(&save_y, 0);
    sp_nodraw(&save_x, 0);
    
    if (&arg7 > 0)
    {
      &save_y = sp_custom("tb_border-bottom", &save_x, 0);
      &save_y = sp_custom("tb_border-top", &save_x, 0);
      &save_y = sp_custom("tb_border-right", &save_x, 0);
      &save_y = sp_custom("tb_border-left", &save_x, 0);
    }
    
    //store the parent sprite of the text
    &val1 = &arg1;
    if (&val1 <= 0)
    {
      &val1 = &current_sprite;
    }
    sp_custom("tb_npc_text_parent", &save_x, &val1);
    
    //store the text sprite
    &save_y = busy(&val1);
    sp_custom("tb_npc_text_num", &save_x, &save_y);
    
    //store the text box in a custom key attached to the parent sprite and vice versa
    sp_custom("npc_tb_make_limit", &val1, &save_x);
    sp_custom("npc_tb_make_limit", &save_x, &val1);
    
    //spawn the script instance that will wait for the text to vanish
    sp_custom("tb_npc_proc2", &save_x, &current_script);
    spawn("dctb-spn");
  }
  
  &save_x = sp_custom("npc_tb_make_limit", &val1, -1);
  return(&save_x);
}

void text_box_adjust(void)
{
  //procedure called to automatically adjust box for NPC text.
  
  ////////////////////////////////////////
  //Empty box creation - required values//
  ////////////////////////////////////////
  //&arg1 = x position of text box
  //&arg2 = y position of text box
  //&arg3 = length of box
  //&arg4 = height of box
  //&arg5 = Parent sprite (sprite doing the talking)
  
  //local vars
  int &val1;
  int &val2;

  //player map check
  &save_x = sp_custom("tb_pmap", &arg5, -1);
  if (&save_x != &player_map)
  {
   kill_this_task();
  }
  
  //get the text box
  &save_x = &arg5;
  &save_x = sp_custom("npc_tb_make_limit", &save_x, -1);
  sp_x(&save_x, &arg1);
  sp_y(&save_x, &arg2);
  
  //save x position
  &val1 = &arg1;
  sp_custom("tb_adj_xpos", &save_x, &val1);
  
  &val2 = &arg3;
  if (&val2 < 600)
  {
    if (&val2 > 0)
    {
tb_adjust_length:
      &save_y = sp_custom("tb_npc_nobd", &arg5, -1);
      if (&save_y <= 0)
      {
        &save_y = sp_custom("tb_border-top", &save_x, -1);
        if (&save_y > 0)
          sp_x(&save_y, &val1);
        &save_y = sp_custom("tb_border-bottom", &save_x, -1);
        if (&save_y > 0)
          sp_x(&save_y, &val1);
        &save_y = sp_custom("tb_border-left", &save_x, -1);
        if (&save_y > 0)
          sp_x(&save_y, &val1);
        &save_y = sp_custom("tb_border-right", &save_x, -1);
        if (&save_y > 0)
          sp_x(&save_y, &val1);
      }
      
      //simply use sp_clip_right to display the amount of pixels we want
      sp_clip_right(&save_x, &val2);
      
      //do the bottom and top borders as well
      &save_y = sp_custom("tb_npc_nobd", &arg5, -1);
      if (&save_y <= 0)
      {
        &save_y = sp_custom("tb_border-bottom", &save_x, -1);
        &val1 = &val2;
        &val1 += 4;
        sp_clip_right(&save_y, &val1);
        &save_y = sp_custom("tb_border-top", &save_x, -1);
        &val1 = &val2;
        &val1 += 4;
        sp_clip_right(&save_y, &val1);
      }
      
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
tb_adjust_length_bugfix:
        //move the main text box left one and adjust clip size to show 1 more pixel on the right as well
        &save_y = sp_custom("tb_adj_xpos", &save_x, -1);
        &save_y -= 1;
        if (&save_y == -1)
        {
          &save_y -= 1;
          &val2 = sp_clip_right(&save_x, -1);
          &val2 += 1;
          sp_clip_right(&save_x, &val2);
        }
        sp_x(&save_x, &save_y);
        &val2 = sp_clip_right(&save_x, -1);
        &val2 += 1;
        &val1 = &save_y;
        goto tb_adjust_length;
      }
      &save_y = sp_x(&save_x, &save_y);
      
      //save where the box centre is(on the x axis) in a custom key
      &save_y -= sp_custom("tb_offset_x", &save_x, -1);
      sp_custom("tb_x_centre", &save_x, &save_y);
      
      &save_y = sp_custom("tb_npc_nobd", &arg5, -1);
      if (&save_y <= 0)
      {
        //centre the borders on the x axis - top first
        &save_y = sp_custom("tb_border-top", &save_x, -1);
        &val1 = sp_x(&save_y, -1);
        &val1 += sp_custom("tb_offset_x", &save_x, -1);
        if (&val1 == -1)
        {
          goto tb_adjust_length_bugfix;
        }
        sp_x(&save_y, &val1);
        
        //now - x axis  bottom
        &save_y = sp_custom("tb_border-bottom", &save_x, -1);
        &val1 = sp_x(&save_y, -1);
        &val1 += sp_custom("tb_offset_x", &save_x, -1);
        if (&val1 == -1)
        {
          goto tb_adjust_length_bugfix;
        }
        sp_x(&save_y, &val1);
        
        //now - x axis right
        &save_y = sp_custom("tb_border-right", &save_x, -1);
        &val1 = sp_x(&save_y, -1);
        &val1 -= sp_custom("tb_clip_diff_x", &save_x, -1);
        &val1 += sp_custom("tb_offset_x", &save_x, -1);
        if (&val1 == -1)
        {
          goto tb_adjust_length_bugfix;
        }
        sp_x(&save_y, &val1);
        
        //now - x axis left
        &save_y = sp_custom("tb_border-left", &save_x, -1);
        &val1 = sp_x(&save_y, -1);
        &val1 += sp_custom("tb_offset_x", &save_x, -1);
        if (&val1 == -1)
        {
          goto tb_adjust_length_bugfix;
        }
        sp_x(&save_y, &val1);
      }
    }
  }
  
  //save y position
  &val1 = &arg2;
  sp_custom("tb_adj_ypos", &save_x, &val1);
  
  &val2 = &arg4;
  if (&val2 < 400)
  {
    if (&val2 > 0)
    {
tb_adjust_height:
      &save_y = sp_custom("tb_npc_nobd", &arg5, -1);
      if (&save_y <= 0)
      {
        &save_y = sp_custom("tb_border-top", &save_x, -1);
        sp_y(&save_y, &val1);
        &save_y = sp_custom("tb_border-bottom", &save_x, -1);
        sp_y(&save_y, &val1);
        &save_y = sp_custom("tb_border-left", &save_x, -1);
        sp_y(&save_y, &val1);
        &save_y = sp_custom("tb_border-right", &save_x, -1);
        sp_y(&save_y, &val1);
      }
      
      //simply use sp_clip_bottom to display the amount of pixles we want
      sp_clip_bottom(&save_x, &val2);
      
      &save_y = sp_custom("tb_npc_nobd", &arg5, -1);
      if (&save_y <= 0)
      {
        //do the left and right borders as well
        &save_y = sp_custom("tb_border-right", &save_x, -1);
        sp_clip_bottom(&save_y, &val2);
        &save_y = sp_custom("tb_border-left", &save_x, -1);
        sp_clip_bottom(&save_y, &val2);
      }
      
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
tb_adjust_height_bugfix:
        //move the main text box left one and adjust clip size to show 1 more pixel on the right as well
        &save_y = sp_custom("tb_adj_ypos", &save_x, -1);
        &save_y -= 1;
        if (&save_y == -1)
        {
          &save_y -= 1;
          &val2 = sp_clip_bottom(&save_x, -1);
          &val2 += 1;
          sp_clip_bottom(&save_x, &val2);
        }
        sp_y(&save_x, &save_y);
        &val2 = sp_clip_bottom(&save_x, -1);
        &val2 += 1;
        goto tb_adjust_height;
      }
      &save_y = sp_y(&save_x, &save_y);
      
      //save where the box centre is(on the x axis) in a custom key
      &save_y -= sp_custom("tb_offset_y", &save_x, -1);
      sp_custom("tb_y_centre", &save_x, &save_y);
      
      &save_y = sp_custom("tb_npc_nobd", &arg5, -1);
      if (&save_y <= 0)
      {
        //centre the borders on the y axis - top first
        &save_y = sp_custom("tb_border-left", &save_x, -1);
        &val1 = sp_y(&save_y, -1);
        &val1 += sp_custom("tb_offset_y", &save_x, -1);
        if (&val1 == -1)
        {
          goto tb_adjust_height_bugfix;
        }
        sp_y(&save_y, &val1);
        
        //now - y axis  bottom
        &save_y = sp_custom("tb_border-right", &save_x, -1);
        &val1 = sp_y(&save_y, -1);
        &val1 += sp_custom("tb_offset_y", &save_x, -1);
        if (&val1 == -1)
        {
          goto tb_adjust_height_bugfix;
        }
        sp_y(&save_y, &val1);
        
        //now - y axis bottom
        &save_y = sp_custom("tb_border-bottom", &save_x, -1);
        &val1 = sp_y(&save_y, -1);
        &val1 -= sp_custom("tb_clip_diff_y", &save_x, -1);
        &val1 += sp_custom("tb_offset_y", &save_x, -1);
        if (&val1 == -1)
        {
          goto tb_adjust_height_bugfix;
        }
        sp_y(&save_y, &val1);
        
        //now - y axis top
        &save_y = sp_custom("tb_border-top", &save_x, -1);
        &val1 = sp_y(&save_y, -1);
        &val1 += sp_custom("tb_offset_y", &save_x, -1);
        if (&val1 == -1)
        {
          goto tb_adjust_height_bugfix;
        }
        sp_y(&save_y, &val1);
      }
    }
  }

  return(&save_x);
  kill_this_task();
}

void tbb_fix_nix(void)
{
 //linux fix to revert &ar9 back to 0
 text_box_blank(&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, 0);
 kill_this_task();
}

void text_box_blank(void)
{
  //text box creation called by npc_start.
  
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
  //&arg8 = custom text box border start frame (frame of BOTTOM border sprite, will use next frame for Right, then next for top, then next for left)
  //&arg9 = set to '1' for borderless text box.
  
  //local vars
  int &val1;
  int &val2;
  
  //create the text box
  &save_x = create_sprite(&arg1, &arg2, 0, 30, 5);
  //sp_nodraw(&save_x, 1);
  sp_nohit(&save_x, 1);
  sp_que(&save_x, 10000);
  sp_noclip(&save_x, 1);
  
  //initiliase sprite size for clipping
  sp_clip_right(&save_x, 600);
  sp_clip_bottom(&save_x, 400);
  
  //&arg5 is custom seq, not textpox x position
  if (&arg5 > 0)
  {
    sp_custom("tb_bg_seq", &save_x, &arg5);
    sp_pseq(&save_x, &arg5);
  }
  if (&arg6 > 0)
  {
    sp_custom("tb_bg_frame", &save_x, &arg6);
    sp_pframe(&save_x, &arg6);
  }
  
  if (&arg9 <= 0)
  {
    //set the sequence and frame to be used for borders
    &val1 = &arg7;
    if (&val1 <= 0)
    {
      &val1 = 30;
    }
    &val2 = &arg8;
    if (&val2 <= 0)
    {
      &val2 = 6;
    }
    
    //create the borders
    //bottom
    &save_y = create_sprite(&arg1, &arg2, 0, &val1, &val2);
    //sp_nodraw(&save_y, 1);
    sp_nohit(&save_y, 1);
    sp_que(&save_y, 10000);
    sp_noclip(&save_y, 1);
    sp_custom("tb_border-bottom", &save_x, &save_y);
    
    //initiliase sprite size for clipping
    sp_clip_right(&save_y, 604);
    sp_clip_bottom(&save_y, 400);
    
    //increment border frame
    &val2 += 1;
    
    //right
    &save_y = create_sprite(&arg1, &arg2, 0, &val1, &val2);
    //sp_nodraw(&save_y, 1);
    sp_nohit(&save_y, 1);
    sp_que(&save_y, 10000);
    sp_noclip(&save_y, 1);
    sp_custom("tb_border-right", &save_x, &save_y);
    
    sp_clip_right(&save_y, 600);
    sp_clip_bottom(&save_y, 400);
    &val2 += 1;
    
    //top
    &save_y = create_sprite(&arg1, &arg2, 0, &val1, &val2);
    //sp_nodraw(&save_y, 1);
    sp_nohit(&save_y, 1);
    sp_que(&save_y, 10000);
    sp_noclip(&save_y, 1);
    sp_custom("tb_border-top", &save_x, &save_y);
    sp_clip_right(&save_y, 604);
    sp_clip_bottom(&save_y, 400);
    &val2 += 1;
    
    //left
    &save_y = create_sprite(&arg1, &arg2, 0, &val1, &val2);
    //sp_nodraw(&save_y, 1);
    sp_nohit(&save_y, 1);
    sp_que(&save_y, 10000);
    sp_noclip(&save_y, 1);
    sp_custom("tb_border-left", &save_x, &save_y);
    sp_clip_right(&save_y, 600);
    sp_clip_bottom(&save_y, 400);
  }
  
  &val2 = &arg3;
  if (&val2 < 600)
  {
    if (&val2 > 0)
    {
tb_blank_length:
      if (&arg9 <= 0)
      {
        &save_y = sp_custom("tb_border-top", &save_x, -1);
        sp_x(&save_y, &arg1);
        &save_y = sp_custom("tb_border-bottom", &save_x, -1);
        sp_x(&save_y, &arg1);
        &save_y = sp_custom("tb_border-left", &save_x, -1);
        sp_x(&save_y, &arg1);
        &save_y = sp_custom("tb_border-right", &save_x, -1);
        sp_x(&save_y, &arg1);
      }
      
      //simply use sp_clip_right to display the amount of pixels we want
      sp_clip_right(&save_x, &val2);
      
      if (&arg9 <= 0)
      {
        //do the bottom and top borders as well
        &save_y = sp_custom("tb_border-bottom", &save_x, -1);
        &val1 = &val2;
        &val1 += 4;
        sp_clip_right(&save_y, &val1);
        &save_y = sp_custom("tb_border-top", &save_x, -1);
        &val1 = &val2;
        &val1 += 4;
        sp_clip_right(&save_y, &val1);
      }
      
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
      &save_y = sp_x(&save_x, &save_y);
      
      //save where the box centre is(on the x axis) in a custom key
      &save_y -= sp_custom("tb_offset_x", &save_x, -1);
      sp_custom("tb_x_centre", &save_x, &save_y);
      
      if (&arg9 <= 0)
      {
        //centre the borders on the x axis - top first
        &save_y = sp_custom("tb_border-top", &save_x, -1);
        &val1 = sp_x(&save_y, -1);
        &val1 += sp_custom("tb_offset_x", &save_x, -1);
        if (&val1 == -1)
        {
          goto tb_blank_length_bugfix;
        }
        sp_x(&save_y, &val1);
        
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
  }
  
  &val2 = &arg4;
  if (&val2 < 400)
  {
    if (&val2 > 0)
    {
tb_blank_height:
      if (&arg9 <= 0)
      {
        &save_y = sp_custom("tb_border-top", &save_x, -1);
        sp_y(&save_y, &arg2);
        &save_y = sp_custom("tb_border-bottom", &save_x, -1);
        sp_y(&save_y, &arg2);
        &save_y = sp_custom("tb_border-left", &save_x, -1);
        sp_y(&save_y, &arg2);
        &save_y = sp_custom("tb_border-right", &save_x, -1);
        sp_y(&save_y, &arg2);
      }
      
      //simply use sp_clip_bottom to display the amount of pixles we want
      sp_clip_bottom(&save_x, &val2);
      
      if (&arg9 <= 0)
      {
        //do the left and right borders as well
        &save_y = sp_custom("tb_border-right", &save_x, -1);
        sp_clip_bottom(&save_y, &val2);
        &save_y = sp_custom("tb_border-left", &save_x, -1);
        sp_clip_bottom(&save_y, &val2);
      }
      
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
        //move the main text box left one and adjust clip size to show 1 more pixel on the right as well
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
      
      if (&arg9 <= 0)
      {
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
  }

  return(&save_x);
  kill_this_task();
}

void killscript(void)
{
  //used to kill any proc calls, or a spawned instance of this script
  kill_this_task();
}
