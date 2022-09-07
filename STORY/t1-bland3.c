void main(void)
{
 &save_x = editor_frame(1, -1);
 if (&save_x == 0)
 {
  int &val1;
  
  wait(1000);
  if (&player_map == 699)
  {
   &val1 = 732;
  }
  if (&player_map == 732)
  {
   &val1 = 699;
  }
  
  external("dc-f", "remoteframe", &val1, 1, -1);
  &val1 = &return;
  if (&val1 == 0)
  {
   say("Actually reminds me of Goodheart Kingdom", 1);
   editor_frame(1, 1);
  }
 }
}