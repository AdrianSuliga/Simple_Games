# Guessing game

In this game you are trying to guess a number from an array of natural numbers. After each guess computer can give you 3 types of feedback:

1) This number is too big,

2) This number is too small,

3) You guessed it!

Download current version of Guessing Game [HERE](https://github.com/AdrianSuliga/Simple_Games/releases/tag/guessing_game_5)

Descrtiption:
---

When you open this game, it shows a title screen. In simple labels I explained the rules of the game, there are also buttons which begin or quit the game.

![Screenshot of title screen](/Guess_a_number/Screenshots/TitleScreen.png "Title screen")

After beginning, player can choose a range by using sliders or simply typing numbers. I added some form of validation. Users cannot enter characters, floating point numbers nor negative numbers as input. If one tries to do it, this application shows an error message.

![Screenshot of window where user can choose an array of numbers](/Guess_a_number/Screenshots/ChooseRange.png "Choose Range")

Having chosen the range, user may now attempt to guess one number which computer chose from said range.

![Screenshot of window where user tries to guess a number](/Guess_a_number/Screenshots/GuessNum.png "Guess a Number")

After successfully guessing a number user can begin next round or quit.

![Screenshot of meassage which user receives after a correct guess](/Guess_a_number/Screenshots/YouWon.png "Congratulations dialog")
