void main( void )
 {
 //preloading an invisible sprite???
 preload_seq(80);
 //variable for gargoyles
 int &junk;
 //coordinates of house
 int &my_x = sp_x(&current_sprite, -1);
 int &my_y = sp_y(&current_sprite, -1);
 //coordinates for gargoyles
 int &put_x;
 int &put_y;
 //house sequence and frame
 int &my_seq = sp_pseq(&current_sprite, -1);
 int &my_frame = sp_pframe(&current_sprite, -1);
 //first we do stone houses
 if (&my_seq == 63)
  {
  if (&my_frame == 1)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   //relative postion of gargoyle to house, as determined empirically via the prototype
   &put_x += -110;
   &put_y += 25;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -110;
   &put_y += -25;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -74;
   &put_y += -58;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -33;
   &put_y += -84;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 18;
   &put_y += -84;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 69;
   &put_y += -84;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 120;
   &put_y += -84;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 153;
   &put_y += -60;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 153;
   &put_y += -11;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 133;
   &put_y += 10;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 84;
   &put_y += 31;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 33;
   &put_y += 57;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -18;
   &put_y += 77;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -64;
   &put_y += 49;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -53;
   &put_y += -75;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -93;
   &put_y += -41;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -88;
   &put_y += 36;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -41;
   &put_y += 62;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 8;
   &put_y += 68;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 61;
   &put_y += 44;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 108;
   &put_y += 20;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  if (&my_frame == 4)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -93;
   &put_y += -22;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -42;
   &put_y += -22;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 9;
   &put_y += -22;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 60;
   &put_y += -22;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 88;
   &put_y += -22;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 94;
   &put_y += 11;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 94;
   &put_y += 48;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 94;
   &put_y += 75;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 52;
   &put_y += 95;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 9;
   &put_y += 119;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -42;
   &put_y += 98;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -93;
   &put_y += 78;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -93;
   &put_y += 28;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -67;
   &put_y += 88;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -18;
   &put_y += 110;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 29;
   &put_y += 107;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 73;
   &put_y += 86;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  if (&my_frame == 5)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -139;
   &put_y += -81;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -99;
   &put_y += -81;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -53;
   &put_y += -81;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -2;
   &put_y += -81;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 46;
   &put_y += -81;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 58;
   &put_y += -42;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 58;
   &put_y += -4;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 32;
   &put_y += 15;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -5;
   &put_y += 33;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -48;
   &put_y += 56;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -96;
   &put_y += 34;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -139;
   &put_y += 15;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -139;
   &put_y += -31;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -118;
   &put_y += 25;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -69;
   &put_y += 47;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 28;
   &put_y += 47;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 13;
   &put_y += 25;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 49;
   &put_y += 5;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  if (&my_frame == 6)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -182;
   &put_y += -121;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -131;
   &put_y += -121;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -29;
   &put_y += -121;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 8;
   &put_y += -96;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 40;
   &put_y += -71;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 75;
   &put_y += -53;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 75;
   &put_y += -3;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 24;
   &put_y += 16;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -27;
   &put_y += 41;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -78;
   &put_y += 23;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -127;
   &put_y += 2;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -156;
   &put_y += -10;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -182;
   &put_y += -23;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -182;
   &put_y += -71;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -101;
   &put_y += 12;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -52;
   &put_y += 28;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -1;
   &put_y += 29;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 50;
   &put_y += 5;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -80;
   &put_y += -121;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  if (&my_frame == 7)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -135;
   &put_y += -78;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -84;
   &put_y += -78;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -33;
   &put_y += -78;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 18;
   &put_y += -78;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 48;
   &put_y += -78;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -135;
   &put_y += -49;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 48;
   &put_y += -28;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 48;
   &put_y += -7;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 12;
   &put_y += 5;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -35;
   &put_y += 35;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -86;
   &put_y += 11;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -135;
   &put_y += 1;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -57;
   &put_y += 19;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -10;
   &put_y += 21;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  if (&my_frame == 8)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -134;
   &put_y += -61;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -83;
   &put_y += -61;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -32;
   &put_y += -61;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 19;
   &put_y += -61;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 56;
   &put_y += -61;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 56;
   &put_y += -23;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 18;
   &put_y += 1;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -17;
   &put_y += 14;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -51;
   &put_y += 24;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -102;
   &put_y += 5;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -134;
   &put_y += -11;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -129;
   &put_y += 0;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -78;
   &put_y += 18;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -49;
   &put_y += 37;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -30;
   &put_y += 27;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 37;
   &put_y += -9;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  if (&my_frame == 9)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -132;
   &put_y += -103;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -91;
   &put_y += -103;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -40;
   &put_y += -103;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 11;
   &put_y += -103;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 34;
   &put_y += -103;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 38;
   &put_y += -76;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 64;
   &put_y += -42;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 64;
   &put_y += 8;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 24;
   &put_y += 25;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -21;
   &put_y += 45;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -72;
   &put_y += 36;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -123;
   &put_y += 53;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -174;
   &put_y += 44;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -174;
   &put_y += -6;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -174;
   &put_y += -56;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -154;
   &put_y += -84;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -145;
   &put_y += 62;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -21;
   &put_y += 62;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 4;
   &put_y += 39;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -47;
   &put_y += 19;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  if (&my_frame == 10)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -125;
   &put_y += -108;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -74;
   &put_y += -108;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -23;
   &put_y += -108;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -28;
   &put_y += -108;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 56;
   &put_y += -67;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 56;
   &put_y += -34;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 75;
   &put_y += -2;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 75;
   &put_y += 46;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 24;
   &put_y += 25;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -27;
   &put_y += 32;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -78;
   &put_y += 48;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -129;
   &put_y += 27;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -167;
   &put_y += 7;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -167;
   &put_y += -43;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -145;
   &put_y += -66;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -151;
   &put_y += 17;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -107;
   &put_y += 40;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -78;
   &put_y += 63;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -57;
   &put_y += 42;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -2;
   &put_y += 45;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 44;
   &put_y += 65;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  }
 if (&my_seq == 424)
  {
  if (&my_frame == 1)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -36;
   &put_y += -90;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 12;
   &put_y += -76;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 36;
   &put_y += -49;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 36;
   &put_y += 1;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -15;
   &put_y += 18;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -62;
   &put_y += 14;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -101;
   &put_y += 9;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -101;
   &put_y += -32;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -86;
   &put_y += -73;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 12;
   &put_y += 11;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  if (&my_frame == 2)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -104;
   &put_y += -68;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -53;
   &put_y += -68;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -2;
   &put_y += -68;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 49;
   &put_y += -68;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 49;
   &put_y += -18;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 22;
   &put_y += 12;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -29;
   &put_y += 23;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -80;
   &put_y += 11;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -104;
   &put_y += -18;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -103;
   &put_y += 2;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -59;
   &put_y += 21;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -3;
   &put_y += 21;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 40;
   &put_y += 1;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  if (&my_frame == 3)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -60;
   &put_y += -82;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -9;
   &put_y += -82;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 38;
   &put_y += -49;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 38;
   &put_y += 1;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -10;
   &put_y += 18;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -61;
   &put_y += 18;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -102;
   &put_y += 5;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -110;
   &put_y += -21;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -96;
   &put_y += -62;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -85;
   &put_y += 13;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 15;
   &put_y += 14;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  if (&my_frame == 4)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -45;
   &put_y += -72;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 6;
   &put_y += -72;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 57;
   &put_y += -72;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 87;
   &put_y += -43;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 87;
   &put_y += 7;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 62;
   &put_y += 38;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 11;
   &put_y += 38;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -40;
   &put_y += 38;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -87;
   &put_y += 20;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -87;
   &put_y += -30;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -74;
   &put_y += -62;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -76;
   &put_y += 37;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -12;
   &put_y += 45;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 82;
   &put_y += 21;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  if (&my_frame == 5)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -57;
   &put_y += -14;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -10;
   &put_y += -14;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 36;
   &put_y += -14;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 69;
   &put_y += 22;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 69;
   &put_y += 72;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 39;
   &put_y += 91;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -7;
   &put_y += 100;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -54;
   &put_y += 100;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -88;
   &put_y += 85;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -108;
   &put_y += 66;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -108;
   &put_y += 16;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -73;
   &put_y += 92;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -33;
   &put_y += 107;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 13;
   &put_y += 107;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 57;
   &put_y += 86;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  if (&my_frame == 6)
   {
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -58;
   &put_y += -16;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -7;
   &put_y += -16;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 44;
   &put_y += -16;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 58;
   &put_y += 34;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 58;
   &put_y += 84;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 9;
   &put_y += 101;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -42;
   &put_y += 101;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -83;
   &put_y += 88;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -105;
   &put_y += 57;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -93;
   &put_y += 7;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -100;
   &put_y += 77;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -64;
   &put_y += 97;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += -16;
   &put_y += 106;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 44;
   &put_y += 114;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   &put_x = &my_x;
   &put_y = &my_y;
   &put_x += 77;
   &put_y += 83;
   &junk = create_sprite(&put_x, &put_y, 0, 80, 24);
   sp_script(&junk, "hardgarg");
   }
  }
 //wait(2);
 //say("drawing hard map", 1);
 draw_hard_map();
 }