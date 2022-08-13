void main(void)
{
  //this script should never be attached to a sprite.
  //So this procedure won't run unless an instance of this script is spawned.
  
  //&save_x = active sprite of text box of talking sprite, depending on calling proc.
  
  //local variable
  int &val1 = &save_x;
  
  &save_x = sp_custom("tb_halt_proc", &val1, -1);
  if (&save_x > 0)
  {
    //spawned from text_box_halt
    //save current script instance
    sp_custom("TB_halt_spawned", &val1, &current_script);
    
    //wait the specified text box timout.
    spwn_wait_loop:
    wait(49);
    &save_x = sp_custom("tb_halt_time", &val1, -1);
    &save_x -= 50;
    wait(1);
    sp_custom("tb_halt_time", &val1, &save_x);

    //check for screen change
    &save_x = sp_custom("TB_pmap", &val1, -1);
    if (&save_x != &player_map)
    {
      kill_this_task();
    }
    if (&save_x > 0)
    {
     goto spwn_wait_loop;
    }
    
    //timout done and player didn't press space, poke the script to time out manually
    sp_custom("tb_timeout", &val1, 1);
    
    //get the script number that spawned this script
    &save_x = sp_custom("tb_halt_proc", &val1, -1);
    if (&save_x > 0)
    {
      run_script_by_number(&save_x, "text_box_halt");
    }
    
    sp_custom("tb_halt_proc", &val1, 0);
    sp_custom("TB_halt_spawned", &val1, 0);
  }
  
  kill_this_task();
}