void main(void)
{
 &save_x = editor_frame(2, -1);
 if (&save_x == 0)
 {
  int &val1;
  
  wait(1000);
  if (&player_map == 733)
  {
   &val1 = 667;
  }
  if (&player_map == 667)
  {
   &val1 = 733;
  }
  
  external("dc-f", "remoteframe", &val1, 2, -1);
  &val1 = &return;
  if (&val1 == 0)
  {
   say("Yeh, this place looks like shit.", 1);
   editor_frame(2, 1);
  }
 }
}