#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <3ds.h>

#include "frames.h"

void sleep(int ms) {
	svcSleepThread(ms * 1000000);
}

void playBadApple() {
	for(int i = 0; i < FRAME_COUNT; i++) {
		for(int j = 0; j < FRAME_HEIGHT; j++) {
			hidScanInput();

			// Your code goes here
			u32 kDown = hidKeysDown();
			if (kDown & KEY_SELECT) {
				printf("Playback stopped.\n\nPress %sSTART %sto play again.\nPress %sSELECT %sto exit.\n", CONSOLE_RED, CONSOLE_RESET, CONSOLE_RED, CONSOLE_RESET);
				return;
			}

			printf("%s\n", frames[i][j]);
		}

		sleep(/*1000 / FPS*/ 28.5); // 1000 ms = 1 second
		consoleClear();
	}

	consoleClear(); // Bad Apple finished, clean up console.
	printf("Bad Apple finished!\n\nPress %sSTART %sto play again.\nPress %sSELECT %sto exit.\n", CONSOLE_RED, CONSOLE_RESET, CONSOLE_RED, CONSOLE_RESET);
}

int main(int argc, char* argv[])
{
	gfxInitDefault();

	consoleInit(GFX_TOP, NULL);

	printf("Bad Apple!! on the Nintendo %s3%sDS\n", CONSOLE_RED, CONSOLE_RESET);
	printf("Developed by %sMiaowz%s\n", CONSOLE_BLUE, CONSOLE_RESET);
	printf("https://github.com/MiaOwOz/BadApple_3DS.git\n\n");
	printf("Press %sSTART %sto begin.\n", CONSOLE_RED, CONSOLE_RESET);
	printf("Press %sSELECT %sto exit.\n", CONSOLE_RED, CONSOLE_RESET);

	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();

		// Your code goes here
		u32 kDown = hidKeysDown();
		if (kDown & KEY_SELECT)
			break; // break in order to return to hbmenu

		if(kDown & KEY_START) {
			playBadApple();
		}
	}

	gfxExit();
	return 0;
}
