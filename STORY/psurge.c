//Script to make power surge text flash rapidly

void main(void)
{
loop: 
  
  wait(20);
  sp_pframe(&current_sprite, 5);
  wait(20);
  sp_pframe(&current_sprite, 4);

  if (&save_x == 1)
	kill_this_task();

goto loop;
}
