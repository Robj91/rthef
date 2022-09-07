//paranoid, delirious dude

void main(void)
{
 int &val1;
}

void talk(void)
{
 freeze(1);
 freeze(&current_sprite);
 
 &val1 = say("`7Nothing was like this, it's a sign, a sign of the apocalyspe and the            the Seth.", &current_sprite);
 &save_x = sp_x(&val1, -1);
 &save_y = sp_y(&val1, -1);
 sp_active(&val3, 0);
 if (&vcheck == 111)
 {
  &save_x -= 272
  &save_y += 76
  &val1 = say_xy("`%rise of", &save_x, &save_y);
  sp_kill(&val1, 0);
  say_stop("`7Nothing was like this, it's a sign, a sign of the apocalyspe and the            the Seth.", &current_sprite);
 }
 else
 {
  &save_x -= 232
  &save_y += 76
  &val1 = say_xy("`%rise of", &save_x, &save_y);
  sp_kill(&val1, 0);
  say_stop("`7Nothing was like this, it's a sign, a sign of the apocalyspe and the             the Seth.", &current_sprite);
 } 
 
 sp_active(&val1, 0);
 say_stop("`7He's coming back. We're all screwed.", &current_sprite);
 
 unfreeze(1);
 unfreeze(&current_sprite);
}