// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/MccTypes.h"
/**
 * 
 */
class MUSTCANCOMPILE_API MccDataHandle
{
public:
	MccDataHandle();

	static void Initialize();
	static TSharedPtr<MccDataHandle> Get();

	void ChangeLocalizationCultrue(ECultureTeam _Culture);

public:
	ECultureTeam CurrentCulture;

private:
	static TSharedRef<MccDataHandle> Creat();

private:
	static TSharedPtr<MccDataHandle> DataInstance;

};
