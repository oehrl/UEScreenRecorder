// Fill out your copyright notice in the Description page of Project Settings.


#include "ScreenRecorder.h"
#include "LogScreenRecorder.h"

FScreenRecorder::~FScreenRecorder()
{
	if (IsRecording())
	{
		StopRecording();
	}
}

void FScreenRecorder::StartRecording()
{
	UE_LOG(LogScreenRecorder, Display, TEXT("Start Recording!"));

	PostRenderDelegate = FSlateApplication::Get().GetRenderer()->OnBackBufferReadyToPresent().AddLambda([](SWindow&, const FTexture2DRHIRef& Texture) {
		UE_LOG(LogScreenRecorder, Display, TEXT("Render %dx%d"), Texture->GetSizeX(), Texture->GetSizeY());
	});
}

void FScreenRecorder::StopRecording()
{
	UE_LOG(LogScreenRecorder, Display, TEXT("Stop Recording!"));
	FSlateApplication::Get().GetRenderer()->OnBackBufferReadyToPresent().Remove(PostRenderDelegate);
	PostRenderDelegate.Reset();
}

bool FScreenRecorder::IsRecording() const
{
	return PostRenderDelegate.IsValid();
}

FScreenRecorder::FScreenRecorder(FString Name)
	: Name(Name)
{
}

UScreenRecorder::UScreenRecorder()
{
	UE_LOG(LogScreenRecorder, Display, TEXT("Recorder created"));
}

UScreenRecorder::~UScreenRecorder()
{
	UE_LOG(LogScreenRecorder, Display, TEXT("Recorder destroyed"));
}