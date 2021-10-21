#include "BullCowCartridge.h"

// When the game starts
void UBullCowCartridge::BeginPlay() {
  Super::BeginPlay();
  PrintLine(TEXT("Welcome to Bull Cow Game"));
  PrintLine(TEXT(
      "Guess the 4 letter word!"));  // TODO: Change to dynamic magic number
  PrintLine(TEXT("Press enter to continue..."));

  // Initializating the game
  InitGame();

  // Prompt player for guess
}

// When the player hits enter
void UBullCowCartridge::OnInput(const FString& Input) {
  ClearScreen();

  // Checking the PlayerGuess

  if (Input == HiddenWord) {
    PrintLine(TEXT("You have Won!"));
  } else {
    PrintLine(TEXT("You have Lost..."));
  }

  // Check if isogram
  // Prompt to guess again
  // Check if right word length
  // Prompt to guess again

  // Remove a life

  // Check if lives > 0
  // If yes GuessGuess
  // Show Lives Left
  // if no show GameOver and the HiddenWord
  // Press Enter to play again
  // Check user input
}

void UBullCowCartridge::InitGame() {
  // Set hidden word
  HiddenWord = TEXT("cake");
  // set lives
  Lives = 4;
}