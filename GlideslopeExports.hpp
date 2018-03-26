//
// Glideslope 2 Exports Header
//
// Purpose ... present target base data to other MFDs
//
// (c) Andrew Stokes (ADSWNJ) 2012-2018
//
// All rights reserved
//
#pragma once

#ifndef __GLIDESLOPEEXPORTS_H
#define __GLIDESLOPEEXPORTS_H

#include "MMExt2_Advanced.hpp"

//
// This defines the Target Base structure for export via ModuleMessagingMFD:
//
// To access this structure, do the following:
//
// 1. #include "GlideslopeExports.hpp" in the header of the class receiving the data
//
// 2. Inside the class receiving the data, include the following (n.b. the consts are mandatory to prevent you updating the structure by accident):
//		// Glideslope Exports
//		const struct GlideslopeExportTgtStruct *GS_trgt;
//
//		Inside your class code, implement something like this:
// 	if (EnjoLib::ModuleMessagingExt().ModMsgGetByRef("GS2","GlideslopeTarget",2, &(VC->GS_trgt),VC->v)) return false;
//
//	3. If you get a good return from ModMsgGetByRef, then you will have a read-only pointer to the data structure (e.g. VC->BS_trgt->name will point to the target name)
//

#pragma pack(push)
#pragma pack(8)
#define GLIDESLOPE_EXPORT_TGT_VER 2
struct GlideslopeExportTgtStruct: public MMExt2::MMStruct {	// Target Data
	GlideslopeExportTgtStruct():MMExt2::MMStruct(GLIDESLOPE_EXPORT_TGT_VER,sizeof(GlideslopeExportTgtStruct)) {};
	char	ref[32];			// Reference planet or moon
	char	name[32];		    // Current target base
	double	lat;				// Target latitude (radians)
	double	lon;				// Target longitude (radians)
	double	alt;				// Altitude at start of glideslope (km)
	double	ang;				// Angle of reentry at start of glideslope (radians)
	double	ant;				// Angle of reentry at start of glideslope (radians)
};
#pragma pack(pop)
#endif 
