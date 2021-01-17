#!/bin/sh
VIDEO_SIZE=800x600
ffmpeg -v warning -f rawvideo -pixel_format rgb32 -framerate 30 -video_size $VIDEO_SIZE -i - 10k_rotation.gif
