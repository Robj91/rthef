//Script for screen with lines of numbers on them
//screen number 34

void main(void)
{
//make it so this sprite can't be seen
 sp_nodraw(&current_sprite, 1);

 if (&story == 0)
 {
  wait(350);

 //create transport
  int &elev = create_sprite(-70, 273, 6, 855, 1);
  sp_seq(&elev, 855);
  sp_brain(&elev, 6);
  sp_speed(&elev, 9);
  sp_sound(&elev, 68);

 //Move it onto the screen
  playsound(69, 44100, 0, 0, 0);
  move_stop(&elev, 6, 161, 1);
  sp_brain(&elev, 0);
  sp_sound(&elev, 0); 
  wait(700);

 //create speech
  int &spch = create_sprite(312, 245, 0, 150, 22);
  sp_pseq(&spch, 150);
  sp_pframe(&spch, 21);
  sp_que(&spch, 1000);
  Playsound(61,22050,0,0,0);
  wait(200);
  wait_for_button();

 //speech 2
  sp_x(&spch, 458);
  sp_y(&spch, 215);
  sp_pframe(&spch, 17);
  Playsound(61,22050,0,0,0);
  wait(200);
  wait_for_button();

 //speech 3
  sp_x(&spch, 491);
  sp_y(&spch, 113);
  sp_pframe(&spch, 15);
  Playsound(61,22050,0,0,0);
  wait(200);
  wait_for_button();

 //speech 4
  sp_x(&spch, 220);
  sp_y(&spch, 111);
  sp_pframe(&spch, 16);
  Playsound(61,22050,0,0,0); 
  wait(200);
  wait_for_button(); 

 //sound before red text displays
  Playsound(70,44100,0,0,0);
  wait(1000);

 //create red text
  sp_x(&spch, 646);
  sp_y(&spch, 301);
  sp_pseq(&spch, 160);
  sp_pframe(&spch, 8);
  Playsound(65,44100,0,0,0); 
  wait(1000);

 //red text 2
  sp_pframe(&spch, 9);
  Playsound(65,44100,0,0,0); 
  wait(1000);

 //red text 3
  sp_pframe(&spch, 10);
  Playsound(65,44100,0,0,0);  
  wait(1000);

 //move transport right
  playsound(69, 44100, 0, 0, 0);
  sp_brain(&elev, 6);
  sp_sound(&elev, 68);
  move_stop(&elev, 6, 260, 1);
  sp_brain(&elev, 0);
  sp_sound(&elev, 0);
  sp_x(&elev, 260);

 //speech 5
  sp_x(&spch, 406);
  sp_y(&spch, 252);
  sp_pseq(&spch, 150);
  sp_pframe(&spch, 22);
  Playsound(61,22050,0,0,0); 
  wait(200);
  wait_for_button();
  sp_nodraw(&spch, 1);

 //move transport right again
  playsound(69, 44100, 0, 0, 0);
  sp_brain(&elev, 6);
  sp_sound(&elev, 68);
  move_stop(&elev, 6, 357, 1);
  sp_x(&elev, 357);

 //move transport up
  sp_speed(&elev, 2);
  move_stop(&elev, 8, 44, 1);
  move_stop(&elev, 4, 342, 1);
  sp_x(&elev, 338);
  sp_brain(&elev, 0);
  sp_sound(&elev, 0);

 //create red number 5
  playsound(70, 44100, 0, 0, 0);
  wait(1000);
  int &numb = create_sprite(442, 285, 0, 853, 10);
  sp_pseq(&numb, 853);
  sp_pframe(&numb, 14);
  playsound(72, 44100, 0, 0, 0);
  wait(400);

 //create red equal sign
  int &symb = create_sprite(533, 307, 0, 856, 16);
  sp_pseq(&symb, 856);
  sp_pframe(&symb, 16);
  playsound(72, 44100, 0, 0, 0); 
  wait(400);

 //create red number 1
  int &numb2 = create_sprite(561, 285, 0, 853, 14);
  sp_pseq(&numb2, 853);
  sp_pframe(&numb2, 10);
  playsound(72, 44100, 0, 0, 0);
  wait(500);  

 //create false sound and text
  playsound(73, 44100, 0, 0, 0);
  sp_nodraw(&numb, 1);
  sp_nodraw(&symb, 1);
  sp_nodraw(&numb2, 1);
  int &text = create_sprite(616, 306, 0, 160, 11);
  sp_pseq(&text, 160);
  sp_pframe(&text, 11);
  wait(1000);
  sp_nodraw(&text, 1);

 //create red number 5
  sp_nodraw(&numb, 0);
  playsound(72, 44100, 0, 0, 0);
  wait(400);

 //create red greater than sign 
  sp_pseq(&symb, 857);
  sp_pframe(&symb, 3);
  sp_nodraw(&symb, 0);
  playsound(72, 44100, 0, 0, 0); 
  wait(400);

 //create red number 1
  sp_nodraw(&numb2, 0);
  playsound(72, 44100, 0, 0, 0);
  wait(500); 
  sp_nodraw(&numb, 1);
  sp_nodraw(&numb2, 1);
  sp_nodraw(&symb, 1);

 //create green true text 
  sp_x(&text, 601);
  sp_y(&text, 300);
  sp_pframe(&text, 12);
  sp_nodraw(&text, 0);
  playsound(63, 44100, 0, 0, 0);
  wait(1000);
  sp_nodraw(&text, 1);

 //move transport down
  sp_brain(&elev, 6);
  sp_sound(&elev, 68);
  move_stop(&elev, 2, 150, 1);
  sp_brain(&elev, 0);
  sp_sound(&elev, 0);
  
 //speech bubble
  sp_x(&spch, 509);
  sp_y(&spch, 218);
  sp_pframe(&spch, 23);
  sp_nodraw(&spch, 0);
  Playsound(61,22050,0,0,0);
  wait(200);
  wait_for_button();
  sp_nodraw(&spch, 1);

 //create red number 5
  sp_pframe(&numb, 14);
  sp_nodraw(&numb, 0);
  playsound(72, 44100, 0, 0, 0);
  wait(400);

 //create red less than sign
  sp_pframe(&symb, 1);
  sp_nodraw(&symb, 0);
  playsound(72, 44100, 0, 0, 0);
  wait(400);

 //create red number 5
  sp_pframe(&numb2, 14);
  sp_nodraw(&numb2, 0);  
  playsound(72, 44100, 0, 0, 0);
  wait(400);

 //create false sound and text 
  sp_nodraw(&numb, 1);
  sp_nodraw(&numb2, 1);
  sp_nodraw(&symb, 1);
  sp_pframe(&text, 11);
  sp_nodraw(&text, 0);
  playsound(73, 44100, 0, 0, 0);
  wait(1000);
  sp_nodraw(&text, 1);

 //create red number 5
  sp_nodraw(&numb, 0)    
  playsound(72, 44100, 0, 0, 0);
  wait(400);

 //create red greater than sign 
  sp_pframe(&symb, 3);
  sp_nodraw(&symb, 0)    
  playsound(72, 44100, 0, 0, 0);
  wait(400);  

 //create red number 5
  sp_nodraw(&numb2, 0)    
  playsound(72, 44100, 0, 0, 0);
  wait(400);  

 //create false sound and text
  sp_nodraw(&numb, 1);
  sp_nodraw(&numb2, 1);
  sp_nodraw(&symb, 1);
  sp_nodraw(&text, 0);
  playsound(73, 44100, 0, 0, 0);
  wait(1000);
  sp_nodraw(&text, 1); 

 //create red number 5
  sp_nodraw(&numb, 0)    
  playsound(72, 44100, 0, 0, 0);
  wait(400);

 //create red equal sign 
  sp_pseq(&symb, 856);
  sp_pframe(&symb, 16);
  sp_nodraw(&symb, 0)    
  playsound(72, 44100, 0, 0, 0);
  wait(400);  

 //create red number 5
  sp_nodraw(&numb2, 0)    
  playsound(72, 44100, 0, 0, 0);
  wait(400);  

 //create last false sound and text
  sp_nodraw(&numb, 1);
  sp_nodraw(&numb2, 1);
  sp_nodraw(&symb, 1);
  sp_pframe(&text, 11);
  sp_nodraw(&text, 0);
  playsound(73, 30050, 0, 0, 0);
  wait(1000);
  sp_nodraw(&text, 1);  

 //speech bubble
  //sp_x(&spch, 509);
  //sp_y(&spch, 218);
  //sp_pframe(&spch, 23);
  //sp_nodraw(&spch, 0);
  //Playsound(61,22050,0,0,0);
  //wait(200);
  //wait_for_button();
  //sp_nodraw(&spch, 1);

 //make transport flash and beep
  sp_brain(&elev, 6);
  sp_frame_delay(&elev, 20);
  playsound(57, 44100, 0, 0, 0);
  sp_sound(&elev, 0);
  wait(2000);
  playsound(69, 44100, 0, 0, 0);
  sp_speed(&elev, 9);
  move_stop(&elev, 6, 366, 1);
  sp_x(&elev, 366);
 
 //move ground
  &text = sp(2);
  sp_speed(&text, 2);
  playsound(75, 22050, 0, 0, 0);
  move_stop(&text, 6, 664, 1);
  
 //move transport off screen
  playsound(69, 22050, 0, 0, 0);
  move_stop(&elev, 2, 500, 1);
 
 //slant numbers
 &spch = 0;
 &numb = 20;
bloop:
 &spch = get_next_sprite_with_this_brain(&numb, 0, &spch);
 if (&spch > 0)
 {
  if (&numb == 20) sp_pframe(&spch, 15);
  if (&numb == 21) sp_pframe(&spch, 16);
  if (&numb == 22) sp_pframe(&spch, 18);
  if (&numb == 23) 
  {
   sp_pframe(&spch, 17);
   sp_clip_right(&spch, 0);
  }
  if (&numb == 24) 
  {
   sp_pframe(&spch, 20);  
  }
  if (&numb == 25)
  {
   sp_x(&spch, 156);
   sp_pframe(&spch, 19);
   
  }
  if (&numb == 26) 
  {
   sp_pframe(&spch, 22);
  }
  if (&numb == 27) 
  {
   sp_clip_right(&spch, 0);
   sp_pframe(&spch, 21);
  }
  if (&numb == 28)  
  {
   sp_pframe(&spch, 23);
  }
  playsound(61, 30000, 0, 0, 0);
  wait(200);
  &numb += 1;
  &spch = 0;
 }
 if (&numb < 29) goto bloop;

 //change screens
  wait(1500);
 }
}  
  
  