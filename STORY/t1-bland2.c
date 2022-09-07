void main(void)
{
 &save_x = editor_frame(1, -1);
 if (&save_x == 0)
 {
  wait(1000);
  say("Not much scenery around here", 1);
  editor_frame(1, 1);
 }
}