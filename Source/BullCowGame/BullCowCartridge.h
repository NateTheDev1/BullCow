// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Console/Cartridge.h"
#include "CoreMinimal.h"
// Generated
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge {
  GENERATED_BODY()

 public:
  virtual void BeginPlay() override;
  virtual void OnInput(const FString& Input) override;
  void SetupGame();

  // Your declarations go below!
 private:
  FString HiddenWord;
  int32 Lives;
};
