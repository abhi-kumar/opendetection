set(SUBSYS_NAME global_image_detector)
set(LIB_NAME od_${SUBSYS_NAME})
set(SUBSYS_DESC "global feature based detection in 2D images")

set(SUBSYS_DEPS od_common ${OpenCV_LIBS} od_svmlight)


set(build TRUE)
#PCL_SUBSYS_OPTION(build "${SUBSYS_NAME}" "${SUBSYS_DESC}" ON)
#PCL_SUBSYS_DEPEND(build "${SUBSYS_NAME}" DEPS ${SUBSYS_DEPS})
ADD_DEFINITIONS(
    -std=c++11 
	${Caffe_DEFINITIONS}
)

if(build)

    set(incs
        "ODFaceRecognizer.h"
        "detection/ODHOGDetector.h"
        "detection/ODCascadeDetector.h"
	"detection/ODConvClassification.h"

        "training/ODHOGTrainer.h"
#	"training/ODConvTrainer.h"
        )

    set(impl_incs
        )

    set(srcs
        ODFaceRecognizer.cpp
        "detection/ODHOGDetector.cpp"
        "detection/ODCascadeDetector.cpp"
	"detection/ODConvClassification.cpp"
        "training/ODHOGTrainer.cpp"
#	"training/ODConvTrainer.cpp"
        )


    OD_ADD_LIBRARY_ALL("${SUBSYS_NAME}" SRCS ${srcs} INCS ${incs} ${impl_incs})
    install(FILES ${incs} DESTINATION ${OD_INSTALL_INCLUDE_DIR}/${SUBSYS_NAME} COMPONENT ${LIB_NAME})

    if(SUBSYS_DEPS)
      target_link_libraries("${LIB_NAME}" ${SUBSYS_DEPS}  ${Caffe_LIBRARIES} ${OpenCV_LIBS} )
    endif(SUBSYS_DEPS)

    #PCL_MAKE_PKGCONFIG("${LIB_NAME}" "${SUBSYS_NAME}" "${SUBSYS_DESC}" "${SUBSYS_DEPS}" "" "" "" "")


endif(build)
