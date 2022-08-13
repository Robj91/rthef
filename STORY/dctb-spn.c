//ROBJ'S Attempt at a somewhat automated NPC conversation text boxes//
//this script is spawned in certain situations by 'dctb-npc.c'

void main(void)
{
  //this script should never be attached to a sprite.
  //So this procedure won't run unless an instance of this script is spawned by dctb-npc.c
  
  //&save_x = active sprite of text box.
  
  //local variable
  int &val1 = &save_x;
  
  &save_x = sp_custom("tb_npc_proc1", &val1, -1);
  if (&save_x > 0)
  {
    sp_custom("tb_npc_proc1", &val1, 0);
    &save_y = sp_custom("TB_npc_spawned2", &val1, -1);
    if (&save_y > 0)
    {
      run_script_by_number(&save_y, "killscript");
    }
    sp_custom("TB_npc_spawned2", &val1, &current_script);
    run_script_by_number(&save_x, "killscript");
npc_pre_busy_loop:
    &save_y = sp_custom("npc_tb_make_limit", &val1, -1);

    //player map check
    &save_x = sp_custom("tb_pmap", &save_y, -1);
    if (&save_x != &player_map)
    {
     kill_this_task();
    }  

    &save_y = busy(&save_y);
    if (&save_y > 0)
    {
      //set the spawned custom key to 0
      sp_custom("TB_npc_spawned2", &val1, 0);
      
      &vision = sp_custom("tb_npc_text_num", &val1, -1);
      &save_x = sp_custom("tb_npc_plength", &vision, -1);
      &save_y = sp_custom("tb_npc_nobd", &vision, -1);
      external("dctb-npc", "text_box_npc_start", &vision, &save_x, 0, 0, 0, 0, &save_y, -99);
      if (&return == 1)
      {
        wait(1);
        goto npc_pre_busy_loop;
      }
      
      kill_this_task();
    }
    else
    {
      wait(1);
      goto npc_pre_busy_loop;
    }
  }
  
  &save_x = sp_custom("tb_npc_proc2", &val1, -1);
  if (&save_x > 0)
  {
    sp_custom("tb_npc_proc2", &val1, 0);
    &save_y = sp_custom("TB_npc_spawned", &val1, -1);
    if (&save_y > 0)
    {
      run_script_by_number(&save_y, "killscript");
    }
    sp_custom("TB_npc_spawned", &val1, &current_script);
    run_script_by_number(&save_x, "killscript");
npc_busy_loop:
    &save_y = sp_custom("npc_tb_make_limit", &val1, -1);
    
    //player map check
    &save_x = sp_custom("tb_pmap", &save_y, -1);
    if (&save_x != &player_map)
    {
     kill_this_task();
    }      
    
    &save_y = busy(&save_y);
    if (&save_y <= 0)
    {
      sp_custom("tb_npc_text_num", &val1, 0);
      
      &save_y = sp_custom("tb_npc_text_parent", &val1, -1);
      if (&save_y > 0)
      {
        &save_x = sp_custom("tb_npc_persist", &save_y, -1);
        if (&save_x <= 0)
        {
          &save_x = sp_custom("tb_npc_nobd", &save_y, -1);
          if (&save_x <= 0)
          {
            &save_y = sp_custom("tb_border-bottom", &val1, -1);
            if (&save_y > 0)
              sp_nodraw(&save_y, 1);
            &save_y = sp_custom("tb_border-top", &val1, -1);
            if (&save_y > 0)
              sp_nodraw(&save_y, 1);
            &save_y = sp_custom("tb_border-right", &val1, -1);
            if (&save_y > 0)
              sp_nodraw(&save_y, 1);
            &save_y = sp_custom("tb_border-left", &val1, -1);
            if (&save_y > 0)
              sp_nodraw(&save_y, 1);
          }
          sp_nodraw(&val1, 1);
        }
      }
    }
    else
    {
      wait(1);
      goto npc_busy_loop;
    }
    
    sp_custom("TB_npc_spawned", &val1, 0);
    sp_custom("tb_npc_proc3", &val1, &current_script);
    ///let this proceed onto the next check, which is where we want to go from here anyway.
  }
  
  &save_x = sp_custom("tb_npc_proc3", &val1, -1);
  if (&save_x > 0)
  {
    sp_custom("tb_npc_proc3", &val1, 0);
    &save_y = sp_custom("TB_npc_spawned3", &val1, -1);
    if (&save_y > 0)
    {
      run_script_by_number(&save_y, "killscript");
    }
    sp_custom("TB_npc_spawned3", &val1, &current_script);
npc_post_busy_loop:
    &save_y = sp_custom("npc_tb_make_limit", &val1, -1);
    
    //player map check
    &save_x = sp_custom("tb_pmap", &save_y, -1);
    if (&save_x != &player_map)
    {
     kill_this_task();
    }      
    
    &save_y = busy(&save_y);
    if (&save_y > 0)
    {
      sp_custom("TB_npc_spawned3", &val1, 0);
      
      //retrieve values that need to be passed to external
      &vision = sp_custom("npc_tb_make_limit", &val1, -1);
      &save_x = sp_custom("tb_npc_plength", &vision, -1);
      &save_y = sp_custom("tb_npc_nobd", &vision, -1);
      
      external("dctb-npc", "text_box_npc_start", &vision, &save_x, 0, 0, 0, 0, &save_y, -99);
      if (&return == 1)
      {
        sp_custom("TB_npc_spawned3", &val1, &current_script);
        wait(1);
        goto npc_post_busy_loop;
      }
      
      kill_this_task();
    }
    else
    {
      wait(1);
      goto npc_post_busy_loop;
    }
  }
  
  &save_x = sp_custom("tb_npc_proc4", &val1, -1);
  if (&save_x > 0)
  {
    &save_y = sp_custom("TB_npc_spawned4", &val1, -1);
    if (&save_y > 0)
    {
      run_script_by_number(&save_y, "killscript");
    }
    sp_custom("TB_npc_spawned4", &val1, &current_script);
    run_script_by_number(&save_x, "killscript");
    sp_custom("tb_npc_proc4", &val1, 0);
    wait(0);
    
    //check if text is still being displayed
text_box_npc_end_wait:
    &save_y = sp_custom("npc_tb_make_limit", &val1, -1);
    
    //player map check
    &save_x = sp_custom("tb_pmap", &save_y, -1);
    if (&save_x != &player_map)
    {
     kill_this_task();
    }    
    
    &save_x = busy(&save_y);
    if (&save_x > 0)
    {
      &save_y = sp_custom("tb_npc_text_num", &val1, -1);
      if (&save_y == &save_x)
      {
        //previous text is still up, we need to wait
        wait(0);    
        goto text_box_npc_end_wait;
      }
      else
      {
        //this is not the text sprite instance this end script was called for - kill this off.
        // (Another end script has probably been called already, we don't want to run it twice).
        kill_this_task();
      }
    }
    
    //kill off spawned scripts if they exist
    &save_x = &val1;
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
    
    &save_y = sp_custom("tb_npc_text_parent", &save_x, -1);
    &save_y = sp_custom("tb_npc_nobd", &save_y, -1);
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
  
  &save_x = sp_custom("tb_npc_proc5", &val1, -1);
  if (&save_x > 0)
  {
    &save_y = sp_custom("TB_npc_spawned5", &val1, -1);
    if (&save_y > 0)
    {
      run_script_by_number(&save_y, "killscript");
    }
    sp_custom("TB_npc_spawned5", &val1, &current_script);
    //run_script_by_number(&save_x, "killscript");
    sp_custom("tb_npc_proc5", &val1, 0);
tb_npc_shadow_loop:
    //make sure text box exists, and if so, retrieve it.
    &save_x = sp_custom("npc_tb_make_limit", &val1, -1);
    if (&save_x > 0)
    {
      &save_y = sp_custom("npc_tb_make_limit", &save_x, -1);
      if (&save_y == &val1)
      {
        &save_y = sp_custom("npc_tb_make_limit", &val1, -1);
        
        //player map check
        &save_x = sp_custom("tb_pmap", &save_y, -1);
        if (&save_x != &player_map)
        {
         kill_this_task();
        }          
        
        busy(&save_y);
        if (&return > 0)
        {
          //get position of text box placement
          busy(&save_y);
          external("dctb-npc", "tb_npc_getxy", &val1, &return);
          
          &save_x = sp_custom("tb_npc_getxy-x", &val1, -1);
          &save_y = sp_custom("tb_npc_getxy-y", &val1, -1);
          
          //get actual width and height of text box
          sp_custom("tb_npc_plength", &val1, -1);
          external("dctb-npc", "tb_npc_getwh", &val1, &return);
          &vision = sp_custom("tb_npc_getwh-h", &val1, -1);
          sp_custom("tb_npc_getwh-w", &val1, -1);
          
          //call the procedure that will adjust all elements of the text box to the new location
          external("dctb-npc", "text_box_adjust", &save_x, &save_y, &return, &vision, &val1, 0, 0, 0);
          
          //a quick update of the text to reduce the jittering effect
          &save_x = busy(&val1);
          &save_y = sp_y(&val1, -1);
          &vision = sp_defense(&save_x, -1);
          &save_y -= &vision;
          if (&save_y < 1)
          {
            &save_y = 1;
          }
          sp_y(&save_x, &save_y);
          &save_y = sp_x(&val1, -1);
          &vision = sp_strength(&save_x, -1);
          &save_y -= &vision;
          if (&save_y < 1)
          {
            &save_y = 1;
          }
          if (&save_y > 470)
          {
            &save_y = 470;
          }
          sp_x(&save_x, &save_y);
        }
        
        wait(0);
        goto tb_npc_shadow_loop;
      }
    }
    
    sp_custom("TB_npc_spawned5", &val1, 0);
    kill_this_task();
  }
  
  kill_this_task();
}

void killscript(void)
{
  //used to kill any proc calls, or a spawned instance of this script
  kill_this_task();
}
