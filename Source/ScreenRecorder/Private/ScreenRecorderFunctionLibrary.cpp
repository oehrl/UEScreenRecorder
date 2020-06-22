// Fill out your copyright notice in the Description page of Project Settings.


#include "ScreenRecorderFunctionLibrary.h"
#include "Modules/ModuleManager.h"
#include "ScreenRecorderModule.h"
#include "ScreenRecorder.h"

UScreenRecorder* UScreenRecorderFunctionLibrary::CreateRecorder(const FString& Id)
{
	TSharedPtr<FScreenRecorder> Recorder = FModuleManager::Get().GetModuleChecked<FScreenRecorderModule>("ScreenRecorder").CreateRecorder(Id);

	if (Recorder != nullptr) {
		auto RecorderObject = NewObject<UScreenRecorder>();
		RecorderObject->Implementation = Recorder;
		return RecorderObject;
	}
	else {
		return nullptr;
	}
}

void UScreenRecorderFunctionLibrary::DestroyRecorder(const FString& Id)
{
	FModuleManager::Get().GetModuleChecked<FScreenRecorderModule>("ScreenRecorder").DestroyRecorder(Id);
}
