//pumpkin farmer

void main(void)
{
 int &val1;
 int &val2;
 int &val3;
}

void talk(void)
{
 freeze(1);
 freeze(&current_sprite);
 
 //set the font colour
 set_font_color(12, 255, 90, 90);
 set_font_color(4, 189, 94, 94);
 
 say_stop("`4It's fucked, the whole crops fucked. Help me. Help, you tight wearing, bandana bitch!", &current_sprite);
 wait(200);
 say_stop("Um. What?", 1);
 wait(200);
 say_stop("`4Are you dumb? You're just gonna stand there flabbergasted?", &current_sprite);
 
 &val3 = say("`4I water all         of my pumpkins everyday, they are a very delicate breed,     it's an eight hour       ", &current_sprite);
 &save_x = sp_x(&val3, -1);
 &save_y = sp_y(&val3, -1);
 sp_active(&val3, 0);
 if (&vcheck == 111)
 {
  &save_x -= 206;
  &val1 = say_xy("`@nine", &save_x, &save_y);
  &save_x -= 28
  &save_y += 95
  &val2 = say_xy("`@job", &save_x, &save_y);
  sp_kill(&val1, 0);
  sp_kill(&val2, 0);
  say_stop("`4I water all         of my pumpkins everyday, they are a very delicate breed,     it's an eight hour       ", &current_sprite);
 }
 else
 {
  &save_x -= 206;
  &val1 = say_xy("`@nine", &save_x, &save_y);
  &save_x -= 12
  &save_y += 95
  &val2 = say_xy("`@job", &save_x, &save_y);
  sp_kill(&val1, 0);
  sp_kill(&val2, 0);
  say_stop("`4I water all         of my pumpkins everyday, they are a very delicate breed, it's an eight hour       ", &current_sprite);
 }
 sp_active(&val1, 0);
 sp_active(&val2, 0);
 wait(200);
 say_stop("ok... and?", 1);
 wait(200);
 say_stop("`4AND DO YOU SEE ANY PUMPKINS ASSHOLE? NO THEY'RE ALL GONE", &current_sprite);
 wait(200);
 say_stop("This towns fucked. bye.", 1);
 
 //revert the font colour
 set_font_color(12, 255, 255, 2); 
 set_font_color(4, 255, 156, 74); 
 
 unfreeze(1);
 unfreeze(&current_sprite);
}