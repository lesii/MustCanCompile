// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MUSTCANCOMPILE_API MccInternation
{
public:
	static void Register(FText value) {
		return;
	}
};

#define LOCTEXT_NAMESPACE "MccMenu"

MccInternation::Register(LOCTEXT("Menu", "Menu"));
MccInternation::Register(LOCTEXT("StartGame", "StartGame"));
MccInternation::Register(LOCTEXT("GameOption", "GameOption"));
MccInternation::Register(LOCTEXT("QuitGame", "QuitGame"));
MccInternation::Register(LOCTEXT("NewGame", "NewGame"));
MccInternation::Register(LOCTEXT("LoadRecord", "LoadRecord"));
MccInternation::Register(LOCTEXT("ChooseRecord", "ChooseRecord"));
MccInternation::Register(LOCTEXT("RecordName", "RecordName"));
MccInternation::Register(LOCTEXT("EnterGame", "EnterGame"));
MccInternation::Register(LOCTEXT("EnterRecord", "EnterRecord"));
MccInternation::Register(LOCTEXT("RecordNameHint", "RecordNameHint"));
MccInternation::Register(LOCTEXT("NameRepreatedHint", "NameRepreatedHint"));
MccInternation::Register(LOCTEXT("Chinese", "Chinese"));
MccInternation::Register(LOCTEXT("English", "English"));
MccInternation::Register(LOCTEXT("Music", "Music"));
MccInternation::Register(LOCTEXT("Sound", "Sound"));

MccInternation::Register(LOCTEXT("GoBack", "GoBack"));

#undef LOCTEXT_NAMESPACE

//MccInternation::Register(LOCTEXT("MccMenu", "Menu", "Menu"));
