void main(void)
{
 int &val1;
 int &keytoggle;
}

void click(void)
{
 if (&keytoggle == 0)
 {
  &keytoggle = 1;
  &save_x = create_sprite(308, 407, 0, 98, 7);
  sp_noclip(&save_x, 1);
  sp_que(&save_x, 1001);
  sp_custom("keyboard", &current_sprite, &save_x);  
 }
 else
 {
  &keytoggle = 0;
  &save_x = sp_custom("keyboard", &current_sprite, -1);  
  sp_active(&save_x, 0);
 }
}