// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScreenRecorderFunctionLibrary.generated.h"

class UScreenRecorder;

/**
 * 
 */
UCLASS()
class SCREENRECORDER_API UScreenRecorderFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Screen Recorder")
	static UScreenRecorder* CreateRecorder(const FString& Id);

	UFUNCTION(BlueprintCallable, Category = "Screen Recorder")
	static void DestroyRecorder(const FString& Id);
};
