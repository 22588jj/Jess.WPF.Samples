﻿using System;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Windows;

// Setting ComVisible to false makes the types in this assembly not visible 
// to COM components.  If you need to access a type in this assembly from 
// COM, set the ComVisible attribute to true on that type.

[assembly: ComVisible(false)]
[assembly: CLSCompliant(true)]

//In order to begin building localizable applications, set 
//<UICulture>CultureYouAreCodingWith</UICulture> in your .csproj file
//inside a <PropertyGroup>.  For example, if you are using US english
//in your source files, set the <UICulture> to en-US.  Then uncomment
//the NeutralResourceLanguage attribute below.  Update the "en-US" in
//the line below to match the UICulture setting in the project file.

//[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]

[assembly: ThemeInfo(
	ResourceDictionaryLocation.None, //where theme specific resource dictionaries are located
	//(used if a resource is not found in the page, 
	// or application resource dictionaries)
	ResourceDictionaryLocation.SourceAssembly //where the generic resource dictionary is located
	//(used if a resource is not found in the page, 
	// app, or any theme specific resource dictionaries)
	)]

[assembly:
	InternalsVisibleTo(
		"MvvmValidation.Tests, PublicKey=0024000004800000940000000602000000240000525341310004000001000100b327736861cacd9185731a01213c996a5479534e1befabbaa2c971d2f9256065a628750e8bad4e281a6231b7db1e602e516fcd3ad4c2670fa6a32d308fa8770da1d57373794408e74872fc4b0b2e84d7fb707968b64464472bd10ce4f040c9a5ab02960eacda10f2545bae415386570e4df18bd7d38929ad698f3952ffcfcaeb"
		)]
[assembly: NeutralResourcesLanguage("en")]