#include "BullCowCartridge.h"

// When the game starts
void UBullCowCartridge::BeginPlay() {
  Super::BeginPlay();

  // Initializating the game
  SetupGame();

  // Debug Line
  PrintLine(TEXT("Hidden Word is: %s.\nIt is %i characters long"), *HiddenWord,
            HiddenWord.Len());

  PrintLine(TEXT("Welcome to Bull Cow Game"));
  PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
  PrintLine(TEXT("Type in your guess and press enter to continue..."));
}

// When the player hits enter
void UBullCowCartridge::OnInput(const FString& Input) {
  ClearScreen();

  // Checking the PlayerGuess

  if (Input == HiddenWord) {
    PrintLine(TEXT("You have Won!"));
  } else {
    // Check if right word length
    if (Input.Len() != HiddenWord.Len()) {
      PrintLine(TEXT("The Hidden Word is %i characters long, try again!"),
                HiddenWord.Len());
    }
    PrintLine(TEXT("You have Lost..."));
  }

  // Check if isogram
  // Prompt to guess again
  // Prompt to guess again
  // Remove a life
  // Check if lives > 0
  // If yes GuessGuess
  // Show Lives Left
  // if no show GameOver and the HiddenWord
  // Press Enter to play again
  // Check user input
}

void UBullCowCartridge::SetupGame() {
  // Set hidden word
  HiddenWord = TEXT("cake");
  // set lives
  Lives = 4;
}