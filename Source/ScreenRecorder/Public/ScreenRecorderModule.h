// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FScreenRecorder;

class FScreenRecorderModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	TSharedPtr<FScreenRecorder> CreateRecorder(const FString& id);
	TSharedPtr<FScreenRecorder> GetRecorder(const FString& id);
	void DestroyRecorder(const FString& id);
	
private:
	TMap<FString, TSharedPtr<FScreenRecorder>> ScreenRecorders;

private:
	/** Handle to the test dll we will load */
	void*	ExampleLibraryHandle;
};
