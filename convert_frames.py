import cv2
import numpy as np

# --- Settings ---
TARGET_WIDTH = 50
TARGET_HEIGHT = 30
VIDEO_RESIZE = (800, 240)  # scaling video first
INPUT_FILE = "bad_apple.webm"
OUTPUT_FILE = "frames.h"   # will contain ASCII frames in C-compatible format

# --- Load Video ---
cap = cv2.VideoCapture(INPUT_FILE)
if not cap.isOpened():
    raise Exception("Could not open video file.")

frames_ascii = []

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # Convert to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Resize to video target resolution first
    resized = cv2.resize(gray, VIDEO_RESIZE, interpolation=cv2.INTER_AREA)

    # Reduce to ASCII target resolution
    small = cv2.resize(resized, (TARGET_WIDTH, TARGET_HEIGHT), interpolation=cv2.INTER_AREA)

    # Threshold to black and white
    _, bw = cv2.threshold(small, 128, 255, cv2.THRESH_BINARY)

    # Convert to ASCII
    ascii_frame = []
    for row in bw:
        line = "".join("#" if pixel == 0 else " " for pixel in row)
        ascii_frame.append(line)

    frames_ascii.append(ascii_frame)

cap.release()

# --- Write to C header file ---
with open(OUTPUT_FILE, "w") as f:
    f.write("/* Auto-generated ASCII frames */\n\n")
    f.write(f"#define FRAME_WIDTH {TARGET_WIDTH}\n")
    f.write(f"#define FRAME_HEIGHT {TARGET_HEIGHT}\n")
    f.write(f"#define FRAME_COUNT {len(frames_ascii)}\n\n")

    f.write("const char *frames[FRAME_COUNT][FRAME_HEIGHT] = {\n")
    for frame in frames_ascii:
        f.write("    {\n")
        for line in frame:
            f.write(f'        "{line}",\n')
        f.write("    },\n")
    f.write("};\n")
