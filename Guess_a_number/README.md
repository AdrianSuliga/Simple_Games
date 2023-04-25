# Guessing game

In this game you are trying to guess a number from given array of natural numbers. After each guess computer can give you 3 types of feedback:

1) This number is too big,

2) This number is too small,

3) You guessed it!

Download current version of Guessing Game [HERE](https://github.com/AdrianSuliga/Simple_Games/releases/tag/guessing_game_3)

Update:

As of today, the programm shows you title screen with a button which begins the game. After beginning you choose a range which the computer is going to choose from.

Update:

You may adjust this range by using sliders connected to lcd displays or by typing numbers from you keyboard. I implemented validation to those inputs, it is impossible
to enter negative numbers and I prevented the situation when last number in range is smaller than the first one. Unfortunately, programm cannot handle situation when someone types words instead of numbers (yet).
After you've entered input game shows you chosen range. Mechanics of drawing number from this range isn't implemented.

Update:

Program draws one number from this range. User can attempt to guess it, but the programm does not check if answer is correct or not.
  
Update:

Core mechanick is done. You can attempt many times to guess a number and as a result you receive one of 3 messages (described above). After guessing the number,
programm closes. There are a few bugs to fix, though. If users enters words as input, computer interprets them as 0 (better than nothing I guess) but it should give an
error message to the user. Maximum range of numbers you can choose by typing is different than the one created by using sliders. They should be the same. Game should
also allow user to play many times, not just once. 
  
Update:

User can no longer enter words as input, there was a major bug while using rand() function but I fortunately managed to fix it.
  
Update:

Ranges which can be chosen via typing and sliders is the same now. Player can play multiple times. I also added ,,Quit to title" button which allows user to     return to the initial interface at any point.

Bugs to fix in the future:

Size of widgets does not scale when user decides to change to fullscreen mode.
