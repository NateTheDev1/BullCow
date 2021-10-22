#include "BullCowCartridge.h"

#include "HiddenWordList.h"

// When the game starts
void UBullCowCartridge::BeginPlay() {
  Super::BeginPlay();

  PrintLine(TEXT("The number of possible words is %i"), Words.Num());

  SetupGame();
}

// When the player hits enter
void UBullCowCartridge::OnInput(const FString& Input) {
  if (bGameOver) {
    ClearScreen();
    SetupGame();
  } else {
    ProcessGuess(Input);
  }
}

void UBullCowCartridge::SetupGame() {
  PrintLine(TEXT("Welcome to Bull Cow Game"));

  HiddenWord = Words[FMath::RandRange(0, Words.Num() - 1)];

  Lives = HiddenWord.Len();
  bGameOver = false;

  PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
  PrintLine(TEXT("You have %i lives"), Lives);
  PrintLine(TEXT("Type in your guess and \npress enter to continue..."));
}

void UBullCowCartridge::EndGame() {
  bGameOver = true;
  ClearScreen();

  PrintLine(TEXT("Press enter to play again."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess) {
  if (Guess == HiddenWord) {
    PrintLine(TEXT("You have Won!"));
    EndGame();
    return;
  }

  if (!IsIsogram(Guess)) {
    PrintLine(TEXT("There are no repeating letters, guess again"));
    return;
  }

  if (Guess.Len() != HiddenWord.Len()) {
    PrintLine(TEXT("The Hidden word is %i letters long"), HiddenWord.Len());
    PrintLine(TEXT("Sorry, try guessing again. \nYou have %i lives remaining"),
              Lives);
    return;
  }

  PrintLine(TEXT("You have lost a life!"));

  --Lives;

  if (Lives <= 0) {
    EndGame();
    PrintLine(TEXT("You have no lives left! \nThe Game Is Over!"));
    PrintLine(TEXT("The hidden word was %s"), *HiddenWord);
    return;
  }

  PrintLine(TEXT("You have %i lives left."), Lives);
}

bool UBullCowCartridge::IsIsogram(const FString& Word) const {
  for (int32 Index = 0; Index < Word.Len(); Index++) {
    for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++) {
      if (Word[Index] == Word[Comparison]) {
        return false;
      }
    }
  }

  return true;
}