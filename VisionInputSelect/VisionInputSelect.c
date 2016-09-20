// VisionInputSelect.cpp : Defines the entry point for the console application.
//

#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <commctrl.h>

#include <audio.h>
#include <audioapi.h>
#include <audiocap.h>

#include <rgb.h>
#include <rgbapi.h>
#include <rgberror.h>


int main()
{
	unsigned long  error;
	HRGBDLL        hRGBDLL = 0;

	error = RGBLoad(&hRGBDLL);
	if (error)
	{
		fprintf(stderr, "Error returned from RGBLoad: 0x%08x", error);
		return error;
	}

	error = RGBAudioSetAnalogueUnbalancedMute(1, 1);
	if (error)
	{
		fprintf(stderr, "Error returned from RGBAudioSetAnalogueUnbalancedMute: 0x%08x", error);
		return error;
	}


	error = RGBAudioSetAnalogueBalancedMute(1, 0);
	if (error)
	{
		fprintf(stderr, "Error returned from RGBAudioSetAnalogueBalancedMute: 0x%08x", error);
		return error;
	}

	if (hRGBDLL)
	{
		error = RGBFree(hRGBDLL);
	}

	return error;
}

