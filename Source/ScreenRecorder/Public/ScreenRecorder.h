// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScreenRecorder.generated.h"

class SCREENRECORDER_API FScreenRecorder
{
	friend class FScreenRecorderModule;

public:
	// TODO: Make private
	FScreenRecorder(FString Name);
	~FScreenRecorder();

	void StartRecording();
	void StopRecording();
	bool IsRecording() const;

	inline FString GetName() const
	{
		return Name;
	}

private:
	FString Name;
	FDelegateHandle PostRenderDelegate;
};

/**
 * 
 */
UCLASS()
class SCREENRECORDER_API UScreenRecorder : public UObject
{
	GENERATED_BODY()

	friend class UScreenRecorderFunctionLibrary;

public:
	UScreenRecorder();
	~UScreenRecorder() override;

	UFUNCTION(BlueprintCallable, Category = "Screen Recorder")
	void StartRecording()
	{
		AccessImplementation()->StartRecording();
	}

	UFUNCTION(BlueprintCallable, Category = "Screen Recorder")
	void StopRecording()
	{
		AccessImplementation()->StopRecording();
	}

	UFUNCTION(BlueprintCallable, Category = "Screen Recorder")
	bool IsRecording() const
	{
		return AccessImplementation()->IsRecording();
	}

private:
	inline TSharedPtr<FScreenRecorder> AccessImplementation() const
	{
		auto SharedPtr = Implementation.Pin();
		check(SharedPtr.IsValid());
		return SharedPtr;
	}

	TWeakPtr<FScreenRecorder> Implementation;
};
