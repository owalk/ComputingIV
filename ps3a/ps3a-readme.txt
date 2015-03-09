/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name: Oliver Walker
OS: Manjaro Linux. (Variant of arch)
Machine (e.g., Dell Latitude, MacBook Pro): umm, bought a ton of parts and put
them together.
Text editor: emacs. fool.
Hours to complete assignment (optional): 2-ish

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
the class body is inherited from sf::Drawable with an overloaded draw function.

in the operator >> overload, I set all the memeber variables to their initial
values from the file planets.txt.
For the x an y positions, I first run them through the function
coordinate_convert to scale them down by 1e-9 of their origanlol value. this
makes them all fit on a window 500 by 500 pixels wide.

I can add an arbitray amount of rows to planets.txt and would simply need to
push back more planets to my vector of planets and then draw them in my
window.isOpen loop.

The scaling is not dependent on the universe size or the window size. it simply
makes the x and y coordinates (10 to the power of -9) times smaller.

scaling code -
new_coordinate = (screen_size/2) + coordinate*1e-9

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
none.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
