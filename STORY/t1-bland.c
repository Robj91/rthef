void main(void)
{
 editor_type(1, 0);

 &save_x = editor_frame(1, -1);
 if (&save_x == 0)
 {
  wait(1000);
  external("dc-f", "remoteframe", 700, 1, -1);
  &save_x = &return;
  if (&save_x == 0)
  {
   say("The scenery seems off around here... it's just.. bland.", 1);
   external("dc-f", "remoteframe", 700, 1, 1);  
   editor_frame(1, 1);
  }
  if (&save_x == 1)
  {
   say("This town seems very boring, and somehow incomplete. Something's wrong...", 1);  
   external("dc-f", "remoteframe", 700, 1, 2);  
   editor_frame(1, 1);
  }
 }
}