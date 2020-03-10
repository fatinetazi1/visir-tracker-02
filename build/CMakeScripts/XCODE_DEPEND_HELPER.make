# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.visir-tracker.Debug:
/Users/fatine/Documents/GitHub/visir-tracker-02/build/bin/Debug/visir-tracker:\
	/usr/local/lib/libopencv_objdetect.4.2.0.dylib\
	/usr/local/lib/libopencv_highgui.4.2.0.dylib\
	/usr/local/lib/libopencv_videoio.4.2.0.dylib\
	/usr/local/lib/libopencv_video.4.2.0.dylib\
	/usr/local/lib/libopencv_imgcodecs.4.2.0.dylib\
	/usr/local/lib/libopencv_calib3d.4.2.0.dylib\
	/usr/local/lib/libopencv_features2d.4.2.0.dylib\
	/usr/local/lib/libopencv_imgproc.4.2.0.dylib\
	/usr/local/lib/libopencv_flann.4.2.0.dylib\
	/usr/local/lib/libopencv_core.4.2.0.dylib
	/bin/rm -f /Users/fatine/Documents/GitHub/visir-tracker-02/build/bin/Debug/visir-tracker


PostBuild.visir-tracker.Release:
/Users/fatine/Documents/GitHub/visir-tracker-02/build/bin/Release/visir-tracker:\
	/usr/local/lib/libopencv_objdetect.4.2.0.dylib\
	/usr/local/lib/libopencv_highgui.4.2.0.dylib\
	/usr/local/lib/libopencv_videoio.4.2.0.dylib\
	/usr/local/lib/libopencv_video.4.2.0.dylib\
	/usr/local/lib/libopencv_imgcodecs.4.2.0.dylib\
	/usr/local/lib/libopencv_calib3d.4.2.0.dylib\
	/usr/local/lib/libopencv_features2d.4.2.0.dylib\
	/usr/local/lib/libopencv_imgproc.4.2.0.dylib\
	/usr/local/lib/libopencv_flann.4.2.0.dylib\
	/usr/local/lib/libopencv_core.4.2.0.dylib
	/bin/rm -f /Users/fatine/Documents/GitHub/visir-tracker-02/build/bin/Release/visir-tracker




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libopencv_calib3d.4.2.0.dylib:
/usr/local/lib/libopencv_core.4.2.0.dylib:
/usr/local/lib/libopencv_features2d.4.2.0.dylib:
/usr/local/lib/libopencv_flann.4.2.0.dylib:
/usr/local/lib/libopencv_highgui.4.2.0.dylib:
/usr/local/lib/libopencv_imgcodecs.4.2.0.dylib:
/usr/local/lib/libopencv_imgproc.4.2.0.dylib:
/usr/local/lib/libopencv_objdetect.4.2.0.dylib:
/usr/local/lib/libopencv_video.4.2.0.dylib:
/usr/local/lib/libopencv_videoio.4.2.0.dylib:
