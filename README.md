# Terminal Wordle

<strong>Wordle</strong> is a popular web-based game, currently published by the [New York Times](https://www.nytimes.com/games/wordle/index.html). It requires the player to guess a five-letter word in at most six attempts. After each attempt, feedback is given on which letters in the guessed word are correctly placed (typically displayed in green), which letters are in the word but in a different positions (typically displayed in yellow), and which letters are not in the word at all.

This program will provide a similar gameplay as the original version, but in a terminal-based interface. Receiving command-line arguments is not expected.

There are also three files contributing to the game mechanics. These files are expected to be found in the current working directory.
- The file `words.txt` contains a list of all words accepted as valid guesses in the game. The words are separated by line breaks ("`\n`"), and are all listed using lower-case letters. Source: https://github.com/tabatkins/wordle-list.
- The file `answer.txt` contains the answer to the game. It is expected to be one of the words listed in `words.txt`. To choose a random word from that file, you may generate this file with a command like:
```Bash
shuf -n 1 -o answer.txt words.txt
```
- The file `stats.txt`, if it exists, contains the current stats of the player. The stats are in the form of 7 integer values: the number of times the player completed the game in 1 attempt, then 2 attempts, then 3, 4, 5, and 6 attempts, and finally the number of times the player failed to complete the game at all. The integer values are separate by spaces, with a final line break at the end of the file.
