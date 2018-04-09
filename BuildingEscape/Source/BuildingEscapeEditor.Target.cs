// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BuildingEscapeEditorTarget : TargetRules
{
	public BuildingEscapeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

        //Enable when its necessary to find a missing include
        //bUseUnityBuild = false;
        //bUsePCHFFiles = false;

		ExtraModuleNames.AddRange( new string[] { "BuildingEscape" } );
	}
}
