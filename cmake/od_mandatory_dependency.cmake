find_package(PCL REQUIRED)
find_package(OpenCV REQUIRED)
find_package(VTK REQUIRED)
find_package(Eigen REQUIRED)
find_package(Boost 1.40 COMPONENTS program_options REQUIRED )

find_package( Caffe REQUIRED)
#ADD_DEFINITIONS(
#    -std=c++11 
#	${Caffe_DEFINITIONS}
#)

set(GTKMM_INCLUDE_DIRS_3 -pthread /usr/include/gtkmm-3.0 /usr/lib/x86_64-linux-gnu/gtkmm-3.0/include /usr/include/atkmm-1.6 /usr/include/giomm-2.4 /usr/lib/x86_64-linux-gnu/giomm-2.4/include /usr/include/pangomm-1.4 /usr/lib/x86_64-linux-gnu/pangomm-1.4/include /usr/include/gtk-3.0 /usr/include/cairomm-1.0 /usr/lib/x86_64-linux-gnu/cairomm-1.0/include /usr/include/gdk-pixbuf-2.0 /usr/include/gtk-3.0/unix-print /usr/include/gdkmm-3.0 /usr/lib/x86_64-linux-gnu/gdkmm-3.0/include /usr/include/atk-1.0 /usr/include/glibmm-2.4 /usr/lib/x86_64-linux-gnu/glibmm-2.4/include /usr/include/glib-2.0 /usr/lib/x86_64-linux-gnu/glib-2.0/include /usr/include/sigc++-2.0 /usr/lib/x86_64-linux-gnu/sigc++-2.0/include /usr/include/pango-1.0 /usr/include/cairo /usr/include/pixman-1 /usr/include/freetype2 /usr/include/libpng12 /usr/include/at-spi2-atk/2.0 /usr/include/gio-unix-2.0/ /usr/include/harfbuzz)
set(GTKMM_LIBRARIES_3 gtkmm-3.0 atkmm-1.6 gdkmm-3.0 giomm-2.4 pangomm-1.4 gtk-3 glibmm-2.4 cairomm-1.0 gdk-3 atk-1.0 gio-2.0 pangocairo-1.0 gdk_pixbuf-2.0 cairo-gobject pango-1.0 cairo sigc-2.0 gobject-2.0 glib-2.0)

include_directories("${OD_SOURCE_DIR}" ${EIGEN_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS} ${OD_SOURCE_DIR}/3rdparty/SiftGPU/src/SiftGPU ${Caffe_INCLUDE_DIRS} ${GTKMM_INCLUDE_DIRS_3})

ADD_DEFINITIONS(${Caffe_DEFINITIONS})
